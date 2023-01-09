/****************************************************************************

				P R O P R I E T A R Y   N O T I C E

	This software, in whole and in every part, is proprietary to Jade Software
	Corporation Limited at Christchurch, New Zealand and is not to be
	reproduced, used or disclosed except upon prior written permission of Jade
	Software Corporation Limited.

	COPYRIGHT (c) JADE SOFTWARE CORPORATION LIMITED 2005 - ALL RIGHTS RESERVED

****************************************************************************/

#ifndef JOMOID_hpp
#define JOMOID_hpp

#include <memory.h>

#include "jomtypes.h"
#include "jomtypno.h"
#include "jomcalls.h"
#include "jomerrs.h"

// oid related support functions -- defined in jomos

const DskObjectId		NullDskObjectId			= { 0 };
const DskObjectId		RootSchemaOid			= { 1, DSKSCHEMA };
const DskObjectId		DbServerNodeOid			= { 1, DSKNODE };
const DskObjectId		ExceptionClassOid		= { 1, DSKEXCEPTIONCLASS };
const DskObjectId		SystemOid				= { 1, DSKSYSTEM };
const DskObjectId		RootDatabaseOid			= { 1, DSKDATABASE };
const ShortDskObjectId	NullShortDskObjectId	= { 0 };
const MidDskObjectId	NullMidDskObjectId		= { 0 };
const OidKey			NullOidKey				= { 0 };

inline bool operator == (const ClassID& x, const ClassID& y)
{
	return x.allbits == y.allbits;
}

inline bool operator != (const ClassID& x, const ClassID& y)
{
	return x.allbits != y.allbits;
}

inline bool operator < (const ClassID& x, const ClassID& y)
{
	return x.allbits < y.allbits;
}

inline bool operator <= (const ClassID& x, const ClassID& y)
{
	return x.allbits <= y.allbits;
}

inline bool operator > (const ClassID& x, const ClassID& y)
{
	return x.allbits > y.allbits;
}

inline bool operator >= (const ClassID& x, const ClassID& y)
{
	return x.allbits >= y.allbits;
}

// support for oid.classID == NullClassID

inline bool operator == (const ClassIDBits& x, const ClassID& y)
{
	return x == y.allbits;
}

// support for oid.classID != NullClassID

inline bool operator != (const ClassIDBits& x, const ClassID& y)
{
	return x != y.allbits;
}

inline void ClassID::set(ClassNumber classNumber)
{ 
	*this = NullClassID; 
	classNo = classNumber; 
}

inline void ClassID::set(ClassIDBits classIdBits)
{ 
	*this = NullClassID; 
	allbits = classIdBits; 
}

inline bool ClassID::isNull() const
{
	return allbits == 0;
}

inline void ClassID::set(ClassID classId)
{ 
	*this = NullClassID; 
	allbits = classId.allbits; 
}

inline void ClassID::copyLifetime(ClassID classId)
{
	classLt = classId.lifetime();
}

inline void DskObjectId::setLifetime(Lifetime lifetime_)
{
	if (classNo)
		classLt = lifetime_;
	if (parClassNo)
		parClassLt = lifetime_;
}

inline void DskObjectId::set(ClassNumber classNumber, InstanceID instanceId, ClassNumber parClassNumber, Level level, SubID sub, Edition ed, Lifetime lt)
{ 
	*this = NullDskObjectId; 
	classNo = classNumber; 
	instId = instanceId; 
	parClassNo = parClassNumber; 
	subLevel = level; 
	subId = sub; 
	edition = ed;
	setLifetime(lt);
}

inline void DskObjectId::set(ClassIDBits classIdBits, InstanceID instanceId, ClassIDBits parClassIdBits, Level level, SubID sub, Edition ed)
{ 
	*this = NullDskObjectId; 
	classId = classIdBits; 
	instId = instanceId; 
	parClassId = parClassIdBits; 
	subLevel = level; 
	subId = sub; 
	edition = ed;
}

inline void DskObjectId::set(ClassID cId, InstanceID instanceId, ClassID parCId, Level level, SubID sub, Edition ed)
{ 
	*this = NullDskObjectId; 
	classId = cId.allbits; 
	instId = instanceId; 
	parClassId = parCId.allbits; 
	subLevel = level; 
	subId = sub;
	edition = ed;
}

inline void DskObjectId::set(const DskObjectId& oid)
{ 
	*this = oid; 
}

