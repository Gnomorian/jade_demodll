/****************************************************************************

				P R O P R I E T A R Y   N O T I C E

	This software, in whole and in every part, is proprietary to Jade Software
	Corporation Limited at Christchurch, New Zealand and is not to be
	reproduced, used or disclosed except upon prior written permission of Jade
	Software Corporation Limited.

	COPYRIGHT (c) JADE SOFTWARE CORPORATION LIMITED 2005 - ALL RIGHTS RESERVED

****************************************************************************/

#pragma once 

#include <string.h>

#include "jomarch.h"
#include "jomdefs.h"
#include "jomtypno.h"

// DSKPARAM_LINKAGE not defined, use empty definition to neither import or export classes (DskParam, ...)
// - DSKPARAM_LINKAGE CLASS_IMPORT must be defined if your DLL uses DskParam, .... to avoid compiler warning C4251 
// - DSKPARAM_LINKAGE CLASS_EXPORT must be defined for jomobj.lib files
#ifndef DSKPARAM_LINKAGE
#define DSKPARAM_LINKAGE CLASS_IMPORT
// static_assert(false, "define DSKPARAM_LINKAGE either as CLASS_EXPORT (jomobj.lib/jom.dll), CLASS_IMPORT or empty string");
#endif

#define VERSIONINFO_OBJECTS

/* primitive lengths */
#define DSKINTEGER_LENGTH			sizeof(Integer) 	/* all platforms */
#define	DSKINTEGER64_LENGTH			sizeof(Integer64)
#define DSKCHARACTER_LENGTH			sizeof(Character)
#define DSKBOOLEAN_LENGTH			sizeof(Boolean)
#define DSKBYTE_LENGTH				sizeof(Byte)
#define DSKREAL_LENGTH				sizeof(Real)
#define DSKDECIMAL_LENGTH			sizeof(DskDecimal)
#define DSKMEMORYADDRESS_LENGTH		sizeof(DskMemoryAddress)
#define DSKPOINT_LENGTH				sizeof(DskPoint)
#define DSKDATE_LENGTH				sizeof(DskDate)
#define DSKTIME_LENGTH				sizeof(DskTime)
#define DSKTIMESTAMP_LENGTH			sizeof(DskTimeStamp)
#define DSKTIMESTAMPINTERVAL_LENGTH	sizeof(DskTimeStampInterval)
#define DSKTIMESTAMPOFFSET_LENGTH	sizeof(DskTimeStampOffset)
#define DSKSHORTOBJECTID_LENGTH		sizeof(ShortDskObjectId)
#define DSKOBJECTID_LENGTH			sizeof(DskObjectId)
#define SLOB_OR_BLOB_LENGTH			sizeof(JomSlobInfo)		 /* length and edition. Copied as RS::Property::SLOB_OR_BLOB_LENGTH*/
#define DSKINSTANCEID_LENGTH		sizeof(InstanceID)

#if defined(UNIX) || !defined(__cplusplus)
#if !defined(__GNUC__) && ! (defined(__IBMCPP__)  && (__IBMCPP__ >= 400))
typedef signed char     bool;
#endif
#if !defined(linux)
#define false           ((bool) 0)
#define true            ((bool) 1)
#endif
#endif /* UNIX */

typedef signed char		Boolean;
typedef unsigned char	BYTE;
typedef BYTE			Byte;
typedef Int32			Integer;    	/* default integer in JOM */
typedef UInt32			UInteger;		/* default unsigned int in JOM */
typedef	Int64			Integer64;
typedef	UInt64			UInteger64;
typedef UInt32			CharacterUtf32;
typedef	unsigned char	StringUtf8Byte;
typedef UInt16			SubID;
typedef UInt16			FeatureNum;
typedef BYTE			Level;
typedef UInt32			ShortInstanceID;		
typedef UInt64			InstanceID;		/* see custom INSTID_FMT defined below */
typedef UInt16			DbNum;
typedef UInt32			VersionNum;
typedef UInt16			BranchNum;
typedef UInt16			ReplicationInfo;
typedef int				ErrorNum;
typedef UInt64			RecOffset;
typedef	UInt64			SequenceNumber;	/* A 64 bit integer in a monotonic sequence space such as a transaction identifier */
typedef UInt64			LockSequenceNumber;
typedef UInt32			CacheSequenceNumber;
typedef UInt32		  	ObjLen;			/* see custom OBJLEN_FMT defined below */
typedef UInt32	        Size;			/* General-purpose 32-bit unsigned 'Size' type */
typedef Int32	        SSize;			/* General-purpose 32-bit signed 'Size' type */
typedef int          	DayType;
typedef int				MonthType;
typedef int				YearType;
typedef UInt64			JosTimestamp;
typedef UInt16			Length;			/* General-purpose 16-bit 'Length' type */
typedef UInt32			PropertyLen;	/* Length of a property */
typedef ObjLen			Offset;			/* Offset of an inst var in its class */
#if defined(_WIN32_WCE)
typedef time_t			Time_T32;		/* for legacy 32bit time_t storage */
#else
typedef UInt32			Time_T32;		/* for legacy 32bit time_t storage */
#endif
typedef time_t			Time_T;			/* c runtime time_t, size can vary between platforms */
typedef UInt32			HashValue;		/* return type for hash() implementations */
typedef Int32			SHashValue;		/* use to calculate hash() result */
typedef UInt32			LineNumber;
typedef UInt32			Counter;
typedef UInt64			Counter64;
typedef UInt32			Index;
typedef UInt32			CollIndex;
typedef UInt32			Edition;
typedef Int32			CollEntries;	/* needs to be signed for comparisons */
typedef UInt32			SubUserID;
typedef UInt16			ConnectionPort;
typedef BYTE			Precision;
typedef BYTE			ScaleFactor;
typedef Length			PropertyDataSize;
typedef void *			CriticalSection;
typedef UInt32			LocaleID;
typedef UInt16			EntryCount;
typedef Int32			BlockIndex;
typedef	float			Float;
typedef double			Real;       	/* default JADE Real type equates to a C 'Double' */
typedef double			Double;
typedef float			Real4;       	/* 4 byte Real */
typedef	void*			FeatureHandle;
typedef UInt32			JomMemorySpaceId;
typedef UInt32			WaitTime;		/* Event wait time (milliseconds) */
typedef UInt32			Counter;		/* General-purpose unsigned type to count 'things' */
typedef UInt32			LockFlag;
typedef BYTE			LockLevel;
typedef UInt32			NoteUserTag;
typedef UInt32			NoteProcessSubsession;
typedef unsigned int	Dimension;

/* reference kinds */
enum ReferenceKind : BYTE
{
	PEER													= 0,
	PARENT													= 1,
	CHILD													= 2
};

/* inverse combination operators */
enum InverseOperator : BYTE
{
	OP_AND													= 0,
	OP_OR													= 1,
	OP_XOR													= 2
};

enum LocationType : UInt16
{
	LOCAL_LOCATION											= 0,
	REMOTE_LOCATION											= 1
};

enum AccessType : BYTE
{
																	/* values for 'access' property in SchemaEntity */
	ACCESS_PUBLIC											= 0,
	ACCESS_READONLY											= 1,
	ACCESS_PROTECTED										= 2,

																	/* values for 'subAccess' property in SchemaEntity */
	SUBACCESS_PUBLIC										= 0,
	SUBACCESS_WRITE_PROTECTED								= 1,
	SUBACCESS_PROTECTED										= 2,
	SUBACCESS_SUBSCHEMAHIDDEN								= 3,
	SUBACCESS_UNPUBLISHED									= 4,
	SUBACCESS_USER_HOOK										= 5,	/* valid for RootSchema methods only */
	SUBACCESS_SYSTEM_ONLY									= 6,

																	/* values for 'access' flag in Locales */
	LOCALE_LOCAL											= 'L',	/* locale is local to this schema */
	LOCALE_INHERITED										= 'I'	/* locale is inherited from a superschema */
};

/* contract type violated for raise exception API */
enum ExceptionCause : BYTE
{
	EC_PRECONDITION											= 0,	/* precondition violation - default */
	EC_INTERNAL												= 1,	/* internal "assertion failure" */
	EC_POSTCONDITION										= 2		/* postcondition violation */
};

/* scope of exception handler for arm exception API */
enum ExceptionScope : BYTE
{
	ES_LOCAL												= 0,
	ES_GLOBAL												= 1
};

/* mode parameter values for the terminate API */
enum TerminateMode : BYTE
{
	CONDITIONAL_TERMINATE									= 0,
	UNCONDITIONAL_TERMINATE									= 1,
	TERMINATE_ABORT_OPERATION								= 2
};

typedef UInt32			PartitionID;
constexpr PartitionID	MIN_DBFILE_PARTITION_ID				= 1; 
constexpr PartitionID	MAX_DBFILE_PARTITION_ID				= INT_MAX - 15; /* Top bit reserved to mark partID from partIndex */
const PartitionID		PARTITION_ID_BIT					=  0x80000000U;

typedef UInt32				PartitionIndex;
constexpr PartitionIndex	MIN_PARTITION_INDEX					= 0;
constexpr PartitionIndex	MIN_PARTITION_MODULUS				= 1;
constexpr PartitionIndex	MAX_PARTITION_MODULUS				= 1024;
constexpr PartitionIndex	MAX_PARTITION_INDEX					= MAX_PARTITION_MODULUS - 1;
constexpr PartitionIndex	NULL_PARTITION_NDX					= INT_MAX;

/* DskBuffer flag values */
enum DskBufferStatus : BYTE
{
	EMPTY													= 0,
	INUSE													= 1,
	TEMPORARY												= 2,
	UPDATED													= 3,
	CREATED													= 4,
	PERMANENT												= 5,
	DELETED													= 6,
	BUFF_BEING_READ											= 8,
	BUFF_DIRTY												= 9,
	BUFF_OBSOLETE											= 10
};

/* record lock statuses */
enum LockType : BYTE
{
	NO_LOCK													= 0,
	SHARED_LOCK												= 1,
	RESERVED_LOCK											= 2,
	EXCLUSIVE_LOCK											= 3,
	UPDATE_LOCK												= 4,
	LOCKED_BY_NODE_LOCK										= 254,	// Internal use only
	UPGRADING_UPDATE_LOCK									= 253,	// Internal use only
	INVALID_LOCK											= 255,
};

/* lock durations */
enum LockDuration : BYTE
{
	TRANSACTION_DURATION									= 0,
	SESSION_DURATION										= 1
};

/* lock wait time (milliseconds) */
typedef Int32			LockWaitTime;
const LockWaitTime		LOCK_TIMEOUT_IMMEDIATE				= -1;
const LockWaitTime		LOCK_TIMEOUT_INFINITE				= INT_MAX;
const LockWaitTime		LOCK_TIMEOUT_SERVER_DEFINED			= 0;
const LockWaitTime		LOCK_TIMEOUT_PROCESS_DEFINED		= -2;

/* class persistence */
enum ClassPersistence : BYTE
{
	CLASS_DEFAULT_LIFETIME									= 0,
	CLASS_TRANSIENT											= 1,
	CLASS_PERSISTENT										= 2,
	CLASS_SHARED_TRANSIENT									= 3,
	CLASS_SKELETON_TRANSIENT								= 4	/* Transient skeleton for constructor/destructor suppression */
};

/* transaction */
enum JomTransactionType : BYTE
{
	PERSISTENT_TRANSACTION									= 0,
	TRANSIENT_TRANSACTION									= 1
};

/* values for methodInvocation flag in class DskMethod */
enum MethodInvocation : BYTE
{
	NORMAL_METHOD											= '\0',
	MAPPING_METHOD											= '\1',
	EVENT_METHOD											= '\2'
};

/* values for 'updateType' parameter in jomUpdateClass() and method/interface update notifications */
enum JomUpdateType : BYTE
{
	UPDATE_ADDED											= 'A',
	UPDATE_DELETED											= 'D',
	UPDATE_MOVED											= 'M',
	UPDATE_CHECKED_OUT										= 'O',			// JadeSchema::JadeWindow::Method_CheckedOut RootSchema::Method::Method_CheckedOut
	UPDATE_CHECKED_IN										= 'I',			// JadeSchema::JadeWindow::Method_CheckedIn
	UPDATE_UNCHECKED_OUT									= 'U',			// JadeSchema::JadeWindow::Method_UncheckedOut
	UPDATE_LIB_OR_ENTRYPOINT_CHANGED						= 'L',
	UPDATE_OPTION_CHANGED									= 'C',			// JadeSchema::JadeWindow::Method_OptionChanged
	UPDATE_ABSTRACT_CHANGED									= 'B',
	UPDATE_NOTIFY_ADD										= 'a',
	UPDATE_NOTIFY_DELETE									= 'd',
	UPDATE_NOTIFY_MOVE										= 'm',
	UPDATE_CLOSE_FORM										= 'F',
	UPDATE_COMPILED											= 'c',			// JadeSchema::JadeWindow::Method_Compiled
	UPDATE_UNCOMPILED										= 'u',			// JadeSchema::JadeWindow::Method_Uncompiled
};

/* values for methodType parameter in method update notifications and in JomMethodDesc structure */
enum JomMethodType : BYTE
{
	UPDATE_METHOD_NONE										= 0,
	UPDATE_METHOD_CLASS										= 'C',
	UPDATE_METHOD_INTERFACE									= 'I',
	UPDATE_METHOD_TYPE										= 'T',
};

/* values for replicationAllowed, replicationDefault and replicationControl attributes of class Class */
enum ReplicationType : BYTE
{
	REPLICATION_NONE										= 'N',
	REPLICATION_TRANSIENT									= 'T',
	REPLICATION_PERSISTENT									= 'P',
	REPLICATION_ANY											= 'A',
	REPLICATION_CLIENT_DRIVEN								= 'C',
	REPLICATION_SERVER_DRIVEN								= 'S'
};

/* values for executionLocation attribute of class Routine */
enum ExecutionLocation : BYTE
{
	EXECUTION_LOCATION_CLIENT								= 'C',
	EXECUTION_LOCATION_SERVER								= 'S',
	EXECUTION_LOCATION_ANY									= 'A',
	EXECUTION_LOCATION_APPLICATION							= 'a',
	EXECUTION_LOCATION_PRESENTATION							= 'p'
};

typedef UInt32		   	DskDate;
const DskDate			INVALID_DATE_VALUE					= (DskDate) ~0;		/* invalid value indicator for Date */
const DskDate			MIN_DSKDATE_AS_KEY_VALUE			= (DskDate) 0;      /* MIN value for Date as parts of keys (compared as Int32 not UInt32 but >= 0 ) */
const DskDate			MAX_DSKDATE_AS_KEY_VALUE			= INT_MAX;			/* MAX value for Date as parts of keys (compared as Int32 not UInt32) */

typedef UInt32		   	DskTime;
const DskTime			INVALID_TIME_VALUE					= (DskTime) ~0;		/* invalid value indicator for Time */
const DskTime			MIN_DSKTIME_AS_KEY_VALUE			= (DskTime) 0;      /* MIN value for Time as parts of keys (compared as Int32 not UInt32 but >= 0 ) */
const DskTime			MAX_DSKTIME_AS_KEY_VALUE			= INT_MAX;			/* MAX value for Time as parts of keys (compared as Int32 not UInt32) */
const DskTime			MILSECS_IN_DAY  					= 86400000;
const DskTime			MILSECS_IN_HOUR 					= 3600000;
const DskTime			MILSECS_IN_MIN  					= 60000;

