#ifndef MIRROR_TYPES_H
#define MIRROR_TYPES_H

#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace Mirror
{
    typedef char                int8;
    typedef short               int16;
    typedef int                 int32;
    typedef long long           int64;
    typedef unsigned char       uint8;
    typedef unsigned short      uint16;
    typedef unsigned int        uint32;
    typedef unsigned long long  uint64;
    typedef float               float32;
    typedef double              float64;

    typedef const char *        cstr;

    template < typename K, typename V >
    using TreeMap = std::map< K, V >;

    template < typename T >
    using TreeSet = std::set< T >;

    template < typename K, typename V >
    using HashMap = std::unordered_map< K, V >;

    template < typename T >
    using HashSet = std::unordered_set< T >;

    template < typename T >
    using Vector = std::vector< T >;
}

#endif
