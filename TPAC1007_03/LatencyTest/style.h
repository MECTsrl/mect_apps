/**
 * @file
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief header for the global style sheet of the HMI
 */
#ifndef STYLE_H
#define STYLE_H

#include "defines.h"

/**
 * @brief this macro is used to set the style for all the pages: this macro will be called in the constuctor of every pages
 * if you need to customize the style of a particular page, you must to setup the stylesheet of that page
 * the syntax is html stylesheet-like
 */
#define SET_PAGE_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    mystyle.append("QWidget"); \
    mystyle.append("{"); \
    /* load the file BACKGROUND_FILE from the file system an set is as the default background. */ \
    /* WARNING if you wanted it for a particular page, set the stylesheet in that page the back ground as url(""); */ \
    mystyle.append("    background-image: url("BACKGROUND_FILE");"); \
    /* set as default font type and size */ \
    mystyle.append("    font: 16pt \"Ubuntu\";"); \
    mystyle.append("}"); \
    /* set as default font type and size of the QPushButton */ \
    mystyle.append("QPushButton"); \
    mystyle.append("{"); \
    mystyle.append("    font: 20pt \"Ubuntu\";"); \
    mystyle.append("}"); \
    /* set as default background, font type and size of the QMessageBox */ \
    mystyle.append("QMessageBox"); \
    mystyle.append("{"); \
    mystyle.append("    font: 18pt \"Ubuntu\";"); \
    mystyle.append("    background-image: url("");"); \
    mystyle.append("}"); \
    this->setStyleSheet(mystyle); \
    }

/**
 * @brief this macro is used to set the style for all the pages: this macro will be called in the constuctor of every dialod pages as numpad
 * if you need to customize the style of a particular dialog page, you must to setup the stylesheet of dialog that dialog page
 * the syntax is html stylesheet-like
 */
#define SET_DIALOG_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    mystyle.append("QDialog"); \
    mystyle.append("{"); \
    /* load the file BACKGROUND_FILE from the file system an set is as the default background. */ \
    mystyle.append("    background-image: url("BACKGROUND_FILE");"); \
    /* set as default font type and size */ \
    mystyle.append("    font: 16pt \"Ubuntu\";"); \
    mystyle.append("}"); \
    /* set as default font type and size of the QPushButton */ \
    mystyle.append("QPushButton"); \
    mystyle.append("{"); \
    mystyle.append("    font: 20pt \"Ubuntu\";"); \
    mystyle.append("}"); \
    this->setStyleSheet(mystyle); \
    }

#endif // STYLE_H

