#include "Mirror_Type.h"

#include <cstring>

namespace Mirror
{
    Type::Type( uint64 hash, cstr name, TypeCategory tc )
        : _category( tc ),
          _hash( hash )
    {
        std::strcpy( _name, name );
    }

    TypeCategory Type::GetCategory( void ) const
    {
        return _category;
    }

    uint64 Type::GetHash( void ) const
    {
        return _hash;
    }

    cstr Type::GetName( void ) const
    {
        return _name;                                                           
    }

    bool Type::operator==( const Type &other ) const
    {
        return this == &other;
    }

    bool Type::operator!=( const Type &other ) const
    {
        return this != &other;
    }
}
