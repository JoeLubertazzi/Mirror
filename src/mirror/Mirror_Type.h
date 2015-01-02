#ifndef MIRROR_TYPE_H
#define MIRROR_TYPE_H

#include "Mirror_Export.h"
#include "Mirror_Settings.h"
#include "Mirror_TypeCategory.h"
#include "Mirror_Types.h"
#include "Mirror_Utility.h"

#include "internal/Mirror_Internal.h" // Friend detail::CreateType

namespace Mirror
{
    class Type
    {
        public:
            MIRROR_API TypeCategory         GetCategory( void ) const;
            MIRROR_API uint64               GetHash( void ) const;
            MIRROR_API cstr                 GetName( void ) const;

            MIRROR_API bool                 operator==( const Type &other ) const;
            MIRROR_API bool                 operator!=( const Type &other ) const;

            MIRROR_DELETE_COPY_MOVE( Type );

        protected:
            Type( uint64 hash, cstr name, TypeCategory tc = TypeCategory::Type );

            virtual MIRROR_DEFAULT_DTOR( Type );

        private:
            TypeCategory    _category;
            uint64          _hash;
            int8            _name[ MIRROR_MAX_TYPE_NAME ];

        template < typename T >
        friend MirrorType< T > *detail::CreateType( cstr );
    };
}

#endif
