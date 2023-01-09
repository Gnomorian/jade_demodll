#if defined(JADE_COMPACT) && defined(IN_MEMORY_STRUCTURE)
#define JOM_PACKED
#else

#if defined(JOM_PACKED1_ENABLED) 

#if defined(TWO_BYTE_PACKING) || defined(FOUR_BYTE_PACKING) || defined(EIGHT_BYTE_PACKING)
#error oops Nested PACK1
#endif

#define ONE_BYTE_PACKING
#undef JOM_PACKED
#if defined(_MSC_VER)
#include <pshpack1.h>
#define JOM_PACKED
#elif defined(__IBMCPP__) 
#pragma options align=packed
#define JOM_PACKED
#elif defined(__GNUC__) || defined(__GNUG__)
// #define JOM_PACKED	__attribute__((aligned (1)))
#define JOM_PACKED	__attribute__((packed))
#endif

#else
#define JOM_PACKED
#endif /* defined(JOM_PACKED1_ENABLED) */
#endif /* defined(JADE_COMPACT) && defined(IN_MEMORY_STRUCTURE) */