typedef Int32		   	DskUTCBias;
const DskUTCBias		INVALID_UTCOFFSET_VALUE				= INT_MAX;

/* values for compiler flag 'deleteIfAbsent' */
enum DeleteIfAbsentFlags : Character
{
	DELETE_IF_ABSENT_NOT_SPECIFIED							= TEXT('Z'),
	DELETE_IF_ABSENT_CONFIRM								= TEXT('C'),
	DELETE_IF_ABSENT_ALWAYS									= TEXT('A'),
	DELETE_IF_ABSENT_NEVER									= TEXT('N')
};

/* values for application types */
enum JomApplicationType : Character
{
	UNKNOWN_APPLICATION_TYPE								= 0,
	GUI_APPLICATION											= TEXT('G'),
	NOFORM_GUI_APPLICATION									= TEXT('F'),
	NONGUI_APPLICATION										= TEXT('S'),
	JAVA_APPLICATION										= TEXT('J'),
	WEB_APPLICATION											= TEXT('W'),
	NONGUI_WEB_APPLICATION									= TEXT('N'),
	REST_SERVICES											= TEXT('R'),
	NONGUI_REST_SERVICES									= TEXT('T')
};

typedef UInt32			NoteEventType;
/* system notification events - sysNotification() */
const NoteEventType		ALL_JOM_EVENTS	 					= 0;			/* Any_System_Event */
const NoteEventType		JOM_UPDATE_EVENT					= UPDATED;		/* Object_Update_Event 3 */
const NoteEventType		JOM_CREATE_EVENT					= CREATED;		/* Object_Create_Event 4 */
const NoteEventType		JOM_DELETE_EVENT					= DELETED;		/* Object_Delete_Event 6 */
/* internel notification events - _internalNotification() */
const NoteEventType		JOM_BEGIN_SAMPLE_EVENT				= 11;			/* Begin_Sample_Event */
const NoteEventType		JOM_END_SAMPLE_EVENT				= 12;			/* End_Sample_Event */
const NoteEventType		JOM_WRITE_SAMPLE_EVENT				= 13;			/* Write_Sample_Event */
const NoteEventType		JOM_SIGN_OFF_PROCESS				= 15;			/* Sign_Off_Process */

/* user notification events - userNotification() */
const NoteEventType		USER_EVENT 		 					= 0x7FFFFFFF;	/* User_Max_Event */
const NoteEventType		USER_BASE_EVENT						= 0x10;			/* User_Base_Event */
const NoteEventType		SYSTEM_BASE_EVENT					= 0x80000000;	/* System_Base_Event */
const NoteEventType		ALL_USER_EVENTS						= (NoteEventType) ~0; /* Any_User_Event */

/* eventType for endNotification and endNotificationForSubscriber */
const NoteEventType		END_ANY_EVENT	 					= 0;

#if defined(__cplusplus)

inline bool isUserEvent(NoteEventType eventType)
{
	return eventType >= USER_BASE_EVENT;
}

inline bool isSystemEvent(NoteEventType eventType)
{
	return eventType == ALL_JOM_EVENTS || (eventType >= JOM_UPDATE_EVENT && eventType <= JOM_DELETE_EVENT);
}

inline bool isInternalEvent(NoteEventType eventType)
{
	return eventType >= JOM_BEGIN_SAMPLE_EVENT && eventType <= JOM_SIGN_OFF_PROCESS;
}

inline bool isSamplingEvent(NoteEventType eventType)
{
	return eventType >= JOM_BEGIN_SAMPLE_EVENT && eventType <= JOM_WRITE_SAMPLE_EVENT;
}

#endif /* defined(__cplusplus) */

/* 
 * internal notification event numbers 
 * 
 * Note: all internal notifications are registered in the RootSchema::SystemEvents Global Constant Category
 * new values should be added there, even if they are not used by the Jade code, and duplicated here to
 * ensure all the values are unique
 */

/* notification event numbers, caused on system System class */
const NoteEventType		JOM_FILE_DELETE_EVENT				= SYSTEM_BASE_EVENT + 1;	/* File_Delete_Event */
const NoteEventType		JOM_SCHEMA_ADD_EVENT				= SYSTEM_BASE_EVENT + 2;	/* Schema_Add_Event */
const NoteEventType		JOM_SDS_DATABASE_ROLE_CHANGE_EVENT  = 22;						/* RootSchema::SDSEventTypes::SDS_RoleChangeEvent Global Constant */

const NoteEventType		JOM_CACHE_SYNCHRONISATION_EVENT		= SYSTEM_BASE_EVENT + 8;	/* Cache_Synchronisation_Event */
const NoteEventType		JOM_REQ_NODE_LOCK_REMOVAL_EVENT     = USER_BASE_EVENT + 12;		/* on System Class */

const NoteEventType		JOM_UNLOCK_NODE_LOCK_EVENT          = SYSTEM_BASE_EVENT + 9;	/* Unlock_Node_Lock_Event */
const NoteEventType		JOM_LOCAL_ONLY_LOCKS_EVENT			= SYSTEM_BASE_EVENT + 10;	/* Local_Only_Locks_Event */

const NoteEventType		JOM_CLASS_CLOSE_EVENT				= SYSTEM_BASE_EVENT + 113;	/* Close_Class_Event */

const NoteEventType		JOM_LOADER_PROGRESS_EVENT			= SYSTEM_BASE_EVENT + 99;	/* JadeFileLoaderProgressEvent */

/* notification event numbers, caused on node Node class */
const NoteEventType		JOM_INTERRUPT_PROCESS		        = SYSTEM_BASE_EVENT + 11; 	/* Jom_Interrupt_Process_Event */

/* reorg notification event numbers, caused on rootSchema Schema class */
const NoteEventType		JOM_REORG_START_EVENT				= SYSTEM_BASE_EVENT + 100;	/* ReorgStartEvent */
const NoteEventType		JOM_REORG_FINISH_EVENT				= SYSTEM_BASE_EVENT + 101;	/* ReorgFinishEvent */
const NoteEventType		JOM_REORG_ABORT_EVENT				= SYSTEM_BASE_EVENT + 102;	/* ReorgAbortEvent */
const NoteEventType		JOM_REORG_WAIT_TRANSITION_EVENT		= SYSTEM_BASE_EVENT + 103;	/* ReorgWaitTransitionEvent */
const NoteEventType		JOM_REORG_CLASS_IN_USE_EVENT		= SYSTEM_BASE_EVENT + 104;	/* ReorgClassInUseEvent */
const NoteEventType		JOM_REORG_PROGRESS_EVENT			= SYSTEM_BASE_EVENT + 105;	/* ReorgProgressEvent */
const NoteEventType		JOM_REORG_SHUTDOWN_EVENT			= SYSTEM_BASE_EVENT + 106;	/* ReorgShutdownEvent */
const NoteEventType		JOM_REORG_SUSPENDED_EVENT			= SYSTEM_BASE_EVENT + 107;	/* ReorgSuspendedEvent */
const NoteEventType		JOM_REORG_EXITING_EVENT				= SYSTEM_BASE_EVENT + 109;

/* class notification events : caused on rootSchema Schema class */
const NoteEventType		JOM_CLASS_ADD_EVENT					= SYSTEM_BASE_EVENT + 111;	/* Class_Add_Event */
const NoteEventType		JOM_CLASS_DELETE_EVENT				= SYSTEM_BASE_EVENT + 112;	/* Class_Delete_Event */
const NoteEventType		JOM_CLASS_MOVE_EVENT				= SYSTEM_BASE_EVENT + 119;	/* Class_Move_Event */
const NoteEventType		JOM_CLASS_NEWVERSION_EVENT			= SYSTEM_BASE_EVENT + 401;	/* Class_New_Version */
const NoteEventType		JOM_CLASS_DELETEPRIORVERSION_EVENT	= SYSTEM_BASE_EVENT + 402;	/* Class_Delete_Prior_Version */
const NoteEventType		JOM_METHOD_DELETEPRIORVERSION_EVENT	= SYSTEM_BASE_EVENT + 403;	/* Method_Delete_Prior_Version */
const NoteEventType		JOM_CLASS_DELETECURRENTVERSION_EVENT= SYSTEM_BASE_EVENT + 404;	/* Class_Delete_Current_Version */
const NoteEventType		JOM_CLASS_DELETELATESTVERSION_EVENT = SYSTEM_BASE_EVENT + 405;	/* Class_Delete_Latest_Version */

/* JADE Constant/globalConstants/Category Notification Events, caused on rootSchema Schema class */
const NoteEventType		JOM_GLOBALCONSTANT_ADD_EVENT		= SYSTEM_BASE_EVENT + 113;	/* GlobalConstant_Add */
const NoteEventType		JOM_GLOBALCONSTANT_DELETE_EVENT		= SYSTEM_BASE_EVENT + 218;	/* GlobalConstant_Delete */
const NoteEventType		JOM_GLOBALCONSTANT_CHANGE_EVENT		= SYSTEM_BASE_EVENT + 217;	/* GlobalConstant_Change */
const NoteEventType		JOM_CONSTANTCATEGORY_DELETE_EVENT	= SYSTEM_BASE_EVENT + 114;	/* Category_Delete_Event */

const NoteEventType		JOM_APPLICATION_ADD_EVENT			= SYSTEM_BASE_EVENT + 124;	/* Application_Add_Event */
const NoteEventType		JOM_SCHEMA_DELETE_EVENT				= SYSTEM_BASE_EVENT + 211;	/* Schema_Delete_Event for painter */
const NoteEventType		JOM_SCHEMA_CLOSE_EVENT				= SYSTEM_BASE_EVENT + 210;	/* Schema_Close_Event */
const NoteEventType		JOM_SCHEMA_CHANGE_DFTLOCALE			= SYSTEM_BASE_EVENT + 209;	/* Change_DftLocale_event */

/* dynamic property notification events, caused on rootSchema Schema class */
const NoteEventType		JOM_DYNAMIC_PROPERTY_CREATE_EVENT	= SYSTEM_BASE_EVENT + 300;	
const NoteEventType		JOM_DYNAMIC_PROPERTY_DELETE_EVENT	= SYSTEM_BASE_EVENT + 301;	
const NoteEventType		JOM_DYNAMIC_PROPERTY_CHANGE_EVENT	= SYSTEM_BASE_EVENT + 302;	
const NoteEventType		JOM_DYNAMIC_PROPERTY_CLUSTER_CREATE_EVENT	= SYSTEM_BASE_EVENT + 303;	
const NoteEventType		JOM_DYNAMIC_PROPERTY_CLUSTER_DELETE_EVENT	= SYSTEM_BASE_EVENT + 304;	
const NoteEventType		JOM_DYNAMIC_PROPERTY_ADD_INVERSE_EVENT		= SYSTEM_BASE_EVENT + 305;	
const NoteEventType		JOM_DYNAMIC_PROPERTY_REMOVE_INVERSE_EVENT	= SYSTEM_BASE_EVENT + 306;	
const NoteEventType		JOM_DYNAMIC_PROPERTY_UPDATE_COMMIT_EVENT	= SYSTEM_BASE_EVENT + 307;	

/* JadeInterface Notification Events */
const NoteEventType		JOM_JADEINTERFACE_ADD_EVENT			= SYSTEM_BASE_EVENT + 130;	/* JadeInterface_Add_Event */
const NoteEventType		JOM_JADEINTERFACE_DELETE_EVENT		= SYSTEM_BASE_EVENT + 131;	/* JadeInterface_Delete_Event */
const NoteEventType		JOM_JADEINTERFACE_CHANGE_EVENT		= SYSTEM_BASE_EVENT + 132;	/* JadeInterface_Change_Event */
const NoteEventType		JOM_JADEINTERFACE_MAP_ADD_EVENT		= SYSTEM_BASE_EVENT + 133;	/* JadeInterface_Map_Add_Event */
const NoteEventType		JOM_JADEINTERFACE_MAP_DELETE_EVENT	= SYSTEM_BASE_EVENT + 134;	/* JadeInterface_Map_Delete_Event */
const NoteEventType		JOM_JADEINTERFACE_MAP_CHANGE_EVENT	= SYSTEM_BASE_EVENT + 135;	/* JadeInterface_Map_Change_Event */

/* method notification events, caused on Method class */
const NoteEventType		JOM_METHOD_CREATE_EVENT				= SYSTEM_BASE_EVENT + 117;	/* Method_Add_Event */
const NoteEventType		JOM_METHOD_DELETE_EVENT				= SYSTEM_BASE_EVENT + 103;	/* Method_Delete_Event */
const NoteEventType		JOM_METHOD_UPDATE_EVENT				= SYSTEM_BASE_EVENT + 154;	/* Method_Change_Event */
const NoteEventType		JOM_METHOD_RENAME_EVENT				= SYSTEM_BASE_EVENT + 132;	/* Method_Rename_Event */

/* property notification events, caused on Property class */
const NoteEventType		JOM_PROPERTY_CREATE_EVENT			= SYSTEM_BASE_EVENT + 115;	/* Property_Add_Event */
const NoteEventType		JOM_PROPERTY_DELETE_EVENT			= SYSTEM_BASE_EVENT + 116;	/* Property_Delete_Event */

/* caused on JadeWindow in dev environment */
const NoteEventType		JOM_PROPERTY_UPDATE_EVENT			= SYSTEM_BASE_EVENT + 201;	/* Property_Change_Event */

/* package notification events , caused on rootSchema Schema class */
const NoteEventType		JOM_PACKAGE_ADD_EVENT				= SYSTEM_BASE_EVENT + 120;	/* Package_Add_Event */
const NoteEventType		JOM_PACKAGE_DELETE_EVENT			= SYSTEM_BASE_EVENT + 121;	/* Package_Delete_Event */
const NoteEventType		JOM_PACKAGE_CHANGE_EVENT			= SYSTEM_BASE_EVENT + 122;	/* Package_Change_Event */
const NoteEventType		PACKAGE_ELEMENT_DELETE_EVENT		= SYSTEM_BASE_EVENT + 16;	/* PackageElementDeleteEvent */

/* TranslatableString notification events */
const NoteEventType		TRANSLATABLESTRING_DELETE_EVENT		= SYSTEM_BASE_EVENT + 141;	/* TranslatableStringDeleteEvent */

/* RPS management events -- caused on process */
const NoteEventType		RPS_STOP_EVENT						= 212;						/* RootSchema::Process::RPS_DATAPUMP_STOP_EVENT */
/* SDS/RPS management events -- caused on system */
const NoteEventType		RPS_REORG_RESTART_EVENT				= 220;						/* RootSchema::System::RpsReorgRestartEvent - RPS_SchemaTransition */
const NoteEventType		SDS_REORG_FINISHED_EVENT			= 221;						/* RootSchema::System::SdsReorgFinishedEvent */
const NoteEventType		RPS_DP_RESTART_EVENT				= 222;						/* RootSchema::System::RPS_DataPumpRestartEvent */

/*Statistics*/
const NoteEventType		JOM_LOCAL_PROC_STATS_EVENT			= SYSTEM_BASE_EVENT + 240;	/* Process_Local_Stats_Event */
const NoteEventType		JOM_REMOTE_PROC_STATS_EVENT			= SYSTEM_BASE_EVENT + 241;	/* Process_Remote_Stats_Event */
const NoteEventType		JOM_WEB_STATS_EVENT					= SYSTEM_BASE_EVENT + 242;	/* Process_Web_Stats_Event */

