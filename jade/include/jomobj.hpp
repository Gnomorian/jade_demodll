/****************************************************************************

				P R O P R I E T A R Y   N O T I C E

	This software, in whole and in every part, is proprietary to Jade Software
	Corporation Limited at Christchurch, New Zealand and is not to be
	reproduced, used or disclosed except upon prior written permission of Jade
	Software Corporation Limited.

	COPYRIGHT (c) JADE SOFTWARE CORPORATION LIMITED 2005 - ALL RIGHTS RESERVED

****************************************************************************/

#ifndef JOMOBJ_hpp
#define JOMOBJ_hpp

#include "jomdefs.h"
#include "jomtypes.h"
#include "jomerrs.h"
#include "jomparam.hpp"
#include "jommco.hpp"

#ifndef JOMOBJ_LINKAGE 
#define JOMOBJ_LINKAGE CLASS_IMPORT  /* _export for DLLs, nothing for LIBs/EXEs */
#endif

#ifndef JOMOBJ_EXPORT  
#define JOMOBJ_EXPORT  DllImport
#endif

/* 'default' structure member alignment (packing) */
#ifdef JADE_64BIT_NODE
#include "jompack8.h"
#else
#include "jompack4.h"
#endif

//----------------------------------------------------------------------
// Class Forward declarations

class JOMOBJ_LINKAGE DskArray;
class JOMOBJ_LINKAGE DskClass;
class JOMOBJ_LINKAGE DskConstant;
class JOMOBJ_LINKAGE DskConstantCategory;
class JOMOBJ_LINKAGE DskDatabase;
class JOMOBJ_LINKAGE DskDbClassMap;
class JOMOBJ_LINKAGE DskDbFile;
class JOMOBJ_LINKAGE DskDbServer;
class JOMOBJ_LINKAGE DskExternalKey;
class JOMOBJ_LINKAGE DskFeatureUsage;
class JOMOBJ_LINKAGE DskFunction;
class JOMOBJ_LINKAGE DskGlobalConstant;
class JOMOBJ_LINKAGE DskInlineTypeUsage;
class JOMOBJ_LINKAGE DskInverse;
class JOMOBJ_LINKAGE DskIterator;
class JOMOBJ_LINKAGE DskJadeExposedList;
class JOMOBJ_LINKAGE DskJadeExportedPackage;
class JOMOBJ_LINKAGE DskJadeImportedClass;
class JOMOBJ_LINKAGE DskJadeImportedConstant;
class JOMOBJ_LINKAGE DskJadeImportedInterface;
class JOMOBJ_LINKAGE DskJadeImportedPackage;
class JOMOBJ_LINKAGE DskJadeInterface;
class JOMOBJ_LINKAGE DskKey;
class JOMOBJ_LINKAGE DskKeyUsage;
class JOMOBJ_LINKAGE DskLibrary;
class JOMOBJ_LINKAGE DskLocale;
class JOMOBJ_LINKAGE DskLocaleFormat;
class JOMOBJ_LINKAGE DskMemberKey;
class JOMOBJ_LINKAGE DskMethod;
class JOMOBJ_LINKAGE DskParameter;
class JOMOBJ_LINKAGE DskPrimType;
class JOMOBJ_LINKAGE DskPseudoType;
class JOMOBJ_LINKAGE DskProperty;
class JOMOBJ_LINKAGE DskReturnType;
class JOMOBJ_LINKAGE DskSchema;
class JOMOBJ_LINKAGE DskSchemaView;
class JOMOBJ_LINKAGE DskSet;
class JOMOBJ_LINKAGE DskTranslatableString;
class JOMOBJ_LINKAGE DskType;
class JOMOBJ_LINKAGE DskUserProfile;

// Declare Pointer types
typedef DskObject    			*PDskObject;
typedef DskMethod    			*PDskMethod;
typedef DskProperty				*PDskProperty;
typedef DskType      			*PDskType;

//-----------------------------------------------------------------------
// Class declarations

#undef isA

class JOMOBJ_LINKAGE DskObject: public JomObj
{
public:
	DskObjectId oid;

	DskObject(const DskObjectId* pOid)									{ oid.set(*pOid); }
	DskObject(const ShortDskObjectId* pShortOid)						{ oid.set(*pShortOid); }
	DskObject(const OidKey* pOidKey)									{ oid.set(*pOidKey); }
	DskObject(ClassNumber classNo)										{ oid.set(classNo); }
	DskObject()															{ oid.set(NullDskObjectId); }

	DskObject(const DskObjectId& fullOid)								{ oid.set(fullOid); }
	DskObject(const ShortDskObjectId& shortOid)							{ oid.set(shortOid); }
	DskObject(const OidKey& oidKey)										{ oid.set(oidKey); }

	virtual ~DskObject() = default;

	// attributes:
	
	// Following reimplemented on SchemaEntity and selected meta schema classes
	virtual int		setModifiedTimeStamp(DskTimeStamp*)					{ return J_OK; }
	virtual int		getModifiedTimeStamp(DskTimeStamp*) const			{ return J_OK; }
	virtual int		setPatchVersion(Int32 )								{ return J_OK; }
	virtual int		getPatchVersion(Int32*) const						{ return J_OK; }
	virtual int		setSystemVersion(const Character[])					{ return J_OK; }
	virtual int		getSystemVersion(Character[]) const					{ return J_OK; }
	virtual int		setModifiedBy(const Character[])					{ return J_OK; }
	virtual int		getModifiedBy(Character[]) const					{ return J_OK; }

	// references:

	// Following reimplemented on SchemaEntity and selected meta schema classes
	virtual int		setUserProfile(const DskUserProfile*)				{ return J_OK; }
	virtual int		getUserProfile(DskUserProfile&) const				{ return J_OK; }

	// methods:
	virtual bool	isEqual(const JomObj& x) const override				{ return oid == ((DskObject&) x).oid; }
	virtual bool	isEqual(const Character string[]) const override	{ return JomObj::isEqual(string); }
	virtual bool	isEqual(unsigned number) const override				{ return JomObj::isEqual(number); }

	virtual HashValue hash() const override;

	virtual bool	isProxyObject() const								{ return true; }
			bool	isA(ClassNumber classNumber) const;
			bool	isA(const Character className[]) const;
			bool	isNull() const;
	inline	void	makeOidNull();
	inline	void	setCls(ClassNumber);

			int		isKindOf(ClassNumber classNumber, bool* pFlag) const;
			int		isKindOf(const Character className[], bool* pFlag) const;
			int		classFirstOid(DskObjectId* pOid) const;
			int		isSystemObject(bool* pFlag) const;
			int		isSystemBasic(bool* pFlag) const;
			int		setSystemBasic(bool sysBasic) const;

			int		createObject();
			int		createObject(const Character[]);
			int		createObject(DskParam* pParam1, DskParam* pParam2);
			int		createTransientObject();
			int		createTransientObject(DskParam* pParam1, DskParam* pParam2);
			int		createSharedTransientObject();
			int		deleteObject() const;
			int		deleteObject(DskParam* pParam1, DskParam* pParam2) const;
			int		getObject(BYTE* pBuffer, UInt32 buffSize) const;
	inline	int		lockObject(LockType type = SHARED_LOCK, LineNumber line = 0) const;
	inline	int		unlockObject(LineNumber line = 0) const;
	inline	int		resynchObject(LineNumber line = 0) const;
			int		getBufferEdition();
			int		touchObject(int filterResult, LineNumber line = 0) const;
			int		updateEdition() const;
			int		cloneObject(DskObject& clone, ClassNumber classNumber, bool transient, bool constructor, LineNumber line = 0) const;
			int		cloneObject(DskObject& clone, ClassNumber classNumber, Lifetime lifetime, bool constructor, LineNumber line = 0) const;
			int		recreateObject();

			int		compilerUpdatePatchDetails(const DskSchema* pSchema, const Character operation[], const Character priorSource[], const Character userCode[], const Character systemVersion[], Int32 patchVersion, const DskTimeStamp* pModifiedTimeStamp, bool& success) const;
			int		setProperty(const Character name[], Character value, LineNumber line = 0) const;
			int		setProperty(const Character name[], Byte value, LineNumber line = 0) const;
			int		setProperty(const Character name[], Boolean value, LineNumber line = 0) const;
			int		setProperty(const Character name[], bool value, LineNumber line = 0) const;
			int		setProperty(const Character name[], const Character value[], LineNumber line = 0) const;
			int		setProperty(const Character name[], const Character value[], PropertyLen length, LineNumber line) const;
			int		setProperty(const Character name[], Int16 value, LineNumber line = 0) const;
			int		setProperty(const Character name[], Int32 value, LineNumber line = 0) const;
			int		setProperty(const Character name[], UInt32 value, LineNumber line = 0) const;
			int		setProperty(const Character name[], Int64 value, LineNumber line = 0) const;
			int		setProperty(const Character name[], UInt64 value, LineNumber line = 0) const;
			int		setProperty(const Character name[], const DskObjectId* pValue, LineNumber line = 0) const;
			int		setProperty(const Character name[], const ShortDskObjectId* pValue, LineNumber line = 0) const;
			int		setProperty(const Character name[], const OidKey* pValue, LineNumber line = 0) const;
			int		setProperty(const Character name[], const DskObject* pValue, LineNumber line = 0) const;
			int		setProperty(const Character name[], const DskObject& value, LineNumber line = 0) const;
			int		setProperty(const Character name[], const DskParam* pValue, LineNumber line = 0) const;
			int		setProperty(const Character name[], const DskPoint* pValue, LineNumber line = 0) const;
			int		setProperty(const Character name[], const DskTimeStamp* pValue, LineNumber line = 0) const;
			int		setProperty(const Character name[], const DskTimeStampInterval* pValue, LineNumber line = 0) const;
			int		setProperty(const Character name[], const DskTimeStampOffset* pValue, LineNumber line = 0) const;
			int		setProperty(const Character name[], Float value, LineNumber line = 0) const;
			int		setProperty(const Character name[], Real value, LineNumber line = 0) const;
			int		setProperty(const Character name[], const DskDecimal* pValue, LineNumber line = 0) const;
			int		setProperty(const Character name[], const DskMemoryAddress* pValue, LineNumber line = 0) const;

			int		setDateProperty(const Character name[], DskDate value, LineNumber line = 0) const;
			int		setTimeProperty(const Character name[], DskTime value, LineNumber line = 0) const;
			int		setBinaryProperty(const Character name[], const BYTE* pValue, PropertyLen byteSize, LineNumber line = 0) const;
			int		setUInt16Property(const Character name[], UInt16 value, LineNumber line = 0) const;
#ifdef JADESTR_TYPEDEFS_DEFINED
			int		setJadeStringProperty(const Character name[], String* pValue, LineNumber line = 0) const;
			int		setJadeStringUtf8Property(const Character name[], StringUtf8* pValue, LineNumber line = 0) const;
			int		setJadeBinaryProperty(const Character name[], Binary* pValue, LineNumber line = 0) const;
#endif

			int		setProperty(const DskBuffer*, const Character name[], Character value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const Character name[], Byte value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const Character name[], Boolean value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const Character name[], bool value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const Character name[], const Character value[], LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const Character name[], const Character value[], PropertyLen length, LineNumber line) const;
			int		setProperty(const DskBuffer*, const Character name[], Int16 value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const Character name[], Int32 value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const Character name[], UInt32 value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const Character name[], Int64 value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const Character name[], UInt64 value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const Character name[], const DskObjectId* pValue, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const Character name[], const ShortDskObjectId* pValue, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const Character name[], const DskObject* pValue, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const Character name[], const DskObject& value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const Character name[], const DskParam* pValue, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const Character name[], const DskPoint* pValue, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const Character name[], const DskTimeStamp* pValue, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const Character name[], const DskTimeStampInterval* pValue, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const Character name[], const DskTimeStampOffset* pValue, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const Character name[], Float value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const Character name[], Real value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const Character name[], const DskDecimal* pValue, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const Character name[], const DskMemoryAddress* pValue, LineNumber line = 0) const;

			int		setDateProperty(const DskBuffer*, const Character name[], DskDate value, LineNumber line = 0) const;
			int		setTimeProperty(const DskBuffer*, const Character name[], DskTime value, LineNumber line = 0) const;
			int		setBinaryProperty(const DskBuffer*, const Character name[], const BYTE* pValue, PropertyLen length, LineNumber line = 0) const;
			int		setUInt16Property(const DskBuffer*, const Character name[], UInt16 value, LineNumber line = 0) const;
#ifdef JADESTR_TYPEDEFS_DEFINED
			int		setJadeStringProperty(const DskBuffer*, const Character name[], String* pValue, LineNumber line = 0) const;
			int		setJadeStringUtf8Property(const DskBuffer*, const Character name[], StringUtf8* pValue, LineNumber line = 0) const;
			int		setJadeBinaryProperty(const DskBuffer*, const Character name[], Binary* pValue, LineNumber line = 0) const;
#endif

			int		setProperty(ClassNumber cNo, FeatureNum mNo, Character value, LineNumber line = 0) const;
			int		setProperty(ClassNumber cNo, FeatureNum mNo, Byte value, LineNumber line = 0) const;
			int		setProperty(ClassNumber cNo, FeatureNum mNo, Boolean value, LineNumber line = 0) const;
			int		setProperty(ClassNumber cNo, FeatureNum mNo, bool value, LineNumber line = 0) const;
			int		setProperty(ClassNumber cNo, FeatureNum mNo, const Character value[], LineNumber line = 0) const;
			int		setProperty(ClassNumber cNo, FeatureNum mNo, const Character value[], PropertyLen length, LineNumber line) const;
			int		setProperty(ClassNumber cNo, FeatureNum mNo, Int16 value, LineNumber line = 0) const;
			int		setProperty(ClassNumber cNo, FeatureNum mNo, Int32 value, LineNumber line = 0) const;
			int		setProperty(ClassNumber cNo, FeatureNum mNo, UInt32 value, LineNumber line = 0) const;
			int		setProperty(ClassNumber cNo, FeatureNum mNo, Int64 value, LineNumber line = 0) const;
			int		setProperty(ClassNumber cNo, FeatureNum mNo, UInt64 value, LineNumber line = 0) const;
			int		setProperty(ClassNumber cNo, FeatureNum mNo, const DskObjectId* pValue, LineNumber line = 0) const;
			int		setProperty(ClassNumber cNo, FeatureNum mNo, const ShortDskObjectId* pValue, LineNumber line = 0) const;
			int		setProperty(ClassNumber cNo, FeatureNum mNo, const OidKey * pValue, LineNumber line = 0) const;
			int		setProperty(ClassNumber cNo, FeatureNum mNo, const DskObject* pValue, LineNumber line = 0) const;
			int		setProperty(ClassNumber cNo, FeatureNum mNo, const DskObject& value, LineNumber line = 0) const;
			int		setProperty(ClassNumber cNo, FeatureNum mNo, const DskParam* pValue, LineNumber line = 0) const;
			int		setProperty(ClassNumber cNo, FeatureNum mNo, const DskPoint* pValue, LineNumber line = 0) const;
			int		setProperty(ClassNumber cNo, FeatureNum mNo, const DskTimeStamp* pValue, LineNumber line = 0) const;
			int		setProperty(ClassNumber cNo, FeatureNum mNo, const DskTimeStampInterval* pValue, LineNumber line = 0) const;
			int		setProperty(ClassNumber cNo, FeatureNum mNo, const DskTimeStampOffset* pValue, LineNumber line = 0) const;
			int		setProperty(ClassNumber cNo, FeatureNum mNo, Float value, LineNumber line = 0) const;
			int		setProperty(ClassNumber cNo, FeatureNum mNo, Real value, LineNumber line = 0) const;
			int		setProperty(ClassNumber cNo, FeatureNum mNo, const DskDecimal* pValue, LineNumber line = 0) const;
			int		setProperty(ClassNumber cNo, FeatureNum mNo, const DskMemoryAddress* pValue, LineNumber line = 0) const;

			int		setDateProperty(ClassNumber cNo, FeatureNum mNo, DskDate value, LineNumber line = 0) const;
			int		setTimeProperty(ClassNumber cNo, FeatureNum mNo, DskTime value, LineNumber line = 0) const;
			int		setBinaryProperty(ClassNumber cNo, FeatureNum mNo, const BYTE* pValue, PropertyLen length, LineNumber line = 0) const;
			int		setUInt16Property(ClassNumber cNo, FeatureNum mNo, UInt16 value, LineNumber line = 0) const;
#ifdef JADESTR_TYPEDEFS_DEFINED
			int		setJadeStringProperty(ClassNumber cNo, FeatureNum mNo, String* pValue, LineNumber line = 0) const;
			int		setJadeStringUtf8Property(ClassNumber cNo, FeatureNum mNo, StringUtf8* pValue, LineNumber line = 0) const;
			int		setJadeBinaryProperty(ClassNumber cNo, FeatureNum mNo, Binary* pValue, LineNumber line = 0) const;
#endif

