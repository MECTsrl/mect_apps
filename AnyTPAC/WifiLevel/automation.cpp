#include "crosstable.h"
#include "automation.h"

#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QString>

#define ROOTFS_FILE        "/rootfs_version"

u_int32_t getMSVersion()
{
    u_int32_t   msVersion = 0;

    QFile file(ROOTFS_FILE);
    if(file.exists()) {
        file.open(QIODevice::ReadOnly);
        QTextStream in(&file);
        while(!in.atEnd()) {
            QString line = in.readLine().trimmed();
            if (! line.isEmpty())  {
                if (line.startsWith("Release:"))  {
                    line.replace("Release:", "");
                    line = line.trimmed();
                    int     nMajor = 0;
                    int     nMinor = 0;
                    int     nBuild = 0;
                    int     nPar   = sscanf(line.toLatin1().data(), "%d.%d.%d", &nMajor, &nMinor, &nBuild);
                    if (nPar == 3)  {
                        msVersion = nBuild | (nMinor << 8) | (nMajor << 16);
                    }
                    break;
                }
            }
        }
        file.close();
    }
    qDebug("Mect Suite Version is: 0x%06X", msVersion);
    return msVersion;
}

/* put here the initalization */
void setup(void)
{    
    // Wait PLC Engine gets ready
    while (PLC_EngineStatus < 2) {
        fputc('*', stderr);
        sleep(1);
    }
    // Insert your start-up code here
    // .....
}

/* put here the operation made every 100ms */
void loop(void)
{
    
}

