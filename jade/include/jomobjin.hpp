/****************************************************************************

				P R O P R I E T A R Y   N O T I C E

	This software, in whole and in every part, is proprietary to Jade Software
	Corporation Limited at Christchurch, New Zealand and is not to be
	reproduced, used or disclosed except upon prior written permission of Jade
	Software Corporation Limited.

	COPYRIGHT (c) JADE SOFTWARE CORPORATION LIMITED 2005 - ALL RIGHTS RESERVED

****************************************************************************/

#pragma once

#include "jomproxy.h"
#include "jommthno.h"
#include "jomprpno.h"
#include "jomcalls.h"

//------------------------------------------------------------------------------
// DskObject set Properties:

inline HashValue DskObject::hash() const
{
	return oid.hash();
}

inline bool DskObject::isA(ClassNumber classNumber) const
{
	return actualClass(oid.classId) == actualClass(classNumber);
}

inline bool DskObject::isNull() const
{
	return oid.isNull();
}

inline void DskObject::makeOidNull()
{
	oid.set(NullDskObjectId);
}

inline void DskObject::setCls(ClassNumber classNum)
{
	oid.setClassNo(classNum);
}

inline int DskObject::setSystemBasic(bool sysBasic) const
{
	return setProperty(TEXT("_systemBasic"), sysBasic);
}

inline int DskObject::createObject()
{
	return ::jomCreateObject(JomDefaultProcessHandle, &oid, CLASS_DEFAULT_LIFETIME, nullptr, nullptr, __LINE__);
}

inline int DskObject::createObject(DskParam* pParam1, DskParam* pParam2)
{
	return ::jomCreateObject(JomDefaultProcessHandle, &oid, CLASS_DEFAULT_LIFETIME, pParam1, pParam2, __LINE__);
}

inline int DskObject::createObject(const Character string[])
{
	ShortDskParam param;
	paramSetCString(param, string);

	return ::jomCreateObject(JomDefaultProcessHandle, &oid, CLASS_DEFAULT_LIFETIME, param, nullptr, __LINE__);
}

inline int DskObject::createTransientObject()
{
	int result = makeTransient();
	CHECK_RESULT;
	return createObject();
}

inline int DskObject::createTransientObject(DskParam* pParam1, DskParam* pParam2)
{
	return ::jomCreateObject(JomDefaultProcessHandle, &oid, CLASS_TRANSIENT, pParam1, pParam2, __LINE__);
}

inline int DskObject::createSharedTransientObject()
{
	int result = makeSharedTransient();
	CHECK_RESULT;
	return createObject();
}

inline int DskObject::deleteObject() const
{
	return ::jomDeleteObject(JomDefaultProcessHandle, &oid, nullptr, nullptr, __LINE__);
}

inline int DskObject::deleteObject(DskParam* pParam1, DskParam* pParam2) const
{
	return ::jomDeleteObject(JomDefaultProcessHandle, &oid, pParam1, pParam2, __LINE__);
}

inline int DskObject::getObject(BYTE* pBuffer, UInt32 buffSize) const
{
	ShortDskParam b;
	paramSetBinaryBlock(b, pBuffer, buffSize);

	return oid.getClassNo() != 0 ? ::jomGetObject(JomDefaultProcessHandle, &oid, b, __LINE__) : OBJECT_NOT_FOUND;
}

inline int DskObject::lockObject(LockType type, LineNumber line) const
{
	unsigned int success;  // Ignored at present
	return ::jomLockObject(JomDefaultProcessHandle, &oid, type, TRANSACTION_DURATION, LOCK_TIMEOUT_SERVER_DEFINED, true, &success, line);
}

inline int DskObject::unlockObject(LineNumber line) const
{
	return ::jomUnlockObject(JomDefaultProcessHandle, &oid, line);
}

inline int DskObject::resynchObject(LineNumber line) const
{
	return ::jomResynchObject(JomDefaultProcessHandle, &oid, line);
}

inline int DskObject::getBufferEdition()
{
	return ::jomGetBufferEdition(JomDefaultProcessHandle, &oid, __LINE__);
}

inline int DskObject::updateEdition() const
{
	return ::jomUpdateEdition(JomDefaultProcessHandle, &oid, __LINE__);
}

//------------------------------------------------------------------------------
// DskObject set Properties:

inline int DskObject::setProperty(const Character name[], Character value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetCharacter(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const Character name[], Byte value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetByte(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const Character name[], Boolean value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetBoolean(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const Character name[], bool value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetBoolean(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const Character name[], const Character value[], LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetCString(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const Character name[], const Character value[], PropertyLen length, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetCharBlock(v, value, length);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const Character name[], Int16 value, LineNumber line) const
{
	return setProperty(name, (Int32)value, line);
}

inline int DskObject::setProperty(const Character name[], Int32 value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetInteger(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const Character name[], UInt32 value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetUnsignedInteger(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const Character name[], Int64 value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetInteger64(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const Character name[], UInt64 value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetUnsignedInteger64(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const Character name[], const DskObjectId* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetOid(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const Character name[], const ShortDskObjectId* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetOid(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const Character name[], const OidKey* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetOid(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const Character name[], const DskObject* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetOid(v, pValue->oid);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const Character name[], const DskObject& value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetOid(v, value.oid);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const Character name[], const DskParam* pValue, LineNumber line) const
{
	ShortDskParam var;
	paramSetCString(var, name);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, pValue, line);
}

inline int DskObject::setProperty(const Character name[], const DskPoint* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetPoint(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const Character name[], Float value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetReal(v, (Real) value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const Character name[], Real value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetReal(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const Character name[], const DskTimeStamp* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetTimeStamp(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const Character name[], const DskTimeStampInterval* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetTimeStampInterval(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const Character name[], const DskTimeStampOffset* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetTimeStampOffset(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const Character name[], const DskDecimal* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetDecimal(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const Character name[], const DskMemoryAddress* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetMemoryAddress(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setDateProperty(const Character name[], DskDate value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetDate(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setTimeProperty(const Character name[], DskTime value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetTime(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setBinaryProperty(const Character name[], const BYTE* pValue, PropertyLen byteSize, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetBinaryBlock(v, (const BYTE*) pValue, byteSize);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setUInt16Property(const Character name[], UInt16 value, LineNumber line) const
{
	return setProperty(name, (UInt32) value, line);
}

#ifdef JADESTR_TYPEDEFS_DEFINED
inline int DskObject::setJadeStringProperty(const Character name[], String* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetJadeString(v, pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setJadeStringUtf8Property(const Character name[], StringUtf8* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetJadeStringUtf8(v, pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setJadeBinaryProperty(const Character name[], Binary* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetJadeBinary(v, pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}
#endif

inline int DskObject::setProperty(ClassNumber cNo, FeatureNum mNo, Character value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetCharacter(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(ClassNumber cNo, FeatureNum mNo, Byte value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetByte(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(ClassNumber cNo, FeatureNum mNo, Boolean value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetBoolean(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(ClassNumber cNo, FeatureNum mNo, bool value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetBoolean(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(ClassNumber cNo, FeatureNum mNo, const Character value[], LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetCString(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(ClassNumber cNo, FeatureNum mNo, const Character value[], PropertyLen length, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetCharBlock(v, value, length);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(ClassNumber cNo, FeatureNum mNo, Int16 value, LineNumber line) const
{
	return setProperty(cNo, mNo, (Int32)value, line);
}

inline int DskObject::setProperty(ClassNumber cNo, FeatureNum mNo, Int32 value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetInteger(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(ClassNumber cNo, FeatureNum mNo, UInt32 value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetUnsignedInteger(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(ClassNumber cNo, FeatureNum mNo, Int64 value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetInteger64(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(ClassNumber cNo, FeatureNum mNo, UInt64 value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetUnsignedInteger64(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(ClassNumber cNo, FeatureNum mNo, const DskObjectId* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetOid(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(ClassNumber cNo, FeatureNum mNo, const ShortDskObjectId* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetOid(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(ClassNumber cNo, FeatureNum mNo, const OidKey* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetOid(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(ClassNumber cNo, FeatureNum mNo, const DskObject* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetOid(v, pValue->oid);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(ClassNumber cNo, FeatureNum mNo, const DskObject& value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetOid(v, value.oid);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(ClassNumber cNo, FeatureNum mNo, const DskParam* pValue, LineNumber line) const
{
	ShortDskParam var;
	paramSetClassFeature(var, cNo, mNo);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, pValue, line);
}

inline int DskObject::setProperty(ClassNumber cNo, FeatureNum mNo, const DskPoint* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetPoint(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(ClassNumber cNo, FeatureNum mNo, Float value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetReal(v, (Real) value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(ClassNumber cNo, FeatureNum mNo, Real value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetReal(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(ClassNumber cNo, FeatureNum mNo, const DskTimeStamp* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetTimeStamp(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(ClassNumber cNo, FeatureNum mNo, const DskTimeStampInterval* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetTimeStampInterval(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(ClassNumber cNo, FeatureNum mNo, const DskTimeStampOffset* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetTimeStampOffset(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(ClassNumber cNo, FeatureNum mNo, const DskDecimal* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetDecimal(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(ClassNumber cNo, FeatureNum mNo, const DskMemoryAddress* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetMemoryAddress(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setDateProperty(ClassNumber cNo, FeatureNum mNo, DskDate value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetDate(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setTimeProperty(ClassNumber cNo, FeatureNum mNo, DskTime value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetTime(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setBinaryProperty(ClassNumber cNo, FeatureNum mNo, const BYTE* pValue, PropertyLen length, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetBinaryBlock(v, (const BYTE*) pValue, length);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setUInt16Property(ClassNumber cNo, FeatureNum mNo, UInt16 value, LineNumber line) const
{
	return setProperty(cNo, mNo, (UInt32) value, line);
}

#ifdef JADESTR_TYPEDEFS_DEFINED
inline int DskObject::setJadeStringProperty(ClassNumber cNo, FeatureNum mNo, String* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetJadeString(v, pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setJadeStringUtf8Property(ClassNumber cNo, FeatureNum mNo, StringUtf8* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetJadeStringUtf8(v, pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setJadeBinaryProperty(ClassNumber cNo, FeatureNum mNo, Binary* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetJadeBinary(v, pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}
#endif

inline int DskObject::setProperty(const JomClassFeatureLevel& feature, Character value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetCharacter(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const JomClassFeatureLevel& feature, Byte value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetByte(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const JomClassFeatureLevel& feature, Boolean value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetBoolean(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const JomClassFeatureLevel& feature, bool value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetBoolean(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const JomClassFeatureLevel& feature, const Character value[], LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetCString(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const JomClassFeatureLevel& feature, const Character value[], PropertyLen length, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetCharBlock(v, value, length);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const JomClassFeatureLevel& feature, Int16 value, LineNumber line) const
{
	return setProperty(feature, (Int32)value, line);
}

inline int DskObject::setProperty(const JomClassFeatureLevel& feature, Int32 value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetInteger(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const JomClassFeatureLevel& feature, UInt32 value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetUnsignedInteger(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const JomClassFeatureLevel& feature, Int64 value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetInteger64(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const JomClassFeatureLevel& feature, UInt64 value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetUnsignedInteger64(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const JomClassFeatureLevel& feature, const DskObjectId* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetOid(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const JomClassFeatureLevel& feature, const ShortDskObjectId* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetOid(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const JomClassFeatureLevel& feature, const OidKey* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetOid(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const JomClassFeatureLevel& feature, const DskObject* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetOid(v, pValue->oid);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const JomClassFeatureLevel& feature, const DskObject& value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetOid(v, value.oid);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const JomClassFeatureLevel& feature, const DskParam* pValue, LineNumber line) const
{
	ShortDskParam var;
	paramSetClassFeatureLevel(var, feature);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, pValue, line);
}

inline int DskObject::setProperty(const JomClassFeatureLevel& feature, const DskPoint* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetPoint(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const JomClassFeatureLevel& feature, Float value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetReal(v, (Real) value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const JomClassFeatureLevel& feature, Real value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetReal(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const JomClassFeatureLevel& feature, const DskTimeStamp* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetTimeStamp(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const JomClassFeatureLevel& feature, const DskTimeStampInterval* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetTimeStampInterval(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const JomClassFeatureLevel& feature, const DskTimeStampOffset* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetTimeStampOffset(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const JomClassFeatureLevel& feature, const DskDecimal* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetDecimal(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setProperty(const JomClassFeatureLevel& feature, const DskMemoryAddress* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetMemoryAddress(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setDateProperty(const JomClassFeatureLevel& feature, DskDate value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetDate(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setTimeProperty(const JomClassFeatureLevel& feature, DskTime value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetTime(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setBinaryProperty(const JomClassFeatureLevel& feature, const BYTE* pValue, PropertyLen length, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetBinaryBlock(v, (const BYTE*) pValue, length);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setUInt16Property(const JomClassFeatureLevel& feature, UInt16 value, LineNumber line) const
{
	return setProperty(feature, (UInt32) value, line);
}

#ifdef JADESTR_TYPEDEFS_DEFINED
inline int DskObject::setJadeStringProperty(const JomClassFeatureLevel& feature, String* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetJadeString(v, pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setJadeStringUtf8Property(const JomClassFeatureLevel& feature, StringUtf8* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetJadeStringUtf8(v, pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::setJadeBinaryProperty(const JomClassFeatureLevel& feature, Binary* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetJadeBinary(v, pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}
#endif

inline int DskObject::setProperty(ShortDskParam& prop, Character value, LineNumber line) const
{
	ShortDskParam v;
	paramSetCharacter(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
}

inline int DskObject::setProperty(ShortDskParam& prop, Boolean value, LineNumber line) const
{
	ShortDskParam v;
	paramSetBoolean(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
}

inline int DskObject::setProperty(ShortDskParam& prop, bool value, LineNumber line) const
{
	ShortDskParam v;
	paramSetBoolean(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
}

inline int DskObject::setProperty(ShortDskParam& prop, const Character value[], LineNumber line) const
{
	ShortDskParam v;
	paramSetCString(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
}

inline int DskObject::setProperty(ShortDskParam& prop, Int32 value, LineNumber line) const
{
	ShortDskParam v;
	paramSetInteger(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
}

inline int DskObject::setProperty(ShortDskParam& prop, UInt32 value, LineNumber line) const
{
	ShortDskParam v;
	paramSetUnsignedInteger(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
}

inline int DskObject::setProperty(ShortDskParam& prop, const ShortDskObjectId* pValue, LineNumber line) const
{
	ShortDskParam v;
	paramSetOid(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
}

inline int DskObject::setProperty(ShortDskParam& prop, const OidKey* pValue, LineNumber line) const
{
	ShortDskParam v;
	paramSetOid(v, *pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
}

inline int DskObject::setProperty(ShortDskParam& prop, Int64 value, LineNumber line) const
{
	ShortDskParam v;
	paramSetInteger64(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
}

inline int DskObject::setProperty(ShortDskParam& prop, UInt64 value, LineNumber line) const
{
	ShortDskParam v;
	paramSetUnsignedInteger64(v, value);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
}

inline int DskObject::setProperty(ShortDskParam& prop, const DskObject* pValue, LineNumber line) const
{
	ShortDskParam v;
	paramSetOid(v, pValue->oid);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
}

inline int DskObject::setProperty(ShortDskParam& prop, const DskObject& value, LineNumber line) const
{
	ShortDskParam v;
	paramSetOid(v, value.oid);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
}

#ifdef JADESTR_TYPEDEFS_DEFINED
inline int DskObject::setJadeStringProperty(ShortDskParam& prop, String* pValue, LineNumber line) const
{
	ShortDskParam v;
	paramSetJadeString(v, pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
}

inline int DskObject::setJadeStringUtf8Property(ShortDskParam& prop, StringUtf8* pValue, LineNumber line) const
{
	ShortDskParam v;
	paramSetJadeStringUtf8(v, pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
}

inline int DskObject::setJadeBinaryProperty(ShortDskParam& prop, Binary* pValue, LineNumber line) const
{
	ShortDskParam v;
	paramSetJadeBinary(v, pValue);

	return ::jomSetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
}
#endif

//------------------------------------------------------------------------------
// DskObject get Properties:

inline int DskObject::getProperty(const Character name[], Character value[], LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetCString(v, value);

	return ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::getProperty(const Character name[], Character value[], PropertyLen buffSize, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetCharBlock(v, value, buffSize);

	return ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::getProperty(const Character name[], Boolean* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetBoolean(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetBoolean(v, *pValue);
}

inline int DskObject::getProperty(const Character name[], bool* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetBoolean(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetBoolean(v, *pValue);
}

inline int DskObject::getProperty(const Character name[], Byte* pValue, LineNumber line) const
{
	ShortDskParam var, v;

	paramSetCString(var, name);
	paramSetByte(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetByte(v, *pValue);
}

inline int DskObject::getProperty(const Character name[], Int16* pValue, LineNumber line) const
{
	Int32 value32;
	int result = getProperty(name, &value32, line);
	CHECK_RESULT;

#ifdef SAFE_ASSIGN_DEFINED
	*pValue = safe_assign<Int16>(value32);
#else
	*pValue = (Int16) value32;
#endif

	return J_OK;
}

inline int DskObject::getProperty(const Character name[], Int32* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetInteger(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetInteger(v, *pValue);
}

inline int DskObject::getProperty(const Character name[], UInt32* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetUnsignedInteger(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetUnsignedInteger(v, *pValue);
}

inline int DskObject::getProperty(const Character name[], Int64* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetInteger64(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetInteger64(v, *pValue);
}

inline int DskObject::getProperty(const Character name[], UInt64* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetUnsignedInteger64(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetUnsignedInteger64(v, *pValue);
}

inline int DskObject::getProperty(const Character name[], DskObjectId* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetOid(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetOid(v, *pValue);
}

inline int DskObject::getProperty(const Character name[], ShortDskObjectId* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetOid(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetOid(v, *pValue);
}

inline int DskObject::getProperty(const Character name[], OidKey* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetOid(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetOid(v, *pValue);
}

inline int DskObject::getProperty(const Character name[], DskObject& value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetOid(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetOid(v, value.oid);
}

inline int DskObject::getProperty(const Character name[], DskParam* pValue, LineNumber line) const
{
	ShortDskParam var;
	paramSetCString(var, name);

	return ::jomGetProperty(JomDefaultProcessHandle, &oid, var, pValue, line);
}

inline int DskObject::getProperty(const Character name[], DskPoint* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetPoint(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetPoint(v, *pValue);
}

inline int DskObject::getProperty(const Character name[], Float* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetReal(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	Real value;
	result = paramGetReal(v, value);
	CHECK_RESULT;

	*pValue = (Float) value;

	return J_OK;
}

inline int DskObject::getProperty(const Character name[], Real* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetReal(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetReal(v, *pValue);
}

inline int DskObject::getProperty(const Character name[], DskTimeStamp* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetTimeStamp(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetTimeStamp(v, *pValue);
}

inline int DskObject::getProperty(const Character name[], DskTimeStampInterval* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetTimeStampInterval(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetTimeStampInterval(v, *pValue);
}

inline int DskObject::getProperty(const Character name[], DskTimeStampOffset* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetTimeStampOffset(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetTimeStampOffset(v, *pValue);
}

inline int DskObject::getProperty(const Character name[], DskDecimal* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetDecimal(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetDecimal(v, *pValue);
}

inline int DskObject::getProperty(const Character name[], DskMemoryAddress* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetMemoryAddress(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetMemoryAddress(v, *pValue);
}

inline int DskObject::getDateProperty(const Character name[], DskDate* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetDate(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetDate(v, *pValue);
}

inline int DskObject::getTimeProperty(const Character name[], DskTime* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetTime(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetTime(v, *pValue);
}

inline int DskObject::getBinaryProperty(const Character name[], BYTE* pValue, PropertyLen* pLengthInOut, LineNumber line) const
// ! pLengthInOut is in/out parameter
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetBinaryBlock(v, (BYTE*) pValue, *pLengthInOut);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	*pLengthInOut= v.body.binaryBlockPtr.length;

	return J_OK;
}

inline int DskObject::getCharProperty(const Character name[], Character* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetCharacter(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetCharacter(v, *pValue);
}

inline int DskObject::getUInt16Property(const Character name[], UInt16* pValue, LineNumber line) const
{
	UInt32 value32;
	int result = getProperty(name, &value32, line);
	CHECK_RESULT;

#ifdef SAFE_ASSIGN_DEFINED
	*pValue = safe_assign<UInt16>(value32);
#else
	*pValue = (UInt16) value32;
#endif

	return J_OK;
}

#ifdef JADESTR_TYPEDEFS_DEFINED
inline int DskObject::getJadeStringProperty(const Character name[], String* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetJadeString(v, pValue);

	return ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::getJadeStringUtf8Property(const Character name[], StringUtf8* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetJadeStringUtf8(v, pValue);

	return ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::getJadeBinaryProperty(const Character name[], Binary* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetCString(var, name);
	paramSetJadeBinary(v, pValue);

	return ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}
#endif

inline int DskObject::getProperty(ClassNumber cNo, FeatureNum mNo, Character value[], LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetCString(v, value);

	return ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::getProperty(ClassNumber cNo, FeatureNum mNo, Character value[], PropertyLen buffSize, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetCharBlock(v, value, buffSize);

	return ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::getProperty(ClassNumber cNo, FeatureNum mNo, Boolean* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetBoolean(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetBoolean(v, *pValue);
}

inline int DskObject::getProperty(ClassNumber cNo, FeatureNum mNo, bool* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetBoolean(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetBoolean(v, *pValue);
}

inline int DskObject::getProperty(ClassNumber cNo, FeatureNum mNo, Byte* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetByte(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetByte(v, *pValue);
}

inline int DskObject::getProperty(ClassNumber cNo, FeatureNum mNo, Int16* pValue, LineNumber line) const
{
	Int32 value32;
	int result = getProperty(cNo, mNo, &value32, line);
	CHECK_RESULT;

#ifdef SAFE_ASSIGN_DEFINED
	*pValue = safe_assign<Int16>(value32);
#else
	*pValue = (Int16) value32;
#endif

	return J_OK;
}

inline int DskObject::getProperty(ClassNumber cNo, FeatureNum mNo, UInt32* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetUnsignedInteger(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetUnsignedInteger(v, *pValue);
}

inline int DskObject::getProperty(ClassNumber cNo, FeatureNum mNo, Int32* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetInteger(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetInteger(v, *pValue);
}

inline int DskObject::getProperty(ClassNumber cNo, FeatureNum mNo, Int64* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetInteger64(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetInteger64(v, *pValue);
}

inline int DskObject::getProperty(ClassNumber cNo, FeatureNum mNo, UInt64* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetUnsignedInteger64(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetUnsignedInteger64(v, *pValue);
}

inline int DskObject::getProperty(ClassNumber cNo, FeatureNum mNo, DskObjectId* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetOid(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetOid(v, *pValue);
}

inline int DskObject::getProperty(ClassNumber cNo, FeatureNum mNo, ShortDskObjectId* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetOid(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetOid(v, *pValue);
}

inline int DskObject::getProperty(ClassNumber cNo, FeatureNum mNo, OidKey* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetOid(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetOid(v, *pValue);
}

inline int DskObject::getProperty(ClassNumber cNo, FeatureNum mNo, DskObject& value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetOid(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetOid(v, value.oid);
}

inline int DskObject::getProperty(ClassNumber cNo, FeatureNum mNo, DskParam* pValue, LineNumber line) const
{
	ShortDskParam var;
	paramSetClassFeature(var, cNo, mNo);

	return ::jomGetProperty(JomDefaultProcessHandle, &oid, var, pValue, line);
}

inline int DskObject::getProperty(ClassNumber cNo, FeatureNum mNo, DskPoint* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetPoint(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetPoint(v, *pValue);
}

inline int DskObject::getProperty(ClassNumber cNo, FeatureNum mNo, Float* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetReal(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	Real value;
	result = paramGetReal(v, value);
	CHECK_RESULT;

	*pValue = (Float) value;

	return J_OK;
}

inline int DskObject::getProperty(ClassNumber cNo, FeatureNum mNo, Real* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetReal(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetReal(v, *pValue);
}

inline int DskObject::getProperty(ClassNumber cNo, FeatureNum mNo, DskTimeStamp* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetTimeStamp(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetTimeStamp(v, *pValue);
}

inline int DskObject::getProperty(ClassNumber cNo, FeatureNum mNo, DskTimeStampInterval* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetTimeStampInterval(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetTimeStampInterval(v, *pValue);
}

inline int DskObject::getProperty(ClassNumber cNo, FeatureNum mNo, DskTimeStampOffset* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetTimeStampOffset(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetTimeStampOffset(v, *pValue);
}

inline int DskObject::getProperty(ClassNumber cNo, FeatureNum mNo, DskDecimal* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetDecimal(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetDecimal(v, *pValue);
}

inline int DskObject::getProperty(ClassNumber cNo, FeatureNum mNo, DskMemoryAddress* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetMemoryAddress(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetMemoryAddress(v, *pValue);
}

inline int DskObject::getDateProperty(ClassNumber cNo, FeatureNum mNo, DskDate* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetDate(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetDate(v, *pValue);
}

inline int DskObject::getTimeProperty(ClassNumber cNo, FeatureNum mNo, DskTime* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetTime(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetTime(v, *pValue);
}

inline int DskObject::getBinaryProperty(ClassNumber cNo, FeatureNum mNo, BYTE* pValue, PropertyLen* pLengthInOut, LineNumber line) const
// ! pLengthInOut is in/out parameter
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetBinaryBlock(v, (BYTE*) pValue, *pLengthInOut);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	*pLengthInOut= v.body.binaryBlockPtr.length;

	return J_OK;
}

inline int DskObject::getCharProperty(ClassNumber cNo, FeatureNum mNo, Character* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetCharacter(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetCharacter(v, *pValue);
}

inline int DskObject::getUInt16Property(ClassNumber cNo, FeatureNum mNo, UInt16* pValue, LineNumber line) const
{
	UInt32 value32;
	int result = getProperty(cNo, mNo, &value32, line);
	CHECK_RESULT;

#ifdef SAFE_ASSIGN_DEFINED
	*pValue = safe_assign<UInt16>(value32);
#else
	*pValue = (UInt16) value32;
#endif

	return J_OK;
}

#ifdef JADESTR_TYPEDEFS_DEFINED
inline int DskObject::getJadeStringProperty(ClassNumber cNo, FeatureNum mNo, String* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetJadeString(v, pValue);

	return ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::getJadeStringUtf8Property(ClassNumber cNo, FeatureNum mNo, StringUtf8* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetJadeStringUtf8(v, pValue);

	return ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::getJadeBinaryProperty(ClassNumber cNo, FeatureNum mNo, Binary* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeature(var, cNo, mNo);
	paramSetJadeBinary(v, pValue);

	return ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}
#endif

inline int DskObject::getProperty(const JomClassFeatureLevel& feature, Character value[], LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetCString(v, value);

	return ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::getProperty(const JomClassFeatureLevel& feature, Character value[], PropertyLen buffSize, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetCharBlock(v, value, buffSize);

	return ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::getProperty(const JomClassFeatureLevel& feature, Boolean* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetBoolean(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetBoolean(v, *pValue);
}

inline int DskObject::getProperty(const JomClassFeatureLevel& feature, bool* pValue, LineNumber line) const
{
	ShortDskParam var, v;

	paramSetClassFeatureLevel(var, feature);
	paramSetBoolean(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetBoolean(v, *pValue);
}

inline int DskObject::getProperty(const JomClassFeatureLevel& feature, Byte* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetByte(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetByte(v, *pValue);
}

inline int DskObject::getProperty(const JomClassFeatureLevel& feature, Int16* pValue, LineNumber line) const
{
	Int32 value32;
	int result = getProperty(feature, &value32, line);
	CHECK_RESULT;

#ifdef SAFE_ASSIGN_DEFINED
	*pValue = safe_assign<Int16>(value32);
#else
	*pValue = (Int16) value32;
#endif

	return J_OK;
}

inline int DskObject::getProperty(const JomClassFeatureLevel& feature, UInt32* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetUnsignedInteger(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetUnsignedInteger(v, *pValue);
}

inline int DskObject::getProperty(const JomClassFeatureLevel& feature, Int32* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetInteger(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetInteger(v, *pValue);
}

inline int DskObject::getProperty(const JomClassFeatureLevel& feature, Int64* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetInteger64(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetInteger64(v, *pValue);
}

inline int DskObject::getProperty(const JomClassFeatureLevel& feature, UInt64* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetUnsignedInteger64(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetUnsignedInteger64(v, *pValue);
}

inline int DskObject::getProperty(const JomClassFeatureLevel& feature, DskObjectId* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetOid(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetOid(v, *pValue);
}

inline int DskObject::getProperty(const JomClassFeatureLevel& feature, ShortDskObjectId* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetOid(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetOid(v, *pValue);
}

inline int DskObject::getProperty(const JomClassFeatureLevel& feature, OidKey* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetOid(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetOid(v, *pValue);
}

inline int DskObject::getProperty(const JomClassFeatureLevel& feature, DskObject& value, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetOid(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetOid(v, value.oid);
}

inline int DskObject::getProperty(const JomClassFeatureLevel& feature, PDskObject& pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetOid(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	DskObjectId o;
	result = paramGetOid(v, o);
	CHECK_RESULT;

	pValue = o.isNull() ? nullptr : createInst(o); // the sender must delete it

	return J_OK;
}

inline int DskObject::getProperty(const JomClassFeatureLevel& feature, DskParam* pValue, LineNumber line) const
{
	ShortDskParam var;
	paramSetClassFeatureLevel(var, feature);

	return ::jomGetProperty(JomDefaultProcessHandle, &oid, var, pValue, line);
}

inline int DskObject::getProperty(const JomClassFeatureLevel& feature, DskPoint* pValue, LineNumber line) const
{
	ShortDskParam var, v;

	paramSetClassFeatureLevel(var, feature);
	paramSetPoint(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetPoint(v, *pValue);
}

inline int DskObject::getProperty(const JomClassFeatureLevel& feature, Float* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetReal(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	Real value;
	result = paramGetReal(v, value);
	CHECK_RESULT;

	*pValue = (Float) value;

	return J_OK;
}

inline int DskObject::getProperty(const JomClassFeatureLevel& feature, Real* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetReal(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetReal(v, *pValue);
}

inline int DskObject::getProperty(const JomClassFeatureLevel& feature, DskTimeStamp* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetTimeStamp(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetTimeStamp(v, *pValue);
}

inline int DskObject::getProperty(const JomClassFeatureLevel& feature, DskTimeStampInterval* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetTimeStampInterval(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetTimeStampInterval(v, *pValue);
}

inline int DskObject::getProperty(const JomClassFeatureLevel& feature, DskTimeStampOffset* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetTimeStampOffset(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetTimeStampOffset(v, *pValue);
}

inline int DskObject::getProperty(const JomClassFeatureLevel& feature, DskDecimal* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetDecimal(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetDecimal(v, *pValue);
}

inline int DskObject::getProperty(const JomClassFeatureLevel& feature, DskMemoryAddress* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetMemoryAddress(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetMemoryAddress(v, *pValue);
}

inline int DskObject::getDateProperty(const JomClassFeatureLevel& feature, DskDate* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetDate(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetDate(v, *pValue);
}

inline int DskObject::getTimeProperty(const JomClassFeatureLevel& feature, DskTime* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetTime(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetTime(v, *pValue);
}

inline int DskObject::getBinaryProperty(const JomClassFeatureLevel& feature, BYTE* pValue, PropertyLen* pLengthInOut, LineNumber line) const
// ! pLengthInOut is in/out parameter
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetBinaryBlock(v, (BYTE*) pValue, *pLengthInOut);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	*pLengthInOut= v.body.binaryBlockPtr.length;

	return J_OK;
}

inline int DskObject::getCharProperty(const JomClassFeatureLevel& feature, Character* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetCharacter(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
	CHECK_RESULT;

	return paramGetCharacter(v, *pValue);
}

inline int DskObject::getUInt16Property(const JomClassFeatureLevel& feature, UInt16* pValue, LineNumber line) const
{
	UInt32 value32;
	int result = getProperty(feature, &value32, line);
	CHECK_RESULT;

#ifdef SAFE_ASSIGN_DEFINED
	*pValue = safe_assign<UInt16>(value32);
#else
	*pValue = (UInt16) value32;
#endif

	return J_OK;
}

#ifdef JADESTR_TYPEDEFS_DEFINED
inline int DskObject::getJadeStringProperty(const JomClassFeatureLevel& feature, String* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetJadeString(v, pValue);

	return ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::getJadeStringUtf8Property(const JomClassFeatureLevel& feature, StringUtf8* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetJadeStringUtf8(v, pValue);

	return ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}

inline int DskObject::getJadeBinaryProperty(const JomClassFeatureLevel& feature, Binary* pValue, LineNumber line) const
{
	ShortDskParam var, v;
	paramSetClassFeatureLevel(var, feature);
	paramSetJadeBinary(v, pValue);

	return ::jomGetProperty(JomDefaultProcessHandle, &oid, var, v, line);
}
#endif

inline int DskObject::getProperty(ShortDskParam& prop, Character value[], LineNumber line) const
{
	ShortDskParam v;
	paramSetCString(v, value);

	return ::jomGetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
}

inline int DskObject::getProperty(ShortDskParam& prop, Boolean* pValue, LineNumber line) const
{
	ShortDskParam v;
	paramSetBoolean(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
	CHECK_RESULT;

	return paramGetBoolean(v, *pValue);
}

inline int DskObject::getProperty(ShortDskParam& prop, bool* pValue, LineNumber line) const
{
	ShortDskParam v;
	paramSetBoolean(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
	CHECK_RESULT;

	return paramGetBoolean(v, *pValue);
}

inline int DskObject::getProperty(ShortDskParam& prop, Byte* pValue, LineNumber line) const
{
	ShortDskParam v;
	paramSetByte(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
	CHECK_RESULT;

	return paramGetByte(v, *pValue);
}

inline int DskObject::getProperty(ShortDskParam& prop, Int16* pValue, LineNumber line) const
{
	Int32 value32;
	int result = getProperty(prop, &value32, line);
	CHECK_RESULT;

#ifdef SAFE_ASSIGN_DEFINED
	*pValue = safe_assign<Int16>(value32);
#else
	*pValue = (Int16) value32;
#endif

	return J_OK;
}

inline int DskObject::getProperty(ShortDskParam& prop, Int32* pValue, LineNumber line) const
{
	ShortDskParam v;
	paramSetInteger(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
	CHECK_RESULT;

	return paramGetInteger(v, *pValue);
}

inline int DskObject::getProperty(ShortDskParam& prop, UInt32* pValue, LineNumber line) const
{
	ShortDskParam v;
	paramSetUnsignedInteger(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
	CHECK_RESULT;

	return paramGetUnsignedInteger(v, *pValue);
}

inline int DskObject::getProperty(ShortDskParam& prop, Int64* pValue, LineNumber line) const
{
	ShortDskParam v;
	paramSetInteger64(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
	CHECK_RESULT;

	return paramGetInteger64(v, *pValue);
}

inline int DskObject::getProperty(ShortDskParam& prop, UInt64* pValue, LineNumber line) const
{
	ShortDskParam v;
	paramSetUnsignedInteger64(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
	CHECK_RESULT;

	return paramGetUnsignedInteger64(v, *pValue);
}

inline int DskObject::getProperty(ShortDskParam& prop, DskObjectId* pValue, LineNumber line) const
{
	ShortDskParam v;
	paramSetOid(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
	CHECK_RESULT;

	return paramGetOid(v, *pValue);
}

inline int DskObject::getProperty(ShortDskParam& prop, ShortDskObjectId* pValue, LineNumber line) const
{
	ShortDskParam v;
	paramSetOid(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
	CHECK_RESULT;

	return paramGetOid(v, *pValue);
}

inline int DskObject::getProperty(ShortDskParam& prop, OidKey* pValue, LineNumber line) const
{
	ShortDskParam v;
	paramSetOid(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
	CHECK_RESULT;

	return paramGetOid(v, *pValue);
}

inline int DskObject::getProperty(ShortDskParam& prop, DskObject& value, LineNumber line) const
{
	ShortDskParam v;
	paramSetOid(v);

	int result = ::jomGetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
	CHECK_RESULT;

	return paramGetOid(v, value.oid);
}

#ifdef JADESTR_TYPEDEFS_DEFINED
inline int DskObject::getJadeStringProperty(ShortDskParam& prop, String* pValue, LineNumber line) const
{
	ShortDskParam v;
	paramSetJadeString(v, pValue);

	return ::jomGetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
}

inline int DskObject::getJadeStringUtf8Property(ShortDskParam& prop, StringUtf8* pValue, LineNumber line) const
{
	ShortDskParam v;
	paramSetJadeStringUtf8(v, pValue);

	return ::jomGetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
}

inline int DskObject::getJadeBinaryProperty(ShortDskParam& prop, Binary* pValue, LineNumber line) const
{
	ShortDskParam v;
	paramSetJadeBinary(v, pValue);

	return ::jomGetProperty(JomDefaultProcessHandle, &oid, prop, v, line);
}
#endif

//------------------------------------------------------------------------------
// DskObject send message:

inline int DskObject::sendMsg(const Character message[], DskParam* pParams, DskParam* pReturn, LineNumber line) const
{
	ShortDskParam msg;
	paramSetCString(msg, message);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, pParams, pReturn, line);
}

inline int DskObject::sendMsg(const Character message[], Character string[], LineNumber line) const
{
	ShortDskParam msg, in;
	paramSetCString(msg, message);
	paramSetCString(in, string);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, in, nullptr, line);
}

inline int DskObject::sendMsg(const Character message[], Integer n, LineNumber line) const
{
	ShortDskParam msg, in;
	paramSetCString(msg, message);
	paramSetInteger(in, n);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, in, nullptr, line);
}

inline int DskObject::sendMsg(const Character message[], UInteger n, LineNumber line) const
{
	ShortDskParam msg, in;
	paramSetCString(msg, message);
	paramSetInteger(in, n);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, in, nullptr, line);
}

inline int DskObject::sendMsg(const Character message[], Character c, LineNumber line) const
{
	ShortDskParam msg, in;
	paramSetCString(msg, message);
	paramSetCharacter(in, c);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, in, nullptr, line);
}

inline int DskObject::sendMsg(const Character message[], Boolean b, LineNumber line) const
{
	ShortDskParam msg, in;
	paramSetCString(msg, message);
	paramSetBoolean(in, b);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, in, nullptr, line);
}

inline int DskObject::sendMsg(const Character message[], bool b, LineNumber line) const
{
	ShortDskParam msg, in;
	paramSetCString(msg, message);
	paramSetBoolean(in, b);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, in, nullptr, line);
}

inline int DskObject::sendMsg(const Character message[], const DskObject* pObj, LineNumber line) const
{
	ShortDskParam msg, in;
	paramSetCString(msg, message);
	paramSetOid(in, pObj->oid);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, in, nullptr, line);
}

inline int DskObject::sendMsg(const Character message[], DskObject* pObj1, DskObject* pObj2, LineNumber line) const
{
	ShortDskParam msg, o1, o2;
	paramSetCString(msg, message);
	if (pObj1)
		paramSetOid(o1, pObj1->oid);
	paramSetOid(o2, pObj2->oid);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, pObj1 ? o1 : static_cast<DskParam*>(nullptr), o2, line);
}

inline int DskObject::sendMsg(const Character message[], DskObject& o, LineNumber line) const
{
	ShortDskParam msg, oParam;
	paramSetCString(msg, message);
	paramSetOid(oParam, o.oid);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, oParam, nullptr, line);
}

inline int DskObject::sendMsg(const Character message[], DskObject* pObj, DskObject& o, LineNumber line) const
{
	ShortDskParam msg, o1, o2;
	paramSetCString(msg, message);
	if (pObj)
		paramSetOid(o1, pObj->oid);
	paramSetOid(o2, o.oid);

	int result = ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, pObj ? o1 : static_cast<DskParam*>(nullptr), o2, line);
	CHECK_RESULT;

	return paramGetOid(o2, o.oid);
}

inline int DskObject::sendMsg(const Character message[], const DskObjectId& o, LineNumber line) const
{
	ShortDskParam msg, oParam;
	paramSetCString(msg, message);
	paramSetOid(oParam, o);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, oParam, nullptr, line);
}

inline int DskObject::sendMsg(ClassNumber cNo, FeatureNum mNo, DskParam* pParams, DskParam* pReturn, LineNumber line) const
{
	ShortDskParam msg;
	paramSetClassFeature(msg, cNo, mNo);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, pParams, pReturn, line);
}

inline int DskObject::sendMsg(ClassNumber cNo, FeatureNum mNo, Character string[], LineNumber line) const
{
	ShortDskParam msg, in;
	paramSetClassFeature(msg, cNo, mNo);
	paramSetCString(in, string);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, in, nullptr, line);
}

inline int DskObject::sendMsg(ClassNumber cNo, FeatureNum mNo, Integer n, LineNumber line) const
{
	ShortDskParam msg, in;

	paramSetClassFeature(msg, cNo, mNo);
	paramSetInteger(in, n);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, in, nullptr, line);
}

inline int DskObject::sendMsg(ClassNumber cNo, FeatureNum mNo, UInteger n, LineNumber line) const
{
	ShortDskParam msg, in;

	paramSetClassFeature(msg, cNo, mNo);
	paramSetInteger(in, n);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, in, nullptr, line);
}

inline int DskObject::sendMsg(ClassNumber cNo, FeatureNum mNo, Character c, LineNumber line) const
{
	ShortDskParam msg, in;
	paramSetClassFeature(msg, cNo, mNo);
	paramSetCharacter(in, c);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, in, nullptr, line);
}

inline int DskObject::sendMsg(ClassNumber cNo, FeatureNum mNo, Boolean b, LineNumber line) const
{
	ShortDskParam msg, in;
	paramSetClassFeature(msg, cNo, mNo);
	paramSetBoolean(in, b);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, in, nullptr, line);
}

inline int DskObject::sendMsg(ClassNumber cNo, FeatureNum mNo, bool b, LineNumber line) const
{
	ShortDskParam msg, in;

	paramSetClassFeature(msg, cNo, mNo);
	paramSetBoolean(in, b);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, in, nullptr, line);
}

inline int DskObject::sendMsg(ClassNumber cNo, FeatureNum mNo, const DskObject* pObj, LineNumber line) const
{
	ShortDskParam msg, in;
	paramSetClassFeature(msg, cNo, mNo);
	paramSetOid(in, pObj->oid);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, in, nullptr, line);
}

inline int DskObject::sendMsg(ClassNumber cNo, FeatureNum mNo, DskObject* pObj1, DskObject* pObj2, LineNumber line) const
{
	ShortDskParam msg, o1, o2;
	paramSetClassFeature(msg, cNo, mNo);
	if (pObj1)
		paramSetOid(o1, pObj1->oid);
	paramSetOid(o2, pObj2->oid);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, pObj1 ? o1 : static_cast<DskParam*>(nullptr), o2, line);
}

inline int DskObject::sendMsg(ClassNumber cNo, FeatureNum mNo, DskObject& o, LineNumber line) const
{
	ShortDskParam msg, oParam;
	paramSetClassFeature(msg, cNo, mNo);
	paramSetOid(oParam, o.oid);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, oParam, nullptr, line);
}

inline int DskObject::sendMsg(ClassNumber cNo, FeatureNum mNo, DskObject* pObj, DskObject& o, LineNumber line) const
{
	ShortDskParam msg, o1, o2;
	paramSetClassFeature(msg, cNo, mNo);
	if (pObj)
		paramSetOid(o1, pObj->oid);
	paramSetOid(o2, o.oid);

	int result = ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, pObj ? o1 : static_cast<DskParam*>(nullptr), o2, line);
	CHECK_RESULT;

	return paramGetOid(o2, o.oid);
}

inline int DskObject::sendMsg(ClassNumber cNo, FeatureNum mNo, const DskObjectId& o, LineNumber line) const
{
	ShortDskParam msg, oParam;
	paramSetClassFeature(msg, cNo, mNo);
	paramSetOid(oParam, o);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, oParam, nullptr, line);
}

inline int DskObject::sendMsg(const JomClassFeatureLevel& feature, DskParam* pParams, DskParam* pReturn, LineNumber line) const
{
	ShortDskParam msg;
	paramSetClassFeatureLevel(msg, feature);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, pParams, pReturn, line);
}

inline int DskObject::sendMsg(const JomClassFeatureLevel& feature, Character string[], LineNumber line) const
{
	ShortDskParam msg, in;
	paramSetClassFeatureLevel(msg, feature);
	paramSetCString(in, string);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, in, nullptr, line);
}

inline int DskObject::sendMsg(const JomClassFeatureLevel& feature, Integer n, LineNumber line) const
{
	ShortDskParam msg, in;
	paramSetClassFeatureLevel(msg, feature);
	paramSetInteger(in, n);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, in, nullptr, line);
}

inline int DskObject::sendMsg(const JomClassFeatureLevel& feature, UInteger n, LineNumber line) const
{
	ShortDskParam msg, in;
	paramSetClassFeatureLevel(msg, feature);
	paramSetInteger(in, n);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, in, nullptr, line);
}

inline int DskObject::sendMsg(const JomClassFeatureLevel& feature, Character c, LineNumber line) const
{
	ShortDskParam msg, in;
	paramSetClassFeatureLevel(msg, feature);
	paramSetCharacter(in, c);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, in, nullptr, line);
}

inline int DskObject::sendMsg(const JomClassFeatureLevel& feature, Boolean b, LineNumber line) const
{
	ShortDskParam msg, in;
	paramSetClassFeatureLevel(msg, feature);
	paramSetBoolean(in, b);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, in, nullptr, line);
}

inline int DskObject::sendMsg(const JomClassFeatureLevel& feature, bool b, LineNumber line) const
{
	ShortDskParam msg, in;

	paramSetClassFeatureLevel(msg, feature);
	paramSetBoolean(in, b);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, in, nullptr, line);
}

inline int DskObject::sendMsg(const JomClassFeatureLevel& feature, const DskObject* pObj, LineNumber line) const
{
	ShortDskParam msg, in;
	paramSetClassFeatureLevel(msg, feature);
	paramSetOid(in, pObj->oid);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, in, nullptr, line);
}

inline int DskObject::sendMsg(const JomClassFeatureLevel& feature, DskObject* pObj1, DskObject* pObj2, LineNumber line) const
{
	ShortDskParam msg, o1, o2;
	paramSetClassFeatureLevel(msg, feature);
	if (pObj1)
		paramSetOid(o1, pObj1->oid);
	paramSetOid(o2, pObj2->oid);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, pObj1 ? o1 : static_cast<DskParam*>(nullptr), o2, line);
}

inline int DskObject::sendMsg(const JomClassFeatureLevel& feature, DskObject& o, LineNumber line) const
{
	ShortDskParam msg, oParam;
	paramSetClassFeatureLevel(msg, feature);
	paramSetOid(oParam, o.oid);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, oParam, nullptr, line);
}

inline int DskObject::sendMsg(const JomClassFeatureLevel& feature, DskObject* pObj, DskObject& o, LineNumber line) const
{
	ShortDskParam msg, o1, o2;
	paramSetClassFeatureLevel(msg, feature);
	if (pObj)
		paramSetOid(o1, pObj->oid);
	paramSetOid(o2, o.oid);

	int result = ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, pObj ? o1 : static_cast<DskParam*>(nullptr), o2, line);
	CHECK_RESULT;

	return paramGetOid(o2, o.oid);
}

inline int DskObject::sendMsg(const JomClassFeatureLevel& feature, const DskObjectId& o, LineNumber line) const
{
	ShortDskParam msg, oParam;

	paramSetClassFeatureLevel(msg, feature);
	paramSetOid(oParam, o);

	return ::jomSendMsg(JomDefaultProcessHandle, &oid, msg, oParam, nullptr, line);
}

inline int DskObject::sendMsg(ShortDskParam& message, DskParam* pParams, DskParam* pReturn, LineNumber line) const
{
	return ::jomSendMsg(JomDefaultProcessHandle, &oid, message, pParams, pReturn, line);
}

inline int DskObject::inheritMethod(DskParam* pParams, DskParam* pReturn) const
{
	return ::jomInheritMethod(JomDefaultProcessHandle, &oid, pParams, pReturn, __LINE__);
}

inline int DskObject::getClass(DskClass& klass, LineNumber line) const
{
	return getProperty(TEXT("class"), klass, line);
}

inline int DskObject::getVersion(VersionNum* pVersion) const
{
	return getProperty(TEXT("version"), pVersion, __LINE__);
}

inline int DskObject::getTimeStamp(UInt32* pTimeStamp) const
{
	return getProperty(TEXT("timeStamp"), pTimeStamp, __LINE__);
}

inline bool DskObject::isValid() const
{
	return oid.isValid();
}

inline bool DskObject::isPersistent() const
{
	return oid.isPersistent();
}

inline int DskObject::makePersistent()
{
	oid.makePersistent();
	return J_OK;
}

inline bool DskObject::isTransient() const
{
	return oid.isTransient();
}

inline int DskObject::makeTransient()
{
	oid.makeTransient();
	return J_OK;
}

inline int DskObject::makeSharedTransient()
{
	oid.makeSharedTransient();
	return J_OK;
}

inline bool DskObject::isSharedTransient() const
{
	return oid.isSharedTransient();
}

inline bool DskObject::isNonSharedTransient() const
{
	return oid.isNonSharedTransient();
}

inline bool DskObject::isLockedByMe() const
{
	LockType type;
	LockDuration duration;
	DskObjectId lockedBy;

	::jomGetLockStatus(JomDefaultProcessHandle, &oid, &type, &duration, &lockedBy, __LINE__);

	return type != NO_LOCK;
}

inline bool DskObject::isLockedByMeWith(LockType requiredType) const
{
	LockType type;
	LockDuration duration;
	DskObjectId lockedBy;

	::jomGetLockStatus(JomDefaultProcessHandle, &oid, &type, &duration, &lockedBy, __LINE__);

	return type >= requiredType;
}

//------------------------------------------------------------------------------
// DskDeltaInfo:

inline int DskDeltaInfo::setDeltaId(const Character deltaId[]) const
{
	return setProperty(PRP_DeltaInfo_deltaId, deltaId, __LINE__);
}

inline int DskDeltaInfo::getDeltaId(Character deltaId[]) const
{
	return getProperty(PRP_DeltaInfo_deltaId, deltaId, __LINE__);
}

inline int DskDeltaInfo::methods(JomColl& coll) const
{
	return valuesFromProperty(PRP_DeltaInfo_methods, coll, __LINE__);
}

//------------------------------------------------------------------------------
// DskSchemaEntity:

inline int DskSchemaEntity::getAbstract(bool* pAbstract) const
{
	return getProperty(PRP_SchemaEntity_abstract, pAbstract, __LINE__);
}

inline int DskSchemaEntity::setAbstract(bool abstract)
{
	return setProperty(PRP_SchemaEntity_abstract, abstract, __LINE__);
}

inline int DskSchemaEntity::getAccess(AccessType* pAccess) const
{
	Character c;
	int result = getCharProperty(PRP_SchemaEntity_access, &c);
	*pAccess= (AccessType) c;
	return result;
}

inline int DskSchemaEntity::setAccess(AccessType access)
{
	return sendMsg(MTH_SchemaEntity_setAccess, (Character) access, __LINE__);
}

inline int DskSchemaEntity::getName(Character name[], LineNumber line) const
{
	return getProperty(PRP_SchemaEntity_name, name, line);
}

inline int DskSchemaEntity::setName(const Character name[])
{
	return setProperty(PRP_SchemaEntity_name, name, __LINE__);
}

inline int DskSchemaEntity::getNumber(UInt16* pNumber, LineNumber line) const
{
	return getUInt16Property(PRP_SchemaEntity_number, pNumber, line == 0 ? __LINE__ : line);
}

inline int DskSchemaEntity::setNumber(UInt16 number)
{
	return setProperty(PRP_SchemaEntity_number, number, __LINE__);
}

inline int DskSchemaEntity::getNumber(Int32* pNumber, LineNumber line) const
{
	return getProperty(PRP_SchemaEntity_number, pNumber, line == 0 ? __LINE__ : line);
}

inline int DskSchemaEntity::setNumber(Int32 number)
{
	return setProperty(PRP_SchemaEntity_number, number, __LINE__);
}
inline int DskSchemaEntity::getNumber(UInt32* pNumber, LineNumber line) const
{
	return getProperty(PRP_SchemaEntity_number, pNumber, line == 0 ? __LINE__ : line);
}

inline int DskSchemaEntity::setNumber(UInt32 number)
{
	return setProperty(PRP_SchemaEntity_number, number, __LINE__);
}

inline int DskSchemaEntity::getSubAccess(AccessType* pSubAccess) const
{
	Character c;
	int result = getCharProperty(PRP_SchemaEntity_subAccess, &c);
	*pSubAccess= (AccessType) c;
	return result;
}

inline int DskSchemaEntity::setSubAccess(AccessType subAccess)
{
	Character access= (Character) subAccess;
	return sendMsg(MTH_SchemaEntity_setSubAccess, access, __LINE__);
}

inline int DskSchemaEntity::getModifiedTimeStamp(DskTimeStamp* pModifiedTimeStamp) const
{
	return getProperty(PRP_SchemaEntity_modifiedTimeStamp, pModifiedTimeStamp, __LINE__);
}

inline int DskSchemaEntity::setModifiedTimeStamp(DskTimeStamp* pModifiedTimeStamp)
{
	return setProperty(PRP_SchemaEntity_modifiedTimeStamp, pModifiedTimeStamp, __LINE__);
}

inline int DskSchemaEntity::getPatchVersion(Int32* pPatchVersion) const
{
	return getProperty(PRP_SchemaEntity_patchVersion, pPatchVersion, __LINE__);
}

inline int DskSchemaEntity::setPatchVersion(Int32 patchVersion)
{
	return setProperty(PRP_SchemaEntity_patchVersion, patchVersion, __LINE__);
}

inline int DskSchemaEntity::getSystemVersion(Character systemVersion[]) const
{
	return getProperty(PRP_SchemaEntity_systemVersion, systemVersion, __LINE__);
}

inline int DskSchemaEntity::setSystemVersion(const Character systemVersion[])
{
	return setProperty(PRP_SchemaEntity_systemVersion, systemVersion, __LINE__);
}

inline int DskSchemaEntity::getModifiedBy(Character modifiedBy[]) const
{
	return getProperty(PRP_SchemaEntity__modifiedBy, modifiedBy, __LINE__);
}

inline int DskSchemaEntity::setModifiedBy(const Character modifiedBy[])
{
	return setProperty(PRP_SchemaEntity__modifiedBy, modifiedBy, __LINE__);
}

inline int DskSchemaEntity::setText(const Character text[]) const
{
	return setProperty(PRP_SchemaEntity_text, text, __LINE__);
}

inline int DskSchemaEntity::getText(Character text[]) const
{
	return getProperty(PRP_SchemaEntity_text, text, __LINE__);
}

inline int DskSchemaEntity::getTextSize(UInt32* pTextSize) const
{
	return getProperty(PRP_SchemaEntity_text, pTextSize, __LINE__);
}

inline int DskSchemaEntity::setDeprecated(Byte deprecatedFlags)
{
	return setProperty(PRP_SchemaEntity__deprecated, deprecatedFlags, __LINE__);
}

inline int DskSchemaEntity::getDeprecated(Byte* deprecatedFlags)
{
	int result = getProperty(PRP_SchemaEntity__deprecated, deprecatedFlags);
	return result;
}

inline int DskSchemaEntity::setDeprecatedDescription(const Character deprecated[])
{
	return setProperty(PRP_SchemaEntity__deprecatedDescription, deprecated, __LINE__);
}

#ifdef JADESTR_TYPEDEFS_DEFINED
inline int DskSchemaEntity::getDeprecatedDescription(String& deprecated) const
{
	return getJadeStringProperty(PRP_SchemaEntity__deprecatedDescription, &deprecated, __LINE__);
}
#endif

inline int DskSchemaEntity::setDeprecated_DeprecatedFlag(bool deprecated)
{
	Byte flags;
	int result = getDeprecated(&flags);
	CHECK_RESULT;

	if (deprecated)
		flags |= DeprecatedFlags::DEPRECATED;
	else
		flags &= ~DeprecatedFlags::DEPRECATED;

	return setDeprecated(flags);
}

inline int DskSchemaEntity::getDeprecated_DeprecatedFlag(bool* deprecated)
{
	Byte flags;
	const int result = getDeprecated(&flags);
	*deprecated = flags & DeprecatedFlags::DEPRECATED;
	return result;
}

//------------------------------------------------------------------------------
// DskConstantCategory:

inline int DskConstantCategory::getSchema(DskSchema& schema) const
{
	return getProperty(PRP_ConstantCategory_schema, schema, __LINE__);
}

inline int DskConstantCategory::setSchema(const DskSchema* pSchema) const
{
	return setProperty(PRP_ConstantCategory_schema, pSchema, __LINE__);
}

inline int DskConstantCategory::addConstant(DskGlobalConstant* pCon) const
{
	return pCon->setCategory(this);
}

inline int DskConstantCategory::constants(JomColl& coll) const
{
	return valuesFromProperty(PRP_ConstantCategory_consts, coll, __LINE__);
}

//------------------------------------------------------------------------------
// DskFeature:

inline int DskFeature::setSchemaType(const DskType* pSchemaType)
{
	return setProperty(PRP_Feature_schemaType, pSchemaType, __LINE__);
}

inline int DskFeature::getSchemaType(PDskType& pSchemaType) const
{
	return getProperty(PRP_Feature_schemaType, (PDskObject&) pSchemaType, __LINE__);
}

inline int DskFeature::getType(DskType& type) const
{
	return getProperty(PRP_Feature_type, type, __LINE__);
}

inline int DskFeature::getType(PDskType& pType) const
{
	return getProperty(PRP_Feature_type, (PDskObject&) pType, __LINE__);
}

inline int DskFeature::deleteSelf()
{
	return sendMsg(MTH_Feature_deleteSelf);
}

inline bool DskFeature::isDynamicProperty() const
{
	switch (actualClass(oid.classId))
	{
	case DSKJADEDYNAMICCOMPATTRIBUTE:
	case DSKJADEDYNAMICPRIMATTRIBUTE:
	case DSKJADEDYNAMICEXPLICITINVERSEREF:
	case DSKJADEDYNAMICIMPLICITINVERSEREF:
		return true;
	default:
		break;
	}
	return false;
}

//------------------------------------------------------------------------------
// DskProperty:

inline int DskProperty::setEmbedded(bool embedded)
{
	return setProperty(PRP_Property_embedded, embedded, __LINE__);
}

inline int DskProperty::getEmbedded(bool* pEmbedded) const
{
	return getProperty(PRP_Property_embedded, pEmbedded, __LINE__);
}

inline int DskProperty::setHasControlInstance(bool hasControlInstance) const
{
	return setProperty(PRP_Property_hasControlInstance, hasControlInstance, __LINE__);
}

inline int DskProperty::getHasControlInstance(bool* pHasControlInstance) const
{
	return getProperty(PRP_Property_hasControlInstance, pHasControlInstance, __LINE__);
}

inline int DskProperty::setRequired(bool required)
{
	return setProperty(PRP_Property_required, required, __LINE__);
}

inline int DskProperty::getRequired(bool* pRequired) const
{
	return getProperty(PRP_Property_required, pRequired, __LINE__);
}

inline int DskProperty::setNillable(bool nillable)
{
	return setProperty(PRP_Property__xmlNillable, nillable, __LINE__);
}

inline int DskProperty::getNillable(bool* pNillable) const
{
	return getProperty(PRP_Property__xmlNillable, pNillable, __LINE__);
}
inline int DskProperty::setSubId(SubID subId)
{
	return setUInt16Property(PRP_Property_subId, subId, __LINE__);
}

inline int DskProperty::getSubId(SubID* pSubId) const
{
	return getUInt16Property(PRP_Property_subId, pSubId, __LINE__);
}

inline int DskProperty::setOrdinal(FeatureNum ordinal)
{
	return setProperty(PRP_Property_ordinal, (UInt32) ordinal, __LINE__);
}

inline int DskProperty::getOrdinal(FeatureNum* pOrdinal) const
{
	return getUInt16Property(PRP_Property_ordinal, pOrdinal, __LINE__);
}

inline int DskProperty::setUsedInCondition(bool val) const
{
	return setProperty(PRP_Property_usedInCondition, val, __LINE__);
}

inline int DskProperty::getUsedInCondition(bool* pVal) const
{
	return getProperty(PRP_Property_usedInCondition, pVal, __LINE__);
}

inline int DskProperty::setVirtual(bool _virtual)
{
	return setProperty(PRP_Property_virtual, _virtual, __LINE__);
}

inline int DskProperty::getVirtual(bool* pVirtual) const
{
	return getProperty(PRP_Property_virtual, pVirtual, __LINE__);
}

inline int DskProperty::setIsHTMLProperty(bool html)
{
	return setProperty(PRP_Property_isHTMLProperty, html, __LINE__);
}

inline int DskProperty::getIsHTMLProperty(bool* pHTML) const
{
	return getProperty(PRP_Property_isHTMLProperty, pHTML, __LINE__);
}

inline int DskProperty::setKey(bool key)
{
	return setProperty(PRP_Property_key, key, __LINE__);
}

inline int DskProperty::getKey(bool* pKey) const
{
	return getProperty(PRP_Property_key, pKey, __LINE__);
}

inline int DskProperty::keyRefs(JomColl& coll) const
{
	int result = valuesFromProperty(PRP_Property__sysKeyRefs, coll, __LINE__);
	CHECK_RESULT;

	return valuesFromProperty(PRP_Property_keyRefs, coll, __LINE__);
}

inline int DskProperty::conditionRefs(JomColl& coll) const
{
	int result = valuesFromProperty(PRP_Property__sysConditionRefs, coll, __LINE__);
	CHECK_RESULT;

	return valuesFromProperty(PRP_Property_conditionRefs, coll, __LINE__);
}

inline int DskProperty::keyPathRefs(JomColl& coll) const
{
	int result = valuesFromProperty(PRP_Property__sysKeyPathRefs, coll, __LINE__);
	CHECK_RESULT;

	return valuesFromProperty(PRP_Property_keyPathRefs, coll, __LINE__);
}

inline int DskProperty::setMappingCount(Integer mappingCount) const
{
	return setProperty(PRP_Property_mappingCount, mappingCount, __LINE__);
}

inline int DskProperty::getMappingCount(Integer* pMappingCount) const
{
	return getProperty(PRP_Property_mappingCount, pMappingCount, __LINE__);
}

inline bool DskProperty::isAttribute() const
{
	// Can't count on being the right proxy class, so have to check the actual dsk class.
	bool answer;
	isKindOf(DSKATTRIBUTE, &answer);

	return answer;
}

inline bool DskProperty::isReference() const
{
	// Can't count on being the right proxy class, so have to check the actual dsk class.
	bool answer;
	isKindOf(DSKREFERENCE, &answer);

	return answer;
}

inline bool DskProperty::isPrimAttribute() const
{
	// Can't count on being the right proxy class, so have to check the actual dsk class.
	bool answer;
	isKindOf(DSKPRIMATTRIBUTE, &answer);

	return answer;
}

inline bool DskProperty::isCompAttribute() const
{
	// Can't count on being the right proxy class, so have to check the actual dsk class.
	bool answer;
	isKindOf(DSKCOMPATTRIBUTE, &answer);

	return answer;
}

inline bool DskProperty::isImplicitInverseRef() const
{
	// Can't count on being the right proxy class, so have to check the actual dsk class.
	bool answer;
	isKindOf(DSKIMPLICITINVERSEREF, &answer);

	return answer;
}

inline bool DskProperty::isExplicitInverseRef() const
{
	// Can't count on being the right proxy class, so have to check the actual dsk class.
	bool answer;
	isKindOf(DSKEXPLICITINVERSEREF, &answer);

	return answer;
}

//------------------------------------------------------------------------------
// DskAttribute:

inline int DskAttribute::setLength(PropertyLen length)
{
	return setProperty(PRP_Attribute_length, length, __LINE__);
}

inline int DskAttribute::getLength(PropertyLen* pLength) const
{
	return getProperty(PRP_Attribute_length, pLength, __LINE__);
}

//------------------------------------------------------------------------------
// DskPrimAttribute:

inline int DskPrimAttribute::setPrecision(Precision precision) const
{
	return setProperty(PRP_PrimAttribute_precision, (Character) precision, __LINE__);
}

inline int DskPrimAttribute::getPrecision(Precision* pPrecision) const
{
	Character c;
	int result = getCharProperty(PRP_PrimAttribute_precision, &c);
	*pPrecision = (Precision) c;
	return result;
}

inline int DskPrimAttribute::setScaleFactor(ScaleFactor scaleFactor) const
{
	return setProperty(PRP_PrimAttribute_scaleFactor, (Character) scaleFactor, __LINE__);
}

inline int DskPrimAttribute::getScaleFactor(ScaleFactor* pScaleFactor) const
{
	Character c;
	int result = getCharProperty(PRP_PrimAttribute_scaleFactor, &c);
	*pScaleFactor = (ScaleFactor) c;
	return result;
}

//------------------------------------------------------------------------------
// DskReference:

inline int DskReference::setConstraintChanged(bool constraintChanged) const
{
	return setProperty(PRP_Reference_constraintChanged, constraintChanged, __LINE__);
}

inline int DskReference::getConstraintChanged(bool* pConstraintChanged) const
{
	return getProperty(PRP_Reference_constraintChanged, pConstraintChanged, __LINE__);
}

inline int DskReference::setConstraint(const DskMethod* pMethod)
{
	return setProperty(PRP_Reference_constraint, pMethod, __LINE__);
}

inline int DskReference::getConstraint(DskMethod& method) const
{
	return getProperty(PRP_Reference_constraint, method, __LINE__);
}

inline int DskReference::getLength(PropertyLen* pLength) const
{
	bool embedded;
	int result = getEmbedded(&embedded);
	CHECK_RESULT;

	*pLength = embedded ? sizeof(ShortDskObjectId) : 0;

	return J_OK;
}

//------------------------------------------------------------------------------
// DskImplicitInverseRef:

inline int DskImplicitInverseRef::setMemberTypeInverse(bool memberTypeInverse)
{
	return setProperty(PRP_ImplicitInverseRef_memberTypeInverse, memberTypeInverse);
}

inline int DskImplicitInverseRef::getMemberTypeInverse(bool* pMemberTypeInverse) const
{
	return getProperty(PRP_ImplicitInverseRef_memberTypeInverse, pMemberTypeInverse);
}

//------------------------------------------------------------------------------
// DskExplicitInverseRef:

inline int DskExplicitInverseRef::setKind(ReferenceKind kind)
{
	return setProperty(PRP_ExplicitInverseRef_kind, (Character) kind, __LINE__);
}

inline int DskExplicitInverseRef::getKind(ReferenceKind* pKind) const
{
	Character c;
	int result = getCharProperty(PRP_ExplicitInverseRef_kind, &c);
	*pKind = (ReferenceKind) c;
	return result;
}

inline int DskExplicitInverseRef::setUpdateMode(InverseUpdateMode updateMode)
{
	return setProperty(PRP_ExplicitInverseRef_updateMode, (Character) updateMode, __LINE__);
}

inline int DskExplicitInverseRef::getUpdateMode(InverseUpdateMode* pUpdateMode) const
{
	Character c;
	int result = getCharProperty(PRP_ExplicitInverseRef_updateMode, &c, __LINE__);
	*pUpdateMode = (InverseUpdateMode) c;
	return result;
}

inline int DskExplicitInverseRef::setAllowTransToPersistRef(bool allowTransToPersistRef)
{
	return setProperty(PRP_ExplicitInverseRef__allowTransToPersistRef, allowTransToPersistRef);
}

inline int DskExplicitInverseRef::getAllowTransToPersistRef(bool* pAllowTransToPersistRef) const
{
	return getProperty(PRP_ExplicitInverseRef__allowTransToPersistRef, pAllowTransToPersistRef);
}

inline int DskExplicitInverseRef::setInverseNotRequired(bool inverseNotRequired)
{
	return setProperty(PRP_ExplicitInverseRef_inverseNotRequired, inverseNotRequired);
}

inline int DskExplicitInverseRef::getInverseNotRequired(bool* pInverseNotRequired) const
{
	return getProperty(PRP_ExplicitInverseRef_inverseNotRequired, pInverseNotRequired);
}

inline int DskExplicitInverseRef::inverses(JomColl& coll) const
{
	return valuesFromProperty(PRP_ExplicitInverseRef_inverses, coll, __LINE__);
}

//------------------------------------------------------------------------------
// DskScript:

inline int DskScript::setErrorCode(UInt32 errorCode) const
{
	return setProperty(PRP_Script_errorCode, errorCode, __LINE__);
}

inline int DskScript::getErrorCode(UInt32* pErrorCode) const
{
	return getProperty(PRP_Script_errorCode, pErrorCode, __LINE__);
}

inline int DskScript::setErrorLength(UInt32 errorLength) const
{
	return setProperty(PRP_Script_errorLength, errorLength, __LINE__);
}

inline int DskScript::getErrorLength(UInt32* pErrorLength) const
{
	return getProperty(PRP_Script_errorLength, pErrorLength, __LINE__);
}

inline int DskScript::setErrorPosition(UInt32 errorPosition) const
{
	return setProperty(PRP_Script_errorPosition, errorPosition, __LINE__);
}

inline int DskScript::getErrorPosition(UInt32* pErrorPosition) const
{
	return getProperty(PRP_Script_errorPosition, pErrorPosition, __LINE__);
}

inline int DskScript::setNotImplemented(bool notImpl)
{
	return setProperty(PRP_Script_notImplemented, notImpl, __LINE__);
}

inline int DskScript::getNotImplemented(bool* pNotImpl) const
{
	return getProperty(PRP_Script_notImplemented, pNotImpl, __LINE__);
}

inline int DskScript::setSource(const Character source[]) const
{
	return setProperty(PRP_Script_source, source, __LINE__);
}

inline int DskScript::getSource(Character source[]) const
{
	return getProperty(PRP_Script_source, source, __LINE__);
}

inline int DskScript::getStatus(UInt32* pStatus) const
{
	*pStatus = SCRIPT_NOT_COMPILED;
	return getProperty(PRP_Script_status, pStatus, __LINE__);
}

inline int DskScript::inlineTypeUsages(JomColl& coll) const
{
	return valuesFromProperty(PRP_Script_inlineTypeUsages, coll, __LINE__);
}

inline int DskScript::getSourceSize(UInt32* pLength) const
{
	return getProperty(PRP_Script_source, pLength, __LINE__);
}

inline int DskScript::clearInlineTypeUsages() const
{
	return sendMsg(MTH_Script__clearInlineTUsages);
}

inline int DskScript::save(void * pRootNode) const
{
	ShortDskParam root;
	paramSetPointer(root, pRootNode);
	return sendMsg(MTH_Script_save, root, nullptr, __LINE__);
}

//------------------------------------------------------------------------------
// DskConstant:

inline int DskConstant::setLength(PropertyLen length) const
{
	return setProperty(PRP_Constant_length, length, __LINE__);
}

inline int DskConstant::getLength(PropertyLen* pLength) const
{
	return getProperty(PRP_Constant_length, pLength, __LINE__);
}

inline int DskConstant::setPrecision(Precision precision) const
{
	return setProperty(PRP_Constant_precision, (Character) precision, __LINE__);
}

inline int DskConstant::getPrecision(Precision* pPrecision) const
{
	Character c;
	int result = getCharProperty(PRP_Constant_precision, &c, __LINE__);
	*pPrecision = (Precision) c;
	return result;
}

inline int DskConstant::setScaleFactor(ScaleFactor scaleFactor) const
{
	return setProperty(PRP_Constant_scaleFactor, (Character) scaleFactor, __LINE__);
}

inline int DskConstant::getScaleFactor(ScaleFactor* pScaleFactor) const
{
	Character c;
	int result = getCharProperty(PRP_Constant_scaleFactor, &c);
	*pScaleFactor = (ScaleFactor) c;
	return result;
}

inline int DskConstant::addConstantUsage(const DskConstant* pConstantUsage) const
{
	return sendMsg(MTH_Constant_addConstantUsage, pConstantUsage, __LINE__);
}

inline int DskConstant::constantRefs(JomColl& coll) const
{
	int result = valuesFromProperty(PRP_Constant__sysConstantRefs, coll, __LINE__);
	CHECK_RESULT;

	return valuesFromProperty(PRP_Constant_constantRefs, coll, __LINE__);
}

inline int DskConstant::constantUsages(JomColl& coll) const
{
	return valuesFromProperty(PRP_Constant_constantUsages, coll, __LINE__);
}

inline int DskConstant::importedConstantUsages(JomColl& coll) const
{
	return valuesFromProperty(PRP_Constant_importedConstantUsages, coll, __LINE__);
}

inline int DskConstant::clearConstantUsages() const
{
	return sendMsg(MTH_Constant_clearConstantUsages);
}

inline int DskConstant::getValueLength(PropertyLen* pLen) const
{
	// Get the length of the "value" slob
	return getProperty(PRP_Constant_value, pLen, __LINE__);  //Get length of slob
}

//------------------------------------------------------------------------------
// DskGlobalConstant:

inline int DskGlobalConstant::setCategory(const DskConstantCategory* pCategory) const
{
	return setProperty(PRP_GlobalConstant_category, pCategory, __LINE__);
}

inline int DskGlobalConstant::getCategory(DskConstantCategory& category) const
{
	return getProperty(PRP_GlobalConstant_category, category, __LINE__);
}

inline int DskGlobalConstant::setSchema(const DskSchema* pSchema) const
{
	return setProperty(PRP_GlobalConstant_schema, pSchema, __LINE__);
}

inline int DskGlobalConstant::getSchema(DskSchema& schema) const
{
	return getProperty(PRP_GlobalConstant_schema, schema, __LINE__);
}

//------------------------------------------------------------------------------
// DskRoutine:

inline int DskRoutine::setEntrypoint(const Character entrypoint[])
{
	return setProperty(PRP_Routine_entrypoint, entrypoint, __LINE__);
}

inline int DskRoutine::getEntrypoint(Character entrypoint[]) const
{
	return getProperty(PRP_Routine_entrypoint, entrypoint, __LINE__);
}

inline int DskRoutine::setExecutionLocation(ExecutionLocation executionLocation)
{
	return setProperty(PRP_Routine_executionLocation, (Character) executionLocation, __LINE__);
}

inline int DskRoutine::getExecutionLocation(ExecutionLocation* pExecutionLocation) const
{
	Character c;
	int result = getCharProperty(PRP_Routine_executionLocation, &c, __LINE__);
	*pExecutionLocation = (ExecutionLocation) c;
	return result;
}

inline int DskRoutine::setOptions_EncryptedSource(bool setting)
{
	Integer opts;
	int result = getProperty(PRP_Routine_options, &opts, __LINE__);
	CHECK_RESULT;

	if (setting)
		opts |= Options_EncryptedSource;
	else
		opts &= (~Options_EncryptedSource);

	return setProperty(PRP_Routine_options, opts, __LINE__);
}

inline int DskRoutine::getOptions_EncryptedSource(bool* pSetting) const
{
	Integer opts;
	int result = getProperty(PRP_Routine_options, &opts, __LINE__);
	*pSetting = (opts & Options_EncryptedSource) ? true : false;
	return result;
}

inline int DskRoutine::setOptions_HasPseudoMethodCallParam(bool setting)
{
	Integer opts = 0;
	int result = getProperty(PRP_Routine_options, &opts, __LINE__);
	CHECK_RESULT;

	if (setting)
		opts |= Options_HasPseudoMethodCallParam;
	else
		opts &= (~Options_HasPseudoMethodCallParam);

	return setProperty(PRP_Routine_options, opts, __LINE__);
}

inline int DskRoutine::getOptions_HasPseudoMethodCallParam(bool* pSetting) const
{
	Integer opts = 0;
	int result = getProperty(PRP_Routine_options, &opts, __LINE__);
	*pSetting = (opts & Options_HasPseudoMethodCallParam) ? true : false;
	return result;
}

inline int DskRoutine::setOptions_IsTypeMethod(bool setting)
{
	Integer opts;
	int result = getProperty(PRP_Routine_options, &opts, __LINE__);
	CHECK_RESULT;

	if (setting)
		opts |= Options_IsTypeMethod;
	else
		opts &= (~Options_IsTypeMethod);

	return setProperty(PRP_Routine_options, opts, __LINE__);
}

inline int DskRoutine::getOptions_IsTypeMethod(bool* pSetting) const
{
	Integer opts;
	int result = getProperty(PRP_Routine_options, &opts, __LINE__);
	*pSetting = (opts & Options_IsTypeMethod) ? true : false;
	return result;
}

inline int DskRoutine::setOptions_IsReceiverByReference(bool setting)
{
	Integer opts;
	int result = getProperty(PRP_Routine_options, &opts, __LINE__);
	CHECK_RESULT;

	if (setting)
		opts |= Options_IsReceiverByReference;
	else
		opts &= ~Options_IsReceiverByReference;

	return setProperty(PRP_Routine_options, opts, __LINE__);
}

inline int DskRoutine::getOptions_IsReceiverByReference(bool* pSetting) const
{
	Integer opts;
	const int result = getProperty(PRP_Routine_options, &opts, __LINE__);
	*pSetting = (opts & Options_IsReceiverByReference) ? true : false;
	return result;
}

inline int DskRoutine::setOptions_IsGenerated(bool setting)
{
	Integer opts;
	int result = getProperty(PRP_Routine_options, &opts, __LINE__);
	CHECK_RESULT;

	if (setting)
		opts |= Options_IsGenerated;
	else
		opts &= ~Options_IsGenerated;

	return setProperty(PRP_Routine_options, opts, __LINE__);
}

inline int DskRoutine::getOptions_IsGenerated(bool* pSetting) const
{
	Integer opts;
	const int result = getProperty(PRP_Routine_options, &opts, __LINE__);
	*pSetting = (opts & Options_IsGenerated) ? true : false;
	return result;
}

inline int DskRoutine::featureUsages(JomColl& coll) const
{
	return valuesFromProperty(PRP_Routine_featureUsages, coll, __LINE__);
}

inline int DskRoutine::keyUsages(JomColl& coll) const
{
	return valuesFromProperty(PRP_Routine_keyUsages, coll, __LINE__);
}

inline int DskRoutine::setLibrary(const DskLibrary* pLibrary)
{
	return setProperty(PRP_Routine_library, pLibrary, __LINE__);
}

inline int DskRoutine::getLibrary(DskLibrary& library) const
{
	return getProperty(PRP_Routine_library, library, __LINE__);
}

inline int DskRoutine::parameters(JomColl& coll) const
{
	return valuesFromProperty(PRP_Routine_parameters, coll, __LINE__);
}

inline int DskRoutine::setReturnType(const DskReturnType* pReturnType)
{
	return sendMsg(MTH_Routine__setReturnType, pReturnType, __LINE__);
}

inline int DskRoutine::getReturnType(DskReturnType& returnType) const
{
	return getProperty(PRP_Routine_returnType, returnType, __LINE__);
}

inline int DskRoutine::clearFeatureUsages() const
{
	return sendMsg(MTH_Routine_clearFeatureUsages);
}

inline int DskRoutine::clearKeyUsages() const
{
	return sendMsg(MTH_Routine_clearKeyUsages);
}

//------------------------------------------------------------------------------
// DskFunction:

inline int DskFunction::setSchema(const DskSchema* pSchema) const
{
	return setProperty(PRP_Function_schema, pSchema, __LINE__);
}

inline int DskFunction::getSchema(DskSchema& schema) const
{
	return getProperty(PRP_Function_schema, schema, __LINE__);
}

//------------------------------------------------------------------------------
// DskMethod:

inline int DskMethod::setMethodInvocation(MethodInvocation methodInvocation)
{
	return setProperty(PRP_Method_methodInvocation, (Character) methodInvocation, __LINE__);
}

inline int DskMethod::getMethodInvocation(MethodInvocation* pMethodInvocation) const
{
	Character c;
	int result = getCharProperty(PRP_Method_methodInvocation, &c, __LINE__);
	*pMethodInvocation = (MethodInvocation) c;
	return result;
}

inline int DskMethod::setLockReceiver(bool lockReceiver)
{
	return setProperty(PRP_Method_lockReceiver, lockReceiver, __LINE__);
}

inline int DskMethod::getLockReceiver(bool* pLockReceiver) const
{
	return getProperty(PRP_Method_lockReceiver, pLockReceiver, __LINE__);
}

inline int DskMethod::setUpdating(bool updating)
{
	return setProperty(PRP_Method_updating, updating, __LINE__);
}

inline int DskMethod::getUpdating(bool* pUpdating) const
{
	return getProperty(PRP_Method_updating, pUpdating, __LINE__);
}

inline int DskMethod::setFinal(bool final)
{
	return setProperty(PRP_Method_final, final, __LINE__);
}

inline int DskMethod::getFinal(bool* pFinal) const
{
	return getProperty(PRP_Method_final, pFinal, __LINE__);
}

inline int DskMethod::setSubschemaFinal(bool subschemaFinal)
{
	return setProperty(PRP_Method_subschemaFinal, subschemaFinal, __LINE__);
}

inline int DskMethod::getSubschemaFinal(bool* pSubschemaFinal) const
{
	return getProperty(PRP_Method_subschemaFinal, pSubschemaFinal, __LINE__);
}

inline int DskMethod::setSubschemaCopyFinal(bool subschemaCopyFinal)
{
	return setProperty(PRP_Method_subschemaCopyFinal, subschemaCopyFinal, __LINE__);
}

inline int DskMethod::getSubschemaCopyFinal(bool* pSubschemaCopyFinal) const
{
	return getProperty(PRP_Method_subschemaCopyFinal, pSubschemaCopyFinal, __LINE__);
}

inline int DskMethod::setCondition(bool condition)
{
	return setProperty(PRP_Method_condition, condition, __LINE__);
}

inline int DskMethod::getCondition(bool* pCondition) const
{
	return getProperty(PRP_Method_condition, pCondition, __LINE__);
}

inline int DskMethod::setConditionSafe(bool conditionSafe)
{
	return setProperty(PRP_Method_conditionSafe, conditionSafe, __LINE__);
}

inline int DskMethod::getConditionSafe(bool* pConditionSafe) const
{
	return getProperty(PRP_Method_conditionSafe, pConditionSafe, __LINE__);
}

inline int DskMethod::setPartitionMethod(bool partitionMethod)
{
	return setProperty(PRP_Method_partitionMethod, partitionMethod, __LINE__);
}

inline int DskMethod::getPartitionMethod(bool* pPartitionMethod) const
{
	return getProperty(PRP_Method_partitionMethod, pPartitionMethod, __LINE__);
}

inline int DskMethod::setUnitTestFlags(UnitTestFlags unitTestFlags)
{
	return setProperty(PRP_Method_unitTestFlags, unitTestFlags, __LINE__);
}

inline int DskMethod::getUnitTestFlags(UnitTestFlags* pUnitTestFlags) const
{
	UInt32 unitTestFlags;
	int result = getProperty(PRP_Method_unitTestFlags, &unitTestFlags, __LINE__);
	*pUnitTestFlags = (UnitTestFlags) unitTestFlags;
	return result;
}

inline int DskMethod::setControlMethod(const DskMethod* pControlMethod) const
{
	return setProperty(PRP_Method_controlMethod, pControlMethod, __LINE__);
}

inline int DskMethod::getControlMethod(DskMethod& controlMethod) const
{
	return getProperty(PRP_Method_controlMethod, controlMethod, __LINE__);
}

inline int DskMethod::setDelta(const DskDeltaInfo* pDelta) const
{
	return setProperty(PRP_Method_delta, pDelta, __LINE__);
}

inline int DskMethod::getDelta(DskDeltaInfo& delta) const
{
	return getProperty(PRP_Method_delta, delta, __LINE__);
}

inline int DskMethod::getOriginalMethod(DskMethod& originalMethod) const
{
	return getProperty(PRP_Method_originalMethod, originalMethod, __LINE__);
}

inline int DskMethod::setSuperMethod(const DskMethod* pSuperMethod)
{
	return setProperty(PRP_Method_superMethod, pSuperMethod, __LINE__);
}

inline int DskMethod::getSuperMethod(DskMethod& superMethod) const
{
	return getProperty(PRP_Method_superMethod, superMethod, __LINE__);
}

inline int DskMethod::isReimplementation(bool* pFlag) const
{
	DskMethod superMethod;
	int result = getProperty(PRP_Method_superMethod, superMethod, __LINE__);
	CHECK_RESULT;

	*pFlag = !superMethod.isNull();
	return J_OK;
}

inline int DskMethod::deleteSelf()
{
	return sendMsg(MTH_Method_deleteSelf);
}

inline int DskMethod::isExternal(bool* pExternal) const
{
	return isKindOf(DSKEXTERNALMETHOD, pExternal);
}

inline int DskMethod::addInterfaceImplements(DskMethod* pInterfaceMethod) const
{
	return sendMsg(TEXT("_addInterfaceImplements"), pInterfaceMethod, __LINE__);
}

inline int DskMethod::delInterfaceImplements(DskMethod* pInterfaceMethod) const
{
	return sendMsg(TEXT("_delInterfaceImplements"), pInterfaceMethod, __LINE__);
}

//------------------------------------------------------------------------------
// DskType:

inline int DskType::setPersistentAllowed(bool persistentAllowed)
{
	return setProperty(PRP_Type_persistentAllowed, persistentAllowed, __LINE__);
}

inline int DskType::getPersistentAllowed(bool* pPersistentAllowed, LineNumber line) const
{
	return getProperty(PRP_Type_persistentAllowed, pPersistentAllowed, line);
}

inline int DskType::setTransientAllowed(bool transientAllowed)
{
	return setProperty(PRP_Type_transientAllowed, transientAllowed, __LINE__);
}

inline int DskType::getTransientAllowed(bool* pTransientAllowed, LineNumber line) const
{
	return getProperty(PRP_Type_transientAllowed, pTransientAllowed, line);
}

inline int DskType::setSharedTransientAllowed(bool sharedTransientAllowed)
{
	return setProperty(PRP_Type_sharedTransientAllowed, sharedTransientAllowed, __LINE__);
}

inline int DskType::getSharedTransientAllowed(bool* pSharedTransientAllowed, LineNumber line) const
{
	return getProperty(PRP_Type_sharedTransientAllowed, pSharedTransientAllowed, line);
}

inline int DskType::setSubclassPersistentAllowed(bool subclassPersistentAllowed)
{
	return setProperty(PRP_Type_subclassPersistentAllowed, subclassPersistentAllowed, __LINE__);
}

inline int DskType::getSubclassPersistentAllowed(bool* pSubclassPersistentAllowed, LineNumber line) const
{
	return getProperty(PRP_Type_subclassPersistentAllowed, pSubclassPersistentAllowed, line);
}

inline int DskType::setSubclassTransientAllowed(bool subclassTransientAllowed)
{
	return setProperty(PRP_Type_subclassTransientAllowed, subclassTransientAllowed, __LINE__);
}

inline int DskType::getSubclassTransientAllowed(bool* pSubclassTransientAllowed, LineNumber line) const
{
	return getProperty(PRP_Type_subclassTransientAllowed, pSubclassTransientAllowed, line);
}

inline int DskType::setSubclassSharedTransientAllowed(bool subclassSharedTransientAllowed)
{
	return setProperty(PRP_Type_subclassSharedTransientAllowed, subclassSharedTransientAllowed, __LINE__);
}

inline int DskType::getSubclassSharedTransientAllowed(bool* pSubclassSharedTransientAllowed, LineNumber line) const
{
	return getProperty(PRP_Type_subclassSharedTransientAllowed, pSubclassSharedTransientAllowed, line);
}

inline int DskType::setFinal(bool final)
{
	return setProperty(PRP_Type_final, final, __LINE__);
}

inline int DskType::getFinal(bool* pFinal, LineNumber line) const
{
	return getProperty(PRP_Type_final, pFinal, line);
}

inline int DskType::setSubschemaFinal(bool subschemaFinal)
{
	return setProperty(PRP_Type_subschemaFinal, subschemaFinal, __LINE__);
}

inline int DskType::getSubschemaFinal(bool* pSubschemaFinal, LineNumber line) const
{
	return getProperty(PRP_Type_subschemaFinal, pSubschemaFinal, line);
}

//------------------------------------------------------------------------------
// DskClass:

inline int DskClass::setNeedsReorg(bool needsReorg) const
{
	return setProperty(PRP_Class__needsReorg, needsReorg);
}

inline int DskClass::getNeedsReorg(bool& needsReorg) const
{
	return getProperty(PRP_Class__needsReorg, &needsReorg);
}

inline int DskClass::setHighestSubId(SubID highestSubId) const
{
	return setUInt16Property(PRP_Class_highestSubId, highestSubId, __LINE__);
}

inline int DskClass::getHighestSubId(SubID* pHighestSubId) const
{
	return getUInt16Property(PRP_Class_highestSubId, pHighestSubId, __LINE__);
}

inline int DskClass::setHighestOrdinal(FeatureNum highestOrdinal) const
{
	return setProperty(PRP_Class_highestOrdinal, (Int32)highestOrdinal, __LINE__);
}

inline int DskClass::getHighestOrdinal(FeatureNum* pHighestOrdinal) const
{
	return getUInt16Property(PRP_Class_highestOrdinal, pHighestOrdinal, __LINE__);
}

inline int DskClass::setReplicationAllowed(ReplicationType replicationAllowed)
{
	return setProperty(PRP_Class_replicationAllowed, (Character) replicationAllowed, __LINE__);
}

inline int DskClass::getReplicationAllowed(ReplicationType* pReplicationAllowed) const
{
	Character c;
	int result = getCharProperty(PRP_Class_replicationAllowed, &c, __LINE__);
	*pReplicationAllowed= (ReplicationType) c;
	return result;
}

inline int DskClass::setReplicationControl(ReplicationType replicationControl)
{
	return setProperty(PRP_Class_replicationControl, (Character) replicationControl, __LINE__);
}

inline int DskClass::getReplicationControl(ReplicationType* pReplicationControl) const
{
	Character c;
	int result = getCharProperty(PRP_Class_replicationControl, &c, __LINE__);
	*pReplicationControl= (ReplicationType) c;
	return result;
}

inline int DskClass::setReplicationDefault(ReplicationType replicationDefault)
{
	return setProperty(PRP_Class_replicationDefault, (Character) replicationDefault, __LINE__);
}

inline int DskClass::getReplicationDefault(ReplicationType* pReplicationDefault) const
{
	Character c;
	int result = getCharProperty(PRP_Class_replicationDefault, &c, __LINE__);
	*pReplicationDefault= (ReplicationType) c;
	return result;
}

inline int DskClass::setTransient(bool transient)
{
	return setProperty(PRP_Class_transient, transient, __LINE__);
}

inline int DskClass::getTransient(bool* pTransient, LineNumber line) const
{
	return getProperty(PRP_Class_transient, pTransient, line);
}

inline int DskClass::classMapRefs(JomColl& coll) const
{
	return valuesFromProperty(PRP_Class_classMapRefs, coll, __LINE__);
}

inline int DskClass::localProperties(JomColl& coll) const
{
	return valuesFromProperty(PRP_Class_properties, coll, __LINE__);
}

inline int DskClass::localClusters(JomColl& coll) const
{
	return valuesFromProperty(PRP_Class_dynamicPropertyClusters, coll, __LINE__);
}

inline int DskClass::localPropertyOrder(JomColl& coll) const
{
	return valuesFromProperty(PRP_Class_propertyOrder, coll, __LINE__);
}

inline int DskClass::localSubclasses(JomColl& coll) const
{
	return valuesFromProperty(PRP_Class_subclasses, coll, __LINE__);
}

inline int DskClass::addSuperclass(const DskClass* pSuperclass)
{
	return sendMsg(MTH_Class_addSuperclass, pSuperclass, __LINE__);
}

inline int DskClass::delSuperclass(const DskClass* pSuperclass) const
{
	return sendMsg(MTH_Class_delSuperclass, pSuperclass, __LINE__);
}

inline int DskClass::getConstructor(DskMethod& constructor) const
{
	return getMethod(CONSTRUCTOR_NAME, constructor);
}

inline int DskClass::getDestructor(DskMethod& destructor) const
{
	return getMethod(DESTRUCTOR_NAME, destructor);
}

inline int DskClass::needsReorg(bool* pNeedsReorg) const
{
	return getProperty(PRP_Class__needsReorg, pNeedsReorg, __LINE__);
}

inline int DskClass::getInstanceVolatility(ObjectVolatility* pVolatility) const
{
	return getProperty(PRP_Class_instanceVolatility, (Integer*) pVolatility, __LINE__);
}

inline int DskClass::setInstanceVolatility(ObjectVolatility volatility)
{
	return setProperty(PRP_Class_instanceVolatility, static_cast<Integer>(volatility), __LINE__);
}

inline int DskClass::getXMLInnerClass(bool* pVal) const
{
	return getProperty(PRP_Class__xmlInnerClass, pVal, __LINE__);
}

inline int DskClass::setXMLInnerClass(bool val) const
{
	return setProperty(PRP_Class__xmlInnerClass, val, __LINE__);
}

inline bool DskClass::isUserClass() const
{
	return actualClass(oid.classId) == DSKJADEUSERCLASS || actualClass(oid.classId) == DSKJADEUSERCOLLCLASS;
}

//------------------------------------------------------------------------------
// DskCollClass:

inline int DskCollClass::setDuplicatesAllowed(bool duplicatesAllowed)
{
	return setProperty(PRP_CollClass_duplicatesAllowed, duplicatesAllowed, __LINE__);
}

inline int DskCollClass::getDuplicatesAllowed(bool* pDuplicatesAllowed) const
{
	return getProperty(PRP_CollClass_duplicatesAllowed, pDuplicatesAllowed, __LINE__);
}

inline int DskCollClass::setScaleEntries(bool scaleEntries) const
{
	return setProperty(PRP_CollClass__scaleEntries, scaleEntries, __LINE__);
}

inline int DskCollClass::getScaleEntries(bool* pScaleEntries) const
{
	return getProperty(PRP_CollClass__scaleEntries, pScaleEntries, __LINE__);
}

inline int DskCollClass::setMaxBlockSize(UInt32 maxBlockSize)
{
	return setProperty(PRP_CollClass_maxBlockSize, maxBlockSize, __LINE__);
}

inline int DskCollClass::getMaxBlockSize(UInt32* pMaxBlockSize) const
{
	return getProperty(PRP_CollClass_maxBlockSize, pMaxBlockSize, __LINE__);
}

inline int DskCollClass::setMaxLogicalBlockSize(UInt32 maxLogicalBlockSize)
{
	return setProperty(PRP_CollClass_maxLogicalBlockSize, (UInt32) maxLogicalBlockSize, __LINE__);
}

inline int DskCollClass::getMaxLogicalBlockSize(UInt32* pMaxLogicalBlockSize) const
{
	return getProperty(PRP_CollClass_maxLogicalBlockSize, pMaxLogicalBlockSize, __LINE__);
}

inline int DskCollClass::setActualBlockEntries(UInt32 actualBlockEntries)
{
	return setProperty(PRP_CollClass_actualBlockEntries, actualBlockEntries, __LINE__);
}

inline int DskCollClass::getActualBlockEntries(UInt32* pActualBlockEntries) const
{
	return getProperty(PRP_CollClass_actualBlockEntries, pActualBlockEntries, __LINE__);
}

inline int DskCollClass::calculateActualBlockEntries(UInt32* pActualBlockEntries) const
{
	*pActualBlockEntries = 0;

	ShortDskParam retrnParam;
	paramSetInteger(retrnParam, 0, USAGE_OUTPUT);

	int result = sendMsg(MTH_CollClass__calculateActualBlockEntries, nullptr, retrnParam, __LINE__);
	if (result == J_OK)
		result = paramGetUnsignedInteger(retrnParam, *pActualBlockEntries);

	return result;
}

inline int DskCollClass::calculateActualBlockEntriesEx(UInt32 blockEntries, UInt32 expectedPop, UInt32 loadFactor, UInt32 fullEntryBytes, UInt32* pActualBlockEntries) const
{
	*pActualBlockEntries = 0;

	ShortDskParam dskparam0, dskparam1, dskparam2, dskparam3;
	paramSetInteger(dskparam0, blockEntries, USAGE_CONSTANT);
	paramSetInteger(dskparam1, expectedPop, USAGE_CONSTANT);
	paramSetInteger(dskparam2, loadFactor, USAGE_OUTPUT);
	paramSetInteger(dskparam3, fullEntryBytes, USAGE_OUTPUT);

	DskParam dskParamList;
	paramSetParamList(dskParamList, dskparam0, dskparam1, dskparam2, dskparam3);

	ShortDskParam dskparamRes;
	paramSetInteger(dskparamRes, 0, USAGE_OUTPUT);

	int result = sendMsg(TEXT("calculateActualBlockEntriesEx")/*CFM_CollClass_calculateActualBlockEntriesEx*/, &dskParamList, dskparamRes, __LINE__);
	if (result == J_OK)
		result = paramGetUnsignedInteger(dskparamRes, *pActualBlockEntries);

	return result;
}

inline int DskCollClass::calculateSingleDiskBlockEntries(UInt32 actualBlockEntries, UInt32* pSingleDiskBlockEntries) const
{
	*pSingleDiskBlockEntries = 0;

	ShortDskParam dskparam0, dskparam1, dskparam2, dskparam3;
	paramSetInteger(dskparam0, actualBlockEntries, USAGE_CONSTANT);
	paramSetInteger(dskparam1, 0, USAGE_CONSTANT);
	paramSetInteger(dskparam2, 0, USAGE_OUTPUT);
	paramSetInteger(dskparam3, 0, USAGE_OUTPUT);

	DskParam dskParamList;
	paramSetParamList(dskParamList, dskparam0, dskparam1, dskparam2, dskparam3);

	int result = sendMsg(TEXT("calculateSingleDiskBlkSizesEx")/*CFM_CollClass_calculateSingleDiskBlkSizesEx*/, &dskParamList, nullptr, __LINE__);
	if (result == J_OK)
		result = paramGetUnsignedInteger(dskparam2, *pSingleDiskBlockEntries);

	return result;
}

inline int DskCollClass::setBlockSize(UInt32 blockSize)
{
	return setProperty(PRP_CollClass_blockSize, blockSize, __LINE__);
}

inline int DskCollClass::getBlockSize(UInt32* pBlockSize) const
{
	return getProperty(PRP_CollClass_blockSize, pBlockSize, __LINE__);
}

inline int DskCollClass::setExpectedPopulation(UInt32 expectedPopulation)
{
	return setProperty(PRP_CollClass_expectedPopulation, expectedPopulation, __LINE__);
}

inline int DskCollClass::getExpectedPopulation(UInt32* pExpectedPopulation) const
{
	return getProperty(PRP_CollClass_expectedPopulation, pExpectedPopulation, __LINE__);
}

inline int DskCollClass::setLoadFactor(UInt32 loadFactor)
{
	return setProperty(PRP_CollClass_loadFactor, loadFactor, __LINE__);
}

inline int DskCollClass::getLoadFactor(UInt32* pLoadFactor) const
{
	return getProperty(PRP_CollClass_loadFactor, pLoadFactor, __LINE__);
}

inline int DskCollClass::setMemberTypePrecision(Precision precision)
{
	return setProperty(PRP_CollClass_memberTypePrecision, (Character) precision, __LINE__);
}

inline int DskCollClass::getMemberTypePrecision(Precision* pPrecision) const
{
	Character c;
	int result = getCharProperty(PRP_CollClass_memberTypePrecision, &c);
	*pPrecision= (Precision) c;
	return result;
}

inline int DskCollClass::setMemberTypeSFactor(ScaleFactor scaleFactor)
{
	return setProperty(PRP_CollClass_memberTypeSFactor, (Character) scaleFactor, __LINE__);
}

inline int DskCollClass::getMemberTypeSFactor(ScaleFactor* pScaleFactor) const
{
	Character c;
	int result = getCharProperty(PRP_CollClass_memberTypeSFactor, &c);
	*pScaleFactor = (ScaleFactor) c;
	return result;
}

inline int DskCollClass::setMemberTypeSize(PropertyLen memberTypeSize)
{
	return setProperty(PRP_CollClass_memberTypeSize, memberTypeSize, __LINE__);
}

inline int DskCollClass::getMemberTypeSize(PropertyLen* pMemberTypeSize) const
{
	return getProperty(PRP_CollClass_memberTypeSize, pMemberTypeSize, __LINE__);
}

inline int DskCollClass::localKeys(JomColl& coll) const
{
	return valuesFromProperty(PRP_CollClass_keys, coll, __LINE__);
}

inline int DskCollClass::setMemberTypeWSDLName(const Character str[])
{
	return setProperty(PRP_CollClass__memberTypeWSDLName, str, __LINE__);
}

inline int DskCollClass::getMemberTypeWSDLName(Character str[]) const
{
	return getProperty(PRP_CollClass__memberTypeWSDLName, str, __LINE__);
}

inline int DskCollClass::getMemberTypeWSDLNameLength(UInt32& len) const
{
	return getProperty(PRP_CollClass__memberTypeWSDLName, &len, __LINE__);
}

//------------------------------------------------------------------------------
// DskScriptElement:

inline int DskScriptElement::setTextLength(ObjLen textLength) const
{
	return setProperty(PRP_ScriptElement_textLength, textLength, __LINE__);
}

inline int DskScriptElement::getTextLength(ObjLen* pTextLength) const
{
	return getProperty(PRP_ScriptElement_textLength, pTextLength, __LINE__);
}

inline int DskScriptElement::setTextPosition(Int32 textPosition) const
{
	return setProperty(PRP_ScriptElement_textPosition, textPosition, __LINE__);
}

inline int DskScriptElement::getTextPosition(Int32* pTextPosition) const
{
	return getProperty(PRP_ScriptElement_textPosition, pTextPosition, __LINE__);
}

inline int DskScriptElement::setSchemaScript(const DskScript* pScript) const
{
	return setProperty(PRP_ScriptElement_schemaScript, pScript, __LINE__);
}

inline int DskScriptElement::getSchemaScript(DskScript& script) const
{
	return getProperty(PRP_ScriptElement_schemaScript, script, __LINE__);
}

//------------------------------------------------------------------------------
// DskTypeUsage:

inline int DskTypeUsage::setName(const Character name[])
{
	return setProperty(PRP_TypeUsage_name, name, __LINE__);
}

inline int DskTypeUsage::getName(Character name[]) const
{
	return getProperty(PRP_TypeUsage_name, name, __LINE__);
}

inline int DskTypeUsage::getType(DskType& type) const
{
	return getProperty(PRP_TypeUsage_type, type, __LINE__);
}

inline int DskTypeUsage::getType(PDskType& pType) const
{
	return getProperty(PRP_TypeUsage_type, (PDskObject&) pType, __LINE__);
}

inline int DskTypeUsage::setType(const DskType* pType)
{
	DskType rootType;
	int result = pType->getRootType(rootType);
	CHECK_RESULT;

	return sendMsg(MTH_TypeUsage_setType, rootType, __LINE__);
}

inline int DskTypeUsage::deleteSelf() const
{
	return sendMsg(MTH_TypeUsage_deleteSelf);
}

//------------------------------------------------------------------------------
// DskReturnType:

inline int DskReturnType::setLength(PropertyLen length) const
{
	return setProperty(PRP_ReturnType_length, length, __LINE__);
}

inline int DskReturnType::getLength(PropertyLen* pLength) const
{
	return getProperty(PRP_ReturnType_length, pLength, __LINE__);
}

//------------------------------------------------------------------------------
// DskDskApplication:

inline int DskApplication::setApplicationType(JomApplicationType applicationType) const
{
	return setProperty(PRP_Application_applicationType, (Character) applicationType, __LINE__);
}

inline int DskApplication::getApplicationType(JomApplicationType& applicationType) const
{
	Character character;
	int result = getCharProperty(PRP_Application_applicationType, &character);
	CHECK_RESULT;

	applicationType = (JomApplicationType) character;
	
	return J_OK;
}

inline int DskApplication::setName(const Character name[]) const
{
	return setProperty(PRP_Application_name, name, __LINE__);
}

inline int DskApplication::getName(Character name[]) const
{
	return getProperty(PRP_Application_name, name, __LINE__);
}

inline int DskApplication::setSchema(const DskSchema* pSchema) const
{
	return setProperty(PRP_Application_schema, pSchema, __LINE__);
}

inline int DskApplication::getSchema(DskSchema& schema) const
{
	return getProperty(PRP_Application_schema, schema, __LINE__);
}

//------------------------------------------------------------------------------
// DskSchema:

inline int DskSchema::getModifiedTimeStamp(DskTimeStamp* pModifiedTimeStamp) const
{
	return getProperty(PRP_Schema__modifiedTimestamp, pModifiedTimeStamp, __LINE__);
}

inline int DskSchema::setModifiedTimeStamp(DskTimeStamp* pModifiedTimeStamp)
{
	return setProperty(PRP_Schema__modifiedTimestamp, pModifiedTimeStamp, __LINE__);
}

inline int DskSchema::getSchemaPatchVersion(Int32* pPatchVersion) const
{
	return getProperty(PRP_Schema_patchVersion, pPatchVersion, __LINE__);
}

inline int DskSchema::setSchemaPatchVersion(Int32 patchVersion)
{
	return setProperty(PRP_Schema_patchVersion, patchVersion, __LINE__);
}

inline int DskSchema::setPatchVersion(Int32 patchVersion)
{
	return setProperty(PRP_Schema__patchVersion, patchVersion, __LINE__);
}

inline int DskSchema::getPatchVersion(Int32* pPatchVersion) const
{
	return getProperty(PRP_Schema__patchVersion, pPatchVersion, __LINE__);
}

inline int DskSchema::getSystemVersion(Character systemVersion[]) const
{
	return getProperty(PRP_Schema__systemVersion, systemVersion, __LINE__);
}

inline int DskSchema::setSystemVersion(const Character systemVersion[])
{
	return setProperty(PRP_Schema__systemVersion, systemVersion, __LINE__);
}

inline int DskSchema::getModifiedBy(Character modifiedBy[]) const
{
	return getProperty(PRP_Schema__modifiedBy, modifiedBy, __LINE__);
}

inline int DskSchema::setModifiedBy(const Character modifiedBy[])
{
	return setProperty(PRP_Schema__modifiedBy, modifiedBy, __LINE__);
}

inline int DskSchema::setUserProfile(const DskUserProfile*)
{
	// No such property
	return J_OK;
}

inline int DskSchema::setFormsManagement(BYTE style) const
{
	return setProperty(PRP_Schema_formsManagement, style, __LINE__);
}

inline int DskSchema::getFormsManagement(BYTE* pStyle) const
{
	return getProperty(PRP_Schema_formsManagement, pStyle, __LINE__);
}

inline int DskSchema::setJomVersion(const Character jomVersion[]) const
{
	return setProperty(PRP_Schema_jomVersion, jomVersion, __LINE__);
}

inline int DskSchema::getJomVersion(Character jomVersion[]) const
{
	return getProperty(PRP_Schema_jomVersion, jomVersion, __LINE__);
}

inline int DskSchema::setNumber(SchemaNumber schemaNo) const
{
	return setProperty(PRP_Schema_number, schemaNo, __LINE__);
}

inline int DskSchema::getNumber(SchemaNumber* pSchemaNo, LineNumber line) const
{
	return getProperty(PRP_Schema_number, pSchemaNo, line == 0 ? __LINE__ : line);
}

inline int DskSchema::setName(const Character name[]) const
{
	return setProperty(PRP_Schema_name, name, __LINE__);
}

inline int DskSchema::getName(Character name[]) const
{
	return getProperty(PRP_Schema_name, name, __LINE__);
}

inline int DskSchema::setNextClassNumber(ClassNumber nextClassNumber) const
{
	return setProperty(PRP_Schema_nextClassNumber, nextClassNumber, __LINE__);
}

inline int DskSchema::getNextClassNumber(ClassNumber* pNextClassNumber) const
{
	return getProperty(PRP_Schema_nextClassNumber, pNextClassNumber, __LINE__);
}

inline int DskSchema::setPatchVersioningEnabled(bool val) const
{
	return setProperty(PRP_Schema__patchVersioningEnabled, val, __LINE__);
}

inline int DskSchema::getPatchVersioningEnabled(bool* pVal) const
{
	return getProperty(PRP_Schema__patchVersioningEnabled, pVal, __LINE__);
}

inline int DskSchema::setPermanent(bool permanent) const
{
	return setProperty(PRP_Schema__permanent, permanent, __LINE__);
}

inline int DskSchema::getPermanent(bool* pPermanent) const
{
	return getProperty(PRP_Schema__permanent, pPermanent, __LINE__);
}

inline int DskSchema::setStatus(SchemaStatus status) const
{
	return setProperty(PRP_Schema_status, status, __LINE__);
}

inline int DskSchema::getStatus(SchemaStatus* pStatus) const
{
	int schemaStatus;
	int result = getProperty(PRP_Schema_status, &schemaStatus, __LINE__);
	CHECK_RESULT;

	*pStatus = (SchemaStatus) schemaStatus;

	return J_OK;
}

inline int DskSchema::setText(const Character text[]) const
{
	return setProperty(PRP_Schema_text, text, __LINE__);
}

inline int DskSchema::getText(Character text[]) const
{
	return getProperty(PRP_Schema_text, text, __LINE__);
}

inline int DskSchema::setAppClass(const DskClass* pAppClass) const
{
	return setProperty(PRP_Schema__appClass, pAppClass, __LINE__);
}

inline int DskSchema::getAppClass(DskClass& appClass) const
{
	return getProperty(PRP_Schema__appClass, appClass, __LINE__);
}

inline int DskSchema::setGlobalClass(const DskClass* pGlobalClass) const
{
	return setProperty(PRP_Schema__globalClass, pGlobalClass, __LINE__);
}

inline int DskSchema::getGlobalClass(DskClass& globalClass) const
{
	return getProperty(PRP_Schema__globalClass, globalClass, __LINE__);
}

inline int DskSchema::setWebClass(const DskClass* pWebClass) const
{
	return setProperty(PRP_Schema__webClass, pWebClass, __LINE__);
}

inline int DskSchema::getWebClass(DskClass& webClass) const
{
	return getProperty(PRP_Schema__webClass, webClass, __LINE__);
}

inline int DskSchema::addClass(const DskClass* pClass)
{
	return sendMsg(MTH_Schema_addClass, pClass, __LINE__);
}

inline int DskSchema::addClassWithoutNotify(const DskClass* pClass) const
{
	return sendMsg(TEXT("_addClassWithoutNotify"), pClass, __LINE__);
}

inline int DskSchema::delClass(const DskClass* pClass) const
{
	return sendMsg(MTH_Schema_delClass, pClass, __LINE__);
}

inline int DskSchema::classes(JomColl& coll) const
{
	return valuesFromProperty(PRP_Schema_classes, coll, __LINE__);
}

inline int DskSchema::constants(JomColl& coll) const
{
	return valuesFromProperty(PRP_Schema_consts, coll, __LINE__);
}

inline int DskSchema::constantCategories(JomColl& coll) const
{
	return valuesFromProperty(PRP_Schema_constantCategories, coll, __LINE__);
}

inline int DskSchema::databases(JomColl& coll) const
{
	return valuesFromProperty(PRP_Schema_databases, coll, __LINE__);
}

inline int DskSchema::dbServers(JomColl& coll) const
{
	return valuesFromProperty(PRP_Schema_dbServers, coll, __LINE__);
}

inline int DskSchema::libraries(JomColl& coll) const
{
	return valuesFromProperty(PRP_Schema_libraries, coll, __LINE__);
}

inline int DskSchema::functions(JomColl& coll) const
{
	return valuesFromProperty(PRP_Schema_functions, coll, __LINE__);
}

inline int DskSchema::locales(JomColl& coll) const
{
	return valuesFromProperty(PRP_Schema_locales, coll, __LINE__);
}

inline int DskSchema::primitives(JomColl& coll) const
{
	return valuesFromProperty(PRP_Schema_primitives, coll, __LINE__);
}

inline int DskSchema::pseudoTypes(JomColl& coll) const
{
	return valuesFromProperty(PRP_Schema_pseudoTypes, coll, __LINE__);
}

inline int DskSchema::addSubschema(const DskSchema* pSubschema)
{
	return sendMsg(MTH_Schema__addSubschema, pSubschema, __LINE__);
}

inline int DskSchema::delSubschema(const DskSchema* pSubschema) const
{
	return sendMsg(MTH_Schema_delSubschema, pSubschema, __LINE__);
}

inline int DskSchema::setSuperschema(const DskSchema* pSuperschema)
{
	return setProperty(PRP_Schema_superschema, pSuperschema, __LINE__);
}

inline int DskSchema::getSuperschema(DskSchema& superschema) const
{
	return getProperty(PRP_Schema_superschema, superschema, __LINE__);
}

inline int DskSchema::getTextSize(UInt32* pTextSize) const
{
	return getProperty(PRP_Schema_text, pTextSize, __LINE__);
}

inline int DskSchema::deleteSelf() const
{
	return sendMsg(MTH_Schema_deleteSelf);
}

inline int DskSchema::exposedLists(JomColl& coll) const
{
	return valuesFromProperty(PRP_Schema__exposedLists, coll, __LINE__);
}

inline int DskSchema::exportedPackages(JomColl& coll) const
{
	return valuesFromProperty(PRP_Schema_exportedPackages, coll, __LINE__);
}

inline int DskSchema::importedPackages(JomColl& coll) const
{
	return valuesFromProperty(PRP_Schema_importedPackages, coll, __LINE__);
}

inline int DskSchema::interfaces(JomColl& coll) const
{
	return valuesFromProperty(PRP_Schema_interfaces, coll, __LINE__);
}

inline int DskSchema::setRootSchema(const DskSchema* pRootSchema) const
{
	return setProperty(PRP_Schema__rootSchema, pRootSchema, __LINE__);
}

inline int DskSchema::getRootSchema(DskSchema& rootSchema) const
{
	return getProperty(PRP_Schema__rootSchema, rootSchema, __LINE__);
}

inline int DskSchema::subschemasByNumber(JomColl& coll) const
{
	int result = valuesFromProperty(PRP_Schema__sysSchemasByNumber, coll, __LINE__);
	CHECK_RESULT;

	return valuesFromProperty(PRP_Schema__schemasByNumber, coll, __LINE__);
}

inline int DskSchema::userSubschemasByNumber(JomColl& coll) const
{
	return valuesFromProperty(PRP_Schema__schemasByNumber, coll, __LINE__);
}

//------------------------------------------------------------------------------
// DskCollection:

inline int DskCollection::purge() const
{
	// send the message to either the btree or list
	return sendMsg(TEXT("purge"));
}

inline int DskCollection::clear() const
{
	// send the message to either the btree or list
	return sendMsg(TEXT("clear"));
}

//------------------------------------------------------------------------------
// DskBtree:

inline int DskBtree::values(JomColl& coll) const
{
	return valuesFromMsg(MTH_Btree__values, coll, __LINE__);
}

//------------------------------------------------------------------------------
// DskDictionary:

inline int DskDictionary::getAtKey(const Character key[], DskObject& value) const
{
	ShortDskParam keyParam;
	paramSetCString(keyParam, key);

	return getAtKey(keyParam, value);
}

inline int DskDictionary::getAtKey(UInt32 key, DskObject& value) const
{
	ShortDskParam keyParam;
	paramSetInteger(keyParam, key);

	return getAtKey(keyParam, value);
}

inline int DskDictionary::getAtKey(Real key, DskObject& value) const
{
	ShortDskParam keyParam;
	paramSetReal(keyParam, key);

	return getAtKey(keyParam, value);
}

inline int DskDictionary::getAtKey(const DskObject* pKey, DskObject& value) const
{
	ShortDskParam keyParam;
	paramSetOid(keyParam, pKey->oid);

	return getAtKey(keyParam, value);
}

inline int DskDictionary::getAtKey(const DskTimeStamp* pKey, DskObject& value) const
{
	ShortDskParam keyParam;
	paramSetTimeStamp(keyParam, *pKey);

	return getAtKey(keyParam, value);
}

inline int DskDictionary::getAtDateKey(const DskDate* pKey, DskObject& value) const
{
	ShortDskParam keyParam;
	paramSetDate(keyParam, *pKey);

	return getAtKey(keyParam, value);
}

inline int DskDictionary::getAtTimeKey(const DskTime* pKey, DskObject& value) const
{
	ShortDskParam keyParam;
	paramSetTime(keyParam, *pKey);
	
	return getAtKey(keyParam, value);
}

inline int DskDictionary::removeKey(const Character key[]) const
{
	ShortDskParam keyParam;
	paramSetCString(keyParam, key);

	return sendMsg(MTH_Dictionary_removeKey, keyParam, nullptr, __LINE__);
}

inline int DskDictionary::removeKey(UInt32 key) const
{
	ShortDskParam keyParam;
	paramSetInteger(keyParam, key);

	return sendMsg(MTH_Dictionary_removeKey, keyParam, nullptr, __LINE__);
}

inline int DskDictionary::removeKey(Real key) const
{
	ShortDskParam keyParam;
	paramSetReal(keyParam, key);

	return sendMsg(MTH_Dictionary_removeKey, keyParam, nullptr, __LINE__);
}

inline int DskDictionary::removeKey(const DskObject* pKey) const
{
	ShortDskParam keyParam;
	paramSetOid(keyParam, pKey->oid);

	return sendMsg(MTH_Dictionary_removeKey, keyParam, nullptr, __LINE__);
}

inline int DskDictionary::removeKey(const DskTimeStamp* pKey) const
{
	ShortDskParam keyParam;
	paramSetTimeStamp(keyParam, *pKey);

	return sendMsg(MTH_Dictionary_removeKey, keyParam, nullptr, __LINE__);
}

inline int DskDictionary::removeDateKey(const DskDate* pKey) const
{
	ShortDskParam keyParam;
	paramSetDate(keyParam, *pKey);

	return sendMsg(MTH_Dictionary_removeKey, keyParam, nullptr, __LINE__);
}

inline int DskDictionary::removeTimeKey(const DskTime* pKey) const
{
	ShortDskParam keyParam;
	paramSetTime(keyParam, *pKey);

	return sendMsg(MTH_Dictionary_removeKey, keyParam, nullptr, __LINE__);
}

//------------------------------------------------------------------------------
// DskMemberKeyDictionary:

inline int DskMemberKeyDictionary::add(const DskObject* pObject) const
{
	ShortDskParam param1;
	paramSetOid(param1, pObject->oid);

	return sendMsg(MTH_MemberKeyDictionary_add, param1, nullptr, __LINE__);
}

inline int DskMemberKeyDictionary::remove(const DskObject* pObject) const
{
	ShortDskParam param1;
	paramSetOid(param1, pObject->oid);

	return sendMsg(MTH_MemberKeyDictionary_remove, param1, nullptr, __LINE__);
}

//------------------------------------------------------------------------------
// DskSet:

inline int DskSet::add(const DskObject* pObject) const
{
	ShortDskParam param1;
	paramSetOid(param1, pObject->oid);

	return sendMsg(MTH_Set_add, param1, nullptr, __LINE__);
}

inline int DskSet::remove(const DskObject* pObject) const
{
	ShortDskParam param1;
	paramSetOid(param1, pObject->oid);

	return sendMsg(MTH_Set_remove, param1, nullptr, __LINE__);
}

//------------------------------------------------------------------------------
// DskList:

inline int DskList::values(JomColl& coll) const
{
	return valuesFromMsg(MTH_List__values, coll, __LINE__);
}

inline int DskList::valuesReversed(JomColl& coll) const
{
	return valuesFromMsg(TEXT("_valuesReversed"), coll, __LINE__);
}

//------------------------------------------------------------------------------
// DskArray:

inline int DskArray::add(const DskObject* pObject) const
{
	ShortDskParam param1;
	paramSetOid(param1, pObject->oid);

	return sendMsg(MTH_Array_add, param1, nullptr, __LINE__);
}

inline int DskArray::add(const DskObjectId* pObject) const
{
	ShortDskParam param1;
	paramSetOid(param1, pObject);

	return sendMsg(MTH_Array_add, param1, nullptr, __LINE__);
}

inline int DskArray::add(const ShortDskObjectId* pObject) const
{
	ShortDskParam param1;
	paramSetOid(param1, *pObject);

	return sendMsg(MTH_Array_add, param1, nullptr, __LINE__);
}

inline int DskArray::add(const Character string[]) const
{
	ShortDskParam param1;
	paramSetCString(param1, string);

	return sendMsg(MTH_Array_add, param1, nullptr, __LINE__);
}

inline int DskArray::remove(const DskObject* pObject) const
{
	ShortDskParam param1;
	paramSetOid(param1, pObject->oid);

	return sendMsg(MTH_Array_remove, param1, nullptr, __LINE__);
}

inline int DskArray::remove(const Character string[]) const
{
	ShortDskParam param1;
	paramSetCString(param1, string);

	return sendMsg(MTH_Array_remove, param1, nullptr, __LINE__);
}

//------------------------------------------------------------------------------
// DskIterator:

inline int DskIterator::setCollection(const DskObjectId& oid) const
{
	return sendMsg(TEXT("setCollection"), oid, __LINE__);
}

inline int DskIterator::reset() const
{
	return sendMsg(TEXT("reset"));
}

