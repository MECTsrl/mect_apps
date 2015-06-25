/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Page browswer base class
 */
#include <QDateTime>
#include <QLineEdit>
#include <QMessageBox>
#include <QTimer>
#include <math.h>
#include <QProcess>
#include <QFile>

#include <errno.h>

#include "app_cfg_file.h"
#include "app_logprint.h"
#include "commpar_rtu.h"
#include "commpar_tcp.h"
#include "commpar_tcprtu.h"
#include "comm_status.h"
#include "cross_table_utility.h"
#include "buzzer_settings.h"
#include "data_manager.h"
#include "display_settings.h"
#include "info.h"
#include "main.h"
#include "menu.h"
#include "option.h"
#include "page0.h"
#include "pagebrowser.h"
#include "pages.h"
#include "sgdd.h"
#include "time_set.h"
#include "app_usb.h"
#include "app_cfg_file.h"
#include "app_config.h"

#if defined(ENABLE_ALARMS) || defined(ENABLE_TREND) || defined(ENABLE_STORE)
#include "datalog_set.h"
#endif

#ifdef ENABLE_ALARMS
#include "alarms.h"
#include "alarms_history.h"
#endif

#ifdef ENABLE_STORE
#include "store.h"
#include "store_filter.h"
#endif

#ifdef ENABLE_TREND
#include "trend.h"
#include "trend_other.h"
#include "trend_option.h"
#include "trend_range.h"
#endif

#ifdef ENABLE_RECIPE
#include "recipe.h"
#include "recipe_select.h"
#endif

#define RETRY_NB 5

/**
 * @brief transform a string in hex format into int
 */
int atoh(const char * string)
{
    int value;
    sscanf (string, "%x", &value);
    return value;
}

/**
 * @brief This is the constructor. The operation written here, are executed only one time: at the instanziation of the page.
 */
page::page(QWidget *parent) :
    QWidget(parent)
{
    /* set up the time for set the refresh timeout */
    refresh_timer = new QTimer(this);
    connect(refresh_timer, SIGNAL(timeout()), this, SLOT(updateData()));
    refresh_timer->start(REFRESH_MS);
    LOG_PRINT(info_e, "START TIMER %s\n", this->windowTitle().toAscii().data());
    labelDataOra = NULL;
    labelUserName = NULL;
    labelIcon = NULL;
    labelTitle = NULL;
    /* set the default protection level */
    protection_level = pwd_operator_e;
}

/**
 * @brief This is the updateData member. The operation written here, are executed every REFRESH_MS milliseconds.
 */
void page::updateData()
{
#ifdef ENABLE_ALARMS
    setAlarmsBuzzer();
#endif
    
    if (this->isVisible() == false)
    {
        LOG_PRINT(warning_e, "NOT VISIBLE BUT RUNNING %s\n", this->windowTitle().toAscii().data());
        return;
    }
    LOG_PRINT(info_e, "PAGEBROWSWER %s\n", this->windowTitle().toAscii().data());
#ifdef ENABLE_AUTODUMP
    {
        static bool inserted = false;
        /* Check USB key */
        if (USBCheck())
        {
            if ( inserted == false)
            {
                inserted = true;
                LOG_PRINT(info_e, "USB INSERTED\n");
                if (USBmount() == false)
                {
                    LOG_PRINT(error_e, "Cannot mount the usb key\n");
                    QMessageBox::critical(this,tr("USB error"), tr("Cannot mount the usb key"));
                    return;
                }
                
                char srcfilename[FILENAME_MAX];
                char dstfilename[FILENAME_MAX];
                /* compose the source file name ans the destination file name */
                sprintf(srcfilename, "%s", STORE_DIR);
                sprintf(dstfilename, "%s/%s.zip",
                        usb_mnt_point,
                        QDateTime::currentDateTime().toString("yy_MM_dd_hh_mm_ss").toAscii().data());
                
                /* zip the file, the sign file and delete them */
                if (zipAndSave(QStringList() << srcfilename, QString(dstfilename), true) == false)
                {
                    USBumount();
                    QMessageBox::critical(this,tr("USB error"), tr("Cannot create the signature '%1.sign'").arg(srcfilename));
                    return;
                }
                
                //QFile::remove(dstfilename);
                //QFile::remove(QString("%1.sign").arg(dstfilename));
                
                /* unmount USB key */
                USBumount();
                LOG_PRINT(info_e, "DOWNLOADED\n");
                QMessageBox::information(this,tr("USB info"), tr("File '%1' saved.").arg(dstfilename));
            }
        }
        else
        {
            LOG_PRINT(info_e, "USB REMOVED\n");
            inserted = false;
        }
    }
#endif
    /* check the password timeout in order to logout */
    if (PwdTimeoutSec > 0 && active_password != pwd_operator_e)
    {
        struct timespec Now;
        clock_gettime(CLOCK_REALTIME, &Now);
        if (PwdTimeoutSec < (int)(Now.tv_sec - LastTouch.tv_sec))
        {
            active_password = pwd_operator_e;
            if (windowTitle().compare(PwdLogoutPage))
            {
                LOG_PRINT(info_e, "password expire after %d seconds. going to '%s' page\n", PwdTimeoutSec, PwdLogoutPage);
                goto_page(PwdLogoutPage);
            }
        }
    }
    
    /* add here te code to be execute everytime */
    if (labelDataOra)
    {
        labelDataOra->setText(QDateTime::currentDateTime().toString("dd/MM/yyyy - HH:mm:ss"));
    }
    if (labelUserName)
    {
        char username[TAG_LEN];
        sprintf(username, "%s", PasswordsString[active_password]);
        labelUserName->setText(tr("User: %1").arg(username));
    }
#ifdef ENABLE_DEVICE_DISCONNECT
    /*Re-activate variables local to a page in case of device reconnection*/
    if(DeviceReconnected)
    {
        this->reload();
        DeviceReconnected = 0;
    }
#endif
    
    checkWriting();
    
    LOG_PRINT(verbose_e, "%x INDEX %d -> %d\n", (IOSyncroAreaI)[(ERRORS_SUMMARY)/2], ERRORS_SUMMARY, (ERRORS_SUMMARY)/2);
    if (IS_RTU_ERROR)
    {
        LOG_PRINT(warning_e, "IS_RTU_ERROR %X\n", (IOSyncroAreaI)[(ERRORS_SUMMARY)/2]);
        SET_WORD_FROM_WORD(RESET_ERROR_OFF, IOSyncroAreaO, RESET_RTU_ERROR);
    }
    if (IS_TCP_ERROR)
    {
        LOG_PRINT(warning_e, "IS_TCP_ERROR %X\n", (IOSyncroAreaI)[(ERRORS_SUMMARY)/2]);
        SET_WORD_FROM_WORD(RESET_ERROR_OFF, IOSyncroAreaO, RESET_TCP_ERROR);
    }
    if (IS_TCPRTU_ERROR)
    {
        LOG_PRINT(warning_e, "IS_TCPRTU_ERROR %X\n", (IOSyncroAreaI)[(ERRORS_SUMMARY)/2]);
        SET_WORD_FROM_WORD(RESET_ERROR_OFF, IOSyncroAreaO, RESET_TCPRTU_ERROR);
    }
    
#ifdef DUMPSCREEN
    QPixmap::grabWidget(this).save(this->windowTitle().append(".png").prepend("/local/root/"));
#endif
}

/**
 * @brief This is the distructor member. The operation written here, are executed only one time when the page will be deleted.
 */
page::~page()
{
}

bool page::getFormattedVar(const char * varname, bool * formattedVar, QLabel * led)
{
    int ctIndex;
    bool return_value = false;
    
#ifdef ENABLE_DEVICE_DISCONNECT
    if (isDeviceConnectedByVarname(varname) != 1)
    {
        LOG_PRINT(warning_e, "device disconnected\n");
        if(led) led->setStyleSheet(STYLE_DISCONNECT);
        *formattedVar = VAR_DISCONNECT;
        return return_value;
    }
#endif
    if (Tag2CtIndex(varname, &ctIndex) != 0)
    {
        LOG_PRINT(error_e, "cannot extract ctIndex\n");
        if(led) led->setStyleSheet(STYLE_UNKNOWN);
        LOG_PRINT(info_e, "FALSE\n");
        return return_value;
    }
    
    int type = CtIndex2Type(ctIndex);
    
    if (
            type == uint_e ||
            type == int_e ||
            type == udint_abcd_e ||
            type == udint_badc_e ||
            type == udint_cdab_e ||
            type == udint_dcba_e ||
            type == dint_abcd_e ||
            type == dint_badc_e ||
            type == dint_cdab_e ||
            type == dint_dcba_e ||
            type == fabcd_e ||
            type == fbadc_e ||
            type == fcdab_e ||
            type == fdcba_e
            )
    {
        LOG_PRINT(error_e, "Invalid type\n");
        if(led) led->setStyleSheet(STYLE_UNKNOWN);
        return return_value;
    }
    /* bit */
    else
    {
        BYTE _value;
        if (readFromDb(ctIndex, &_value) != 0)
        {
            if(led) led->setStyleSheet(STYLE_ERROR);
            return return_value;
        }
        
        switch (getStatusVarByCtIndex(ctIndex, NULL))
        {
        case BUSY:
            if(led) led->setStyleSheet(STYLE_PROGRESS);
            *formattedVar = (_value == 1);
            return_value = true;
            break;
        case ERROR:
            if(led) led->setStyleSheet(STYLE_ERROR);
            return_value = false;
            break;
        case DONE:
            if(led) led->setStyleSheet(STYLE_READY);
            *formattedVar = (_value == 1);
            return_value = true;
            break;
        default:
            if(led) led->setStyleSheet(STYLE_UNKNOWN);
            return_value = false;
            break;
        }
    }
    
    LOG_PRINT(info_e, "HEX %X - FORMATTED BIT '%s': '%d'\n", pIODataAreaI[(ctIndex - 1) * 4], varNameArray[ctIndex].tag, *formattedVar);
    return return_value;
    
}