/* Diagnostic events */
const NoteEventType		JOM_PROC_CALL_STACK_INFO_EVENT		= SYSTEM_BASE_EVENT + 243; /* Process_Call_Stack_Info_Event */
const NoteEventType		JOM_PROC_TDB_FILE_INFO_EVENT		= SYSTEM_BASE_EVENT + 244; /* Process_TDB_Info_Event */
const NoteEventType		JOM_PROC_TDB_FILE_ANALYSIS_EVENT	= SYSTEM_BASE_EVENT + 245; /* Process_TDB_Analysis_Event */
const NoteEventType		JOM_PROC_METHOD_CACHE_STATS_EVENT	= SYSTEM_BASE_EVENT + 248; /* Process_Method_Cache_Stats_Event */

/* Other process related events */
const NoteEventType		JOM_PROC_TRANSLATE_CLS_NO_EVENT		= SYSTEM_BASE_EVENT + 246; /* Process_Translate_ClsNo_Event */
const NoteEventType		JOM_JOOB_REQUEST_SIGNOFF_EVENT		= SYSTEM_BASE_EVENT + 247;

/* SchemaBrowser schema add userNotification */
const NoteEventType     SCHEMABROWSER_SCHEMA_ADD			= 110;

/* JadeWindow script execution completed event */
const NoteEventType     EXECUTION_COMPLETE					= 150;

/* JadeCompilerWarningConfig update userNotification */
const NoteEventType		JOM_COMPILER_CONFIG_UPDATE			= SYSTEM_BASE_EVENT + 420;

/* notification response type */
typedef enum 
{
	NOTE_ALL												= 0,
	NOTE_AND_CANCEL											= 1,
	NOTE_ON_CHANGE											= 2,
	NOTE_GROUP												= 256
} NoteResponseType;

/* subscriber type */
typedef enum 
{
	NOTE_SUBSCRIBER_JADE									= 0,
	NOTE_SUBSCRIBER_DOTNET									= 2
} NoteSubscriberType;

/* database file kind number ranges */
typedef UInt16			DbFileNum;
const DbFileNum			MIN_CONTROL_DBFILE_NUM				= 2;
const DbFileNum			MAX_CONTROL_DBFILE_NUM				= 10;
const DbFileNum			MIN_ENVIRON_DBFILE_NUM				= 11;
const DbFileNum			MAX_ENVIRON_DBFILE_NUM				= 20;
const DbFileNum			MIN_SYSTEM_DBFILE_NUM				= 21;
const DbFileNum			MAX_SYSTEM_DBFILE_NUM				= 30;
const DbFileNum			MIN_USER_SCHEMA_DBFILE_NUM			= 31;
const DbFileNum			MAX_USER_SCHEMA_DBFILE_NUM			= 40;
const DbFileNum			MIN_UTILITY_DBFILE_NUM				= 41;
const DbFileNum			MAX_UTILITY_DBFILE_NUM				= 50;
const DbFileNum			MIN_USER_DATA_DBFILE_NUM			= 51;

const DbFileNum			ENVIRON_FILENUM						= MIN_ENVIRON_DBFILE_NUM + 1;
const DbFileNum			STATS_FILENUM						= MIN_ENVIRON_DBFILE_NUM + 2;   // NO LONGER USED as of 7.2/2016
const DbFileNum			AUX_ENVIRON_FILENUM					= MIN_ENVIRON_DBFILE_NUM + 3;
const DbFileNum			RPS_TRANS_FILENUM					= MIN_UTILITY_DBFILE_NUM + 3;

const DbFileNum			_CONTROL_DBFILE_NUM					= 1;
const DbFileNum			_TDB_DBFILE_NUM						= 9;

const DbFileNum			_SYSTEM_DBFILE_NUM					= MIN_SYSTEM_DBFILE_NUM;
const DbFileNum			_SYSXRF_DBFILE_NUM					= MIN_SYSTEM_DBFILE_NUM + 1;
const DbFileNum			_SYSGUI_DBFILE_NUM					= MIN_SYSTEM_DBFILE_NUM + 2;
const DbFileNum			_SYSINT_DBFILE_NUM					= MIN_SYSTEM_DBFILE_NUM + 3;
const DbFileNum			_SYSDEV_DBFILE_NUM					= MIN_SYSTEM_DBFILE_NUM + 4;
const DbFileNum			_JADEAPP_DBFILE_NUM					= MIN_SYSTEM_DBFILE_NUM + 5;
const DbFileNum			_JADEDEF_DBFILE_NUM					= MIN_SYSTEM_DBFILE_NUM + 6;
const DbFileNum			_SYSTOOLS_DBFILE_NUM				= MIN_SYSTEM_DBFILE_NUM + 7;
const DbFileNum			_SYSDEF_DBFILE_NUM					= MAX_SYSTEM_DBFILE_NUM;

const DbFileNum			_USERSCM_DBFILE_NUM					= MIN_USER_SCHEMA_DBFILE_NUM;
const DbFileNum			_USERXRF_DBFILE_NUM					= MIN_USER_SCHEMA_DBFILE_NUM + 1;
const DbFileNum			_USERGUI_DBFILE_NUM					= MIN_USER_SCHEMA_DBFILE_NUM + 2;
const DbFileNum			_USERINT_DBFILE_NUM					= MIN_USER_SCHEMA_DBFILE_NUM + 3;
const DbFileNum			_USERDEV_DBFILE_NUM					= MIN_USER_SCHEMA_DBFILE_NUM + 4;
const DbFileNum			_SYSPRIOR_DBFILE_NUM				= MIN_USER_SCHEMA_DBFILE_NUM + 5;// used by upgrade scripts
const DbFileNum			_ROOTDEF_DBFILE_NUM					= MAX_USER_SCHEMA_DBFILE_NUM;

const DbFileNum			_MONITOR_DBFILE_NUM					= MIN_UTILITY_DBFILE_NUM;
const DbFileNum			_DMPLOAD_DBFILE_NUM					= MIN_UTILITY_DBFILE_NUM + 1;   // NO LONGER USED
const DbFileNum			_REPORTS_DBFILE_NUM					= MIN_UTILITY_DBFILE_NUM + 2;
const DbFileNum			_RPSTRANS_DBFILE_NUM				= MIN_UTILITY_DBFILE_NUM + 3;

const DbFileNum			_SINDEXDEFS_DBFILE_NUM				= MIN_UTILITY_DBFILE_NUM + 4;
const DbFileNum			_SINDEXES_DBFILE_NUM				= MIN_UTILITY_DBFILE_NUM + 5;

enum SchemaStatus
{
	SCHEMA_STATUS_NONE										= 0,
	SCHEMA_BEING_CREATED									= 1,	        // infant schema under construction
	SCHEMA_BEING_DELETED									= -1,			// delete/remove started
	SCHEMA_PARTLY_DELETED									= -2,			// class instances deleted
	SCHEMA_DELETING_SELF									= -3,			// Schema instance delete started
	SCHEMA_UNVERSIONABLE									= 2
};

enum PMore : BYTE 
{
	Done													= 0,
	More													= 1
};

enum PUsage : BYTE	
{
	USAGE_CONSTANT											= 0,
	USAGE_INPUT												= 1,
	USAGE_IO												= 2,
	USAGE_OUTPUT											= 3,
	USAGE_KEY												= 4,
};

enum PFormat : UInt16 
{
	DSKUNDEF												= 0,		
	DSKCSTRING												= DSKCSTRING_PRIMITIVE,		
	DSKPSTRING												= 2,		
	DSKOBJECTID												= 3,		
	DSKINTEGER												= DSKINTEGER_PRIMITIVE,		
	DSKANY													= DSKANY_PRIMITIVE,		
	DSKCHARACTER											= DSKCHARACTER_PRIMITIVE,		
	DSKBOOLEAN												= DSKBOOLEAN_PRIMITIVE,		
	DSKPOINT												= DSKPOINT_PRIMITIVE,		
	DSKOIDKEYLIST											= 9,		
	DSKINTEGERLIST											= 10,		
	DSKBINARY												= DSKBINARY_PRIMITIVE,		
	DSKPOINTERLIST											= 12,		
	DSKSHORTOIDLIST											= 13,		
	DSKCHARBLOCKPOINTER 									= 14,		
	DSKCLASSFEATURE											= 15,		
	DSKDATE													= DSKDATE_PRIMITIVE,		
	DSKTIME													= DSKTIME_PRIMITIVE,		
	DSKTIMESTAMP											= DSKTIMESTAMP_PRIMITIVE,		
	DSKDECIMAL												= DSKDECIMAL_PRIMITIVE,		
	DSKFLOAT												= 20,		
	DSKDOUBLE												= DSKREAL_PRIMITIVE,		
	DSKREAL													= DSKDOUBLE,
	DSKREAL4												= DSKFLOAT,	
	DSKBINARYPTR											= 22,		// used to pass a binary ptr to Jade exe rather than use a Jade binary
	DSKJADEEXTSTR											= 23,		// used to pass Jade strings passed to external fns
	DSKSHORTOBJECTID										= 24,		
	DSKJADESTRING											= 25,		
	DSKBUFFERPTR											= 26,		
	DSKJADEPRIMITIVE										= 27,		
	DSKPROPERTYDESC											= 28,		
	DSKWINHANDLE											= 29,		
	DSKPARAMLIST											= 30,		
	DSKSTRINGLIST											= 31,		
	JADEPARAMETERLIST										= 32,		
	DSKJADEBINARY											= 33,		
	DSKBINARYBLOCKPOINTER									= 34,		
	DSKANYLIST												= 35,		
	DSKNULL													= 36,		
	DSKPMAPID												= 37,	// used to pass internal ids which are converted to jom objects
	DSKBUFFERLIST											= 38,		
	DSKJOMLOCKREQUEST										= 39,		
	DSKRECTANGLE2D											= 40,		
	DSKNULLPOINTER											= 41,		
	DSKINTEGER64											= DSKINTEGER64_PRIMITIVE,		
	DSKDBCONTROLINFO										= 43,		
	DSKMEMORYADDRESS										= DSKMEMORYADDRESS_PRIMITIVE,		
	DSKPRIMFEATURE											= 45,		
	DSKCLASSFEATURELEVEL									= 46,		
	DSKDBMETHODDESC											= 47,		
	DSKFEATURENAME											= 48,		
	DSKINTERFACEFEATURE										= 49,		
	DSKOBJECTUPDATEDESC										= 50,		
	DSKSTRINGUTF8											= DSKSTRINGUTF8_PRIMITIVE,		
	DSKBYTE													= DSKBYTE_PRIMITIVE,		
	DSKTIMESTAMPINTERVAL									= DSKTIMESTAMPINTERVAL_PRIMITIVE,		
	DSKJADESTRINGUTF8										= 54,		
	DSKINTEGER64LIST										= 55,		
	DSKJOSUTCTIMESTAMP										= 56,		
	DSKTIMESTAMPOFFSET										= DSKTIMESTAMPOFFSET_PRIMITIVE,		
	DSKINSTANCEID											= 58,		
	DSKINSTANCEIDLIST										= 59,		
	DSKMETHODDESC											= 60,		
	DSKPMAPBYTE												= 61,	// used to store byte integers 0 - 255
	DSKJOMSLOBINFO											= 62,		
	DSKPOINTER												= 63,		

	// datatstrm.cpp: UnloadMessageData & UnloadMessageReply handle only PFormat < 64

	DSKDICTKEYBLOCKPOINTER									= 64,		
	DSKINTERPPARAMCALLBACK									= 65,
};

/* Callback ID's to define callback functions from CPP back into JOOB */
enum JoobManagedCallbackId
{
	// jomsupp
	NoOp													= 0,

	// jomsupp
	GetAndValidateUser										= 1,
	IsUserValid												= 2,
	MethodCallback											= 3,
	SendMsg													= 4,
	ClientNodeInit											= 5,

	// jom
	TerminateProcessOnDisconnect							= 6,
	ProcessRequestSignOff									= 7,

	// jomos
	AppConfigIniFileRead									= 8,
	AppConfigIniFileWrite									= 9,
};

/* Object reference update mode */
enum InverseUpdateMode
{
	MANUAL_UPDATE 											= 0,
	MANUAL_AUTOMATIC_UPDATE									= 1,
	AUTOMATIC_UPDATE 										= 2,
	SYSTEM_AUTOMATIC_UPDATE 								= 3,
	AUTOMATIC_DEFERRED_UPDATE								= 4,
	MANUAL_AUTOMATIC_DEFERRED_UPDATE						= 5
};

/* DbClassMap modes */
enum DbClassMapMode
{
	SHARED_INSTANCES										= 0,
	SUBOBJECT_INSTANCES										= 1,
	ALL_INSTANCES											= 2
};

enum ObjectVersionState
{
	OBJVERSTATE_CURRENT_ONLY								= 0,
	OBJVERSTATE_VERSIONED_CURRENT							= 1,
	OBJVERSTATE_VERSIONED_LATEST							= 2,
	OBJVERSTATE_LATEST_ONLY 								= 3,
	OBJVERSTATE_ERROR		 								= 250,
	OBJVERSTATE_METAPARENT_NYI								= 251
};

enum Lifetime
{
	LIFETIME_PERSISTENT										= 0,
	LIFETIME_TRANSIENT										= 1,
	LIFETIME_SHAREDTRANSIENT								= 3
};

typedef enum
{
	VOLATILITY_VOLATILE										= 0x00,
	VOLATILITY_STABLE										= 0x08,
	VOLATILITY_FROZEN										= 0x04,
	VOLATILITY_UNKNOWN										= 0xFF		/* runtime only - not stored */
} ObjectVolatility;

typedef enum
{
	DbOV_Transparent										= 0x00,
	DbOV_Volatile											= VOLATILITY_VOLATILE +1,
	DbOV_Stable												= VOLATILITY_STABLE +1,
	DbOV_Frozen												= VOLATILITY_FROZEN +1
} DbObjectVolatility;

enum DatabaseRole
{
	DB_Undefined											= 0,
	DB_Primary												= 1,
	DB_Secondary											= 2
};

enum DatabaseSubrole
{
	SR_Undefined											= 0,
	SR_Native												= 1,
	SR_Relational											= 2
};

/* Following enumeration must match constants defined in RootSchema::GlobalConstants::SdsCallbackID */
enum SdsCallbackId
{
	// JOM Callbacks
	JCB_Undefined											= 0,
	JCB_TransitionSchemaCheck								= 1,
	JCB_NonTransitionSchemaCheck							= 2,
	JCB_EndTransitionNormal									= 3,
	JCB_EndTransitionManaged								= 4,
	// RPS Callbacks
	RPSCB_MappingCheck										= 101,
	RPSCB_ExecuteSql										= 102
};

enum SdsTransOp
{
	SDS_Undefined											= 0,
	SDS_SuppressRpsTransDeletes								= 1,
	SDS_SuppressTransaction									= 2
};

/* Following enumeration must match constants defined in RootSchema::GlobalConstants::ConsoleMsgTag */
enum ConsoleMessageTag
{
	ConMsg_Default											= 0,
	ConMsg_Error											= 1,
	ConMsg_Warning											= 2,
	ConMsg_Info												= 3,
	ConMsg_Raw												= 4
};

