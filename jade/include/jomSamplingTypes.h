/****************************************************************************

							P R O P R I E T A R Y   N O T I C E

	This software, in whole and in every part, is proprietary to Jade Software
	Corporation Limited at Christchurch, New Zealand and is not to be
	reproduced, used or disclosed except upon prior written permission of Jade
	Software Corporation Limited.

	COPYRIGHT (c) JADE SOFTWARE CORPORATION LIMITED 2005 - ALL RIGHTS RESERVED


****************************************************************************/

#ifndef JOMSAMPLINGTYPES_h
#define JOMSAMPLINGTYPES_h

#include "jomtypes.h"

/* request numbers */
#define GET_OBJECT_REQUEST					1
#define LOCK_OBJECT_REQUEST					2
#define UNLOCK_OBJECT_REQUEST				3
#define GET_OBJECT_GROUP_REQUEST			4
#define LOCK_OBJECT_GROUP_REQUEST			5
#define UNLOCK_OBJECT_GROUP_REQUEST			6
#define PUT_OBJECT_REQUEST					7
#define GET_OID_REQUEST						8
#define GET_EDITION_REQUEST					9
#define BEGIN_NOTIFICATION_REQUEST			11
#define END_NOTIFICATION_REQUEST			12
#define CAUSE_EVENT_REQUEST					13
#define RETURN_NOTES_REQUEST				14
#define RECEIVED_NOTIFICATION				15
#define BEGIN_TRANSACTION_REQUEST			16
#define END_TRANSACTION_REQUEST				17
#define ABORT_TRANSACTION_REQUEST			18
#define REMOTE_METHOD_CALL_REQUEST			19
/*Next three are used by the Most Frequently Accessed Objects feature*/
#define CREATE_OBJECT_REQUEST				20
#define UPDATE_OBJECT_REQUEST				21
#define DELETE_OBJECT_REQUEST				22

/* buffer read mode */
#define MODE_NOT_AVAILABLE					0 
#define NEW_BUFFER_REQUEST					1
#define NON_UPDATE_BUFFER_REQUEST			2
#define UPDATE_BUFFER_REQUEST				3
#define TEMPORARY_BUFFER_REQUEST			4

/* buffer put mode */
#define BUFFER_CREATED						1
#define BUFFER_UPDATED						2
#define BUFFER_DELETED						3

/* buffer unlock mode */
#define UNLOCK_INDIVIDUAL					1
#define REMOVE_LOCKS						2

/* remote method call mode */
#define STANDARD_METHOD						1
#define DB_METHOD							2

/* eventType */
#define EVENT_BEGIN							1
#define EVENT_END							2

/* samplingRequestOrigin */
#define LOCAL_SAMPLING_REQUEST				1
#define REMOTE_SAMPLING_REQUEST				2

/* samplingRequestMode */
#define MANUAL_SAMPLING_MODE				1
#define AUTOMATIC_SAMPLING_MODE				2

/* buffer activity in cache */
#define BUFFER_CREATED						1
#define BUFFER_ALLOCATED					2
#define BUFFER_REMOVED						3
#define BUFFER_SWAPPED						4
#define BUFFER_REALLOCATED					5
#define BUFFER_SNAPSHOT						6
#define BUFFER_STUBBED						7
#define BUFFER_EMPTIED						8
#define BUFFER_CYCLED						9

/* buffer ownership */
#define SHARED_BUFFER						0
#define NON_SHARED_BUFFER					1

/* buffer replication */
#define NON_REPLICA_BUFFER					0			
#define REPLICA_BUFFER						1

enum SemanticCategory
{
	SYSTEM_META_OBJECT 	= 1,
	SYSTEM_GUI_OBJECT 	= 2,
	SYSTEM_OBJECT		= 3,
	USER_META_OBJECT 	= 4,
	USER_GUI_OBJECT 	= 5,
	USER_OBJECT 		= 6,
	UNKNOWN_OBJECT 		= 7
};

enum PhysicalCategory
{
	NON_RESIDENT		= 0,
	NORMAL_OBJECT	 	= 1,
	COLLECTION_HEADER 	= 2,
	COLLECTION_BLOCK 	= 3,
	BLOB_SLOB		 	= 4,
	CLUSTER			 	= 5
};

//matches #defines in lockmgr.hpp
#define LOCK_KIND_PROCESS_LOCK				0
#define LOCK_KIND_NODE_LOCK					2

