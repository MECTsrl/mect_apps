/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief display the file SPLASH_FILE for SPLASH_TIMEOUT_MS milliseconds
 */
#include "main.h"
#include "page0.h"
#include "app_logprint.h"
#include "ui_page0.h"

#include <QTimer>
#include <QFile>
#include <QMessageBox>
#ifdef TARGET
#ifdef ENABLE_SCREENSAVER
#include "screensaver.h"
#endif
#endif

page0::page0(QWidget *parent) :
    page(parent),
    ui(new Ui::page0)
{
    ui->setupUi(this);
    
    /* load and show the splash screen*/
    QPixmap splash;
    if (splash.load(SPLASH_FILE))
    {
        LOG_PRINT(info_e, "Splash file: '%s'\n", SPLASH_FILE);
        ui->label->setPixmap(splash);
        ui->label->update();
    }
    else
    {
        LOG_PRINT(info_e, "Cannot load splash file: '%s'\n", SPLASH_FILE);
    }
    
    first_time = true;
}

page0::~page0()
{
    delete ui;
}

void page0::reload()
{
    /* stop the unused refresh timer */
    refresh_timer->stop();
    
#ifdef TRANSLATION
    /* load translations */
    ui->retranslateUi(this);
#endif
    
    /* prepare the splash screen time out */
    QTimer::singleShot(10, this, SLOT(changePage()));
}

