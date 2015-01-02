#ifndef MIRROR_TYPEMODIFIER_HPP
#define MIRROR_TYPEMODIFIER_HPP

#include "Mirror_Primitive.h"

namespace Mirror
{
    template < typename T >
    TypeModBase< T, Type >::TypeModBase( Type *type )
        : _type( type )
    {
    }

    template < typename T >
    TypeModBase< T, Primitive >::TypeModBase( Primitive *prim )
        : _type( prim )
    {
    }

    template < typename T >
    void TypeModBase< T, Primitive >::SetSize( MIRROR_SIZE_TYPE size ) const
    {
        _type->i_SetSize( size );
    }

    template < typename T >
    void TypeModBase< T, Primitive >::SetDefaultSize( void ) const
    {
        SetSize( sizeof( T ) );
    }

    template < typename T >
    TypeModifier< T >::TypeModifier( MirrorType< T > *type )
        : TypeModBase< T, typename TypeClassification< T >::type >( type )
    {
    }
}

#endif
