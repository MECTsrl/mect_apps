/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 4.8.5
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtCore/qglobal.h>

static const unsigned char qt_resource_data[] = {
  // C:/mect_apps/TPAC1006/Simple/languages_en.qm
  0x0,0x0,0x0,0x17,
  0x3c,
  0xb8,0x64,0x18,0xca,0xef,0x9c,0x95,0xcd,0x21,0x1c,0xbf,0x60,0xa1,0xbd,0xdd,0x88,
  0x0,0x0,0x0,0x2,0x1,0x1,
    // C:/mect_apps/TPAC1006/Simple/languages_it.qm
  0x0,0x0,0x0,0x17,
  0x3c,
  0xb8,0x64,0x18,0xca,0xef,0x9c,0x95,0xcd,0x21,0x1c,0xbf,0x60,0xa1,0xbd,0xdd,0x88,
  0x0,0x0,0x0,0x2,0x1,0x1,
  
};

static const unsigned char qt_resource_name[] = {
  // translations
  0x0,0xc,
  0xd,0xfc,0x11,0x13,
  0x0,0x74,
  0x0,0x72,0x0,0x61,0x0,0x6e,0x0,0x73,0x0,0x6c,0x0,0x61,0x0,0x74,0x0,0x69,0x0,0x6f,0x0,0x6e,0x0,0x73,
    // languages_en.qm
  0x0,0xf,
  0x0,0x8f,0x24,0xfd,
  0x0,0x6c,
  0x0,0x61,0x0,0x6e,0x0,0x67,0x0,0x75,0x0,0x61,0x0,0x67,0x0,0x65,0x0,0x73,0x0,0x5f,0x0,0x65,0x0,0x6e,0x0,0x2e,0x0,0x71,0x0,0x6d,
    // languages_it.qm
  0x0,0xf,
  0x0,0xb7,0x44,0xfd,
  0x0,0x6c,
  0x0,0x61,0x0,0x6e,0x0,0x67,0x0,0x75,0x0,0x61,0x0,0x67,0x0,0x65,0x0,0x73,0x0,0x5f,0x0,0x69,0x0,0x74,0x0,0x2e,0x0,0x71,0x0,0x6d,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
  // :/translations
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x2,
  // :/translations/languages_en.qm
  0x0,0x0,0x0,0x1e,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
  // :/translations/languages_it.qm
  0x0,0x0,0x0,0x42,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1b,

};

QT_BEGIN_NAMESPACE

extern Q_CORE_EXPORT bool qRegisterResourceData
    (int, const unsigned char *, const unsigned char *, const unsigned char *);

extern Q_CORE_EXPORT bool qUnregisterResourceData
    (int, const unsigned char *, const unsigned char *, const unsigned char *);

QT_END_NAMESPACE


int QT_MANGLE_NAMESPACE(qInitResources_languages)()
{
    QT_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x01, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_languages))

int QT_MANGLE_NAMESPACE(qCleanupResources_languages)()
{
    QT_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x01, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

Q_DESTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qCleanupResources_languages))

