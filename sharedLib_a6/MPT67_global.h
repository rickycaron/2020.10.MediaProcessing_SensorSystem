#ifndef MPT67_GLOBAL_H
#define MPT67_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MPT67_LIBRARY)
#  define MPT67_EXPORT Q_DECL_EXPORT
#else
#  define MPT67_EXPORT Q_DECL_IMPORT
#endif

#endif // MPT67_GLOBAL_H