			int		setProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, Character value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, Byte value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, Boolean value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, bool value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, const Character value[], LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, const Character value[], PropertyLen length, LineNumber line) const;
			int		setProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, Int16 value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, Int32 value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, UInt32 value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, Int64 value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, UInt64 value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, const DskObjectId* pValue, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, const ShortDskObjectId* pValue, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, const DskObject* pValue, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, const DskObject& value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, const DskParam* pValue, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, const DskPoint* pValue, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, const DskTimeStamp* pValue, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, const DskTimeStampInterval* pValue, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, const DskTimeStampOffset* pValue, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, Float value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, Real value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, const DskDecimal* pValue, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, const DskMemoryAddress* pValue, LineNumber line = 0) const;

			int		setDateProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, DskDate value, LineNumber line = 0) const;
			int		setTimeProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, DskTime value, LineNumber line = 0) const;
			int		setBinaryProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, const BYTE* pValue, PropertyLen length, LineNumber line = 0) const;
			int		setUInt16Property(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, UInt16 value, LineNumber line = 0) const;
#ifdef JADESTR_TYPEDEFS_DEFINED
			int		setJadeStringProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, String* pValue, LineNumber line = 0) const;
			int		setJadeStringUtf8Property(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, StringUtf8* pValue, LineNumber line = 0) const;
			int		setJadeBinaryProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, Binary* pValue, LineNumber line = 0) const;
#endif

			int		setProperty(const JomClassFeatureLevel& feature, Character value, LineNumber line = 0) const;
			int		setProperty(const JomClassFeatureLevel& feature, Byte value, LineNumber line = 0) const;
			int		setProperty(const JomClassFeatureLevel& feature, Boolean value, LineNumber line = 0) const;
			int		setProperty(const JomClassFeatureLevel& feature, bool value, LineNumber line = 0) const;
			int		setProperty(const JomClassFeatureLevel& feature, const Character value[], LineNumber line = 0) const;
			int		setProperty(const JomClassFeatureLevel& feature, const Character value[], PropertyLen length, LineNumber line) const;
			int		setProperty(const JomClassFeatureLevel& feature, Int16 value, LineNumber line = 0) const;
			int		setProperty(const JomClassFeatureLevel& feature, Int32 value, LineNumber line = 0) const;
			int		setProperty(const JomClassFeatureLevel& feature, UInt32 value, LineNumber line = 0) const;
			int		setProperty(const JomClassFeatureLevel& feature, Int64 value, LineNumber line = 0) const;
			int		setProperty(const JomClassFeatureLevel& feature, UInt64 value, LineNumber line = 0) const;
			int		setProperty(const JomClassFeatureLevel& feature, const DskObjectId* pValue, LineNumber line = 0) const;
			int		setProperty(const JomClassFeatureLevel& feature, const ShortDskObjectId* pValue, LineNumber line = 0) const;
			int		setProperty(const JomClassFeatureLevel& feature, const OidKey* pValue, LineNumber line = 0) const;
			int		setProperty(const JomClassFeatureLevel& feature, const DskObject* pValue, LineNumber line = 0) const;
			int		setProperty(const JomClassFeatureLevel& feature, const DskObject& value, LineNumber line = 0) const;
			int		setProperty(const JomClassFeatureLevel& feature, const DskParam* pValue, LineNumber line = 0) const;
			int		setProperty(const JomClassFeatureLevel& feature, const DskPoint* pValue, LineNumber line = 0) const;
			int		setProperty(const JomClassFeatureLevel& feature, const DskTimeStamp* pValue, LineNumber line = 0) const;
			int		setProperty(const JomClassFeatureLevel& feature, const DskTimeStampInterval* pValue, LineNumber line = 0) const;
			int		setProperty(const JomClassFeatureLevel& feature, const DskTimeStampOffset* pValue, LineNumber line = 0) const;
			int		setProperty(const JomClassFeatureLevel& feature, Float value, LineNumber line = 0) const;
			int		setProperty(const JomClassFeatureLevel& feature, Real value, LineNumber line = 0) const;
			int		setProperty(const JomClassFeatureLevel& feature, const DskDecimal* pValue, LineNumber line = 0) const;
			int		setProperty(const JomClassFeatureLevel& feature, const DskMemoryAddress* pValue, LineNumber line = 0) const;

			int		setDateProperty(const JomClassFeatureLevel& feature, DskDate value, LineNumber line = 0) const;
			int		setTimeProperty(const JomClassFeatureLevel& feature, DskTime value, LineNumber line = 0) const;
			int		setBinaryProperty(const JomClassFeatureLevel& feature, const BYTE* pValue, PropertyLen length, LineNumber line = 0) const;
			int		setUInt16Property(const JomClassFeatureLevel& feature, UInt16 value, LineNumber line = 0) const;
#ifdef JADESTR_TYPEDEFS_DEFINED
			int		setJadeStringProperty(const JomClassFeatureLevel& feature, String* pValue, LineNumber line = 0) const;
			int		setJadeStringUtf8Property(const JomClassFeatureLevel& feature, StringUtf8* pValue, LineNumber line = 0) const;
			int		setJadeBinaryProperty(const JomClassFeatureLevel& feature, Binary* pValue, LineNumber line = 0) const;
#endif

			int		setProperty(const DskBuffer*, const JomClassFeatureLevel& feature, Character value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const JomClassFeatureLevel& feature, Byte value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const JomClassFeatureLevel& feature, Boolean value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const JomClassFeatureLevel& feature, bool value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const JomClassFeatureLevel& feature, const Character value[], LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const JomClassFeatureLevel& feature, const Character value[], PropertyLen length, LineNumber line) const;
			int		setProperty(const DskBuffer*, const JomClassFeatureLevel& feature, Int16 value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const JomClassFeatureLevel& feature, Int32 value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const JomClassFeatureLevel& feature, UInt32 value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const JomClassFeatureLevel& feature, Int64 value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const JomClassFeatureLevel& feature, UInt64 value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const JomClassFeatureLevel& feature, const DskObjectId* pValue, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const JomClassFeatureLevel& feature, const ShortDskObjectId* pValue, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const JomClassFeatureLevel& feature, const DskObject* pValue, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const JomClassFeatureLevel& feature, const DskObject& value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const JomClassFeatureLevel& feature, const DskParam* pValue, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const JomClassFeatureLevel& feature, const DskPoint* pValue, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const JomClassFeatureLevel& feature, const DskTimeStamp* pValue, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const JomClassFeatureLevel& feature, const DskTimeStampInterval* pValue, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const JomClassFeatureLevel& feature, const DskTimeStampOffset* pValue, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const JomClassFeatureLevel& feature, Float value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const JomClassFeatureLevel& feature, Real value, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const JomClassFeatureLevel& feature, const DskDecimal* pValue, LineNumber line = 0) const;
			int		setProperty(const DskBuffer*, const JomClassFeatureLevel& feature, const DskMemoryAddress* pValue, LineNumber line = 0) const;

			int		setDateProperty(const DskBuffer*, const JomClassFeatureLevel& feature, DskDate value, LineNumber line = 0) const;
			int		setTimeProperty(const DskBuffer*, const JomClassFeatureLevel& feature, DskTime value, LineNumber line = 0) const;
			int		setBinaryProperty(const DskBuffer*, const JomClassFeatureLevel& feature, const BYTE* pValue, PropertyLen length, LineNumber line = 0) const;
			int		setUInt16Property(const DskBuffer*, const JomClassFeatureLevel& feature, UInt16 value, LineNumber line = 0) const;
#ifdef JADESTR_TYPEDEFS_DEFINED
			int		setJadeStringProperty(const DskBuffer*, const JomClassFeatureLevel& feature, String* pValue, LineNumber line = 0) const;
			int		setJadeStringUtf8Property(const DskBuffer*, const JomClassFeatureLevel& feature, StringUtf8* pValue, LineNumber line = 0) const;
			int		setJadeBinaryProperty(const DskBuffer*, const JomClassFeatureLevel& feature, Binary* pValue, LineNumber line = 0) const;
#endif

			int		setProperty(ShortDskParam&, Character value, LineNumber line = 0) const;
			int		setProperty(ShortDskParam&, Boolean value, LineNumber line = 0) const;
			int		setProperty(ShortDskParam&, const Character value[], LineNumber line = 0) const;
			int		setProperty(ShortDskParam&, bool value, LineNumber line = 0) const;
			int		setProperty(ShortDskParam&, Int32 value, LineNumber line = 0) const;
			int		setProperty(ShortDskParam&, UInt32 value, LineNumber line = 0) const;
			int		setProperty(ShortDskParam&, Int64 value, LineNumber line = 0) const;
			int		setProperty(ShortDskParam&, UInt64 value, LineNumber line = 0) const;
			int		setProperty(ShortDskParam&, const ShortDskObjectId* pValue, LineNumber line = 0) const;
			int		setProperty(ShortDskParam&, const OidKey* pValue, LineNumber line = 0) const;
			int		setProperty(ShortDskParam&, const DskObject* pValue, LineNumber line = 0) const;
			int		setProperty(ShortDskParam&, const DskObject& value, LineNumber line = 0) const;

#ifdef JADESTR_TYPEDEFS_DEFINED
			int		setJadeStringProperty(ShortDskParam& prop, String* pValue, LineNumber line = 0) const;
			int		setJadeStringUtf8Property(ShortDskParam& prop, StringUtf8* pValue, LineNumber line = 0) const;
			int		setJadeBinaryProperty(ShortDskParam& prop, Binary* pValue, LineNumber line = 0) const;
#endif

			int		getProperty(const Character name[], Character value[], LineNumber line = 0) const;
			int		getProperty(const Character name[], Character value[], PropertyLen buffSize, LineNumber line) const;
			int		getProperty(const Character name[], Boolean* pValue, LineNumber line = 0) const;
			int		getProperty(const Character name[], bool* pValue, LineNumber line = 0) const;
			int		getProperty(const Character name[], Byte* pValue, LineNumber line = 0) const;
			int		getProperty(const Character name[], Int16* pValue, LineNumber line = 0) const;
			int		getProperty(const Character name[], Int32* pValue, LineNumber line = 0) const;
			int		getProperty(const Character name[], UInt32* pValue, LineNumber line = 0) const;
			int		getProperty(const Character name[], Int64* pValue, LineNumber line = 0) const;
			int		getProperty(const Character name[], UInt64* pValue, LineNumber line = 0) const;
			int		getProperty(const Character name[], DskObjectId* pValue, LineNumber line = 0) const;
			int		getProperty(const Character name[], ShortDskObjectId* pValue, LineNumber line = 0) const;
			int		getProperty(const Character name[], OidKey* pValue, LineNumber line = 0) const;
			int		getProperty(const Character name[], DskObject& value, LineNumber line = 0) const;
			int		getProperty(const Character name[], DskParam* pValue, LineNumber line = 0) const;
			int		getProperty(const Character name[], DskPoint* pValue, LineNumber line = 0) const;
			int		getProperty(const Character name[], DskTimeStamp* pValue, LineNumber line = 0) const;
			int		getProperty(const Character name[], DskTimeStampInterval* pValue, LineNumber line = 0) const;
			int		getProperty(const Character name[], DskTimeStampOffset* pValue, LineNumber line = 0) const;
			int		getProperty(const Character name[], Float* pValue, LineNumber line = 0) const;
			int		getProperty(const Character name[], Real* pValue, LineNumber line = 0) const;
			int		getProperty(const Character name[], DskDecimal* pValue, LineNumber line = 0) const;
			int		getProperty(const Character name[], DskMemoryAddress* pValue, LineNumber line = 0) const;

			int		getDateProperty(const Character name[], DskDate* pValue, LineNumber line = 0) const;
			int		getTimeProperty(const Character name[], DskTime* pValue, LineNumber line = 0) const;
			int		getBinaryProperty(const Character name[], BYTE* pValue, PropertyLen* pLengthInOut, LineNumber line = 0) const;
			int		getCharProperty(const Character name[], Character* pValue, LineNumber line = 0) const;
			int		getUInt16Property(const Character name[], UInt16* pValue, LineNumber line = 0) const;
#ifdef JADESTR_TYPEDEFS_DEFINED
			int		getJadeStringProperty(const Character name[], String* pValue, LineNumber line = 0) const;
			int		getJadeStringUtf8Property(const Character name[], StringUtf8* pValue, LineNumber line = 0) const;
			int		getJadeBinaryProperty(const Character name[], Binary* pValue, LineNumber line = 0) const;
#endif

			int		getProperty(const DskBuffer*, const Character name[], Character value[], LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const Character name[], Character value[], PropertyLen buffSize, LineNumber line) const;
			int		getProperty(const DskBuffer*, const Character name[], Boolean* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const Character name[], bool* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const Character name[], Byte* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const Character name[], Int16* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const Character name[], Int32* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const Character name[], UInt32* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const Character name[], Int64* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const Character name[], UInt64* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const Character name[], DskObjectId* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const Character name[], ShortDskObjectId* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const Character name[], DskObject& value, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const Character name[], DskParam* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const Character name[], DskPoint* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const Character name[], DskTimeStamp* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const Character name[], DskTimeStampInterval* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const Character name[], DskTimeStampOffset* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const Character name[], Float* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const Character name[], Real* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const Character name[], DskDecimal* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const Character name[], DskMemoryAddress* pValue, LineNumber line = 0) const;

			int		getDateProperty(const DskBuffer*, const Character name[], DskDate* pValue, LineNumber line = 0) const;
			int		getTimeProperty(const DskBuffer*, const Character name[], DskTime* pValue, LineNumber line = 0) const;
			int		getBinaryProperty(const DskBuffer*, const Character name[], BYTE* pValue, PropertyLen* pLength, LineNumber line = 0) const;
			int		getCharProperty(const DskBuffer*, const Character name[], Character* pValue, LineNumber line = 0) const;
			int		getUInt16Property(const DskBuffer*, const Character name[], UInt16* pValue, LineNumber line = 0) const;
#ifdef JADESTR_TYPEDEFS_DEFINED
			int		getJadeStringProperty(const DskBuffer*, const Character name[], String* pValue, LineNumber line = 0) const;
			int		getJadeStringUtf8Property(const DskBuffer*, const Character name[], StringUtf8* pValue, LineNumber line = 0) const;
			int		getJadeBinaryProperty(const DskBuffer*, const Character name[], Binary* pValue, LineNumber line = 0) const;
#endif
			int		getOidProperty(const DskBuffer*, const Character name[], DskObjectId*, LineNumber line = 0) const;

			int		getProperty(ClassNumber cNo, FeatureNum mNo, Character value[], LineNumber line = 0) const;
			int		getProperty(ClassNumber cNo, FeatureNum mNo, Character value[], PropertyLen buffSize, LineNumber line) const;
			int		getProperty(ClassNumber cNo, FeatureNum mNo, Boolean* pValue, LineNumber line = 0) const;
			int		getProperty(ClassNumber cNo, FeatureNum mNo, bool* pValue, LineNumber line = 0) const;
			int		getProperty(ClassNumber cNo, FeatureNum mNo, Byte* pValue, LineNumber line = 0) const;
			int		getProperty(ClassNumber cNo, FeatureNum mNo, Int16* pValue, LineNumber line = 0) const;
			int		getProperty(ClassNumber cNo, FeatureNum mNo, Int32* pValue, LineNumber line = 0) const;
			int		getProperty(ClassNumber cNo, FeatureNum mNo, UInt32* pValue, LineNumber line = 0) const;
			int		getProperty(ClassNumber cNo, FeatureNum mNo, Int64* pValue, LineNumber line = 0) const;
			int		getProperty(ClassNumber cNo, FeatureNum mNo, UInt64* pValue, LineNumber line = 0) const;
			int		getProperty(ClassNumber cNo, FeatureNum mNo, DskObjectId* pValue, LineNumber line = 0) const;
			int		getProperty(ClassNumber cNo, FeatureNum mNo, ShortDskObjectId* pValue, LineNumber line = 0) const;
			int		getProperty(ClassNumber cNo, FeatureNum mNo, OidKey* pValue, LineNumber line = 0) const;
			int		getProperty(ClassNumber cNo, FeatureNum mNo, DskObject& value, LineNumber line = 0) const;
			int		getProperty(ClassNumber cNo, FeatureNum mNo, DskParam* pValue, LineNumber line = 0) const;
			int		getProperty(ClassNumber cNo, FeatureNum mNo, DskPoint* pValue, LineNumber line = 0) const;
			int		getProperty(ClassNumber cNo, FeatureNum mNo, DskTimeStamp* pValue, LineNumber line = 0) const;
			int		getProperty(ClassNumber cNo, FeatureNum mNo, DskTimeStampInterval* pValue, LineNumber line = 0) const;
			int		getProperty(ClassNumber cNo, FeatureNum mNo, DskTimeStampOffset* pValue, LineNumber line = 0) const;
			int		getProperty(ClassNumber cNo, FeatureNum mNo, Float* pValue, LineNumber line = 0) const;
			int		getProperty(ClassNumber cNo, FeatureNum mNo, Real* pValue, LineNumber line = 0) const;
			int		getProperty(ClassNumber cNo, FeatureNum mNo, DskDecimal* pValue, LineNumber line = 0) const;
			int		getProperty(ClassNumber cNo, FeatureNum mNo, DskMemoryAddress* pValue, LineNumber line = 0) const;

			int		getDateProperty(ClassNumber cNo, FeatureNum mNo, DskDate* pValue, LineNumber line = 0) const;
			int		getTimeProperty(ClassNumber cNo, FeatureNum mNo, DskTime* pValue, LineNumber line = 0) const;
			int		getBinaryProperty(ClassNumber cNo, FeatureNum mNo, BYTE* pValue, PropertyLen* pLengthInOut, LineNumber line = 0) const;
			int		getCharProperty(ClassNumber cNo, FeatureNum mNo, Character* pValue, LineNumber line = 0) const;
			int		getUInt16Property(ClassNumber cNo, FeatureNum mNo, UInt16* pValue, LineNumber line = 0) const;