const ObjectVolatility OBJECT_VOLATILITY_VOLATILE	= VOLATILITY_VOLATILE;
const ObjectVolatility OBJECT_VOLATILITY_FROZEN		= VOLATILITY_FROZEN;
const ObjectVolatility OBJECT_VOLATILITY_STABLE		= VOLATILITY_STABLE;

/* record types */
#define	NODE_INFO_RECORD					0
#define	CACHE_INFO_RECORD					1
#define	OBJECT_BUFFER_RECORD				2
#define	BEGIN_PROCESS_INFO_RECORD			6
#define	END_PROCESS_INFO_RECORD				7
#define	LOCAL_REQUEST_STATISTICS_RECORD		8
#define	REMOTE_REQUEST_STATISTICS_RECORD	9
#define	INDIVIDUAL_REMOTE_REQUEST_RECORD	10
#define	BEGIN_SAMPLING_INTERVAL_RECORD		11
#define	END_SAMPLING_INTERVAL_RECORD		12
#define	USER_COMMAND_RECORD					13
#define	INDIVIDUAL_LOCAL_REQUEST_RECORD		14
#define	NODE_FINALIZE_RECORD				20

#define OBJECT_TRACKING_HEADER_RECORD		21
#define OBJECT_TRACKING_DATA_RECORD			22
#define OBJECT_TRACKING_TRAILER_RECORD		23
#define CACHE_TRACKING_HEADER_RECORD		24
#define CACHE_TRACKING_DATA_RECORD			25
#define CACHE_TRACKING_TRAILER_RECORD		26

/* sampling inifile settings */
const Character SAMPLING_SECTION_TAG[]			= TEXT("JadeSampling");
const Character SAMPLING_EXCEPTION_EVENT_TAG[]	= TEXT("SamplingExceptionEvent");

/* sampling exceptions */
#define	SAMPLING_OPEN_FAILED					1
#define	SAMPLING_WRITE_FAILED					2

enum SamplingRequestSource
{
	LOCAL_AUTOMATIC								= 1,
	LOCAL_MANUAL								= 2,
	REMOTE_MANUAL								= 3,
	SYSTEM_INDIRECT								= 4
};

enum SamplingEventSubType
{
	NON_APPLICABLE								= 0,
	WRITE_SAMPLE								= 1,
	USER_COMMAND								= 2
};

/* Structures */

typedef struct NodeSampleCallDesc
{
	DskObjectId					receiverObject;
	DskObjectId					methodOid;
	int							invokationMode;	/* mapping method, inherited, etc */
} NodeSampleCallDesc;

typedef struct NodeSampleTimeStamp
{
	int							processId;
	UInt64						clockTicks;
	UInt64						nodeCpuTime;
	UInt64						nodeTicks;
	UInt64						processCpuTime;
	UInt64						processTicks;
	UInt64						processLogicalClock;
} NodeSampleTimeStamp;

typedef struct NodeSampleUserInfo
{
	UInt32						userNumber;
	const Character*			pUserText;
	UInt32						userLibraryHandle;
} NodeSampleUserReference;

typedef struct NodeSampleNodeInfo
{
	NodeSampleTimeStamp*		pStartTime;
	UInt32						nodeHandleNumber;
	const Character*			pJADEVersionNumber;
	const Character*			pComputerName;
	int							nodeType;	/* App server, standard client, etc. */
} NodeSampleNodeInfo;

typedef struct NodeSampleProcessInfo
{
	UInt32						processHandleNumber;
	NodeSampleTimeStamp*		pTime;
	InstanceID					processInstanceId;
	InstanceID					nodeInstanceId;
	const Character*			pSchemaName;
	const Character*			pApplicationName;
	int							processLocation;	/* local, remote. */
	NodeSampleCallDesc*			pTopOfCallStack;
} NodeSampleProcessInfo;

typedef struct NodeSampleRequest
{
	UInt32						requestCount;
	UInt32						requestLevel;	
	UInt32						request;
	UInt32						mode;	
	UInt64						duration;	/* 0 for local requests */
	UInt32						size;
	BYTE						flag;
	UInt32						result;		/* 0 for local requests */
	LockWaitTime				waitTime;	/* 0 for local requests */
	InstanceID					processInstanceId;	/* 0 for local requests */
	BYTE						volatility;
	BYTE						lockRequestKind;
} NodeSampleRequest;

