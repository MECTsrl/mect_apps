#include "crosstable.h"
#include "automation.h"
#include <QFile>
#include <QTextStream>

#define LIST_FILE "/local/root/itemList.txt"

// Global Variables to hold the list
int          loadedElements = 0;
QStringList  listElements;


/* put here the initalization */
void setup(void)
{    
    // Wait PLC Engine gets ready
    while (PLC_EngineStatus < 2) {
        fputc('*', stderr);
        sleep(1);
    }
    // Insert your start-up code here
    // First allocate QStringList as required in retentive Variable
    listElements.clear();
    for (int nItem = 0; nItem < requiredItems; nItem++)  {
        listElements.append(NO_VALUE);
    }
}

/* put here the operation made every 100ms */
void loop(void)
{
    
}

int  loadList()
{
    int nLoadedItems = 0;

    QFile fileList(LIST_FILE);
    if (fileList.exists())  {
        if (fileList.open(QIODevice::ReadOnly | QIODevice::Text)) {
            // Associate a Text Stream to QFile
            QTextStream     listStream(&fileList);
            while (! listStream.atEnd())  {
                QString szLine = listStream.readLine().trimmed();
                // The item should already exist in the list in memory
                if (nLoadedItems < listElements.count())  {
                    listElements[nLoadedItems] = szLine;
                }
                else  {
                    listElements.append(szLine);
                }
                // Counter increment
                nLoadedItems++;
            }
            fileList.close();
        }
    }
    // Update Retentive Variable
    if (nLoadedItems > requiredItems)  {
        doWrite_requiredItems(nLoadedItems);
    }
    qDebug("Loaded [%d] elements from file [%s]", nLoadedItems, LIST_FILE);
    return nLoadedItems;
}

int  saveList()
{
    int nSavedItems = 0;
    QFile fileList(LIST_FILE);

    if (fileList.open(QIODevice::Truncate | QIODevice::WriteOnly | QIODevice::Text)) {
        // Associate a Text Stream to QFile
        QTextStream listStream(&fileList);
        // Set Codec to UTF-8
        listStream.setCodec("UTF-8");
        for (nSavedItems = 0; nSavedItems < listElements.count(); nSavedItems++)  {
            listStream << listElements.at(nSavedItems).trimmed() << endl;
        }
        fileList.flush();
        fileList.close();
    }
    qDebug("Saved [%d] elements in file [%s]", nSavedItems, LIST_FILE);
    return nSavedItems;
}
