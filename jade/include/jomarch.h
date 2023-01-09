/****************************************************************************

				P R O P R I E T A R Y   N O T I C E

	This software, in whole and in every part, is proprietary to Jade Software
	Corporation Limited at Christchurch, New Zealand and is not to be
	reproduced, used or disclosed except upon prior written permission of Jade
	Software Corporation Limited.

	COPYRIGHT (c) JADE SOFTWARE CORPORATION LIMITED 2005 - ALL RIGHTS RESERVED

****************************************************************************/

/*
**                     NOTICE   NOTICE   NOTICE
**
** This header is compiled in to C programs, avoid using C++ style // comments.
** Some C/C++ compilers when compiling C source code are accurate about the
** rules regarding what are legal C comment tokens.
**
*/

#ifndef JOMARCH_h
#define JOMARCH_h

/* ---------------------------------------------------------------------- */
/* Meaning and intent of various O/S based defines
 *
 * _Windows			Microsoft Windows
 *   _WIN32			Window Win32 and Win64
 *   _WIN64			Window Win64
 *   _WIN32_WCE     Pocket PC 2003/Mobile 5.0/Mobile 6.0
 * UNIX				A *nix variant
 *   _AIX			IBM AIX, (UNIX will also be defined)
 *   linux			GNU Linux, (UNIX will also be defined)
 *     __s390__     IBM S/390 hardware, (linux will also be defined)
 *     __s390x__    IBM zSeries hardware, (linux will also be defined)
 *     __powerpc__  IBM p/Series hardware (linux will also be defined)
 *     __i386__		Intel chip set
 *   sun                      GNU on Solaris, (UNIX will also be defined)
 *     __i386__               Intel chip set
 *   __APPLE__      Darwin, (UNIX will also be defined)
 *     __powerpc__  Apple hardware
 *
 * Used to determine what compiler is being used.  These values should not
 * be used to control O/S based choices.
 * __IBMCPP__, __GNUC__, __GNUG__, _MSC_VER
 *
 * Used to determine what feature content is available/implemented
 * JADE_COMPACT     Feature restricted version, appropriate for PDA type devices
 *
 */


#define __STDC_LIMIT_MACROS   /* ensure xyz_MIN and xyz_MAX macros are defined */

/* ---------------------------------------------------------------------- */
/* AIX/GNU/UNIX specifics                                                 */
#if defined(_AIX) || defined(linux) || defined(__APPLE__)
#if !defined(UNIX)
#define UNIX
#endif

/* pthread.h  **MUST** be first header file included in a UNIX multithreaded app */
#include <pthread.h>
#if !defined(_THREAD_SAFE)
#define _THREAD_SAFE
#endif
#if !defined(_REENTRANT)
#define _REENTRANT
#endif

/* undefine some unknown pragmas for AIX */
#if !defined(__IBMCPP__)
#define hdrstop
#endif
#define argsused

typedef int		BOOL;		/* Equilivent as <windef.h> for UNIX */

#endif /* _AIX */

#if !defined(__GNUC__) && !defined(__GNUG__)
#define  __attribute__(x)  /*NOTHING*/
#endif

/* ---------------------------------------------------------------------- */
/* Windows CE specifics                                                   */
#if defined(_WIN32_WCE)
#if _WIN32_WCE < 0x420
#error Jade requires that _WIN32_WCE be atleast 0x420
#endif
#if !defined(CE_MAJOR_VER)
#define CE_MAJOR_VER 0x0004
#endif
#if !defined(JADE_COMPACT)
#define JADE_COMPACT
#endif
#endif

#if defined(_WIN64) || defined(_M_IA64) || defined(_M_X64) || defined(_LP64)
#define JADE_64BIT_NODE
#endif

#if defined(_MSC_VER) // && defined(JADE_64BIT_NODE)
//#pragma warning(4: 4365)		// conversion from 'type_1' to 'type_2', signed/unsigned mismatch
//#pragma warning(4: 4242)		// conversion from 'type1' to 'type2', possible loss of data (i.e. int to char)
#pragma warning(4: 4254)		// conversion from 'type1' to 'type2', possible loss of data (i.e. A larger bit field was assigned to a smaller bit field)
//#pragma warning(4: 4287)		// unsigned/negative constant mismatch
//#pragma warning(4: 4302)		// truncation from 'type 1' to 'type 2' (i.e char x = (char)&integer)
//#pragma warning(4: 4826)		// Conversion from 'type1 ' to 'type_2' is sign-extended. This may cause unexpected runtime behavior.
#endif