inline void DskObjectId::set(const ShortDskObjectId& oid)
{ 
	*this = NullDskObjectId; 
	classId = oid.classId;
	instId = oid.instId; 
}

inline void DskObjectId::set(const MidDskObjectId& oid)
{
	*this = NullDskObjectId;
	classId = oid.classId;
	instId = oid.instId;
	parClassId = oid.parClassId;
}

inline void DskObjectId::set(const OidKey& oid)
{ 
	*this = NullDskObjectId; 
	classId = oid.classId; 
	instId = oid.instId; 
	parClassId = oid.parClassId; 
	subLevel = oid.subLevel; 
	subId = oid.subId;
	edition = 0;
}

inline bool DskObjectId::isNull() const
{
	return (classId == 0 && parClassId == 0) || instId == 0;
}

inline bool DskObjectId::isPersistent() const
{
	return (classId != NullClassID ? classLt : parClassLt) == LIFETIME_PERSISTENT;
}

inline bool DskObjectId::isNonSharedTransient() const
{
	return (classId != NullClassID ? classLt : parClassLt) == LIFETIME_TRANSIENT;
}

inline bool DskObjectId::isSharedTransient() const
{
	return (classId != NullClassID ? classLt : parClassLt) == LIFETIME_SHAREDTRANSIENT;
}

inline bool DskObjectId::isTransient() const
{
	return isNonSharedTransient() || isSharedTransient();
}

inline bool DskObjectId::isPersistentOrSharedTransient() const
{
	return isPersistent() || isSharedTransient();
}

inline void DskObjectId::makePersistent()
{ 
	if (classNo != 0) 
		classLt = LIFETIME_PERSISTENT;
	if (parClassNo != 0)
		parClassLt = LIFETIME_PERSISTENT;
}

inline void DskObjectId::makeNonSharedTransient()
{
	if (classNo != 0) 
		classLt = LIFETIME_TRANSIENT;
	if (parClassNo != 0)
		parClassLt = LIFETIME_TRANSIENT;
}

inline void DskObjectId::makeSharedTransient()
{ 
	if (classNo != 0) 
		classLt = LIFETIME_SHAREDTRANSIENT;
	if (parClassNo != 0)
		parClassLt = LIFETIME_SHAREDTRANSIENT; 
}

inline void DskObjectId::makeTransient()
{ 
	makeNonSharedTransient(); 
}

inline void DskObjectId::copyLifetime(const DskObjectId& oid)
{
	setLifetime(oid.lifetime());
}

inline void DskObjectId::copyLifetime(const OidKey& oid)
{
	setLifetime(oid.lifetime());
}

inline void DskObjectId::getParent(DskObjectId& parent) const
{
	if (getParClassNo())
	{
		parent.set(getParClassNo(), getInstId());
		parent.copyLifetime(*this);
	}
	else
		parent = NullDskObjectId;
}

inline bool DskObjectId::isShortObjectId() const
{
	// isShortObjectId: Short Oid - NOT blob, exclusive collection header, collection block or cluster
	return parClassId == NullClassID;
}

inline bool DskObjectId::isExclusive() const
{
	return parClassId != NullClassID && subId != 0;
}

inline bool DskObjectId::isCollBlock() const
{
	return parClassId != NullClassID && subLevel == 0 && subId == 0;
}

inline bool DskObjectId::isCluster() const
{
	return parClassId != NullClassID && getClassNo() == DSKCLUSTER;
}

inline bool DskObjectId::isPersistentCluster() const
{
	return isCluster() && isPersistent();
}

inline bool DskObjectId::isBlobOrSlob() const
{
	// include parClassId to allow for null!
	return classId == NullClassID && parClassId != NullClassID;
}

inline bool DskObjectId::isValid() const
{
	if (instId == 0) 
		return false;

	bool isValid = false;
	jomIsValidObject(JomDefaultProcessHandle, this, isValid, __LINE__);

	return isValid;
}

inline bool DskObjectId::isLockedByMe() const
{
	LockType type;
	LockDuration duration;
	DskObjectId lockedBy;

	jomGetLockStatus(JomDefaultProcessHandle, this, &type, &duration, &lockedBy, __LINE__);

	return type != NO_LOCK;
}

inline void ShortDskObjectId::setLifetime(Lifetime lifetime_)
{
	if (classNo)
		classLt = lifetime_;
}