/* Cache Types */
enum CacheType
{
	UNKNOWN_CACHE_TYPE										= 0,
	PERSISTENT_CACHE										= 1,
	TRANSIENT_CACHE											= 2,
	REMOTE_TRANSIENT_CACHE									= 3,
	PROCESS_TRANSIENT_CACHE									= 4
};

/* Exception handler return disposition */
enum ExceptionHandlerReturn
{
	E_PASS_BACK	 											= -1,		/* Ex_Pass_Back - pass exception to prior handler */
	E_CONTINUE												= 0,		/* Ex_Continue - ignore exception and continue */
	E_ABORT_ACTION											= 1,		/* Ex_Abort_Action - cutback stack to idle state */
	E_RESUME		 										= 2,		/* Ex_Resume_Next - resume at next op in method that armed handler */
	E_RESUME_METHOD_EPILOG									= 3,		/* Ex_Resume_Method_Epilog - resume at method epilog or end of method if no epilog */
};

/* bitwise enumeration used in [Collection::_flags] */
enum CollectionHeaderFlags					
{ 
	CH_Flag_None											= 0,
	CH_Flag_RemovesSuspended								= 1,
	JB_Flag_EmbeddedVector									= 2,
	JB_Flag_ShortInstIDVector								= 4,
	JB_Flag_UnauditedSingleFile								= 8,
	CH_Flag_VariableArray									= 16		// the array has been upgraded (fixed sized entries to variable)
};

/* bitwise enumeration used to pass collection boolean attributes to CollBlock related JOM APIs */
enum CollBlockFlags					
{ 
	CB_Flag_None											= 0,
	CB_Flag_SingleFile										= 1,
	CB_Flag_UDRBlock										= 2,
	CB_Flag_UDRSingleFile									= (CB_Flag_SingleFile | CB_Flag_UDRBlock)
};

// these values must match constants defined on RelationalView in RootSchema
// In RelationalView, 0 means ODBC RelationalView.
// In RPS Node Control File, 0 means use default from RelationalView object
//                           other values mean the user has overridden the default value on the RPS node
//
// Note the numerical order is significant the >= operator is used to determine backwards compatibility

enum RPSDatabaseType
{
	RPS_DatabaseUseDefault									= 0,
	RPS_SqlServer2000										= 1,
	RPS_SqlServer2005										= 2,
	RPS_SqlServer2008										= 3

#ifdef SUPPORT_SQL2016
	,
	RPS_SqlServer2008R2										= 4,
	RPS_SqlServer2012									    = 5,
	RPS_SqlServer2014                                       = 6,
	RPS_SqlServer2016                                       = 7
#endif
	
};

enum Rps_Restart_State
{
	RESTART_STATE_UNDEFINED									= -1,
	RESTART_NOSCRIPT										=  0,
	RESTART_AUTOSCRIPT										=  1,
	RESTART_MANUALSCRIPT									=  2,
	RESTART_MAPPINGDELETED									=  3
};

/* database file kinds */
enum DbFileKind
{
	DBFILE_UNDEFINED_KIND									= 0,
	DBFILE_CONTROL_KIND										= 1,
	DBFILE_ENVIRON_KIND										= (1 << 1),
	DBFILE_SYSTEM_KIND										= (1 << 2),
	DBFILE_USER_SCHEMA_KIND									= (1 << 3),
	DBFILE_UTILITY_KIND										= (1 << 4),
	DBFILE_USER_DATA_KIND									= (1 << 5)
};

enum DbTimestamp
{
	Db_Undefined_TS											= 0,
	Db_Creation_TS											= 1,
	Db_Open_TS												= 2,
	Db_LatestBackup_TS										= 3,
	Db_LatestFullBackup_TS									= 4
};

enum DbFileTimestamp
{
	DbFile_Undefined_TS										= 0,
	DbFile_Creation_TS										= 1,
	DbFile_Modified_TS										= 2,
	DbFile_StableBackup_TS									= 3,
	DbFile_StableFullBackup_TS								= 4
};

/* values for unitTestFlags in class DskMethod */
enum UnitTestFlags
{
	UNIT_TEST_FLAGS_NONE									= 0,
	UNIT_TEST_FLAGS_UNIT_TEST								= 1,
	UNIT_TEST_FLAGS_UNIT_TEST_BEFORE						= 2,
	UNIT_TEST_FLAGS_UNIT_TEST_AFTER							= 4,
	UNIT_TEST_FLAGS_UNIT_TEST_BEFORE_CLASS					= 8,
	UNIT_TEST_FLAGS_UNIT_TEST_AFTER_CLASS					= 16,
	UNIT_TEST_FLAGS_UNIT_TEST_INGORE						= 32,
	UNIT_TEST_FLAGS_UNIT_TEST_BEFORE_ALL					= 64,
	UNIT_TEST_FLAGS_UNIT_TEST_AFTER_ALL						= 128,
};

/* values for _deprecated property on class SchemaEntity */
enum DeprecatedFlags : Byte
{
	NOT_DEPRECATED											= 0,
	DEPRECATED												= 1,
};

/* values for compiler flags parameter */
enum CompilerFlags
{
	COMP_FLAGS_NONE											= 0,
	COMP_USE_LATEST_VERSIONS								= 1,
	COMP_IGNORE_EMPTY_METHODS								= 2,
	COMP_USE_CURRENT_VERSIONS								= 4,
	COMP_ONLY_STRUCTURAL_VERSIONING							= 8,
	COMP_COMPILE_UNCHANGED_METHODS							= 16,
	COMP_COMPILE_EXTERNAL_WIZARD_LOAD						= 32
};

enum TerminationCallBackType
{
	NodeTerminationCallBack									= 1,
	ProcessTerminationCallBack								= 2,
	GlobalTerminationCallBack								= 3
};

/* caller id for NoteMgr::markNoteEntry */
enum NoteCallerId
{
	VIA_CAUSE_EVENT											= 1,
	VIA_CAUSE_SDS_EVENT										= 2,
	VIA_PUT_OBJECT											= 3,
	VIA_UPDATE_OBJECT										= 4,
	VIA_CAUSE_SDE_EVENT										= 5 
};

/* node types */
enum Node_Type
{
	UNDEFINED_NODETYPE										= 0,																					// RootSchema::Node::Type_Undefined
	DATABASE_SERVER											= 1,																					// RootSchema::Node::Type_DatabaseServer
	APPLICATION_SERVER										= 2,																					// RootSchema::Node::Type_ApplicationServer
	APPLICATION_SERVER_AND_DATABASE_SERVER					= APPLICATION_SERVER + DATABASE_SERVER,													// RootSchema::Node::Type_ApplicationServerAndDatabaseServer
	STANDARD_CLIENT_NODE									= 4,																					// RootSchema::Node::Type_StandardClient
	STANDARD_CLIENT_NODE_AND_DATABASE_SERVER				= STANDARD_CLIENT_NODE + DATABASE_SERVER,												// RootSchema::Node::Type_StandardClientAndDatabaseServer
	STANDARD_CLIENT_NODE_AND_APPLICATION_SERVER 			= 6,																					// illegal value
	STANDARD_CLIENT_NODE_AND_APPLICATION_AND_DATABASE_SERVER = STANDARD_CLIENT_NODE_AND_APPLICATION_SERVER + DATABASE_SERVER,						// illegal value
	JADCLIENT_NODE											= 16,																					// RootSchema::Node::Type_NonGuiClient
	JADCLIENT_NODE_AND_DATABASE_SERVER						= JADCLIENT_NODE + DATABASE_SERVER,														// RootSchema::Node::Type_NonGuiClientAndDatabaseServer
	DBADMIN_NODE											= 32,																					// RootSchema::Node::Type_DatabaseAdmin
	DBADMIN_NODE_AND_DATABASE_SERVER						= DBADMIN_NODE + DATABASE_SERVER														// RootSchema::Node::Type_DatabaseAdminAndDatabaseServer
};

#if defined(__cplusplus)

inline Node_Type operator | (Node_Type a, Node_Type b)		{ return (Node_Type) ((UInt32) a | (UInt32) b); }
inline Node_Type operator & (Node_Type a, Node_Type b)		{ return (Node_Type) ((UInt32) a & (UInt32) b); }
inline bool isApplicationServer(Node_Type nodeType)			{ return (nodeType & APPLICATION_SERVER) == APPLICATION_SERVER; }
inline bool isStandardClient(Node_Type nodeType)			{ return (nodeType & STANDARD_CLIENT_NODE) == STANDARD_CLIENT_NODE; }
inline bool isJadClient(Node_Type nodeType)					{ return (nodeType & JADCLIENT_NODE) == JADCLIENT_NODE; }
inline bool isDbAdmin(Node_Type nodeType)					{ return (nodeType & DBADMIN_NODE) == DBADMIN_NODE; }

#endif /* defined(__cplusplus) */

enum CollectionBlockType
{
	CB_Type_Undefined										= 0,
	CB_Type_Vector											= 1,
	CB_Type_Segment											= 2
};

#if !defined(BYTE_ORDER)
#error BYTE_ORDER and either BIG_ENDIAN or LITTLE_ENDIAN need to be defined
#endif

typedef UInt32 ClassIDBits;

#pragma warning ( push )
#pragma warning ( disable : 4201 )	// nonstandard extension used : nameless struct/union

typedef struct ClassID
{
	union
	{
		struct
		{
			ClassIDBits classNo : 22;
			ClassIDBits classLt : 2;
			ClassIDBits notused : 8;
		};
		struct
		{
			ClassIDBits allbits : 24;
			ClassIDBits _notused : 8;
		};
	};

#ifdef __cplusplus
	ClassID(ClassIDBits bits = 0)								{ allbits = bits; _notused = 0; }

	void				set(ClassNumber);
	void				set(ClassIDBits);
	void				set(ClassID);

	ClassNumber			getClassNo() const						{ return classNo; }
	ClassIDBits			getClassId() const						{ return allbits; }
	ClassIDBits			getClassIdBits() const					{ return allbits; }

	Lifetime			lifetime() const						{ return (Lifetime) classLt; }

	bool				isNull() const;

	bool				isPersistent() const					{ return classLt == LIFETIME_PERSISTENT; }
	bool				isNonSharedTransient() const			{ return classLt == LIFETIME_TRANSIENT; }
	bool				isSharedTransient()	const				{ return classLt == LIFETIME_SHAREDTRANSIENT; }
	bool				isTransient() const						{ return isNonSharedTransient() || isSharedTransient(); }

	void				makePersistent()						{ classLt = LIFETIME_PERSISTENT; }
	void				makeNonSharedTransient()				{ classLt = LIFETIME_TRANSIENT; }
	void				makeSharedTransient()					{ classLt = LIFETIME_SHAREDTRANSIENT; }
	void				makeTransient()							{ makeNonSharedTransient(); }

	void				copyLifetime(ClassID);
#endif /* __cplusplus */
} ClassID;

#pragma warning ( pop )				// nonstandard extension used : nameless struct/union

const ClassIDBits		NullClassIDBits(0);
const ClassID			NullClassID(0);
const ClassID			HighestClassId(0x00FFFFFF);
const ClassID			Invalid_PersistentClassID(0xFFFFFF);
const ClassID			Invalid_TransientClassID(0x7FFFFF);

const InstanceID		HighestInstanceId					= (InstanceID) ~0;
const SubID				HighestSubId						= (SubID) ~0;

typedef void						*Handle;
typedef struct __jomHwnd__ { } 		*Hwnd;
typedef struct __jomHfont__ { } 	*Hfont;
#if !defined(UNIX)
typedef struct __jomHhook__ { }		*Hhook;
typedef struct __jomHresource__ { } *Hresource;
typedef struct __jomHInstance__ { } *Hinstance;
typedef struct __jomHInternet__ { } *Hinternet;
typedef struct __jomHmodule__ { }	*Hmodule;
typedef struct __jomHglobal__ { } 	*Hglobal;
#else /* UNIX */
typedef struct __jomHhook__ {
	UInt32		id;
	void*		func;
	} 								*Hhook;
typedef struct __jomHresource__ {
	union	{
		UInt16	magic;
		UInt16	type;
		UInt16	name;
	};
	union	{
		UInt16	version;
		UInt16	count;
		UInt16	length;
	};
	UInt32	offset;
	}								*Hresource;
typedef void					 	*Hinstance;
typedef void					 	*Hinternet;
typedef void						*Hmodule;
typedef void					 	*Hglobal;
#endif /* UNIX */

typedef struct DskParam				DskParam;
typedef struct DskObjectId			DskObjectId;
typedef struct ShortDskObjectId		ShortDskObjectId;
typedef struct MidDskObjectId		MidDskObjectId;
typedef struct OidKey				OidKey;

#define MAX_SYSTEMVERSION_LENGTH    8
#define MAX_USERNAME_LENGTH         30

#define MAX_IDENTIFIER_LENGTH		100
#define MAX_IDENTIFIER_LENGTH70		30
#define MAX_ENTRYPOINT_LENGTH		255
#define MAX_ENTRYPOINT_LENGTH70		30

enum DataHandlerOperation : BYTE
{
	JADE_STRING_OP					= 0x10,
	JADE_DEREF_STRING_OP   			= JADE_STRING_OP + 0,
	JADE_GET_STRING_OP				= JADE_STRING_OP + 1,
	JADE_SET_STRING_OP				= JADE_STRING_OP + 2,
	JADE_RESIZE_STRING_OP  			= JADE_STRING_OP + 3,
	JADE_STRING_LENGTH_OP  			= JADE_STRING_OP + 4,
	JADE_STRING_MAX_LENGTH_OP 		= JADE_STRING_OP + 5,
	JADE_GET_STRING_NO_NULL_OP		= JADE_STRING_OP + 6,
	JADE_APPEND_STRING_OP			= JADE_STRING_OP + 7,
	JADE_DEREF_STRING_LENGTH_OP		= JADE_STRING_OP + 8,
	JADE_DELETE_STRING_OP			= JADE_STRING_OP + 9,

	JADE_BINARY_OP					= 0x20,
	JADE_DEREF_BINARY_OP   			= JADE_BINARY_OP + 0,
	JADE_GET_BINARY_OP				= JADE_BINARY_OP + 1,
	JADE_SET_BINARY_OP				= JADE_BINARY_OP + 2,
	JADE_RESIZE_BINARY_OP  			= JADE_BINARY_OP + 3,
	JADE_BINARY_LENGTH_OP  			= JADE_BINARY_OP + 4,
	JADE_BINARY_MAX_LENGTH_OP  		= JADE_BINARY_OP + 5,
	JADE_APPEND_BINARY_OP			= JADE_BINARY_OP + 6,
	JADE_DEREF_BINARY_LENGTH_OP		= JADE_BINARY_OP + 7,
	JADE_DELETE_BINARY_OP			= JADE_BINARY_OP + 8,

	JADE_STRINGUTF8_OP				= 0x40,
	JADE_DEREF_STRINGUTF8_OP   		= JADE_STRINGUTF8_OP + 0,
	JADE_GET_STRINGUTF8_OP			= JADE_STRINGUTF8_OP + 1,
	JADE_SET_STRINGUTF8_OP			= JADE_STRINGUTF8_OP + 2,
	JADE_RESIZE_STRINGUTF8_OP  		= JADE_STRINGUTF8_OP + 3,
	JADE_STRINGUTF8_SIZE_OP  		= JADE_STRINGUTF8_OP + 4,
	JADE_STRINGUTF8_LENGTH_OP  		= JADE_STRINGUTF8_OP + 5,
	JADE_STRINGUTF8_MAX_LENGTH_OP 	= JADE_STRINGUTF8_OP + 6,
	JADE_APPEND_STRINGUTF8_OP		= JADE_STRINGUTF8_OP + 7,
	JADE_DELETE_STRINGUTF8_OP		= JADE_STRINGUTF8_OP + 8,

};