bool page::getFormattedVar(const char * varname, short int * formattedVar, QLabel * led)
{
    int ctIndex;
    bool return_value = false;
#ifdef ENABLE_DEVICE_DISCONNECT
    if (isDeviceConnectedByVarname(varname) != 1)
    {
        LOG_PRINT(warning_e, "device disconnected\n");
        if(led) led->setStyleSheet(STYLE_DISCONNECT);
        *formattedVar = (short int)VAR_NAN;
        return return_value;
    }
#endif
    
    if (Tag2CtIndex(varname, &ctIndex) != 0)
    {
        LOG_PRINT(error_e, "cannot extract ctIndex\n");
        if(led) led->setStyleSheet(STYLE_UNKNOWN);
        LOG_PRINT(info_e, "FALSE\n");
        return return_value;
    }
    
    LOG_PRINT(info_e, "HEXADECIMAL CTI: %d BYTE %d - '%s': 0x%X\n", ctIndex, (ctIndex - 1) * 4, varNameArray[ctIndex].tag, pIODataAreaI[(ctIndex - 1) * 4]);
    
    if (varNameArray[ctIndex].decimal > 0)
    {
        if(led) led->setStyleSheet(STYLE_UNKNOWN);
        LOG_PRINT(info_e, "FALSE\n");
        return return_value;
    }
    if(CtIndex2Type(ctIndex) == int_e)
    {
        if (readFromDb(ctIndex, formattedVar) != 0)
        {
            if(led) led->setStyleSheet(STYLE_UNKNOWN);
            LOG_PRINT(info_e, "FALSE\n");
            return return_value;
        }
        switch (getStatusVarByCtIndex(ctIndex, NULL))
        {
        case BUSY:
            if(led) led->setStyleSheet(STYLE_PROGRESS);
            return_value = false;
            break;
        case ERROR:
            if(led) led->setStyleSheet(STYLE_ERROR);
            return_value = false;
            break;
        case DONE:
            if(led) led->setStyleSheet(STYLE_READY);
            return_value = true;
            break;
        default:
            if(led) led->setStyleSheet(STYLE_UNKNOWN);
            return_value = false;
            break;
        }
    }
    else
    {
        if(led) led->setStyleSheet(STYLE_UNKNOWN);
        LOG_PRINT(info_e, "FALSE\n");
        return return_value;
    }
    
    LOG_PRINT(info_e, "HEX %X - FORMATTED '%s': '%d'\n", pIODataAreaI[(ctIndex - 1) * 4], varNameArray[ctIndex].tag, *formattedVar);
    return return_value;
}

bool page::getFormattedVar(const char * varname, unsigned short int * formattedVar, QLabel * led)
{
    int ctIndex;
    bool return_value = false;
#ifdef ENABLE_DEVICE_DISCONNECT
    if (isDeviceConnectedByVarname(varname) != 1)
    {
        LOG_PRINT(warning_e, "device disconnected\n");
        if(led) led->setStyleSheet(STYLE_DISCONNECT);
        *formattedVar = (unsigned short int)VAR_NAN;
        return return_value;
    }
#endif
    
    if (Tag2CtIndex(varname, &ctIndex) != 0)
    {
        LOG_PRINT(error_e, "cannot extract ctIndex\n");
        if(led) led->setStyleSheet(STYLE_UNKNOWN);
        LOG_PRINT(info_e, "FALSE\n");
        return return_value;
    }
    
    LOG_PRINT(info_e, "HEXADECIMAL CTI: %d BYTE %d - '%s': 0x%X\n", ctIndex, (ctIndex - 1) * 4, varNameArray[ctIndex].tag, pIODataAreaI[(ctIndex - 1) * 4]);
    
    if (varNameArray[ctIndex].decimal > 0)
    {
        LOG_PRINT(error_e, "Invalid type\n");
        if(led) led->setStyleSheet(STYLE_UNKNOWN);
        return return_value;
    }
    if(CtIndex2Type(ctIndex) == uint_e)
    {
        if (readFromDb(ctIndex, formattedVar) != 0)
        {
            LOG_PRINT(error_e, "readFromDb\n");
            if(led) led->setStyleSheet(STYLE_UNKNOWN);
            return return_value;
        }
        switch (getStatusVarByCtIndex(ctIndex, NULL))
        {
        case BUSY:
            if(led) led->setStyleSheet(STYLE_PROGRESS);
            return_value = true;
            break;
        case ERROR:
            if(led) led->setStyleSheet(STYLE_ERROR);
            return_value = false;
            break;
        case DONE:
            if(led) led->setStyleSheet(STYLE_READY);
            return_value = true;
            break;
        default:
            if(led) led->setStyleSheet(STYLE_UNKNOWN);
            return_value = false;
            break;
        }
    }
    else
    {
        LOG_PRINT(error_e, "Invalid type\n");
        if(led) led->setStyleSheet(STYLE_UNKNOWN);
        return return_value;
    }
    
    LOG_PRINT(info_e, "HEX %X - FORMATTED '%s': '%d'\n", pIODataAreaI[(ctIndex - 1) * 4], varNameArray[ctIndex].tag, *formattedVar);
    return return_value;
}

bool page::getFormattedVar(const char * varname, int * formattedVar, QLabel * led)
{
    int ctIndex;
    bool return_value = false;
#ifdef ENABLE_DEVICE_DISCONNECT
    if (isDeviceConnectedByVarname(varname) != 1)
    {
        LOG_PRINT(warning_e, "device disconnected\n");
        if(led) led->setStyleSheet(STYLE_DISCONNECT);
        *formattedVar = (int)VAR_NAN;
        return return_value;
    }
#endif
    
    if (Tag2CtIndex(varname, &ctIndex) != 0)
    {
        LOG_PRINT(error_e, "cannot extract ctIndex\n");
        if(led) led->setStyleSheet(STYLE_UNKNOWN);
        LOG_PRINT(info_e, "FALSE\n");
        return return_value;
    }
    
    LOG_PRINT(info_e, "HEXADECIMAL CTI: %d BYTE %d - '%s': 0x%X\n", ctIndex, (ctIndex - 1) * 4, varNameArray[ctIndex].tag, pIODataAreaI[(ctIndex - 1) * 4]);
    
    if (varNameArray[ctIndex].decimal > 0)
    {
        LOG_PRINT(error_e, "Invalid type\n");
        if(led) led->setStyleSheet(STYLE_UNKNOWN);
        return return_value;
    }
    if 	(
         CtIndex2Type(ctIndex) == dint_abcd_e ||
         CtIndex2Type(ctIndex) == dint_badc_e ||
         CtIndex2Type(ctIndex) == dint_cdab_e ||
         CtIndex2Type(ctIndex) == dint_dcba_e
         )
    {
        if (readFromDb(ctIndex, formattedVar) != 0)
        {
            LOG_PRINT(error_e, "readFromDb\n");
            if(led) led->setStyleSheet(STYLE_UNKNOWN);
            return return_value;
        }
        switch (getStatusVarByCtIndex(ctIndex, NULL))
        {
        case BUSY:
            if(led) led->setStyleSheet(STYLE_PROGRESS);
            return_value = true;
            break;
        case ERROR:
            if(led) led->setStyleSheet(STYLE_ERROR);
            return_value = false;
            break;
        case DONE:
            if(led) led->setStyleSheet(STYLE_READY);
            return_value = true;
            break;
        default:
            if(led) led->setStyleSheet(STYLE_UNKNOWN);
            return_value = false;
            break;
        }
    }
    else
    {
        LOG_PRINT(error_e, "Invalid type\n");
        if(led) led->setStyleSheet(STYLE_UNKNOWN);
        return return_value;
    }
    
    LOG_PRINT(info_e, "HEX %X - FORMATTED '%s': '%d'\n", pIODataAreaI[(ctIndex - 1) * 4], varNameArray[ctIndex].tag, *formattedVar);
    return return_value;
}

bool page::getFormattedVar(const char * varname, unsigned int * formattedVar, QLabel * led)
{
    int ctIndex;
    bool return_value = false;
#ifdef ENABLE_DEVICE_DISCONNECT
    if (isDeviceConnectedByVarname(varname) != 1)
    {
        LOG_PRINT(warning_e, "device disconnected\n");
        if(led) led->setStyleSheet(STYLE_DISCONNECT);
        *formattedVar = (unsigned int)VAR_NAN;
        return return_value;
    }
#endif
    
    if (Tag2CtIndex(varname, &ctIndex) != 0)
    {
        LOG_PRINT(error_e, "cannot extract ctIndex\n");
        if(led) led->setStyleSheet(STYLE_UNKNOWN);
        LOG_PRINT(info_e, "FALSE\n");
        return return_value;
    }
    
    LOG_PRINT(info_e, "HEXADECIMAL CTI: %d BYTE %d - '%s': 0x%X\n", ctIndex, (ctIndex - 1) * 4, varNameArray[ctIndex].tag, pIODataAreaI[(ctIndex - 1) * 4]);
    
    if (varNameArray[ctIndex].decimal > 0)
    {
        LOG_PRINT(error_e, "Invalid type\n");
        if(led) led->setStyleSheet(STYLE_UNKNOWN);
        return return_value;
    }
    if (
            CtIndex2Type(ctIndex) == udint_abcd_e ||
            CtIndex2Type(ctIndex) == udint_badc_e ||
            CtIndex2Type(ctIndex) == udint_cdab_e ||
            CtIndex2Type(ctIndex) == udint_dcba_e
            )
    {
        if (readFromDb(ctIndex, formattedVar) != 0)
        {
            LOG_PRINT(error_e, "readFromDb\n");
            if(led) led->setStyleSheet(STYLE_UNKNOWN);
            return return_value;
        }
        switch (getStatusVarByCtIndex(ctIndex, NULL))
        {
        case BUSY:
            if(led) led->setStyleSheet(STYLE_PROGRESS);
            return_value = true;
            break;
        case ERROR:
            if(led) led->setStyleSheet(STYLE_ERROR);
            return_value = false;
            break;
        case DONE:
            if(led) led->setStyleSheet(STYLE_READY);
            return_value = true;
            break;
        default:
            if(led) led->setStyleSheet(STYLE_UNKNOWN);
            return_value = false;
            break;
        }
    }
    else
    {
        LOG_PRINT(error_e, "Invalid type\n");
        if(led) led->setStyleSheet(STYLE_UNKNOWN);
        return return_value;
    }
    
    LOG_PRINT(info_e, "HEX %X - FORMATTED '%s': '%d'\n", pIODataAreaI[(ctIndex - 1) * 4], varNameArray[ctIndex].tag, *formattedVar);
    return return_value;
}

