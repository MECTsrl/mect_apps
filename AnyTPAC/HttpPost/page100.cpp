/**
 * @file
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Generic page
 */
#include "app_logprint.h"
#include "atcmplugin.h"
#include "main.h"
#include "page100.h"
#include "ui_page100.h"
#include "crosstable.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

/**
 * @brief this macro is used to set the PAGE100 style.
 * the syntax is html stylesheet-like
 */
#define SET_PAGE100_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stilesheet customization */ \
    mystyle.append(""); \
    this->setStyleSheet(mystyle); \
    }

/**
 * @brief This is the constructor. The operation written here, are executed only one time: at the instantiation of the page.
 */
page100::page100(QWidget *parent) :
    page(parent),
    ui(new Ui::page100)
{
    ui->setupUi(this);
    /* set here the protection level (pwd_admin_e, pwd_super_user_e, pwd_user_e, pwd_operator_e), default is pwd_operator_e
     * protection_level = pwd_operator_e;
     */
    
    /* set up the page style */
    //SET_PAGE_STYLE();
    /* set the style described into the macro SET_PAGE100_STYLE */
    SET_PAGE100_STYLE();
    translateFontSize(this);

    manager = new QNetworkAccessManager();
    reply = NULL;
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finished(QNetworkReply*)));
}

/**
 * @brief This is the reload member. The operation written here, are executed every time this page is shown.
 */
void page100::reload()
{
    /*
       H variables initalizations:
         variableList.clear();
         variableList << "VARIABLE1" << "VARIABLE2" << "VARIABLE3"
       alarm banner initialization in QLineEdit:
         rotateShowError(ui->myLineEdit, ERROR_LABEL_PERIOD_MS);
     */
}

/**
 * @brief This is the updateData member. The operation written here, are executed every REFRESH_MS milliseconds.
 */
void page100::updateData()
{
    if (this->isVisible() == false)
    {
        return;
    }
    /* call the parent updateData member */
    page::updateData();
    
    /* To read the cross table variable UINT TEST1:
     *    uint_16 tmp = TEST1;
     */
    /* To write 5 into the the cross table variable UINT TEST1:
     *    doWrite_TEST1(5);
     */
}

/**
 * @brief This is the event slot to detect new language translation.
 */
void page100::changeEvent(QEvent * event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }
}

/**
 * @brief This is the distructor member. The operation written here, are executed only one time when the page will be deleted.
 */
page100::~page100()
{
    delete ui;
}

void page100::page100::on_atcmButton_HttpPost_clicked()
{
    QString msg;
    QString hostname = ui->lineEdit_HostName->text();
    QString url = QString("http://%1/%2").arg(hostname).arg(ui->lineEdit_page->text());
    QNetworkRequest request = QNetworkRequest(QUrl(url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json; charset=UTF-8"));
    QString json = QString("{ \"Var_1\" : %1 }").arg(Var_1);
    QByteArray data = json.toLatin1();

    msg = QString("url = '%1\njson = '%2'\n").arg(url).arg(json);
    ui->label_reply->setText(msg);
    reply = manager->post(request, data);
}

void page100::finished(QNetworkReply *r)
{
    QString msg;

    if (r == reply) {
        int status = r->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        if (r->error() == QNetworkReply::NoError && status >= 200 && status < 300) {
            msg = QString("successfull reply (%1)").arg(status);
        } else {
            msg = QString("failure reply (%1), %2").arg(status).arg(r->errorString());
        }
        reply = NULL;
    } else {
        msg = QString("unknown reply, url=%1").arg(r->url().toString());
    }
    r->deleteLater();
    ui->label_reply->setText(ui->label_reply->text() + msg);
}
