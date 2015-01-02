#ifndef MIRROR_TYPEMODIFIER_H
#define MIRROR_TYPEMODIFIER_H


namespace Mirror
{
    class Primitive;
}

#include "Mirror.h"
#include "Mirror_Settings.h"
#include "Mirror_Types.h"
#include "Mirror_TypeTraits.h"
#include "Mirror_Utility.h"

namespace Mirror
{
    template < typename T, typename MirrorT >
    class TypeModBase;

    template < typename T >
    class TypeModBase< T, Type >
    {
        public:
            MIRROR_DELETE_COPY_MOVE( TypeModBase );

        protected:
            TypeModBase( Type *type );

            MIRROR_DEFAULT_DEF_CTOR( TypeModBase );

            virtual MIRROR_DEFAULT_DTOR( TypeModBase );

        private:
            Type *_type;
    };

    template < typename T >
    class TypeModBase< T, Primitive >
        : public TypeModBase< T, Type >
    {
        public:
            void            SetSize( MIRROR_SIZE_TYPE size ) const;
            void            SetDefaultSize( void ) const;

        protected:
            TypeModBase( Primitive *prim );

        private:
            Primitive *_type;
    };

    template < typename T >
    class TypeModifier
        : public TypeModBase< T, typename TypeClassification< T >::type >
    {
        private:
            TypeModifier( MirrorType< T > *type );

        template < typename T >
        friend MirrorType< T > *AddType( cstr );
    };
}

#include "Mirror_TypeModifier.hpp"

#endif