typedef int (JOMAPI* DataHandlerCB)	(DataHandlerOperation operation, DskParam* pParam, void** pData, Size* pLength);

enum DbMode
{
	DB_DEFAULT						= 9,
	DB_SHARED						= 0,
	DB_EXCLUSIVE					= 1,
	DB_REORG						= 2,
	DB_RECOVERY						= 3,
	DB_ARCHIVE						= 4,
	DB_UPGRADE						= 5,
	DB_SNAPSHOT						= 6
};

enum DbUsage
{
	DB_UPDATE						= 0,
	DB_READ_ONLY					= 1,
	DB_NO_AUDIT						= 2,
	DB_ODBC_LOGIN					= 3,
	DB_UPDATE_NO_LOCKS				= 4,
	DB_PRIVATE_FILE					= 5
};

enum ConnectionType
{
	LOCAL_CONNECTION				= 0,
	NETBIOS_CONNECTION				= 1,
	NETBIOS_SYNC_CONNECTION			= 2,
	TCPIP_CONNECTION				= 3,
	SHARED_MEMORY_CONNECTION		= 4,
	NAMED_PIPE_CONNECTION			= 5
};

const ConnectionType	LOCAL_USER      					= LOCAL_CONNECTION;

#include "jompack1.h"

/* long Object Identifier */
/* this structure is packed because it is written to the database */
#pragma warning ( push )
#pragma warning ( disable : 4201 )	// nonstandard extension used : nameless struct/union

typedef struct DskObjectId
{
	InstanceID			instId;
	union
	{
		struct
		{
			ClassIDBits classNo : 22;
			ClassIDBits classLt : 2;
			ClassIDBits reserved : 8;
		};
		struct
		{
			ClassIDBits classId : 24;
			ClassIDBits _reserved : 8;
		};
	};
	union 
	{
		struct 
		{
			ClassIDBits parClassNo : 22;
			ClassIDBits parClassLt : 2;
			ClassIDBits subLevel : 8;
		};
		struct 
		{
			ClassIDBits parClassId : 24;
			ClassIDBits _subLevel : 8;
		};
	};
	SubID				subId;
	Edition				edition;

#if defined(__cplusplus)
	operator ShortDskObjectId&()								{ return *(ShortDskObjectId*)this; }
	operator MidDskObjectId&()									{ return *(MidDskObjectId*)this; }

	operator const ShortDskObjectId&() const					{ return *(ShortDskObjectId*)this; }
	operator const MidDskObjectId&() const						{ return *(MidDskObjectId*)this; }

	ClassNumber			getClassNo() const						{ return classNo; }
	ClassID				getClassId() const						{ return classId; }
	ClassNumber			getParClassNo()	const					{ return parClassNo; }
	ClassID				getParClassId()	const					{ return parClassId; }
	InstanceID			getInstId()	const						{ return instId; }
	Level				getSubLevel() const						{ return subLevel; }
	SubID				getSubId() const						{ return subId; }
	Edition				getEdition() const						{ return edition; }

	ClassIDBits			getClassIdBits() const					{ return classId; }
	ClassIDBits			getParClassIdBits()	const				{ return parClassId; }

	Lifetime			lifetime() const						{ return (Lifetime) (classNo ? classLt : parClassLt); }

	void				setClassNo(ClassNumber cNo)				{ classNo = cNo; }
	void				setClassId(ClassIDBits cBits)			{ classId = cBits; }
	void				setClassId(ClassID cId)					{ classId = cId.allbits; }
	void				setParClassNo(ClassNumber cNo)			{ parClassNo = cNo; }
	void				setParClassId(ClassIDBits cBits)		{ parClassId = cBits; }
	void				setParClassId(ClassID cId)				{ parClassId = cId.allbits; }
	void				setInstId(InstanceID instanceId)		{ instId = instanceId; }
	void				setSubLevel(Level level)				{ subLevel = level; }
	void				setSubId(SubID id) 						{ subId = id; }
	void				setEdition(Edition ed) 					{ edition = ed; }

	void				setLifetime(Lifetime);

	void				set(ClassNumber, InstanceID = 0, ClassNumber = 0, Level = 0, SubID = 0, Edition = 0, Lifetime = LIFETIME_PERSISTENT);
	void				set(ClassIDBits, InstanceID = 0, ClassIDBits = 0, Level = 0, SubID = 0, Edition = 0);
	void				set(ClassID, InstanceID = 0, ClassID = NullClassID, Level = 0, SubID = 0, Edition = 0);
	void				set(const DskObjectId&);
	void				set(const ShortDskObjectId&);
	void				set(const MidDskObjectId&);
	void				set(const OidKey&);

	bool				isNull() const;

	HashValue			hash() const							{ return (HashValue) (classId + instId + parClassId + subLevel + subId); }

	bool				isPersistent() const;
	bool				isNonSharedTransient() const;
	bool				isSharedTransient() const;
	bool				isTransient() const;
	bool				isPersistentOrSharedTransient() const;

	void				makePersistent();
	void				makeNonSharedTransient();
	void				makeSharedTransient();
	void				makeTransient();

	void				copyLifetime(const DskObjectId&);
	void				copyLifetime(const OidKey&);

	void				getParent(DskObjectId&) const;

	bool				isShortObjectId() const;
	bool				isExclusive() const;
	bool				isCollBlock() const;
	bool				isCluster() const;
	bool				isPersistentCluster() const;
	bool				isBlobOrSlob() const;
	bool				isValid() const;
	bool				isLockedByMe() const;
#endif /* __cplusplus */
} JOM_PACKED DskObjectId;

/* short form Object Identifier */
/* this structure is packed because it is written to the database */
typedef struct ShortDskObjectId
{
	InstanceID			instId;
	union
	{
		struct
		{
			ClassIDBits classNo : 22;
			ClassIDBits classLt : 2;
			ClassIDBits reserved : 8;
		};
		struct
		{
			ClassIDBits classId : 24;
			ClassIDBits _reserved : 8;
		};
	};

#if defined(__cplusplus)
	ClassNumber			getClassNo() const						{ return classNo; }
	ClassID				getClassId() const						{ return classId; }
	InstanceID			getInstId()	const						{ return instId; }

	ClassIDBits			getClassIdBits() const					{ return classId; }

	Lifetime			lifetime() const						{ return (Lifetime) classLt; }

	void				setClassNo(ClassNumber cNo)				{ classNo = cNo; }
	void				setClassId(ClassIDBits cBits)			{ classId = cBits; }
	void				setClassId(ClassID cId)					{ classId = cId.allbits; }
	void				setInstId(InstanceID instanceId)		{ instId = instanceId; }

	void				setLifetime(Lifetime);

	void				set(ClassNumber, InstanceID = 0, Lifetime = LIFETIME_PERSISTENT);
	void				set(ClassIDBits, InstanceID = 0);
	void				set(ClassID, InstanceID = 0);
	void				set(const DskObjectId&);
	void				set(const ShortDskObjectId&);
	void				set(const OidKey&);

	bool				isNull() const;

	HashValue			hash() const							{ return (HashValue) (classId + instId); }

	bool				isPersistent() const;
	bool				isNonSharedTransient() const;
	bool				isSharedTransient() const;
	bool				isTransient() const;
	bool				isPersistentOrSharedTransient() const;

	void				makePersistent();
	void				makeNonSharedTransient();
	void				makeSharedTransient();
	void				makeTransient();

	void				copyLifetime(const ShortDskObjectId&);

	bool				isValid() const;

	bool				operator == (void* ptr) const;

#endif /* __cplusplus */
} JOM_PACKED ShortDskObjectId;

/* this structure is packed because it is written to the database */
typedef struct MidDskObjectId
{
	InstanceID			instId;
	union
	{
		struct
		{
			ClassIDBits classNo : 22;
			ClassIDBits classLt : 2;
			ClassIDBits reserved : 8;
		};
		struct
		{
			ClassIDBits classId : 24;
			ClassIDBits _reserved : 8;
		};
	};
	union 
	{
		struct 
		{
			ClassIDBits parClassNo : 22;
			ClassIDBits parClassLt : 2;
			ClassIDBits notused : 8;
		};
		struct 
		{
			ClassIDBits parClassId : 24;
			ClassIDBits _notused : 8;
		};
	};

#if defined(__cplusplus)
	ClassNumber			getClassNo() const						{ return classNo; }
	ClassID				getClassId() const						{ return classId; }
	ClassNumber			getParClassNo()	const					{ return parClassNo; }
	ClassID				getParClassId()	const					{ return parClassId; }
	InstanceID			getInstId()	const						{ return instId; }
			
	ClassIDBits			getClassIdBits() const					{ return classId; }
	ClassIDBits			getParClassIdBits()	const				{ return parClassId; }

	Lifetime			lifetime() const						{ return (Lifetime) classLt; }

	void				setClassNo(ClassNumber cNo)				{ classNo = cNo; }
	void				setClassId(ClassIDBits cBits)			{ classId = cBits; }
	void				setClassId(ClassID cId)					{ classId = cId.allbits; }
	void				setParClassNo(ClassNumber cNo)			{ parClassNo = cNo; }
	void				setParClassId(ClassIDBits cBits)		{ parClassId = cBits; }
	void				setParClassId(ClassID cId)				{ parClassId = cId.allbits; }
	void				setInstId(InstanceID instanceId)		{ instId = instanceId; }

	void				setLifetime(Lifetime);

	void				set(ClassNumber, InstanceID = 0, ClassNumber = 0, Lifetime = LIFETIME_PERSISTENT);
	void				set(ClassIDBits, InstanceID = 0, ClassIDBits = 0);
	void				set(ClassID, InstanceID = 0, ClassID = NullClassID);
	void				set(const DskObjectId&);
	void				set(const MidDskObjectId&);

	bool				isNull() const;

	HashValue			hash() const							{ return (HashValue) (classId + instId + parClassId); }

	bool				isPersistent() const;
	bool				isNonSharedTransient() const;
	bool				isSharedTransient() const;
	bool				isTransient() const;
	bool				isPersistentOrSharedTransient() const;

	void				makePersistent();
	void				makeNonSharedTransient();
	void				makeSharedTransient();
	void				makeTransient();

	void				copyLifetime(const MidDskObjectId&);
#endif /* __cplusplus */
} JOM_PACKED MidDskObjectId;

/* this structure is packed because it is written to the database */
typedef struct OidKey
{
	InstanceID			instId;
	union
	{
		struct
		{
			ClassIDBits classNo : 22;
			ClassIDBits classLt : 2;
			ClassIDBits reserved : 8;
		};
		struct
		{
			ClassIDBits classId : 24;
			ClassIDBits _reserved : 8;
		};
	};
	union 
	{
		struct 
		{
			ClassIDBits parClassNo : 22;
			ClassIDBits parClassLt : 2;
			ClassIDBits subLevel : 8;
		};
		struct 
		{
			ClassIDBits parClassId : 24;
			ClassIDBits _subLevel : 8;
		};
	};
	SubID				subId;

#if defined(__cplusplus)
	ClassNumber			getClassNo() const						{ return classNo; }
	ClassID				getClassId() const						{ return classId; }
	ClassNumber			getParClassNo()	const					{ return parClassNo; }
	ClassID				getParClassId()	const					{ return parClassId; }
	InstanceID			getInstId()	const						{ return instId; }
	Level				getSubLevel() const						{ return subLevel; }
	SubID				getSubId() const						{ return subId; }

	ClassIDBits			getClassIdBits() const					{ return classId; }
	ClassIDBits			getParClassIdBits()	const				{ return parClassId; }

	Lifetime			lifetime() const						{ return (Lifetime) (classNo ? classLt : parClassLt); }

	void				setClassNo(ClassNumber cNo)				{ classNo = cNo; }
	void				setClassId(ClassIDBits cBits)			{ classId = cBits; }
	void				setClassId(ClassID cId)					{ classId = cId.allbits; }
	void				setParClassNo(ClassNumber cNo)			{ parClassNo = cNo; }
	void				setParClassId(ClassIDBits cBits)		{ parClassId = cBits; }
	void				setParClassId(ClassID cId)				{ parClassId = cId.allbits; }
	void				setInstId(InstanceID instanceId)		{ instId = instanceId; }
	void				setSubLevel(Level level)				{ subLevel = level; }
	void				setSubId(SubID id) 						{ subId = id; }

	void				setLifetime(Lifetime);

	void				set(ClassNumber, InstanceID = 0, ClassNumber = 0, Level = 0, SubID = 0, Lifetime = LIFETIME_PERSISTENT);
	void				set(ClassIDBits, InstanceID = 0, ClassIDBits = 0, Level = 0, SubID = 0);
	void				set(ClassID, InstanceID = 0, ClassID = NullClassID, Level = 0, SubID = 0);
	void				set(const DskObjectId&);
	void				set(const ShortDskObjectId&);
	void				set(const OidKey&);

	bool				isNull() const;

	HashValue			hash() const							{ return (HashValue) (classId + instId + parClassId + subLevel + subId); }

	bool				isPersistent() const;
	bool				isNonSharedTransient() const;
	bool				isSharedTransient() const;
	bool				isTransient() const;
	bool				isPersistentOrSharedTransient() const;

	void				makePersistent();
	void				makeNonSharedTransient();
	void				makeSharedTransient();
	void				makeTransient();

	void				copyLifetime(const OidKey&);
	void				copyLifetime(const DskObjectId&);

	void				getParent(DskObjectId&) const;

	bool				isShortObjectId() const;
	bool				isExclusive() const;
	bool				isCollBlock() const;
	bool				isCluster() const;
	bool				isPersistentCluster() const;
	bool				isBlobOrSlob() const;
	bool				isValid() const;
#endif /* __cplusplus */
} JOM_PACKED OidKey;

#pragma warning ( pop )				// nonstandard extension used : nameless struct/union

#include "jompack0.h"

typedef struct StringUtf8Info
{
	StringUtf8Byte*		utf8BytePtr;	/* pointer to string */
#ifndef JADE_64BIT_NODE
	BYTE				pad1[ 4 ];		/* pad a 4-byte pointer (32-bit) to 8 bytes (64-bit) */
#endif
	Size	 			size;			/* size (bytes) of string */
	Size				length;			/* length (CharacterUtf32) of string */
	Size	 			maxLength;		/* maximum length (CharacterUtf32) of string */
	BYTE				pad2[ 4 ];		/* pad to 8-byte (64-bit) boundary */
} StringUtf8Info;

#define STRINGUTF8_MAXLENGTH_UNDEFINED	0

/* JADE TimeStamp structure */
/* this structure is written to the database, it is aligned naturally so it does not need to be packed */
typedef struct DskTimeStamp
{
	DskDate				date;			/* date component */
	DskTime				timeVal;		/* time component */
} DskTimeStamp;

/* JADE TimeStampInterval structure */
/* this structure is written to the database, it is aligned naturally so it does not need to be packed */
typedef struct DskTimeStampInterval
{
	Int64				milliseconds;
} DskTimeStampInterval;

