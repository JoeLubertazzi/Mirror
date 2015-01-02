#include "Mirror_Internal.h"

namespace Mirror
{
    namespace detail
    {
        NameTypeMap &GetNameTypeMap( void )
        {
            static NameTypeMap s_NameMap;

            return s_NameMap;
        }

        HashTypeMap &GetHashTypeMap( void )
        {
            static HashTypeMap s_HashMap;

            return s_HashMap;
        }
    }
}