inline void ShortDskObjectId::set(ClassNumber classNumber, InstanceID instanceId, Lifetime lt)
{ 
	*this = NullShortDskObjectId; 
	classNo = classNumber; 
	instId = instanceId; 
	setLifetime(lt);
}

inline void ShortDskObjectId::set(ClassIDBits classIdBits, InstanceID instanceId)
{ 
	*this = NullShortDskObjectId; 
	classId = classIdBits; 
	instId = instanceId; 
}

inline void ShortDskObjectId::set(ClassID cId, InstanceID instanceId)
{ 
	*this = NullShortDskObjectId; 
	classId = cId.allbits; 
	instId = instanceId; 
}

inline void ShortDskObjectId::set(const DskObjectId& oid)
{ 
	*this = NullShortDskObjectId; 
	classId = oid.classId;
	instId = oid.instId; 
}

inline void ShortDskObjectId::set(const ShortDskObjectId& oid)
{ 
	*this = oid; 
}

inline void ShortDskObjectId::set(const OidKey& oid)
{ 
	*this = NullShortDskObjectId; 
	classId = oid.classId; 
	instId = oid.instId; 
}

inline bool ShortDskObjectId::isNull() const
{
	return classId == 0 || instId == 0;
}

inline bool ShortDskObjectId::isPersistent() const
{
	return classLt == LIFETIME_PERSISTENT;
}

inline bool ShortDskObjectId::isNonSharedTransient() const
{
	return classLt == LIFETIME_TRANSIENT;
}

inline bool ShortDskObjectId::isSharedTransient() const
{
	return classLt == LIFETIME_SHAREDTRANSIENT;
}

inline bool ShortDskObjectId::isTransient() const
{
	return isNonSharedTransient() || isSharedTransient();
}

inline bool ShortDskObjectId::isPersistentOrSharedTransient() const
{
	return isPersistent() || isSharedTransient();
}

inline void ShortDskObjectId::makePersistent()
{ 
	classLt = LIFETIME_PERSISTENT; 
}

inline void ShortDskObjectId::makeNonSharedTransient()
{ 
	classLt = LIFETIME_TRANSIENT; 
}

inline void ShortDskObjectId::makeSharedTransient()
{ 
	classLt = LIFETIME_SHAREDTRANSIENT; 
}

inline void ShortDskObjectId::makeTransient()
{ 
	makeNonSharedTransient(); 
}

inline void ShortDskObjectId::copyLifetime(const ShortDskObjectId& oid)
{
	setLifetime(oid.lifetime());
}

inline bool ShortDskObjectId::isValid() const
{
	if (instId == 0) 
		return false;

	DskObjectId oid;
	oid.set(*this);

	Edition edition;
	jomGetLatestEdition(JomDefaultProcessHandle, &oid, &edition, __LINE__);

	return edition > 0;
}

// SplitVector requires an operator that defines whether an entry is 'null' or not
// if comparing with null (0) then return false, otherwise true
inline bool ShortDskObjectId::operator == (void* ptr) const
{
	return ptr != 0; 
}

inline void MidDskObjectId::setLifetime(Lifetime lifetime_)
{
	if (classNo)
		classLt = lifetime_;
	if (parClassNo)
		parClassLt = lifetime_;
}

inline void MidDskObjectId::set(ClassNumber classNumber, InstanceID instanceId, ClassNumber parClassNumber, Lifetime lt)
{ 
	*this = NullMidDskObjectId; 
	classNo = classNumber; 
	instId = instanceId; 
	parClassNo = parClassNumber; 
	setLifetime(lt);
}

inline void MidDskObjectId::set(ClassIDBits classIdBits, InstanceID instanceId, ClassIDBits parClassIdBits)
{ 
	*this = NullMidDskObjectId; 
	classId = classIdBits; 
	instId = instanceId; 
	parClassId = parClassIdBits; 
}

inline void MidDskObjectId::set(ClassID cId, InstanceID instanceId, ClassID parCId)
{ 
	*this = NullMidDskObjectId; 
	classId = cId.allbits; 
	instId = instanceId; 
	parClassId = parCId.allbits; 
}

inline void MidDskObjectId::set(const DskObjectId& oid)
{ 
	*this = NullMidDskObjectId; 
	classId = oid.classId; 
	instId = oid.instId; 
	parClassId = oid.parClassId; 
}

inline void MidDskObjectId::set(const MidDskObjectId& oid)
{ 
	*this = oid; 
}

