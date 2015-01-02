#include "../Mirror_TypeModifier.h"

namespace Mirror
{
    template <>
    void InitializeType< void >( const TypeModifier< void > & )
    {
    }

    template <>
    void InitializeType< char >( const TypeModifier< char > &mod )
    {
        mod.SetDefaultSize();
    }

    template <>
    void InitializeType< short >( const TypeModifier< short > &mod )
    {
        mod.SetDefaultSize();
    }

    template <>
    void InitializeType< int >( const TypeModifier< int > &mod )
    {
        mod.SetDefaultSize();
    }

    template <>
    void InitializeType< long long >( const TypeModifier< long long > &mod )
    {
        mod.SetDefaultSize();
    }

    template <>
    void InitializeType< unsigned char >( const TypeModifier< unsigned char > &mod )
    {
        mod.SetDefaultSize();
    }

    template <>
    void InitializeType< unsigned short >( const TypeModifier< unsigned short > &mod )
    {
        mod.SetDefaultSize();
    }

    template <>
    void InitializeType< unsigned int >( const TypeModifier< unsigned int > &mod )
    {
        mod.SetDefaultSize();
    }

    template <>
    void InitializeType< unsigned long long >( const TypeModifier< unsigned long long > &mod )
    {
        mod.SetDefaultSize();
    }

    template <>
    void InitializeType< float >( const TypeModifier< float > &mod )
    {
        mod.SetDefaultSize();
    }

    template <>
    void InitializeType< double >( const TypeModifier< double > &mod )
    {
        mod.SetDefaultSize();
    }
}