#ifdef JADESTR_TYPEDEFS_DEFINED
			int		getJadeStringProperty(ClassNumber cNo, FeatureNum mNo, String* pValue, LineNumber line = 0) const;
			int		getJadeStringUtf8Property(ClassNumber cNo, FeatureNum mNo, StringUtf8* pValue, LineNumber line = 0) const;
			int		getJadeBinaryProperty(ClassNumber cNo, FeatureNum mNo, Binary* pValue, LineNumber line = 0) const;
#endif

			int		getProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, Character value[], LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, Character value[], PropertyLen buffSize, LineNumber line) const;
			int		getProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, Boolean* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, bool* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, Byte* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, Int16* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, Int32* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, UInt32* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, Int64* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, UInt64* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, DskObjectId* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, ShortDskObjectId* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, DskObject& value, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, DskParam* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, DskPoint* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, DskTimeStamp* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, DskTimeStampInterval* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, DskTimeStampOffset* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, Float* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, Real* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, DskDecimal* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, DskMemoryAddress* pValue, LineNumber line = 0) const;

			int		getDateProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, DskDate* pValue, LineNumber line = 0) const;
			int		getTimeProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, DskTime* pValue, LineNumber line = 0) const;
			int		getBinaryProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, BYTE* pValue, PropertyLen* pLength, LineNumber line = 0) const;
			int		getCharProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, Character* pValue, LineNumber line = 0) const;
			int		getUInt16Property(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, UInt16* pValue, LineNumber line = 0) const;
#ifdef JADESTR_TYPEDEFS_DEFINED
			int		getJadeStringProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, String* pValue, LineNumber line = 0) const;
			int		getJadeStringUtf8Property(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, StringUtf8* pValue, LineNumber line = 0) const;
			int		getJadeBinaryProperty(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, Binary* pValue, LineNumber line = 0) const;
#endif

			int		getProperty(const JomClassFeatureLevel& feature, Character value[], LineNumber line = 0) const;
			int		getProperty(const JomClassFeatureLevel& feature, Character value[], PropertyLen buffSize, LineNumber line) const;
			int		getProperty(const JomClassFeatureLevel& feature, Boolean* pValue, LineNumber line = 0) const;
			int		getProperty(const JomClassFeatureLevel& feature, bool* pValue, LineNumber line = 0) const;
			int		getProperty(const JomClassFeatureLevel& feature, Byte* pValue, LineNumber line = 0) const;
			int		getProperty(const JomClassFeatureLevel& feature, Int16* pValue, LineNumber line = 0) const;
			int		getProperty(const JomClassFeatureLevel& feature, Int32* pValue, LineNumber line = 0) const;
			int		getProperty(const JomClassFeatureLevel& feature, UInt32* pValue, LineNumber line = 0) const;
			int		getProperty(const JomClassFeatureLevel& feature, Int64* pValue, LineNumber line = 0) const;
			int		getProperty(const JomClassFeatureLevel& feature, UInt64* pValue, LineNumber line = 0) const;
			int		getProperty(const JomClassFeatureLevel& feature, DskObjectId* pValue, LineNumber line = 0) const;
			int		getProperty(const JomClassFeatureLevel& feature, ShortDskObjectId* pValue, LineNumber line = 0) const;
			int		getProperty(const JomClassFeatureLevel& feature, OidKey* pValue, LineNumber line = 0) const;
			int		getProperty(const JomClassFeatureLevel& feature, DskObject& value, LineNumber line = 0) const;
			int		getProperty(const JomClassFeatureLevel& feature, PDskObject& pValue, LineNumber line = 0) const;
			int		getProperty(const JomClassFeatureLevel& feature, DskParam* pValue, LineNumber line = 0) const;
			int		getProperty(const JomClassFeatureLevel& feature, DskPoint* pValue, LineNumber line = 0) const;
			int		getProperty(const JomClassFeatureLevel& feature, DskTimeStamp* pValue, LineNumber line = 0) const;
			int		getProperty(const JomClassFeatureLevel& feature, DskTimeStampInterval* pValue, LineNumber line = 0) const;
			int		getProperty(const JomClassFeatureLevel& feature, DskTimeStampOffset* pValue, LineNumber line = 0) const;
			int		getProperty(const JomClassFeatureLevel& feature, Float* pValue, LineNumber line = 0) const;
			int		getProperty(const JomClassFeatureLevel& feature, Real* pValue, LineNumber line = 0) const;
			int		getProperty(const JomClassFeatureLevel& feature, DskDecimal* pValue, LineNumber line = 0) const;
			int		getProperty(const JomClassFeatureLevel& feature, DskMemoryAddress* pValue, LineNumber line = 0) const;

			int		getDateProperty(const JomClassFeatureLevel& feature, DskDate* pValue, LineNumber line = 0) const;
			int		getTimeProperty(const JomClassFeatureLevel& feature, DskTime* pValue, LineNumber line = 0) const;
			int		getBinaryProperty(const JomClassFeatureLevel& feature, BYTE* pValue, PropertyLen* pLengthInOut, LineNumber line = 0) const;
			int		getCharProperty(const JomClassFeatureLevel& feature, Character* pValue, LineNumber line = 0) const;
			int		getUInt16Property(const JomClassFeatureLevel& feature, UInt16* pValue, LineNumber line = 0) const;
#ifdef JADESTR_TYPEDEFS_DEFINED
			int		getJadeStringProperty(const JomClassFeatureLevel& feature, String* pValue, LineNumber line = 0) const;
			int		getJadeStringUtf8Property(const JomClassFeatureLevel& feature, StringUtf8* pValue, LineNumber line = 0) const;
			int		getJadeBinaryProperty(const JomClassFeatureLevel& feature, Binary* pValue, LineNumber line = 0) const;
#endif

			int		getProperty(const DskBuffer*, const JomClassFeatureLevel& feature, Character value[], LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const JomClassFeatureLevel& feature, Character value[], PropertyLen buffSize, LineNumber line) const;
			int		getProperty(const DskBuffer*, const JomClassFeatureLevel& feature, Boolean* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const JomClassFeatureLevel& feature, bool* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const JomClassFeatureLevel& feature, Byte* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const JomClassFeatureLevel& feature, Int16* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const JomClassFeatureLevel& feature, Int32* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const JomClassFeatureLevel& feature, UInt32* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const JomClassFeatureLevel& feature, Int64* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const JomClassFeatureLevel& feature, UInt64* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const JomClassFeatureLevel& feature, DskObjectId* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const JomClassFeatureLevel& feature, ShortDskObjectId* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const JomClassFeatureLevel& feature, DskObject& value, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const JomClassFeatureLevel& feature, DskParam* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const JomClassFeatureLevel& feature, DskPoint* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const JomClassFeatureLevel& feature, DskTimeStamp* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const JomClassFeatureLevel& feature, DskTimeStampInterval* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const JomClassFeatureLevel& feature, DskTimeStampOffset* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const JomClassFeatureLevel& feature, Float* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const JomClassFeatureLevel& feature, Real* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const JomClassFeatureLevel& feature, DskDecimal* pValue, LineNumber line = 0) const;
			int		getProperty(const DskBuffer*, const JomClassFeatureLevel& feature, DskMemoryAddress* pValue, LineNumber line = 0) const;

			int		getDateProperty(const DskBuffer*, const JomClassFeatureLevel& feature, DskDate* pValue, LineNumber line = 0) const;
			int		getTimeProperty(const DskBuffer*, const JomClassFeatureLevel& feature, DskTime* pValue, LineNumber line = 0) const;
			int		getBinaryProperty(const DskBuffer*, const JomClassFeatureLevel& feature, BYTE* pValue, PropertyLen* pLength, LineNumber line = 0) const;
			int		getCharProperty(const DskBuffer*, const JomClassFeatureLevel& feature, Character* pValue, LineNumber line = 0) const;
			int		getUInt16Property(const DskBuffer*, const JomClassFeatureLevel& feature, UInt16* pValue, LineNumber line = 0) const;
#ifdef JADESTR_TYPEDEFS_DEFINED
			int		getJadeStringProperty(const DskBuffer*, const JomClassFeatureLevel& feature, String* pValue, LineNumber line = 0) const;
			int		getJadeStringUtf8Property(const DskBuffer*, const JomClassFeatureLevel& feature, StringUtf8* pValue, LineNumber line = 0) const;
			int		getJadeBinaryProperty(const DskBuffer*, const JomClassFeatureLevel& feature, Binary* pValue, LineNumber line = 0) const;
#endif
			int		getOidProperty(const DskBuffer*, const JomClassFeatureLevel& feature, DskObjectId* pValue, LineNumber line = 0) const;

			int		getProperty(ShortDskParam&, Character value[], LineNumber line = 0) const;
			int		getProperty(ShortDskParam&, Boolean* pValue, LineNumber line = 0) const;
			int		getProperty(ShortDskParam&, bool* pValue, LineNumber line) const;
			int		getProperty(ShortDskParam&, Byte* pValue, LineNumber line) const;
			int		getProperty(ShortDskParam&, Int16* pValue, LineNumber line = 0) const;
			int		getProperty(ShortDskParam&, Int32* pValue, LineNumber line = 0) const;
			int		getProperty(ShortDskParam&, UInt32* pValue, LineNumber line = 0) const;
			int		getProperty(ShortDskParam&, Int64* pValue, LineNumber line = 0) const;
			int		getProperty(ShortDskParam&, UInt64* pValue, LineNumber line = 0) const;
			int		getProperty(ShortDskParam&, DskObjectId* pValue, LineNumber line = 0) const;
			int		getProperty(ShortDskParam&, ShortDskObjectId* pValue, LineNumber line = 0) const;
			int		getProperty(ShortDskParam&, OidKey* pValue, LineNumber line = 0) const;
			int		getProperty(ShortDskParam&, DskObject& value, LineNumber line = 0) const;

#ifdef JADESTR_TYPEDEFS_DEFINED
			int		getJadeStringProperty(ShortDskParam& prop, String* pValue, LineNumber line = 0) const;
			int		getJadeStringUtf8Property(ShortDskParam& prop, StringUtf8* pValue, LineNumber line = 0) const;
			int		getJadeBinaryProperty(ShortDskParam& prop, Binary* pValue, LineNumber line = 0) const;
#endif

			int		sendMsg(const Character message[], DskParam* pParams = nullptr, DskParam* pReturn = nullptr, LineNumber line = 0) const;
			int		sendMsg(const Character message[], Character string[], LineNumber line = 0) const;
			int		sendMsg(const Character message[], Integer n, LineNumber line) const;		// line number is required to avoid ambiguity with sendMsg("string", __LINE__)
			int		sendMsg(const Character message[], UInteger n, LineNumber line) const;		// line number is required to avoid ambiguity with sendMsg("string", __LINE__)
			int		sendMsg(const Character message[], Character c, LineNumber line = 0) const;
			int		sendMsg(const Character message[], Boolean b, LineNumber line = 0) const;
			int		sendMsg(const Character message[], bool b, LineNumber line = 0) const;
			int		sendMsg(const Character message[], const DskObject* pObj, LineNumber line = 0) const;
			int		sendMsg(const Character message[], DskObject* pObj1, DskObject* pObj2, LineNumber line = 0) const;
			int		sendMsg(const Character message[], DskObject* pObj, DskObject& o, LineNumber line = 0) const;
			int		sendMsg(const Character message[], DskObject& o, LineNumber line = 0) const;
			int		sendMsg(const Character message[], const DskObjectId& o, LineNumber line = 0) const;

			int		sendMsg(const DskBuffer*, const Character message[], DskParam* pParams = nullptr, DskParam* pReturn = nullptr, LineNumber line = 0) const;
			int		sendMsg(const DskBuffer*, const Character message[], Character string[], LineNumber line = 0) const;
			int		sendMsg(const DskBuffer*, const Character message[], Integer n, LineNumber line) const;			// line number is required to avoid ambiguity with sendMsg("string", __LINE__)
			int		sendMsg(const DskBuffer*, const Character message[], UInteger n, LineNumber line) const;		// line number is required to avoid ambiguity with sendMsg("string", __LINE__)
			int		sendMsg(const DskBuffer*, const Character message[], Character c, LineNumber line = 0) const;
			int		sendMsg(const DskBuffer*, const Character message[], Boolean b, LineNumber line = 0) const;
			int		sendMsg(const DskBuffer*, const Character message[], bool b, LineNumber line = 0) const;
			int		sendMsg(const DskBuffer*, const Character message[], const DskObject* pObj, LineNumber line = 0) const;
			int		sendMsg(const DskBuffer*, const Character message[], DskObject* pObj1, DskObject* pObj2, LineNumber line = 0) const;
			int		sendMsg(const DskBuffer*, const Character message[], DskObject* pObj, DskObject& o, LineNumber line = 0) const;
			int		sendMsg(const DskBuffer*, const Character message[], DskObject& o, LineNumber line = 0) const;
			int		sendMsg(const DskBuffer*, const Character message[], const DskObjectId& o, LineNumber line = 0) const;

			int		sendMsg(ClassNumber cNo, FeatureNum mNo, DskParam* pParams = nullptr, DskParam* pReturn = nullptr, LineNumber line = 0) const;
			int		sendMsg(ClassNumber cNo, FeatureNum mNo, Character string[], LineNumber line = 0) const;
			int		sendMsg(ClassNumber cNo, FeatureNum mNo, Integer n, LineNumber line) const;			// line number is required to avoid ambiguity with sendMsg("string", __LINE__)
			int		sendMsg(ClassNumber cNo, FeatureNum mNo, UInteger n, LineNumber line) const;		// line number is required to avoid ambiguity with sendMsg("string", __LINE__)
			int		sendMsg(ClassNumber cNo, FeatureNum mNo, Character c, LineNumber line = 0) const;
			int		sendMsg(ClassNumber cNo, FeatureNum mNo, Boolean b, LineNumber line = 0) const;
			int		sendMsg(ClassNumber cNo, FeatureNum mNo, bool b, LineNumber line = 0) const;
			int		sendMsg(ClassNumber cNo, FeatureNum mNo, const DskObject* pObj, LineNumber line = 0) const;
			int		sendMsg(ClassNumber cNo, FeatureNum mNo, DskObject* pObj1, DskObject* pObj2, LineNumber line = 0) const;
			int		sendMsg(ClassNumber cNo, FeatureNum mNo, DskObject* pObj, DskObject& o, LineNumber line = 0) const;
			int		sendMsg(ClassNumber cNo, FeatureNum mNo, DskObject& o, LineNumber line = 0) const;
			int		sendMsg(ClassNumber cNo, FeatureNum mNo, const DskObjectId& o, LineNumber line = 0) const;

			int		sendMsg(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, DskParam* pParams = nullptr, DskParam* pReturn = nullptr, LineNumber line = 0) const;
			int		sendMsg(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, Character string[], LineNumber line = 0) const;
			int		sendMsg(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, Integer n, LineNumber line) const;		// line number is required to avoid ambiguity with sendMsg("string", __LINE__)
			int		sendMsg(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, UInteger n, LineNumber line) const;		// line number is required to avoid ambiguity with sendMsg("string", __LINE__)
			int		sendMsg(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, Character c, LineNumber line = 0) const;
			int		sendMsg(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, Boolean b, LineNumber line = 0) const;
			int		sendMsg(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, bool b, LineNumber line = 0) const;
			int		sendMsg(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, const DskObject* pObj, LineNumber line = 0) const;
			int		sendMsg(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, DskObject* pObj1, DskObject* pObj2, LineNumber line = 0) const;
			int		sendMsg(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, DskObject* pObj, DskObject& o, LineNumber line = 0) const;
			int		sendMsg(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, DskObject& o, LineNumber line = 0) const;
			int		sendMsg(const DskBuffer*, ClassNumber cNo, FeatureNum mNo, const DskObjectId& o, LineNumber line = 0) const;

			int		sendMsg(const JomClassFeatureLevel& feature, DskParam* pParams = nullptr, DskParam* pReturn = nullptr, LineNumber line = 0) const;
			int		sendMsg(const JomClassFeatureLevel& feature, Character string[], LineNumber line = 0) const;
			int		sendMsg(const JomClassFeatureLevel& feature, Integer n, LineNumber line) const;			// line number is required to avoid ambiguity with sendMsg("string", __LINE__)
			int		sendMsg(const JomClassFeatureLevel& feature, UInteger n, LineNumber line) const;		// line number is required to avoid ambiguity with sendMsg("string", __LINE__)
			int		sendMsg(const JomClassFeatureLevel& feature, Character c, LineNumber line = 0) const;
			int		sendMsg(const JomClassFeatureLevel& feature, Boolean b, LineNumber line = 0) const;
			int		sendMsg(const JomClassFeatureLevel& feature, bool b, LineNumber line = 0) const;
			int		sendMsg(const JomClassFeatureLevel& feature, const DskObject* pObj, LineNumber line = 0) const;
			int		sendMsg(const JomClassFeatureLevel& feature, DskObject* pObj1, DskObject* pObj2, LineNumber line = 0) const;
			int		sendMsg(const JomClassFeatureLevel& feature, DskObject* pObj, DskObject& o, LineNumber line = 0) const;
			int		sendMsg(const JomClassFeatureLevel& feature, DskObject& o, LineNumber line = 0) const;
			int		sendMsg(const JomClassFeatureLevel& feature, const DskObjectId& o, LineNumber line = 0) const;

			int		sendMsg(const DskBuffer*, const JomClassFeatureLevel& feature, DskParam* pParams = nullptr, DskParam* pReturn = nullptr, LineNumber line = 0) const;
			int		sendMsg(const DskBuffer*, const JomClassFeatureLevel& feature, Character string[], LineNumber line = 0) const;
			int		sendMsg(const DskBuffer*, const JomClassFeatureLevel& feature, Integer n, LineNumber line) const;		// line number is required to avoid ambiguity with sendMsg("string", __LINE__)
			int		sendMsg(const DskBuffer*, const JomClassFeatureLevel& feature, UInteger n, LineNumber line) const;		// line number is required to avoid ambiguity with sendMsg("string", __LINE__)
			int		sendMsg(const DskBuffer*, const JomClassFeatureLevel& feature, Character c, LineNumber line = 0) const;
			int		sendMsg(const DskBuffer*, const JomClassFeatureLevel& feature, Boolean b, LineNumber line = 0) const;
			int		sendMsg(const DskBuffer*, const JomClassFeatureLevel& feature, bool b, LineNumber line = 0) const;
			int		sendMsg(const DskBuffer*, const JomClassFeatureLevel& feature, const DskObject* pObj, LineNumber line = 0) const;
			int		sendMsg(const DskBuffer*, const JomClassFeatureLevel& feature, DskObject* pObj1, DskObject* pObj2, LineNumber line = 0) const;
			int		sendMsg(const DskBuffer*, const JomClassFeatureLevel& feature, DskObject* pObj, DskObject& o, LineNumber line = 0) const;
			int		sendMsg(const DskBuffer*, const JomClassFeatureLevel& feature, DskObject& o, LineNumber line = 0) const;
			int		sendMsg(const DskBuffer*, const JomClassFeatureLevel& feature, const DskObjectId& o, LineNumber line = 0) const;

			int		sendMsg(const DskBuffer*, DskParam*, DskParam* pParams = nullptr, DskParam* pReturn = nullptr, LineNumber line = 0) const;
			int		sendMsg(ShortDskParam&, DskParam* pParams = nullptr, DskParam* pReturn = nullptr, LineNumber line = 0) const;

			int		sendCollBlockMsg(const Character message[], const DskObjectId* pHdrOid, CollBlockFlags flags, DskParam* pParams, DskParam* pReturn, LineNumber line = 0) const;
			int		sendCollBlockMsg(ShortDskParam&, const DskObjectId* pHdrOid, CollBlockFlags flags, DskParam* pParams, DskParam* pReturn = nullptr, LineNumber line = 0) const;

