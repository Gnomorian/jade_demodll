/****************************************************************************

				P R O P R I E T A R Y   N O T I C E

	This software, in whole and in every part, is proprietary to Jade Software
	Corporation Limited at Christchurch, New Zealand and is not to be
	reproduced, used or disclosed except upon prior written permission of Jade
	Software Corporation Limited.

	COPYRIGHT (c) JADE SOFTWARE CORPORATION LIMITED 2005 ALL RIGHTS RESERVED

****************************************************************************/

#pragma once 

#include <memory.h>

#include "jomdefs.h"
#include "jomerrs.h"
#include "jomstr.h"
#include "jomoid.hpp"
#include "jomerrs.h"

#ifndef JOMSTR_EXPORT
#define JOMSTR_EXPORT DllImport
#endif

/* --------------------------------------------------------------------------*/
// If we're building for Win32 but haven't included windows.h, we must
// prototype the required Windows API's here
#if defined(_Windows) && !defined(_WINDOWS_)

#ifdef __cplusplus
extern "C" {
#endif

char *        __stdcall lstrcpynA(char * pStr1, const char * pStr2, int maxLength);
UnicodeChar * __stdcall lstrcpynW(UnicodeChar * pStr1, const UnicodeChar * pStr2, int maxLength);

#if !defined(_WIN32_WCE)
int           __stdcall lstrlenA(const char * pStr);
int           __stdcall lstrlenW(const UnicodeChar * pStr);
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#ifdef UNICODE
#  if defined(_WIN32_WCE)
#    define STRCPYN	wcsncpy
#    define STRLEN	wcslen
#  else
#    define STRCPYN	lstrcpynW
#    define STRLEN	lstrlenW
#  endif
#else
#  define STRCPYN	lstrcpynA
#  define STRLEN	lstrlenA
#endif /* UNICODE */

#elif defined(UNIX)
// UNIX version

#ifdef UNICODE
#  define STRCPYN	wcsncpy
#  define STRLEN	wcslen
#else
#  define STRCPYN	strncpy
#  define STRLEN	strlen
#endif /* UNICODE */

#else
// _Windows code with <windows.h> included

#define STRCPYN	lstrcpyn
#define STRLEN	lstrlen

#endif /* _Windows && !_WINDOWS_ */
/* --------------------------------------------------------------------------*/

const Size	UseNullTerminatedLength = (Size) ~0;

/* ----- Memory Address support inlines --------------------------------------------*/

// The Jade MemoryAddress primitive type is used to store native (C/C++) pointers (either a 32-bit or 64-bit value depending on the build configuration)
// Pointers can be passed between nodes (eg client <-> server), but must only be dereferenced on the node where the pointer was initialised. The
// JomMemorySpaceId is a unique identifier for each node. This value is inserted into the MemoryAddress structure to provide a way for an external method
// to determine if a pointer can safely be used.

inline JomMemorySpaceId
jomGetMemorySpaceId()
{
#if defined(josGetMemorySpaceId)
	return josGetMemorySpaceId();
#else
#if defined(JOMUTIL_EXPORT)
	extern JOMUTIL_EXPORT JomMemorySpaceId jomutilMemorySpaceId;
#else
	extern DllImport JomMemorySpaceId jomutilMemorySpaceId;
#endif

	return jomutilMemorySpaceId;
#endif
}

inline int
setDskMemoryAddress(DskMemoryAddress& memaddr, void* pAddrs, JomMemorySpaceId memSpaceId = JomMemorySpaceUnknown)
{
	// a null pointer is a special case: the memory space id is 0
	memaddr.memSpaceId = pAddrs ? (memSpaceId == JomMemorySpaceUnknown ? jomGetMemorySpaceId() : memSpaceId) : JomMemorySpaceNull;
	memaddr.u.maxSpaceHolder = 0;		// ensure the full address area is cleared
	memaddr.u.pVoid = pAddrs;
	return J_OK;
}

inline bool
isDskMemoryAddressValid(const DskMemoryAddress& memaddr, JomMemorySpaceId memSpaceId = JomMemorySpaceUnknown)
{
	// return true if the pointer is null or is valid in the address space of the current node
	return memaddr.memSpaceId == JomMemorySpaceNull || memaddr.memSpaceId == (memSpaceId == JomMemorySpaceUnknown ? jomGetMemorySpaceId() : memSpaceId);
}

inline bool
isDskMemoryAddressValidNotNull(const DskMemoryAddress& memaddr)
{
	return memaddr.memSpaceId == jomGetMemorySpaceId();
}

inline void*
getDskMemoryAddressPointer(const DskMemoryAddress& memaddr)
{
	return memaddr.u.pVoid;
}


/* ----- Param setting functions --------------------------------------------*/

// Have to use a reference parameter (&param) in the functions below to avoid
// compiler warning on call: "Possible use of xxxx before definition"

inline int paramSetAnyList(DskParam& param, Size size, EntryCount entries = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format = DSKANYLIST;
	param.header.usage = usage;
	param.header.more = Done;
	param.body.anyList.entries = entries;
	param.body.anyList.size = size;
	return J_OK;
}

inline int paramSetBinaryBlock(DskParam& param, BYTE* pValue, Size length, Size offset= 0, Size maxLength=0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKBINARYBLOCKPOINTER;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.binaryBlockPtr.bytePtr = pValue;
	param.body.binaryBlockPtr.length  = length;
	param.body.binaryBlockPtr.offset  = offset;
	param.body.binaryBlockPtr.maxLength	= maxLength ? maxLength : length;
	return J_OK;
}

inline int paramSetBinaryBlock(DskParam& param, const BYTE* pValue, Size length, Size offset= 0, Size maxLength=0, PUsage usage = USAGE_CONSTANT)
{
	return paramSetBinaryBlock(param, CONST_CAST(BYTE*, pValue), length, offset, maxLength, usage);
}

inline int paramSetBinaryBlock(ShortDskParam& param, BYTE* pValue, Size length, Size offset= 0, Size maxLength=0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKBINARYBLOCKPOINTER;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.binaryBlockPtr.bytePtr = pValue;
	param.body.binaryBlockPtr.length  = length;
	param.body.binaryBlockPtr.offset  = offset;
	param.body.binaryBlockPtr.maxLength	= maxLength ? maxLength : length;
	return J_OK;
}

inline int paramSetBinaryBlock(ShortDskParam& param, const BYTE* pValue, Size length, Size offset= 0, Size maxLength=0, PUsage usage = USAGE_CONSTANT)
{
	return paramSetBinaryBlock(param, CONST_CAST(BYTE*, pValue), length, offset, maxLength, usage);
}

inline int paramSetBinary(DskParam& param, BYTE* pValue, Size length, Size /*maxLength*/ = 0, PUsage usage = USAGE_CONSTANT)
{
	//maxLength is a deprecated parameter. No functions currently pass it as a non-zero value. Should be removed later.
	param.header.usage = usage;
	param.header.more	= Done;

	if (param.header.format == DSKJADEBINARY || param.header.format == DSKANY)
	{
		return JADE_SET_BINARY(&param.body.dataHandler, pValue, length);
	}

	if (param.header.format == DSKBINARY)
	{
		if (length > sizeof(param.body.binary.dataArea)) 
			return BINARY_TOO_LONG;
		memcpy(param.body.binary.dataArea, pValue, param.body.binary.length = (UInt16) length);
		return J_OK;
	}

	if (param.header.format == DSKBINARYBLOCKPOINTER)
	{
		if (param.body.binaryBlockPtr.bytePtr == nullptr)
			return INVALID_PARAMETER_VALUE;
		if (length > param.body.binaryBlockPtr.maxLength)
			return BINARY_TOO_LONG;
		param.body.binaryBlockPtr.length = length;
		memcpy(param.body.binaryBlockPtr.bytePtr, pValue, param.body.binaryBlockPtr.length);
		return J_OK;
	}
	return INVALID_PARAMETER_TYPE;
}

inline int paramSetBinary(DskParam& param, const BYTE* pValue, Size length, Size maxLength = 0, PUsage usage = USAGE_CONSTANT)
{
	return paramSetBinary(param, CONST_CAST(BYTE*, pValue), length, maxLength, usage);
}

inline int paramSetBinary(ShortDskParam& param, BYTE* pValue, Size length, Size /*maxLength*/ = 0, PUsage usage = USAGE_CONSTANT)
{
	//maxLength is a deprecated parameter. No functions currently pass it as a non-zero value. Should be removed later.
	param.header.usage = usage;
	param.header.more = Done;

	if (param.header.format == DSKJADEBINARY || param.header.format == DSKANY)
	{
		return JADE_SET_BINARY(&param.body.dataHandler, pValue, length);
	}

	if (param.header.format == DSKBINARY)
	{
		if (length > sizeof(param.body.binary.dataArea))
			return BINARY_TOO_LONG;
		memcpy(param.body.binary.dataArea, pValue, param.body.binary.length = (UInt16)length);
		return J_OK;
	}

	if (param.header.format == DSKBINARYBLOCKPOINTER)
	{
		if (param.body.binaryBlockPtr.bytePtr == nullptr)
			return INVALID_PARAMETER_VALUE;
		if (length > param.body.binaryBlockPtr.maxLength)
			return BINARY_TOO_LONG;
		param.body.binaryBlockPtr.length = length;
		memcpy(param.body.binaryBlockPtr.bytePtr, pValue, param.body.binaryBlockPtr.length);
		return J_OK;
	}
	return INVALID_PARAMETER_TYPE;
}

inline int paramSetBinary(ShortDskParam& param, const BYTE* pValue, Size length, PUsage usage = USAGE_CONSTANT)
{
	return paramSetBinary(param, CONST_CAST(BYTE*, pValue), length, 0, usage);
}

inline int paramSetBinaryData(DskParam& param, BYTE* pValue, Size length, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKBINARY;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.binary.length = (UInt16) length;
	memcpy(param.body.binary.dataArea, pValue, length);
	return J_OK;
}

inline int paramSetBinaryData(DskParam& param, const BYTE* pValue, Size length, PUsage usage = USAGE_CONSTANT)
{
	return paramSetBinaryData(param, CONST_CAST(BYTE*, pValue), length, usage);
}

inline int paramSetBoolean(DskParam& param, Boolean value = FALSE, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKBOOLEAN;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.boolean	= value;
	return J_OK;
}

inline int paramSetBoolean(ShortDskParam& param, Boolean value = FALSE, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKBOOLEAN;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.boolean	= value;
	return J_OK;
}

inline int paramSetBoolean(DskParam& param, bool value, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKBOOLEAN;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.boolean	= value ? TRUE : FALSE;
	return J_OK;
}

inline int paramSetBoolean(ShortDskParam& param, bool value, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKBOOLEAN;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.boolean	= value ? TRUE : FALSE;
	return J_OK;
}

inline int paramSetBufferList(LargeDskParam& param, EntryCount entries = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format = DSKBUFFERLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.bufferList.entries = entries;
	return J_OK;
}

inline int paramSetByte(DskParam& param, Byte value = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKBYTE;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.byte	= value;
	return J_OK;
}

inline int paramSetByte(ShortDskParam& param, Byte value = FALSE, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKBYTE;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.byte	= value;
	return J_OK;
}

inline int paramSetCharacter(DskParam& param, Character value = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKCHARACTER;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.character= value;
	return J_OK;
}

inline int paramSetCharacter(ShortDskParam& param, Character value = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKCHARACTER;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.character= value;
	return J_OK;
}

inline int paramSetCharBlock(DskParam& param, Character* pValue, Size length, Size offset = 0, Size maxLength = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKCHARBLOCKPOINTER;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.charBlockPtr.charPtr		= pValue;
	param.body.charBlockPtr.length		= length;
	param.body.charBlockPtr.offset		= offset;
	param.body.charBlockPtr.maxLength	= maxLength ? maxLength : length;
	return J_OK;
}

inline int paramSetCharBlock(DskParam& param, const Character* pValue, Size length, Size offset = 0, Size maxLength = 0, PUsage usage = USAGE_CONSTANT)
{
	return paramSetCharBlock(param, CONST_CAST(Character*, pValue), length, offset, maxLength, usage);
}

inline int paramSetCharBlock(ShortDskParam& param, Character* pValue, Size length, Size offset = 0, Size maxLength = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKCHARBLOCKPOINTER;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.charBlockPtr.charPtr		= pValue;
	param.body.charBlockPtr.length		= length;
	param.body.charBlockPtr.offset		= offset;
	param.body.charBlockPtr.maxLength	= maxLength ? maxLength : length;
	return J_OK;
}

inline int paramSetCharBlock(ShortDskParam& param, const Character* pValue, Size length, Size offset = 0, Size maxLength = 0, PUsage usage = USAGE_CONSTANT)
{
	return paramSetCharBlock(param, CONST_CAST(Character*, pValue), length, offset, maxLength, usage);
}

inline int paramSetClassFeature(DskParam& param, const JomClassFeature& feature, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKCLASSFEATURE;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.feature  = feature;
	return J_OK;
}

inline int paramSetClassFeature(ShortDskParam& param, const JomClassFeature& feature, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKCLASSFEATURE;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.feature  = feature;
	return J_OK;
}

inline int paramSetClassFeature(DskParam& param, ClassNumber cNo, FeatureNum fNo, PUsage usage = USAGE_CONSTANT)
{
	param.header.format			= DSKCLASSFEATURE;
	param.header.usage  		= usage;
	param.header.more	= Done;
	param.body.feature.classNo	= cNo;
	param.body.feature.number	= fNo;
	return J_OK;
}

inline int paramSetClassFeature(ShortDskParam& param, ClassNumber cNo, FeatureNum fNo, PUsage usage = USAGE_CONSTANT)
{
	param.header.format			= DSKCLASSFEATURE;
	param.header.usage  		= usage;
	param.header.more	= Done;
	param.body.feature.classNo	= cNo;
	param.body.feature.number	= fNo;
	return J_OK;
}

inline int paramSetClassFeatureLevel(DskParam& param, const JomClassFeatureLevel& classFeatureLevel, PUsage usage = USAGE_CONSTANT)
{
	param.header.format		= DSKCLASSFEATURELEVEL;
	param.header.usage		= usage;
	param.header.more	= Done;
	param.body.featureLevel.classFeatureLevel	= classFeatureLevel;
	param.body.featureLevel.handle = 0;
	return J_OK;
}

inline int paramSetClassFeatureLevel(ShortDskParam& param, const JomClassFeatureLevel& classFeatureLevel, PUsage usage = USAGE_CONSTANT)
{
	param.header.format		= DSKCLASSFEATURELEVEL;
	param.header.usage		= usage;
	param.header.more	= Done;
	param.body.featureLevel.classFeatureLevel	= classFeatureLevel;
	param.body.featureLevel.handle = 0;
	return J_OK;
}

inline int paramSetClassFeatureLevel(DskParam& param, ClassNumber cNo, FeatureNum fNo, Level level, PUsage usage = USAGE_CONSTANT)
{
	param.header.format									= DSKCLASSFEATURELEVEL;
	param.header.usage  								= usage;
	param.header.more	= Done;
	param.body.featureLevel.classFeatureLevel.classNo	= cNo;
	param.body.featureLevel.classFeatureLevel.number	= fNo;
	param.body.featureLevel.classFeatureLevel.level		= level;
	param.body.featureLevel.handle						= 0;
	return J_OK;
}

inline int paramSetClassFeatureLevel(ShortDskParam& param, ClassNumber cNo, FeatureNum fNo, Level level, PUsage usage = USAGE_CONSTANT)
{
	param.header.format									= DSKCLASSFEATURELEVEL;
	param.header.usage  								= usage;
	param.header.more	= Done;
	param.body.featureLevel.classFeatureLevel.classNo	= cNo;
	param.body.featureLevel.classFeatureLevel.number	= fNo;
	param.body.featureLevel.classFeatureLevel.level		= level;
	param.body.featureLevel.handle						= 0;
	return J_OK;
}

inline int paramSetClassFeatureLevel(DskParam& param, const JomClassFeatureLevelHandle& featureLevel, PUsage usage = USAGE_CONSTANT)
{
	param.header.format		= DSKCLASSFEATURELEVEL;
	param.header.usage		= usage;
	param.header.more	= Done;
	param.body.featureLevel	= featureLevel;
	return J_OK;
}

inline int paramSetClassFeatureLevel(ShortDskParam& param, const JomClassFeatureLevelHandle& featureLevel, PUsage usage = USAGE_CONSTANT)
{
	param.header.format		= DSKCLASSFEATURELEVEL;
	param.header.usage		= usage;
	param.header.more	= Done;
	param.body.featureLevel	= featureLevel;
	return J_OK;
}

inline int paramSetDictKeyBlock(DskParam& param, BYTE* pValue, Size length, Size keyCount, Size maxLength = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKDICTKEYBLOCKPOINTER;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.dictKeyBlockPtr.dictKeysPtr = pValue;
	param.body.dictKeyBlockPtr.length  = length;
	param.body.dictKeyBlockPtr.keyCount  = keyCount;
	param.body.dictKeyBlockPtr.maxLength  = maxLength != 0 ? maxLength : length;
	return J_OK;
}

inline int paramSetDictKeyBlock(DskParam& param, const BYTE* pValue, Size length, Size keyCount, Size maxLength = 0, PUsage usage = USAGE_CONSTANT)
{
	return paramSetDictKeyBlock(param, CONST_CAST(BYTE*, pValue), length, keyCount, maxLength, usage);
}

inline int paramSetDictKeyBlock(ShortDskParam& param, BYTE* pValue, Size length, Size keyCount, Size maxLength=0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKDICTKEYBLOCKPOINTER;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.dictKeyBlockPtr.dictKeysPtr = pValue;
	param.body.dictKeyBlockPtr.length  = length;
	param.body.dictKeyBlockPtr.keyCount  = keyCount;
	param.body.dictKeyBlockPtr.maxLength  = maxLength != 0 ? maxLength : length;
	return J_OK;
}

inline int paramSetDictKeyBlock(ShortDskParam& param, const BYTE* pValue, Size length, Size keyCount, Size maxLength=0, PUsage usage = USAGE_CONSTANT)
{
	return paramSetDictKeyBlock(param, CONST_CAST(BYTE*, pValue), length, keyCount, maxLength, usage);
}

inline int paramSetFeatureName(DskParam& param, Character* pName = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format = DSKFEATURENAME;
	param.header.usage = usage;
	param.header.more	= Done;
	param.body.featureName.pName = pName;
	param.body.featureName.handle = 0;
	return J_OK;
}

inline int paramSetFeatureName(DskParam& param, const Character* pName, PUsage usage = USAGE_CONSTANT)
{
	return paramSetFeatureName(param, CONST_CAST(Character*, pName), usage);
}

inline int paramSetFeatureName(ShortDskParam& param, Character* pName = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKFEATURENAME;
	param.header.usage = usage;
	param.header.more	= Done;
	param.body.featureName.pName = pName;
	param.body.featureName.handle = 0;
	return J_OK;
}

inline int paramSetFeatureName(ShortDskParam& param, const Character* pName, PUsage usage = USAGE_CONSTANT)
{
	return paramSetFeatureName(param, CONST_CAST(Character*, pName), usage);
}

inline int paramSetFeatureNameHandle(DskParam& param, const JomFeatureNameHandle& featureName, PUsage usage = USAGE_CONSTANT)
{
	param.header.format = DSKFEATURENAME;
	param.header.usage = usage;
	param.header.more	= Done;
	param.body.featureName = featureName;
	return J_OK;
}

inline int paramSetFeatureNameHandle(ShortDskParam& param, const JomFeatureNameHandle& featureName, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKFEATURENAME;
	param.header.usage = usage;
	param.header.more	= Done;
	param.body.featureName= featureName;
	return J_OK;
}

inline int paramSetFormat(DskParam& param, PFormat format, PUsage usage = USAGE_CONSTANT)
{
	param.header.format = format;
	param.header.usage  = usage;
	param.header.more	= Done;
	return J_OK;
}

inline int paramSetFormat(ShortDskParam& param, PFormat format, PUsage usage = USAGE_CONSTANT)
{
	param.header.format = format;
	param.header.usage  = usage;
	param.header.more	= Done;
	return J_OK;
}

inline int paramSetPrimFeature(DskParam& param, const JomPrimFeature& feature, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPRIMFEATURE;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.primFeature  = feature;
	return J_OK;
}

inline int paramSetPrimFeature(ShortDskParam& param, const JomPrimFeature& feature, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPRIMFEATURE;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.primFeature  = feature;
	return J_OK;
}

inline int paramSetPrimFeature(DskParam& param, SchemaNumber schemaNo, JomClassFeature feature, PUsage usage = USAGE_CONSTANT)
{
	param.header.format			= DSKPRIMFEATURE;
	param.header.usage  		= usage;
	param.header.more	= Done;
	param.body.primFeature.schemaNo	= schemaNo;
	param.body.primFeature.feature	= feature;
	return J_OK;
}

inline int paramSetPrimFeature(ShortDskParam& param, SchemaNumber schemaNo, JomClassFeature feature, PUsage usage = USAGE_CONSTANT)
{
	param.header.format			= DSKPRIMFEATURE;
	param.header.usage  		= usage;
	param.header.more	= Done;
	param.body.primFeature.schemaNo	= schemaNo;
	param.body.primFeature.feature	= feature;
	return J_OK;
}

inline int paramSetInterfaceFeature(DskParam& param, const JomInterfaceFeature& feature, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKINTERFACEFEATURE;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.interfaceFeature  = feature;
	return J_OK;
}

inline int paramSetInterfaceFeature(ShortDskParam& param, const JomInterfaceFeature& feature, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKINTERFACEFEATURE;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.interfaceFeature  = feature;
	return J_OK;
}

inline int paramSetInterfaceFeature(DskParam& param, InterfaceNumber iNo, FeatureNum fNo, PUsage usage = USAGE_CONSTANT)
{
	param.header.format			= DSKINTERFACEFEATURE;
	param.header.usage  		= usage;
	param.header.more	= Done;
	param.body.interfaceFeature.interfaceNo	= iNo;
	param.body.interfaceFeature.number		= fNo;
	return J_OK;
}

inline int paramSetInterfaceFeature(ShortDskParam& param, InterfaceNumber iNo, FeatureNum fNo, PUsage usage = USAGE_CONSTANT)
{
	param.header.format			= DSKINTERFACEFEATURE;
	param.header.usage  		= usage;
	param.header.more	= Done;
	param.body.interfaceFeature.interfaceNo	= iNo;
	param.body.interfaceFeature.number		= fNo;
	return J_OK;
}

inline int paramSetCString(DskParam& param, Character* pValue = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKCSTRING;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.pText	= pValue;
	return J_OK;
}

inline int paramSetCString(DskParam& param, const Character* pValue, PUsage usage = USAGE_CONSTANT)
{
	return paramSetCString(param, CONST_CAST(Character*, pValue), usage);
}

inline int paramSetCString(ShortDskParam& param, Character* pValue = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKCSTRING;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.pText	= pValue;
	return J_OK;
}

inline int paramSetCString(ShortDskParam& param, const Character* pValue, PUsage usage = USAGE_CONSTANT)
{
	return paramSetCString(param, CONST_CAST(Character*, pValue), usage);
}

inline int paramSetDate(DskParam& param, DskDate value = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKDATE;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.date    	= value;
	return J_OK;
}

inline int paramSetDate(ShortDskParam& param, DskDate value = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKDATE;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.date    	= value;
	return J_OK;
}

inline int paramSetDbMethodDesc(DskParam& param, UInt32 category, UInt32 dbRequest, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKDBMETHODDESC;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.dbMethodDesc.category = category;
	param.body.dbMethodDesc.dbRequest = dbRequest;
	return J_OK;
}

inline int paramSetDbMethodDesc(ShortDskParam& param, UInt32 category, UInt32 dbRequest, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKDBMETHODDESC;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.dbMethodDesc.category = category;
	param.body.dbMethodDesc.dbRequest = dbRequest;
	return J_OK;
}

inline int paramSetDecimal(DskParam& param, const DskDecimal& value, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKDECIMAL;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.decimal  = value;
	return J_OK;
}

inline int paramSetDecimal(ShortDskParam& param, const DskDecimal& value, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKDECIMAL;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.decimal  = value;
	return J_OK;
}

inline int paramSetDecimal(DskParam& param, const DskDecimal& value, Precision maxPrecision, ScaleFactor maxScaleFactor, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKDECIMAL;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.decimal  = value;
	param.body.decimal.maxPrecision		= maxPrecision;
	param.body.decimal.maxScaleFactor	= maxScaleFactor;
	return J_OK;
}

inline int paramSetDecimal(ShortDskParam& param, const DskDecimal& value, Precision maxPrecision, ScaleFactor maxScaleFactor, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKDECIMAL;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.decimal  = value;
	param.body.decimal.maxPrecision		= maxPrecision;
	param.body.decimal.maxScaleFactor	= maxScaleFactor;
	return J_OK;
}

inline int paramSetDecimal(DskParam& param, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKDECIMAL;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.decimal.precision		= 0;
	param.body.decimal.maxPrecision		= 0;
	param.body.decimal.scaleFactor		= 0;
	param.body.decimal.maxScaleFactor	= 0;
	return J_OK;
}

inline int paramSetDecimal(ShortDskParam& param, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKDECIMAL;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.decimal.precision		= 0;
	param.body.decimal.maxPrecision		= 0;
	param.body.decimal.scaleFactor		= 0;
	param.body.decimal.maxScaleFactor	= 0;
	return J_OK;
}

inline int paramSetFloat(DskParam& param, Float value = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKFLOAT;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.floatVal	= value;
	return J_OK;
}

inline int paramSetFloat(ShortDskParam& param, Float value = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKFLOAT;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.floatVal	= value;
	return J_OK;
}

inline int paramSetInstanceID(ShortDskParam& param, InstanceID value = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format		= DSKINSTANCEID;
	param.header.usage		= usage;
	param.header.more	= Done;
	param.body.instanceID	= value;
	return J_OK;
}

inline int paramSetInstanceID(DskParam& param, InstanceID value = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format		= DSKINSTANCEID;
	param.header.usage		= usage;
	param.header.more	= Done;
	param.body.instanceID	= value;
	return J_OK;
}

inline int paramSetInstanceIDAsInteger(DskParam& param, InstanceID value = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format		= DSKINTEGER64;
	param.header.usage		= usage;
	param.header.more	= Done;
	param.body.integer64	= value;
	return J_OK;
}

inline int paramSetInstanceIDAsInteger(ShortDskParam& param, InstanceID value = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format		= DSKINTEGER64;
	param.header.usage		= usage;
	param.header.more	= Done;
	param.body.integer64	= value;
	return J_OK;
}

inline int paramSetInstanceIdList(DskParam& param, EntryCount entries = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format = DSKINSTANCEIDLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.instanceIDList.entries = entries;
	return J_OK;
}

inline int paramSetInteger(DskParam& param, Integer value = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKINTEGER;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.integer	= value;
	return J_OK;
}

inline int paramSetInteger(ShortDskParam& param, Integer value, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKINTEGER;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.integer	= value;
	return J_OK;
}

inline int paramSetInteger(DskParam& param, UInteger value, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKINTEGER;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.uInteger	= value;
	return J_OK;
}

inline int paramSetInteger(ShortDskParam& param, UInteger value = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKINTEGER;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.uInteger	= value;
	return J_OK;
}

inline int paramSetIntegerList(DskParam& param, EntryCount entries = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKINTEGERLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.intList.entries = entries;
	return J_OK;
}

inline int paramSaveInteger3264(DskParam& param, Integer value)
{
	switch (param.header.format)
	{
	case DSKINTEGER:
		param.body.integer   = value;
		return J_OK;
	case DSKINTEGER64:
		param.body.integer64 = value;
		return J_OK;
	}
	return INVALID_PARAMETER_TYPE;
}

inline int paramSaveInteger3264(ShortDskParam& param, Integer value)
{
	switch (param.header.format)
	{
	case DSKINTEGER:
		param.body.integer   = value;
		return J_OK;
	case DSKINTEGER64:
		param.body.integer64 = value;
		return J_OK;
	}
	return INVALID_PARAMETER_TYPE;
}

inline int paramSaveInteger3264(DskParam& param, UInteger value)
{
	switch (param.header.format)
	{
	case DSKINTEGER:
		if (value > INT_MAX)
			return JOM_INTEGER_OVERFLOW;
		param.body.integer   = (Integer)value;
		return J_OK;
	case DSKINTEGER64:
		param.body.integer64 = value;
		return J_OK;
	}
	return INVALID_PARAMETER_TYPE;
}

inline int paramSaveInteger3264(ShortDskParam& param, UInteger value)
{
	switch (param.header.format)
	{
	case DSKINTEGER:
		if (value > INT_MAX)
			return JOM_INTEGER_OVERFLOW;
		param.body.integer   = (Integer)value;
		return J_OK;
	case DSKINTEGER64:
		param.body.integer64 = value;
		return J_OK;
	}
	return INVALID_PARAMETER_TYPE;
}

inline int paramSaveInteger3264(DskParam& param, Integer64 value)
{
	switch (param.header.format)
	{
	case DSKINTEGER:
		if (value > INT_MAX || value < INT_MIN)
			return JOM_INTEGER_OVERFLOW;
		param.body.integer   = (Integer)value;
		return J_OK;
	case DSKINTEGER64:
		param.body.integer64 = value;
		return J_OK;
	}
	return INVALID_PARAMETER_TYPE;
}

inline int paramSaveInteger3264(ShortDskParam& param, Integer64 value)
{
	switch (param.header.format)
	{
	case DSKINTEGER:
		if (value > INT_MAX || value < INT_MIN)
			return JOM_INTEGER_OVERFLOW;
		param.body.integer   = (Integer)value;
		return J_OK;
	case DSKINTEGER64:
		param.body.integer64 = value;
		return J_OK;
	}
	return INVALID_PARAMETER_TYPE;
}

inline int paramSaveInteger3264(DskParam& param, UInteger64 value)
{
	switch (param.header.format)
	{
	case DSKINTEGER:
		if (value > INT_MAX)
			return JOM_INTEGER_OVERFLOW;
		param.body.integer   = (Integer)value;
		return J_OK;
	case DSKINTEGER64:
		if (value > INT64_MAX)
			return JOM_INTEGER_OVERFLOW;
		param.body.integer64 = (Integer64)value;
		return J_OK;
	default:
		break;
	}
	return INVALID_PARAMETER_TYPE;
}

inline int paramSaveInteger3264(ShortDskParam& param, UInteger64 value)
{
	switch (param.header.format)
	{
	case DSKINTEGER:
		if (value > INT_MAX)
			return JOM_INTEGER_OVERFLOW;
		param.body.integer   = (Integer)value;
		return J_OK;
	case DSKINTEGER64:
		if (value > INT64_MAX)
			return JOM_INTEGER_OVERFLOW;
		param.body.integer64 = (Integer64)value;
		return J_OK;
	default:
		break;
	}
	return INVALID_PARAMETER_TYPE;
}

inline int paramSetInteger64(DskParam& param, Integer64 value = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	 = DSKINTEGER64;
	param.header.usage   = usage;
	param.header.more	 = Done;
	param.body.integer64 = value;
	return J_OK;
}

inline int paramSetInteger64(ShortDskParam& param, Integer64 value = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	 = DSKINTEGER64;
	param.header.usage   = usage;
	param.header.more	 = Done;
	param.body.integer64 = value;
	return J_OK;
}

inline int paramSetInteger64List(DskParam& param, EntryCount entries = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKINTEGER64LIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.int64List.entries = entries;
	return J_OK;
}

inline int paramSetMemoryAddress(DskParam& param, const DskMemoryAddress& value, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKMEMORYADDRESS;
	param.header.usage	= usage;
	param.header.more	= Done;
	param.body.memoryAddress = value;
	return J_OK;
}

inline int paramSetMemoryAddress(ShortDskParam& param, const DskMemoryAddress& value, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKMEMORYADDRESS;
	param.header.usage	= usage;
	param.header.more	= Done;
	param.body.memoryAddress = value;
	return J_OK;
}

inline int paramSetMemoryAddress(DskParam& param, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKMEMORYADDRESS;
	param.header.usage  = usage;
	param.header.more	= Done;
	return setDskMemoryAddress(param.body.memoryAddress, 0, JomMemorySpaceNull);
//	param.body.memoryAddress.memSpaceId = JomMemorySpaceNull;
//	param.body.memoryAddress.u.maxSpaceHolder = 0;
}

inline int paramSetMemoryAddress(ShortDskParam& param, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKMEMORYADDRESS;
	param.header.usage  = usage;
	param.header.more	= Done;
	return setDskMemoryAddress(param.body.memoryAddress, 0, JomMemorySpaceNull);
//	param.body.memoryAddress.memSpaceId = JomMemorySpaceNull;
//	param.body.memoryAddress.u.maxSpaceHolder = 0;
}

inline int paramSetMemoryAddress(DskParam& param, void* value, JomMemorySpaceId memSpaceId, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKMEMORYADDRESS;
	param.header.usage  = usage;
	param.header.more	= Done;
	return setDskMemoryAddress(param.body.memoryAddress, value, memSpaceId);
//	param.body.memoryAddress.memSpaceId = memSpaceId;
//	param.body.memoryAddress.u.maxSpaceHolder = 0;
//	param.body.memoryAddress.u.pVoid= value;
}

inline int paramSetMemoryAddress(ShortDskParam& param, void* value, JomMemorySpaceId memSpaceId, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKMEMORYADDRESS;
	param.header.usage  = usage;
	param.header.more	= Done;
	return setDskMemoryAddress(param.body.memoryAddress, value, memSpaceId);
//	param.body.memoryAddress.memSpaceId = memSpaceId;
//	param.body.memoryAddress.u.maxSpaceHolder = 0;
//	param.body.memoryAddress.u.pVoid= value;
}

inline int paramSetOid(DskParam& param, const DskObjectId& value, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKOBJECTID;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.oid     	= value;
	return J_OK;
}

inline int paramSetOid(ShortDskParam& param, const DskObjectId& value, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKOBJECTID;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.oid     	= value;
	return J_OK;
}

inline int paramSetOid(DskParam& param, const DskObjectId* pValue = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKOBJECTID;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.oid 		= pValue ? *pValue : NullDskObjectId;
	return J_OK;
}

inline int paramSetOid(ShortDskParam& param, const DskObjectId* pValue = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format = DSKOBJECTID;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.oid 		= pValue ? *pValue : NullDskObjectId;
	return J_OK;
}

inline int paramSetOid(DskParam* param, const DskObjectId& value, PUsage usage = USAGE_CONSTANT)
{
	param->header.format= DSKOBJECTID;
	param->header.usage = usage;
	param->header.more	= Done;
	param->body.oid     = value;
	return J_OK;
}

inline int paramSetOid(ShortDskParam* param, const DskObjectId& value, PUsage usage = USAGE_CONSTANT)
{
	param->header.format= DSKOBJECTID;
	param->header.usage = usage;
	param->header.more	= Done;
	param->body.oid	= value;
	return J_OK;
}

inline int paramSetOid(DskParam& param, const OidKey& value, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKOBJECTID;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.oid 		= NullDskObjectId;	// clear the edition
	param.body.oidkey   = value;
	return J_OK;
}

inline int paramSetOid(ShortDskParam& param, const OidKey& value, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKOBJECTID;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.oid 		= NullDskObjectId;	// clear the edition
	param.body.oidkey   = value;
	return J_OK;
}

inline int paramSetOid(DskParam& param, const ShortDskObjectId& value, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKSHORTOBJECTID;
	param.header.usage 	= usage;
	param.header.more	= Done;
	param.body.oid 		= NullDskObjectId;	// just in case someone assumes that this is a full oid
	param.body.shortOid	= value;
	return J_OK;
}

inline int paramSetOid(DskParam* param, const ShortDskObjectId& value, PUsage usage = USAGE_CONSTANT)
{
	param->header.format= DSKSHORTOBJECTID;
	param->header.usage = usage;
	param->header.more	= Done;
	param->body.oid 	= NullDskObjectId;	// just in case someone assumes that this is a full oid
	param->body.shortOid= value;
	return J_OK;
}

inline int paramSetOid(ShortDskParam* param, const ShortDskObjectId& value, PUsage usage = USAGE_CONSTANT)
{
	param->header.format= DSKSHORTOBJECTID;
	param->header.usage = usage;
	param->header.more	= Done;
	param->body.oid 	= NullDskObjectId;	// just in case someone assumes that this is a full oid
	param->body.shortOid= value;
	return J_OK;
}

inline int paramSetOid(ShortDskParam& param, const ShortDskObjectId& value, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKSHORTOBJECTID;
	param.header.usage 	= usage;
	param.header.more	= Done;
	param.body.oid 		= NullDskObjectId;	// just in case someone assumes that this is a full oid
	param.body.shortOid	= value;
	return J_OK;
}

inline int paramSetPointerList(DskParam& param, EntryCount entries = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format = DSKPOINTERLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.ptrList.entries = entries;
	return J_OK;
}

inline int paramSetPString(DskParam& param, const Character* pValue = 0, Size length = UseNullTerminatedLength, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPSTRING;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.string.length = (UInt16) ((length != UseNullTerminatedLength || !pValue) ? length : pValue ? STRLEN(pValue) : 0);
	memcpy(param.body.string.dataArea, pValue, param.body.string.length * sizeof(Character));
	return J_OK;
}

inline int paramSetShortOidList(DskParam& param, EntryCount entries = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKSHORTOIDLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.list.size = sizeof param.body.list.oidArray;
	param.body.list.entries = entries;
	return J_OK;
}

inline int paramSetOidKeyList(DskParam& param, EntryCount entries = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format = DSKOIDKEYLIST;
	param.header.usage = usage;
	param.header.more = Done;
	param.body.oidKeyList.size = sizeof param.body.oidKeyList.oidKeyArray;
	param.body.oidKeyList.entries = entries;
	return J_OK;
}

inline int paramSetParameter(DskParam& param, EntryCount index, DskParam* pValue, PUsage usage = USAGE_CONSTANT)
{
	param.header.format = DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;

	param.body.parameterList.entries = index;
	param.body.parameterList.param[index - 1] = pValue;
	return J_OK;
}

inline int paramSetParameter(LargeDskParam& param, EntryCount index, DskParam* pValue, PUsage usage = USAGE_CONSTANT)
{
	param.header.format = DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;

	param.body.parameterList.entries = index;
	param.body.parameterList.param[index - 1] = pValue;
	return J_OK;
}

inline int paramSetParameter(ShortDskParam& param, EntryCount index, DskParam* pValue, PUsage usage = USAGE_CONSTANT)
{
	int result = 0;
	param.header.format = DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;

	if (index > NUM_ELEMS(param.body.parameterList.param))
		result = PARAM_NUMBER_MISMATCH;
	else
	{
		param.body.parameterList.entries = index;
		param.body.parameterList.param[index - 1] = pValue;
	}
	return result;
}

inline int paramSetParamList(DskParam& param, EntryCount entries = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = entries;
	return J_OK;
}

inline int paramSetParamList(ShortDskParam& param, EntryCount entries = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = entries;
	return J_OK;
}

inline int paramSetParamList(MidDskParam& param, EntryCount entries = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = entries;
	return J_OK;
}

inline int paramSetParamList(LargeDskParam& param, EntryCount entries = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = entries;
	return J_OK;
}

inline int paramSetParamList(DskParam& param, DskParam* p1, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = 1;
	param.body.parameterList.param[0]= p1;
	return J_OK;
}

inline int paramSetParamList(ShortDskParam& param, DskParam* p1, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = 1;
	param.body.parameterList.param[0]= p1;
	return J_OK;
}

inline int paramSetParamList(DskParam& param, ShortDskParam* p1, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = 1;
	param.body.parameterList.param[0]= (DskParam*) p1;
	return J_OK;
}

inline int paramSetParamList(ShortDskParam& param, ShortDskParam* p1, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = 1;
	param.body.parameterList.param[0]= (DskParam*) p1;
	return J_OK;
}

inline int paramSetParamList(DskParam& param, ShortDskParam& p1, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = 1;
	param.body.parameterList.param[0]= (DskParam*) &p1;
	return J_OK;
}

inline int paramSetParamList(ShortDskParam& param, ShortDskParam& p1, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = 1;
	param.body.parameterList.param[0]= (DskParam*) &p1;
	return J_OK;
}

inline int paramSetParamList(DskParam& param, DskParam* p1, DskParam* p2, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = 2;
	param.body.parameterList.param[0]= p1;
	param.body.parameterList.param[1]= p2;
	return J_OK;
}

inline int paramSetParamList(ShortDskParam& param, DskParam* p1, DskParam* p2, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = 2;
	param.body.parameterList.param[0]= p1;
	param.body.parameterList.param[1]= p2;
	return J_OK;
}

inline int paramSetParamList(DskParam& param, ShortDskParam* p1, ShortDskParam* p2, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = 2;
	param.body.parameterList.param[0]= (DskParam*) p1;
	param.body.parameterList.param[1]= (DskParam*) p2;
	return J_OK;
}

inline int paramSetParamList(ShortDskParam& param, ShortDskParam* p1, ShortDskParam* p2, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = 2;
	param.body.parameterList.param[0]= (DskParam*) p1;
	param.body.parameterList.param[1]= (DskParam*) p2;
	return J_OK;
}

inline int paramSetParamList(DskParam& param, ShortDskParam& p1, ShortDskParam& p2, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = 2;
	param.body.parameterList.param[0]= (DskParam*) &p1;
	param.body.parameterList.param[1]= (DskParam*) &p2;
	return J_OK;
}

inline int paramSetParamList(ShortDskParam& param, ShortDskParam& p1, ShortDskParam& p2, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = 2;
	param.body.parameterList.param[0]= (DskParam*) &p1;
	param.body.parameterList.param[1]= (DskParam*) &p2;
	return J_OK;
}

inline int paramSetParamList(DskParam& param, DskParam* p1, DskParam* p2, DskParam* p3, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = 3;
	param.body.parameterList.param[0]= p1;
	param.body.parameterList.param[1]= p2;
	param.body.parameterList.param[2]= p3;
	return J_OK;
}

inline int paramSetParamList(DskParam& param, DskParam* p1, DskParam* p2, DskParam* p3, DskParam* p4, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = 4;
	param.body.parameterList.param[0]= p1;
	param.body.parameterList.param[1]= p2;
	param.body.parameterList.param[2]= p3;
	param.body.parameterList.param[3]= p4;
	return J_OK;
}

inline int paramSetParamList(DskParam& param, DskParam* p1, DskParam* p2, DskParam* p3, DskParam* p4, DskParam* p5, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = 5;
	param.body.parameterList.param[0]= p1;
	param.body.parameterList.param[1]= p2;
	param.body.parameterList.param[2]= p3;
	param.body.parameterList.param[3]= p4;
	param.body.parameterList.param[4]= p5;
	return J_OK;
}

inline int paramSetParamList(DskParam& param, DskParam* p1, DskParam* p2, DskParam* p3, DskParam* p4, DskParam* p5, DskParam* p6, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = 6;
	param.body.parameterList.param[0]= p1;
	param.body.parameterList.param[1]= p2;
	param.body.parameterList.param[2]= p3;
	param.body.parameterList.param[3]= p4;
	param.body.parameterList.param[4]= p5;
	param.body.parameterList.param[5]= p6;
	return J_OK;
}

inline int paramSetParamList(ShortDskParam& param, DskParam* p1, DskParam* p2, DskParam* p3, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = 3;
	param.body.parameterList.param[0]= p1;
	param.body.parameterList.param[1]= p2;
	param.body.parameterList.param[2]= p3;
	return J_OK;
}

inline int paramSetParamList(DskParam& param, ShortDskParam* p1, ShortDskParam* p2, ShortDskParam* p3, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = 3;
	param.body.parameterList.param[0]= (DskParam*) p1;
	param.body.parameterList.param[1]= (DskParam*) p2;
	param.body.parameterList.param[2]= (DskParam*) p3;
	return J_OK;
}

inline int paramSetParamList(ShortDskParam& param, ShortDskParam* p1, ShortDskParam* p2, ShortDskParam* p3, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = 3;
	param.body.parameterList.param[0]= (DskParam*) p1;
	param.body.parameterList.param[1]= (DskParam*) p2;
	param.body.parameterList.param[2]= (DskParam*) p3;
	return J_OK;
}

inline int paramSetParamList(DskParam& param, ShortDskParam& p1, ShortDskParam& p2, ShortDskParam& p3, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = 3;
	param.body.parameterList.param[0]= (DskParam*) &p1;
	param.body.parameterList.param[1]= (DskParam*) &p2;
	param.body.parameterList.param[2]= (DskParam*) &p3;
	return J_OK;
}

inline int paramSetParamList(ShortDskParam& param, ShortDskParam& p1, ShortDskParam& p2, ShortDskParam& p3, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = 3;
	param.body.parameterList.param[0]= (DskParam*) &p1;
	param.body.parameterList.param[1]= (DskParam*) &p2;
	param.body.parameterList.param[2]= (DskParam*) &p3;
	return J_OK;
}

inline int paramSetParamList(DskParam& param, ShortDskParam& p1, ShortDskParam& p2, ShortDskParam& p3, ShortDskParam& p4, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = 4;
	param.body.parameterList.param[0]= (DskParam*) &p1;
	param.body.parameterList.param[1]= (DskParam*) &p2;
	param.body.parameterList.param[2]= (DskParam*) &p3;
	param.body.parameterList.param[3]= (DskParam*) &p4;
	return J_OK;
}

inline int paramSetParamList(DskParam& param, ShortDskParam& p1, ShortDskParam& p2, ShortDskParam& p3, ShortDskParam& p4, ShortDskParam& p5, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = 5;
	param.body.parameterList.param[0]= (DskParam*) &p1;
	param.body.parameterList.param[1]= (DskParam*) &p2;
	param.body.parameterList.param[2]= (DskParam*) &p3;
	param.body.parameterList.param[3]= (DskParam*) &p4;
	param.body.parameterList.param[4]= (DskParam*) &p5;
	return J_OK;
}

inline int paramSetParamList(DskParam& param, ShortDskParam& p1, ShortDskParam& p2, ShortDskParam& p3, ShortDskParam& p4, ShortDskParam& p5, ShortDskParam& p6, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPARAMLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.parameterList.entries = 6;
	param.body.parameterList.param[0]= (DskParam*) &p1;
	param.body.parameterList.param[1]= (DskParam*) &p2;
	param.body.parameterList.param[2]= (DskParam*) &p3;
	param.body.parameterList.param[3]= (DskParam*) &p4;
	param.body.parameterList.param[4]= (DskParam*) &p5;
	param.body.parameterList.param[5]= (DskParam*) &p6;
	return J_OK;
}

inline int paramSetPoint(DskParam& param, const DskPoint& value, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPOINT;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.point	= value;
	return J_OK;
}

inline int paramSetPoint(ShortDskParam& param, const DskPoint& value, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPOINT;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.point	= value;
	return J_OK;
}

inline int paramSetPoint(DskParam& param, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPOINT;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.point.x	=
	param.body.point.y	= 0;
	return J_OK;
}

inline int paramSetPoint(ShortDskParam& param, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPOINT;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.point.x	=
	param.body.point.y	= 0;
	return J_OK;
}

inline int paramSetPointer(DskParam& param, void* pValue = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPOINTER;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.bodyPtr	= pValue;
	return J_OK;
}

inline int paramSetPointer(ShortDskParam& param, void* pValue = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKPOINTER;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.bodyPtr	= pValue;
	return J_OK;
}

inline int paramSetReal(DskParam& param, Real value = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKREAL;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.real		= value;
	return J_OK;
}

inline int paramSetReal(ShortDskParam& param, Real value = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKREAL;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.real		= value;
	return J_OK;
}

inline int paramSetRectangle2D(DskParam& param, Integer left_, Integer top_, Integer right_, Integer bottom_, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKRECTANGLE2D;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.rectangle2d.left		= left_;
	param.body.rectangle2d.top		= top_;
	param.body.rectangle2d.right	= right_;
	param.body.rectangle2d.bottom	= bottom_;
	return J_OK;
}

inline int paramSetRectangle2D(ShortDskParam& param, Integer left_, Integer top_, Integer right_, Integer bottom_, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKRECTANGLE2D;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.rectangle2d.left		= left_;
	param.body.rectangle2d.top		= top_;
	param.body.rectangle2d.right	= right_;
	param.body.rectangle2d.bottom	= bottom_;
	return J_OK;
}

inline int paramSetString(DskParam& param, Character* pValue, Size length = UseNullTerminatedLength, PUsage /*usage*/ = USAGE_CONSTANT)
{
	if (param.header.format == DSKJADESTRING || param.header.format == DSKANY)
		return JADE_SET_STRING(&param.body.dataHandler, pValue,
			length != UseNullTerminatedLength ? length : pValue ? STRLEN(pValue) : 0);	// windows locale aware string compare
	if (param.header.format == DSKCSTRING)
	{
		if (param.body.pText == nullptr)
			return INVALID_PARAMETER_VALUE;
		length = ((length != UseNullTerminatedLength || !pValue) ? length : pValue ? STRLEN(pValue) : 0);
		memcpy(param.body.pText, pValue, length * sizeof(Character));
		param.body.pText[length] = 0;
		return J_OK;
	}
	if ((param.header.format == DSKCHARBLOCKPOINTER) && (param.body.charBlockPtr.charPtr != nullptr))
	{
		if (param.body.charBlockPtr.charPtr == nullptr)
			return INVALID_PARAMETER_VALUE;
		Size len = ((length != UseNullTerminatedLength || !pValue) ? length : pValue ? STRLEN(pValue) : 0);
		if (len > param.body.charBlockPtr.maxLength)
			return STRING_TOO_LONG;
		param.body.charBlockPtr.length = len;
		memcpy(param.body.charBlockPtr.charPtr, pValue, param.body.charBlockPtr.length * sizeof(Character));
		param.body.charBlockPtr.charPtr[param.body.charBlockPtr.length] = 0;
		return J_OK;
	}
	return INVALID_PARAMETER_TYPE;
}

inline int paramSetString(ShortDskParam& param, Character* pValue, Size length = UseNullTerminatedLength, PUsage /*usage*/ = USAGE_CONSTANT)
{
	if (param.header.format == DSKJADESTRING || param.header.format == DSKANY)
		return JADE_SET_STRING(&param.body.dataHandler, pValue,
			length != UseNullTerminatedLength ? length : pValue ? STRLEN(pValue) : 0);	// windows locale aware string compare
	if (param.header.format == DSKCSTRING)
	{
		if (param.body.pText == nullptr)
			return INVALID_PARAMETER_VALUE;
		length = ((length != UseNullTerminatedLength || !pValue) ? length : pValue ? STRLEN(pValue) : 0);
		memcpy(param.body.pText, pValue, length * sizeof(Character));
		param.body.pText[length] = 0;
		return J_OK;
	}
	if ((param.header.format == DSKCHARBLOCKPOINTER) && (param.body.charBlockPtr.charPtr != nullptr))
	{
		if (param.body.charBlockPtr.charPtr == nullptr)
			return INVALID_PARAMETER_VALUE;
		Size len = ((length != UseNullTerminatedLength || !pValue) ? length : pValue ? STRLEN(pValue) : 0);
		if (len > param.body.charBlockPtr.maxLength)
			return STRING_TOO_LONG;
		param.body.charBlockPtr.length = len;
		memcpy(param.body.charBlockPtr.charPtr, pValue, param.body.charBlockPtr.length * sizeof(Character));
		param.body.charBlockPtr.charPtr[param.body.charBlockPtr.length] = 0;
		return J_OK;
	}
	return INVALID_PARAMETER_TYPE;
}

inline int paramSetString(DskParam& param, const Character* pValue, Size length = UseNullTerminatedLength, PUsage usage = USAGE_CONSTANT)
{
	return paramSetString(param, CONST_CAST(Character*, pValue), length, usage);
}

inline int paramSetString(ShortDskParam& param, const Character* pValue, Size length = UseNullTerminatedLength, PUsage usage = USAGE_CONSTANT)
{
	return paramSetString(param, CONST_CAST(Character*, pValue), length, usage);
}

inline int paramSetStringList(DskParam& param, EntryCount entries, PUsage usage = USAGE_CONSTANT)
{
	param.header.format = DSKSTRINGLIST;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.stringList.entries = entries;
	return J_OK;
}

inline int paramSetStringUtf8(DskParam& param, const StringUtf8Info& value, PUsage /*usage*/ = USAGE_CONSTANT)
{
	if (param.header.format == DSKJADESTRINGUTF8 || param.header.format == DSKANY)
		return JADE_SET_STRINGUTF8(&param.body.dataHandler, CONST_CAST(StringUtf8Info&, value));

	if (param.header.format == DSKSTRINGUTF8)
	{
		if (param.body.stringUtf8BlockPtr.utf8BytePtr == nullptr)
			return INVALID_PARAMETER_VALUE;
		if (value.length >= param.body.stringUtf8BlockPtr.maxLength)
			return STRINGUTF8_TOO_LONG;
		param.body.stringUtf8BlockPtr.size = value.size;
		param.body.stringUtf8BlockPtr.length = value.length;
		memcpy(param.body.stringUtf8BlockPtr.utf8BytePtr, value.utf8BytePtr, value.size);
		param.body.stringUtf8BlockPtr.utf8BytePtr[value.size] = 0;
		return J_OK;
	}
	return INVALID_PARAMETER_TYPE;
}

inline int paramSetStringUtf8(ShortDskParam& param, const StringUtf8Info& value, PUsage /*usage*/ = USAGE_CONSTANT)
{
	if (param.header.format == DSKJADESTRINGUTF8 || param.header.format == DSKANY)
		return JADE_SET_STRINGUTF8(&param.body.dataHandler, CONST_CAST(StringUtf8Info&, value));

	if (param.header.format == DSKSTRINGUTF8)
	{
		if (param.body.stringUtf8BlockPtr.utf8BytePtr == nullptr)
			return INVALID_PARAMETER_VALUE;
		if (value.length >= param.body.stringUtf8BlockPtr.maxLength)
			return STRINGUTF8_TOO_LONG;
		param.body.stringUtf8BlockPtr.size = value.size;
		param.body.stringUtf8BlockPtr.length = value.length;
		memcpy(param.body.stringUtf8BlockPtr.utf8BytePtr, value.utf8BytePtr, value.size);
		param.body.stringUtf8BlockPtr.utf8BytePtr[value.size] = 0;
		return J_OK;
	}
	return INVALID_PARAMETER_TYPE;
}

inline int paramSetStringUtf8Block(DskParam& param, StringUtf8Info* pValue, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKSTRINGUTF8;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.stringUtf8BlockPtr.utf8BytePtr	= pValue->utf8BytePtr;
	param.body.stringUtf8BlockPtr.size			= pValue->size;
	param.body.stringUtf8BlockPtr.length		= pValue->length;
	param.body.stringUtf8BlockPtr.maxLength		= pValue->maxLength;

	return J_OK;
}

inline int paramSetStringUtf8Block(ShortDskParam& param, StringUtf8Info* pValue, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKSTRINGUTF8;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.stringUtf8BlockPtr.utf8BytePtr	= pValue->utf8BytePtr;
	param.body.stringUtf8BlockPtr.size			= pValue->size;
	param.body.stringUtf8BlockPtr.length		= pValue->length;
	param.body.stringUtf8BlockPtr.maxLength		= pValue->maxLength;

	return J_OK;
}

inline int paramSetTime(DskParam& param, DskTime value = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKTIME;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.timeVal 	= value;
	return J_OK;
}

inline int paramSetTime(ShortDskParam& param, DskTime value = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKTIME;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.timeVal 	= value;
	return J_OK;
}

inline int paramSetTimeStamp(DskParam& param, const DskTimeStamp& value, PUsage usage = USAGE_CONSTANT)
{
	param.header.format = DSKTIMESTAMP;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.timeStamp= value;
	return J_OK;
}

inline int paramSetTimeStamp(ShortDskParam& param, const DskTimeStamp& value, PUsage usage = USAGE_CONSTANT)
{
	param.header.format = DSKTIMESTAMP;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.timeStamp= value;
	return J_OK;
}

inline int paramSetTimeStamp(DskParam& param, PUsage usage = USAGE_CONSTANT)
{
	param.header.format			= DSKTIMESTAMP;
	param.header.usage			= usage;
	param.header.more	= Done;
	param.body.timeStamp.date	= 0;
	param.body.timeStamp.timeVal= 0;
	return J_OK;
}

inline int paramSetTimeStamp(ShortDskParam& param, PUsage usage = USAGE_CONSTANT)
{
	param.header.format			= DSKTIMESTAMP;
	param.header.usage			= usage;
	param.header.more	= Done;
	param.body.timeStamp.date	= 0;
	param.body.timeStamp.timeVal= 0;
	return J_OK;
}

inline int paramSetTimeStampInterval(DskParam& param, const DskTimeStampInterval& value, PUsage usage = USAGE_CONSTANT)
{
	param.header.format = DSKTIMESTAMPINTERVAL;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.timeStampInterval = value;
	return J_OK;
}

inline int paramSetTimeStampInterval(ShortDskParam& param, const DskTimeStampInterval& value, PUsage usage = USAGE_CONSTANT)
{
	param.header.format = DSKTIMESTAMPINTERVAL;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.timeStampInterval = value;
	return J_OK;
}

inline int paramSetTimeStampInterval(DskParam& param, PUsage usage = USAGE_CONSTANT)
{
	param.header.format = DSKTIMESTAMPINTERVAL;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.timeStampInterval.milliseconds = 0;
	return J_OK;
}

inline int paramSetTimeStampInterval(ShortDskParam& param, PUsage usage = USAGE_CONSTANT)
{
	param.header.format = DSKTIMESTAMPINTERVAL;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.timeStampInterval.milliseconds = 0;
	return J_OK;
}

inline int paramSetTimeStampOffset(DskParam& param, const DskTimeStampOffset& value, PUsage usage = USAGE_CONSTANT)
{
	param.header.format = DSKTIMESTAMPOFFSET;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.timeStampOffset = value;
	return J_OK;
}

inline int paramSetTimeStampOffset(ShortDskParam& param, const DskTimeStampOffset& value, PUsage usage = USAGE_CONSTANT)
{
	param.header.format = DSKTIMESTAMPOFFSET;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.timeStampOffset = value;
	return J_OK;
}

inline int paramSetTimeStampOffset(DskParam& param, PUsage usage = USAGE_CONSTANT)
{
	param.header.format = DSKTIMESTAMPOFFSET;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.timeStampOffset.date = 0;
	param.body.timeStampOffset.timeVal = 0;
	param.body.timeStampOffset.utcBias = 0;
	return J_OK;
}

inline int paramSetTimeStampOffset(ShortDskParam& param, PUsage usage = USAGE_CONSTANT)
{
	param.header.format = DSKTIMESTAMPOFFSET;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.timeStampOffset.date = 0;
	param.body.timeStampOffset.timeVal = 0;
	param.body.timeStampOffset.utcBias = 0;
	return J_OK;
}

inline int paramSetUndefined(DskParam& param, PUsage usage = USAGE_CONSTANT)
{
	param.header.format = DSKUNDEF;
	param.header.usage  = usage;
	param.header.more	= Done;
	return J_OK;
}

inline int paramSetUndefined(ShortDskParam& param, PUsage usage = USAGE_CONSTANT)
{
	param.header.format = DSKUNDEF;
	param.header.usage  = usage;
	param.header.more	= Done;
	return J_OK;
}

inline int paramSetUndefined(LargeDskParam& param, PUsage usage = USAGE_CONSTANT)
{
	param.header.format = DSKUNDEF;
	param.header.usage  = usage;
	param.header.more	= Done;
	return J_OK;
}

inline int paramSetUnsignedInteger(DskParam& param, UInteger value = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKINTEGER;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.uInteger	= value;
	return J_OK;
}

inline int paramSetUnsignedInteger(ShortDskParam& param, UInteger value = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	= DSKINTEGER;
	param.header.usage  = usage;
	param.header.more	= Done;
	param.body.uInteger	= value;
	return J_OK;
}

inline int paramSetUnsignedInteger64(DskParam& param, UInt64 value = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	  = DSKINTEGER64;
	param.header.usage    = usage;
	param.header.more	= Done;
	param.body.uInteger64 = value;
	return J_OK;
}

inline int paramSetUnsignedInteger64(ShortDskParam& param, UInt64 value = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	  = DSKINTEGER64;
	param.header.usage    = usage;
	param.header.more	= Done;
	param.body.uInteger64 = value;
	return J_OK;
}

inline int paramSetHandle(DskParam& param, Handle value = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	 = DSKWINHANDLE;
	param.header.usage   = usage;
	param.header.more	 = Done;
	param.body.winhandle = value;
	return J_OK;
}

inline int paramSetHandle(ShortDskParam& param, Handle value = 0, PUsage usage = USAGE_CONSTANT)
{
	param.header.format	 = DSKWINHANDLE;
	param.header.usage   = usage;
	param.header.more	 = Done;
	param.body.winhandle = value;
	return J_OK;
}

inline int paramSetUsage(DskParam& param, PUsage usage)
{
	param.header.usage  = usage;
	return J_OK;
}

inline int paramSetUsage(ShortDskParam& param, PUsage usage)
{
	param.header.usage  = usage;
	return J_OK;
}

/* ----- Param getting functions --------------------------------------------*/

inline int paramGetBinary(const DskParam& param, BYTE*& pValue, Size& length)
{
	if (param.header.format == DSKJADEBINARY)
		return JADE_DEREF_BINARY_LENGTH(&param.body.dataHandler, pValue, length);

	if (param.header.format == DSKBINARY)
	{
		pValue = (BYTE*) &param.body.binary.dataArea;
		length = param.body.binary.length;

		return J_OK;
	}

	if (param.header.format != DSKBINARYBLOCKPOINTER)
		return INVALID_PARAMETER_TYPE;

	pValue = (BYTE*) param.body.binaryBlockPtr.bytePtr + param.body.binaryBlockPtr.offset;
	length = param.body.binaryBlockPtr.length - param.body.binaryBlockPtr.offset;

	return J_OK;
}

inline int paramGetBinary(const ShortDskParam& param, BYTE*& pValue, Size& length)
{
	if (param.header.format == DSKJADEBINARY)
		return JADE_DEREF_BINARY_LENGTH(&param.body.dataHandler, pValue, length);

	if (param.header.format == DSKBINARY)
	{
		pValue = (BYTE*) &param.body.binary.dataArea;
		length = param.body.binary.length;

		return J_OK;
	}

	if (param.header.format != DSKBINARYBLOCKPOINTER)
		return INVALID_PARAMETER_TYPE;

	pValue = (BYTE*) param.body.binaryBlockPtr.bytePtr + param.body.binaryBlockPtr.offset;
	length = param.body.binaryBlockPtr.length - param.body.binaryBlockPtr.offset;

	return J_OK;
}

inline int paramGetBinaryBlock(const DskParam& param, BYTE*& pValue, Size& offset, Size& length)
{
	if (param.header.format != DSKBINARYBLOCKPOINTER)
		return INVALID_PARAMETER_TYPE;

	pValue = (BYTE*) param.body.binaryBlockPtr.bytePtr;
	offset = param.body.binaryBlockPtr.offset;
	length = param.body.binaryBlockPtr.length;

	return J_OK;
}

inline int paramGetBinaryBlock(const ShortDskParam& param, BYTE*& pValue, Size& offset, Size& length)
{
	if (param.header.format != DSKBINARYBLOCKPOINTER)
		return INVALID_PARAMETER_TYPE;

	pValue = (BYTE*) param.body.binaryBlockPtr.bytePtr;
	offset = param.body.binaryBlockPtr.offset;
	length = param.body.binaryBlockPtr.length;

	return J_OK;
}

inline int paramGetBoolean(const DskParam& param, Boolean& value)
{
	if (param.header.format != DSKBOOLEAN)
		return INVALID_PARAMETER_TYPE;

	value = param.body.boolean;

	return J_OK;
}

inline int paramGetBoolean(const ShortDskParam& param, Boolean& value)
{
	if (param.header.format != DSKBOOLEAN)
		return INVALID_PARAMETER_TYPE;

	value = param.body.boolean;

	return J_OK;
}

inline int paramGetBoolean(const DskParam& param, bool& value)
{
	if (param.header.format != DSKBOOLEAN)
		return INVALID_PARAMETER_TYPE;

	value = param.body.boolean ? true : false;

	return J_OK;
}

inline int paramGetBoolean(const ShortDskParam& param, bool& value)
{
	if (param.header.format != DSKBOOLEAN)
		return INVALID_PARAMETER_TYPE;

	value = param.body.boolean ? true : false;

	return J_OK;
}

inline int paramGetByte(const DskParam& param, Byte& value)
{
	if (param.header.format != DSKBYTE)
		return INVALID_PARAMETER_TYPE;

	value = param.body.byte;

	return J_OK;
}

inline int paramGetByte(const ShortDskParam& param, Byte& value)
{
	if (param.header.format != DSKBYTE)
		return INVALID_PARAMETER_TYPE;

	value = param.body.byte;

	return J_OK;
}

inline int paramGetCharacter(const DskParam& param, Character& value)
{
	if (param.header.format != DSKCHARACTER)
		return INVALID_PARAMETER_TYPE;

	value = param.body.character;

	return J_OK;
}

inline int paramGetCharacter(const ShortDskParam& param, Character& value)
{
	if (param.header.format != DSKCHARACTER)
		return INVALID_PARAMETER_TYPE;

	value = param.body.character;

	return J_OK;
}

inline int paramGetCharBlock(const DskParam& param, Character*& pValue)
{
	if (param.header.format != DSKCHARBLOCKPOINTER)
		return INVALID_PARAMETER_TYPE;

	pValue = param.body.charBlockPtr.charPtr;

	return J_OK;
}

inline int paramGetCharBlock(const ShortDskParam& param, Character*& pValue)
{
	if (param.header.format != DSKCHARBLOCKPOINTER)
		return INVALID_PARAMETER_TYPE;

	pValue = param.body.charBlockPtr.charPtr;

	return J_OK;
}

inline int paramGetCharBlock(const DskParam& param, Character*& pValue, Size* pLength)
{
	if (param.header.format != DSKCHARBLOCKPOINTER)
		return INVALID_PARAMETER_TYPE;

	pValue = param.body.charBlockPtr.charPtr;
	*pLength = param.body.charBlockPtr.length;

	return J_OK;
}

inline int paramGetCharBlock(const ShortDskParam& param, Character*& pValue, Size* pLength)
{
	if (param.header.format != DSKCHARBLOCKPOINTER)
		return INVALID_PARAMETER_TYPE;

	pValue = param.body.charBlockPtr.charPtr;
	*pLength = param.body.charBlockPtr.length;

	return J_OK;
}

inline int paramGetCharBlock(const DskParam& param, Character*& pValue, Size* pLength, Size* pMaxLength)
{
	if (param.header.format != DSKCHARBLOCKPOINTER)
		return INVALID_PARAMETER_TYPE;

	pValue = param.body.charBlockPtr.charPtr;
	*pLength = param.body.charBlockPtr.length;
	*pMaxLength = param.body.charBlockPtr.maxLength;

	return J_OK;
}

inline int paramGetCharBlock(const ShortDskParam& param, Character*& pValue, Size* pLength, Size* pMaxLength)
{
	if (param.header.format != DSKCHARBLOCKPOINTER)
		return INVALID_PARAMETER_TYPE;

	pValue = param.body.charBlockPtr.charPtr;
	*pLength = param.body.charBlockPtr.length;
	*pMaxLength = param.body.charBlockPtr.maxLength;

	return J_OK;
}

inline int paramGetCString(const DskParam& param, Character*& pValue)
{
	if (param.header.format != DSKCSTRING)
		return INVALID_PARAMETER_TYPE;

	pValue = param.body.pText;

	return J_OK;
}

inline int paramGetCString(const ShortDskParam& param, Character*& pValue)
{
	if (param.header.format != DSKCSTRING)
		return INVALID_PARAMETER_TYPE;

	pValue = param.body.pText;

	return J_OK;
}

inline int paramGetCString(const DskParam& param, Character* pValue, Size length)
{
	if (param.header.format != DSKCSTRING)
		return INVALID_PARAMETER_TYPE;

	STRCPYN(pValue, param.body.pText, (int) length);

	return J_OK;
}

inline int paramGetCString(const ShortDskParam& param, Character* pValue, Size length)
{
	if (param.header.format != DSKCSTRING)
		return INVALID_PARAMETER_TYPE;

	STRCPYN(pValue, param.body.pText, (int) length);

	return J_OK;
}

inline int paramGetDate(const ShortDskParam& param, DskDate& value)
{
	if (param.header.format != DSKDATE)
		return INVALID_PARAMETER_TYPE;

	value = param.body.date;

	return J_OK;
}

inline int paramGetDate(const DskParam& param, DskDate& value)
{
	if (param.header.format != DSKDATE)
		return INVALID_PARAMETER_TYPE;

	value = param.body.date;

	return J_OK;
}

inline int paramGetDbMethodDesc(const ShortDskParam& param, JomDbMethodDesc& value)
{
	if (param.header.format != DSKDBMETHODDESC)
		return INVALID_PARAMETER_TYPE;

	value = param.body.dbMethodDesc;

	return J_OK;
}

inline int paramGetDbMethodDesc(const DskParam& param, JomDbMethodDesc& value)
{
	if (param.header.format != DSKDBMETHODDESC)
		return INVALID_PARAMETER_TYPE;

	value = param.body.dbMethodDesc;

	return J_OK;
}

inline int paramGetDecimal(const DskParam& param, DskDecimal& value)
{
	if (param.header.format != DSKDECIMAL)
		return INVALID_PARAMETER_TYPE;

	value = param.body.decimal;

	return J_OK;
}

inline int paramGetDecimal(const ShortDskParam& param, DskDecimal& value)
{
	if (param.header.format != DSKDECIMAL)
		return INVALID_PARAMETER_TYPE;

	value = param.body.decimal;

	return J_OK;
}

inline int paramGetFloat(const DskParam& param, Float& value)
{
	// Make the various real types as interchangeable as possible.
	// Can't use 'else if' or 'switch' here - causes a warning re inline expansion.
	if (param.header.format == DSKFLOAT)
	{
		value = (Float) param.body.floatVal;
		return J_OK;
	}
	if (param.header.format == DSKREAL)
	{
		value = (Float) param.body.real;
		return J_OK;
	}

	return INVALID_PARAMETER_TYPE;
}

inline int paramGetFloat(const ShortDskParam& param, Float& value)
{
	// Make the various real types as interchangeable as possible.
	// Can't use 'else if' or 'switch' here - causes a warning re inline expansion.
	if (param.header.format == DSKFLOAT)
	{
		value = (Float) param.body.floatVal;
		return J_OK;
	}
	if (param.header.format == DSKREAL)
	{
		value = (Float) param.body.real;
		return J_OK;
	}

	return INVALID_PARAMETER_TYPE;
}

inline int paramGetInstanceID(const DskParam& param, InstanceID& value)
{
	if (param.header.format != DSKINSTANCEID)
		return INVALID_PARAMETER_TYPE;

	value = param.body.instanceID;

	return J_OK;
}

inline int paramGetInstanceID(const ShortDskParam& param, InstanceID& value)
{
	if (param.header.format != DSKINSTANCEID)
		return INVALID_PARAMETER_TYPE;

	value = param.body.instanceID;

	return J_OK;
}

inline int paramGetInstanceIDFromInteger(const DskParam& param, InstanceID& value)
{
	if (param.header.format == DSKINSTANCEID)
		value = param.body.instanceID;
	else if (param.header.format == DSKINTEGER)
		value = param.body.integer;
	else if (param.header.format == DSKINTEGER64)
		value = (InstanceID) param.body.uInteger64;
	else
		return INVALID_PARAMETER_TYPE;

	return J_OK;
}

inline int paramGetInstanceIDFromInteger(const ShortDskParam& param, InstanceID& value)
{
	if (param.header.format == DSKINSTANCEID)
		value = param.body.instanceID;
	else if (param.header.format == DSKINTEGER)
		value = param.body.integer;
	else if (param.header.format == DSKINTEGER64)
		value = (InstanceID) param.body.uInteger64;
	else
		return INVALID_PARAMETER_TYPE;

	return J_OK;
}

inline int paramGetInteger(const DskParam& param, Integer& value)
{
	if (param.header.format != DSKINTEGER)
		return INVALID_PARAMETER_TYPE;

	value = param.body.integer;

	return J_OK;
}

inline int paramGetInteger(const ShortDskParam& param, Integer& value)
{
	if (param.header.format != DSKINTEGER)
		return INVALID_PARAMETER_TYPE;

	value = param.body.integer;

	return J_OK;
}

inline int paramGetPositiveInteger(const DskParam& param, Integer& value)
{
	if (param.header.format != DSKINTEGER)
		return INVALID_PARAMETER_TYPE;

	if (param.body.integer < 0)
		return INVALID_PARAMETER_VALUE;

	value = param.body.integer;

	return J_OK;
}

inline int paramGetPositiveInteger(const ShortDskParam& param, Integer& value)
{
	if (param.header.format != DSKINTEGER)
		return INVALID_PARAMETER_TYPE;

	if (param.body.integer < 0)
		return INVALID_PARAMETER_VALUE;

	value = param.body.integer;

	return J_OK;
}

inline int paramGetPositiveInteger(const DskParam& param, UInteger& value)
{
	if (param.header.format != DSKINTEGER)
		return INVALID_PARAMETER_TYPE;

	if (param.body.integer < 0)
		return INVALID_PARAMETER_VALUE;

	value = param.body.integer;

	return J_OK;
}

inline int paramGetPositiveInteger(const ShortDskParam& param, UInteger& value)
{
	if (param.header.format != DSKINTEGER)
		return INVALID_PARAMETER_TYPE;

	if (param.body.integer < 0)
		return INVALID_PARAMETER_VALUE;

	value = param.body.integer;

	return J_OK;
}

inline int paramGetInteger64(const DskParam& param, Integer64& value)
{
	if (param.header.format != DSKINTEGER64)
		return INVALID_PARAMETER_TYPE;

	value = param.body.integer64;

	return J_OK;
}

inline int paramGetInteger64(const ShortDskParam& param, Integer64& value)
{
	if (param.header.format != DSKINTEGER64)
		return INVALID_PARAMETER_TYPE;

	value = param.body.integer64;

	return J_OK;
}

inline int paramGetPositiveInteger64(const DskParam& param, Integer64& value)
{
	if (param.header.format != DSKINTEGER64)
		return INVALID_PARAMETER_TYPE;

	if (param.body.integer64 < 0)
		return INVALID_PARAMETER_VALUE;

	value = param.body.integer64;

	return J_OK;
}

inline int paramGetPositiveInteger64(const ShortDskParam& param, Integer64& value)
{
	if (param.header.format != DSKINTEGER64)
		return INVALID_PARAMETER_TYPE;

	if (param.body.integer64 < 0)
		return INVALID_PARAMETER_VALUE;

	value = param.body.integer64;

	return J_OK;
}

inline int paramGetPositiveInteger64(const DskParam& param, UInteger64& value)
{
	if (param.header.format != DSKINTEGER64)
		return INVALID_PARAMETER_TYPE;

	if (param.body.integer64 < 0)
		return INVALID_PARAMETER_VALUE;

	value = param.body.integer64;

	return J_OK;
}

inline int paramGetPositiveInteger64(const ShortDskParam& param, UInteger64& value)
{
	if (param.header.format != DSKINTEGER64)
		return INVALID_PARAMETER_TYPE;

	if (param.body.integer64 < 0)
		return INVALID_PARAMETER_VALUE;

	value = param.body.integer64;

	return J_OK;
}

inline int paramGetInteger3264(const DskParam& param, Integer& value)
{
	switch (param.header.format)
	{
	case DSKINTEGER:
		value = param.body.integer;
		return J_OK;
	case DSKINTEGER64:
		if (param.body.integer64 > INT_MAX)
			return JOM_INTEGER_OVERFLOW;
		if (param.body.integer64 < INT_MIN)
			return JOM_INTEGER_UNDERFLOW;
		value = (Integer)param.body.integer64;
		return J_OK;
	}
	return INVALID_PARAMETER_TYPE;
}

inline int paramGetInteger3264(const ShortDskParam& param, Integer& value)
{
	switch (param.header.format)
	{
	case DSKINTEGER:
		value = param.body.integer;
		return J_OK;
	case DSKINTEGER64:
		if (param.body.integer64 > INT_MAX)
			return JOM_INTEGER_OVERFLOW;
		if (param.body.integer64 < INT_MIN)
			return JOM_INTEGER_UNDERFLOW;
		value = (Integer)param.body.integer64;
		return J_OK;
	}
	return INVALID_PARAMETER_TYPE;
}

inline int paramGetInteger3264(const DskParam& param, UInteger& value)
{
	switch (param.header.format)
	{
	case DSKINTEGER:
		if (param.body.integer < 0)
			return JOM_INTEGER_UNDERFLOW;
		value = (UInteger)param.body.integer;
		return J_OK;
	case DSKINTEGER64:
		if (param.body.integer64 < 0)
			return JOM_INTEGER_UNDERFLOW;
		if (param.body.integer64 > UINT_MAX)
			return JOM_INTEGER_OVERFLOW;
		value = (UInteger)param.body.integer64;
		return J_OK;
	}
	return INVALID_PARAMETER_TYPE;
}

inline int paramGetInteger3264(const ShortDskParam& param, UInteger& value)
{
	switch (param.header.format)
	{
	case DSKINTEGER:
		if (param.body.integer < 0)
			return JOM_INTEGER_UNDERFLOW;
		value = (UInteger)param.body.integer;
		return J_OK;
	case DSKINTEGER64:
		if (param.body.integer64 < 0)
			return JOM_INTEGER_UNDERFLOW;
		if (param.body.integer64 > UINT_MAX)
			return JOM_INTEGER_OVERFLOW;
		value = (UInteger)param.body.integer64;
		return J_OK;
	}
	return INVALID_PARAMETER_TYPE;
}

inline int paramGetInteger3264(const DskParam& param, Integer64& value)
{
	switch (param.header.format)
	{
	case DSKINTEGER:
		value = param.body.integer;
		return J_OK;
	case DSKINTEGER64:
		value = param.body.integer64;
		return J_OK;
	}
	return INVALID_PARAMETER_TYPE;
}

inline int paramGetInteger3264(const ShortDskParam& param, Integer64& value)
{
	switch (param.header.format)
	{
	case DSKINTEGER:
		value = param.body.integer;
		return J_OK;
	case DSKINTEGER64:
		value = param.body.integer64;
		return J_OK;
	}
	return INVALID_PARAMETER_TYPE;
}

inline int paramGetInteger3264(const DskParam& param, UInteger64& value)
{
	switch (param.header.format)
	{
	case DSKINTEGER:
		if (param.body.integer < 0)
			return JOM_INTEGER_UNDERFLOW;
		value = (UInteger64)param.body.integer;
		return J_OK;
	case DSKINTEGER64:
		if (param.body.integer64 < 0)
			return JOM_INTEGER_UNDERFLOW;
		value = (UInteger64)param.body.integer64;
		return J_OK;
	}
	return INVALID_PARAMETER_TYPE;
}

inline int paramGetInteger3264(const ShortDskParam& param, UInteger64& value)
{
	switch (param.header.format)
	{
	case DSKINTEGER:
		if (param.body.integer < 0)
			return JOM_INTEGER_UNDERFLOW;
		value = (UInteger64)param.body.integer;
		return J_OK;
	case DSKINTEGER64:
		if (param.body.integer64 < 0)
			return JOM_INTEGER_UNDERFLOW;
		value = (UInteger64)param.body.integer64;
		return J_OK;
	}
	return INVALID_PARAMETER_TYPE;
}

inline int paramGetMemoryAddress(const DskParam& param, DskMemoryAddress& value)
{
	if (param.header.format != DSKMEMORYADDRESS)
		return INVALID_PARAMETER_TYPE;

	value = param.body.memoryAddress;

	return J_OK;
}

inline int paramGetMemoryAddress(const ShortDskParam& param, DskMemoryAddress& value)
{
	if (param.header.format != DSKMEMORYADDRESS)
		return INVALID_PARAMETER_TYPE;

	value = param.body.memoryAddress;

	return J_OK;
}

inline int paramGetMemoryAddress(const DskParam& param, void*& value, JomMemorySpaceId memSpaceId)
{
	if (param.header.format != DSKMEMORYADDRESS)
		return INVALID_PARAMETER_TYPE;

	// Note: This inline version does not support memSpaceId being JomMemorySpaceUnknown, like the full isDskMemoryAddressValid() implementation
	// this is because the jomMemorySpaceId() function is not available at the jomos layer.

	if (!isDskMemoryAddressValid(param.body.memoryAddress, memSpaceId))
		return MEMORYADDRESS_NODE_INVALID;

	value = getDskMemoryAddressPointer(param.body.memoryAddress);

	return J_OK;
}

inline int paramGetMemoryAddress(const ShortDskParam& param, void*& value, JomMemorySpaceId memSpaceId)
{
	if (param.header.format != DSKMEMORYADDRESS)
		return INVALID_PARAMETER_TYPE;

	// Note: This inline version does not support memSpaceId being JomMemorySpaceUnknown, like the full isDskMemoryAddressValid() implementation
	// this is because the jomMemorySpaceId() function is not available at the jomos layer.
	if (!isDskMemoryAddressValid(param.body.memoryAddress, memSpaceId))
		return MEMORYADDRESS_NODE_INVALID;

	value = getDskMemoryAddressPointer(param.body.memoryAddress);

	return J_OK;
}

inline int paramGetOid(const DskParam& param, DskObjectId& value)
{
	if (param.header.format == DSKOBJECTID)
		value = param.body.oid;
	else if (param.header.format == DSKSHORTOBJECTID)
		value.set(param.body.shortOid);
	else
		return INVALID_PARAMETER_TYPE;

	return J_OK;
}

inline int paramGetOid(const ShortDskParam& param, DskObjectId& value)
{
	if (param.header.format == DSKOBJECTID)
		value = param.body.oid;
	else if (param.header.format == DSKSHORTOBJECTID)
		value.set(param.body.shortOid);
	else
		return INVALID_PARAMETER_TYPE;

	return J_OK;
}

inline int paramGetOid(const DskParam& param, ShortDskObjectId& value)
{
	if (param.header.format != DSKOBJECTID && param.header.format != DSKSHORTOBJECTID)
		return INVALID_PARAMETER_TYPE;

	value.set(param.body.oid);

	return J_OK;
}

inline int paramGetOid(const ShortDskParam& param, ShortDskObjectId& value)
{
	if (param.header.format != DSKOBJECTID && param.header.format != DSKSHORTOBJECTID)
		return INVALID_PARAMETER_TYPE;

	value.set(param.body.oid);

	return J_OK;
}

inline int paramGetOid(const DskParam& param, OidKey& value)
{
	if (param.header.format != DSKOBJECTID && param.header.format != DSKSHORTOBJECTID)
		return INVALID_PARAMETER_TYPE;

	value = param.body.oidkey;

	return J_OK;
}

inline int paramGetOid(const ShortDskParam& param, OidKey& value)
{
	if (param.header.format != DSKOBJECTID && param.header.format != DSKSHORTOBJECTID)
		return INVALID_PARAMETER_TYPE;

	value = param.body.oidkey;

	return J_OK;
}

inline unsigned paramGetParameterCount(const ShortDskParam* pParams)
{
	return pParams == nullptr ? 0 : pParams->header.format == DSKPARAMLIST ? pParams->body.parameterList.entries : 1;
}

inline unsigned paramGetParameterCount(const DskParam* pParams)
{
	return pParams == nullptr ? 0 : pParams->header.format == DSKPARAMLIST ? pParams->body.parameterList.entries : 1;
}

inline int paramGetParameter(const DskParam& param, EntryCount index, DskParam*& pValue)
{
	if (param.header.format != DSKPARAMLIST || index > param.body.parameterList.entries)
		return INVALID_PARAMETER_TYPE;

	pValue = param.body.parameterList.param[index - 1];

	return J_OK;
}

inline int paramGetParameter(const DskParam& param, EntryCount index, ShortDskParam*& pValue)
{
	if (param.header.format != DSKPARAMLIST || index > param.body.parameterList.entries)
		return INVALID_PARAMETER_TYPE;

	pValue = (ShortDskParam*) param.body.parameterList.param[index - 1];

	return J_OK;
}

inline int paramGetParameter(const ShortDskParam& param, EntryCount index, DskParam*& pValue)
{
	if (param.header.format != DSKPARAMLIST || index > param.body.parameterList.entries)
		return INVALID_PARAMETER_TYPE;

	pValue = param.body.parameterList.param[index - 1];

	return J_OK;
}

inline int paramGetParameter(const ShortDskParam& param, EntryCount index, ShortDskParam*& pValue)
{
	if (param.header.format != DSKPARAMLIST || index > param.body.parameterList.entries)
		return INVALID_PARAMETER_TYPE;

	pValue = (ShortDskParam*) param.body.parameterList.param[index - 1];

	return J_OK;
}

inline int paramGetPoint(const DskParam& param, DskPoint& value)
{
	if (param.header.format != DSKPOINT)
		return INVALID_PARAMETER_TYPE;

	value = param.body.point;

	return J_OK;
}

inline int paramGetPoint(const ShortDskParam& param, DskPoint& value)
{
	if (param.header.format != DSKPOINT)
		return INVALID_PARAMETER_TYPE;

	value = param.body.point;

	return J_OK;
}

inline int paramGetPointer(const DskParam& param, void*& pValue)
{
	if (param.header.format != DSKPOINTER)
		return INVALID_PARAMETER_TYPE;

	pValue = param.body.bodyPtr;

	return J_OK;
}

inline int paramGetPointer(const ShortDskParam& param, void*& pValue)
{
	if (param.header.format != DSKPOINTER)
		return INVALID_PARAMETER_TYPE;

	pValue = param.body.bodyPtr;

	return J_OK;
}

inline int paramGetPString(const DskParam& param, Character*& pValue)
{
	if (param.header.format != DSKPSTRING)
		return INVALID_PARAMETER_TYPE;

	pValue = CONST_CAST(Character*, param.body.string.dataArea);

	return J_OK;
}

inline int paramGetPString(const DskParam& param, Character*& pValue, Size* pLength)
{
	if (param.header.format != DSKPSTRING)
		return INVALID_PARAMETER_TYPE;

	pValue = CONST_CAST(Character*, param.body.string.dataArea);
	*pLength = param.body.string.length;

	return J_OK;
}

inline int paramGetPString(const DskParam& param, Character* pValue, Size length)
{
	if (param.header.format != DSKPSTRING)
		return INVALID_PARAMETER_TYPE;

	STRCPYN(pValue, param.body.string.dataArea, (int) length);

	return J_OK;
}

inline int paramGetReal(const DskParam& param, Real& value)
{
	// Make the various real types as interchangeable as possible.
	// Can't use 'else if' or 'switch' here - causes a warning re inline expansion.
	if (param.header.format == DSKREAL)
	{
		value = (Real) param.body.real;
		return J_OK;
	}
	if (param.header.format == DSKFLOAT)
	{
		value = (Real) param.body.floatVal;
		return J_OK;
	}

	return INVALID_PARAMETER_TYPE;
}

inline int paramGetReal(const ShortDskParam& param, Real& value)
{
	// Make the various real types as interchangeable as possible.
	// Can't use 'else if' or 'switch' here - causes a warning re inline expansion.
	if (param.header.format == DSKREAL)
	{
		value = (Real) param.body.real;
		return J_OK;
	}
	if (param.header.format == DSKFLOAT)
	{
		value = (Real) param.body.floatVal;
		return J_OK;
	}

	return INVALID_PARAMETER_TYPE;
}

inline int paramGetString(const DskParam& param, Character*& pValue)
{
	if (param.header.format == DSKJADESTRING)
		return JADE_DEREF_STRING(&param.body.dataHandler, pValue);

	if (param.header.format == DSKPSTRING)
		return paramGetPString(param, pValue);

	if (param.header.format == DSKCHARBLOCKPOINTER)
		return paramGetCharBlock(param, pValue);

	return paramGetCString(param, pValue);
}

inline int paramGetString(const ShortDskParam& param, Character*& pValue)
{
	if (param.header.format == DSKJADESTRING)
		return JADE_DEREF_STRING(&param.body.dataHandler, pValue);

	if (param.header.format == DSKCHARBLOCKPOINTER)
		return paramGetCharBlock(param, pValue);

	return paramGetCString(param, pValue);
}

inline int paramGetString(const DskParam& param, Character*& pValue, Size* pLength)
{
	if (param.header.format == DSKJADESTRING)
		return JADE_DEREF_STRING_LENGTH(&param.body.dataHandler, pValue, *pLength);

	if (param.header.format == DSKPSTRING)
		return paramGetPString(param, pValue, pLength);
	
	if (param.header.format == DSKCHARBLOCKPOINTER)
		return paramGetCharBlock(param, pValue, pLength);
	
	int result = paramGetCString(param, pValue);
	CHECK_RESULT;

	*pLength = (Size) STRLEN(pValue);

	return J_OK;
}

inline int paramGetString(const ShortDskParam& param, Character*& pValue, Size* pLength)
{
	if (param.header.format == DSKJADESTRING)
		return JADE_DEREF_STRING_LENGTH(&param.body.dataHandler, pValue, *pLength);

	if (param.header.format == DSKCHARBLOCKPOINTER)
		return paramGetCharBlock(param, pValue, pLength);
	
	int result = paramGetCString(param, pValue);
	CHECK_RESULT;

	*pLength = (Size) STRLEN(pValue);

	return J_OK;
}

inline int paramGetString(const DskParam& param, Character* pValue, Size length)
{
	if (param.header.format == DSKJADESTRING)
		return JADE_GET_STRING(&param.body.dataHandler, pValue, length);

	if (param.header.format == DSKPSTRING)
		return paramGetPString(param, pValue, length);

	if (param.header.format == DSKCHARBLOCKPOINTER)
	{
		// copy the value to the buffer that has been set up by the caller
		STRCPYN(pValue, param.body.charBlockPtr.charPtr, (int) length);

		return J_OK;
	}

	return paramGetCString(param, pValue, length);
}

inline int paramGetString(const ShortDskParam& param, Character* pValue, Size length)
{
	if (param.header.format == DSKJADESTRING)
		return JADE_GET_STRING(&param.body.dataHandler, pValue, length);

	if (param.header.format == DSKCHARBLOCKPOINTER)
	{
		// copy the value to the buffer that has been set up by the caller
		STRCPYN(pValue, param.body.charBlockPtr.charPtr, (int) length);

		return J_OK;
	}

	return paramGetCString(param, pValue, length);
}

inline int paramGetStringUtf8Block(const DskParam& param, StringUtf8Info& value)
{
	if (param.header.format != DSKSTRINGUTF8)
		return INVALID_PARAMETER_TYPE;

	value.utf8BytePtr	= param.body.stringUtf8BlockPtr.utf8BytePtr;
	value.size			= param.body.stringUtf8BlockPtr.size;
	value.length		= param.body.stringUtf8BlockPtr.length;
	value.maxLength		= STRINGUTF8_MAXLENGTH_UNDEFINED;

	return J_OK;
}

inline int paramGetStringUtf8Block(const ShortDskParam& param, StringUtf8Info& value)
{
	if (param.header.format != DSKSTRINGUTF8)
		return INVALID_PARAMETER_TYPE;

	value.utf8BytePtr	= param.body.stringUtf8BlockPtr.utf8BytePtr;
	value.size			= param.body.stringUtf8BlockPtr.size;
	value.length		= param.body.stringUtf8BlockPtr.length;
	value.maxLength		= STRINGUTF8_MAXLENGTH_UNDEFINED;

	return J_OK;
}

inline int paramGetStringUtf8Ref(const DskParam& param, StringUtf8Info& value)
{
	if (param.header.format == DSKJADESTRINGUTF8)
		return JADE_DEREF_STRINGUTF8(&param.body.dataHandler, value);

	if (param.header.format == DSKSTRINGUTF8)
		return paramGetStringUtf8Block(param, value);

	return INVALID_PARAMETER_TYPE;
}

inline int paramGetStringUtf8Ref(const ShortDskParam& param, StringUtf8Info& value)
{
	if (param.header.format == DSKJADESTRINGUTF8)
		return JADE_DEREF_STRINGUTF8(&param.body.dataHandler, value);

	if (param.header.format == DSKSTRINGUTF8)
		return paramGetStringUtf8Block(param, value);
	
	return INVALID_PARAMETER_TYPE;
}

inline int paramGetStringUtf8Copy(const DskParam& param, StringUtf8Info& value, Size maxSize)
{
	if (param.header.format == DSKJADESTRINGUTF8)
		return JADE_GET_STRINGUTF8(&param.body.dataHandler, value, maxSize);

	if (param.header.format == DSKSTRINGUTF8)
		return paramGetStringUtf8Block(param, value);

	return INVALID_PARAMETER_TYPE;
}

inline int paramGetStringUtf8Copy(const ShortDskParam& param, StringUtf8Info& value, Size maxSize)
{
	if (param.header.format == DSKJADESTRINGUTF8)
		return JADE_GET_STRINGUTF8(&param.body.dataHandler, value, maxSize);

	if (param.header.format == DSKSTRINGUTF8)
		return paramGetStringUtf8Block(param, value);

	return INVALID_PARAMETER_TYPE;
}

inline int paramGetTime(const DskParam& param, DskTime& value)
{
	if (param.header.format != DSKTIME)
		return INVALID_PARAMETER_TYPE;

	value = param.body.timeVal;

	return J_OK;
}

inline int paramGetTime(const ShortDskParam& param, DskTime& value)
{
	if (param.header.format != DSKTIME)
		return INVALID_PARAMETER_TYPE;

	value = param.body.timeVal;

	return J_OK;
}

inline int paramGetTimeStamp(const DskParam& param, DskTimeStamp& value)
{
	if (param.header.format != DSKTIMESTAMP)
		return INVALID_PARAMETER_TYPE;

	value = param.body.timeStamp;

	return J_OK;
}

inline int paramGetTimeStamp(const ShortDskParam& param, DskTimeStamp& value)
{
	if (param.header.format != DSKTIMESTAMP)
		return INVALID_PARAMETER_TYPE;

	value = param.body.timeStamp;

	return J_OK;
}

inline int paramGetTimeStampInterval(const DskParam& param, DskTimeStampInterval& value)
{
	if (param.header.format != DSKTIMESTAMPINTERVAL)
		return INVALID_PARAMETER_TYPE;

	value = param.body.timeStampInterval;

	return J_OK;
}

inline int paramGetTimeStampInterval(const ShortDskParam& param, DskTimeStampInterval& value)
{
	if (param.header.format != DSKTIMESTAMPINTERVAL)
		return INVALID_PARAMETER_TYPE;

	value = param.body.timeStampInterval;

	return J_OK;
}

inline int paramGetTimeStampOffset(const DskParam& param, DskTimeStampOffset& value)
{
	if (param.header.format != DSKTIMESTAMPOFFSET)
		return INVALID_PARAMETER_TYPE;

	value = param.body.timeStampOffset;

	return J_OK;
}

inline int paramGetTimeStampOffset(const ShortDskParam& param, DskTimeStampOffset& value)
{
	if (param.header.format != DSKTIMESTAMPOFFSET)
		return INVALID_PARAMETER_TYPE;

	value = param.body.timeStampOffset;

	return J_OK;
}

inline int paramGetUnsignedInteger(const DskParam& param, UInteger& value)
{
	if (param.header.format != DSKINTEGER)
		return INVALID_PARAMETER_TYPE;

	*(UInteger UNALIGNED *)&value = param.body.uInteger;

	return J_OK;
}

inline int paramGetUnsignedInteger(const ShortDskParam& param, UInteger& value)
{
	if (param.header.format != DSKINTEGER)
		return INVALID_PARAMETER_TYPE;

	*(UInteger UNALIGNED *)&value = param.body.uInteger;

	return J_OK;
}

inline int paramGetUnsignedInteger64(const DskParam& param, UInt64& value)
{
	if (param.header.format != DSKINTEGER64)
		return INVALID_PARAMETER_TYPE;

	*(UInt64 UNALIGNED *)&value = param.body.uInteger64;

	return J_OK;
}

inline int paramGetUnsignedInteger64(const ShortDskParam& param, UInt64& value)
{
	if (param.header.format != DSKINTEGER64)
		return INVALID_PARAMETER_TYPE;

	*(UInt64 UNALIGNED *)&value = param.body.uInteger64;

	return J_OK;
}

inline int paramGetHandle(const DskParam& param, Handle& value)
{
	if (param.header.format != DSKWINHANDLE)
		return INVALID_PARAMETER_TYPE;

	value = param.body.winhandle;

	return J_OK;
}

inline int paramGetHandle(const ShortDskParam& param, Handle& value)
{
	if (param.header.format != DSKWINHANDLE)
		return INVALID_PARAMETER_TYPE;

	value = param.body.winhandle;

	return J_OK;
}

inline int paramGetInterfaceFeature(const DskParam& param, JomInterfaceFeature& feature)
{
	if (param.header.format != DSKINTERFACEFEATURE)
		return INVALID_PARAMETER_TYPE;

	feature = param.body.interfaceFeature;

	return J_OK;
}

inline int paramGetInterfaceFeature(const ShortDskParam& param, JomInterfaceFeature& feature)
{
	if (param.header.format != DSKINTERFACEFEATURE)
		return INVALID_PARAMETER_TYPE;

	feature = param.body.interfaceFeature;

	return J_OK;
}

extern "C" JOMSTR_EXPORT int JOMAPI paramCreateJadeString(DskParam* pString, const Character* pData, Size length, Size maxLength = (Size) ~0, PUsage usage = USAGE_IO);
extern "C" JOMSTR_EXPORT int JOMAPI paramCreateJadeStringUtf8(DskParam* pString, const StringUtf8Info* pData, Size maxLength = (Size) ~0, PUsage usage = USAGE_IO);
extern "C" JOMSTR_EXPORT int JOMAPI paramCreateJadeBinary(DskParam* pBinary, const BYTE* pData, Size length, Size maxLength = (Size) ~0, PUsage usage = USAGE_IO);
extern "C" JOMSTR_EXPORT int JOMAPI paramCreateJadeAny(DskParam* pAny, PUsage usage = USAGE_IO);
extern "C" JOMSTR_EXPORT int JOMAPI paramDeleteJadeString(DskParam* pString);
extern "C" JOMSTR_EXPORT int JOMAPI paramDeleteJadeStringUtf8(DskParam* pString);
extern "C" JOMSTR_EXPORT int JOMAPI paramDeleteJadeBinary(DskParam* pBinary);
extern "C" JOMSTR_EXPORT int JOMAPI paramDeleteJadeAny(DskParam* pAny);
