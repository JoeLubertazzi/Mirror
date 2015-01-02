#ifndef MIRROR_H
#define MIRROR_H

namespace Mirror
{
    class Type;
    
    template < typename >
    class TypeModifier;
}

#include "Mirror_Export.h"
#include "Mirror_Types.h"
#include "Mirror_TypeTraits.h"

namespace Mirror
{
    MIRROR_API void             Initialize( void );
    MIRROR_API void             Uninitialize( void );

    template < typename T >
    MirrorType< T > *           AddType( cstr name );

    template < typename T >
    uint64                      GetTypeHash( void );

    /** Explicitly specialize this function to initialize registered types. */
    template < typename T >
    void                        InitializeType( const TypeModifier< T > &mod );
}

#include "Mirror.hpp"

#endif