#if defined(DB_METHOD_OPS)
			// enum type safe overloads for internal use
			// operation is bound to method category via the signature
			int		sendDbMsg(DbObjectOperation, DskParam* pParams = nullptr, DskParam* pReturn = nullptr, LineNumber line = 0) const;
			int		sendDbMsg(DbAdminOperation, DskParam* pParams = nullptr, DskParam* pReturn = nullptr, LineNumber line = 0) const;
			int		sendDbMsg(DbFileAdminOperation, DskParam* pParams = nullptr, DskParam* pReturn = nullptr, LineNumber line = 0) const;
			int		sendDbMsg(DbReorgOperation, DskParam* pParams = nullptr, DskParam* pReturn = nullptr, LineNumber line = 0) const;
			int		sendDbMsg(SDSDatabaseOperation, DskParam* pParams = nullptr, DskParam* pReturn = nullptr, LineNumber line = 0) const;
			int		sendDbMsg(SDSOperation, DskParam* pParams = nullptr, DskParam* pReturn = nullptr, LineNumber line = 0) const;
			int		sendDbMsg(RPSOperation, DskParam* pParams = nullptr, DskParam* pReturn = nullptr, LineNumber line = 0) const;
			int		sendDbMsg(GetStatisticsOperation, DskParam* pParams = nullptr, DskParam* pReturn = nullptr, LineNumber line = 0) const;
			int		sendDbMsg(DbFilePartOperation, DskParam* pParams = nullptr, DskParam* pReturn = nullptr, LineNumber line = 0) const;
			int		sendDbMsg(DiagDbOperation, DskParam* pParams = nullptr, DskParam* pReturn = nullptr, LineNumber line = 0) const;
			int		sendDbMsg(RDBReorgOperation, DskParam* pParams = nullptr, DskParam* pReturn = nullptr, LineNumber line = 0) const;
#endif
			int		valuesFromMsg(const Character message[], JomColl& coll, LineNumber line = 0) const;
			int		valuesFromProperty(const Character propertyName[], JomColl& coll, LineNumber line = 0) const;

			int		valuesFromMsg(const JomClassFeatureLevel& feature, JomColl& coll, LineNumber line = 0) const;
			int		valuesFromProperty(const JomClassFeatureLevel& feature, JomColl& coll, LineNumber line = 0) const;

			int		inheritMethod(DskParam* pParams = nullptr, DskParam* pReturn = nullptr) const;

	virtual	int		getClass(DskClass& klass, LineNumber line = 0) const;
	virtual int		getFile(DskDbFile& file) const;

			int		isVersioned(bool* pIsVersioned) const;
			int		isLatestVersion(bool* pIsLatestVersion) const;
			int		makeCurrentVersion();
			int		makeLatestVersionIfAny();
			int		makeVersionOf(DskObject* pNextObj) const;
			int		createVersion(DskObject* pNew) const;
			int		deletePriorVersions() const;
			int		getPriorVersionObject(DskObject* pVerObj) const;
			int		getNextVersionObject(DskObject* pVerObj) const;
			int		getVersion(VersionNum* pVersion) const;
	virtual int		getTimeStamp(UInt32* pTimeStamp) const;
	virtual int		getLatestObject(DskObject* pVerObj) const;
			int		getMetaDataParent(DskObject& parent) const;
			ObjectVersionState getParentVersionState() const;
			ObjectVersionState getVersionState() const;
			const Character* getVersionStateText() const;
			int		fullyQualifiedName(Character name[]) const;

			bool	isValid() const;
			bool	isLockedByMe() const;
			bool	isLockedByMeWith(LockType requiredType) const;

			bool	isPersistent() const;
			int		makePersistent();

			bool	isTransient() const;
			int		makeTransient();

			int		makeSharedTransient();
			bool	isSharedTransient() const;

			bool	isNonSharedTransient() const;

	//initialization messages
	virtual int		storeOnDisk() { return J_OK; }
};

class JOMOBJ_LINKAGE DskDeltaInfo : public DskObject
{
public:

	DskDeltaInfo(const DskObjectId* pOid) : DskObject(pOid) {}
	DskDeltaInfo(const ShortDskObjectId* pOid) : DskObject(pOid) {}
	DskDeltaInfo(ClassNumber classNo) : DskObject(classNo) {}
	DskDeltaInfo() : DskObject(DSKDELTAINFO) {}
	virtual ~DskDeltaInfo() {}

	// attributes:
	int				setDeltaId(const Character deltaId[]) const;
	int				getDeltaId(Character deltaId[]) const;

	// references:
	int				methods(JomColl& coll) const;

	// methods:
};

class JOMOBJ_LINKAGE DskSchemaEntity: public DskObject
{
public:

	DskSchemaEntity(const DskObjectId* pOid): DskObject(pOid) {}
	DskSchemaEntity(const ShortDskObjectId* pOid): DskObject(pOid) {}
	DskSchemaEntity(ClassNumber classNo): DskObject(classNo) {}
	DskSchemaEntity(): DskObject(DSKSCHEMAENTITY) {}
	virtual ~DskSchemaEntity() = default;

	// attributes:
	virtual int		setAbstract(bool abstract);
	virtual int		getAbstract(bool* pAbstract) const;
	virtual int		setAccess(AccessType access);
	virtual int		getAccess(AccessType* pAccess) const;
	virtual int		setModifiedTimeStamp(DskTimeStamp* pModifiedTimeStamp) override;
	virtual int		getModifiedTimeStamp(DskTimeStamp* pModifiedTimeStamp) const override;
	virtual int		setName(const Character name[]);
	virtual int		getName(Character name[], LineNumber line = 0) const;
	virtual int		setNumber(UInt16 number);
	virtual int		getNumber(UInt16* pNumber, LineNumber line = 0) const;
	virtual int		setNumber(Int32 number);
	virtual int		getNumber(Int32* pNumber, LineNumber line = 0) const;
	virtual int		setNumber(UInt32 number);
	virtual int		getNumber(UInt32* pNumber, LineNumber line = 0) const;
	virtual int		setPatchVersion(Int32 patchVersion) override;
	virtual int		getPatchVersion(Int32* pPatchVersion) const override;
	virtual int		setSubAccess(AccessType subAccess);
	virtual int		getSubAccess(AccessType* pSubAccess) const;
	virtual int		setSystemVersion(const Character systemVersion[]) override;
	virtual int		getSystemVersion(Character systemVersion[]) const override;
	virtual int		setModifiedBy(const Character[]) override;
	virtual int		getModifiedBy(Character[]) const override;
			int		setText(const Character text[]) const;
			int		getText(Character text[]) const;
			int		setDeprecated(Byte deprecated);
			int		getDeprecated(Byte* pDeprecated);
			int		setDeprecatedDescription(const Character deprecated[]);
#ifdef JADESTR_TYPEDEFS_DEFINED
			int		getDeprecatedDescription(String& deprecated) const;
#endif

	// references:
			int		setUserProfile(const DskUserProfile* pUserProfile) override;
			int		getUserProfile(DskUserProfile& userProfile) const override;

	// methods:
			int		getTextSize(UInt32* pTextSize) const;

			int		setDeprecated_DeprecatedFlag(bool deprecated);
			int		getDeprecated_DeprecatedFlag(bool* deprecated);
#ifdef JADESTR_TYPEDEFS_DEFINED
			int		strHistoryExtract(String* str) const;
#endif
			int		changeName(const Character newName[], const Character userCode[], const Character systemVersion[], Int32 patchVersion, const DskTimeStamp& modifiedTimeStamp, DskSet& methsChanged) const;
	virtual int		isOnlyInLatestSchemaVersion(bool* pFlag) const;
	virtual bool	canBeCheckedOut() const { return false; }

	// type aware wrapper for getNumber
	inline int		getNumber(PFormat* pFormat, LineNumber line = 0) const 
					{
						static_assert(sizeof(PFormat) == sizeof(UINT16), "has to be the same size");
						return getNumber((UInt16 *) pFormat, line);
					}
};

class JOMOBJ_LINKAGE DskConstantCategory : public DskSchemaEntity
{
public:

	DskConstantCategory(const DskObjectId* pOid) : DskSchemaEntity(pOid) {}
	DskConstantCategory(const ShortDskObjectId* pOid) : DskSchemaEntity(pOid) {}
	DskConstantCategory(ClassNumber classNo) : DskSchemaEntity(classNo) {}
	DskConstantCategory() : DskSchemaEntity(DSKCONSTANTCATEGORY) {}
	virtual ~DskConstantCategory() {}

	// attributes:

	// references:
	int				setSchema(const DskSchema* pSchema) const;
	int				getSchema(DskSchema& schema) const;
	int				addConstant(DskGlobalConstant* pCon) const;
	int				constants(JomColl& coll) const;

	// methods:
};

class JOMOBJ_LINKAGE DskFeature : public DskSchemaEntity
{
public:

	DskFeature(const DskObjectId* pOid) : DskSchemaEntity(pOid) {}
	DskFeature(const ShortDskObjectId* pOid) : DskSchemaEntity(pOid) {}
	DskFeature(ClassNumber classNo) : DskSchemaEntity(classNo) {}
	DskFeature() : DskSchemaEntity(DSKFEATURE) {}
	virtual ~DskFeature() {}

	// attributes:

	// references:
	virtual	int		setSchemaType(const DskType* pSchemaType);
	virtual	int		getSchemaType(DskType& schemaType) const;
	virtual	int		getSchemaType(PDskType& pSchemaType) const;
	virtual	int		scriptRefs(JomColl& coll) const;
	virtual	int		setType(const DskType* pType);
	virtual	int		getType(DskType& type) const;
	virtual	int		getType(PDskType& pType) const;
	int				exposedClassRefs(JomColl& coll) const;
	int				relationalAttributeRefs(JomColl& coll) const;

	// methods:
	virtual	int		getSchemaTypeNumber(ClassNumber*) const;
	virtual	int		getSchema(DskSchema& schema) const;
	int				removeScriptRefs() const;
	int				purgeScriptRefs() const;
	int				markExposedListsForRegen(JomColl& markedLists) const;
	int				hasRelationalAttributeRefs(bool& hasRefs) const;
	int				isInBothTypeVersions(const DskType* pDskType, bool& inBothVersions) const;
	int				areVersionsCompatible(bool &areCompatible) const;
	int				isExposedFeature(bool& isExposed) const;
	int				calculateLevel(Level* pLevel) const;
	int				calculateLatestLevel(Level* pLevel) const;

	virtual	int		deleteSelf();
	virtual	bool	isDynamicProperty() const;
};

class JOMOBJ_LINKAGE DskProperty : public DskFeature
{
public:

	DskProperty(const DskObjectId* pOid) : DskFeature(pOid) {}
	DskProperty(const ShortDskObjectId* pOid) : DskFeature(pOid) {}
	DskProperty(ClassNumber classNo) : DskFeature(classNo) {}
	DskProperty() : DskFeature(DSKPROPERTY) {}
	virtual ~DskProperty() {}

	// attributes:
	virtual	int		setOrdinal(FeatureNum ordinal);
	virtual	int		getOrdinal(FeatureNum* pOrdinal) const;
	virtual int		setEmbedded(bool embedded);
	virtual int		getEmbedded(bool* pEmbedded) const;
	int				setHasControlInstance(bool hasControlInstance) const;
	int				getHasControlInstance(bool* pHasControlInstance) const;
	virtual int		setKey(bool key);
	virtual int		getKey(bool* pKey) const;
	int				setMappingCount(Integer mappingCount) const;
	int				getMappingCount(Integer* pMappingCount) const;
	virtual int		setRequired(bool required);
	virtual int		getRequired(bool* pRequired) const;
	virtual int		setNillable(bool nillable);
	virtual int		getNillable(bool* pNillable) const;
	virtual int		setSubId(SubID subId);
	virtual int		getSubId(SubID* pSubId) const;
	int				setUsedInCondition(bool val) const;
	int				getUsedInCondition(bool* pVal) const;
	virtual int		setVirtual(bool _virtual);
	virtual int		getVirtual(bool* pVirtual) const;
	virtual int		setIsHTMLProperty(bool html);
	virtual int		getIsHTMLProperty(bool* pHTML) const;

	// references:
	int				conditionRefs(JomColl& coll) const;
	int				keyRefs(JomColl& coll) const;
	int				keyPathRefs(JomColl& coll) const;
	int				exportedPropertyRefs(JomColl& coll) const;

	// methods:
	int				incrementMappingCount() const;
	int				decrementMappingCount() const;
	virtual int		getLength(PropertyLen* pLength) const;
	virtual int		calculateEmbeddedSize(PropertyLen* pLength) const;
	virtual int		calculateEmbeddedSizeForKey(PropertyLen* pLength) const;
	virtual int		isMapped(bool* pIsMapped) const;
	int				getMappingMethod(DskMethod & mappingMethod) const;
	int				getLocalMappingMethod(DskMethod & mappingMethod) const;
	virtual int		isOnlyInLatestSchemaVersion(bool* pFlag) const override;

	virtual bool	isAttribute() const;
	virtual bool	isReference() const;
	virtual bool	isPrimAttribute() const;
	virtual bool	isCompAttribute() const;
	virtual bool	isImplicitInverseRef() const;
	virtual bool	isExplicitInverseRef() const;
	virtual bool	isMemPrimAttribute() const { return false; }
	virtual bool	isMemImplicitInverseRef() const { return false; }
	virtual bool	isMemExplicitInverseRef() const { return false; }
	bool			isSlobOrBlob() const;

