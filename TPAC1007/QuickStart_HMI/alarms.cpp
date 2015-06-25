/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Alarm page
 */
#include "app_logprint.h"
#include "main.h"
#include "alarms.h"
#include "ui_alarms.h"

/* this define set the window title */
#define WINDOW_TITLE "ALARM"
/* this define set the window icon the file can have a path into resource file or into the file system */
#define WINDOW_ICON ""

/**
 * @brief this macro is used to set the current page style.
 * the syntax is html stylesheet-like
 */
#define SET_ALARMS_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stilesheet customization */ \
    mystyle.append(""); \
    this->setStyleSheet(mystyle); \
    }

/**
 * @brief This is the constructor. The operation written here, are executed only one time: at the instanziation of the page.
 */
alarms::alarms(QWidget *parent) :
    page(parent),
    ui(new Ui::alarms)
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
    /* set the style described into the macro SET_ALARMS_STYLE */
    SET_ALARMS_STYLE();
    
    /* connect the label that show the date and the time to the timer of the parent updateData */
    labelDataOra = ui->labelDataOra;
    /* connect the label that show the actual user name */
    //labelUserName = ui->labelUserName;
    
    ui->comboBoxLevel->clear();
    for (int i = level_all_e; i < nb_of_level_e; i++)
    {
        ui->comboBoxLevel->addItem(QString("%1").arg(i));
    }
    
    reload();
    /*
       connect(logger, SIGNAL(new_alarm(info_msg_e *)), this, SLOT(addEvent(info_msg_e *)));
       connect(logger, SIGNAL(new_event(info_msg_e *)), this, SLOT(addEvent(info_msg_e *)));
     */
    connect(logger, SIGNAL(new_alarm(char *)), this, SLOT(receiveEvent(char *)));
    connect(logger, SIGNAL(new_event(char *)), this, SLOT(receiveEvent(char *)));
}

#undef WINDOW_TITLE
#undef WINDOW_ICON

/**
 * @brief This is the reload member. The operation written here, are executed every time this page is shown.
 */
void alarms::reload()
{
    _alarm = true;
    _event = true;
    _level = level_all_e;
    
    /* clean the list Widget from the old values */
    QListWidgetItem * item;
    do
    {
        item = ui->listWidget->takeItem ( 0 );
        if (item !=  0)
        {
            delete item;
        }
    }
    while (item != 0);
    refreshEvent();
    /* rotateShowError is the function for the alarm banner.
     * the "ui->lineEditStatus" is the line edit in your custom page used to diplay the error.
     * the ERROR_LABEL_PERIOD_MS is the feedrate.
     * is enought to use this funtion to make the banner working.
     */
    rotateShowError(ui->lineEditStatus, ERROR_LABEL_PERIOD_MS);
}

/**
 * @brief This is the updateData member. The operation written here, are executed every REFRESH_MS milliseconds.
 */
void alarms::updateData()
{
    if (this->isVisible() == false)
    {
        return;
    }
    refreshEvent();
    /* call the parent updateData member */
    page::updateData();
}

/**
 * @brief This is the distructor member. The operation written here, are executed only one time when the page will be deleted.
 */
alarms::~alarms()
{
    delete ui;
}

/**
 * @brief Add a new element into the Alarm list box
 */
void alarms::addEvent(event_descr_e * msg, bool visibility)
{
    char line[DESCR_LEN * 2];
    char event[DESCR_LEN];
    char type[DESCR_LEN];
    
    if (msg->isack == alarm_ack_e)
    {
        strcpy(event, TAG_ACK);
    }
    else if (msg->status == alarm_rise_e)
    {
        strcpy(event, TAG_RISE);
    }
    else if (msg->status == alarm_fall_e)
    {
        strcpy(event, TAG_FALL);
    }
    else
    {
        strcpy(event, TAG_UNK);
        LOG_PRINT(warning_e, "Unknown event\n");
    }
    
    event_t * evt = EventHash.find(msg->tag).value();
    if (evt->type == ALARM)
    {
        strcpy(type, TAG_ALARM);
    }
    else if (evt->type == EVENT)
    {
        strcpy(type, TAG_EVENT);
    }
    else
    {
        strcpy(event, TAG_UNK);
        LOG_PRINT(warning_e, "Unknown event\n");
    }
    
    /* description [date - time] */
#ifdef DATETIME_IS_ALARM_RISE
    char * description = getDescription(msg->tag);
    sprintf(line, "%s [%s]",
            ((description == NULL) ? "-" : description),
            (msg->begin == NULL) ? "-" : msg->begin->toString("yyyy/MM/dd-HH:mm:ss").toAscii().data()
                                   );
#else
    if (msg->ack == NULL)
    {
        sprintf(line, "%s [%s]",
                ((description == NULL) ? "-" : description),
                msg->ack->toString("yyyy/MM/dd-HH:mm:ss").toAscii().data()
                );
    }
    else
    {
        sprintf(line, "%s [%s]",
                ((description == NULL) ? "-" : description),
                (msg->begin == NULL) ? "-" : msg->begin->toString("yyyy/MM/dd-HH:mm:ss").toAscii().data()
                                       );
    }
    
#endif
#if 0
    sprintf(line, "%s START:[%s] STOP:[%s]",
            getDescription(msg->tag),
            (msg->begin == NULL) ? "-" : msg->begin->toString("yyyy/MM/dd-HH:mm:ss").toAscii().data(),
            (msg->end == NULL) ? "-" : msg->end->toString("yyyy/MM/dd-HH:mm:ss").toAscii().data()
                                 );
#endif
    LOG_PRINT(info_e, "STYLE INDEX %d STYLE '%s'\n", msg->styleindex, StatusColorTable[msg->styleindex]);
    addEvent(line, visibility, description, StatusColorTable[msg->styleindex]);
    return;
}