bool page::getFormattedVar(const char * varname, float * formattedVar, QLabel * led)
{
    int ctIndex;
    bool return_value = false;
    char fmt[8] = "";
    int decimal = 0;
#ifdef ENABLE_DEVICE_DISCONNECT
    if (isDeviceConnectedByVarname(varname) != 1)
    {
        LOG_PRINT(warning_e, "device disconnected\n");
        if(led) led->setStyleSheet(STYLE_DISCONNECT);
        *formattedVar = (float)VAR_NAN;
        return return_value;
    }
#endif
    
    if (Tag2CtIndex(varname, &ctIndex) != 0)
    {
        LOG_PRINT(error_e, "cannot extract ctIndex '%s'\n", varname);
        if(led) led->setStyleSheet(STYLE_UNKNOWN);
        LOG_PRINT(info_e, "FALSE\n");
        return return_value;
    }
    
    LOG_PRINT(info_e, "HEXADECIMAL CTI: %d BYTE %d - '%s': 0x%X\n", ctIndex, (ctIndex - 1) * 4, varNameArray[ctIndex].tag, pIODataAreaI[(ctIndex - 1) * 4]);
    
    if (varNameArray[ctIndex].decimal > 4)
    {
        if (readFromDb(varNameArray[ctIndex].decimal, &decimal) != 0)
        {
            if(led) led->setStyleSheet(STYLE_UNKNOWN);
            decimal = 0;
        }
    }
    else if (varNameArray[ctIndex].decimal > 0)
    {
        LOG_PRINT(verbose_e, "Decimal %d\n", varNameArray[ctIndex].decimal);
        decimal = varNameArray[ctIndex].decimal;
    }
    else
    {
        decimal = 0;
    }
    switch (getStatusVarByCtIndex(ctIndex, NULL))
    {
    case BUSY:
        if(led) led->setStyleSheet(STYLE_PROGRESS);
        return_value = true;
        break;
    case ERROR:
        if(led) led->setStyleSheet(STYLE_ERROR);
        return_value = false;
        break;
    case DONE:
        if(led) led->setStyleSheet(STYLE_READY);
        return_value = true;
        break;
    default:
        if(led) led->setStyleSheet(STYLE_UNKNOWN);
        return_value = false;
        break;
    }
    if (return_value == false)
    {
        return return_value;
    }
    
    LOG_PRINT(verbose_e, "CURRENT Decimal is %d to be used for VARIABLE %s\n", decimal, varNameArray[ctIndex].tag);
    
    if (decimal > 0)
    {
        sprintf (fmt, "%%.%df", decimal);
    }
    
    switch(	CtIndex2Type(ctIndex))
    {
    case uint_e:
    {
        unsigned short int _value;
        if (readFromDb(ctIndex, &_value) != 0)
        {
            LOG_PRINT(error_e, "readFromDb\n");
            if(led) led->setStyleSheet(STYLE_UNKNOWN);
            return return_value;
        }
        switch (getStatusVarByCtIndex(ctIndex, NULL))
        {
        case BUSY:
            if(led) led->setStyleSheet(STYLE_PROGRESS);
            return_value = true;
            break;
        case ERROR:
            if(led) led->setStyleSheet(STYLE_ERROR);
            return_value = false;
            break;
        case DONE:
            if(led) led->setStyleSheet(STYLE_READY);
            return_value = true;
            break;
        default:
            if(led) led->setStyleSheet(STYLE_UNKNOWN);
            return_value = false;
            break;
        }
        if (return_value == false)
        {
            return return_value;
        }
        
        LOG_PRINT(verbose_e, "%s - value %u decimal %d divisor %f\n", varNameArray[ctIndex].tag, _value, decimal, pow(10,decimal));
        if (decimal > 0)
        {
            *formattedVar = (float)_value / pow(10,decimal);
        }
        else
        {
            *formattedVar = (float)_value;
        }
    }
        break;
    case int_e:
    {
        short int _value;
        if (readFromDb(ctIndex, &_value) != 0)
        {
            LOG_PRINT(error_e, "readFromDb\n");
            if(led) led->setStyleSheet(STYLE_UNKNOWN);
            return return_value;
        }
        switch (getStatusVarByCtIndex(ctIndex, NULL))
        {
        case BUSY:
            if(led) led->setStyleSheet(STYLE_PROGRESS);
            return_value = true;
            break;
        case ERROR:
            if(led) led->setStyleSheet(STYLE_ERROR);
            return_value = false;
            break;
        case DONE:
            if(led) led->setStyleSheet(STYLE_READY);
            return_value = true;
            break;
        default:
            if(led) led->setStyleSheet(STYLE_UNKNOWN);
            return_value = false;
            break;
        }
        if (return_value == false)
        {
            return return_value;
        }
        LOG_PRINT(verbose_e, "%s - value %d decimal %d divisor %f\n", varNameArray[ctIndex].tag, _value, decimal, pow(10,decimal));
        if (decimal > 0)
        {
            *formattedVar = (float)_value / pow(10,decimal);
        }
        else
        {
            *formattedVar = (float)_value;
        }
    }
        break;
    case udint_abcd_e:
    case udint_badc_e:
    case udint_cdab_e:
    case udint_dcba_e:
    {
        unsigned int _value;
        if (readFromDb(ctIndex, &_value) != 0)
        {
            LOG_PRINT(error_e, "readFromDb\n");
            if(led) led->setStyleSheet(STYLE_UNKNOWN);
            return return_value;
        }
        switch (getStatusVarByCtIndex(ctIndex, NULL))
        {
        case BUSY:
            if(led) led->setStyleSheet(STYLE_PROGRESS);
            return_value = true;
            break;
        case ERROR:
            if(led) led->setStyleSheet(STYLE_ERROR);
            return_value = false;
            break;
        case DONE:
            if(led) led->setStyleSheet(STYLE_READY);
            return_value = true;
            break;
        default:
            if(led) led->setStyleSheet(STYLE_UNKNOWN);
            return_value = false;
            break;
        }
        if (return_value == false)
        {
            return return_value;
        }
        LOG_PRINT(verbose_e, "%s - value %u decimal %d divisor %f\n", varNameArray[ctIndex].tag, _value, decimal, pow(10,decimal));
        if (decimal > 0)
        {
            *formattedVar = (float)_value / pow(10,decimal);
        }
        else
        {
            *formattedVar = (float)_value;
        }
    }
        break;
    case dint_abcd_e:
    case dint_badc_e:
    case dint_cdab_e:
    case dint_dcba_e:
    {
        int _value;
        if (readFromDb(ctIndex, &_value) != 0)
        {
            LOG_PRINT(error_e, "readFromDb\n");
            if(led) led->setStyleSheet(STYLE_UNKNOWN);
            return return_value;
        }
        switch (getStatusVarByCtIndex(ctIndex, NULL))
        {
        case BUSY:
            if(led) led->setStyleSheet(STYLE_PROGRESS);
            return_value = true;
            break;
        case ERROR:
            if(led) led->setStyleSheet(STYLE_ERROR);
            return_value = false;
            break;
        case DONE:
            if(led) led->setStyleSheet(STYLE_READY);
            return_value = true;
            break;
        default:
            if(led) led->setStyleSheet(STYLE_UNKNOWN);
            return_value = false;
            break;
        }
        if (return_value == false)
        {
            return return_value;
        }
        LOG_PRINT(verbose_e, "%s - value %d decimal %d divisor %f\n", varNameArray[ctIndex].tag, _value, decimal, pow(10,decimal));
        if (decimal > 0)
        {
            *formattedVar = (float)_value / pow(10,decimal);
        }
        else
        {
            *formattedVar = (float)_value;
        }
    }
        break;
    case fabcd_e:
    case fbadc_e:
    case fcdab_e:
    case fdcba_e:
    {
        float _value;
        if (readFromDb(ctIndex, &_value) != 0)
        {
            LOG_PRINT(error_e, "readFromDb\n");
            if(led) led->setStyleSheet(STYLE_UNKNOWN);
            return return_value;
        }
        switch (getStatusVarByCtIndex(ctIndex, NULL))
        {
        case BUSY:
            if(led) led->setStyleSheet(STYLE_PROGRESS);
            return_value = true;
            break;
        case ERROR:
            if(led) led->setStyleSheet(STYLE_ERROR);
            return_value = false;
            break;
        case DONE:
            if(led) led->setStyleSheet(STYLE_READY);
            return_value = true;
            break;
        default:
            if(led) led->setStyleSheet(STYLE_UNKNOWN);
            return_value = false;
            break;
        }
        if (return_value == false)
        {
            return return_value;
        }
        LOG_PRINT(verbose_e, "%s - value %f decimal %d divisor %f\n", varNameArray[ctIndex].tag, _value, decimal, pow(10,decimal));
#if 0
        if (decimal > 0)
        {
            *formattedVar = (float)_value / pow(10,decimal);
        }
        else
#endif
        {
            *formattedVar = (float)_value;
        }
    }
        break;
    default:
        /* bit */
    {
        BYTE _value;
        if (readFromDb(ctIndex, &_value) != 0)
        {
            LOG_PRINT(error_e, "readFromDb\n");
            if(led) led->setStyleSheet(STYLE_UNKNOWN);
            return return_value;
        }
        switch (getStatusVarByCtIndex(ctIndex, NULL))
        {
        case BUSY:
            if(led) led->setStyleSheet(STYLE_PROGRESS);
            return_value = true;
            break;
        case ERROR:
            if(led) led->setStyleSheet(STYLE_ERROR);
            return_value = false;
            break;
        case DONE:
            if(led) led->setStyleSheet(STYLE_READY);
            return_value = true;
            break;
        default:
            if(led) led->setStyleSheet(STYLE_UNKNOWN);
            return_value = false;
            break;
        }
        if (return_value == false)
        {
            return return_value;
        }
        *formattedVar = (float)(_value == 1);
    }
        break;
    }
    
    LOG_PRINT(info_e, "HEX %X - FORMATTED '%s': '%f'\n", pIODataAreaI[(ctIndex - 1) * 4], varNameArray[ctIndex].tag, *formattedVar);
    return return_value;
}

/**
 * @brief read the variable with tag varname and put the read value into QString formattedVar
 * and set the colour of QLabel led in according with the variable status
 */