#define BIT_VECTOR_MULTIPLIER	4		/* RS::Property::BIT_VECTOR_MULTIPLIER */

#if defined(JADE_COMPACT)
#if !defined(UNICODE)
#error UNICODE and JADE_COMPACT must be defined together
#endif
#define STRSAFE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE
#define _SCL_SECURE_NO_DEPRECATE
#define _ATL_SECURE_NO_DEPRECATE
#define _AFX_SECURE_NO_DEPRECATE
#undef ENABLE_SDS
// for jade compact audit records are unpacked 
#define AUDIT_RECORD_ALIGNMENT 4

#else  // !JADE_COMPACT
#define ENABLE_DBPARTITIONS
#if !defined(RODB)
#define ENABLE_DELTADB
#define ENABLE_SDS
#define ENABLE_DBENCRYPTION
#define ENABLE_RPCSSPIAUTH
#endif
// for non jade compact audit records packed (no realignment)
#define AUDIT_RECORD_ALIGNMENT 1
#endif // JADE_COMPACT

#if defined(_WIN32_WCE) || defined(__IBMCPP__) || defined(__GNUC__) || (defined(_MSC_VER) && _MSC_VER == 1200) // JAX uses VS6==1200
#define _W64
#endif

/* ---------------------------------------------------------------------- */

#define JOM_PACKED1_ENABLED
#define JOM_PACKED2_ENABLED
#define JOM_PACKED4_ENABLED
#define JOM_PACKED8_ENABLED

// Include assert.h here to ensure default assert() macro is defined
#include <assert.h>
#include <limits.h>

#if CHAR_BIT != 8
#error 8-bit character type required
#endif

/* use _Windows for non UNIX windows code */
#if !defined (_Windows) && !defined(UNIX) && defined(_WIN32)
#define _Windows
#define NOMINMAX
#if defined(INVALID_SET_FILE_POINTER)
/* Find something unique to decide if the Microsoft SDK header files are installed */
#define _Windows_SDK
#endif
#endif /* _Windows */
#if defined (UNIX)
/* make sure _Windows not defined */
#undef _Windows
#endif

#if defined(__GNUC__) || defined(__GNUG__)
#define JOM_NOINLINE	__attribute__((noinline))
#elif defined(_Windows)
#define JOM_NOINLINE	__declspec(noinline)
#else
#error Need specific compiler support to explicitly disable inlining
#endif

#if defined(__GNUC__) || defined(__GNUG__)
#define JOM_LIKELY(cond)	(__builtin_expect(!!(cond), 1))
#define JOM_UNLIKELY(cond)	(__builtin_expect(!!(cond), 0))
#else
#define JOM_LIKELY(cond)	(cond)
#define JOM_UNLIKELY(cond)	(cond)
#endif

#if defined(__GNUC__) || defined(__GNUG__)
#define JOM_USED	__attribute__((used))
#elif defined(_Windows)
// see KB# 87634
#define JOM_USED	extern
#else
#error Need specific compiler support to mark declaration as used
#endif

#if defined(_MSC_VER)
#ifndef MSVC
#define MSVC		// Not used by Jade
#endif /* MSVC */
#endif /* _MSC_VER */

/* ---------------------------------------------------------------------- */
/* Include non-portable header files if required                          */

/* Used to be conditional on NON_PORTABLE being defiend, but have removed */
/* this for convenience                                                   */

#if defined(_Windows)
#if defined(_WIN32_WINNT)
#undef		_WIN32_WINNT
#endif

#if defined(_MSC_VER) && _MSC_VER >= 1800		/* VS 2013 */
#define _APISET_ERRORHANDLING_VER 0x0101
#endif

#if !defined(WIN32_LEAN_AND_MEAN)
#define WIN32_LEAN_AND_MEAN
#endif
#if !defined(STRICT)
#define STRICT
#endif

#pragma warning( push, 3 )
#if _MSC_VER >= 1300
 // Allow use of any win2k and higher APIs
#ifdef _Jade_WIN32_WINNT
  #define	_WIN32_WINNT _Jade_WIN32_WINNT
#else
	#define _WIN32_WINNT 0x0600 // Windows vista level features
#endif // _Jade_WIN32_WINNT

