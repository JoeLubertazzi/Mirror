#ifndef MIRROR_INTERNAL_H
#define MIRROR_INTERNAL_H

namespace Mirror
{
    class Type;
}

#include "../Mirror_Export.h"
#include "../Mirror_Types.h"
#include "../Mirror_TypeTraits.h"

namespace Mirror
{
    namespace detail
    {
        typedef TreeMap< cstr, Type * >     NameTypeMap;
        typedef TreeMap< uint64, Type * >   HashTypeMap;

        MIRROR_API NameTypeMap &GetNameTypeMap( void );
        MIRROR_API HashTypeMap &GetHashTypeMap( void );

        template < typename T >
        MirrorType< T > *GetType( void );

        template < typename T >
        MirrorType< T > *CreateType( cstr name );
    }
}

#endif