void page0::changePage()
{
    if (first_time == true)
    {
        /* load the tag table if it is present */
        loadTagTable();
        
        /* Load the cross-table in order to allocate the ioArea to the right size (should be fixed size) and fill the syncro table */
        int elem_read = fillSyncroArea();
        if (elem_read < 0)
        {
            LOG_PRINT(error_e, "Cannot found the cross table [%s]\n", CROSS_TABLE);
            QMessageBox::critical(0,QApplication::tr("Cross Table Check"), QApplication::tr("Cannot found the cross table %1\nMSG: '%2'").arg(CROSS_TABLE).arg(CrossTableErrorMsg));
        }
        else if (elem_read != DB_SIZE_ELEM)
        {
            LOG_PRINT(error_e, "Cannot load completly the cross table [%dvs%d]\n", elem_read, DB_SIZE_ELEM);
            QMessageBox::critical(0,QApplication::tr("Cross Table Check"), QApplication::tr("Syntax error into the cross table at line %1\nMSG: '%2'").arg(elem_read).arg(CrossTableErrorMsg));
            exit(0);
        }
        
        /* start the io layers */
        
        ioComm = new io_layer_comm(&data_send_mutex, &data_recv_mutex);
        LOG_PRINT(info_e, "Starting IOLayer Data\n");
        
        /* setting output data area size */
        SET_SIZE_BYTE(IODataAreaO + DB_OUT_BASE_BYTE, DB_SIZE_ELEM);
        /* setting status area size */
        SET_SIZE_BYTE(IODataAreaO + STATUS_BASE_BYTE, DB_SIZE_ELEM);
        
        /* setting input data area size (shouldn't be necessary) -- it has been checked at least for array init*/
        //SET_SIZE_BYTE(IODataAreaI + DB_IN_BASE_BYTE, DB_SIZE_ELEM);
        //SET_SIZE_BYTE(IODataAreaI + STATUS_BASE_BYTE, DB_SIZE_ELEM);
        
        if (ioComm->initializeData(LOCAL_SERVER_ADDR, LOCAL_SERVER_DATA_RX_PORT, LOCAL_SERVER_DATA_TX_PORT, IODataAreaI, STATUS_BASE_BYTE + DB_SIZE_BYTE, IODataAreaO, STATUS_BASE_BYTE + DB_SIZE_BYTE) == false)
        {
            LOG_PRINT(error_e, "Cannot connect to the Data IOLayer\n");
            QMessageBox::critical(0,QApplication::tr("Connection"), QApplication::tr("Cannot connect to the Data IOLayer"));
            exit(1);
        }
        
        /* setting output syncro area size, for the corresponding reading area it's not necessary */
        SET_SIZE_WORD(IOSyncroAreaO + SYNCRO_BASE_BYTE, DB_SIZE_ELEM);
        
        if (ioComm->initializeSyncro(LOCAL_SERVER_ADDR, LOCAL_SERVER_SYNCRO_RX_PORT, LOCAL_SERVER_SYNCRO_TX_PORT, IOSyncroAreaI, SYNCRO_SIZE_BYTE, IOSyncroAreaO, SYNCRO_SIZE_BYTE) == false)
        {
            LOG_PRINT(error_e, "Cannot connect to the Syncro IOLayer\n");
            QMessageBox::critical(0,QApplication::tr("Connection"), QApplication::tr("Cannot connect to the Data IOLayer"));
            exit(1);
        }
        ioComm->start();
        LOG_PRINT(info_e, "IOLayer Syncro Started\n");
        
#if defined(ENABLE_ALARMS) || defined(ENABLE_TREND) || defined(ENABLE_STORE)
        logger = new Logger(NULL, NULL, LogPeriodSecS*1000);
        /* start the logger thread */
        logger->start();
        LOG_PRINT(info_e, "Logger Started\n");
#endif
        
        if (QFile::exists(KINDOFUPDATE_FILE))
        {
            FILE * fp = fopen(KINDOFUPDATE_FILE, "r");
            char msg[STR_LEN];
            QString fullmsg;
            if (fp != NULL)
            {
                int i = 0;
                while ((fgets(msg, STR_LEN, fp))!= NULL)
                {
                    if (i < MAX_LEN_UPDATE_MSG)
                    {
                        fullmsg.append(msg);
                    }
                    else
                    {
                        fullmsg.append("...");
                        break;
                    }
                    fullmsg.append("\n");
                    i++;
                }
                fclose(fp);
                QMessageBox::information(0, "Update", fullmsg);
            }
            QFile::remove(KINDOFUPDATE_FILE);
        }
        
        int retry = 0;
        while(IS_ENGINE_READY == 0)
        {
            LOG_PRINT(info_e, "Waiting communication engine\n");
            if(retry > WAIT_COMM_RETRY_NB)
            {
                retry = 0;
                QMessageBox::critical(0, "Communication Error", "Problem to start communication engine.");
            }
            retry++;
            sleep(1);
        }
        
        LOG_PRINT(info_e, "Communication engine started\n");
        
        if (IS_COMMPAR_ERROR)
        {
            LOG_PRINT(error_e, "Commpar error\n");
            QMessageBox::critical(0,QApplication::tr("Commpar Table Check"), QApplication::tr("A problem occour when the communication paramenters are loading"));
        }
        if (IS_CROSSTABLE_ERROR)
        {
            LOG_PRINT(error_e, "CrossTable error\n");
            QMessageBox::critical(0,QApplication::tr("Cross Table Check"), QApplication::tr("A problem occour when the CrossTable variables are loading"));
        }
        if (IS_ALARMSTBL_ERROR)
        {
            if (QFile::exists(ERROR_TABLE))
            {
                LOG_PRINT(error_e, "Alarms error\n");
                QMessageBox::critical(0,QApplication::tr("Alarms Table Check"), QApplication::tr("A problem occour when the alarms are loading"));
            }
        }
        
        /* disable the device connected to a protocol not started */
        if (IS_RTU_ENABLED == 0)
        {
            for (int node = 0; node < MAX_DEVICE_NB; node++)
            {
                device_status[prot_rtu_e][node] = 0;
            }
        }
        if (IS_TCP_ENABLED == 0)
        {
            for (int node = 0; node < MAX_DEVICE_NB; node++)
            {
                device_status[prot_tcp_e][node] = 0;
            }
        }
        if (IS_TCPRTU_ENABLED == 0)
        {
            for (int node = 0; node < MAX_DEVICE_NB; node++)
            {
                device_status[prot_tcprtu_e][node] = 0;
            }
        }
        
        /* load the passwords */
        loadPasswords();
#ifdef LOG_DISABLED
        int i;
        for (i = 0; i <= PASSWORD_NB; i++)
        {
            LOG_PRINT(info_e, "Password %d '%s' = '%d'\n", i, PasswordsString[i], passwords[i]);
        }
#endif
        first_time = false;
    }
    
    LOG_PRINT(info_e, "CHANGE PAGE\n");
    /* go to the home page */
    if (goto_page(StartPage) == false && goto_page(STARTPAGE) == false && goto_page(HomePage) == false && goto_page(HOMEPAGE) == false )
    {
        QMessageBox::critical(0,QApplication::tr("Invalid Page"), QApplication::tr("Cannot show any of Default pages '%1', '%2' and home pages '%3'. '%4'").arg(StartPage).arg(STARTPAGE).arg(HomePage).arg(HOMEPAGE));
    }
    this->hide();
}