#ifndef _WINSOCKAPI_	/* if winsock.h not already included -- include winsock2.h */
  #include <winsock2.h>
  #include <ws2tcpip.h>
 #endif
#else
  // ATL headers used by the JADE Rose Link don't compile under VC6 with _WIN32_WINNT = 0x0500
  #define		_WIN32_WINNT 0x0400
#endif /* _MSC_VER >= 1300 */

#include <windows.h>
#pragma warning( pop )
#endif /* _Windows */

/* ---------------------------------------------------------------------- */

/* ---------------------------------------------------------------------- */
/* Define declaration specifiers                                          */

#if defined(_Windows)

#if defined(_MSC_VER)
#define DllExport 		__declspec(dllexport)
#define DllImport 		__declspec(dllimport)
#define CLASS_IMPORT 	DllImport
#define CLASS_EXPORT 	DllExport
#define CLASS_INLINE
#define DEPRECATEDCPP	__declspec(deprecated)
#endif /* defined(_MSC_VER) */

#define JOMAPI			__stdcall
#define WINDOWS_API		__stdcall

#else /* _Windows */

/* for aix vac compiler defined export/import */
#if defined(__IBMCPP__) && (__IBMCPP__ >= 500) && defined(IBMCPP_VAC)
#define DllExport 		__declspec(dllexport)
#define DllImport 		__declspec(dllimport)
#define CLASS_IMPORT	DllImport
#define CLASS_EXPORT	DllExport
#else   /* __IBMCPP__ >= 500 */
/* for aix xlc compiler don't define export/import */
#define DllExport
#define DllImport
#define CLASS_IMPORT
#define CLASS_EXPORT
#endif
#define CLASS_INLINE 	inline
#define JOMAPI
#if defined(PASCAL)
#undef PASCAL
#endif
#define PASCAL
#define WINDOWS_API
#define UNALIGNED
#define DEPRECATEDCPP

#endif /* _Windows */
/* ---------------------------------------------------------------------- */

typedef unsigned char	UInt8;
typedef signed char		SInt8;

/* 16-bit integral types for use where a 2-byte integer mapping is required */
#if INT_MAX == 32767
typedef int				Int16;
typedef unsigned 		UInt16;
typedef signed 			SInt16;
#elif SHRT_MAX == 32767
typedef short			Int16;
typedef unsigned short  UInt16;
typedef signed short  	SInt16;
#elif SCHAR_MAX == 32767
typedef signed char     Int16;
typedef unsigned char   UInt16;
typedef signed char   	SInt16;
#elif LONG_MAX == 32767
typedef long		Int16;
typedef unsigned long   UInt16;
typedef signed long   	SInt16;
#else
#error  16-bit integral type not found
#endif

/* 32-bit integral types for use where a 4-byte integer mapping is required */
#if INT_MAX == 0x7FFFFFFFL
typedef int				Int32;
typedef unsigned 		UInt32;
typedef signed 			SInt32;
#elif LONG_MAX == 0x7FFFFFFFL
typedef long			Int32;
typedef unsigned long	UInt32;
typedef signed long		SInt32;
#else
#error  32-bit integral type not found
#endif

/* 64-bit integral types for use where an 8-byte integer mapping is required */

#if defined(_Windows)

#include <stdint.h>