const Int64				INVALID_TIMESTAMPINTERVAL_VALUE		= INT64_MIN;
const int				MAX_TIMESTAMPINTERVAL_DAYS			= 622191233;
const int				MAX_TIMESTAMPINTERVAL_MILLISECONDS	= 25975807;

/* JADE TimeStampOffset structure */
/* this structure is written to the database, it is aligned naturally so it does not need to be packed */
typedef struct DskTimeStampOffset
{
	DskDate				date;			/* date component */
	DskTime				timeVal;		/* time component */
	DskUTCBias			utcBias;		/* bias from UTC (minutes) */
} DskTimeStampOffset;

#define MAX_DECIMAL_DIGITS	23

/* JADE Decimal structure */
/* this structure is written to the database, it is aligned naturally so it does not need to be packed */
typedef struct DskDecimal
{
	Precision			precision;  	/* total number of bytes in value[] */
	ScaleFactor			scaleFactor;	/* number of digits right of decimal point */
	UInt16				value[ 5 ];		/* enough for 23 digits */
	Precision			maxPrecision;  	/* maximum (declared) precision - runtime only */
	ScaleFactor			maxScaleFactor;	/* maximum (declared) scalefactor - runtime only */
	BYTE				pad1[ 2 ];		/* pad to 4-byte boundary */
} DskDecimal;

/* JADE Point structure */
/* this structure is written to the database, it is aligned naturally so it does not need to be packed */
typedef struct DskPoint
{
	Int32				x;				/* x co-ordinate */
	Int32				y;				/* y co-ordinate */
} DskPoint;

typedef struct DskRectangle2D
{
	Int32				left;
	Int32				top;
	Int32				right;
	Int32				bottom;
} DskRectangle2D;

#include "jompack1.h"

/* this structure is packed because it is written to the database */
typedef struct ObjectVersion
{
#ifdef VERSIONINFO_OBJECTS
	ShortDskObjectId    versionInfoOid;
#else
	ShortDskObjectId	genericOid;
#endif /*VERSIONINFO_OBJECTS*/
	VersionNum			version;
} JOM_PACKED ObjectVersion;

/* this structure is packed because it is written to the database */
typedef struct VersionInfo
{
	ObjectVersion    	objectVersion;
	Time_T32			timeStamp;		
	VersionNum			classVersion;
} JOM_PACKED VersionInfo;

/* this structure is packed because it is written to the database */
typedef struct DskMemoryAddress
{
	union DskMemoryAddress_u 
	{
		UInt64			maxSpaceHolder;	/* ensure the space that the pointer occupies is constant */
		void *			pVoid;			/* the actual pointer value */
	} u;
	JomMemorySpaceId	memSpaceId;		/* unique id per memory space */
} JOM_PACKED DskMemoryAddress;

#define JomMemorySpaceThinClient	((JomMemorySpaceId) -1)
#define JomMemorySpaceUnknown		((JomMemorySpaceId) -2)
#define JomMemorySpaceNull			((JomMemorySpaceId)  0)

#include "jompack0.h"

/* the following structure represents the slob info in the Jom object buffer */
/* this structure is written to the database, it is aligned naturally so it does not need to be packed */
typedef struct JomSlobInfo
{
	ObjLen				length;
	Edition				edition;
} JomSlobInfo;

/* the following structure represents the the StringUtf8 header info (Jom object buffer, slobs, arrays, etc.) */
/* this structure is written to the database, it is aligned naturally so it does not need to be packed */
typedef struct JomStringUtf8Info
{
	ObjLen				size;		/* number of bytes in current value */
	ObjLen				length;		/* number of characters in current value */
	StringUtf8Byte		data[ VARIABLE ];
} JomStringUtf8Info;

#define JOMSTRINGUTF8INFO_HDR_SIZE static_cast<Length>(OFFSETOF(JomStringUtf8Info, data))		/* RS::Attribute::JOMSTRINGUTF8INFO_HDR_SIZE */

/* the following structure represents the embedded binary info in the Jom object buffer */
/* this structure is written to the database, it is aligned naturally so it does not need to be packed */
typedef struct JomBinaryInfo
{
	PropertyDataSize	size;		/* number of bytes in current value */
	BYTE				data[ VARIABLE ];
} JomBinaryInfo;

#define JOMBINARYINFO_HDR_SIZE static_cast<Length>(OFFSETOF(JomBinaryInfo, data))		/* RS::Attribute::JOMBINARYINFO_HDR_SIZE */

/* the following structure represents the embedded string info in the Jom object buffer */
/* this structure is written to the database, it may not be aligned naturally (linux/unicode) so it needs to be packed */

#include "jompack1.h"

typedef struct JomStringInfo
{
	PropertyDataSize	size;		/* number of bytes in current value */
	Character			data[ VARIABLE ];
} JOM_PACKED JomStringInfo;

#include "jompack0.h"

#define JOMSTRINGINFO_HDR_SIZE static_cast<Length>(OFFSETOF(JomStringInfo, data))		/* RS::Attribute::JOMSTRINGINFO_HDR_SIZE */

/* the following structure represents the embedded binary info in the collection block */
/* this structure is written to the database, it is aligned naturally so it does not need to be packed */

typedef struct JomAnyInfo
{
	PFormat				type;				// type of the current value
	BYTE				data[ VARIABLE ];
} JOM_PACKED JomAnyInfo;

#define JOMANYINFO_HDR_SIZE static_cast<Length>(OFFSETOF(JomAnyInfo, data))	

typedef struct ObjectBitVector
{
	BYTE		bitVector[ 1 * BIT_VECTOR_MULTIPLIER ];
} ObjectBitVector;

#include "jompack1.h"

typedef struct DskBuffer
{
	ObjLen				size;			/* the size of the oid + the trailing user data*/
	PartitionID			partIdIndex;	/* partitionID or partitionIndex */
	DbFileNum			file;			/* file number */
	UInt16				cacheBits;      /* bit flags for CacheMgr use */
	DskBufferStatus		flag;			/* created, updated, inuse, deleted */
	BYTE				cryptState;		/* non-zero means userData is encrypted */
	BYTE				filler[2];		/* To make sizeof(DskBuffer) multiple of 8 */

	/* members from here on overlay persistent database structures and single byte alignment of fields is required */
	
	ReplicationInfo		replicationInfo;
	SequenceNumber		updateTranID;
	VersionInfo 		versionInfo;	
	DskObjectId 		oid;
#ifdef CPP_DSKBUFFER
#include "dskbuff.hpp"
#define DSKBUFFER_ACCESS
#endif
#ifdef DSKBUFFER_ACCESS
#include "sys/dskbuffer.hpp"
#endif
} JOM_PACKED DskBuffer;

#include "jompack0.h"

#define OBJECT_HISTORY_STATESIZE		sizeof(ReplicationInfo) + sizeof(SequenceNumber) + sizeof(VersionInfo)

/* This is a CollBlock DskBuffer which includes the header block OID in the data area */
/* Fields described in terms of BYTES for single byte alignment because GCC disallows an
	unpacked struct (DskBuffer) inside a packed struct, see DskBuffer. */
typedef struct DskBufferCollBlock
{
	DskBuffer	dskBuff;
	ObjectBitVector objectBitVector;			/* This overlays first byte of the data area: bit-vector or blocktype for the collBlock */
	BYTE		headerOid_sizeBytes[sizeof(PropertyDataSize)];
	BYTE		headerOidBytes[sizeof(OidKey)]; 
	BYTE		currentLimitBytes[sizeof(Integer)];
	BYTE		entriesBytes[sizeof(Integer)];
	BYTE		etc[VARIABLE];
} DskBufferCollBlock;

typedef struct JomDbMethodDesc
{
	UInt32				category;
	UInt32				dbRequest;
} JomDbMethodDesc;

/* Do not change these values as they affect existing DBs */
#define DB_CONTROL_VLOT_SIZE		(128)

typedef struct
{
	SequenceNumber	upgradeHighestTranID;
	UInt32			upgradeVersion;
	UInt32			checkpointLsnJournal;
	UInt32			checkpointLsnOffset;
	BYTE			dbPrimaryID[ 16 ];
	BYTE			dbInstanceID[ 16 ];	
	bool			inUpgradeState;
	bool			productionMode;
	BYTE			pad1[ 2 ];		/* pad to 8-byte (64-bit) boundary */
} JomDbControlInfo;

typedef struct DskHandle
{
	UInt64			pInternals;		/* large enough to hold a 64-bit pointer */
	UInt16			number;
	UInt16			incarnation;
	BYTE			pad1[ 4 ];		/* pad to 8-byte (64-bit) boundary */
} DskHandle;

#define JomDefaultNodeHandle		nullptr
#define JomDefaultProcessHandle		nullptr

// Log sequence number
struct JomLSN	
{
	UInt32		journal;
	UInt32		offset;

	void		setValue(UInt32 jnl, UInt32 off)
				{ journal = jnl; offset = off; }
};

enum JomObjectState
{
	OS_Undefined,
	OS_OldEdition,
	OS_Committed,
	OS_Created,
	OS_Updated,
	OS_Deleted,
	OS_Recreated,
	OS_Ignore,
	OS_IgnoreOverflow,
	OS_IgnoreDelete
};

struct JomObjectUpdateDesc
{
	JomObjectState		state;			
	DskTimeStamp		timestamp;
	JomLSN				auditLSN;
	JomLSN				biLSN;
	DskObjectId			oid;
	BYTE				pad1[ 2 ];	/* pad to 4-byte (32-bit) boundary */
};

typedef struct JomExecInstances
{
	DskObjectId 		global;
	DskObjectId 		app;
	DskObjectId 		rootSchema;
	DskObjectId 		currentSchema;
	DskObjectId 		system;
	DskObjectId 		node;
	DskObjectId 		process;
	DskObjectId 		persistentApp;
	DskObjectId 		session;
	DskObjectId			appContext;
	SchemaNumber		currentSchemaNo;
} JomExecInstances;

typedef enum 
{ 
	MetaSchemaClass						= 1,
	MetaSchemaClassProperty				= 2,
	MetaSchemaClassMethod				= 3,
	MetaSchemaImportedClass				= 4,
	MetaSchemaInterface					= 5,
	MetaSchemaInterfaceMethod			= 6,
	MetaSchemaPackage					= 7,
	MetaSchemaPrimitiveType				= 8,
	MetaSchemaPrimitiveMethod			= 9,
	MetaSchemaImportedClassProperty		= 10,
	MetaSchemaImportedClassMethod		= 11,
	MetaSchemaUserFormat				= 12,
	MetaSchemaClassConstant				= 13,
	MetaSchemaImportedClassConstant		= 14,
	MetaSchemaPrimitiveConstant			= 15,
	MetaSchemaInterfaceConstant			= 16,
	MetaSchemaImportedInterface			= 17,
	MetaSchemaImportedInterfaceMethod	= 18,
	MetaSchemaImportedInterfaceConstant	= 19,
} JomMetaObjectType;

typedef enum 
{
	BACKGROUND						= 0,				// ProcessType_Background
	JADE_DEVELOPMENT				= 1,				// ProcessType_JadeDevelopment
	NON_DEVELOPMENT					= 2,				// ProcessType_NonDevelopment
	JADE_DEBUGGER					= 3,				// ProcessType_JadeDebugger
	JADE_PAINTER					= 4,				// ProcessType_JadePainter
	UNKNOWN_PROCESS_TYPE			= 5,				// ProcessType_UnknownType
	JADE_TOOL						= 6					// ProcessType_JadeTool
} JomProcessType;

typedef enum 
{
	JomTriStateMaybe				= -1,
	JomTriStateDefault				= JomTriStateMaybe,
	JomTriStateFalse				= 0, 
	JomTriStateTrue					= 1 
} JomTriState;

#define DSKPARAM_BODY_SIZE			520
#ifdef JADE_64BIT_NODE
#define SHORTDSKPARAM_BODY_SIZE		32
#else /* JADE_64BIT_NODE */
#define SHORTDSKPARAM_BODY_SIZE		24		/* ends on 8-byte (64-bit pointer) boundary */
#endif /* JADE_64BIT_NODE */

typedef struct DummyBinary
{
	Length				length;			/* length (bytes) of binary (sub)string */
	BYTE 				pad1[ sizeof(UInt64) - sizeof(EntryCount) ];
	BYTE				dataArea[ VARIABLE ];
} DummyBinary;

typedef struct DummyDskString
{
	Length				length;			/* length (characters) of (sub)string, excl. null */
	BYTE 				pad1[ sizeof(UInt64) - sizeof(EntryCount) ];
	Character			dataArea[ VARIABLE ];
} DummyDskString;

const Length MAX_EMBEDDED_BINARY_LENGTH = DSKPARAM_BODY_SIZE - OFFSETOF(DummyBinary, dataArea);
const Length MAX_EMBEDDED_STRING_LENGTH = (DSKPARAM_BODY_SIZE - OFFSETOF(DummyDskString, dataArea)) / sizeof(Character);
const Length MAX_EMBEDDED_STRING_SIZE = MAX_EMBEDDED_STRING_LENGTH * sizeof(Character);
const Length MAX_SHORT_BINARY_LENGTH = SHORTDSKPARAM_BODY_SIZE - OFFSETOF(DummyBinary, dataArea);
const Length MAX_SHORT_STRING_LENGTH = (SHORTDSKPARAM_BODY_SIZE - OFFSETOF(DummyDskString, dataArea)) / sizeof(Character);

/* align size member to a 4-byte (32-bit) boundary */
#define ANYLIST_FILLER_SIZE			(sizeof(UInt32) - sizeof(EntryCount))

typedef struct AnyList
{
	EntryCount 			entries;		/* number of entries in list */
	BYTE 				pad1[ ANYLIST_FILLER_SIZE ];
	Size				size;			/* size (in bytes) of array[] */
	BYTE 				array[ VARIABLE ];
} AnyList;

const int DSKPARAM_ARRAY_SIZE				= DSKPARAM_BODY_SIZE - OFFSETOF(AnyList,array);

const EntryCount MAX_INTEGER_LIST_SIZE		= DSKPARAM_ARRAY_SIZE / sizeof(Integer);
const EntryCount MAX_INTEGER64_LIST_SIZE	= DSKPARAM_ARRAY_SIZE / sizeof(Integer64);
const EntryCount MAX_STRING_ARRAY_SIZE		= DSKPARAM_ARRAY_SIZE / sizeof(Character);
const EntryCount MAX_SHORTOID_LIST_SIZE		= DSKPARAM_ARRAY_SIZE / sizeof(ShortDskObjectId);
const EntryCount MAX_OID_KEY_LIST_SIZE		= DSKPARAM_ARRAY_SIZE / sizeof(OidKey);
const EntryCount MAX_POINTER_LIST_SIZE		= DSKPARAM_ARRAY_SIZE / sizeof(void*);
const EntryCount MAX_INSTANCEID_LIST_SIZE	= DSKPARAM_ARRAY_SIZE / sizeof(InstanceID);

/* short form Object Identifier list */
typedef struct ShortDskObjectIdList
{
	EntryCount			entries;		/* number of entries in list */
	BYTE 				pad1[ ANYLIST_FILLER_SIZE ];
	Size				size;			/* size (in bytes) of array[] */
	ShortDskObjectId	oidArray[ MAX_SHORTOID_LIST_SIZE ];
} ShortDskObjectIdList;

typedef struct OidKeyList
{
	EntryCount			entries;		/* number of entries in list */
	BYTE 				pad1[ ANYLIST_FILLER_SIZE ];
	Size				size;			/* size (in bytes) of array[] */
	OidKey				oidKeyArray[ MAX_OID_KEY_LIST_SIZE ];
} OidKeyList;