	int				hasKeyOrKeyPathRefs(bool* pHasRefs) const;
	int				isUsedAsKey(bool* pIsUsedAsKey) const;
	int				isUsedAsKeyUsePrior(bool* pIsUsedAsKey) const;
	int				resetKeyFlagIfNotKey();
	int				reorgCreateVersion(DskProperty & newPropertyVer) const;
	int				versionReferencedMethods() const;
	int				importedScriptRefs(JomColl& coll) const;

	void			setWsdlSubschemaHidden(bool val) const;
	bool			isWsdlSubschemaHidden() const;
	void			setIsBeingCloned(bool) const;
	bool			isBeingCloned() const;
	void			setInstancesDeleted(bool) const;
	bool			isInstancesDeleted() const;
};

class JOMOBJ_LINKAGE DskAttribute : public DskProperty
{
public:

	DskAttribute(const DskObjectId* pOid) : DskProperty(pOid) {}
	DskAttribute(const ShortDskObjectId* pOid) : DskProperty(pOid) {}
	DskAttribute(ClassNumber classNo) : DskProperty(classNo) {}
	DskAttribute() : DskProperty(DSKATTRIBUTE) {}
	virtual ~DskAttribute() {}

	// attributes:
	virtual int		setLength(PropertyLen length);
	virtual int		getLength(PropertyLen* pLength) const override;

	// references:

	// methods:
	bool			isAttribute() const override { return true; }
	bool			isReference() const override { return false; }
	bool			isImplicitInverseRef() const override { return false; }
	bool			isExplicitInverseRef() const override { return false; }
	virtual int		calculateEmbeddedSize(PropertyLen* pLength) const override;
	virtual int		calculateEmbeddedSizeForKey(PropertyLen* pLength) const override;
};

class JOMOBJ_LINKAGE DskPrimAttribute : public DskAttribute
{
public:

	DskPrimAttribute(const DskObjectId* pOid) : DskAttribute(pOid) {}
	DskPrimAttribute(const ShortDskObjectId* pOid) : DskAttribute(pOid) {}
	DskPrimAttribute(ClassNumber classNo) : DskAttribute(classNo) {}
	DskPrimAttribute() : DskAttribute(DSKPRIMATTRIBUTE) {}
	virtual ~DskPrimAttribute() {}

	// attributes:
	int				setPrecision(Precision precision) const;
	int				getPrecision(Precision* pPrecison) const;
	int				setScaleFactor(ScaleFactor scaleFactor) const;
	virtual int		getScaleFactor(ScaleFactor* pScaleFactor) const;

	// references:

	// methods:
	bool			isPrimAttribute() const override { return true; }
	bool			isCompAttribute() const override { return false; }
};

class JOMOBJ_LINKAGE DskCompAttribute : public DskAttribute
{
public:

	DskCompAttribute(const DskObjectId* pOid) : DskAttribute(pOid) {}
	DskCompAttribute(const ShortDskObjectId* pOid) : DskAttribute(pOid) {}
	DskCompAttribute(ClassNumber classNo) : DskAttribute(classNo) {}
	DskCompAttribute() : DskAttribute(DSKCOMPATTRIBUTE) {}
	virtual ~DskCompAttribute() {}

	// attributes:

	// references:

	// methods:
	bool			isPrimAttribute() const override { return false; }
	bool			isCompAttribute() const override { return true; }
};

class JOMOBJ_LINKAGE DskReference : public DskProperty
{
public:

	DskReference(const DskObjectId* pOid) : DskProperty(pOid) {}
	DskReference(const ShortDskObjectId* pOid) : DskProperty(pOid) {}
	DskReference(ClassNumber classNo) : DskProperty(classNo) {}
	DskReference() : DskProperty(DSKREFERENCE) {}
	virtual ~DskReference() {}

	// attributes:
	int				setConstraintChanged(bool constraintChanged) const;
	int				getConstraintChanged(bool* pConstraintChanged) const;

	// references:
	virtual	int		setConstraint(const DskMethod* pMethod);
	virtual	int		getConstraint(DskMethod& method) const;

	// methods:
	virtual int		getLength(PropertyLen* pLength) const override;
	virtual int		calculateEmbeddedSize(PropertyLen* pLength) const override;
	virtual int		calculateEmbeddedSizeForKey(PropertyLen* pLength) const override;

	bool			isReference() const override { return true; }
	bool			isAttribute() const override { return false; }
	bool			isPrimAttribute() const override { return false; }
	bool			isCompAttribute() const override { return false; }
};

class JOMOBJ_LINKAGE DskImplicitInverseRef : public DskReference
{
public:

	DskImplicitInverseRef(const DskObjectId* pOid) : DskReference(pOid) {}
	DskImplicitInverseRef(const ShortDskObjectId* pOid) : DskReference(pOid) {}
	DskImplicitInverseRef(ClassNumber classNo) : DskReference(classNo) {}
	DskImplicitInverseRef() : DskReference(DSKIMPLICITINVERSEREF) {}
	virtual ~DskImplicitInverseRef() {}

	// attributes:
	virtual int		setMemberTypeInverse(bool memberTypeInverse);
	virtual int		getMemberTypeInverse(bool* pMemberTypeInverse) const;

	// references:

	// methods:
	bool			isImplicitInverseRef() const override { return true; }
	bool			isExplicitInverseRef() const override { return false; }
};

class JOMOBJ_LINKAGE DskExplicitInverseRef : public DskReference
{
public:

	DskExplicitInverseRef(const DskObjectId* pOid) : DskReference(pOid) {}
	DskExplicitInverseRef(const ShortDskObjectId* pOid) : DskReference(pOid) {}
	DskExplicitInverseRef(ClassNumber classNo) : DskReference(classNo) {}
	DskExplicitInverseRef() : DskReference(DSKEXPLICITINVERSEREF) {}
	virtual ~DskExplicitInverseRef() {}

	// attributes:
	virtual int		setKind(ReferenceKind kind);
	virtual int		getKind(ReferenceKind* pKind) const;
	virtual int		setUpdateMode(InverseUpdateMode updateMode);
	virtual int		getUpdateMode(InverseUpdateMode* pUpdateMode) const;
	virtual	int		setAllowTransToPersistRef(bool allowTransToPersistRef);
	virtual	int		getAllowTransToPersistRef(bool* pAllowTransToPersistRef) const;
	virtual	int		setInverseNotRequired(bool inverseNotRequired);
	virtual	int		getInverseNotRequired(bool* pInverseNotRequired) const;

	// references:
	virtual int		inverses(JomColl& coll) const;

	// methods:
	int				getInverse(DskExplicitInverseRef* pInverseRef, DskInverse& inv) const;
	int				getInverseRefs(OrderedJomColl & inverseRefs) const;
	int				deleteInverse(DskInverse& inv, bool & done) const;
	int				structureChangedAddingInverse(DskInverse & inv, DskArray & versionedClasses) const;

	bool			isImplicitInverseRef() const override { return false; }
	bool			isExplicitInverseRef() const override { return true; }
};

class JOMOBJ_LINKAGE DskScript : public DskFeature
{
public:

	DskScript(const DskObjectId* pOid) : DskFeature(pOid) {}
	DskScript(const ShortDskObjectId* pOid) : DskFeature(pOid) {}
	DskScript(ClassNumber classNo) : DskFeature(classNo) {}
	DskScript() : DskFeature(DSKSCRIPT) {}
	virtual ~DskScript() {}

	// attributes:
	int				setErrorCode(UInt32 errorCode) const;
	int				getErrorCode(UInt32* pErrorCode) const;
	int				setErrorLength(UInt32 errorLength) const;
	int				getErrorLength(UInt32* pErrorLength) const;
	int				setErrorPosition(UInt32 errorPosition) const;
	int				getErrorPosition(UInt32* pErrorPosition) const;
	int				setSource(const Character source[]) const;
	int				getSource(Character source[]) const;
	virtual int		setStatus(UInt32 status);
	virtual int		getStatus(UInt32* pStatus) const;
	virtual	int		setStatusWithoutNotify(UInt32 status);
	virtual	int		setNotImplemented(bool notImpl);
	virtual int		getNotImplemented(bool* pNotImpl) const;

	// base implementation is always false, overridden by DskRoutine
	virtual bool	isEncryptedSource() const { return false; }

	// references:
	int				addInlineTypeUsage(const DskInlineTypeUsage* pInlineTypeUsage) const;
	int				inlineTypeUsages(JomColl& coll) const;

	// methods:
	int				getSourceSize(UInt32* pLength) const;
	UInt32			getSourceSize() const { UInt32 size; getSourceSize(&size); return size; }
	int				setError(UInt32 errorCode, UInt32 errorPosition, UInt32 errorLength) const;

	int				clearInlineTypeUsages() const;

	int				getEncryptedSourceSize(PropertyLen* pEncByteCntOut) const;
	int				getEncryptedSource(BYTE* pEncrypted, PropertyLen* pEncryptedLength) const;

	int				save(void* pRootNode) const;
};

class JOMOBJ_LINKAGE DskConstant : public DskScript
{
public:

	DskConstant(const DskObjectId* pOid) : DskScript(pOid) {}
	DskConstant(const ShortDskObjectId* pOid) : DskScript(pOid) {}
	DskConstant(ClassNumber classNo) : DskScript(classNo) {}
	DskConstant() : DskScript(DSKCONSTANT) {}
	virtual ~DskConstant() {}

	// attributes:
	int				setLength(PropertyLen length) const;
	int				getLength(PropertyLen* pLength) const;

	int				setPrecision(Precision precision) const;
	int				getPrecision(Precision* pPrecison) const;
	int				setScaleFactor(ScaleFactor scaleFactor) const;
	int				getScaleFactor(ScaleFactor* pScaleFactor) const;
	int				setValue(const ShortDskParam* pValue) const;
	int				getValue(ShortDskParam* pValue) const;

	// references:
	int				exportedConstantRefs(JomColl& coll) const;

	// methods:
	int				addConstantUsage(const DskConstant* pConstantUsage) const;
	int				addImportedConstantUsage(const DskJadeImportedConstant* pImpConstantUsage) const;
	int				constantRefs(JomColl& coll) const;
	int				constantUsages(JomColl& coll) const;
	int				importedConstantUsages(JomColl& coll) const;
	int				clearConstantUsages() const;	//also clears importedConstantUsages

	int				getValueLength(PropertyLen* pLen) const;
	int				importedScriptRefs(JomColl& coll) const;
};

class JOMOBJ_LINKAGE DskGlobalConstant : public DskConstant
{
public:

	DskGlobalConstant(const DskObjectId* pOid) : DskConstant(pOid) {}
	DskGlobalConstant(const ShortDskObjectId* pOid) : DskConstant(pOid) {}
	DskGlobalConstant(ClassNumber classNo) : DskConstant(classNo) {}
	DskGlobalConstant() : DskConstant(DSKGLOBALCONSTANT) {}
	virtual ~DskGlobalConstant() {}

	// attributes:

	// references:
	int				setCategory(const DskConstantCategory* pCategory) const;
	int				getCategory(DskConstantCategory& category) const;
	int				setSchema(const DskSchema* pSchema) const;
	int				getSchema(DskSchema& schema) const override;

	// methods:
};

class JOMOBJ_LINKAGE DskRoutine : public DskScript
{
public:

	DskRoutine(const DskObjectId* pOid) : DskScript(pOid) {}
	DskRoutine(const ShortDskObjectId* pOid) : DskScript(pOid) {}
	DskRoutine(ClassNumber classNo) : DskScript(classNo) {}
	DskRoutine() : DskScript(DSKROUTINE) {}
	virtual ~DskRoutine() {}

	// attributes:
	virtual int		setEntrypoint(const Character entrypoint[]);
	virtual int		getEntrypoint(Character entrypoint[]) const;
	virtual int		setExecutionLocation(ExecutionLocation executionLocation);
	virtual int		getExecutionLocation(ExecutionLocation* pExecutionLocation) const;
	virtual int		setOptions_EncryptedSource(bool setting);
	virtual int		getOptions_EncryptedSource(bool* setting) const;
	virtual int		setOptions_HasPseudoMethodCallParam(bool setting);
	virtual int		getOptions_HasPseudoMethodCallParam(bool* setting) const;
	virtual int		setOptions_IsTypeMethod(bool setting);
	virtual int		getOptions_IsTypeMethod(bool* setting) const;
	virtual int		setOptions_IsReceiverByReference(bool setting);
	virtual int		getOptions_IsReceiverByReference(bool* setting) const;
	virtual int		setOptions_IsGenerated(bool setting);
	virtual int		getOptions_IsGenerated(bool* setting) const;

	// overrides DskScript's always false implementation
	virtual bool	isEncryptedSource() const override { bool encrOption; getOptions_EncryptedSource(&encrOption); return encrOption; }

	// references:
	int				addFeatureUsage(const DskFeatureUsage* pFeatureUsage) const;
	int				delFeatureUsage(const DskFeatureUsage* pFeatureUsage) const;
	int				featureUsages(JomColl& coll) const;
	int				addKeyUsage(const DskKeyUsage* pKeyUsage) const;
	int				delKeyUsage(const DskKeyUsage* pKeyUsage) const;
	int				keyUsages(JomColl& coll) const;
	virtual int		setLibrary(const DskLibrary* pLibrary);
	virtual int		getLibrary(DskLibrary& library) const;
	virtual int		addParameter(const DskParameter* pParameter);
	int				delParameter(const DskParameter* pParameter) const;
	virtual int		parameters(JomColl& coll) const;
	virtual int		setReturnType(const DskReturnType* pReturnType);
	virtual int		getReturnType(DskReturnType& returnType) const;

	// methods:
	int				clearFeatureUsages() const;
	int				clearKeyUsages() const;
};

class JOMOBJ_LINKAGE DskFunction : public DskRoutine
{
public:

	DskFunction(const DskObjectId* pOid) : DskRoutine(pOid) {}
	DskFunction(const ShortDskObjectId* pOid) : DskRoutine(pOid) {}
	DskFunction(ClassNumber classNo) : DskRoutine(classNo) {}
	DskFunction() : DskRoutine(DSKFUNCTION) {}
	virtual ~DskFunction() {}

	// attributes:

	// references:
	int				setSchema(const DskSchema* pSchema) const;
	int				getSchema(DskSchema& schema) const override;

	// methods:
};

class JOMOBJ_LINKAGE DskMethod : public DskRoutine
{
public:

	DskMethod(const DskObjectId* pOid) : DskRoutine(pOid) {}
	DskMethod(const ShortDskObjectId* pOid) : DskRoutine(pOid) {}
	DskMethod(ClassNumber classNo) : DskRoutine(classNo) {}
	DskMethod() : DskRoutine(DSKMETHOD) {}
	virtual ~DskMethod() {}

	// attributes:
	virtual int		setMethodInvocation(MethodInvocation methodInvocation);
	virtual int		getMethodInvocation(MethodInvocation* pMmethodInvocation) const;
	virtual int		setLockReceiver(bool lockReceiver);
	virtual int		getLockReceiver(bool* pLockReceiver) const;
	virtual int		setUpdating(bool updating);
	virtual int		getUpdating(bool* pUpdating) const;
	virtual int		setFinal(bool final);
	virtual int		getFinal(bool* pFinal) const;
	virtual int		setSubschemaFinal(bool subschemaFinal);
	virtual int		getSubschemaFinal(bool* pSubschemaFinal) const;
	virtual int		setSubschemaCopyFinal(bool subschemaCopyFinal);
	virtual int		getSubschemaCopyFinal(bool* pSubschemaCopyFinal) const;
	virtual int		setCondition(bool condition);
	virtual	int		getCondition(bool* pCondition) const;
	virtual int		setConditionSafe(bool conditionSafe);
	virtual	int		getConditionSafe(bool* pConditionSafe) const;
	virtual int		setPartitionMethod(bool partitionMethod);
	virtual	int		getPartitionMethod(bool* pPartitionMethod) const;
	virtual int		setUnitTestFlags(UnitTestFlags unitTestFlags);
	virtual	int		getUnitTestFlags(UnitTestFlags* pUnitTestFlags) const;

	// references:
	int				checkedOutMethods(JomColl& coll) const;
	int				setControlMethod(const DskMethod* pControlMethod) const;
	int				getControlMethod(DskMethod &controlMethod) const;
	int				setDelta(const DskDeltaInfo* pDeltaInfo) const;
	int				getDelta(DskDeltaInfo &deltaInfo) const;
	int				implementors(JomColl& coll) const;
	int				controlMethodRefs(JomColl& coll) const;
	virtual	int		getOriginalMethod(DskMethod &originalMethod) const;
	virtual int		setSuperMethod(const DskMethod* pSuperMethod);
	virtual int		getSuperMethod(DskMethod &superMethod) const;
	int				exportedMethodRefs(JomColl& coll) const;
	int				interfaceImplements(JomColl& coll) const;