/* supported by MSVC and BC 5.02 and above */
typedef	__int64					Int64;
typedef unsigned __int64		UInt64;
typedef signed __int64			SInt64;
/* minimum signed 64 bit value */
#undef INT64_MIN
#define INT64_MIN				_I64_MIN
/* maximum signed 64 bit value */
#undef INT64_MAX
#define INT64_MAX				_I64_MAX
/* maximum unsigned 64 bit value */
#undef UINT64_MAX
#define UINT64_MAX				_UI64_MAX
/* format string */
#define	SI64_UTF8FMT			"%I64d"
#define	UI64_UTF8FMT			"%I64u"
#define	SI64_WIDEFMT			L"%I64d"
#define	UI64_WIDEFMT			L"%I64u"
#define	SI64_FMT				TEXT("%I64d")
#define	UI64_FMT				TEXT("%I64u")
#define	UI64_FMT_STR			TEXT("I64u")
#define	SI64_FMTn(n)			TEXT("%") TEXT(#n) TEXT("I64d")
#define	UI64_FMTn(n)			TEXT("%") TEXT(#n) TEXT("I64u")
#define XI64_FMT                TEXT("0x%016I64x")
#define	XI64_FMTn(n)			TEXT("%") TEXT(#n) TEXT("I64X")
#if defined(JADE_64BIT_NODE)
#define	SI32_FMT				TEXT("%I32d")
#define	UI32_FMT				TEXT("%I32u")
#define	UI32_FMT_STR			TEXT("I32u")
#define	Size_FMT				TEXT("%I32u")
#define	SSize_FMT				TEXT("%I32d")
#define	SI3264_FMT				TEXT("%I64d")
#define	UI3264_FMT				TEXT("%I64u")
#define	UI3264_FMTn(n)			TEXT("%") TEXT(#n) TEXT("I64u")
#define XI3264_FMT              TEXT("0x%016I64x")
#define	XI3264_FMTn(n)			TEXT("%") TEXT(#n) TEXT("I64X")
#define	FDHAND_FMT				TEXT("%I64d")			/*For printing Windows Handles/Sockets and *NIX FileDescriptors/Sockets */
#elif defined(_WIN32_WCE)
#define	SI32_FMT				TEXT("%d")
#define	UI32_FMT				TEXT("%u")
#define	UI32_FMT_STR			TEXT("u")
#define	Size_FMT				TEXT("%u")
#define	SSize_FMT				TEXT("%d")
#define	SI3264_FMT				TEXT("%d")
#define	UI3264_FMT				TEXT("%u")
#define	UI3264_FMTn(n)			TEXT("%") TEXT(#n) TEXT("u")
#define XI3264_FMT              TEXT("0x%016x")
#define	XI3264_FMTn(n)			TEXT("%") TEXT(#n) TEXT("X")
#define	FDHAND_FMT				TEXT("%d")			/*For printing Windows Handles/Sockets and *NIX FileDescriptors/Sockets */
#else
#define	SI32_FMT				TEXT("%I32d")
#define	UI32_FMT				TEXT("%I32u")
#define	UI32_FMT_STR			TEXT("I32u")
#define	Size_FMT				TEXT("%I32u")
#define	SSize_FMT				TEXT("%I32d")
#define	SI3264_FMT				TEXT("%I32d")
#define	UI3264_FMT				TEXT("%I32u")
#define	UI3264_FMTn(n)			TEXT("%") TEXT(#n) TEXT("I32u")
#define XI3264_FMT              TEXT("0x%016I32x")
#define	XI3264_FMTn(n)			TEXT("%") TEXT(#n) TEXT("I32X")
#define	FDHAND_FMT				TEXT("%I32d")			/*For printing Windows Handles/Sockets and *NIX FileDescriptors/Sockets */
#endif

#elif defined(__APPLE__)

#include <stdint.h>
typedef int64_t					Int64;
typedef uint64_t				UInt64;
typedef int64_t					SInt64;
#if !defined(INT64_MAX)
# define INT64_MIN		LLONG_MIN
# define INT64_MAX		LLONG_MAX
# define UINT64_MAX		ULLONG_MAX
#endif
#define	SI32_FMT				TEXT("%d")
#define	UI32_FMT				TEXT("%u")
#define	UI32_FMT_STR			TEXT("u")
#define SI64_UTF8FMT            "%lld"
#define UI64_UTF8FMT            "%llu"
#define SI64_WIDEFMT            L"%lld"
#define UI64_WIDEFMT            L"%llu"
#define SI64_FMT				TEXT("%lld")
#define UI64_FMT				TEXT("%llu")
#define UI64_FMT_STR			TEXT("llu")
#define SI64_FMTn(n)			TEXT("%") TEXT(#n) TEXT("lld")
#define UI64_FMTn(n)			TEXT("%") TEXT(#n) TEXT("llu")
#define XI64_FMT				TEXT("0x%016llx")
#define XI64_FMTn(n)			TEXT("%") TEXT(#n) TEXT("llX")
#define	FDHAND_FMT				TEXT("%u")				/*For printing Windows Handles/Sockets and *NIX FileDescriptors/Sockets */
#if defined(JADE_64BIT_NODE)
#define	Size_FMT				TEXT("%u")
#define	SSize_FMT				TEXT("%d")
#define	SI3264_FMT				TEXT("%lld")
#define	UI3264_FMT				TEXT("%llu")
#define	UI3264_FMTn(n)			TEXT("%") TEXT(#n) TEXT("llu")
#define XI3264_FMT              TEXT("0x%016llx")
#define	XI3264_FMTn(n)			TEXT("%") TEXT(#n) TEXT("llX")
#else
#define	Size_FMT				TEXT("%u")
#define	SSize_FMT				TEXT("%d")
#define	SI3264_FMT				TEXT("%d")
#define	UI3264_FMT				TEXT("%u")
#define	UI3264_FMTn(n)			TEXT("%") TEXT(#n) TEXT("u")
#define XI3264_FMT              TEXT("0x%016x")
#define	XI3264_FMTn(n)			TEXT("%") TEXT(#n) TEXT("X")
#endif