inline bool MidDskObjectId::isNull() const
{
	return (classId == 0 && parClassId == 0) || instId == 0;
}

inline bool MidDskObjectId::isPersistent() const
{
	return classLt == LIFETIME_PERSISTENT;
}

inline bool MidDskObjectId::isNonSharedTransient() const
{
	return classLt == LIFETIME_TRANSIENT;
}

inline bool MidDskObjectId::isSharedTransient() const
{
	return classLt == LIFETIME_SHAREDTRANSIENT;
}

inline bool MidDskObjectId::isTransient() const
{
	return isNonSharedTransient() || isSharedTransient();
}

inline bool MidDskObjectId::isPersistentOrSharedTransient() const
{
	return isPersistent() || isSharedTransient();
}

inline void MidDskObjectId::makePersistent()
{ 
	classLt = LIFETIME_PERSISTENT; 
}

inline void MidDskObjectId::makeNonSharedTransient()
{ 
	classLt = LIFETIME_TRANSIENT; 
}

inline void MidDskObjectId::makeSharedTransient()
{ 
	classLt = LIFETIME_SHAREDTRANSIENT; 
}

inline void MidDskObjectId::makeTransient()
{ 
	makeNonSharedTransient(); 
}

inline void MidDskObjectId::copyLifetime(const MidDskObjectId& oid)
{
	setLifetime(oid.lifetime());
}

inline void OidKey::setLifetime(Lifetime lifetime_)
{
	if (classNo)
		classLt = lifetime_;
	if (parClassNo)
		parClassLt = lifetime_;
}

inline void OidKey::set(ClassNumber classNumber, InstanceID instanceId, ClassNumber parClassNumber, Level level, SubID sub, Lifetime lt)
{ 
	*this = NullOidKey; 
	classNo = classNumber; 
	instId = instanceId; 
	parClassNo = parClassNumber; 
	subLevel = level; 
	subId = sub; 
	setLifetime(lt);
}

inline void OidKey::set(ClassIDBits classIdBits, InstanceID instanceId, ClassIDBits parClassIdBits, Level level, SubID sub)
{ 
	*this = NullOidKey; 
	classId = classIdBits; 
	instId = instanceId; 
	parClassId = parClassIdBits; 
	subLevel = level; 
	subId = sub; 
}


inline void OidKey::set(ClassID cId, InstanceID instanceId, ClassID parCId, Level level, SubID sub)
{ 
	*this = NullOidKey; 
	classId = cId.allbits; 
	instId = instanceId; 
	parClassId = parCId.allbits; 
	subLevel = level; 
	subId = sub;
}

inline void OidKey::set(const DskObjectId& oid)
{ 
	*this = NullOidKey; 
	classId = oid.classId; 
	instId = oid.instId; 
	parClassId = oid.parClassId; 
	subLevel = oid.subLevel; 
	subId = oid.subId;
}

inline void OidKey::set(const ShortDskObjectId& oid)
{ 
	*this = NullOidKey; 
	classId = oid.classId; 
	instId = oid.instId; 
}

inline void OidKey::set(const OidKey& oid)
{ 
	*this = oid; 
}

inline bool OidKey::isNull() const
{
	return (classId == 0 && parClassId == 0) || instId == 0;
}

inline bool OidKey::isPersistent() const
{
	return (classId != NullClassID ? classLt : parClassLt) == LIFETIME_PERSISTENT;
}

inline bool OidKey::isNonSharedTransient() const
{
	return (classId != NullClassID ? classLt : parClassLt) == LIFETIME_TRANSIENT;
}

inline bool OidKey::isSharedTransient() const
{
	return (classId != NullClassID ? classLt : parClassLt) == LIFETIME_SHAREDTRANSIENT;
}

inline bool OidKey::isTransient() const
{
	return isNonSharedTransient() || isSharedTransient();
}

inline bool OidKey::isPersistentOrSharedTransient() const
{
	return isPersistent() || isSharedTransient();
}

inline void OidKey::makePersistent()
{ 
	if (classNo != 0) 
		classLt = LIFETIME_PERSISTENT; 
	if (parClassNo != 0)
		parClassLt = LIFETIME_PERSISTENT;
}

inline void OidKey::makeNonSharedTransient()
{ 
	if (classNo != 0) 
		classLt = LIFETIME_TRANSIENT;
	if (parClassNo != 0)
		parClassLt = LIFETIME_TRANSIENT;
}