void alarms::addEvent(char * line, bool visibility, char * id, char * style)
{
    QString text = line;
    LOG_PRINT(error_e, "##################################\n")
        #if 0
            if (ui->listWidget->findItems(text,Qt::MatchCaseSensitive).count() != 0)
    {
        LOG_PRINT(info_e, "event alredy present '%s'\n", line);
        return;
    }
#endif
    if (style != NULL)
    {
        int i;
        QListWidgetItem * item = NULL;
        for (i = 0; i < ui->listWidget->count(); i++)
        {
            if (ui->listWidget->item(i)->text().startsWith(id) == true)
            {
                item = ui->listWidget->item(i);
                break;
            }
        }
        if (item != NULL)
        {
            if (strcasecmp(style, INVISIBLE) != 0)
            {
                if (item->text().compare(text) != 0)
                {
                    item->setText(text);
                    LOG_PRINT(info_e, "Adding updating item '%s'\n", item->text().toAscii().data());
                }
                else
                {
                    LOG_PRINT(info_e, "Already existing item item '%s'\n", item->text().toAscii().data());
                }
            }
            else
            {
                LOG_PRINT(info_e, "Hide item '%s'\n", item->text().toAscii().data());
                QListWidgetItem* item = ui->listWidget->takeItem(i);
                delete item;
                LOG_PRINT(error_e, "##################################\n");
                return;
            }
        }
        else if (strcasecmp(style, INVISIBLE) != 0)
        {
            item = new QListWidgetItem();
            item->setText(QString(line).trimmed());
#ifdef ALARM_FIRST_TO_LAST
            ui->listWidget->addItem(item);
#else
            ui->listWidget->insertItem(0,item);
#endif
            LOG_PRINT(info_e, "Adding new item '%s'\n", item->text().toAscii().data());
        }
        else
        {
            LOG_PRINT(error_e, "##################################\n");
            return;
        }
        LOG_PRINT(info_e, "'%s'\n",style);
        int r = 0, g = 0, b = 0, ret = 0;
        ret = sscanf(style, "rgb(%d,%d,%d)", &r,&g,&b);
        if (ret == 3)
        {
            LOG_PRINT(info_e, "setting color %d %d %d\n",r,g,b)
                    item->setTextColor(QColor(r,g,b));
            LOG_PRINT(info_e, "set color %d %d %d\n",r,g,b)
        }
        else
        {
            LOG_PRINT(error_e, "cannot set color\n")
        }
        item->setHidden(!visibility);
    }
    else
    {
        LOG_PRINT(error_e, "Not visible into the banner\n")
    }
    LOG_PRINT(error_e, "##################################\n")
}

void alarms::on_pushButtonHome_clicked()
{
    go_home();
}

void alarms::on_pushButtonBack_clicked()
{
    go_back();
}

void alarms::on_pushButtonHistory_clicked()
{
    goto_page("alarms_history");
}

void alarms::on_comboBoxLevel_currentIndexChanged(int index)
{
    /* 0 is all level */
    if (_level != index && index < nb_of_level_e)
    {
        _level = index;
        refreshEvent();
    }
}

