#ifndef MIRROR_PRIMITIVE_H
#define MIRROR_PRIMITIVE_H

namespace Mirror
{
    template < typename, typename >
    class TypeModBase;
}

#include "Mirror_Export.h"
#include "Mirror_Settings.h"
#include "Mirror_Type.h"
#include "Mirror_TypeCategory.h"
#include "Mirror_Types.h"

#include "internal/Mirror_Internal.h" // Friend detail::CreateType

namespace Mirror
{
    class Primitive
        : public Type
    {
        public:
            MIRROR_API MIRROR_SIZE_TYPE GetSize( void ) const;

        protected:
            MIRROR_API Primitive( uint64 hash, cstr name, TypeCategory tc = TypeCategory::Primitive );

        private:
            MIRROR_SIZE_TYPE _size;

            MIRROR_API void i_SetSize( MIRROR_SIZE_TYPE size );

        template < typename T >
        friend MirrorType< T > *detail::CreateType( cstr );

        template < typename, typename >
        friend class TypeModBase;
    };
}

#endif