inline void OidKey::makeSharedTransient()
{ 
	if (classId != NullClassID)
		classLt = LIFETIME_SHAREDTRANSIENT;
	if (parClassId != NullClassID)
		parClassLt = LIFETIME_SHAREDTRANSIENT;
}

inline void OidKey::makeTransient()
{ 
	makeNonSharedTransient(); 
}

inline bool OidKey::isShortObjectId() const
{
	// isShortObjectId: Short Oid - NOT blob, exclusive collection header, collection block or cluster
	return parClassId == NullClassID;
}

inline bool OidKey::isExclusive() const
{
	return parClassId != NullClassID && subId != 0;
}

inline bool OidKey::isCollBlock() const
{
	return parClassId != NullClassID && subLevel == 0 && subId == 0;
}

inline bool OidKey::isCluster() const
{
	return parClassId != NullClassID && getClassNo() == DSKCLUSTER;
}

inline bool OidKey::isPersistentCluster() const
{
	return isCluster() && isPersistent();
}

inline bool OidKey::isBlobOrSlob() const
{
	// include parClassId to allow for null!
	return classId == NullClassID && parClassId != NullClassID;
}

inline bool OidKey::isValid() const
{
	if (instId == 0) 
		return false;

	DskObjectId oid;
	oid.set(*this);

	Edition edition;
	jomGetLatestEdition(JomDefaultProcessHandle, &oid, &edition, __LINE__);

	return edition > 0;
}

inline void OidKey::copyLifetime(const OidKey& oid)
{
	setLifetime(oid.lifetime());
}

inline void OidKey::copyLifetime(const DskObjectId& oid)
{
	setLifetime(oid.lifetime());
}

inline void OidKey::getParent(DskObjectId& parent) const
{
	if (getParClassNo())
	{
		parent.set(getParClassNo(), getInstId());
		parent.copyLifetime(*this);
	}
	else
		parent = NullDskObjectId;
}

inline bool isCollBlockClassNumber(const ClassNumber classNo)
{
	return classNo == DSKARRAYBLOCK || classNo == DSKSETBLOCK || classNo == DSKDICTBLOCK || classNo == DSKJADEDATABLOCK || classNo == DSKJADERTREEBLOCK;
}

inline bool isTransientClassNumber(const ClassNumber classNo)
{
	return classNo >= MIN_TRANSIENT_CLASS_NUM && classNo <= MAX_TRANSIENT_CLASS_NUM;
}

inline bool isPersistentClassNumber(const ClassNumber classNo)
{
	return !isTransientClassNumber(classNo);
}

inline bool isEnvironmentalClassNumber(const ClassNumber classNo)
{
	return (classNo >= DSKSYSTEM && classNo <= DSKPROCESS) || classNo == DSKWEBSESSIONMANAGER || classNo == DSKWEBSESSIONSDICT || classNo == DSKJADEDATABASEADMIN;
}

inline bool isRootSchemaObject(ClassNumber classNo)
{
	return classNo >= MIN_ROOT_SCHEMA_CLASS_NUM && classNo <= MAX_ROOT_SCHEMA_CLASS_NUM;
}

inline bool isJadeSchemaObject(ClassNumber classNo)
{
	return classNo >= MIN_JADE_SCHEMA_CLASS_NUM && classNo <= MAX_JADE_SCHEMA_CLASS_NUM;
}

inline bool isReportWriterSchemaObject(ClassNumber classNo)
{
	return classNo >= MIN_REPORTWRITER_CLASS_NUM && classNo <= MAX_REPORTWRITER_CLASS_NUM;
}

inline bool isSystemSchemaObject(ClassNumber classNo)
{
	return classNo >= MIN_SYSTEMSCHEMA_CLASS_NUM && classNo <= MAX_SYSTEMSCHEMA_CLASS_NUM;
}

inline bool isRemappedSystemObject(ClassNumber classNo)
{
	return classNo >= MIN_USER_REMAP_CLASS_NUM && classNo <= MAX_USER_REMAP_CLASS_NUM;
}

inline bool isRemappedSystemObject(const DskObjectId& oid)
{
	return isRemappedSystemObject(oid.isExclusive() ? oid.getParClassNo() : oid.getClassNo());
}

inline bool isRemappedSystemObject(const ShortDskObjectId& oid)
{
	return isRemappedSystemObject(oid.getClassNo());
}

