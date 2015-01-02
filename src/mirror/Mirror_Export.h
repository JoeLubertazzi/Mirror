#ifndef MIRROR_EXPORT_H
#define MIRROR_EXPORT_H

#ifdef MIRROR_EXPORTS
    #define MIRROR_API __declspec(dllexport)
#else
    #define MIRROR_API __declspec(dllimport)
#endif

#endif
