#include "Mirror_Primitive.h"

namespace Mirror
{
    Primitive::Primitive( uint64 hash, cstr name, TypeCategory tc)
        : Type( hash, name, tc ), 
          _size( 0 )
    {
    }

    MIRROR_SIZE_TYPE Primitive::GetSize( void ) const
    {
        return _size;
    }

    MIRROR_API void Primitive::i_SetSize( MIRROR_SIZE_TYPE size )
    {
        _size = size;
    }
}
