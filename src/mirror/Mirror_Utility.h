#ifndef MIRROR_UTILITY_H
#define MIRROR_UTILITY_H

#define MIRROR_DELETE_DEF_CTOR( type )      type( void ) = delete
#define MIRROR_DELETE_DTOR( type )          ~type( void ) = delete
#define MIRROR_DELETE_COPY_CTOR( type )     type( const type & ) = delete
#define MIRROR_DELETE_MOVE_CTOR( type )     type( type && ) = delete
#define MIRROR_DELETE_COPY_ASSIGN( type )   type &operator=( const type & ) = delete
#define MIRROR_DELETE_MOVE_ASSIGN( type )   type &operator=( type && ) = delete

#define MIRROR_DELETE_COPY( type )          MIRROR_DELETE_COPY_CTOR( type ); MIRROR_DELETE_COPY_ASSIGN( type )
#define MIRROR_DELETE_MOVE( type )          MIRROR_DELETE_MOVE_CTOR( type ); MIRROR_DELETE_MOVE_ASSIGN( type )
#define MIRROR_DELETE_COPY_MOVE( type )     MIRROR_DELETE_COPY( type ); MIRROR_DELETE_MOVE( type )
#define MIRROR_DELETE_ALL( type )           MIRROR_DELETE_DEF_CTOR( type ); MIRROR_DELETE_DTOR( type ); MIRROR_DELETE_COPY_MOVE( type )

#define MIRROR_DEFAULT_DEF_CTOR( type )     type( void ) = default
#define MIRROR_DEFAULT_DTOR( type )          ~type( void ) = default
#define MIRROR_DEFAULT_COPY_CTOR( type )    type( const type & ) = default
#define MIRROR_DEFAULT_MOVE_CTOR( type )    type( type && ) = default
#define MIRROR_DEFAULT_COPY_ASSIGN( type )  type &operator=( const type & ) = default
#define MIRROR_DEFAULT_MOVE_ASSIGN( type )  type &operator=( type && ) = default

#define MIRROR_DEFAULT_COPY( type )         MIRROR_DEFAULT_COPY_CTOR( type ); MIRROR_DEFAULT_COPY_ASSIGN( type )
#define MIRROR_DEFAULT_MOVE( type )         MIRROR_DEFAULT_MOVE_CTOR( type ); MIRROR_DEFAULT_MOVE_ASSIGN( type )
#define MIRROR_DEFAULT_COPY_MOVE( type )    MIRROR_DEFAULT_COPY( type ); MIRROR_DEFAULT_MOVE( type )
#define MIRROR_DEFAULT_ALL( type )          MIRROR_DEFAULT_DEF_CTOR( type ); MIRROR_DEFAULT_DTOR( type ); MIRROR_DEFAULT_COPY_MOVE( type )

#endif