#elif defined(__GNUC__) || defined(_AIX)

#if defined(_AIX)
#include <sys/types.h>
#elif defined(__GNUC__) && !defined(sun)
#include <stdint.h>
#endif
#if defined(__64BIT__)
typedef	long				Int64;
typedef	unsigned long		UInt64;
typedef	signed long			SInt64;
#else
typedef	long long			Int64;
typedef	unsigned long long	UInt64;
typedef	signed long long	SInt64;
#endif
#if !defined(INT64_MAX)
# define INT64_MIN		LLONG_MIN
# define INT64_MAX		LLONG_MAX
# define UINT64_MAX		ULLONG_MAX
#endif
#define	SI32_FMT				TEXT("%d")
#define	UI32_FMT				TEXT("%u")
#define	UI32_FMT_STR			TEXT("u")
#define	SI64_UTF8FMT			"%lld"
#define	UI64_UTF8FMT			"%llu"
#define	SI64_FMT				TEXT("%lld")
#define	UI64_FMT				TEXT("%llu")
#define	UI64_FMT_STR			TEXT("llu")
#define SI64_WIDEFMT            L"%lld"
#define UI64_WIDEFMT            L"%llu"
#define	SI64_FMTn(n)			TEXT("%") TEXT(#n) TEXT("lld")
#define	UI64_FMTn(n)			TEXT("%") TEXT(#n) TEXT("llu")
#define XI64_FMT                TEXT("0x%016llx")
#define	XI64_FMTn(n)			TEXT("%") TEXT(#n) TEXT("llX")
#define	FDHAND_FMT				TEXT("%u")			/*For printing Windows Handles/Sockets and *NIX FileDescriptors/Sockets */
#if defined(JADE_64BIT_NODE)
#define	Size_FMT				TEXT("%u")
#define	SSize_FMT				TEXT("%d")
#define	SI3264_FMT				TEXT("%lld")
#define	UI3264_FMT				TEXT("%llu")
#define	UI3264_FMTn(n)			TEXT("%") TEXT(#n) TEXT("llu")
#define XI3264_FMT              TEXT("0x%016llx")
#define	XI3264_FMTn(n)			TEXT("%") TEXT(#n) TEXT("llX")
#else
#define	Size_FMT				TEXT("%u")
#define	SSize_FMT				TEXT("%d")
#define	SI3264_FMT				TEXT("%d")
#define	UI3264_FMT				TEXT("%u")
#define	UI3264_FMTn(n)			TEXT("%") TEXT(#n) TEXT("u")
#define XI3264_FMT              TEXT("0x%016x")
#define	XI3264_FMTn(n)			TEXT("%") TEXT(#n) TEXT("X")
#endif

#else
#error  64-bit integral type not known
#endif

// all types used externally to this module must map to the same JADE type
// which may in turn be mapped to a platform specific type in jomarch. The required mapping
// or cast to an O/S or run time library type must be encapsulated in the jomos 
// implementation. This is required to insulate users of jomos interfaces from the
// underlying platform types

typedef UInt32			BuffSize;
typedef UInt64			FileSize;
typedef UInt64			FileOffset;

/* types that have dynamic sizes */
#if defined(JADE_64BIT_NODE)
typedef	Int64			Int3264;
typedef	SInt64			SInt3264;
typedef	UInt64			UInt3264;
typedef	Int64			Int32_PTR;
typedef	UInt64			UInt32_PTR;
#define INT3264_MAX		INT64_MAX
#define UINT3264_MAX	UINT64_MAX
#else
typedef	Int32			Int3264;
typedef	SInt32			SInt3264;
typedef	UInt32			UInt3264;
typedef	_W64 Int32		Int32_PTR;
typedef	_W64 UInt32		UInt32_PTR;
#define INT3264_MAX		INT_MAX
#define UINT3264_MAX	UINT_MAX
#endif