bool page::getFormattedVar(const char * varname, QString * formattedVar, QLabel * led)
{
    int CtIndex;
    char value[TAG_LEN];
    char status[TAG_LEN];
#ifdef ENABLE_DEVICE_DISCONNECT
    if (isDeviceConnectedByVarname(varname) != 1)
    {
        LOG_PRINT(warning_e, "device disconnected\n");
        if(led) led->setStyleSheet(STYLE_DISCONNECT);
        *formattedVar = VAR_DISCONNECT;
        return false;
    }
#endif
    
    formattedVar->clear();
    if (Tag2CtIndex(varname, &CtIndex) != 0)
    {
        LOG_PRINT(error_e, "cannot extract ctIndex of variable '%s'\n", varname);
        if(led) led->setStyleSheet(STYLE_UNKNOWN);
        *formattedVar = VAR_UNKNOWN;
        LOG_PRINT(info_e, "FALSE\n");
        return false;
    }
    
    if (formattedReadFromDb(CtIndex, value) == 0 && strlen(value) > 0)
    {
        bool return_value = true;
        switch (getStatusVarByCtIndex(CtIndex, status))
        {
        case BUSY:
            if(led) led->setStyleSheet(STYLE_PROGRESS);
            /*
                   if tthe following line is commented, after a write, I will see the new value immediatly
                   else I will see the new value after is fisically set
                 */
            //*formattedVar = value;
            return_value = true;
            break;
        case ERROR:
            if(led) led->setStyleSheet(STYLE_ERROR);
            if (strlen(status) > 0) *formattedVar = status;
            return_value = false;
            break;
        case DONE:
            if(led) led->setStyleSheet(STYLE_READY);
            *formattedVar = value;
            return_value = true;
            break;
        default:
            if(led) led->setStyleSheet(STYLE_UNKNOWN);
            *formattedVar = VAR_UNKNOWN;
            return_value = false;
            break;
        }
        LOG_PRINT(info_e, "%s '%s': '%s' status %d\n", (return_value == true) ? "TRUE" : "FALSE", varname, value,getStatusVarByCtIndex(CtIndex, status));
        return return_value;
    }
    else
    {
        if(led) led->setStyleSheet(STYLE_UNKNOWN);
        *formattedVar = VAR_UNKNOWN;
        LOG_PRINT(info_e, "FALSE '%s'\n", varname);
        return false;
    }
}

/**
 * @brief read the variable with tag varname and put the read value into QLabel formattedVar
 * and set the colour of QLabel led in according with the variable status
 */
bool page::getFormattedVar(const char * varname, QLabel * formattedVar, QLabel * led)
{
    QString value;
    if (getFormattedVar(varname, &value, led) && value.length() > 0)
    {
        LOG_PRINT(verbose_e, "TRUE %s\n", value.toAscii().data());
        formattedVar->setText(value);
        return true;
    }
    else
    {
        LOG_PRINT(verbose_e, "FALSE\n");
        formattedVar->setText(value);
        return false;
    }
}

/**
 * @brief read the variable with tag varname and put the read value into QLineEdit formattedVar
 * and set the colour of QLabel led in according with the variable status
 */
