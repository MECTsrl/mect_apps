/** 
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief HMI Main function
 */
#ifndef _MAIN_H_
#define _MAIN_H_

#include "global_var.h"
#include "global_functions.h"
#include "style.h"

#define VERSION ( \
    (QDate::fromString(__DATE__, "MMM dd yyyy").toString("yyyyMMdd").length() != 0) \
    ? \
    QDate::fromString(__DATE__, "MMM dd yyyy").toString("yyyyMMdd").toAscii().data() \
    : \
    QDate::fromString(__DATE__, "MMM  d yyyy").toString("yyyyMMdd").toAscii().data() \
    )

#endif