const int MAX_PARAM_LIST_SIZE				= MAX_POINTER_LIST_SIZE;
const int MAX_METHOD_PARAMETERS				= 129;						/* use LargeDskParam for 129 parameters */
const int MAX_BUFFERLIST_POINTERS			= 128;						/* use LargeDskParam for 128 DskBuffers */
const int MAX_CONCAT_KEY_LENGTH				= 512;
const int MAX_KEYS							= MAX_CONCAT_KEY_LENGTH;	/* worst case is 512 single byte keys! */
#define MAX_ARRAY_ELEMENT_LENGTH			16000				    /* worst array member size is a UNICODE String[16000] or 15999 in the IDE*/    
#define MAX_ARRAY_ELEMENT_SIZE            (MAX_ARRAY_ELEMENT_LENGTH * sizeof(Character))

/* pad to 8-byte (64-bit) boundary */
#define ENTRYCOUNT_FILLER_SIZE		(sizeof(UInt64) - sizeof(EntryCount))

/* parameter pointer list */
typedef struct DskParamList				/* 32-bit: 128 parameters; 64-bit: 64 parameters - use LargeDskParam for 129 parameters */
{
	EntryCount			entries;		/* number of entries in list */
	BYTE 				pad1[ ENTRYCOUNT_FILLER_SIZE ];
	DskParam*			param[ MAX_POINTER_LIST_SIZE ];
} DskParamList;

/* short form parameter pointer list - for fewer than 4 parameters */
typedef struct ShortDskParamList
{
	EntryCount			entries;		/* number of entries in list */
	BYTE 				pad1[ ENTRYCOUNT_FILLER_SIZE ];
	DskParam*			param[ 3 ];
} ShortDskParamList;

/* mid form parameter pointer list - for fewer than 5 parameters */
typedef struct MidDskParamList
{
	EntryCount			entries;		/* number of entries in list */
	BYTE 				pad1[ ENTRYCOUNT_FILLER_SIZE ];
	DskParam*			param[ 4 ];
} MidDskParamList;

/* long form parameter pointer list - used for a full (129) parameter list, even with 64-bit pointers */
typedef struct LargeDskParamList
{
	EntryCount			entries;		/* number of entries in list */
	BYTE 				pad1[ ENTRYCOUNT_FILLER_SIZE ];
	DskParam*			param[ MAX_METHOD_PARAMETERS ];
} LargeDskParamList;

typedef struct DskBufferList
{
	EntryCount			entries;		/* number of entries in list */
	BYTE 				pad1[ ENTRYCOUNT_FILLER_SIZE ];
	DskBuffer*			buffer[ MAX_POINTER_LIST_SIZE ];
} DskBufferList;

/* long form DskBuffer list - used for a full (128) parameter list, even with 64-bit pointers */
typedef struct LargeDskBufferList
{
	EntryCount			entries;		/* number of entries in list */
	BYTE 				pad1[ ENTRYCOUNT_FILLER_SIZE ];
	DskBuffer*			buffer[ MAX_BUFFERLIST_POINTERS ];
} LargeDskBufferList;

typedef struct JomPropertyDesc
{
	enum
	{
		KindUnknown		= 0,			/* property kind is unknown */
		KindClass		= 1,			/* property is a reference to a class, or an exclusive collecion */
		KindPrimitive	= 2,			/* property is a primitive */
		KindInterface	= 3				/* property is a reference to an interface */
	}					propertyKind;
	Offset				offset;
	Size				size;			/* size in bytes of property */
	PropertyLen			length;			/* length in units of property (Binary/String/StringUtf8 - else 0) */
	TypeNum				typeNumber;
	ClassNumber			classNo;		/* class or interface number */
	TypeNum				schemaTypeNumber;
	FeatureNum			number;
	PFormat				type;
	SubID				subId;
	Level				level;
	Precision			precision;       
	ScaleFactor			scaleFactor;
	Boolean				isMapped;
	Boolean				isEmbedded;
	Boolean				isVirtual;
	Boolean				isKey;
	Boolean				isDynamic;
	ShortDskObjectId	oid;
	Character			name[ MAX_IDENTIFIER_LENGTH + 1 ];
#ifdef UNICODE
	BYTE				pad1[ 3 ];		/* pad to 4-byte (32-bit) boundary */
#else /* UNICODE */
	BYTE				pad1[ 2 ];		/* pad to 4-byte (32-bit) boundary */
#endif /* UNICODE */
} JomPropertyDesc;

typedef struct JomMethodDesc
{
	ClassNumber			classNo;
	FeatureNum			number;
	Level				level;
	Boolean				isJade;
	ExecutionLocation	executionLocation;
	Boolean				isSafe;
	Boolean				isCallable;
	Character			name[ MAX_IDENTIFIER_LENGTH + 1 ];
#ifdef UNICODE
	BYTE				pad1[ 3 ];		/* pad to 4-byte (32-bit) boundary */
#else
	BYTE				pad1[ 2 ];		/* pad to 4-byte (32-bit) boundary */
#endif /* UNICODE */
} JomMethodDesc;

typedef struct DynamicDataHandler
{
	DataHandlerCB		callBack;
#ifndef JADE_64BIT_NODE
	BYTE				pad1[ 4 ];		/* pad a 4-byte pointer (32-bit) to 8 bytes (64-bit) */
#endif
	void*				pItem;
#ifndef JADE_64BIT_NODE
	BYTE				pad2[ 4 ];		/* pad a 4-byte pointer (32-bit) to 8 bytes (64-bit) */
#endif
	DskParam*			pParam;
#ifndef JADE_64BIT_NODE
	BYTE				pad3[ 4 ];		/* pad a 4-byte pointer (32-bit) to 8 bytes (64-bit) */
#endif
} DynamicDataHandler;

typedef struct InterpParamCallBack
{
	void				(*pCallBack) (DskParam* pThis, DskParam** ppP1, DskParam** ppP2);
#ifndef JADE_64BIT_NODE
	BYTE				pad1[ 4 ];		/* pad a 4-byte pointer (32-bit) to 8 bytes (64-bit) */
#endif
	void*				pNodeRef;
#ifndef JADE_64BIT_NODE
	BYTE				pad2[ 4 ];		/* pad a 4-byte pointer (32-bit) to 8 bytes (64-bit) */
#endif
	void*				pActualParams;
#ifndef JADE_64BIT_NODE
	BYTE				pad3[ 4 ];		/* pad a 4-byte pointer (32-bit) to 8 bytes (64-bit) */
#endif
	DskParam*			param1;
#ifndef JADE_64BIT_NODE
	BYTE				pad4[ 4 ];		/* pad a 4-byte pointer (32-bit) to 8 bytes (64-bit) */
#endif
	DskParam*			param2;
#ifndef JADE_64BIT_NODE
	BYTE				pad5[ 4 ];		/* pad a 4-byte pointer (32-bit) to 8 bytes (64-bit) */
#endif
} InterpParamCallBack;

/* pad to 4-byte (32-bit) (Unicode Chracter size on Linux) boundary */
#define STRINGLENGTH_FILLER_SIZE	(sizeof(UInt32) - sizeof(Length))

/* length counted embedded string */
typedef struct DskString
{
	Length				length;			/* length (characters) of (sub)string, excl. null */
	BYTE				pad1[ STRINGLENGTH_FILLER_SIZE ];
	Character			dataArea[ MAX_EMBEDDED_STRING_LENGTH ];
} DskString;

/* short form of length counted embedded string */
typedef struct ShortDskString
{
	Length				length;			/* length (characters) of (sub)string, excl. null */
	BYTE				pad1[ STRINGLENGTH_FILLER_SIZE ];
	Character			dataArea[ MAX_SHORT_STRING_LENGTH ];
} ShortDskString;

/* length counted non-embedded (pointer) string with offset for substring */
typedef struct CharBlockPointer
{
	Character*			charPtr;        /* pointer to (sub)string */
#ifndef JADE_64BIT_NODE
	BYTE				pad1[ 4 ];		/* pad a 4-byte pointer (32-bit) to 8 bytes (64-bit) */
#endif
	Size	  			offset;			/* offset of (sub)string */
	Size	 			length;			/* length (characters) of (sub)string, excl. null */
	Size	 			maxLength;		/* maximum length (characters) of string, excl. null */
	BYTE				pad2[ 4 ];		/* pad to 8-byte (64-bit pointer) boundary */
} CharBlockPointer;

/* length counted embedded binary string */
typedef struct DskBinary
{
	Length				length;			/* length (bytes) of binary (sub)string */
	BYTE				pad1[ STRINGLENGTH_FILLER_SIZE ];
	BYTE				dataArea[ MAX_EMBEDDED_BINARY_LENGTH ];
} DskBinary;

/* length counted short embedded binary string */
typedef struct ShortDskBinary
{
	Length				length;			/* length (bytes) of binary (sub)string */
	BYTE				pad1[ STRINGLENGTH_FILLER_SIZE ];
	BYTE				dataArea[ MAX_SHORT_BINARY_LENGTH ];
} ShortDskBinary;

/* length counted non-embedded (pointer) binary string with offset for binary substring */
typedef struct BinaryBlockPointer
{
	BYTE*				bytePtr;		/* pointer to binary */
#ifndef JADE_64BIT_NODE
	BYTE				pad1[ 4 ];		/* pad a 4-byte pointer (32-bit) to 8 bytes (64-bit) */
#endif
	Size				offset;			/* offset of binary (sub)string */
	Size				length;			/* length (bytes) of binary (sub)string */
	Size				maxLength;		/* maximum length (bytes) of binary string */
	BYTE				pad2[ 4 ];		/* pad to 8-byte (64-bit pointer) boundary */
} BinaryBlockPointer;

/* size&length counted non-embedded (pointer) stringUtf8 */
typedef struct StringUtf8BlockPointer
{
	StringUtf8Byte*		utf8BytePtr;	/* pointer to string */
#ifndef JADE_64BIT_NODE
	BYTE				pad1[ 4 ];		/* pad a 4-byte pointer (32-bit) to 8 bytes (64-bit) */
#endif
	Size				size;			/* size (bytes) of string */
	Size				length;			/* length (CharacterUtf32) of string */
	Size				maxLength;		/* maximum length (CharacterUtf32) of string */
	BYTE				pad2[ 4 ];		/* pad to 8-byte (64-bit pointer) boundary */
} StringUtf8BlockPointer;

/* Collection keys in a format compatible with DictDesc::makeKey buffer */
typedef struct DictKeyBlockPointer
{
	BYTE*				dictKeysPtr;	/* pointer to dict keys, in "DictDesc::makeKey" format */
#ifndef JADE_64BIT_NODE
	BYTE				pad1[ 4 ];		/* pad a 4-byte pointer (32-bit) to 8 bytes (64-bit) */
#endif
	Size				keyCount;		/* number of keys */
	Size				length;			/* length (bytes) of dictKeysPtr that are valid */
	Size				maxLength;		/* maximum length (bytes) of dictKeysPtr */
	BYTE				pad2[ 4 ];		/* pad to 8-byte (64-bit pointer) boundary */
} DictKeyBlockPointer;

typedef struct JomLockRequest
{
	LockWaitTime		waitTime;
	DskObjectId 		target;
	DskObjectId 		waitingFor;
	BYTE 				duration;
	BYTE 				type;
	BYTE				pad1[ 2 ];		/* pad to 4-byte (32-bit) boundary */
} JomLockRequest;

typedef struct StringList
{
	EntryCount			entries;		/* number of entries in list */
	BYTE 				pad1[ ENTRYCOUNT_FILLER_SIZE ];
	Character			dataArea[ MAX_STRING_ARRAY_SIZE ];  /* Contains a sequence of null terminated strings */
} StringList;

typedef struct IntegerList
{
	EntryCount			entries;		/* number of entries in list */
	BYTE 				pad1[ ENTRYCOUNT_FILLER_SIZE ];
	Integer				integer[ MAX_INTEGER_LIST_SIZE ];
} IntegerList;

typedef struct Integer64List
{
	EntryCount			entries;
	BYTE 				pad1[ ENTRYCOUNT_FILLER_SIZE ];
	Integer64			integer64[ MAX_INTEGER64_LIST_SIZE ];
} Integer64List;

typedef struct InstanceIDList
{
	EntryCount			entries;
	BYTE 				pad1[ ENTRYCOUNT_FILLER_SIZE ];
	InstanceID			instId[ MAX_INSTANCEID_LIST_SIZE ];
} InstanceIDList;

typedef struct PointerList
{
	EntryCount			entries;		/* number of entries in list */
	BYTE 				pad1[ ENTRYCOUNT_FILLER_SIZE ];
	void* 				pointer[ MAX_POINTER_LIST_SIZE ];
} PointerList;

typedef struct JomCallBack
{
	DskObjectId			oid;
	BYTE				pad1[ 2 ];		/* pad to 4-byte (32-bit) (Unicode Chracter size on Linux) boundary */
	Character			msg[ MAX_IDENTIFIER_LENGTH + 1 ];
} JomCallBack;

typedef struct JomFeatureNameHandle
{
	const Character*	pName;	
#ifndef JADE_64BIT_NODE
	BYTE				pad1[ 4 ];		/* pad a 4-byte pointer (32-bit) to 8 bytes (64-bit) */
#endif
	FeatureHandle		handle;
} JomFeatureNameHandle;

typedef struct JomClassFeature
{
	ClassNumber			classNo;
	FeatureNum			number;
	BYTE				pad1[ 2 ];		/* pad to 4-byte (32-bit) boundary */
} JomClassFeature;

typedef struct JomClassFeatureLevel
{
	ClassNumber			classNo;
	FeatureNum			number;
	Level				level;
	BYTE				pad1[ 1 ];		/* pad to 4-byte (32-bit) boundary */
} JomClassFeatureLevel;

typedef struct JomClassFeatureLevelHandle
{
	FeatureHandle		handle;
	JomClassFeatureLevel classFeatureLevel;
} JomClassFeatureLevelHandle;

typedef struct JomPrimFeature
{
	SchemaNumber		schemaNo;
	JomClassFeature		feature;
} JomPrimFeature;

typedef struct JomInterfaceFeature
{
	InterfaceNumber		interfaceNo;
	FeatureNum			number;
	BYTE				pad1[ 2 ];		/* pad to 4-byte (32-bit) boundary */
} JomInterfaceFeature;

const JomInterfaceFeature NullJomInterfaceFeature	= { };

typedef struct DskHeader
{
	PFormat				format;			/* parameter format, eg DSKINTEGER */
	PUsage				usage;			/* parameter usage, eg USAGE_INPUT */
	PMore				more;			/* more to come? usually 0 */
	BYTE				pad1[ 4 ];		/* pad to 8-byte (64-bit) boundary */
} DskHeader;

// derived, overlapping by ShortDskParam and DskParam
struct DSKPARAM_LINKAGE DskParamHeader 
{

	DskParamHeader() = delete;
	DskParamHeader(const DskHeader& dskHdr) { header = dskHdr; }
	DskParamHeader(PFormat formatInit, PUsage usageInit = USAGE_CONSTANT, PMore moreInit = PMore::Done) 
	{
		header.format = formatInit;
        header.usage  = usageInit;
        header.more   = moreInit;
	}

	DskHeader header;
};

