#if defined(JADE_COMPACT) && defined(IN_MEMORY_STRUCTURE)
#define JOM_PACKED
#else
#if defined(JOM_PACKED1_ENABLED) || defined(JOM_PACKED2_ENABLED) || defined(JOM_PACKED4_ENABLED) || defined(JOM_PACKED8_ENABLED)

#if defined(ONE_BYTE_PACKING) || defined(TWO_BYTE_PACKING) || defined(FOUR_BYTE_PACKING) || defined(EIGHT_BYTE_PACKING)
#if defined(_MSC_VER)
#include <poppack.h>
#elif defined (__IBMCPP__)
#pragma options align=reset
#endif
#undef JOM_PACKED
#endif

#if defined(ONE_BYTE_PACKING)
#undef ONE_BYTE_PACKING
#elif defined(TWO_BYTE_PACKING)
#undef TWO_BYTE_PACKING
#elif defined(FOUR_BYTE_PACKING)
#undef FOUR_BYTE_PACKING
#elif defined(EIGHT_BYTE_PACKING)
#undef EIGHT_BYTE_PACKING
#endif
#define JOM_PACKED

#endif /* defined(JOM_PACKED1_ENABLED) || defined(JOM_PACKED2_ENABLED) || defined(JOM_PACKED4_ENABLED) || defined(JOM_PACKED8_ENABLED) */
#endif /* defined(JADE_COMPACT) && defined(IN_MEMORY_STRUCTURE) */