#ifndef SIZE_T_MAX
#if defined(JADE_64BIT_NODE)
#define SIZE_T_MAX		UINT64_MAX
#else
#define SIZE_T_MAX		UINT_MAX
#endif
#endif

// Do not use SIZE_MAX.  It isn't available on all architectures ans is too easily confused with our Size_MAX. Only use
// our SIZE_T_MAX.  We undefine SIZE_MAX here and if it wasn't for others possibly including our headers then that would
// be the end of it.  Unfortunately though we have to redefine it for them, to our SIZE_T_MAX.
#undef SIZE_MAX
#define SIZE_MAX		SIZE_T_MAX

#define Size_MAX		UINT_MAX			/* Must valid with respect to typedef ... Size in jomtypes.h */
#define SSize_MAX		INT_MAX

/* define our own ANSI/Unicode character types and TEXT macros */
#include <stddef.h>
#include <wchar.h>
typedef wchar_t					UnicodeChar;
#if !defined(UNICODE)
typedef char					Character;
typedef unsigned char			UCharacter;
#define CHARACTER_MAX			UCHAR_MAX	/* Jade Character is considered unsigned by the Interpreter */

#define __TEXT(quote)   		quote
#define TEXT(quote)     		__TEXT(quote)
#else
#if defined(linux)
#include <wctype.h>
#endif
typedef wchar_t					Character;
#define CHARACTER_MAX			WCHAR_MAX
#if defined(_MSC_VER)
typedef unsigned short			UCharacter;
#elif defined(__IBMCPP__)
typedef unsigned short			UCharacter;
#elif defined(__GNUC__) || defined(__GNUG__)
#if defined(_AIX)
typedef unsigned short			UCharacter;
#else
typedef unsigned long			UCharacter;
#endif
#endif
#define __TEXT(quote)   		L##quote
#define TEXT(quote)     		__TEXT(quote)
#endif /* !UNICODE */

#define UTF8_CHARACTER_SIZE		4			/*RS GlbConst Utf8CharacterSize*/
#define UTF8TEXT(doublequoted)	((const unsigned char *)doublequoted)

/*---------------------------------------------------------------------- */
/*  These CAST macros encapsulate the new cast syntax in the ANSI/ISO */
/*  working paper. */
/* */
/*  Usage: */
/* */
/*  DYNAMICIC_CAST(targetType,object) */
/*      Converts the data object referred to by 'object' into the type */
/*      referred to by 'targetType'. When using a compiler that supports */
/*      new style casts, this is done with dynamic_cast<> and will */
/*		return 0 if the cast cannot be done. */
/*      When using a compiler that does not support new style casts, this */
/*      is done with an old style dangerous cast. */
/* */
/*  STATIC_CAST(targetType,object) */
/*      Converts the data object referred to by 'object' into the type */
/*      referred to by 'targetType'. When using a compiler that supports */
/*      new style casts, this is done with static_cast<> and will fail */
/*      if the cast cannot be done without runtime type information. */
/*      When using a compiler that does not support new style casts, this */
/*      is done with an old style dangerous cast. */
/* */
/*  CONST_CAST(targetType,object) */
/*      Converts the data object referred to by 'object' into the type */
/*      referred to by 'targetType'. When using a compiler that supports */
/*      new style casts, this is done with const_cast<> and will fail */
/*      if the cast changes the type of the object in any way other than */
/*      adding or removing const and volatile qualifiers. */
/*      When using a compiler that does not support new style casts, this */
/*      is done with an old style dangerous cast. */

#if !defined(UNIX) || (defined(__IBMCPP__) && (__IBMCPP__ >= 400))
#define DYNAMIC_CAST(targetType,object)		dynamic_cast<targetType>(object)
#if !defined(STATIC_CAST)
#define STATIC_CAST(targetType,object)		static_cast<targetType>(object)
#endif
#define CONST_CAST(targetType,object)		const_cast<targetType>(object)
#define REINTERPRET_CAST(targetType,object)	reinterpret_cast<targetType>(object)

#else  /* !defined(UNIX) || (defined(__IBMCPP__) && (__IBMCPP__ >= 400)) */

