#if defined(JOM_PACKED4_ENABLED)

#if defined(ONE_BYTE_PACKING) || defined(TWO_BYTE_PACKING) || defined(EIGHT_BYTE_PACKING)
#error oops Nested PACK4
#endif

#define FOUR_BYTE_PACKING
#undef JOM_PACKED
#if defined(_MSC_VER)
#include <pshpack4.h>
#define JOM_PACKED
#elif defined(__IBMCPP__) 
#pragma options align=fourbyte
#define JOM_PACKED
#elif defined(__GNUC__) || defined(__GNUG__)
// #define JOM_PACKED __attribute__((aligned(4)))
#define JOM_PACKED	__attribute__((packed))
#endif

#else
#define JOM_PACKED
#endif /* defined(JOM_PACKED4_ENABLED) */