typedef struct NodeSampleDataCommInfo
{
	UInt32 						remoteNodeInstanceId;
	UInt64 						lastRequestBytesSent;
	UInt64 						lastRequestBytesReceived;
	UInt64 						lastRequestPacketsSent;
	UInt64 						lastRequestPacketsReceived;
} NodeSampleDataCommInfo;

typedef struct NodeSampleStatsArray
{
	UInt32 						entries;
	UInt64 						statValue[ 1 ];
} NodeSampleStatsArray;

typedef struct NodeSampleCacheSyncInfo
{
	UInt64 						totalCacheSyncerUpdatedObjects;
	UInt64 						totalCacheSyncerNotifications;
	UInt64 						cacheSyncerNotificationHits;
	UInt64 						cacheSyncerObjectHits;
	UInt64 						cacheSyncerObjectMisses;
	UInt64 						cacheSyncerRangeRequests;
} NodeSampleCacheSyncInfo; 

typedef struct NodeSampleNodeLockInfo
{
	UInt64 						removeNodeLockReqsSent;
	UInt64 						removeNodeLockReqsRcvd;
	UInt64 						swapoutNodeLockReqsSent;
} NodeSampleNodeLockInfo;

//06Jan2010: Use UInt64 for all counters, rather than 32/64 bit variants.
typedef struct NodeSampleObjectCacheInfo
{
	UInt64 						hits;
	UInt64 						misses;
	UInt64 						topOfLRUHits;
	UInt64						createdBuffers;
	UInt64						cleanSwappedBuffers;
	UInt64						dirtySwappedBuffers;
	UInt64						resizedBuffers;
	UInt64						maximumBufferSize;
	UInt64						totalNumberOfBuffers;
	UInt64						availableBufferSize;
	UInt64						maximumOverdraftBufferSize;
	UInt64						overdraftBufferSize;
	/* internal Information */
	UInt64						totalCumulativeOps;
	UInt64						totalCurrentOps;
	UInt64						totalCurrentBuffers;
	UInt64						totalDeletedBuffers;
	UInt64						totalDeadBuffers;
	UInt64						totalCopiedBuffers;
	UInt64						newBuffers;
	UInt64						totalFetches;
	UInt64						duplicateFetches;
	UInt64						totalStubs;
	UInt64						totalSwaps;
	UInt64						totalOpsWhenSwapped;
	UInt64						minOpsWhenSwapped;
	UInt64						maxOpsWhenSwapped;
	UInt64						totalAgeWhenSwapped;
	UInt64						minAgeWhenSwapped;
	UInt64						maxAgeWhenSwapped;
	UInt64						lruTraversals;
	UInt64						totalLruTraversalTicks;
	UInt64						lruTraversalTicks;
	NodeSampleCacheSyncInfo		cacheSyncInfo;
	NodeSampleNodeLockInfo		nodeLockInfo;
} NodeSampleObjectCacheInfo;

typedef struct NodeSampleObjectBuffer
{
	UInt32						lruOrder;
	UInt64						birthNodeTicks;
	UInt64						operations;
	const DskObjectId*			pOid;
	Size						objectSize;
	BYTE						flag;
	BYTE						status;
	BYTE						semanticCategory;
	BYTE						physicalCategory;
	BYTE						shared;
	BYTE						replica;
	UInt32						processNumber;
	Size						bufferSize;
	/* Internal information */
	UInt16						nailCount;
	UInt16						ioCount;
	BYTE						internalFlags;
	BYTE						lives;
	UInt16						cycles;
} NodeSampleObjectBuffer;
/*	Call backs */
typedef int (JOMAPI* NodeSampleInfoCallBack)
(
	NodeSampleTimeStamp*		pTimeStamp,
	NodeSampleUserReference*	pUserReference,
	int							eventType,	/* begin, end, etc */
	int							samplingRequestOrigin, /* 1- local, 2-remote. */
	int							samplingRequestMode /* 1-manual, 2-automatic. */
);

typedef int (JOMAPI* NodeSampleNodeInfoCallBack)
(
	NodeSampleTimeStamp*		pTimeStamp,
	NodeSampleNodeInfo*			pNodeInfo,
	NodeSampleUserReference*	pUserReference,
	int							eventType	/*1-begin, 2-end, etc */
);

