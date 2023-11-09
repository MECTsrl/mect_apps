#include "app_logprint.h"
#include "atcmplugin.h"
#include "main.h"
#include "page100.h"
#include "ui_page100.h"
#include "crosstable.h"

#include <QString>
#include <QProcess>
#include <QDebug>

page100::page100(QWidget *parent) :
    page(parent),
    ui(new Ui::page100)
{
    ui->setupUi(this);    
    translateFontSize(this);

    ui->theHostLineEdit->setText("api.open-meteo.com");
    ui->thePathLineEdit->setText("/v1/forecast?latitude=45.0935&longitude=7.5239&hourly=temperature_2m&forecast_days=1");
}

void page100::reload()
{
}

void page100::updateData()
{
    if (this->isVisible() == false)
    {
        return;
    }
    page::updateData();    
}

void page100::changeEvent(QEvent * event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }
}

page100::~page100()
{
    delete ui;
}

// ------------------------------------------------------------------------------------------------------

void page100::on_pushButton_clicked()
{
    QString host = ui->theHostLineEdit->text();
    QString path = ui->thePathLineEdit->text();
    QString cmd = "openssl";
    QStringList args = QStringList() << "s_client" << "-quiet" << "-connect" << QString("%0:443").arg(host);
    QString input = QString("GET %0 HTTP/1.1\nHost: %1\nConnection: close\n\n").arg(path).arg(host);
    qDebug("Input to openssl command:\n[%s]", input.toLatin1().data());
    QProcess process;

    // QString args_s;
    // foreach (QString a, args) args_s += a + " ";

    // ui->theCommandLabel->setText(QString("%0\n%1\n%2\n").arg(cmd).arg(args_s).arg(input));
    ui->theResultLabel->setText("...");

    // waitForStarted and waitForFinished default timeout: 30000 ms
    process.start(cmd, args);
    if (process.waitForStarted())   {
        process.write(input.toLatin1().data());
        process.closeWriteChannel();

        if (process.waitForFinished())  {
            QByteArray result = process.readAll();

            ui->theResultLabel->setText(QString(result));
        }
        else  {
            ui->theResultLabel->setText("error in process.waitForFinished()");
        }
    }
    else  {
        ui->theResultLabel->setText("error in process.waitForStarted()");
    }
}