inline bool isSystemObject(ClassNumber classNo)
{
	return classNo <= MAX_ROOT_SCHEMA_CLASS_NUM || classNo >= MIN_SYSTEMSCHEMA_CLASS_NUM;
}

inline bool isSystemObject(const DskObjectId& oid)
{
	return isSystemObject(oid.isExclusive() ? oid.getParClassNo() : oid.getClassNo());
}

inline bool isSystemObject(const ShortDskObjectId& oid)
{
	return isSystemObject(oid.getClassNo());
}

inline ClassNumber actualClass(ClassNumber classNo)
{
	return isRemappedSystemObject(classNo) ? ClassNumber(classNo - USER_REMAP_OFFSET) : classNo;
}

inline ClassNumber actualClass(ClassID classId)
{
	return actualClass(classId.getClassNo());
}

inline ClassNumber actualClass(ClassIDBits bits)
{
	return actualClass((ClassID) bits);
}

inline bool isBootstrapSchemaObject(ClassNumber classNo)
{
	return actualClass(classNo) <= MAX_HARDCODED_SCHEMA_CLASSNO;
}

inline bool isUserObject(ClassNumber classNo)
{
	const auto isUserSchemaClass{ classNo >= MIN_USER_CLASS_NUM && classNo <= MAX_USER_CLASS_NUM };
	const auto isReportWriterClass{ classNo >= MIN_REPORTWRITER_CLASS_NUM && classNo <= MAX_REPORTWRITER_CLASS_NUM };
	return isUserSchemaClass || isReportWriterClass;
}

inline bool isUserObject(const DskObjectId& oid)
{
	return isUserObject(oid.isExclusive() ? oid.getParClassNo() : oid.getClassNo());
}

inline bool isUserObject(const ShortDskObjectId& oid)
{
	return isUserObject(oid.getClassNo());
}

inline bool isSystemOnlyCollection(TypeNum typeNo)
{
	return (typeNo >= MIN_SYS_ONLY_COLL && typeNo <= MAX_SYS_ONLY_COLL) || (typeNo >= MIN_SYS_ONLY_COLL_EX && typeNo <= MAX_SYS_ONLY_COLL_EX);
}

inline bool isSystemOnlyCollection(const DskObjectId& oid)
{
	return isSystemOnlyCollection(oid.getClassNo());
}

inline bool isUserOnlyCollection(TypeNum typeNo)
{
	return (typeNo >= MIN_USER_ONLY_COLL && typeNo <= MAX_USER_ONLY_COLL) || (typeNo >= MIN_USER_ONLY_COLL_EX && typeNo <= MAX_USER_ONLY_COLL_EX);
}

inline bool isUserOnlyCollection(const DskObjectId& oid)
{
	return isUserOnlyCollection(oid.getClassNo());
}

inline bool isSystemOrUserOnlyCollection(TypeNum typeNo)
{
	return isSystemOnlyCollection(typeNo) || isUserOnlyCollection(typeNo);
}

inline bool isSystemOrUserOnlyCollection(const DskObjectId& oid)
{
	return isSystemOnlyCollection(oid.getClassNo()) || isUserOnlyCollection(oid.getClassNo());
}

inline bool isJadePatchClass(ClassNumber classNo)
{
	// some RootSchema classes are not remapped
	return classNo == DSKJADEPATCHCONTROLDICT || classNo == DSKJADEPATCHVERSION || classNo == DSKJADEPATCHVERSIONDETAIL || classNo == DSKJADEPATCHVERSIONDICT;
}

inline ClassNumber normaliseTransientClassNumber(ClassNumber classNo)
{
	if (isTransientClassNumber(classNo))
		classNo = (ClassNumber) (classNo - MIN_TRANSIENT_CLASS_NUM + 1);
	return classNo;
}

inline bool isNullOid(const DskObjectId& oid)
{
	return oid.isNull();
}

inline bool isNullOid(const ShortDskObjectId& oid)
{
	return oid.isNull();
}

inline bool isNullOid(const OidKey& oid)
{
	return oid.isNull();
}

inline void setToNull(DskObjectId& oid)
{
	oid = NullDskObjectId;
}

inline void setToNull(ShortDskObjectId& oid)
{
	oid = NullShortDskObjectId;
}

inline void setToNull(OidKey& oid)
{
	oid = NullOidKey;
}

/* Operator overloads for DskObjectId */

