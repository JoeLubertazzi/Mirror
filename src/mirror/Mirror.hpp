#ifndef MIRROR_HPP
#define MIRROR_HPP

#include "Mirror_Primitive.h"       // Primitive ctor
#include "Mirror_Settings.h"
#include "Mirror_Type.h"            // Type ctor
#include "Mirror_TypeModifier.h"
#include "Mirror_TypeTraits.h"

#include "internal/Mirror_Internal.h"

#include <typeinfo>

namespace Mirror
{
    namespace detail
    {
        template < typename T >
        MirrorType< T > *GetType( void )
        {
            // Across exes/dlls, a type's static pointer may not alias
            // depending on where the linker placed the instantiation of 
            // this templated function, so a mechanism must be put in place
            // to synchronize static type pointers across exes/dlls

            static typename TypeClassification< T >::type *s_Type;

            if ( !s_Type )
            {
                // Check if an entry for the type is already present
                auto &&hashMap = detail::GetHashTypeMap();

                auto &&it = hashMap.find( GetTypeHash< T >() );

                if ( it != hashMap.end() )
                {
                    // If so, patch the static pointer
                    s_Type = reinterpret_cast< MirrorType< T > * >( it->second );
                }
            }

            return s_Type;
        }

        template < typename T >
        MirrorType< T > *CreateType( cstr name )
        {
            // Get the static pointer of the type
            auto &&type = detail::GetType< T >();

            // If the type is not currently catalogued
            if ( !type )
            {
                uint64 hash = GetTypeHash< T >();

                // Construct the type
                type = new MirrorType< T >( hash, name );

                // Map the type by name and hash
                GetNameTypeMap().emplace( type->GetName(), type );
                GetHashTypeMap().emplace( hash, type );

                return type;
            }

            return nullptr;
        }
    }

    template < typename T >
    MirrorType< T > *AddType( cstr name )
    {
        // Create the type
        auto &&type = detail::CreateType< T >( name );
        
        // If the type was successfully created, initialize it
        if ( type )
            InitializeType< T >( TypeModifier< T >( type ) );

        return type;
    }

#ifndef MIRROR_CUSTOM_TYPE_HASH

    template < typename T >
    uint64 GetTypeHash( void )
    {
        static uint64 s_TypeHash = (uint64)( typeid( T ).hash_code() );

        return s_TypeHash;
    }

#endif

}

#endif
