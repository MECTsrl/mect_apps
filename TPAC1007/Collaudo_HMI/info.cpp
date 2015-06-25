/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Info page
 */
#include "app_logprint.h"
#include "main.h"
#include "info.h"
#include "ui_info.h"
#include "app_config.h"
#if 0
#include "fw_build_version.h"
#else
#define FW_RELEASE ( \
    (QDate::fromString(__DATE__, "MMM dd yyyy").toString("yyyyMMdd").length() != 0) \
    ? \
    QDate::fromString(__DATE__, "MMM dd yyyy").toString("yyyyMMdd").toAscii().data() \
    : \
    QDate::fromString(__DATE__, "MMM  d yyyy").toString("yyyyMMdd").toAscii().data() \
    )

#endif

/* this define set the window title */
#define WINDOW_TITLE "INFO"
/* this define set the window icon the file can have a path into resource file or into the file system */
#define WINDOW_ICON ""

#define SET_INFO_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    mystyle.append("QLabel"); \
    mystyle.append("{"); \
    mystyle.append("    font: 20pt \"Ubuntu\";"); \
    mystyle.append("}"); \
    mystyle.append("QWidget"); \
    mystyle.append("{"); \
    mystyle.append("    background-image: url(\"\");"); \
    mystyle.append("}"); \
    this->setStyleSheet(mystyle); \
    }

/**
 * @brief This is the constructor. The operation written here, are executed only one time: at the instanziation of the page.
 */
info::info(QWidget *parent) :
    page(parent),
    ui(new Ui::info)
{
    ui->setupUi(this);
    /* set here the protection level (pwd_admin_e, pwd_super_user_e, pwd_user_e, pwd_operator_e), default is pwd_operator_e
     * protection_level = pwd_operator_e;
     */
    
    /* if exist and is not empty enable the WINDOW_ICON */
    if (strlen(WINDOW_ICON) > 0)
    {
        /* enable this line, define the WINDOW_ICON and put a Qlabel named labelIcon in your ui file if you want have a window icon */
        labelIcon = ui->labelIcon;
    }
    /* if exist and is not empty enable the WINDOW_TITLE */
    if (strlen(WINDOW_TITLE) > 0)
    {
        /* enable this line, define the WINDOW_TITLE and put a Qlabel named labelTitle in your ui file if you want have a window title */
        labelTitle = ui->labelTitle;
    }
    
    /* set up the page style */
    SET_PAGE_STYLE();
    /* set the style described into the macro SET_INFO_STYLE */
    SET_INFO_STYLE();
    
    /* connect the label that show the date and the time to the timer of the parent updateData */
    labelDataOra = ui->labelDataOra;
    /* connect the label that show the actual user name */
    //labelUserName = ui->labelUserName;
}

#undef WINDOW_TITLE
#undef WINDOW_ICON

/**
 * @brief This is the reload member. The operation written here, are executed every time this page is shown.
 */
void info::reload()
{
    char version[LINE_SIZE] = "";
    char command[LINE_SIZE] = "";
    
    /* SN */
    if (app_build_serial_get() != NULL)
    {
        ui->labelSNval->setText(app_build_serial_get());
    }
    else
    {
        ui->labelSNval->setText("-");
    }
    /* SO */
    if (getVersion("cat /etc/factory.info", version, LINE_SIZE))
    {
        ui->labelSOval->setText(version);
    }
    else
    {
        ui->labelSOval->setText("-");
    }
    /* show the actual build version */
    sprintf(command, "%s/systool -v | cut -d: -f2", LOCAL_ROOT_DIR);
    if (getVersion(command, version, LINE_SIZE))
    {
        ui->labelSystoolval->setText(version);
    }
    else
    {
        ui->labelSystoolval->setText("-");
    }
    
    /* RUNTIME */
    sprintf(command, "%s/fcrts -v | cut -d: -f2", LOCAL_ROOT_DIR);
    if (getVersion(command, version, LINE_SIZE))
    {
        ui->labelFcrtsval->setText(version);
    }
    else
    {
        ui->labelFcrtsval->setText("-");
    }
    /* PLC */
    sprintf(version, "%d.%d", getCommunicationEngineMainRevision(), getCommunicationEngineMinorRevision());
    ui->labelPLCval->setText(version);
    /* HMI */
    ui->labelHMIval->setText(FW_RELEASE);
    
    char string[32];
    /* MAC */
    if (getMAC(string) == 0)
    {
        ui->labelMACval->setText(string);
    }
    else
    {
        ui->labelMACval->setText("-");
    }
    /* IP */
    if (getIP(string) == 0)
    {
        ui->labelIPval->setText(string);
    }
    else
    {
        ui->labelIPval->setText("-");
    }
    /* GATEWAY */
    if (app_build_gateway_get() != NULL)
    {
        ui->labelGatewayval->setText(app_build_gateway_get());
    }
    else
    {
        ui->labelGatewayval->setText("-");
    }
    /* NETMASK */
    if (app_build_netmask_get() != NULL)
    {
        ui->labelNetMaskval->setText(app_build_netmask_get());
    }
    else
    {
        ui->labelNetMaskval->setText("-");
    }
    /* DNS1 */
    if (app_build_dns1_get() != NULL)
    {
        ui->labelDNS1val->setText(app_build_dns1_get());
    }
    else
    {
        ui->labelDNS1val->setText("-");
    }
    /* DNS2 */
    if (app_build_dns2_get() != NULL)
    {
        ui->labelDNS2val->setText(app_build_dns2_get());
    }
    else
    {
        ui->labelDNS2val->setText("-");
    }
    
    char serial[SN_LEN] = "-";
    if (getSdSN(serial) == 0)
    {
        ui->labelSDval->setText(serial);
    }
    else
    {
        ui->labelSDval->setText("-");
    }
    
    QString message;
    switch (checkLicence(&message))
    {
    case 2:
        ui->labelLICval->setText("Storage");
        break;
    case 3:
        ui->labelLICval->setText("System");
        break;
    default:
        ui->labelLICval->setText("-");
        break;
    }
}

/**
 * @brief This is the updateData member. The operation written here, are executed every REFRESH_MS milliseconds.
 */
void info::updateData()
{
    /* call the parent updateData member */
    page::updateData();
}

/**
 * @brief This is the distructor member. The operation written here, are executed only one time when the page will be deleted.
 */
info::~info()
{
    delete ui;
}


void info::on_pushButtonHome_clicked()
{
    go_home();
}

bool info::getVersion(const char * command, char * version, int maxsize)
{
    FILE *fp;
    
    /* Open the command for reading. */
    fp = popen(command, "r");
    if (fp == NULL)
    {
        LOG_PRINT(error_e, "Failed to run command '%s'\n", command );
        return false;
    }
    
    /* Read the output a line at a time - output it. */
    if (fgets(version, maxsize, fp) != NULL)
    {
        sscanf(version, "%s", version);
        LOG_PRINT(info_e, "version: '%s'\n", version);
    }
    else
    {
        pclose(fp);
        LOG_PRINT(error_e, "Failed to run command '%s': '%s'\n", command, version );
        return false;
    }
    
    /* close */
    pclose(fp);
    return true;
}