inline bool operator == (const DskObjectId& x, const DskObjectId& y)
{
	return x.classId	== y.classId &&
	   x.instId			== y.instId &&
	   x.parClassId		== y.parClassId &&
	   x.subLevel		== y.subLevel &&
	   x.subId			== y.subId;
}

inline bool operator == (const DskObjectId& x, const MidDskObjectId& y)
{
	return x.classId	== y.classId &&
	   x.instId			== y.instId &&
	   x.parClassId		== y.parClassId &&
	   x.subLevel		== 0 &&
	   x.subId			== 0;
}

inline bool operator != (const DskObjectId& x, const DskObjectId& y)
{
	return x.classId	!= y.classId ||
	   x.instId			!= y.instId ||
	   x.parClassId		!= y.parClassId ||
	   x.subLevel		!= y.subLevel ||
	   x.subId			!= y.subId;
}

inline bool operator < (const DskObjectId& x, const DskObjectId& y)
{
	if (x.classId < y.classId)
		return true;
	if (x.classId > y.classId)
		return false;
	if (x.instId < y.instId)
		return true;
	if (x.instId > y.instId)
		return false;
	if (x.parClassId < y.parClassId)
		return true;
	if (x.parClassId > y.parClassId)
		return false;
	if (x.subLevel < y.subLevel)
		return true;
	if (x.subLevel > y.subLevel)
		return false;
	return x.subId < y.subId;
}

inline bool operator > (const DskObjectId& x, const DskObjectId& y)
{
	if (x.classId > y.classId)
		return true;
	if (x.classId < y.classId)
		return false;
	if (x.instId > y.instId)
		return true;
	if (x.instId < y.instId)
		return false;
	if (x.parClassId > y.parClassId)
		return true;
	if (x.parClassId < y.parClassId)
		return false;
	if (x.subLevel > y.subLevel)
		return true;
	if (x.subLevel < y.subLevel)
		return false;
	return x.subId > y.subId;
}

inline bool operator <= (const DskObjectId& x, const DskObjectId& y)
{
	if (x.classId < y.classId)
		return true;
	if (x.classId > y.classId)
		return false;
	if (x.instId < y.instId)
		return true;
	if (x.instId > y.instId)
		return false;
	if (x.parClassId < y.parClassId)
		return true;
	if (x.parClassId > y.parClassId)
		return false;
	if (x.subLevel < y.subLevel)
		return true;
	if (x.subLevel > y.subLevel)
		return false;
	return x.subId <= y.subId;
}

inline bool operator >= (const DskObjectId& x, const DskObjectId& y)
{
	if (x.classId > y.classId)
		return true;
	if (x.classId < y.classId)
		return false;
	if (x.instId > y.instId)
		return true;
	if (x.instId < y.instId)
		return false;
	if (x.parClassId > y.parClassId)
		return true;
	if (x.parClassId < y.parClassId)
		return false;
	if (x.subLevel > y.subLevel)
		return true;
	if (x.subLevel < y.subLevel)
		return false;
	return x.subId >= y.subId;
}

/* Operator overloads for ShortDskObjectId */

inline bool operator == (const ShortDskObjectId& x, const ShortDskObjectId& y)
{
	return x.classId	== y.classId &&
	   x.instId			== y.instId;
}

inline bool operator != (const ShortDskObjectId& x, const ShortDskObjectId& y)
{
	return x.classId	!= y.classId ||
	   x.instId			!= y.instId;
}

inline bool operator < (const ShortDskObjectId& x, const ShortDskObjectId& y)
{
	if (x.classId < y.classId)
		return true;
	if (x.classId > y.classId)
		return false;
	return x.instId < y.instId;
}

inline bool operator > (const ShortDskObjectId& x, const ShortDskObjectId& y)
{
	if (x.classId > y.classId)
		return true;
	if (x.classId < y.classId)
		return false;
	return x.instId > y.instId;
}

inline bool operator <= (const ShortDskObjectId& x, const ShortDskObjectId& y)
{
	if (x.classId < y.classId)
		return true;
	if (x.classId > y.classId)
		return false;
	return x.instId <= y.instId;
}

inline bool operator >= (const ShortDskObjectId& x, const ShortDskObjectId& y)
{
	if (x.classId > y.classId)
		return true;
	if (x.classId < y.classId)
		return false;
	return x.instId >= y.instId;
}

/* Operator overloads for OidKey */