	// methods:
	int				deleteSelf() override;
	int				isReimplementation(bool* pFlag) const;
	virtual int		isExternal(bool* pExternal) const;
	int				addInterfaceImplements(DskMethod* pInterfaceMethod) const;
	int				delInterfaceImplements(DskMethod* pInterfaceMethod) const;
	virtual int		isOnlyInLatestSchemaVersion(bool* pFlag) const override;
	virtual bool	canBeCheckedOut() const override { return true; }
	int				importedScriptRefs(JomColl& coll) const;
};

class JOMOBJ_LINKAGE DskLibrary : public DskSchemaEntity
{
public:

	DskLibrary(const DskObjectId* pOid) : DskSchemaEntity(pOid) {}
	DskLibrary(const ShortDskObjectId* pOid) : DskSchemaEntity(pOid) {}
	DskLibrary(ClassNumber classNo) : DskSchemaEntity(classNo) {}
	DskLibrary() : DskSchemaEntity(DSKLIBRARY) {}
	virtual ~DskLibrary() {}

	// attributes:

	// references:
	int				setSchema(const DskSchema* pSchema) const;
	int				getSchema(DskSchema& schema) const;

	// methods:
	int				structureChanged(DskLibrary & newLibraryVer) const;
};

class JOMOBJ_LINKAGE DskType: public DskSchemaEntity
{
public:

	DskType(const DskObjectId* pOid): DskSchemaEntity(pOid) {}
	DskType(const ShortDskObjectId* pOid): DskSchemaEntity(pOid) {}
	DskType(ClassNumber classNo): DskSchemaEntity(classNo) {}
	DskType(): DskSchemaEntity(DSKTYPE) {}
	virtual ~DskType() = default;

	// attributes:
	virtual int		setPersistentAllowed(bool persistentAllowed);
	virtual int		getPersistentAllowed(bool* pPersistentAllowed, LineNumber line = 0) const;
	virtual int		setTransientAllowed(bool transientAllowed);
	virtual int		getTransientAllowed(bool* pTransientAllowed, LineNumber line = 0) const;
	virtual int		setSharedTransientAllowed(bool sharedTransientAllowed);
	virtual int		getSharedTransientAllowed(bool* pSharedTransientAllowed, LineNumber line = 0) const;
	virtual int		setSubclassPersistentAllowed(bool subclassPersistentAllowed);
	virtual int		getSubclassPersistentAllowed(bool* pSubclassPersistentAllowed, LineNumber line = 0) const;
	virtual int		setSubclassTransientAllowed(bool subclassTransientAllowed);
	virtual int		getSubclassTransientAllowed(bool* pSubclassTransientAllowed, LineNumber line = 0) const;
	virtual int		setSubclassSharedTransientAllowed(bool subclassSharedTransientAllowed);
	virtual int		getSubclassSharedTransientAllowed(bool* pSubclassSharedTransientAllowed, LineNumber line = 0) const;
	virtual int		setFinal(bool final);
	virtual int		getFinal(bool* pFinal, LineNumber line = 0) const;
	virtual int		setSubschemaFinal(bool subschemaFinal);
	virtual int		getSubschemaFinal(bool* pSubschemaFinal, LineNumber line = 0) const;

	// references:
			int		accessRefs(JomColl& coll) const;
			int		localAccessRefs(JomColl& coll) const;
	virtual int		addAccessType(const DskType* pAccessType);
			int		delAccessType(const DskType* pAccessType) const;
	virtual int		accessTypes(JomColl& coll) const;
			int		localAccessTypes(JomColl& coll) const;
			int		addConstant(const DskConstant* pConstant) const;
			int		delConstant(const DskConstant* pConstant) const;
			int		collClassRefs(JomColl& coll) const;
			int		localCollClassRefs(JomColl& coll) const;
	virtual	int		allConstants(JomColl& coll) const;
			int		constants(JomColl& coll) const;
			int		localConstants(JomColl& coll) const;
			int		propertyRefs(JomColl& coll) const;
			int		localPropertyRefs(JomColl& coll) const;
	virtual int		addMethod(const DskMethod* pMethod);
			int		addMethod(const DskMethod* pMethod, bool) const;
			int		addMethodLatest(const DskMethod* pMethod, bool) const;
			int		delMethod(const DskMethod* pMethod) const;
			int		delMethod(const DskMethod* pMethod, bool) const;
	virtual int		methods(JomColl& coll) const;
			int		localMethods(JomColl& coll) const;
	virtual int		setSchema(const DskSchema* pSchema);
	virtual int		getSchema(DskSchema& schema) const;
			int		scriptRefs(JomColl& coll) const;
			int		localScriptRefs(JomColl& coll) const;
			int		setSuperschemaType(const DskType* pSuperschemaType) const;
			int		getSuperschemaType(DskType &superschemaType) const;
			int		subschemaTypes(JomColl& coll) const;

	// methods:
	virtual bool	isClass() const;
	virtual bool	isCollClass() const;
	virtual bool	isJadeInterface() const;
	virtual bool	isPrimitive() const;
	virtual bool	isPseudoType() const;
	virtual bool	isExceptionClass() const;
	virtual bool	isGUIClass() const;
	virtual bool	isHTMLClass() const;
	virtual bool	isImportedClass() const;
			bool	isImportedJadeInterface() const;
	virtual bool	isJadeWebServicesClass() const;
	virtual bool	isJadeWebServiceConsumerClass() const;
	virtual bool	isJadeWebServiceProviderClass() const;
	virtual bool	isJadeWebServiceSoapHeaderClass() const;

			int		getAbstractOrSubschemaCopy(bool* pValue) const;
	virtual int		getMethod(const Character name[], DskMethod& method) const;
	virtual int		getMethod(const Character name[], PDskMethod& pMethod) const;
	virtual	int		getMethodInHTree(const Character name[], DskMethod& method) const;
			int		getLatestMethod(const Character name[], DskMethod& method) const;
			int		getMethodInSchema(const Character name[], const DskSchema &schema, DskMethod& method) const;
			int		getConstant(const Character name[], DskConstant& constant, bool latest) const;
			int		getConstantInSchema(const Character name[], const DskSchema& schema, DskConstant& constant, bool latest) const;
	virtual	int		getConstantInHTree(const Character name[], DskConstant& constant) const;

			int		getLocalMethod(const Character name[], DskMethod& method) const;
			int		getLocalMethodByNumber(const FeatureNum featureNumber, DskMethod& method) const;
	virtual	int		getLocalConstant(const Character name[], DskConstant& constant) const;
			int		getLocalConstantByNumber(const FeatureNum featureNumber, DskConstant& constant) const;

	virtual int		inheritsFrom(ClassNumber superNum, bool* pInheritsFrom) const;
	virtual int		inheritsFrom(const DskType* pSuperType, bool* pInheritsFrom) const;

	virtual	int		getRootType(DskType &rootType) const;
            DskType getRootType() const { DskType rt = *this; getRootType(*&rt); return rt; }     // C++ version of getRootType
			int		allSuperschemaTypes(JomColl& coll) const;
			int		withAllSuperschemaTypes(JomColl& coll) const;
			int		allSubschemaTypes(JomColl& coll) const;
			int		withAllSubschemaTypes(JomColl& coll) const;
	virtual int		createSubschemaCopy(DskSchema& subschema, DskType& copy);
			int		createSubschemaCopyLatest(DskSchema& subschema, DskType& copy) const;
			int		isSubschemaCopy(bool* pIsSubschemaCopy) const;

			int		hasCollClassRefs(bool* pHasRefs) const;
			int		hasSubschemaTypes(bool* pHasSubs) const;

			int		structureChangedNoReorg(bool versionMethods, DskArray & versionedClasses, DskType & newTypeVer) const;
			int		structureChangedChangingMeth(DskMethod & meth, bool versionMeth, bool versionMethods, DskArray & versionedClasses, DskType & newTypeVer) const;
			int		structureChangedChangingConst(DskConstant & constant, bool versionConst, bool versionMethods, DskArray & versionedClasses, DskType & newTypeVer) const;

			int		purgeScriptRefs() const;

			int		deleteSelf() const;

	virtual int		isMethodNumAvailable(FeatureNum methodNum, bool* pIsAvailable) const;
	virtual int		isConstantNumAvailable(FeatureNum constantNum, bool* pIsAvailable) const;
};

class JOMOBJ_LINKAGE DskClass: public DskType
{
public:

	DskClass(const DskObjectId* pOid): DskType(pOid) {}
	DskClass(const ShortDskObjectId* pOid): DskType(pOid) {}
	DskClass(ClassNumber classNo): DskType(classNo) {}
	DskClass(): DskType(DSKCLASS) {}
	virtual ~DskClass() = default;

	// attributes:
			int		setNeedsReorg(bool needsReorg) const;
			int		getNeedsReorg(bool& needsReorg) const;
			int		setHighestSubId(SubID highestSubId) const;
	virtual int		getHighestSubId(SubID* pHighestSubId) const;
			int		setHighestOrdinal(FeatureNum highestOrdinal) const;
			int		getHighestOrdinal(FeatureNum* pHighestOrdinal) const;
	virtual int		getNextSubObjSubId(SubID* pSubId) const;
	virtual int		getNextSlobOrBlobSubId(SubID* pSubId) const;
	virtual int		setReplicationAllowed(ReplicationType replicationAllowed);
	virtual int		getReplicationAllowed(ReplicationType* pReplicationAllowed) const;
	virtual int		setReplicationControl(ReplicationType replicationControl);
	virtual int		getReplicationControl(ReplicationType* pReplicationControl) const;
	virtual int		setReplicationDefault(ReplicationType replicationDefault);
	virtual int		getReplicationDefault(ReplicationType* pReplicationDefault) const;
	virtual int		setTransient(bool transient);
	virtual int		getTransient(bool* pTransient, LineNumber line = 0) const;
	virtual int		setInstanceVolatility(ObjectVolatility volatility);
	virtual int		getInstanceVolatility(ObjectVolatility* pVolatility) const;
			int		setXMLInnerClass(bool val) const;
			int		getXMLInnerClass(bool* pVal) const;

	// references:
			int		classMapRefs(JomColl& coll) const;
	virtual int		addProperty(const DskProperty* pProperty);
			int		delProperty(const DskProperty* pProperty) const;
			int		delProperty(const DskProperty *pProperty, bool sendNotification) const;
			int		removeProperty(const DskProperty* pProperty, bool removePropRefs, bool removeInverses) const;
	virtual int		properties(JomColl& coll) const;
			int		clusters(JomColl& coll) const;
	virtual int		propertyOrder(JomColl& coll) const;
			int		localProperties(JomColl& coll) const;
			int		localClusters(JomColl& coll) const;
			int		localPropertyOrder(JomColl& coll) const;
	virtual int		addSubclass(const DskClass* pSubclass);
	virtual int		subclasses(JomColl& coll) const;
			int		localSubclasses(JomColl& coll) const;
	virtual int		addSuperclass(const DskClass* pSuperclass);
			int		delSuperclass(const DskClass* pSuperclass) const;
			int		getSuperclass(DskClass& superclass) const;
			int		exposedClassRefs(JomColl& coll) const;
			int		exportedClassRefs(JomColl& coll) const;
	virtual int		implementedInterfaces(JomColl& coll) const;
	virtual int		addImplementedInterface(const DskJadeInterface* pJadeInterface);
			int		delImplementedInterface(const DskJadeInterface* pJadeInterface) const;

	// methods:
			bool	isClass() const override							{ return true; }
			bool	isJadeInterface() const override					{ return false; }
			bool	isPrimitive() const override						{ return false; }
			bool	isPseudoType() const override						{ return false; }
	virtual bool	isImportedClassOrSubclass() const;
	virtual bool	isMemClass() const									{ return false; }
	virtual bool	isMemCollClass() const								{ return false; }
			bool	isUserClass() const;

	virtual int		getImportedSuperclass(DskJadeImportedClass& cls) const;
	virtual int		getRootSchemaSuperclass(DskClass& cls) const;
	virtual	int		allRootSchemaSuperclasses(JomColl& coll) const;
	virtual int		allImportedAndRootSuperclasses(JomColl& coll) const;
	virtual int		withAllImportedAndRootSuperclasses(JomColl& coll) const;

	virtual int		setConstructor(DskMethod* pConstructor);
			int		getConstructor(DskMethod& constructor) const;
	virtual int		setDestructor(DskMethod* pDestructor);
			int		getDestructor(DskMethod& destructor) const;
			
			int		getPropertyByName(const Character name[], DskProperty& property, bool latest) const;
			int		getPropertyByNumber(const FeatureNum featureNumber, DskProperty& property) const;
			int		getLocalPropertyByName(const Character name[], DskProperty& property) const;
			int		getSubclass(const Character name[], DskClass& subclass) const;
			int		getLatestSubclass(const Character name[], DskClass& subclass) const;
			int		getLocalSubclass(const Character name[], DskClass& subclass) const;

			int		allConstants(JomColl& coll) const override;
			int		allMethods(JomColl& coll) const;
			int		allProperties(JomColl& coll) const;
			int		allPropertiesOrder(JomColl& coll) const;
			int		allSubclasses(JomColl& coll) const;
			int		allImplementedInterfaces(JomColl& coll) const;

	virtual int		withAllSubclasses(JomColl& coll) const;
			int		allLocalSubclasses(JomColl& coll) const;
			int		allLatestLocalSubclasses(JomColl& coll) const;
	virtual int		allSuperclasses(JomColl& coll) const;
			int		allLatestSuperclasses(JomColl& coll) const;
	virtual int		withAllSuperclasses(JomColl& coll) const;
			int		withAllLatestSuperclasses(JomColl& coll) const;
			int		allSubclassesAndSubschemaSubclasses(JomColl& coll) const;
			int		allLatestSubclassesAndSubschemaSubclasses(JomColl& coll) const;
			int		withAllSubclassesAndSubschemaSubclasses(JomColl& coll) const;
			int		withAllLatestSubclassesAndSubschemaSubclasses(JomColl& coll) const;
			int		childSubclassesAndSubschemaSubclasses(JomColl& coll) const;
			int		childLatestSubclassesAndSubschemaSubclasses(JomColl& coll) const;
			int		immediateSubclassesAndSubschemaSubclasses(JomColl& coll) const;
			int		immediateLatestSubclassesAndSubschemaSubclasses(JomColl& coll) const;
			int		parentSubclasses(JomColl& coll) const;
			int		parentLatestSubclasses(JomColl& coll) const;

			int		getConstantInHTree(const Character name[], DskConstant& constant) const override;
			int		getLatestConstantInHTree(const Character name[], DskConstant& constant) const;
			int		getConstantInHTree(const Character name[], const DskSchema &schm, DskConstant& constant) const;
			int		getLatestConstantInHTree(const Character name[], const DskSchema &schm, DskConstant& constant) const;
			int		getMethodInHTree(const Character name[], DskMethod& method) const override;
			int		getMethodInHTree(const Character name[], const DskSchema &schm, DskMethod& method) const;
			int		getLatestMethodInHTree(const Character name[], const DskSchema &schm, DskMethod& method) const;
			int		getLatestMethodInHTree(const Character name[], DskMethod& method) const;
			int		getLatestMethodInAnySubclass(const Character name[], DskMethod& method) const;
	virtual int		getPropertyInHTree(const Character name[], DskProperty& property) const;
	virtual int		getPropertyInHTree(const Character name[], PDskProperty& pProperty) const;
	virtual	int		getLocalPropertyByName(const Character name[], PDskProperty& pProperty) const;
			int		getOldestPropertyInHTree(const Character name[], DskProperty& property) const;
			int		getNewestPropertyInHTree(const Character name[], DskProperty& property) const;
			int		getLatestPropertyInHTree(const Character name[], DskProperty& property) const;
			int		getLatestOldestPropertyInHTree(const Character name[], DskProperty& property) const;
			int		getLatestNewestPropertyInHTree(const Character name[], DskProperty& property) const;
			int		getClassMethodInSchema(const Character name[], const DskSchema &schm, bool useCurrent, DskMethod& mth) const;
			int		getClassConstantInSchema(const Character name[], const DskSchema &schm, bool useCurrent, DskConstant& con) const;

			int		importedScriptRefs(JomColl& coll) const;

			int		closeAgent() const;
			int		closeAgentWithSubclasses() const;

	virtual int		firstInstance(DskObjectId* pOid) const;
			int		firstProcessTransientInstance(DskObjectId* pOid) const;
			int		firstSharedTransientInstance(DskObjectId* pOid) const;
			int		instancesExist(bool* pInstsExist) const;

