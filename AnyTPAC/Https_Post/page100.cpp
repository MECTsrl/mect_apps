#include "app_logprint.h"
#include "atcmplugin.h"
#include "main.h"
#include "page100.h"
#include "ui_page100.h"
#include "crosstable.h"

#include <QString>
#include <QStringList>
#include <QProcess>
#include <QDebug>
#include <QCoreApplication>
#include <QFile>

const QString homeDir = "/local/flash/root";

/* Simple http command to send to postman-echo.com:
POST /post?qs1=wave&qs2=sound HTTP/1.1
Host: postman-echo.com
Connection: close
Content-Type: application/json
Content-Length: 25

{par1=value1&par2=value2}

*/


page100::page100(QWidget *parent) :
    page(parent),
    ui(new Ui::page100)
{
    ui->setupUi(this);    
    translateFontSize(this);

    // Prepare the POST Command
    homeDir = "/local/flash/root";
    ui->theHostLineEdit->setText("postman-echo.com");
    ui->thePathLineEdit->setText("/post?qs1=wave&qs2=sound");
    ui->theParamsLineEdit->setText("{par1=value1&par2=value2}");
    homeDir = QCoreApplication::applicationDirPath();
    httpsPort = 443;          // https default Port
    startTimeOut = 3000;
    connectPause = 2000;
    writePause = 2000;
    commandTimeOut = 20000;
    shCommand = "testPost.sh";
    postResult = "postResult.txt";
    qDebug("Current Path is: [%s]", homeDir.toLatin1().data());
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

void page100::on_pushButtonQProcess_clicked()
{
    // Post is called via QProcess
    // Prepare openssl command and stdin
    QString host = ui->theHostLineEdit->text().trimmed();
    QString path = ui->thePathLineEdit->text().trimmed();
    QString param = ui->theParamsLineEdit->text().trimmed();
    // Command and Params
    QString resultFile = QString("%1/%2") .arg(homeDir) .arg(postResult);
    QString resultMessage;
    QString sslCommand = "openssl ";
    QStringList cmdArgs = QStringList() << "s_client" << "-quiet" << "-no_ign_eof" << "-connect" << QString("%0:%1").arg(host) .arg(httpsPort);
    // Stdin to pass to openssl
    QString stdInput = QString("POST %0 HTTP/1.1\nHost: %1\n").arg(path).arg(host);
    stdInput.append(QString("Content-Length: %0\nContent-Type: application/json\r\n\r\n%1\n") .arg(param.length() + 1) .arg(param));
    // QProcess for openssl
    QProcess openSSLProcess;

    qDebug("Input to openssl command:\n[%s]", stdInput.toLatin1().data());

    QString args_s;
    foreach (QString a, cmdArgs) args_s += a + " ";
    args_s.append(QString(" 2>&1 | tee %1") .arg(resultFile));
    sslCommand.append(args_s);
    qDebug("Command line: [%s]", sslCommand.toLatin1().data());
    ui->theResultLabel->setText("...");
    ui->theResultLabel->update();

    // Remove previous Result file
    if (QFile::exists(resultFile))  {
        QFile::remove(resultFile);
    }
    // waitForStarted and waitForFinished default timeout: 30000 ms
    // openSSLProcess.setReadChannel(QProcess::StandardOutput);
    openSSLProcess.setProcessChannelMode(QProcess::ForwardedChannels);
    openSSLProcess.setWorkingDirectory(homeDir);
    timeCounter.start();
    openSSLProcess.start("sh", QStringList() << "-c"  << sslCommand);
    // openSSLProcess.start(sslCommand, cmdArgs);
    if (openSSLProcess.waitForStarted(startTimeOut))    {
        qDebug("Command: [%s] started, elapsed:[%d] ms", sslCommand.toLatin1().data(), (int) timeCounter.elapsed());
        timeCounter.restart();
        while (not timeCounter.hasExpired(connectPause)) {
            QCoreApplication::processEvents();
        }
        openSSLProcess.write(stdInput.toLatin1().data());
        while (not timeCounter.hasExpired(connectPause + writePause)) {
            QCoreApplication::processEvents();
        }
        // Needed to close connection
        openSSLProcess.closeWriteChannel();

        if (openSSLProcess.waitForFinished(commandTimeOut))  {
            // Reading Result file
            if (QFile::exists(resultFile))  {
                qDebug("Reading result file:[%s]", resultFile.toLatin1().data());
                QFile resFile(resultFile);
                if (resFile.open(QIODevice::ReadOnly | QIODevice::Text))  {
                    QByteArray result = resFile.readAll();
                    ui->theResultLabel->setText(QString(result));
                    resFile.close();
                    qDebug("Read file:[%s]", resultFile.toLatin1().data());
                }
            }
            else  {
                resultMessage = "No Result";
                ui->theResultLabel->setText(resultMessage);
                qWarning("%s", resultMessage.toLatin1().data());
            }
        }
        else  {
            resultMessage = QString("Error in process.waitForFinished() Timeout:%0") .arg(commandTimeOut);
            ui->theResultLabel->setText(resultMessage);
            qCritical("%s", resultMessage.toLatin1().data());
        }
    }
    else  {
        resultMessage = QString("Error in process.waitForStarted() Timeout:%0") .arg(startTimeOut);
        ui->theResultLabel->setText(resultMessage);
        qCritical("%s", resultMessage.toLatin1().data());
    }
    qDebug("Done. Exit Code:[%d]", openSSLProcess.exitStatus());
}

void page100::on_pushButtonShell_clicked()
{
    QString myCommand = QString("%1/%2") .arg(homeDir) .arg(shCommand);
    QString resultFile = QString("%1/%2") .arg(homeDir) .arg(postResult);
    QProcess shellProcess;
    QString resultMessage;

    // Remove previous Result file
    if (QFile::exists(resultFile))  {
        QFile::remove(resultFile);
    }
    ui->theResultLabel->clear();
    if (QFile::exists(myCommand))  {
        ui->theResultLabel->setText("...");
        ui->theResultLabel->update();
        QApplication::processEvents();
        timeCounter.start();
        qDebug("Starting Command: [%s]", myCommand.toLatin1().data());
        shellProcess.setWorkingDirectory(homeDir);
        shellProcess.setProcessChannelMode(QProcess::ForwardedChannels);
        // shellProcess.setStandardOutputFile(resultFile, QIODevice::Truncate);
        shellProcess.start(myCommand, QStringList());
        if (shellProcess.waitForFinished(commandTimeOut))  {
            qDebug("Done. Exit Status:[%d] - Exit Code:[%d] Elapsed:[%d]ms",
                   shellProcess.exitStatus(), shellProcess.exitCode(), (int) timeCounter.elapsed());
            if (QFile::exists(resultFile))  {
                qDebug("Reading result file:[%s]", resultFile.toLatin1().data());
                QFile resFile(resultFile);
                if (resFile.open(QIODevice::ReadOnly | QIODevice::Text))  {
                    QByteArray result = resFile.readAll();
                    ui->theResultLabel->setText(QString(result));
                    resFile.close();
                    qDebug("Read file:[%s]", resultFile.toLatin1().data());
                }
                else  {
                    resultMessage = "No Result";
                    ui->theResultLabel->setText(resultMessage);
                    qWarning("%s", resultMessage.toLatin1().data());
                }
            }
        }
        else  {
            resultMessage = QString("Error in process.waitForFinished() Timeout:%0") .arg(commandTimeOut);
            ui->theResultLabel->setText(resultMessage);
            qCritical("%s", resultMessage.toLatin1().data());
        }
    }
    else  {
        resultMessage = QString("Command script:[%0] not found!") .arg(myCommand);
        ui->theResultLabel->setText(resultMessage);
        qCritical("%s", resultMessage.toLatin1().data());
    }
}