void alarms::on_comboBoxType_currentIndexChanged(int index)
{
    /* 0 is all
     * 1 is alarms
     * 2 is event
     */
    switch(index)
    {
    case 0:
        _alarm = true;
        _event = true;
        break;
    case 1:
        _alarm = true;
        _event = false;
        break;
    case 2:
        _alarm = false;
        _event = true;
        break;
    default:
        _alarm = true;
        _event = true;
        break;
    }
    LOG_PRINT(info_e, "alarm %d event %d\n", _alarm, _event);
    refreshEvent();
}

void alarms::receiveEvent(__attribute__((unused)) char * msg)
{
    LOG_PRINT(info_e, "alarm %s\n", msg);
    if (this->isVisible() == false)
    {
        return;
    }
    refreshEvent();
}

void alarms::refreshEvent()
{
    event_t * event;
    bool visibility = true;
    
    /* to avoid flikering don't remove and refill all the widget but update only the difference */
    //ui->listWidget->clear();
    
    LOG_PRINT(info_e,"%d\n", _active_alarms_events_.count());
    
    int found = 0;
    /* remove the non active alarm */
    for (int i = 0; i < ui->listWidget->count(); i++)
    {
        for (int j = 0; j < _active_alarms_events_.count(); j++)
        {
            char * description = getDescription(_active_alarms_events_.at(j)->tag);
            LOG_PRINT(verbose_e, "'%s' vs '%s'\n", ui->listWidget->item(i)->text().toAscii().data(), (description == NULL) ? "-" : description);
            if (ui->listWidget->item(i)->text().startsWith((description == NULL) ? "-" : description) == true)
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            LOG_PRINT(info_e, "NOT FOUND %s\n", ui->listWidget->item(i)->text().toAscii().data());
            QListWidgetItem * item = ui->listWidget->takeItem(i);
            delete item;
        }
        else
        {
            LOG_PRINT(info_e, "FOUND %s\n", ui->listWidget->item(i)->text().toAscii().data());
            found = 0;
        }
    }
    
    /* update the active alarm if it is necessary */
    for (int i = 0; i < _active_alarms_events_.count(); i++)
    {
        LOG_PRINT(info_e,"%s\n", _active_alarms_events_.at(i)->tag);
        event = EventHash.find(_active_alarms_events_.at(i)->tag).value();
        
        /* loking into event db this event to get the level and the type if it is necessary */
        if (event->type == ALARM && _alarm == false)
        {
            LOG_PRINT(info_e, "Hide event '%s'\n", event->description);
            visibility = false;
        }
        if (event->type == EVENT && _event == false)
        {
            LOG_PRINT(info_e, "Hide event '%s'\n", event->description);
            visibility = false;
        }
        if (_level != level_all_e && event->level > _level)
        {
            LOG_PRINT(info_e, "Hide event '%s'\n", event->description);
            visibility = false;
        }
        addEvent(_active_alarms_events_.at(i), visibility);
    }
}

void alarms::on_pushButtonACK_clicked()
{
    if (ui->listWidget->selectedItems().count() > 0)
    {
        int current_index = ui->listWidget->currentRow();
        if (current_index < 0)
        {
            return;
        }
        LOG_PRINT(info_e, "selected row %d '%s'\n", current_index, _active_alarms_events_.at(current_index)->tag);
        _active_alarms_events_.at(current_index)->isack = true;
        if (_active_alarms_events_.at(current_index)->ack == NULL)
        {
            _active_alarms_events_.at(current_index)->ack = new QDateTime();
        }
        *(_active_alarms_events_.at(current_index)->ack) = QDateTime::currentDateTime();
        
        event_msg_e info_msg;
        info_msg.event = alarm_ack_e;
        strcpy(info_msg.tag, _active_alarms_events_.at(current_index)->tag);
        info_msg.time = *(_active_alarms_events_.at(current_index)->ack);
        
        emit new_ack(&info_msg);
        ui->listWidget->currentItem()->setSelected(false);
        refreshEvent();
    }
}

void alarms::on_pushButtonACKall_clicked()
{
    LOG_PRINT(info_e, "ACKALL\n");
    for (int i = 0; i < _active_alarms_events_.count(); i++)
    {
        if (_active_alarms_events_.at(i)->ack == NULL)
        {
            _active_alarms_events_.at(i)->ack = new QDateTime();
        }
        *(_active_alarms_events_.at(i)->ack) = QDateTime::currentDateTime();
        _active_alarms_events_.at(i)->isack = true;
    }
    emit new_ack(NULL);
    if (ui->listWidget->currentItem() != NULL)
    {
        ui->listWidget->currentItem()->setSelected(false);
    }
    refreshEvent();
}

void alarms::on_pushButtonHornACK_clicked()
{
    HornACK = true;
}