			int		needsReorg(bool* pNeedsReorg) const;
			int		structureChanged(DskArray & versionedClasses, DskClass & newClassVer) const;
			int		structureChangedDeletingProp(DskProperty & prop, bool versionMethods, DskArray & versionedClasses, DskClass & newClassVer) const;
			int		structureChangedChangingProp(DskProperty & prop, bool versionProp, bool markForReorg, bool versionMethods, bool versionKeys, DskArray & versionedClasses, DskClass & newClassVer) const;
			int		structureChangedDeletingInv(DskInverse & inv, DskArray & versionedClasses, DskClass & newClassVer) const;
			int		structureChangedDeletingKey(DskKey & key, DskArray & versionedClasses, DskClass & newClassVer) const;
			int		structureChangedRemoveImplementedInterface(DskJadeInterface & interf, DskArray & versionedClasses, DskClass & newClassVer) const;
			int		structureChangedRPSAddProp(DskProperty & prop, DskObject /*DskRelationalView*/ & newRelationalViewVer) const;
			int		structureChangedRPSDeleteProp(DskProperty & prop, DskObject /*DskRelationalView*/ & newRelationalViewVer) const;
			int		structureChangedRPSChangeProp(DskProperty & prop, DskObject /*DskRelationalView*/ & newRelationalViewVer) const;
			int		structureChangedRPSDeleteCond(DskMethod & meth, DskObject /*DskRelationalView*/ & newRelationalViewVer) const;
			int		reorgCreateVersion(DskClass & newClassVer, bool markForReorg) const;

			int		getClassMap(const DskDatabase* pDatabase, DskDbClassMap& classMap) const;
			int		hasClassMap(bool & hasMap) const;
			int		hasRPSClassMap(bool & hasMap) const;

			int		hasSubclasses(bool* pHasSubs) const;
			bool	hasPropertyInSubclass(const Character propertyName[], bool latest) const;
			int		markExposedListsForRegen(JomColl& markedLists) const;
	virtual int		isPropertyNumAvailable(FeatureNum propertyNum, bool* pIsAvailable) const;
	virtual int		isOrdinalNumAvailable(FeatureNum ordinalNum, bool* pIsAvailable) const;
	virtual int		isSubIdAvailable(bool slobOrBlob, SubID subId, bool* pIsAvailable) const;
			bool	implementsInterface(const DskJadeInterface* pJadeInterface) const;
			bool	implementsInterfaceLatest(const DskJadeInterface* pJadeInterface) const;
			bool	implementsInterfaceLocally(const DskJadeInterface* pJadeInterface) const;

			void	setWsdlSubschemaHidden(bool val) const;
			bool	isWsdlSubschemaHidden() const;

private:
			int		getPropertyInHTreeByTime(const Character name[], DskProperty& property, bool oldest, bool latest) const;

};

class JOMOBJ_LINKAGE DskCollClass: public DskClass
{
public:

	DskCollClass(const DskObjectId* pOid): DskClass(pOid) {}
	DskCollClass(const ShortDskObjectId* pOid): DskClass(pOid) {}
	DskCollClass(ClassNumber classNo): DskClass(classNo) {}
	DskCollClass(): DskClass(DSKCOLLCLASS) {}
	virtual ~DskCollClass() = default;

	// attributes:
	virtual int		setDuplicatesAllowed(bool duplicatesAllowed);
	virtual int		getDuplicatesAllowed(bool* pDuplicatesAllowed) const;
	virtual int		setMaxBlockSize(UInt32 maxBlockSize);
	virtual int		getMaxBlockSize(UInt32* pMaxBlockSize) const;
	virtual int		setMaxLogicalBlockSize(UInt32 maxLogicalBlockSize);
	virtual int		getMaxLogicalBlockSize(UInt32* pMaxLogicalBlockSize) const;
	virtual int		setActualBlockEntries(UInt32 actualBlockEntries);
	virtual int		getActualBlockEntries(UInt32* pActualBlockEntries) const;
	virtual int		calculateActualBlockEntries(UInt32* pActualBlockEntries) const;
	virtual int		calculateActualBlockEntriesEx(UInt32 blockEntries, UInt32 expectedPop, UInt32 loadFactor, UInt32 fullEntryBytes, UInt32* pActualBlockEntries) const;
	virtual int		calculateSingleDiskBlockEntries(UInt32 actualBlockEntries, UInt32* pSingleDiskBlockEntries) const;
	virtual int		setBlockSize(UInt32 blockSize);
	virtual int		getBlockSize(UInt32* pBlockSize) const;
	virtual int		setExpectedPopulation(UInt32 expectedPopulation);
	virtual int		getExpectedPopulation(UInt32* pExpectedPopulation) const;
	virtual int		setLoadFactor(UInt32 loadFactor);
	virtual int		getLoadFactor(UInt32* pLoadFactor) const;
			int		setMaxSize(Size size) const;
			int		getMaxSize(Size* pSize) const;
	virtual int		setMemberTypePrecision(Precision precision);
	virtual int		getMemberTypePrecision(Precision* pPrecision) const;
	virtual int		setMemberTypeSFactor(ScaleFactor scaleFactor);
	virtual int		getMemberTypeSFactor(ScaleFactor* pScaleFactor) const;
	virtual int		setMemberTypeSize(PropertyLen memberTypeSize);
	virtual int		getMemberTypeSize(PropertyLen* pMemberTypeSize) const;
			int		getMemberTypeWSDLNameLength(UInt32& len) const;
	virtual	int		setMemberTypeWSDLName(const Character str[]);
	virtual	int		getMemberTypeWSDLName(Character str[]) const;
	virtual	int		getKeysIsEmpty(bool* pHasNoKeys) const;
			int		setScaleEntries(bool scaleEntries) const;
			int		getScaleEntries(bool* pScaleEntries) const;

	// references:
	virtual int		setMemberType(const DskType* pMemberType);
	virtual int		getMemberType(PDskType& pMemberType) const;
	virtual int		getMemberType(DskType& memberType) const;
	virtual int		addKey(const DskKey* pKey);
	virtual int		keys(JomColl& coll) const;
			int		localKeys(JomColl& coll) const;
			int		scriptKeyRefs(JomColl& coll) const;
			int		localScriptKeyRefs(JomColl& coll) const;

	// methods:
			bool	isCollClass() const override						{ return true; }
			bool	isExceptionClass() const override					{ return false; }
			bool	isGUIClass() const override							{ return false; }
			bool	isHTMLClass() const override						{ return false; }
			bool	isJadeWebServicesClass() const override				{ return false; }
			bool	isJadeWebServiceConsumerClass() const override		{ return false; }
			bool	isJadeWebServiceProviderClass() const override		{ return false; }
			bool	isJadeWebServiceSoapHeaderClass() const override	{ return false; }

	virtual int		getMemberTypeNumber(ClassNumber*) const;
			int		getMemberKey(OrderedJomColl& matchKeyPath, DskProperty* pMatchKeyProp, DskMemberKey& key) const;
			int		getExternalKey(const Character keyName[], DskExternalKey& key) const;
			int		purgeScriptKeyRefs() const;
};

class JOMOBJ_LINKAGE DskScriptElement : public DskObject
{
public:

	DskScriptElement(const DskObjectId* pOid) : DskObject(pOid) {}
	DskScriptElement(const ShortDskObjectId* pOid) : DskObject(pOid) {}
	DskScriptElement(ClassNumber classNo) : DskObject(classNo) {}
	DskScriptElement() : DskObject(DSKSCRIPTELEMENT) {}
	virtual ~DskScriptElement() {}

	// attributes:
	int				setTextLength(ObjLen textLength) const;
	int				getTextLength(ObjLen* pTextLength) const;
	int				setTextPosition(Int32 textPosition) const;
	int				getTextPosition(Int32* pTextPosition) const;

	// references:
	int				setSchemaScript(const DskScript* pScript) const;
	int				getSchemaScript(DskScript& script) const;

	// methods:
};

class JOMOBJ_LINKAGE DskTypeUsage : public DskScriptElement
{
public:

	DskTypeUsage(const DskObjectId* pOid) : DskScriptElement(pOid) {}
	DskTypeUsage(const ShortDskObjectId* pOid) : DskScriptElement(pOid) {}
	DskTypeUsage(ClassNumber classNo) : DskScriptElement(classNo) {}
	DskTypeUsage() : DskScriptElement(DSKTYPEUSAGE) {}
	virtual ~DskTypeUsage() {}

	// attributes:
	virtual int		setName(const Character name[]);
	virtual int		getName(Character name[]) const;

	// references:
	virtual int		setType(const DskType* pType);
	virtual int		getType(DskType& type) const;
	virtual int		getType(PDskType& pType) const;

	// methods:
	int				deleteSelf() const;
};

class JOMOBJ_LINKAGE DskReturnType : public DskTypeUsage
{
public:

	DskReturnType(const DskObjectId* pOid) : DskTypeUsage(pOid) {}
	DskReturnType(const ShortDskObjectId* pOid) : DskTypeUsage(pOid) {}
	DskReturnType(ClassNumber classNo) : DskTypeUsage(classNo) {}
	DskReturnType() : DskTypeUsage(DSKRETURNTYPE) {}
	virtual ~DskReturnType() {}

	// attributes:
	int				setLength(PropertyLen length) const;
	int				getLength(PropertyLen* pLength) const;

	// references:

	// methods:
};

class JOMOBJ_LINKAGE DskApplication: public DskObject
{
public:

	DskApplication(const DskObjectId* pOid): DskObject(pOid) {}
	DskApplication(const ShortDskObjectId* pOid): DskObject(pOid) {}
	DskApplication(ClassNumber classNo): DskObject(classNo) {}
	DskApplication(): DskObject(DSKAPPLICATION) {}
	virtual ~DskApplication() = default;

	// attributes:
			int		setApplicationType(JomApplicationType) const;
			int		getApplicationType(JomApplicationType&) const;
			int		setName(const Character name[]) const;
			int		getName(Character name[]) const;

	// references:
			int		setCurrentLocale(const DskLocale& locale) const;
			int		getCurrentLocale(DskLocale& locale) const;
			int		setSchema(const DskSchema* pSchema) const;
			int		getSchema(DskSchema& schema) const;

	// methods:
};

class JOMOBJ_LINKAGE DskSchema: public DskObject
{
public:

	DskSchema(const DskObjectId* pOid): DskObject(pOid) {}
	DskSchema(const ShortDskObjectId* pOid): DskObject(pOid) {}
	DskSchema(ClassNumber classNo): DskObject(classNo) {}
	DskSchema(): DskObject(DSKSCHEMA) {}
	virtual ~DskSchema() = default;

	// attributes:
	virtual int		setModifiedTimeStamp(DskTimeStamp* pModifiedTimeStamp) override;
	virtual int		getModifiedTimeStamp(DskTimeStamp* pModifiedTimeStamp) const override;
	virtual int		setSchemaPatchVersion(Int32 patchVersion);
	virtual int		getSchemaPatchVersion(Int32* pPatchVersion) const;
	virtual int		setPatchVersion(Int32 patchVersion) override;
	virtual int		getPatchVersion(Int32* pPatchVersion) const override;
	virtual int		setSystemVersion(const Character systemVersion[]) override;
	virtual int		getSystemVersion(Character systemVersion[]) const override;
	virtual int		setModifiedBy(const Character[]) override;
	virtual int		getModifiedBy(Character[]) const override;
			int		setFormsManagement(BYTE style) const;
			int		getFormsManagement(BYTE* pStyle) const;
			int		setJomVersion(const Character jomVersion[]) const;
	virtual	int		getJomVersion(Character jomVersion[]) const;
			int		setNumber(SchemaNumber schemaNo) const;
			int		getNumber(SchemaNumber* pSchemaNo, LineNumber line = 0) const;
			int		setName(const Character name[]) const;
	virtual int		getName(Character name[]) const;
			int		setNextClassNumber(ClassNumber nextClassNumber) const;
			int		getNextClassNumber(ClassNumber* pNextClassNumber) const;
			int		setPatchVersioningEnabled(bool val) const;
			int		getPatchVersioningEnabled(bool* pVal) const;
			int		setPermanent(bool permanent) const;
			int		getPermanent(bool* pPermanent) const;
			int		setStatus(SchemaStatus status) const;
			int		getStatus(SchemaStatus* pStatus) const;
			int		setText(const Character text[]) const;
			int		getText(Character text[]) const;

	// references:
	virtual int		setUserProfile(const DskUserProfile* pUserProfile) override;
	virtual int		getUserProfile(DskUserProfile& userProfile) const override;
			int		setAppClass(const DskClass* pAppClass) const;
			int		getAppClass(DskClass& appClass) const;
			int		setGlobalClass(const DskClass* pGlobalClass) const;
			int		getGlobalClass(DskClass& globalClass) const;
			int		setWebClass(const DskClass* pWebClass) const;
			int		getWebClass(DskClass& webClass) const;
	virtual int		addClass(const DskClass* pClass);
			int		addClassWithoutNotify(const DskClass* pClass) const;
			int		delClass(const DskClass* pClass) const;
	virtual int		classes(JomColl& coll) const;
			int		addConstant(const DskGlobalConstant* pGlobalConstant) const;
			int		delConstant(const DskGlobalConstant* pGlobalConstant) const;
			int		constants(JomColl& coll) const;
			int		addConstantCategory(const DskConstantCategory* pConstantCategory) const;
			int		delConstantCategory(const DskConstantCategory* pConstantCategory) const;
			int		constantCategories(JomColl& coll) const;
	virtual	int		addDatabase(const DskDatabase* pDatabase);
			int		delDatabase(const DskDatabase* pDatabase) const;
	virtual int		databases(JomColl& coll) const;
	virtual int		addDbServer(const DskDbServer* pDbServer);
			int		delDbServer(const DskDbServer* pDbServer) const;
	virtual int		dbServers(JomColl& coll) const;
	virtual int		addLibrary(const DskLibrary* pLibrary);
			int		delLibrary(const DskLibrary* pLibrary) const;
	virtual int		libraries(JomColl& coll) const;
	virtual int		functions(JomColl& coll) const;
			int		addLocale(DskLocale* pLocale) const;
			int		delLocale(DskLocale* pLocale) const;
			int		locales(JomColl& coll) const;
			int		setPrimaryLocale(const DskLocale* pLocale) const;
			int		getPrimaryLocale(DskLocale& locale) const;
	virtual int		addPrimitive(const DskPrimType* pPrimitive);
			int		delPrimitive(const DskPrimType* pPrimitive) const;
	virtual int		primitives(JomColl& coll) const;
	virtual int		addPseudoType(const DskPseudoType* pPseudoType);
	virtual int		pseudoTypes(JomColl& coll) const;
	virtual int		addSubschema(const DskSchema* pSubschema);
			int		delSubschema(const DskSchema* pSubschema) const;
	virtual int		setSuperschema(const DskSchema* pSuperschema);
	virtual int		getSuperschema(DskSchema& superschema) const;
			int		exposedLists(JomColl& coll) const;
	virtual int		exportedPackages(JomColl& coll) const;
	virtual int		importedPackages(JomColl& coll) const;
	virtual int		addJadeInterface(const DskJadeInterface* pJadeInterface);
			int		addJadeInterfaceWithoutNotify(const DskJadeInterface* pJadeInterface) const;
			int		delJadeInterface(const DskJadeInterface* pJadeInterface) const;
	virtual int		interfaces(JomColl& coll) const;
			int		setRootSchema(const DskSchema* pRootSchema) const;
			int		getRootSchema(DskSchema& rootSchema) const;
			int		subschemasByNumber(JomColl& coll) const;
			int		userSubschemasByNumber(JomColl& coll) const;

