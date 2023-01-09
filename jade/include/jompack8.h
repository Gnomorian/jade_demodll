#if defined(JOM_PACKED8_ENABLED)

#if defined(ONE_BYTE_PACKING) || defined(TWO_BYTE_PACKING) || defined(FOUR_BYTE_PACKING)
#error oops Nested PACK8
#endif

#define EIGHT_BYTE_PACKING
#undef JOM_PACKED
#if defined(_MSC_VER)
#include <pshpack8.h>
#define JOM_PACKED
#elif defined(__IBMCPP__) 
#pragma options align=eightbyte
#define JOM_PACKED
#elif defined(__GNUC__) || defined(__GNUG__)
// #define JOM_PACKED __attribute__((aligned (8)))
#define JOM_PACKED	__attribute__((packed))
#endif

#else
#define JOM_PACKED
#endif /* defined(JOM_PACKED8_ENABLED) */