inline bool operator == (const OidKey& x, const OidKey& y)
{
	return x.classId	== y.classId &&
	   x.instId			== y.instId &&
	   x.parClassId		== y.parClassId &&
	   x.subLevel		== y.subLevel &&
	   x.subId			== y.subId;
}

inline bool operator != (const OidKey& x, const OidKey& y)
{
	return x.classId	!= y.classId ||
	   x.instId			!= y.instId ||
	   x.parClassId		!= y.parClassId ||
	   x.subLevel		!= y.subLevel ||
	   x.subId			!= y.subId;
}

inline bool operator < (const OidKey& x, const OidKey& y)
{
	if (x.classId < y.classId)
		return true;
	if (x.classId > y.classId)
		return false;
	if (x.instId < y.instId)
		return true;
	if (x.instId > y.instId)
		return false;
	if (x.parClassId < y.parClassId)
		return true;
	if (x.parClassId > y.parClassId)
		return false;
	if (x.subLevel < y.subLevel)
		return true;
	if (x.subLevel > y.subLevel)
		return false;
	return x.subId < y.subId;
}

inline bool operator > (const OidKey& x, const OidKey& y)
{
	if (x.classId > y.classId)
		return true;
	if (x.classId < y.classId)
		return false;
	if (x.instId > y.instId)
		return true;
	if (x.instId < y.instId)
		return false;
	if (x.parClassId > y.parClassId)
		return true;
	if (x.parClassId < y.parClassId)
		return false;
	if (x.subLevel > y.subLevel)
		return true;
	if (x.subLevel < y.subLevel)
		return false;
	return x.subId > y.subId;
}

inline bool operator <= (const OidKey& x, const OidKey& y)
{
	if (x.classId < y.classId)
		return true;
	if (x.classId > y.classId)
		return false;
	if (x.instId < y.instId)
		return true;
	if (x.instId > y.instId)
		return false;
	if (x.parClassId < y.parClassId)
		return true;
	if (x.parClassId > y.parClassId)
		return false;
	if (x.subLevel < y.subLevel)
		return true;
	if (x.subLevel > y.subLevel)
		return false;
	return x.subId <= y.subId;
}

inline bool operator >= (const OidKey& x, const OidKey& y)
{
	if (x.classId > y.classId)
		return true;
	if (x.classId < y.classId)
		return false;
	if (x.instId > y.instId)
		return true;
	if (x.instId < y.instId)
		return false;
	if (x.parClassId > y.parClassId)
		return true;
	if (x.parClassId < y.parClassId)
		return false;
	if (x.subLevel > y.subLevel)
		return true;
	if (x.subLevel < y.subLevel)
		return false;
	return x.subId >= y.subId;
}

/* Operator overloads for MidDskObjectId */

inline bool operator == (const MidDskObjectId& x, const MidDskObjectId& y)
{
	return x.classId	== y.classId &&
	   x.instId			== y.instId &&
	   x.parClassId		== y.parClassId;
}

inline bool operator != (const MidDskObjectId& x, const MidDskObjectId& y)
{
	return x.classId	!= y.classId ||
	   x.instId			!= y.instId ||
	   x.parClassId		!= y.parClassId;
}

inline bool operator < (const MidDskObjectId& x, const MidDskObjectId& y)
{
	if (x.classId < y.classId)
		return true;
	if (x.classId > y.classId)
		return false;
	if (x.instId < y.instId)
		return true;
	if (x.instId > y.instId)
		return false;
	return x.parClassId < y.parClassId;
}

inline bool operator > (const MidDskObjectId& x, const MidDskObjectId& y)
{
	if (x.classId > y.classId)
		return true;
	if (x.classId < y.classId)
		return false;
	if (x.instId > y.instId)
		return true;
	if (x.instId < y.instId)
		return false;
	return x.parClassId > y.parClassId;
}

inline bool operator <= (const MidDskObjectId& x, const MidDskObjectId& y)
{
	if (x.classId < y.classId)
		return true;
	if (x.classId > y.classId)
		return false;
	if (x.instId < y.instId)
		return true;
	if (x.instId > y.instId)
		return false;
	return x.parClassId <= y.parClassId;
}

inline bool operator >= (const MidDskObjectId& x, const MidDskObjectId& y)
{
	if (x.classId > y.classId)
		return true;
	if (x.classId < y.classId)
		return false;
	if (x.instId > y.instId)
		return true;
	if (x.instId < y.instId)
		return false;
	return x.parClassId >= y.parClassId;
}

#endif /* JOMOID_hpp */