	// methods:
			int		getConstant(const Character name[], DskGlobalConstant& con) const;
			int		getConstantLatestVersion(const Character name[], DskGlobalConstant& con) const;
			int		getLocalConstant(const Character name[], DskGlobalConstant& con) const;
			int		getConstantCategory(const Character name[], DskConstantCategory& cat) const;
			int		getLocalConstantCategory(const Character name[], DskConstantCategory& cat) const;
	virtual int		getDatabase(const Character name[], DskDatabase& database) const;
			int		getLocalDatabase(const Character name[], DskDatabase& database) const;
	virtual	int		getDbServer(const Character name[], DskDbServer& dbServer) const;
			int		getLocalDbServer(const Character name[], DskDbServer& dbServer) const;
			int		getFunction(const Character name[], DskFunction& function) const;
			int		getFunctionLatestVersion(const Character name[], DskFunction& function) const;
			int		getLocalFunction(const Character name[], DskFunction& function) const;
	virtual int		getLibrary(const Character name[], DskLibrary& library) const;
			int		getLibraryLatestVersion(const Character name[], DskLibrary& library) const;
			int		getLocale(const Character name[], DskLocale& locale) const;
			int		getLocalLibrary(const Character name[], DskLibrary& library) const;
			int		getPrimitive(const Character name[], DskPrimType& primitive) const;
			int		getPrimitiveLatestVersion(const Character name[], DskPrimType& primitive) const;
	virtual int		getLocalPrimitive(const Character name[], DskPrimType& primitive) const;
			int		getLocalPrimitiveTypeName(TypeNum typenum, Character name[]) const;
			int		getLocalPrimitiveByNumber(TypeNum typenum, DskPrimType& primitive) const;
			int		getPseudoType(const Character name[], DskPseudoType& pseudoType) const;
			int		getLocalPseudoType(const Character name[], DskPseudoType& pseudoType) const;
	virtual int		getSchemaClass(const Character name[], DskClass& schemaClass) const;
	virtual int		getSchemaClass(ClassNumber classNumber, DskClass& schemaClass) const;
			int		getSchemaClassLatestVersion(const Character name[], DskClass& schemaClass) const;
	virtual int		getSchemaOrImportedClass(ClassNumber classNumber, DskClass& schemaClass) const;
	virtual int		getSchemaOrImportedClass(const Character name[], DskClass& schemaClass) const;
			int		getSchemaClassNo(const Character name[], ClassNumber& classNumber) const;
	virtual int		getLocalClass(const Character name[], DskClass& schemaClass) const;
	virtual	int		getLocalClass(ClassNumber, DskClass& schemaClass) const;
			int		getClassByNumber(ClassNumber classNo, DskClass& cls) const;
			int		getClassByNumberCurrent(ClassNumber classNo, DskClass& cls) const;
			int		getClassByNumberLatest(ClassNumber classNo, DskClass& cls) const;
			int		getSchemaByNumber(SchemaNumber schemaNumber, DskSchema& schema) const;
	virtual int		getSchemaJadeInterface(const Character name[], DskJadeInterface& jadeInterface) const;
			int		getSchemaJadeInterfaceLatestVersion(const Character name[], DskJadeInterface& jadeInterface) const;
			int		getLocalJadeInterface(const Character name[], DskJadeInterface& jadeInterface) const;
			int		getLocalInterfaceByNumber(InterfaceNumber, DskJadeInterface&) const;
			int		getRootJadeInterface(const Character name[], DskJadeInterface& jadeInterface) const;
			int		getInterfaceByNumber(InterfaceNumber, DskJadeInterface&) const;
			int		getInterfaceByNumberLatest(InterfaceNumber, DskJadeInterface&) const;
			int		getSchemaImportedJadeInterface(const Character name[], DskJadeImportedInterface& jadeInterface) const;
			int		getSchemaView(const Character name[], DskSchemaView& schemaView) const;
	virtual int		getSubschema(const Character name[], DskSchema& subschema) const;
			int		getUserFormat(const Character name[], DskLocaleFormat& userFormat) const;
			int		getUserFormatLatestVersion(const Character name[], DskLocaleFormat& userFormat) const;
			int		getLocalUserFormat(const Character name[], DskLocaleFormat& userFormat) const;
			int		getLocalUserFormatByNumber(FeatureNum formatNumber, DskLocaleFormat& userFormat) const;
			int		getLocaleFormatHighestNumber(FeatureNum& userFormatNumber) const;
			int		getUserProfile(const Character name[], DskUserProfile& userProfile) const;
			int		getTranslatableStringInDfltLocale(const Character name[], DskTranslatableString& transStr) const;
			int		getTranslatableStringInDfltLocaleLatestVersion(const Character name[], DskTranslatableString& transStr) const;
			int		getNextTransStringNum(FeatureNum hint, FeatureNum& nextNumber) const; 

	virtual int		findSchema(const Character name[], DskSchema& schema) const;
			int		findDbFile(const Character fileName[], DskDbFile& dbFile) const;
			int		findDbFile(DbFileNum fileNum, DskDbFile& dbFile) const;
	virtual int		getType(const Character name[], DskType& type) const;
			int		getTypeLatestVersion(const Character name[], DskType& type) const;
	virtual int		getType(const Character name[], PDskType& pType) const;
			int		getLocalType(const Character name[], DskType& type) const;

	virtual int		subschemas(JomColl& coll) const;
			int		userSubschemas(JomColl& coll) const;
			int		systemSubschemas(JomColl& coll) const;

			int		allClasses(JomColl& coll) const;
			int		getTextSize(UInt32* pTextSize) const;

			int		getErrorDesc(ErrorNum errorNo, Character errorDesc[]) const;

			int		allSuperschemas(JomColl& coll) const;
			int		withAllSuperschemas(JomColl& coll) const;
			int		allSubschemas(JomColl& coll) const;
			int		withAllSubschemas(JomColl& coll) const;
			int		allLatestSuperschemas(JomColl& coll) const;
			int		withAllLatestSuperschemas(JomColl& coll) const;
			int		allLatestSubschemas(JomColl& coll) const;
			int		withAllLatestSubschemas(JomColl& coll) const;

			int		nonCloneLocales(JomColl& coll) const;
			int		copyLocales(const DskSchema &superschema, bool asLocal) const;

			int		deleteSelf() const;
			int		getExposedList(const Character name[], DskJadeExposedList& expList) const;

			int		allLibraries(JomColl& coll) const;
			int		allFunctions(JomColl& coll) const;
			int		getApplication(const Character name[], DskObject& app) const;

			int		allImportedPackages(JomColl& coll) const;
			int		createExportedPackage(const Character name[], DskJadeExportedPackage& expPkg) const;
			int		deleteExportedPackage(const DskJadeExportedPackage& expPkg) const;
	virtual	int		getExportedPackage(const Character name[], DskJadeExportedPackage& pkg) const;
			int		createImportedPackage(const Character name[], const DskJadeExportedPackage& expPkg, DskJadeImportedPackage& impPkg) const;
			int		deleteImportedPackage(const DskJadeImportedPackage& impPkg) const;
	virtual	int		getImportedPackage(const Character name[], DskJadeImportedPackage& pkg) const;
			int		getLocalImportedPackage(const Character name[], DskJadeImportedPackage& pkg) const;
			int		getLocalImportedPackageByNumber(const PackageNumber packageNumber, DskJadeImportedPackage& pkg) const;
	virtual	int		getImportedClass(const Character name[], DskJadeImportedClass& cls) const;
			int		getImportedClassLatestVersion(const Character name[], DskJadeImportedClass& cls) const;
	virtual	int		getImportedClass(ClassNumber classNumber, DskJadeImportedClass& cls) const;
			int		getImportedInterface(const Character name[], DskJadeImportedInterface& impInterface) const;
			int		getImportedInterfaceLatestVersion(const Character name[], DskJadeImportedInterface& impInterface) const;
			int		delTranslatableString(const DskTranslatableString* pTransStr) const;
			int		delUserFormat(const DskLocaleFormat* pUserFormat) const;
			int		structureChanged(DskSchema & newSchemaVer) const;
			int		structureChangedChangingCat(DskConstantCategory & cat, bool versionCat, DskConstantCategory & newCatVer) const;
			int		structureChangedChangingConst(DskConstant & constant, bool versionConst, bool versionMethods, DskArray & versionedClasses, DskConstant & newConstVer) const;
			int		structureChangedChangingLocaleFormat(DskLocaleFormat & format, bool versionFormat, bool versionMethods, DskArray & versionedClasses, DskLocaleFormat & newFormatVer) const;
			int		structureChangedChangingFunction(DskFunction & func, bool versionFunction, bool versionMethods, DskArray & versionedClasses, DskFunction & newFunctionVer) const;
			int		structureChangedRPSDeleteCls(DskClass* pDskClass, bool & ok) const;
			int		structureChangedRPSChangeCls(DskClass* pDskClass, bool & ok) const;
};

#undef getSize

class JOMOBJ_LINKAGE DskCollection: public DskObject
{
public:

	DskCollection(const DskObjectId* pOid): DskObject(pOid) {}
	DskCollection(const ShortDskObjectId* pOid): DskObject(pOid) {}
	DskCollection(const OidKey* pOidKey): DskObject(pOidKey) {}
	DskCollection(ClassNumber classNo): DskObject(classNo) {}
	DskCollection(): DskObject(DSKCOLLECTION) {}
	DskCollection(const DskObjectId& oid): DskObject(oid) {}
	DskCollection(const ShortDskObjectId& shortOid): DskObject(shortOid) {}
	DskCollection(const OidKey& oidKey): DskObject(oidKey) {} 
	virtual ~DskCollection() = default;

	// attributes:
			int		setRootBlock(InstanceID rootBlock) const;
			int		getRootBlock(InstanceID* pRootBlock) const;

	// references:

	// methods:
			int		createIterator(DskIterator* pIter, LineNumber line = 0) const;
			int		getSize(UInt32* pSize) const;
			int		isEmpty(bool* pIsEmpty) const;
			int		purge() const;
			int		clear() const;
			int		first(DskObject& value) const;
			int		last(DskObject& value) const;
			int		includes(const DskObject* pObject, bool* pFlag) const;
};

class JOMOBJ_LINKAGE DskBtree: public DskCollection
{
public:

	DskBtree(const DskObjectId* pOid): DskCollection(pOid) {}
	DskBtree(const ShortDskObjectId* pOid): DskCollection(pOid) {}
	DskBtree(const OidKey* pOid): DskCollection(pOid) {}
	DskBtree(ClassNumber classNo): DskCollection(classNo) {}
	DskBtree(): DskCollection(DSKBTREE) {}
	virtual ~DskBtree() = default;

	// attributes:

	// references:

	// methods:
			int		values(JomColl& coll) const;
};

class JOMOBJ_LINKAGE DskDictionary: public DskBtree
{
protected:

			int		getAtKey(DskParam* pKeyParam, DskObject& value) const;

public:

	DskDictionary(const DskObjectId* pOid): DskBtree(pOid) {}
	DskDictionary(const ShortDskObjectId* pOid): DskBtree(pOid) {}
	DskDictionary(const OidKey* pOid): DskBtree(pOid) {}
	DskDictionary(ClassNumber classNo): DskBtree(classNo) {}
	DskDictionary(): DskBtree(DSKDICTIONARY) {}
	virtual ~DskDictionary() = default;

	// attributes:

	// references:

	// methods:

			int		getAtKey(const Character key[], DskObject& value) const;
			int		getAtKey(UInt32 key, DskObject& value) const;
			int		getAtKey(Real key, DskObject& value) const;
			int		getAtKey(const DskObject* pKey, DskObject& value) const;
			int		getAtKey(const DskTimeStamp* pKey, DskObject& value) const;
			int		getAtDateKey(const DskDate* pKey, DskObject& value) const;
			int		getAtTimeKey(const DskTime* pKey, DskObject& value) const;

			int		removeKey(const Character key[]) const;
			int		removeKey(UInt32 key) const;
			int		removeKey(Real key) const;
			int		removeKey(const DskObject* pKey) const;
			int		removeKey(const DskTimeStamp* pKey) const;
			int		removeDateKey(const DskDate* pKey) const;
			int		removeTimeKey(const DskTime* pKey) const;
};

class JOMOBJ_LINKAGE DskExtKeyDictionary: public DskDictionary
{
public:

	DskExtKeyDictionary(const DskObjectId* pOid): DskDictionary(pOid) {}
	DskExtKeyDictionary(const ShortDskObjectId* pOid): DskDictionary(pOid) {}
	DskExtKeyDictionary(ClassNumber classNo): DskDictionary(classNo) {}
	DskExtKeyDictionary(): DskDictionary(DSKEXTKEYDICTIONARY) {}
	virtual ~DskExtKeyDictionary() = default;

	// attributes:

	// references:

	// methods:
			int		putAtKey(const ShortDskParam* pKey, const DskObject* pValue) const;
			int		putAtKey(const Character key[], const DskObject* pValue) const;
			int		putAtKey(UInt32 key, const DskObject* pValue) const;
			int		putAtKey(Real key, const DskObject* pValue) const;
			int		putAtKey(const DskObject* pKey, const DskObject* pValue) const;
			int		putAtKey(const DskTimeStamp* pKey, const DskObject* pValue) const;
			int		putAtDateKey(const DskDate* pKey, const DskObject* pValue) const;
			int		putAtTimeKey(const DskTime* pKey, const DskObject* pValue) const;
};

class JOMOBJ_LINKAGE DskMemberKeyDictionary: public DskDictionary
{
public:

	DskMemberKeyDictionary(const DskObjectId* pOid): DskDictionary(pOid) {}
	DskMemberKeyDictionary(const ShortDskObjectId* pOid): DskDictionary(pOid) {}
	DskMemberKeyDictionary(ClassNumber classNo): DskDictionary(classNo) {}
	DskMemberKeyDictionary(): DskDictionary(DSKMEMBERKEYDICTIONARY) {}
	virtual ~DskMemberKeyDictionary() = default;

	// attributes:

	// references:

	// methods:
			int		add(const DskObject* pObject) const;
			int		remove(const DskObject* pObject) const;
};

class JOMOBJ_LINKAGE DskSet: public DskBtree
{
public:

	DskSet(const DskObjectId* pOid): DskBtree(pOid) {}
	DskSet(const ShortDskObjectId* pOid): DskBtree(pOid) {}
	DskSet(const OidKey* pOid): DskBtree(pOid) {}
	DskSet(ClassNumber classNo): DskBtree(classNo) {}
	DskSet(): DskBtree(DSKSET) {}
	virtual ~DskSet() = default;

	// attributes:

	// references:

	// methods:
			int		add(const DskObject* pObject) const;
			int		remove(const DskObject* pObject) const;
};

class JOMOBJ_LINKAGE DskObjectSet: public DskSet
{
public:

	DskObjectSet(const DskObjectId* pOid): DskSet(pOid) {}
	DskObjectSet(const ShortDskObjectId* pOid): DskSet(pOid) {}
	DskObjectSet(const OidKey* pOid): DskSet(pOid) {}
	DskObjectSet(ClassNumber classNo): DskSet(classNo) {}
	DskObjectSet(): DskSet(DSKOBJECTSET) {}
	virtual ~DskObjectSet() = default;

	// attributes:

	// references:

	// methods:
};

class JOMOBJ_LINKAGE DskList: public DskCollection
{
public:

	DskList(const DskObjectId* pOid): DskCollection(pOid) {}
	DskList(const ShortDskObjectId* pOid): DskCollection(pOid) {}
	DskList(const OidKey* pOid): DskCollection(pOid) {}
	DskList(ClassNumber classNo): DskCollection(classNo) {}
	DskList(): DskCollection(DSKLIST) {}
	DskList(const DskObjectId& oid): DskCollection(oid) {}
	DskList(const ShortDskObjectId& shortOid): DskCollection(shortOid) {}
	DskList(const OidKey& oidKey): DskCollection(oidKey) {}
	virtual ~DskList() = default;

	// attributes:

	// references:

	// methods:
			int		values(JomColl& coll) const;
			int		valuesReversed(JomColl& coll) const;
};

class JOMOBJ_LINKAGE DskArray: public DskList
{
public:

	DskArray(const DskObjectId* pOid): DskList(pOid) {}
	DskArray(const ShortDskObjectId* pOid): DskList(pOid) {}
	DskArray(const OidKey* pOid): DskList(pOid) {}
	DskArray(ClassNumber classNo): DskList(classNo) {}
	DskArray(): DskList(DSKARRAY) {}
	DskArray(const DskObjectId& oid): DskList(oid) {}
	DskArray(const ShortDskObjectId& shortOid): DskList(shortOid) {}
	DskArray(const OidKey& oidKey): DskList(oidKey) {}
	virtual ~DskArray() = default;

	// attributes:

	// references:

	// methods:
			int		valuesPos(const Character message[], CollIndex pos, JomColl& coll) const;
			int		valuesAt(CollIndex pos, JomColl& coll) const;
			int		valuesAtReversed(CollIndex pos, JomColl& coll) const;

			int		add(const DskObject* pObject) const;
			int		add(const DskObjectId* pObject) const;
			int		add(const ShortDskObjectId* pObject) const;
			int		add(const Character string[]) const;
			int		remove(const DskObject* pObject) const;
			int		remove(const Character string[]) const;
			int		at(CollIndex pos, DskObject& object) const;
			int		atEx(CollIndex pos, DskParam* pParam) const;
			int		atPut(CollIndex pos, const DskObject* pObject) const;
			int		removeAt(CollIndex pos, DskObject& object) const;
			int		insert(CollIndex pos, const DskObject* pObject) const;
			int		replace(CollIndex pos, const DskObject* pObject) const;
			int		indexOf(const DskObject* pObject, CollIndex* pPos) const;
};

class JOMOBJ_LINKAGE DskObjectArray: public DskArray
{
public:

	DskObjectArray(const DskObjectId* pOid): DskArray(pOid) {}
	DskObjectArray(const ShortDskObjectId* pOid): DskArray(pOid) {}
	DskObjectArray(ClassNumber classNo): DskArray(classNo) {}
	DskObjectArray(): DskArray(DSKOBJECTARRAY) {}
	virtual ~DskObjectArray() = default;

	// attributes:

	// references:

	// methods:
};

class JOMOBJ_LINKAGE DskIterator: public DskObject
{
public:

	DskIterator(const DskObjectId* pOid): DskObject(pOid) {}
	DskIterator(const ShortDskObjectId* pOid): DskObject(pOid) {}
	DskIterator(ClassNumber classNo): DskObject(classNo) {}
	DskIterator(): DskObject(DSKITERATOR) {}
	virtual ~DskIterator() = default;

	// attributes:

	// references:

	// methods:
			int		setCollection(const DskObjectId&) const;
			int		getCollection(DskObjectId&) const;
			int		reset() const;
			int		next(DskObject& object, bool* pMore) const;
			int		back(DskObject& object, bool* pMore) const;
};

#include "jompack0.h"				/* restore structure member alignment (packing) */

// jom proxy inline implementations
#include "jomobjin.hpp"

#endif /* JOMOBJ_hpp */