#if defined(__IBMCPP__)
#define DYNAMIC_CAST(targetType,object)		dynamic_cast<targetType>(object)
#else
#define DYNAMIC_CAST(targetType,object)		((targetType)(object))
#endif
#define STATIC_CAST(targetType,object)		((targetType)(object))
#define CONST_CAST(targetType,object)		((targetType)(object))
#define REINTERPRET_CAST(targetType,object)	((targetType)(object))

#endif /* !defined(UNIX) || (defined(__IBMCPP__) && (__IBMCPP__ >= 400)) */

/* Which exception handing technique does Jade use */
/* Either USE_CPP_EXCEPTIONS or USE_SEH_EXCEPTIONS */
#if defined(USE_CPP_EXCEPTIONS) && defined(USE_SEH_EXCEPTIONS)
#error  USE_CPP_EXCEPTIONS and USE_SEH_EXCEPTIONS both can not be defined
#endif
#if !defined(USE_CPP_EXCEPTIONS) && !defined(USE_SEH_EXCEPTIONS)
/* Windows now uses CEH by default */
#define	    USE_CPP_EXCEPTIONS
#endif

#if defined(__cplusplus)
/* Useful for avoiding Microsoft "warning C4127: conditional expression is constant"
** Rather than "if (sizeof(void *) == 4)" use "if (constant_expression(sizeof(void *) == 4))"
*/
template<typename T>
T constant_expression(T v) {return v;}
#else
#define constant_expression(v) ((void)0, v)
#endif

#define	_USERENTRY

#define EXTENDED_LENGTH_PATHS

/* miscellaneous string lengths*/
#if !defined(JADE_COMPACT) && defined(EXTENDED_LENGTH_PATHS)
#define	JADE_MAX_PATH					(MAX_PATH * 2)
#else
#define	JADE_MAX_PATH					MAX_PATH
#endif // defined(EXTENDED_LENGTH_PATHS)
#if defined(NI_MAXHOST)
#define JOM_MAX_COMPUTERNAME_LENGTH		NI_MAXHOST
#else
#define JOM_MAX_COMPUTERNAME_LENGTH		255
#endif
#if defined(NI_MAXSERV)
#define JOM_MAX_SERVICENAME_LENGTH		NI_MAXSERV
#else
#define JOM_MAX_SERVICENAME_LENGTH		255
#endif

#define JADE_DATAFILE_EXT					TEXT(".dat")
#define JADE_SYSFILE_EXT					TEXT(".bin")
#define	JADE_UNIX_DIRECTORY_SEPARATOR		TEXT('/')
#define	JADE_WINDOWS_DIRECTORY_SEPARATOR	TEXT('\\')
#if defined (_Windows)
#define	JADE_DIRECTORY_SEPARATOR		JADE_WINDOWS_DIRECTORY_SEPARATOR
#else
#define	JADE_DIRECTORY_SEPARATOR		JADE_UNIX_DIRECTORY_SEPARATOR
#endif
#define JADE_SNAPCONTROLFILE_EXT			TEXT(".snap")

#if defined (UNIX)
/* always disable dllheaps on unix -- the linker will not resolve the new/delete references */
/*  within each library */
#define DISABLE_DLLHEAPS
#endif

/* ---------------------------------------------------------------------- */

#ifndef BYTE_ORDER
/*
 * Definitions for byte order,
 * according to byte significance from low address to high.
 */
#define LITTLE_ENDIAN   1234    /* least-significant byte first (vax) */
#define BIG_ENDIAN      4321    /* most-significant byte first (IBM, net) */
#define PDP_ENDIAN      3412    /* LSB first in word, MSW first in long (pdp) */

#if defined(_AIX) || defined(_S390) || defined(__powerpc__)
#define BYTE_ORDER      BIG_ENDIAN
#else
#define BYTE_ORDER      LITTLE_ENDIAN
#endif

/*
 *
 * The above defines are normally used as follows
 *
 * #if BYTE_ORDER == LITTLE_ENDIAN
 * #endif
 * #if BYTE_ORDER == BIG_ENDIAN
 * #endif
 */
#endif /* BYTE_ORDER */

// used to document variable length array members at end of structures
#define VARIABLE				1

// offsetof not allowed on non-POD on some compilers so define here
#if defined(_MSC_VER) || (defined(__GNUG__) && __GNUG__ >= 4)
#define OFFSETOF(T,m)	offsetof(T,m)
#else
#define OFFSETOF(T,m)	((size_t)(&((T*)1)->m)-1)
#endif
#endif /* JOMARCH_h */