bool page::getFormattedVar(const char * varname, QLineEdit * formattedVar, QLabel * led)
{
    QString value;
    if (getFormattedVar(varname, &value, led) && value.length() > 0)
    {
        formattedVar->setText(value);
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief read the variable with tag varname and put the read value into QPushButton formattedVar
 * and set the colour of QLabel led in according with the variable status
 */
bool page::getFormattedVar(const char * varname, QPushButton * formattedVar, QLabel * led)
{
    QString value;
    if (getFormattedVar(varname, &value, led) && value.length() > 0)
    {
        formattedVar->setText(value);
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief read the variable with tag varname and put the read value into QSpinBox formattedVar
 * and set the colour of QLabel led in according with the variable status
 */
bool page::getFormattedVar(const char * varname, QSpinBox * formattedVar, QLabel * led)
{
    QString value;
    if (getFormattedVar(varname, &value, led) && value.length() > 0)
    {
        formattedVar->setValue(value.toInt());
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief read the variable with tag varname and put the read value into QDoubleSpinBox formattedVar
 * and set the colour of QLabel led in according with the variable status
 */
bool page::getFormattedVar(const char * varname, QDoubleSpinBox * formattedVar, QLabel * led)
{
    QString value;
    if (getFormattedVar(varname, &value, led) && value.length() > 0)
    {
        formattedVar->setValue(value.toFloat());
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief read the variable with tag varname and put the read value into QComboBox formattedVar
 * and set the colour of QLabel led in according with the variable status
 */
bool page::getFormattedVar(const char * varname, QComboBox * formattedVar, QLabel * led)
{
    QString value;
    if (getFormattedVar(varname, &value, led) && value.length() > 0)
    {
        int index = formattedVar->findText(value);
        if (index >= 0)
        {
            if(formattedVar->currentIndex() != index)
            {
                formattedVar->setCurrentIndex(index);
            }
            else
            {
                LOG_PRINT(info_e,"Value not changed\n");
            }
        }
        else
        {
            /* if is not managed, put an empty string */
            LOG_PRINT(warning_e, "Cannot found data '%s' into selection.\n", value.toAscii().data());
            formattedVar->setEditable(true);
            formattedVar->setEditText("");
        }
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief read the variable with tag varname and put the read value into QComboBox formattedVar
 * and set the colour of QLabel led in according with the variable status.
 * Into the map variable yu need to put the mapping between the read value and text string as follow
 *      QList map << val1 << lab1 << val2 << lab2 << ... valn << labn;
 */
bool page::getFormattedVar(const char * varname, QComboBox * formattedVar, QStringList map, QLabel * led)
{
    QString value;
    int i;
    
    if (getFormattedVar(varname, &value, led) && value.length() > 0)
    {
        LOG_PRINT(info_e, "data read '%s'.\n", value.toAscii().data());
        for (i = 0; i < map.count(); i+=2)
        {
            if (map.at(i).compare(value) == 0)
            {
                LOG_PRINT(info_e, "Found mapping '%s' -> '%s'.\n", map.at(i).toAscii().data(), map.at(i + 1).toAscii().data());
                break;
            }
        }
        if (i >= map.count())
        {
            /* if is not managed, put an empty string */
            LOG_PRINT(warning_e, "Cannot found data '%s' into selection.\n", value.toAscii().data());
            formattedVar->setEditable(true);
            formattedVar->setEditText("");
            return false;
        }
        
        int index = formattedVar->findText(map.at(i+1));
        if (index >= 0)
        {
            formattedVar->setCurrentIndex(index);
        }
        else
        {
            /* if is not managed, put an empty string */
            LOG_PRINT(warning_e, "Cannot found data '%s' into selection.\n", value.toAscii().data());
            formattedVar->setEditable(true);
            formattedVar->setEditText("");
            return false;
        }
        return true;
    }
    else
    {
        return false;
    }
}

#if 0
/**
 * @brief read the variable with tag varname and put the read value into QLCDNumber formattedVar
 * and set the colour of QLabel led in according with the variable status
 */
bool page::getFormattedVar(const char * varname, QLCDNumber * formattedVar, QLabel * led)
{
    QString value;
    if (getFormattedVar(varname, &value, led) && value.length() > 0)
    {
        if (value.indexOf(".") >= 0)
        {
            formattedVar->display(value.toFloat());
        }
        else
        {
            formattedVar->display(value.toInt());
        }
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief read the variable with tag varname and put the read value into QwtTextLabel formattedVar
 * and set the colour of QLabel led in according with the variable status
 */
bool page::getFormattedVar(const char * varname, QwtTextLabel * formattedVar, QLabel * led)
{
    QString value;
    if (getFormattedVar(varname, &value, led) && value.length() > 0)
    {
        formattedVar->setText(value);
        return true;
    }
    else
    {
        return false;
    }
}
#endif

/**
 * @brief create a new page
 */
bool page::create_next_page(page ** p, const char * t)
{
    *p = NULL;
    /* special pages */
    if (strncmp(t, PAGE_PREFIX, strlen(PAGE_PREFIX)) != 0)
    {
        if (strcmp(t, "commpar_rtu") == 0)
        {
            *p = (page *)(new commpar_rtu);
        }
        else if (strcmp(t, "commpar_tcp") == 0)
        {
            *p = (page *)(new commpar_tcp);
        }
        else if (strcmp(t, "commpar_tcprtu") == 0)
        {
            *p = (page *)(new commpar_tcprtu);
        }
        else if (strcmp(t, "comm_status") == 0)
        {
            *p = (page *)(new comm_status);
        }
        else if (strcmp(t, "info") == 0)
        {
            *p = (page *)(new info);
        }
        else if (strcmp(t, "buzzer_settings") == 0)
        {
            *p = (page *)(new buzzer_settings);
        }
        else if (strcmp(t, "data_manager") == 0)
        {
            *p = (page *)(new data_manager);
        }
        else if (strcmp(t, "display_settings") == 0)
        {
            *p = (page *)(new display_settings);
        }
        else if (strcmp(t, "menu") == 0)
        {
            *p = (page *)(new menu);
        }
        else if (strcmp(t, "option") == 0)
        {
            *p = (page *)(new option);
        }
        else if (strcmp(t, "sgdd") == 0)
        {
            *p = (page *)(new sgdd);
        }
        else if (strcmp(t, "time_set") == 0)
        {
            *p = (page *)(new time_set);
        }
#if defined(ENABLE_ALARMS) || defined(ENABLE_TREND) || defined(ENABLE_STORE)
        else if (strcmp(t, "datalog_set") == 0)
        {
            *p = (page *)(new datalog_set);
        }
#endif
#ifdef ENABLE_ALARMS
        else if (strcmp(t, "alarms") == 0)
        {
            *p = (page *)(new alarms);
        }
        else if (strcmp(t, "alarms_history") == 0)
        {
            *p = (page *)(new alarms_history);
        }
#endif
#ifdef ENABLE_STORE
        else if (strcmp(t, "store") == 0)
        {
            *p = (page *)(new store);
        }
        else if (strcmp(t, "store_filter") == 0)
        {
            *p = (page *)(new store_filter);
        }
#endif
#ifdef ENABLE_TREND
        else if (strcmp(t, "trend") == 0)
        {
            *p = (page *)(new trend);
        }
        else if (strcmp(t, "trend_other") == 0)
        {
            *p = (page *)(new trend_other);
        }
        else if (strcmp(t, "trend_option") == 0)
        {
            *p = (page *)(new trend_option);
        }
        else if (strcmp(t, "trend_range") == 0)
        {
            *p = (page *)(new trend_range);
        }
#endif
#ifdef ENABLE_RECIPE
        else if (strcmp(t, "recipe") == 0)
        {
            *p = (page *)(new recipe);
        }
        else if (strcmp(t, "recipe_select") == 0)
        {
            *p = (page *)(new recipe_select);
        }
#endif
        else
        {
            LOG_PRINT(error_e, "cannot create special page %s\n", t);
            return false;
        }
    }
    /* it is a ordinary pages */
    else
    {
        int pageNb = atoh(&(t[strlen(PAGE_PREFIX)]));
        
        if (create_page_nb(p, pageNb)!= 0)
        {
            LOG_PRINT(error_e, "cannot create ordinary page %d (%s)\n", pageNb, t);
            return false;
        }
    }
    return true;
}

/**
 * @brief hide all pages
 */
bool page::hideAll(void)
{
    /* chek if some windows is still open */
    QHash<QString, page *>::const_iterator i;
    for ( i = ScreenHash.begin(); i != ScreenHash.end() && i.value() != NULL ; i++)
    {
        if ( i.value()->isVisible())
        {
            LOG_PRINT(verbose_e,"QUESTA FINESTRA (%s) ERA ATTIVA!!!!\n", i.value()->windowTitle().toAscii().data() );
            i.value()->hide();
            LOG_PRINT(verbose_e,"ORA E' NASCOSTA!!!!\n" );
        }
    }
    LOG_PRINT(verbose_e,"ORA E' TUTTO NASCOSTO!!!!\n" );
    return 0;
}

/**
 * @brief go to a page named page_name
 */
bool page::goto_page(const char * page_name, bool remember)
{
    page * p = NULL;
    
    if (strcmp(page_name, "BACK") == 0)
    {
        return go_back();
    }
    if (strcmp(page_name, "HOME") == 0)
    {
        return go_home();
    }
    if (strcmp(page_name, "page0") == 0)
    {
        goto_page(StartPage, false);
    }
    
    LOG_PRINT(info_e, "page_name %s\n", page_name);
    
    refresh_timer->stop();
    LOG_PRINT(info_e, " %s TIMER STOP\n", this->windowTitle().toAscii().data());
    
    //mymutex.lock();
    if (remember)
    {
        //LOG_PRINT(info_e,"PUT INTO HISTORY '%s'\n", this->windowTitle().toAscii().data());
        /* update history */
        History.push((page *)this);
    }
    
    /* clear the variable of the actual page */
    emptySyncroElement();
    
#ifdef ENABLE_TREND
    if (strcmp(page_name, "trend") == 0 && _last_layout_ != _layout_)
    {
        _last_layout_ = _layout_;
        if(ScreenHash.contains(page_name))
        {
            p = ScreenHash.take(page_name);
            //p->destroy();
            delete p;
            p = NULL;
            LOG_PRINT(info_e,"RIMOSSO TREND\n");
        }
    }
#endif
    
    /*prepare the next page */
    if(!ScreenHash.contains(page_name))
    {
        create_next_page(&p, page_name);
        if (p == NULL)
        {
            LOG_PRINT(info_e,"ERRORE GRAVE: fallita create_next_page\n");
            //mymutex.unlock();
            QMessageBox::critical(this,tr("Access Denied"), tr("The requested page '%1' doesn't exist.").arg(page_name));
            refresh_timer->start(REFRESH_MS);
            LOG_PRINT(info_e, " %s TIMER START\n", this->windowTitle().toAscii().data());
            return false;
        }
        if (active_password > p->protection_level)
        {
            QMessageBox::critical(this,tr("Access Denied"), tr("Impossible to access the desired page '%1': inadequate privilegies. %2 vs %3").arg(p->windowTitle()).arg(p->protection_level).arg(active_password));
            delete p;
            LOG_PRINT(info_e,"active %d, protection %d\n", active_password, p->protection_level);
            go_home();
            return false;
        }
        ScreenHash.insert(page_name, p);
        p->reload();
        LOG_PRINT(info_e,"CREATA NUOVA PAGINA %s\n", page_name);
    }
    else
    {
        p = ScreenHash.value(page_name);
        p->refresh_timer->stop();
        LOG_PRINT(info_e, " %s TIMER STOP\n", p->windowTitle().toAscii().data());
        if (active_password > p->protection_level)
        {
            QMessageBox::critical(this,tr("Access Denied"), tr("Impossible to access the desired page '%1': inadequate privilegies. %2 vs %3").arg(p->windowTitle()).arg(p->protection_level).arg(active_password));
            go_home();
            return false;
        }
        p->reload();
        LOG_PRINT(info_e,"RICARICATA PAGINA ESISTENTE %s\n", page_name);
    }
    //p->updateData();
    
    if (p != this) {
        /* deactivate the old variables */
        if (this->variableList.count() == 0 || deactivateVarList(this->variableList) == false)
        {
            LOG_PRINT(error_e, "cannot deactivate the variable list\n");
        }
        
        /* activate the new variables */
        /* send to the plc the active flag for the active variable */
        /* this code will be active only if the variable VAR_TO_DISPLAY is not empty */
        if (p->variableList.count() == 0 || activateVarList(p->variableList) == false)
        {
            LOG_PRINT(error_e, "cannot activate the variable list\n");
        }
    }
    hideAll();
    p->refresh_timer->start(REFRESH_MS);
    LOG_PRINT(info_e, " %s TIMER START\n", p->windowTitle().toAscii().data());
    p->SHOW();
    //mymutex.unlock();
    LOG_PRINT(info_e, "ORA LA NUOVA PAGINA '%s' (%s) E' MOSTRATA!!!!\n", p->windowTitle().toAscii().data(), page_name );
    return true;
}

/**
 * @brief go to the home page
 */
bool page::go_home(void)
{
    History.clear();
#ifdef ENABLE_TREND
    _trend_data_reload_ = true;
#endif
    if (goto_page(HomePage) == false)
    {
        return goto_page(HOMEPAGE);
    }
    return true;
}

/**
 * @brief go to the previous page
 */
bool page::go_back()
{
    if (isVisible() == false)
    {
        //LOG_PRINT(info_e,"NOT VISIBE\n");
        return false;
    }
    //mymutex.lock();
    LOG_PRINT(info_e, " FROM (%s)\n", this->windowTitle().toAscii().data());
    if (!History.isEmpty())
    {
        page * p = History.pop();
        LOG_PRINT(info_e, " FROM (%s) BACK TO (%s)\n", this->windowTitle().toAscii().data(), p->windowTitle().toAscii().data());
        return goto_page (p->windowTitle().toAscii().data(),false);
    }
    else
    {
        LOG_PRINT(info_e, "No history\n");
        go_home();
        //mymutex.unlock();
        return false;
    }
}

/* this section is used for hardwares with phisical key */
#ifdef HW_KEY_ENABLED
/* WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING */
/* for some reason chis event is assocated when the key is pressed!!! */
void page::keyReleaseEvent(QKeyEvent *event)
{
    fprintf(stderr, "A KEY IS PRESSED: 1 - %d\n", event->key());
    //LOG_PRINT(info_e, "A KEY IS PRESSED: 1 - %d\n", event->key());
#if 0
    int i;
    switch (event->key() - 0x1000000 + 11)
    {
    case F01:
        //LOG_PRINT(info_e,"A KEY IS PRESSED: 1 - %d\n", event->key());
        i = 0;
        break;
    case F02:
        //LOG_PRINT(info_e,"A KEY IS PRESSED: 2 - %d\n", event->key());
        i = 1;
        break;
    case F03:
        //LOG_PRINT(info_e,"A KEY IS PRESSED: 3 - %d\n", event->key());
        i = 2;
        break;
    case F04:
        //LOG_PRINT(info_e,"A KEY IS PRESSED: 4 - %d\n", event->key());
        i = 3;
        break;
    case F05:
        //LOG_PRINT(info_e,"A KEY IS PRESSED: 5 - %d\n", event->key());
        i = 4;
        break;
    case F06:
        //LOG_PRINT(info_e,"A KEY IS PRESSED: 6 - %d\n", event->key());
        i = 5;
        break;
    case F07:
        //LOG_PRINT(info_e,"A KEY IS PRESSED: 7 - %d\n", event->key());
        i = 6;
        break;
    case F08:
        //LOG_PRINT(info_e,"A KEY IS PRESSED: 8 - %d\n", event->key());
        i = 7;
        break;
    case F09:
        //LOG_PRINT(info_e,"A KEY IS PRESSED: 9 - %d\n", event->key());
        i = 8;
        break;
    case F10:
        //LOG_PRINT(info_e,"A KEY IS PRESSED: 0 - %d\n", event->key());
        i = 9;
        break;
    default:
        //LOG_PRINT(info_e,"UNKNOWN KEY IS PRESSED: 0 - %d\n", event->key() - 0x1000000);
        return;
        break;
    }
    KeyPress(keymap[i]);
#endif
}

/* WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING */
/* for some reason chis event is assocated when the key is released!!! */
void page::keyPressEvent(QKeyEvent *event)
{
    fprintf(stderr, "A KEY IS RELEASED: 1 - %d\n", event->key());
    LOG_PRINT(info_e, "A KEY IS RELEASED: 1 - %d\n", event->key());
#if 0
    int i;
    switch (event->key() - 0x1000000 + 11)
    {
    case F01:
        //LOG_PRINT(info_e,"A KEY IS RELEASED: 1 - %d\n", event->key());
        i = 0;
        break;
    case F02:
        //LOG_PRINT(info_e,"A KEY IS RELEASED: 2 - %d\n", event->key());
        i = 1;
        break;
    case F03:
        //LOG_PRINT(info_e,"A KEY IS RELEASED: 3 - %d\n", event->key());
        i = 2;
        break;
    case F04:
        //LOG_PRINT(info_e,"A KEY IS RELEASED: 4 - %d\n", event->key());
        i = 3;
        break;
    case F05:
        //LOG_PRINT(info_e,"A KEY IS RELEASED: 5 - %d\n", event->key());
        i = 4;
        break;
    case F06:
        //LOG_PRINT(info_e,"A KEY IS RELEASED: 6 - %d\n", event->key());
        i = 5;
        break;
    case F07:
        //LOG_PRINT(info_e,"A KEY IS RELEASED: 7 - %d\n", event->key());
        i = 6;
        break;
    case F08:
        //LOG_PRINT(info_e,"A KEY IS RELEASED: 8 - %d\n", event->key());
        i = 7;
        break;
    case F09:
        //LOG_PRINT(info_e,"A KEY IS RELEASED: 9 - %d\n", event->key());
        i = 8;
        break;
    case F10:
        //LOG_PRINT(info_e,"A KEY IS RELEASED: 0 - %d\n", event->key());
        i = 9;
        break;
    default:
        //LOG_PRINT(info_e,"UNKNOWN KEY IS RELEASED: 0 - %d\n", event->key() - 0x1000000);
        return;
        break;
    }
    KeyRelease(keymap[i]);
#endif
}

void page::KeyRelease(const char * Id)
{
    if (Id == NULL)
    {
        return;
    }
    //LOG_PRINT(verbose_e, "RELEASE ##################################### '%s'\n", Id);
}

void page::KeyPress(const char * Id)
{
    if (Id == NULL)
    {
        return;
    }
    //LOG_PRINT(verbose_e, "PRESS ##################################### '%s'\n", Id);
}
#endif


/**
 * @brief call the activateVar function for each variable into listVarname
 */
bool page::activateVarList(const QStringList listVarname)
{
    QString varname;
    bool ret = true;
    
    foreach(varname, listVarname)
    {
        if (activateVar(varname.toAscii().data()) != 0)
        {
            LOG_PRINT(error_e, "cannot activate '%s'\n", varname.toAscii().data());
            ret = false;
        }
        else
        {
            LOG_PRINT(verbose_e, "activated '%s'\n", varname.toAscii().data());
        }
    }
    
    return ret;
}

/**
 * @brief call the deactivateVar function for each variable into listVarname
 */
bool page::deactivateVarList(const QStringList listVarname)
{
    QString varname;
    bool ret = true;
    
    foreach(varname, listVarname)
    {
        if (deactivateVar(varname.toAscii().data()) == false)
        {
            LOG_PRINT(error_e, "cannot deactivate '%s'\n", varname.toAscii().data());
            ret = false;
        }
        else
        {
            LOG_PRINT(verbose_e, "deactivated '%s'\n", varname.toAscii().data());
        }
    }
    
    return ret;
}


/**
 * @brief get the actual status.
 * The status could be:
 * - ERROR:  error flag is set to 1
 * - DONE:   error flag is set to 0
 * - BUSY:   error flag is set to 0
 */
char page::getStatusVar(const char * varname, char * msg)
{
    char Status = DONE;
    char StatusComm = ioComm->getStatusIO();
    int CtIndex = - 1;
    
    /* force a status vector update before read the status */
    checkWriting();
    
    if (StatusComm == ERROR)
    {
        Status = ERROR;
        LOG_PRINT(error_e, "ioLayer Status %c or Syncro %c ERROR\n", StatusComm);
        if (msg != NULL)
        {
            strcpy(msg, VAR_COMMUNICATION);
        }
        return Status;
    }
    else if (StatusComm == BUSY)
    {
        Status = BUSY;
        LOG_PRINT(info_e, "ioLayer Status %c or Syncro %c BUSY\n", StatusComm);
        if (msg != NULL)
        {
            strcpy(msg, VAR_PROGRESS);
        }
    }
    
    if (Tag2CtIndex(varname, &CtIndex) != 0)
    {
        LOG_PRINT(error_e, "CtIndex '%d' Status %d ERROR\n", CtIndex, Status);
        if (msg != NULL)
        {
            strcpy(msg, VAR_UNKNOWN);
        }
        return ERROR;
    }
    
    Status = getStatusVarByCtIndex(CtIndex, msg);
    return Status;
}

/**
 * @brief set the actual status.
 * The status could be:
 * - ERROR:  error flag is set to 1
 * - DONE:   error flag is set to 0
 * - BUSY:   error flag is set to 0
 */
bool page::setStatusVar(int SynIndex, char Status)
{
    int CtIndex;
    
    /* get the variable address from syncrovector */
    if (SynIndex2CtIndex(SynIndex, &CtIndex) == 0)
    {
        if (Status == BUSY)
        {
            pIODataStatusAreaO[CtIndex] = Status;
        }
        else
        {
            pIODataStatusAreaO[CtIndex] = Status;
        }
        LOG_PRINT(info_e, "Status '%d' is '%c'\n", CtIndex, Status);
        return true;
    }
    else
    {
        LOG_PRINT(error_e, "Cannot set the status '%c' the variable '%d'\n", Status, CtIndex);
        return false;
    }
}
/**
 * @brief save the passwords
 */
bool page::dumpPasswords()
{
    FILE *out;
    int i;
    out = fopen(PASSFILE, "wb");
    if (out != NULL)
    {
        for (i = 0; i < PASSWORD_NB; i++)
        {
            fwrite(&passwords[i], 4,1, out);
            printf("dump password[%d] = %d\n", i, passwords[i]);
        }
        fclose(out);
        return true;
    }
    else
    {
        printf("Cannot create password file\n");
        return false;
    }
}

/**
 * @brief load the passwords
 */
bool page::loadPasswords()
{
    FILE *out;
    int i;
    out = fopen(PASSFILE, "rb");
    if (out == NULL)
    {
        printf("Cannot open password file\n");
        return false;
    }
    for (i = 0; i < PASSWORD_NB; i++)
    {
        if (fread(&passwords[i], 4,1, out)==0)
        {
            printf("Cannot read password %d\n", i);
            return false;
        }
        printf("password[%d] = %d\n", i, passwords[i]);
    }
    fclose(out);
    return true;
}

/**
 * @brief Load the modbus communication options
 */
int page::saveModbusOption()
{
    /* it will be a CSV file.
     * the first line is reserved for number of fail and decimator frequency for the failed request
     * the second line is reserved for RTU parameters
     * the third line is reserved for TCP parameters
     * the forth line is reserved for TCPRTU parameters
     */
    FILE * fp = fopen(COMMUNICATION_FILE, "w");
    if (fp == NULL)
    {
        LOG_PRINT(error_e, "Cannot open '%s'.\n", COMMUNICATION_FILE);
        return 1;
    }
    
    /* dump the fail nb and the decimator */
    fprintf(fp, "%d;%d\n", FailNb, FailDivisor);
    
    /* dump the priority timers */
    fprintf(fp, "%d;%d;%d\n", HighPriorityTimerMsec, MediumPriorityTimerMsec, LowPriorityTimerMsec);
    
    /* dump the RTU configuration: <device>;;;<BAUD>;<PARITY>;<DATABIT>;<STOPBIT>;<QueryInterval>;<Timeout> */
    fprintf(fp, "%s;;;%d;%c;%d;%d;%d;%d\n",
            RTUDevice,
            BaudRate,
            Parity,
            DataBit,
            StopBit,
            QueryIntervalRTU,
            TimeoutRTU
            );
    
    /* dump the TCP configuration: ;<IP>;<PORT>;;;;;<QueryInterval>;<Timeout> */
    fprintf(fp, ";%s;%d;;;;;%d;%d\n",
            IpTCP,
            PortTCP,
            QueryIntervalTCP,
            TimeoutTCP
            );
    /* dump the TCPRTU configuration: ;<IP>;<PORT>;;;;;<QueryInterval>;<Timeout> */
    fprintf(fp, ";%s;%d;;;;;%d;%d\n",
            IpTCPRTU,
            PortTCPRTU,
            QueryIntervalTCPRTU,
            TimeoutTCPRTU
            );
    fclose(fp);
    return 0;
}

/**
 * @brief Load the modbus communication options
 */
int page::loadModbusOption()
{
    char line[LINE_SIZE];
    char token[LINE_SIZE];
    char * p;
    
    FILE * fp = fopen(COMMUNICATION_FILE, "r");
    
    if (fp == NULL)
    {
        LOG_PRINT(error_e, "Cannot open '%s'.\n", COMMUNICATION_FILE);
        return 1;
    }
    
    /* Fail number and Fail divisor */
    if (fgets(line, LINE_SIZE, fp) == NULL)
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    p = line;
    p = mystrtok(p, token, SEPARATOR);
    
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    FailNb = atoi(token);
    
    p = mystrtok(p, token, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    FailDivisor = atoi(token);
    
    /* Priority Timers */
    if (fgets(line, LINE_SIZE, fp) == NULL)
    {
        LOG_PRINT(error_e, "Cannot read the priority tmers.\n");
        fclose(fp);
        return 1;
    }
    p = line;
    p = mystrtok(p, token, SEPARATOR);
    
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the high priority timer\n");
        fclose(fp);
        return 1;
    }
    
    HighPriorityTimerMsec = atoi(token);
    
    p = mystrtok(p, token, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the  medium priority timer\n");
        fclose(fp);
        return 1;
    }
    
    MediumPriorityTimerMsec = atoi(token);
    
    p = mystrtok(p, token, SEPARATOR);
    
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the  low priority timer\n");
        fclose(fp);
        return 1;
    }
    
    LowPriorityTimerMsec = atoi(token);
    
    /* read the RTU configuration: <device>;;;<BAUD>;<PARITY>;<DATABIT>;<STOPBIT>;<QueryInterval>;<Timeout> */
    if (fgets(line, LINE_SIZE, fp) == NULL)
    {
        LOG_PRINT(error_e, "Cannot read the RTU option.\n");
        fclose(fp);
        return 1;
    }
    p = line;
    /* device */
    p = mystrtok(p, RTUDevice, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    
    /* skip IP */
    p = mystrtok(p, token, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    
    /* skip Port */
    p = mystrtok(p, token, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    
    /* Baudrate */
    p = mystrtok(p, token, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    BaudRate = atoi(token);
    
    /* Parity */
    p = mystrtok(p, token, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    Parity = token[0];
    
    /* Data bit */
    p = mystrtok(p, token, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    DataBit = atoi(token);
    
    /* Stop Bit */
    p = mystrtok(p, token, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    StopBit = atoi(token);
    
    /* Query interval */
    p = mystrtok(p, token, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    QueryIntervalRTU = atoi(token);
    
    /* Timeout */
    p = mystrtok(p, token, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    TimeoutRTU = atoi(token);
    
    /* read the TCP configuration: ;<IP>;<PORT>;;;;;<QueryInterval>;<Timeout> */
    if (fgets(line, LINE_SIZE, fp) == NULL)
    {
        LOG_PRINT(error_e, "Cannot read the RTU option.\n");
        fclose(fp);
        return 1;
    }
    p = line;
    /* skip device */
    p = mystrtok(p, token, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    
    /* Ip address */
    p = mystrtok(p, IpTCP, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    
    /* Port */
    p = mystrtok(p, token, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    PortTCP = atoi(token);
    
    /* skip Baud rate */
    p = mystrtok(p, token, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    
    /* skip parity */
    p = mystrtok(p, token, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    
    /* skip databit */
    p = mystrtok(p, token, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    
    /* skip stop bit */
    p = mystrtok(p, token, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    
    /* Query interval */
    p = mystrtok(p, token, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    QueryIntervalTCP = atoi(token);
    
    /* Query timeout */
    p = mystrtok(p, token, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    TimeoutTCP = atoi(token);
    
    /* dump the TCPRTU configuration: ;<IP>;<PORT>;;;;;<QueryInterval>;<Timeout> */
    if (fgets(line, LINE_SIZE, fp) == NULL)
    {
        LOG_PRINT(error_e, "Cannot read the RTU option.\n");
        fclose(fp);
        return 1;
    }
    p = line;
    /* skip device */
    p = mystrtok(p, token, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    
    /* Ip address */
    p = mystrtok(p, IpTCPRTU, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    
    /* Port */
    p = mystrtok(p, token, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    PortTCPRTU = atoi(token);
    
    /* skip baud rate */
    p = mystrtok(p, token, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    
    /* skip parity */
    p = mystrtok(p, token, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    
    /* skip data bit */
    p = mystrtok(p, token, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    
    /* skip stop bit */
    p = mystrtok(p, token, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    
    /* Query interval */
    p = mystrtok(p, token, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    QueryIntervalTCPRTU = atoi(token);
    
    /* Timeout */
    p = mystrtok(p, token, SEPARATOR);
    if (p == NULL && token[0] == '\0' )
    {
        LOG_PRINT(error_e, "Cannot read the generic option.\n");
        fclose(fp);
        return 1;
    }
    TimeoutTCPRTU = atoi(token);
    
    fclose(fp);
    return 0;
}

/**
 * @brief set the actual page as start page
 */
bool page::setAsStartPage(char * window)
{
    strcpy(StartPage, window);
    if (writeCfgVal(CONFIG_FILE, STARTPAGE, StartPage) < 0)
    {
        LOG_PRINT(error_e, "Cannot write '%s' = %s\n", STARTPAGE, StartPage);
        return false;
    }
    return true;
}
#ifdef ENABLE_ALARMS
void page::setAlarmsBuzzer(int period_ms)
{
    static int index = 0;
    static int counter = 0;
    
    if (BuzzerAlarm == false || HornACK == true)
    {
        LOG_PRINT(verbose_e, "BuzzerAlarm '%d' HornACK '%d'\n", BuzzerAlarm, HornACK);
        return;
    }
    
    if (_active_alarms_events_.count() == 0)
    {
        LOG_PRINT(info_e, "NO ALARM '%d'\n", _active_alarms_events_.count());
        return;
    }
    
    if (counter * REFRESH_MS < period_ms)
    {
        LOG_PRINT(info_e, "SKIP ALARM CHECK '%d < %d'\n", counter * REFRESH_MS, period_ms);
        counter++;
        return;
    }
    counter = 0;
    
    for (; index < _active_alarms_events_.count() && _active_alarms_events_.at(index)->isack == true; index++);
    
    if (index < _active_alarms_events_.count() && _active_alarms_events_.at(index)->isack == false)
    {
        LOG_PRINT(info_e, "BEEEEEEP '%d'\n", period_ms/2);
        if (Buzzerfd == -1 || ioctl(Buzzerfd, BUZZER_BEEP, period_ms/2) != 0)
        {
            fprintf(stderr,"CANNOT PLAY\n");
        }
    }
    else
    {
        LOG_PRINT(info_e, "NO ACTIVE ALARM FOUND\n");
    }
}

void page::sequentialShowError(QLineEdit * line, int period_ms)
{
    static int index = 0;
    static int counter = 0;
    
    if (_active_alarms_events_.count() == 0)
    {
        return;
    }
    
    if (counter * REFRESH_MS < period_ms)
    {
        counter++;
        return;
    }
    counter = 0;
    
    for (; index < _active_alarms_events_.count(); index++)
    {
        /* skip the acknowloged error */
        if (ISBANNER(_active_alarms_events_.at(index)->styleindex) == 0)
        {
            continue;
        }
    }
    
    if (index >= _active_alarms_events_.count())
    {
        LOG_PRINT(info_e, "rewind\n");
        index = 0;
    }
    if (_active_alarms_events_.at(index)->isack)
    {
        line->clear();
        LOG_PRINT(info_e, "nothing to show\n");
    }
    else
    {
        line->setText((EventHash.find(_active_alarms_events_.at(index)->tag).value())->description);
        LOG_PRINT(info_e, "show '%s'\n", line->text().toAscii().data());
    }
}

void page::rotateShowErrorSlot()
{
    if (rotateShowError(_line, _period_ms))
    {
    }
}

bool page::rotateShowError(QLineEdit * line, int period_ms)
{
    static int shift = 0;
    static int counter = 0;
    QString bannerStr;
    static QString bannerStrOld;
    static page * p = NULL;
    static QFontMetrics fm(line->font());
    
    if (p == NULL)
    {
        p = this;
        if (logger->connectToPage(p))
        {
            LOG_PRINT(info_e, "'%s' connected to logger\n", this->windowTitle().toAscii().data());
            
        }
        else
        {
            LOG_PRINT(error_e, "Cannot connect '%s' to logger\n", this->windowTitle().toAscii().data());
        }
    }
    _line = line;
    _period_ms = period_ms;
    
    counter = 0;
    bannerStr.clear();
    for (int index = 0; index < _active_alarms_events_.count(); index++)
    {
        /* skip the invisible error */
        if (ISBANNER(_active_alarms_events_.at(index)->styleindex) == 0)
        {
            continue;
        }
        if (bannerStr.length() > 0)
        {
            bannerStr.append( ERROR_SEPARATOR );
        }
        bannerStr.append((EventHash.find(_active_alarms_events_.at(index)->tag).value())->description);
    }
    
    if (bannerStrOld.compare(bannerStr) != 0)
    {
        LOG_PRINT(error_e, "new error\n");
        bannerStrOld = bannerStr;
        shift = 0;
    }
    else if (bannerStr.length() != 0)
    {
        LOG_PRINT(error_e, "rewind %d >= %d\n", line->width(), fm.width(bannerStr.right(bannerStr.length() - shift)));
        if (line->width() < fm.width(bannerStr.right(bannerStr.length() - shift)))
        {
            LOG_PRINT(error_e, "rewind %d >= %d\n", line->width(), fm.width(bannerStr.right(bannerStr.length() - shift)));
            shift++;
        }
        else
        {
            shift = 0;
        }
    }
    if (bannerStr.length() == 0)
    {
        line->clear();
        LOG_PRINT(error_e, "nothing to show\n");
    }
    else
    {
        line->setText(bannerStr.right(bannerStr.length() - shift));
        line->setCursorPosition(0);
        LOG_PRINT(error_e, "show '%s'\n", line->text().toAscii().data());
    }
    QTimer::singleShot(_period_ms, this, SLOT(rotateShowErrorSlot()));
    return true;
}

char * page::getDescription(char* tag)
{
    if (tag != NULL)
    {
        QHash<QString, event_t *>::const_iterator i = EventHash.find(tag);
        
        if (i != EventHash.end())
        {
            return EventHash.find(tag).value()->description;
        }
    }
    return NULL;
}
#endif

int page::countLine(const char * filename)
{
    FILE * fp = NULL;
    int i = 0;
    char line[LINE_SIZE];
    
    fp = fopen (filename, "r");
    if (fp == NULL)
    {
        LOG_PRINT(error_e, "cannot open file '%s'\n", filename);
        return false;
    }
    for (i = 0; fgets(line, LINE_SIZE, fp) != NULL; i++);
    fclose (fp);
    return i;
}

bool page::isBlockFullUsed(int block, QStringList variablelist)
{
    int i;
    for (i = 0; i < DB_SIZE_ELEM && varNameArray[i].block != block; i++);
    for (; i < DB_SIZE_ELEM && varNameArray[i].block == block; i++)
    {
        if (variablelist.indexOf(varNameArray[i].tag) == -1)
        {
            return false;
        }
    }
    return true;
}

QStringList page::getBlocksToFill(QStringList variablelist)
{
    char varblockhead[TAG_LEN] = "";
    QStringList list;
    int i;
    for (i = 0; i < variablelist.count(); i++)
    {
        int block = getHeadBlockName(variablelist.at(i).toAscii().data(), varblockhead);
        if (block >= 0)
        {
            if (isBlockFullUsed(block, variablelist) == false)
            {
                list << varblockhead;
            }
        }
    }
    return list;
}


void page::translateFontSize( QWidget *ui )
{
    QObjectList l;
    QObject *w;
    
    if (!ui)
        return;
    
    QFont font = QFont(ui->font());
    font.setPointSize( (font.pointSize() *6) / 5);
    ui->setFont(font);
    
    l = ui->children();
    
    foreach (w, l) {
        QWidget *ww = dynamic_cast<QWidget *>(w);
        if (ww) {
            QFont font = QFont(ww->font());
            font.setPointSize( (font.pointSize() *6) / 5);
            ww->setFont(font);
        }
    }
}

int page::getPageNb()
{
    return atoh(this->windowTitle().right(strlen(PAGE_PREFIX)).toAscii().data());
}

bool page::zipAndSave(QStringList sourcefiles, QString destfile, bool junkdir)
{
    if (destfile.length() == 0)
    {
        LOG_PRINT(error_e, "no zip file found \n");
        return false;
    }
    if (!QFile::exists(ZIP_BIN))
    {
        LOG_PRINT(error_e, "no zip command found\n");
        return false;
    }
    for (int i = 0; i < sourcefiles.count(); i++)
    {
        if (!QFile::exists(sourcefiles.at(i)))
        {
            LOG_PRINT(error_e, "Cannot found the file to zip '%s'\n", sourcefiles.at(i).toAscii().data());
            return false;
        }
    }
    
    QProcess process;
    if (junkdir)
    {
        process.start(ZIP_BIN, QStringList() << "-r" << "-j" << destfile << sourcefiles);
    }
    else
    {
        process.start(ZIP_BIN, QStringList() << "-r"  << destfile << sourcefiles);
    }
    
    if (!process.waitForFinished())
    {
        LOG_PRINT(error_e, "Cannot execute command: '%s'\n", process.errorString().toAscii().data());
        return false;
    }
    return true;
}

bool page::setTag(QString * label, QString value)
{
    QHash<QString, QString>::const_iterator i;
    LOG_PRINT(info_e,"LOOKING FOR %s\n", value.toAscii().data());
    if (value.length() == 0)
    {
        return false;
    }
    else
    {
        i = TagTable.find(value);
    }
    if (i != TagTable.end())
    {
        *label = i.value();
        LOG_PRINT(info_e,"FOUND %s\n", i.value().toAscii().data());
        return true;
    }
    return false;
}

/*
   -1 error
   0 no sdcard
   1 sdcard without licence
   2 sdcard with storage licence
   3 sdcard with system licence
 */
int page::checkLicence(QString * message)
{
    if (SDCheck() == 0)
    {
        char cid[CID_LEN + 1];
        message->clear();
        if (getSdCID(cid) != 0)
        {
            LOG_PRINT(error_e, "Cannot open CID file '%s'\n", CID_FILE );
            *message = "Invalid SD card detected.";
            return -1;
        }
        
        char command[1024];
        
        /* read licence */
        char licence[CID_LEN + 1];
        /* Open the command for reading. */
        sprintf(command, "%s/%s", SD_MOUNT_POINT, LICENCE_FILE);
        
        FILE * fp = fopen(command, "r");
        if (fp == NULL)
        {
            LOG_PRINT(error_e, "Failed to run open '%s'\n", command );
            *message = "SD card detected, no licence found.";
            return 1;
        }
        
        /* Read the output a line at a time - output it. */
        if (fscanf(fp, "%s", licence) == 1)
        {
            LOG_PRINT(info_e, "licence: '%s'\n", licence);
        }
        else
        {
            fclose(fp);
            LOG_PRINT(error_e, "Failed to run command '%s': '%s'\n", command, licence );
            *message = "SD card detected, invalid licence found.";
            return 1;
        }
        
        LOG_PRINT(info_e, "licence: '%s'\n", licence);
        /* close */
        fclose(fp);
        
        LOG_PRINT(info_e, "licence: '%s'\n", licence);
        /* compose licence */
        char signedcode[LINE_SIZE];
        /* Open the command for reading. */
        sprintf(command, "echo %s%s | %s", cid, STORAGE_PERMISSION, APP_SIGN);
        fp = popen(command, "r");
        if (fp == NULL)
        {
            LOG_PRINT(error_e, "Failed to run command '%s'\n", command );
            QMessageBox::critical(0,tr("Internal error"), tr("cannot create the code."));
            return -1;
        }
        
        LOG_PRINT(info_e, "licence: '%s'\n", licence);
        /* Read the output a line at a time - output it. */
        if (fgets(signedcode, LINE_SIZE, fp) != NULL)
        {
            sscanf(signedcode, "%s", signedcode);
            LOG_PRINT(info_e, "signedcode: '%s'\n", signedcode);
        }
        else
        {
            pclose(fp);
            LOG_PRINT(error_e, "Failed to run command '%s': '%s'\n", command, signedcode );
            QMessageBox::critical(0,tr("Internal error"), tr("cannot create the code."));
            return -1;
        }
        
        LOG_PRINT(info_e, "licence: '%s'\n", licence);
        /* close */
        pclose(fp);
        
        if (strcmp(licence, signedcode) == 0)
        {
            *message = "SD card detected, storage licence found.";
            LOG_PRINT(info_e, "SD card detected, storage licence found.\n");
            return 2;
        }
        
        /* Open the command for reading. */
        sprintf(command, "echo %s%s | %s", cid, APPLICATION_PERMISSION, APP_SIGN);
        fp = popen(command, "r");
        if (fp == NULL)
        {
            LOG_PRINT(error_e, "Failed to run command '%s'\n", command );
            QMessageBox::critical(0,tr("Internal error"), tr("cannot create the code."));
            return -1;
        }
        
        /* Read the output a line at a time - output it. */
        if (fgets(signedcode, LINE_SIZE, fp) != NULL)
        {
            sscanf(signedcode, "%s", signedcode);
            LOG_PRINT(info_e, "signedcode: '%s'\n", signedcode);
        }
        else
        {
            pclose(fp);
            LOG_PRINT(error_e, "Failed to run command '%s': '%s'\n", command, signedcode );
            QMessageBox::critical(0,tr("Internal error"), tr("cannot create the code."));
            return -1;
        }
        
        /* close */
        pclose(fp);
        
        if (strcmp(licence, signedcode) == 0)
        {
            *message = "SD card detected, application licence found.";
            LOG_PRINT(info_e, "SD card detected, application licence found.\n");
            return 3;
        }
        else
        {
            LOG_PRINT(info_e, "'%s'\n'%s'\n", licence, signedcode);
            *message = "SD card detected, No valid licence found.";
            return 1;
        }
        
    }
    else
    {
        *message = "No SD card detected.";
        return 0;
    }
}

bool page::USBmount()
{
    if (usb_mnt_point[0] != '\0')
    {
        LOG_PRINT(info_e, "Usb already mounted to '%s'\n", usb_mnt_point);
        return true;
    }
    
    if (USBmode() == usb_device_e)
    {
        char command[256];
        sprintf(command,"LOOP=`losetup -f` && losetup -o 4096 $LOOP %s && mount -t vfat $LOOP %s", BACKING_FILE, MOUNT_POINT);
        if (system (command) == 0)
        {
            strcpy(usb_mnt_point, MOUNT_POINT);
            return true;
        }
        else
        {
            usb_mnt_point[0] = '\0';
            return false;
        }
    }
    else
    {
        static int last_usb_status = 0;
        
        last_usb_status = USBstatus[0];
        
        if (USBCheck() == false)
        {
            LOG_PRINT(error_e, "Usb Check fail\n");
            return false;
        }
        
        /* check if a usb key is inserted */
        if (USBstatus[0] != 0 && strlen(usb_mnt_point) == 0)
        {
            int retry_nb = 0;
            /* wait that is not busy */
            do {
                usleep(5000);
                LOG_PRINT (info_e, "usb waiting free \n");
                retry_nb++;
            }
            while(USBfeedback[0] != 0 /*|| strlen(Usb_mpoint(1)) != 0*/ && retry_nb < RETRY_NB);
            LOG_PRINT (info_e, "found usb USBfeedback[1] %d\n", USBfeedback[1]);
            /* mount the key */
            if (USBfeedback[1] != 0 || Usb_on(1) != 0)
            {
                LOG_PRINT (error_e, "cannot mount the USB! USBfeedback[1] = %d\n", USBfeedback[1]);
                usb_mnt_point[0] = '\0';
                return false;
            }
            strcpy(usb_mnt_point, Usb_mpoint(1));
            LOG_PRINT (info_e, "Found USB. Mountpint: '%s'\n", usb_mnt_point);
            return true;
        }
        else if (strlen(usb_mnt_point) != 0)
        {
            LOG_PRINT (verbose_e, "Already mounted to '%s'\n", usb_mnt_point);
            return true;
        }
        else
        {
            LOG_PRINT (info_e, "Cannot found USB.\n");
        }
        
        if (last_usb_status != USBstatus[0])
        {
            LOG_PRINT(info_e, "extracted USB\n");
            usb_mnt_point[0] = '\0';
        }
        
        usb_mnt_point[0] = '\0';
        return false;
    }
}

bool page::USBumount()
{
    if (usb_mnt_point[0] == '\0')
    {
        LOG_PRINT (warning_e, "USB already unmounted cause usb_mnt_point = '%s'\n", usb_mnt_point);
        return false;
    }
    if (USBmode() == usb_device_e)
    {
        char command[256];
        sprintf(command,"LOOP=`losetup -f | tr \"\\/dev\\/loop\" \" \" | awk '{printf(\"%%d\\n\", $1 - 1);}'` && umount %s && losetup -d /dev/loop$LOOP", MOUNT_POINT);
        if (system (command) == 0)
        {
            LOG_PRINT(error_e, "Cannot unmount: %s\n", strerror(errno));
        }
    }
    else
    {
        Usb_off(1);
    }
    LOG_PRINT(info_e, "unmount\n");
    usb_mnt_point[0] = '\0';
    return true;
}

bool page::setUSBmode(enum usb_mode_e mode)
{
    if (mode == usb_device_e)
    {
        if (writeCfgVal(CONFIG_FILE, USB_MODE, "Device") < 0)
        {
            LOG_PRINT(error_e, "Cannot write '%s' = %s\n", USB_MODE, "Device");
            return false;
        }
    }
    else
    {
        if (writeCfgVal(CONFIG_FILE, USB_MODE, "Host") < 0)
        {
            LOG_PRINT(error_e, "Cannot write '%s' = %s\n", USB_MODE, "Host");
            return false;
        }
    }
    return true;
}

enum usb_mode_e page::USBmode()
{    
    static enum usb_mode_e mode = usb_undefined_e;
    
    if (mode == usb_undefined_e)
    {
        if (system ("lsmod | grep -qc g_file_storage >/dev/null 2>&1") == 0)
        {
            return usb_device_e;
        }
        else
        {
            return usb_host_e;
        }
    }
    else
    {
        return mode;
    }
}

bool page::USBCheck()
{
    if (USBmode() == usb_device_e)
    {
        return true;
    }
    else
    {
        /*USBstatus*/
        int i;
        int usb = 1;
        usb = app_usb_status_read();
        if ( usb == 0 )
        {
            for (i = 0; i < APP_USB_MAX+1; i++ )
            {
                USBstatus[i]= (int)app_usb_status[i];
            }
        }
        else if	( usb == -1 )
        {
            USBstatus[APP_USB_MAX]= 30;
        }
        
        USBfeedback[0]= (int)app_usb_feedback[0];
        USBfeedback[1]= (int)app_usb_feedback[1];
        
        return  USBstatus[0] != 0;
    }
}