/* short form parameter - suitable for most JOM primitives */
struct DSKPARAM_LINKAGE ShortDskParam : public DskParamHeader
{
	// default, to safe undefined typed
	ShortDskParam() : DskParamHeader(DSKUNDEF) {}
    ShortDskParam(PFormat formatInit, PUsage usageInit = USAGE_CONSTANT, PMore moreInit = PMore::Done) 
        : DskParamHeader(formatInit, usageInit, moreInit) {}

	// from DskHeader
	ShortDskParam(const DskHeader& dskHdr) : DskParamHeader(dskHdr) {}

#if defined(__cplusplus)
	// operators to make laying a ShortDskParam over a DskParam easier
	operator DskParam*() { return reinterpret_cast<DskParam*>(this); }
	operator DskParam&() { return reinterpret_cast<DskParam&>(*this); }
#endif

    // returns a ShortDskParam with everything set to 0
    // - replaces the NullShortDskParam
    static const ShortDskParam allZero() 
	{
        ShortDskParam sd;
        memset(&sd, 0, sizeof(sd));
        return sd;
    }

	union DskBytes 
	{
		 BYTE				bytes[SHORTDSKPARAM_BODY_SIZE];
		 void*  			bodyPtr;
		 BYTE*				pData;
		 Character*			pText;			/* DSKCSTRING */
		 DskObjectId		oid;			/* DSKOBJECTID */
		 ShortDskObjectId	shortOid;		/* DSKSHORTOBJECTID */
		 OidKey				oidkey;
		 ShortDskString 	string;			/* DSKPSTRING */
		 DskPoint 			point;			/* DSKPOINT */
		 Integer			integer;	 	/* DSKINTEGER - 32 bit signed integer */
		 Integer64			integer64;	 	/* DSKINTEGER64 - 64 bit signed integer */
		 UInteger			uInteger;	 	/* DSKINTEGER - 32 bit positive integer */
		 UInteger64			uInteger64;	 	/* DSKINTEGER - 64 bit positive integer */
		 Handle				winhandle;
		 Boolean	   		boolean;		/* DSKBOOLEAN */
		 BYTE				byte;			/* DSKByte */
		 Float				floatVal;		/* DSKFLOAT */
		 Double	 			doubleVal;		/* DSKDOUBLE */
		 Real	 			real;			/* DSKREAL */
		 Real4	 			real4;			/* DSKREAL4 (float) */
		 Character  		character;		/* DSKCHARACTER */
		 Character  		charPlus[2];	/* DSKCHARACTER */
		 CharBlockPointer	charBlockPtr;	/* DSKCHARBLOCKPOINTER */
		 BinaryBlockPointer	binaryBlockPtr;	/* DSKBINARYBLOCKPOINTER */
		 JomClassFeature	feature;		/* DSKCLASSFEATURE */
		 ShortDskBinary 	binary;			/* DSKBINARY */
		 DskDate 			date;			/* DSKDATE */
		 DskTime 			timeVal;		/* DSKTIME */
		 DskTimeStamp 		timeStamp;		/* DSKTIMESTAMP */
		 DskTimeStampInterval timeStampInterval;/* DSKTIMESTAMPINTERVAL */
		 DskTimeStampOffset	timeStampOffset;/* DSKTIMESTAMPOFFSET */
		 DskDecimal			decimal;		/* DSKDECIMAL */
		 DskRectangle2D     rectangle2d;    /* DSKRECTANGLE2D */
		 ShortDskParamList	parameterList;	/* DSKPARAMLIST */
		 DynamicDataHandler	dataHandler;	/* DSKJADESTRING/DSKJADEBINARY/DSKANY/DSKJadeStringUtf8 */
		 JomPrimFeature		primFeature;	/* DSKPRIMFEATURE */
		 JomClassFeatureLevelHandle	featureLevel;	/* DSKCLASSFEATURELEVEL */
		 JomDbMethodDesc	dbMethodDesc;	/* DSKDBMETHODDESC */
		 JomFeatureNameHandle featureName;	/* DSKFEATURENAME */
		 JomInterfaceFeature interfaceFeature;	/* DSKINTERFACEFEATURE */
		 StringUtf8BlockPointer stringUtf8BlockPtr;/* DSKSTRINGUTF8 */
		 DskMemoryAddress	memoryAddress;	/* DSKMEMORYADDRESS */
		 InstanceID			instanceID;		/* DSKINSTANCEID */
		 DictKeyBlockPointer dictKeyBlockPtr; /* DSKDICTKEYBLOCKPOINTER */
		 JomSlobInfo		slobInfo;		/* DSKJOMSLOBINFO */
	 } body;
};

/* JOM parameter structure */
struct DSKPARAM_LINKAGE DskParam : public DskParamHeader
{
	DskParam() : DskParamHeader(DSKUNDEF) {}
    DskParam(PFormat formatInit, PUsage usageInit = USAGE_CONSTANT, PMore moreInit = PMore::Done)
        : DskParamHeader(formatInit, usageInit, moreInit) {}

	// copy from short version
	DskParam& operator =(ShortDskParam& rhs) 
	{
		// assumes identical memory layout of ShortDskParam, but shorter
		static_assert(sizeof(DskParam) > sizeof(ShortDskParam), "ShortDskParam must be base (and smaller) than DskParam" );

		*(ShortDskParam *)this = rhs;
		return *this;
	}

    // returns a DskParam with everything set to 0
    // - replaces the NullDskParam
    static const DskParam allZero() 
	{
        DskParam dp;
        memset(&dp, 0, sizeof(dp));
        return dp;
    }

	/* JOM parameter structure */
	union DskBytes 
	{
		BYTE	  			bytes[DSKPARAM_BODY_SIZE];
		void*  				bodyPtr;
		BYTE*				pData;
		Character*			pText;			/* DSKCSTRING */
		DskObjectId			oid;			/* DSKOBJECTID */
		ShortDskObjectId	shortOid;		/* DSKSHORTOBJECTID */
		OidKey				oidkey;
		DskString 			string;			/* DSKPSTRING */
		ShortDskObjectIdList list;			/* DSKSHORTOIDLIST */
		OidKeyList			oidKeyList;		/* DSKOIDKEYLIST */
		IntegerList			intList;		/* DSKINTEGERLIST */
		Integer64List       int64List;      /* DSKINTEGER64LIST */
		StringList			stringList;		/* DSKSTRINGLIST */
		DskParamList		parameterList;	/* DSKPARAMLIST */
		InstanceIDList		instanceIDList;	/* DSKINSTANCEIDLIST */
		DskPoint 			point;			/* DSKPOINT */
		Integer				integer;	 	/* DSKINTEGER - 32 bit signed integer */
		Integer64			integer64;	 	/* DSKINTEGER - 64 bit signed integer */
		UInteger			uInteger;	 	/* DSKINTEGER - 32 bit positive integer */
		UInteger64			uInteger64;	 	/* DSKINTEGER - 64 bit positive integer */
		Handle				winhandle;
		Boolean    			boolean;		/* DSKBOOLEAN */
		BYTE				byte;			/* DSKBYTE */
		Character  			character;		/* DSKCHARACTER */
		Float				floatVal;		/* DSKFLOAT */
		Double	 			doubleVal;		/* DSKDOUBLE */
		Real	 			real;			/* DSKREAL */
		Real4	 			real4;			/* DSKREAL4 (float) */
		PointerList 		ptrList;
		DskBufferList		bufferList;		/* DSKBUFFERLIST */
		CharBlockPointer	charBlockPtr;	/* DSKCHARBLOCKPOINTER */
		BinaryBlockPointer	binaryBlockPtr;	/* DSKBINARYBLOCKPOINTER */
		JomCallBack 		callBack;
		JomClassFeature		feature;		/* DSKCLASSFEATURE */
		DskBinary 			binary;			/* DSKBINARY */
		DskDate 			date;			/* DSKDATE */
		DskTime 			timeVal;		/* DSKTIME */
		DskTimeStamp 		timeStamp;		/* DSKTIMESTAMP */
		DskTimeStampInterval timeStampInterval;/* DSKTIMESTAMPINTERVAL */
		DskTimeStampOffset	timeStampOffset;/* DSKTIMESTAMPOFFSET */
		DskDecimal			decimal;		/* DSKDECIMAL */
		DskRectangle2D      rectangle2d;    /* DSKRECTANGLE2D */
		DynamicDataHandler	dataHandler;	/* DSKJADESTRING/DSKJADEBINARY/DSKANY/DSKJadeStringUtf8 */
		InterpParamCallBack	interpParamCallBack;/* DSKINTERPPARAMCALLBACK */
		JomPropertyDesc		propertyDesc;	/* DSKPROPERTYDESC */
		JomMethodDesc		methodDesc;		/* DSKMETHODDESC */
		JomLockRequest		jomLockRequest;	/* DSKJOMLOCKREQUEST */
		AnyList				anyList;		/* DSKANYLIST */
		JomDbControlInfo	dbControlInfo;	/* DSKDBCONTROLINFO */
		JomPrimFeature		primFeature;	/* DSKPRIMFEATURE */
		JomClassFeatureLevelHandle featureLevel;	/* DSKCLASSFEATURELEVEL */
		JomDbMethodDesc		dbMethodDesc;	/* DSKDBMETHODDESC */
		JomFeatureNameHandle featureName;	/* DSKFEATURENAME */
		JomInterfaceFeature	interfaceFeature;	/* DSKINTERFACEFEATURE */
		JomObjectUpdateDesc	objectUpdateDesc;	/* DSKOBJECTUPDATEDESC */
		StringUtf8BlockPointer stringUtf8BlockPtr;/* DSKSTRINGUTF8 */
		DskMemoryAddress	memoryAddress;	/* DSKMEMORYADDRESS */
		InstanceID			instanceID;		/* DSKINSTANCEID */
		DictKeyBlockPointer dictKeyBlockPtr; /* DSKDICTKEYBLOCKPOINTER */
		JomSlobInfo			slobInfo;		/* DSKJOMSLOBINFO */
	} body;
};

////////////////// DskParam specialisations  

struct DskParamBool : public DskParam 
{
    DskParamBool(Boolean initialVal = FALSE, PUsage usageInit = USAGE_CONSTANT)
        : DskParam(DSKBOOLEAN, usageInit)
    {
        body.boolean = initialVal;
    }
};

////////////////// 

/* medium form parameter - for the interpreter parameter callback, to avoid the overhead of a full DskParam */
typedef union MidDskBytes
{
	MidDskParamList		parameterList;	/* DSKPARAMLIST */
	InterpParamCallBack	interpParamCallBack;
} MidDskBytes;

/* medium form parameter - for the interpreter parameter callback, to avoid the overhead of a full DskParam */
typedef struct MidDskParam
{
	 DskHeader	 		header;
	 MidDskBytes 		body;
} MidDskParam;

/* long form parameter - used for a full (128) parameter list, even with 64-bit pointers */
typedef union LargeDskBytes
{
	LargeDskParamList	parameterList;	/* DSKPARAMLIST */
	LargeDskBufferList	bufferList;		/* DSKBUFFERLIST */
	OidKeyList			oidKeyList;		/* DSKOIDKEYLIST */
} LargeDskBytes;

/* Long form parameter - used for a full (128) parameter list, even with 64-bit pointers.
 * Used by: interpParamCallBack, ExternalMethodNode::call, objGetPropertyValues, objSetPropertyValues, 
 *          objSendMsgWithParams, objSendMsgToObjWithParams, objSendEventMsg, objInvokeMethod, 
 *          jamcMethContxSendMsgUsingRqst */
typedef struct LargeDskParam
{
	 DskHeader	 		header;
	 LargeDskBytes 		body;
#if defined(__cplusplus)
	 // operators to make laying a LargeDskParam over a DskParam easier
	 operator DskParam*() { return reinterpret_cast<DskParam*>(this); }
	 operator DskParam&() { return reinterpret_cast<DskParam&>(*this);}
#endif
} LargeDskParam;

typedef int (JOMAPI* JadeProcSendMsgEntryPoint)
(
	const DskHandle*		pHandle,
	DskObjectId*			pOid,
	int						message
);

typedef int (JOMAPI* JadeGenericCallBack)
(
	DskHandle*			pHandle,
	void*				pParam
);

typedef int (JOMAPI* JadeWapperGenericCallBack)
(
	JadeGenericCallBack target,
	DskHandle*			pHandle,
	void*				pVoid
);

typedef int (JOMAPI* JadeTerminationCallBack)
(
	DskHandle*			pHandle,
	void*				pParam,
	bool                nodeTermination
);

typedef int (JOMAPI* DskMethodEntryPoint)
(
	DskBuffer* 			pDskBuffer,
	DskParam*  			pParams,
	DskParam*  			pResult
);

typedef int (JOMAPI* DskMethodReceiverByReferenceEntryPoint)
(
	const DskObjectId* 	pOid,
	DskParam*  			pParams,
	DskParam*  			pResult
	);

typedef int (JOMAPI* DskCollMethodEntryPoint)
(
	void*				pCollectionDescriptor,
	DskBuffer* 			pDskBuffer,
	DskParam*  			pParams,
	DskParam*  			pResult
);

typedef int (JOMAPI* DskCollReceiverByReferenceMethodEntryPoint)
(
	void*				pCollectionDescriptor,
	const DskObjectId*	pOid,
	DskParam*  			pParams,
	DskParam*  			pResult
	);

typedef int (JOMAPI* DskPrimMethodEntryPoint)
(
	TypeNum				primitiveNo,
	DskParam*			pValue,
	DskParam*			pParams,
	DskParam*			pResult
);

typedef Byte DictionaryKeyBuffer[(MAX_CONCAT_KEY_LENGTH + 1) * sizeof(Character)];

/* Data structure and callback typedef to handle obtaining a username and password from a 3rd party DLL */
typedef union GETPASSWORD_UNION_tag
{
	int					iVersion;
	struct GETPASSWORD_STRUCTv1_tag			// version == 1, SSL proxy web server authentication
	{
		int					iVersion;		// [IN]
		bool				bValid;			// [OUT] set to true, if valid data in username/password 
		Character			realm[60];		// [IN] requesting username/password for this realm
		Character			username[40];	// [OUT] NULL terminated user name
		Character			password[30];	// [OUT] NULL terminated password
		Character			domain[40];		// [OUT] NULL terminated domain (optional)
	} GETPASSWORD_STRUCTv1;
	struct GETPASSWORD_STRUCTv2_tag 		// version == 2, username/password to signon to a Jade application
	{
		int					iVersion;		// [IN]
		bool				bValid;			// [OUT] set to true, if valid data in username/password 
		Character			schemaName[MAX_IDENTIFIER_LENGTH + 1];	// [IN] schema name about to pass to jomSignOn
		Character			appName[MAX_IDENTIFIER_LENGTH + 1];		// [IN] application name about to pass to jomSignOn
		Character			userId[MAX_IDENTIFIER_LENGTH + 1];		// [OUT] NULL terminated user name
		Character			password[MAX_IDENTIFIER_LENGTH + 1];	// [OUT] NULL terminated password
	} GETPASSWORD_STRUCTv2;
} GETPASSWORD_UNION;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef int (JOMAPI * UserGetPasswordCallBack) (GETPASSWORD_UNION *);

#ifdef  __cplusplus
}
#endif /* __cplusplus */

// Example signature 
// extern "C" DllExport int JOMAPI UserSuppliedAuthCallback(GETPASSWORD_UNION * arg);

