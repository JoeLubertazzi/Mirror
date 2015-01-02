#include "Mirror.h"

namespace Mirror
{
    void Initialize( void )
    {
        AddType< void >( "void" );
        AddType< char >( "char" );
        AddType< short >( "short" );
        AddType< int >( "int" );
        AddType< long long >( "long long" );
        AddType< unsigned char >( "unsigned char" );
        AddType< unsigned short >( "unsigned short" );
        AddType< unsigned int >( "unsigned int" );
        AddType< unsigned long long >( "unsigned long long" );
        AddType< float >( "float" );
        AddType< double >( "double" );
    }

    void Uninitialize( void )
    {
    }
}
