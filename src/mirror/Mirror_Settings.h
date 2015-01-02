#ifndef MIRROR_SETTINGS_H
#define MIRROR_SETTINGS_H

/** Defines the maximum length of a Type's name. */
#define MIRROR_MAX_TYPE_NAME 128

/** Defines the size type stored by Primitive types. Use either uint16, uint32 or uint64. */
#define MIRROR_SIZE_TYPE uint32

/** Uncomment this line to specify a custom definition of Mirror::GetTypeHash. 
 *  You can also define explicit specializations to provide hashes for specific
 *  types.
 */
//#define MIRROR_CUSTOM_TYPE_HASH

#endif
