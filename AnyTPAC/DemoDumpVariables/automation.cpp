#include "crosstable.h"
#include "automation.h"

#include <QTime>
#include <QString>
#include <QDebug>
#include <QFileInfo>

#define FIRST_DIAG_VAR 5000


u_int32_t variablesBuffer[FIRST_DIAG_VAR - 1];  // The raw type of CrossTable Vars is u_int32_t
                                                // The buffer size is big enough to store all Users Cross Table Variables


/* put here the initalization */
void setup(void)
{
    QString fileDump = QString("/local/root/dumpVars.bin");
    if (QFile::exists(fileDump))  {
        if (restoreVariables(ID_HMI_1_Start_H_1, 40, fileDump))  {
            qDebug("Vars Restored from: [%s]", fileDump.toLatin1().data());
        }
        else  {
            qCritical("Error Restoring Vars from: [%s]", fileDump.toLatin1().data());
        }
    }
    else  {
        qDebug("Dump File [%s] NOT found", fileDump.toLatin1().data());
    }
}

/* put here the operation made every 100ms */
void loop(void)
{
    
}

bool dumpVariables(int nStart, int nVariables, QString &szFile2Dump)
// nStart:          Starting Cross Table Index of Variable to be dumped
// nVariables:      Number of Items to be dumped
// szFile2Dump:     File to be dumped
{
    bool fRes = false;
    QTime   dumpTime;

    dumpTime.restart();
    if (nStart < 1 || nStart > FIRST_DIAG_VAR -1 || FIRST_DIAG_VAR < (nStart + nVariables))  {
        qCritical("Variables Indexes out of Range: nStart [%d] must be from [1] to [%d] and nStart + nVariables [%d] should be less than [%d]",
                  nStart, FIRST_DIAG_VAR -1, nVariables, FIRST_DIAG_VAR);
    }
    else  {
        // Clear Buffer
        memset (&variablesBuffer[0], 0x00, sizeof(u_int32_t) * DB_SIZE_ELEM);
        // Lock Access to Cross Table storage area
        pthread_mutex_lock(&datasync_recv_mutex);
        {
            int byte_nb = (nStart - 1) * sizeof(u_int32_t);
            memcpy(&variablesBuffer[0], &(pIODataAreaI[byte_nb]), nVariables * sizeof(u_int32_t));
        }
        // Unlock Access
        pthread_mutex_unlock(&datasync_recv_mutex);
        // Write to Binary file
        FILE *out;
        out = fopen(szFile2Dump.toLatin1().data(), "wb");
        if (out != NULL)
        {
            fwrite(&variablesBuffer[0], sizeof(u_int32_t), nVariables, out);
            fclose(out);
            fRes = true;
        }
    }
    // Log Dump result
    if (fRes)  {
        qDebug("Dumped [%d] Variables from: [%d] Elapsed: [%d]ms to File: [%s]", nVariables, nStart, dumpTime.elapsed(), szFile2Dump.toLatin1().data());
    }
    else  {
        qCritical("Error Dumping Variables to File: [%s]", szFile2Dump.toLatin1().data());
    }
    return fRes;
}

bool restoreVariables(int nStart, int nVariables, QString &szFile2Restore)
// nStart:          Starting Cross Table Index of Variable to be restored
// nVariables:      Number of Items to be restored
// szFile2Restore:  File to be restored
{
    bool fRes = false;
    QTime   restoreTime;

    restoreTime.restart();
    if (nStart < 1 || nStart > FIRST_DIAG_VAR -1 || FIRST_DIAG_VAR < (nStart + nVariables))  {
        qCritical("Variables Indexes out of Range: nStart [%d] must be from [1] to [%d] and nStart + nVariables [%d] should be less than [%d]",
                  nStart, FIRST_DIAG_VAR -1, nVariables, FIRST_DIAG_VAR);
    }
    else  {
        // Check for existence and minimum size of binary File
        QFileInfo fileInfo(szFile2Restore);
        if (fileInfo.exists() && fileInfo.size() >= nVariables * sizeof(u_int32_t))  {
            FILE *out;
            out = fopen(szFile2Restore.toLatin1().data(), "rb");
            if (out != NULL)
            {
                // Clear Buffer
                memset (&variablesBuffer[0], 0x00, sizeof(u_int32_t) * DB_SIZE_ELEM);
                // Read requested elements
                int nItems = fread(&variablesBuffer[0], sizeof(u_int32_t), nVariables, out);
                fclose(out);
                if (nItems == nVariables)  {
                    // Write Buffer Items to Cross Table Variables
                    beginWrite();
                    for (int nItem = 0; nItem < nItems; nItem++)  {
                        addWrite(nStart + nItem, &variablesBuffer[nItem]);
                    }
                    endWrite();
                    fRes = true;
                }
            }
        }
        else  {
            qCritical("Variables File: [%s] NOT Found", szFile2Restore.toLatin1().data());
        }
    }
    // Log Dump result
    if (fRes)  {
        qDebug("Restored [%d] Variables starting from: [%d]. Elapsed: [%d]ms from File: [%s]", nVariables, nStart, restoreTime.elapsed(), szFile2Restore.toLatin1().data());
    }
    else  {
        qCritical("Error Restoring Variables from File: [%s]", szFile2Restore.toLatin1().data());
    }
    return fRes;

}