typedef int (JOMAPI* NodeSampleProcessInfoCallBack)
(
	NodeSampleTimeStamp*		pTimeStamp,
	NodeSampleProcessInfo *		pProcessInfo,
	NodeSampleUserReference*	pUserReference,
	int							eventType	/* 1-begin, 2-end, etc */
);

typedef int (JOMAPI* NodeSampleIntervalCallBack)
(
	NodeSampleTimeStamp*		pTimeStamp,
	NodeSampleUserReference*	pUserReference,
	int							eventType,	/* 1- begin, 2- end, etc */
	int							individualLocalRequests,
	int							individualRemoteRequests,
	int							individualPersistentCacheActivities,
	int							individualTransientCacheActivities,
	int							individualRemoteTransientCacheActivities
);

typedef int (JOMAPI* NodeSampleIndividualRequestCallBack)
(
	NodeSampleTimeStamp*		pTimeStamp,
	NodeSampleProcessInfo*		pProcessInfo,
	NodeSampleUserReference*	pUserReference,
	NodeSampleRequest*			pRequest,
	NodeSampleDataCommInfo*		pDataComm,	/*  null for local requests */
	int							requestType,	/* 1-local or 2-remote */
	DskObjectId*				pOid
);

typedef int (JOMAPI* NodeSampleRequestStatisticsCallBack)
(
	NodeSampleTimeStamp*		pTimeStamp,
	NodeSampleProcessInfo *		pProcessInfo,
	NodeSampleUserReference*	pUserReference,
	int							requestType,	/* local, remote, etc */
	NodeSampleStatsArray*		pStats
);

typedef int (JOMAPI* NodeSampleCacheInfoCallBack)
(
	NodeSampleTimeStamp*		pTimeStamp,
	NodeSampleUserReference*	pUserReference,
	CacheType					cacheType,	/* 1-persistent, 2-transient, 3- remote transient */
	NodeSampleObjectCacheInfo*	pCache
);

typedef int (JOMAPI* NodeSampleObjectBufferCallBack)
(
	NodeSampleTimeStamp*		pTimeStamp,
	NodeSampleUserReference*	pUserReference,
	CacheType					cacheType,	/* 1-persistent, 2-transient, 3- remote transient */
	int							bufferActivity, 
	NodeSampleObjectBuffer*		pBuffer
);

typedef int (JOMAPI* NodeSampleUserCommandCallBack)
(
	NodeSampleTimeStamp*		pTimeStamp,
	NodeSampleUserReference*	pUserReference,
	const Character*			pUserCommand
);

extern "C" {

DllExport int JOMAPI	nodeSampleInfoCb(NodeSampleTimeStamp *, NodeSampleUserReference*, int, int, int);
DllExport int JOMAPI	nodeSampleNodeInfoCb(NodeSampleTimeStamp *, NodeSampleNodeInfo *, NodeSampleUserReference*, int);
DllExport int JOMAPI	nodeSampleProcessInfoCb(NodeSampleTimeStamp *, NodeSampleProcessInfo *, NodeSampleUserReference*, int);
DllExport int JOMAPI	nodeSampleIntervalCb(NodeSampleTimeStamp *, NodeSampleUserReference*, int, int, int, int, int, int);
DllExport int JOMAPI	nodeSampleIndividualRequestCb(NodeSampleTimeStamp *, NodeSampleProcessInfo *,
							NodeSampleUserReference *, NodeSampleRequest *, NodeSampleDataCommInfo *, int, DskObjectId *);
DllExport int JOMAPI	nodeSampleRequestStatisticsCb(NodeSampleTimeStamp *, NodeSampleProcessInfo *,
							NodeSampleUserReference *, int, NodeSampleStatsArray *);
DllExport int JOMAPI	nodeSampleCacheInfoCb(NodeSampleTimeStamp *, NodeSampleUserReference *, CacheType, NodeSampleObjectCacheInfo *);
DllExport int JOMAPI	nodeSampleObjectBufferCb(NodeSampleTimeStamp *, NodeSampleUserReference *, CacheType, int, NodeSampleObjectBuffer *);
DllExport int JOMAPI	nodeSampleUserCommandCb(NodeSampleTimeStamp *, NodeSampleUserReference *, Character *);

}

#endif /* JOMSAMPLINGTYPES_h */

