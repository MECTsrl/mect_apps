/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Generic page
 */
#include "main.h"
#include "app_cfg_file.h"
#include "app_logprint.h"
#include "buzzer_settings.h"
#include "ui_buzzer_settings.h"

/* this define set the window title */
#define WINDOW_TITLE "BUZZER SETTINGS"
/* this define set the window icon the file can have a path into resource file or into the file system */
#define WINDOW_ICON ":/systemicons/img/Home.png"

/**
 * @brief this macro is used to set the BUZZER_SETTINGS style.
 * the syntax is html stylesheet-like
 */
#define SET_BUZZER_SETTINGS_STYLE() { \
	QString mystyle; \
	mystyle.append(this->styleSheet()); \
	/* add there the page stilesheet customization */ \
	mystyle.append(""); \
	this->setStyleSheet(mystyle); \
}

/**
 * @brief This is the constructor. The operation written here, are executed only one time: at the instanziation of the page.
 */
buzzer_settings::buzzer_settings(QWidget *parent) :
	page(parent),
	ui(new Ui::buzzer_settings)
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
	/* set the style described into the macro SET_BUZZER_SETTINGS_STYLE */
	SET_BUZZER_SETTINGS_STYLE();

	/* connect the label that show the date and the time to the timer of the parent updateData */
	labelDataOra = ui->labelDataOra;
	/* connect the label that show the actual user name */
	//labelUserName = ui->labelUserName;

	reload();
}

#undef WINDOW_TITLE
#undef WINDOW_ICON

/**
 * @brief This is the reload member. The operation written here, are executed every time this page is shown.
 */
void buzzer_settings::reload()
{
	ui->pushButtonTouchBuzzer->setText(((BuzzerTouch==true)?"ON":"OFF"));
	ui->pushButtonTouchBuzzer->setChecked(!BuzzerTouch);
	ui->pushButtonAlarmBuzzer->setText(((BuzzerAlarm==true)?"ON":"OFF"));
	ui->pushButtonAlarmBuzzer->setChecked(!BuzzerAlarm);
}

/**
 * @brief This is the updateData member. The operation written here, are executed every REFRESH_MS milliseconds.
 */
void buzzer_settings::updateData()
{
	/* call the parent updateData member */
	page::updateData();
}

/**
 * @brief This is the distructor member. The operation written here, are executed only one time when the page will be deleted.
 */
buzzer_settings::~buzzer_settings()
{
	delete ui;
}

void buzzer_settings::on_pushButtonTouchBuzzer_toggled(bool checked)
{
	ui->pushButtonTouchBuzzer->setText(((checked==false)?"ON":"OFF"));
	BuzzerTouch = !checked;

	char valuestr[32] = "";
	sprintf(valuestr, "%d", BuzzerTouch);
	if (writeCfgVal(CONFIG_FILE, BUZZER_TOUCH, valuestr) <= 0)
	{
		LOG_PRINT(error_e, "Cannot write '%s' = %d\n", BUZZER_TOUCH, BuzzerTouch);
	}
}

void buzzer_settings::on_pushButtonAlarmBuzzer_toggled(bool checked)
{
	ui->pushButtonAlarmBuzzer->setText(((checked==false)?"ON":"OFF"));
	BuzzerAlarm = !checked;

	char valuestr[32] = "";
	sprintf(valuestr, "%d", BuzzerAlarm);
	if (writeCfgVal(CONFIG_FILE, BUZZER_ALARM, valuestr) <= 0)
	{
		LOG_PRINT(error_e, "Cannot write '%s' = %d\n", BUZZER_ALARM, BuzzerAlarm);
	}
}

void buzzer_settings::on_pushButtonHome_clicked()
{
	go_home();
}

void buzzer_settings::on_pushButtonBack_clicked()
{
	go_back();
}
