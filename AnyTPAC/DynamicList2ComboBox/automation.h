#ifndef AUTOMATION_H
#define AUTOMATION_H

#include "main.h"
#include "hmi_logger.h"
#include "global_functions.h"

#include <QString>
#include <QStringList>
#include <QDebug>

#define     NO_VALUE "-"

extern int          loadedElements;
extern QStringList  listElements;


void setup(void);
void loop(void);
int  loadList();
int  saveList();

#endif // AUTOMATION_H

