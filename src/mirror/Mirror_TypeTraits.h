#ifndef MIRROR_TYPETRAITS_H
#define MIRROR_TYPETRAITS_H

namespace Mirror
{
    class Primitive;
    class Class;
    class Enum;
}

#include "Mirror_TypeCategory.h"

#include <type_traits>
#include <utility>

namespace Mirror
{
    /** \name TypeClassification */
    /**@{*/

    template < typename T, typename = void >
    struct TypeClassification;

    // Void type
    template < typename T >
    struct TypeClassification< T, typename std::enable_if< std::is_void< T >::value >::type >
        : std::integral_constant < TypeCategory, TypeCategory::Type >
    {
        typedef Type type;
    };

    // Fundamental type
    template < typename T >
    struct TypeClassification< T, typename std::enable_if< !std::is_void< T >::value && std::is_fundamental< T >::value >::type >
        : std::integral_constant < TypeCategory, TypeCategory::Primitive >
    {
        typedef Primitive type;
    };

    // Class type
    template < typename T >
    struct TypeClassification< T, typename std::enable_if< std::is_class< T >::value >::type >
        : std::integral_constant < TypeCategory, TypeCategory::Class >
    {
        typedef Class type;
    };

    // Enum type
    template < typename T >
    struct TypeClassification< T, typename std::enable_if< std::is_enum< T >::value >::type >
        : std::integral_constant < TypeCategory, TypeCategory::Enum >
    {
        typedef Enum type;
    };

    /**@}*/

    /** \name RemQual */
    /**@{*/

    template < typename T >
    struct RemQual
    {
        typedef T type;
    };

    // Const type
    template < typename T >
    struct RemQual < const T >
    {
        typedef typename RemQual< T>::type type;
    };

    // Volatile type
    template < typename T >
    struct RemQual < volatile T >
    {
        typedef typename RemQual< T >::type type;
    };

    // Const-volatile type
    template < typename T >
    struct RemQual < const volatile T >
    {
        typedef typename RemQual< T >::type type;
    };

    // L-value reference type
    template < typename T >
    struct RemQual < T & >
    {
        typedef typename RemQual< T >::type type;
    };

    // R-value reference type
    template < typename T >
    struct RemQual < T && >
    {
        typedef typename RemQual< T >::type type;
    };

    // Pointer type
    template < typename T >
    struct RemQual < T * >
    {
        typedef typename RemQual< T >::type type;
    };

    // Array type
    template < typename T >
    struct RemQual < T[] >
    {
        typedef typename RemQual< T >::type type;
    };

    // Fixed-size array type
    template < typename T, unsigned N >
    struct RemQual < T[ N ] >
    {
        typedef typename RemQual< T >::type type;
    };

    /**@}*/

    template < typename T >
    using MirrorType = typename TypeClassification< T >::type;

    template < typename T >
    using StrippedType = typename RemQual< T >::type;

    template < typename T >
    using StrippedMirrorType = typename MirrorType< StrippedType< T > >;
}

#endif
