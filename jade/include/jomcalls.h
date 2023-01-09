/****************************************************************************

				P R O P R I E T A R Y   N O T I C E

	This software, in whole and in every part, is proprietary to Jade Software
	Corporation Limited at Christchurch, New Zealand and is not to be
	reproduced, used or disclosed except upon prior written permission of Jade
	Software Corporation Limited.

	COPYRIGHT (c) JADE SOFTWARE CORPORATION LIMITED 2005 - ALL RIGHTS RESERVED

****************************************************************************/

#ifndef JOMCALLS_h
#define JOMCALLS_h

#include "jomtypes.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef JOM_EXPORT  
#ifdef JOM_SOURCE
#define JOM_EXPORT  DllExport
#else
#define JOM_EXPORT  DllImport
#endif
#endif /* JOM_EXPORT */

// defined names for jomInitialize pServerName parameter
#define JOM_SINGLEUSER_TAG		TEXT("singleUser")
#define JOM_MULTIUSER_TAG		TEXT("multiUser")

JOM_EXPORT int JOMAPI jomInitialize(DskHandle* pNodeHandle, const DskParam* pDirectory, const DskParam* pServerType, const DskParam* pIniFile);
JOM_EXPORT int JOMAPI jomFinalize(DskHandle* pNodeHandle);
JOM_EXPORT int JOMAPI jomRehydrateProcess(const DskHandle* pNodeHandle, DskHandle* pProcessHandle, DskHandle* pSecurityHandle, const DskParam* pSchemaName, const DskParam* pAppName, const DskParam* pUserName,
							const DskParam* pPassword, const DskParam* pDbMode, const DskParam* pDbUsage, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomSignOn(const DskHandle* pNodeHandle, DskHandle* pProcessHandle, DskHandle* pSecurityHandle, const DskParam* pSchemaName, const DskParam* pAppName, const DskParam* pUserName, 
							const DskParam* pPassword, const DskParam* pDbMode, const DskParam* pDbUsage, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomInitializeApplication(const DskHandle* pHandle, bool, const DskParam* pParam, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomFinalizeApplication(const DskHandle* pHandle, bool, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomSignOff(DskHandle* pHandle, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomBeginTransaction(const DskHandle* pHandle, JomTransactionType type, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomEndTransaction(const DskHandle* pHandle, JomTransactionType type, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomAbortTransaction(const DskHandle* pHandle, JomTransactionType type, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomBeginLoad(const DskHandle* pHandle, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomEndLoad(const DskHandle* pHandle, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomBeginLock(const DskHandle* pHandle, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomEndLock(const DskHandle* pHandle, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomCreateObject(const DskHandle* pHandle, DskObjectId* pOid, ClassPersistence type, DskParam* pParam1, DskParam* pParam2, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomDeleteObject(const DskHandle* pHandle, const DskObjectId* pOid, DskParam* pParam1, DskParam* pParam2, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomGetObject(const DskHandle* pHandle, const DskObjectId* pOid, DskParam* pObjectBuffer, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomLockObject(const DskHandle* pHandle, const DskObjectId* pOid, LockType type, LockDuration duration, LockWaitTime waitTime, unsigned int invokeHandler, unsigned int* pSuccess, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomUnlockObject(const DskHandle* pHandle, const DskObjectId* pOid, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomGetLatestEdition(const DskHandle* pHandle, const DskObjectId* pOid, Edition* pEdition, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomGetBufferEdition(const DskHandle* pHandle, DskObjectId* pOid, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomUpdateEdition(const DskHandle* pHandle, const DskObjectId* pOid, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomIsValidObject(const DskHandle* pHandle, const DskObjectId* pOid, bool& valid, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomIsValidCollBlock(const DskHandle* pHandle, const DskObjectId* pOid, const DskObjectId* pHeaderOid, bool& valid, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomGetProperty(const DskHandle* pHandle, const DskObjectId* pOid, DskParam* pProp, DskParam* pValue, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomGetPropertyDesc(const DskHandle* pHandle, const DskObjectId* pOid, DskParam* pProp, DskParam* pValue, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomSetProperty(const DskHandle* pHandle, const DskObjectId* pOid, DskParam* pProp, const DskParam* pValue, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomSendMsg(const DskHandle* pHandle, const DskObjectId* pOid, DskParam* pMessage, DskParam* pParams, DskParam* pReturn, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomSendTypeMsg(const DskHandle* pHandle, ClassNumber classNumber, DskParam* pMessage, DskParam* pParams, DskParam* pReturn, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomInvokeMethod(const DskHandle* pHandle, const DskObjectId* pTargetOid, const DskObjectId* pParamTargetContext, const DskObjectId* pTargetMethod, DskParam *pInParam, DskParam *pOutParam, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomInvokeTypeMethod(const DskHandle* pHandle, const ClassNumber classNumber, const DskObjectId* pParamTargetContext, const DskObjectId* pTargetMethod, DskParam* pParams, DskParam* pReturn, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomCallPrimMethod(const DskHandle* pHandle, TypeNum primNo, DskParam* pValue, DskParam* pMessage, DskParam* pParams, DskParam* pReturn, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomInheritMethod(const DskHandle* pHandle, const DskObjectId* pOid, DskParam* pParams, DskParam* pReturn, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomInheritCreate(const DskHandle* pHandle, const DskObjectId* pOid, DskParam* pParam1, DskParam* pParam2, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomImportMethod(const DskHandle* pHandle, const DskObjectId* pOid, DskParam * pMessage, DskParam* pParams, DskParam* pReturn, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomSendEventMsg(const DskHandle* pHandle, const DskObjectId* pOid, DskParam* pMessage, DskParam* pParams, DskParam* pReturn,
							unsigned int raiseNoReceiverException, int noReceiverError, unsigned int raiseInvalidMessageException, int invalidMessageError, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomClearBuffers(const DskHandle* pHandle, const DskObjectId* pOid, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomChangeAccessMode(const DskHandle* pHandle, const DskParam* pMode, const DskParam* pUsage, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomResynchObject(const DskHandle * pHandle, const DskObjectId* pOid,  UInt32 lineNo);
JOM_EXPORT int JOMAPI jomBeginNotification(const DskHandle* pHandle, const DskParam* pSubscriber, const DskParam* pFeature, const DskObjectId* pTarget, NoteEventType eventType, 
							NoteResponseType responseType, NoteSubscriberType subscriberType, NoteUserTag userTag, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomEndNotification(const DskHandle* pHandle, const DskObjectId* pTarget, NoteEventType eventType, const DskParam* pSubscriber, const DskParam* pInterfaceFeature, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomCauseEvent(const DskHandle* pHandle, const DskObjectId* pTarget, NoteEventType eventType, UInt16 immediate, const DskParam* pInfo, const DskObjectId* pCausedBy, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomCauseSDEEvent(const DskHandle* pHandle, const DskObjectId* pTarget, NoteEventType eventType, UInt16 immediate, const DskParam* pInfo, const DskObjectId* pCausedBy, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomCauseSDSEvent(const DskHandle* pHandle, const DskObjectId* pTarget, NoteEventType eventType, UInt16 immediate, const DskParam* pInfo, const DskObjectId* pCausedBy, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomCountQueuedNotifications(const DskHandle * pHandle, int* pCount, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomSetNotificationDeliveryState(const DskHandle * pHandle, bool suspend, int* pState, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomRespondsTo(const DskHandle* pHandle, const DskObjectId* pOid, InterfaceNumber interfaceNo, unsigned int* pResult, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomIsKindOf(const DskHandle* pHandle, const DskObjectId* pOid, ClassNumber superClassNo, unsigned int* pResult, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomIsSubclassOf(const DskHandle* pHandle, ClassNumber subClassNo, ClassNumber superClassNo, unsigned int* pResult, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomGetExecInstances(const DskHandle* pHandle, DskObjectId* pGlobal, DskObjectId* pApp, DskObjectId* pRootSchema, DskObjectId* pSchema,
							DskObjectId* pSystem, DskObjectId* pNode, DskObjectId* pProcess, DskObjectId* pSession, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomArmExceptionHandler(const DskHandle* pHandle, const DskObjectId* pOid, const DskObjectId* pExceptionClass, DskParam* pMessage, DskParam* pInputParams, ExceptionScope scope, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomDisarmExceptionHandler(const DskHandle* pHandle, const DskObjectId* pExceptionClass, ExceptionScope scope, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomRaiseException(const DskHandle* pHandle, const DskObjectId* pException, ExceptionCause cause, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomTerminate(const DskHandle* pHandle, TerminateMode mode, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomGetSystemStatus(const DskHandle* pHandle, unsigned int* pInTransactionState, unsigned int* pInTransientTransactionState, unsigned int* pInLoadState, unsigned int* pInLockState,
							unsigned int* pInExceptionState, unsigned int* pUnicodeVersion, DskParam* pCurrentMth, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomCloneObject(const DskHandle* pHandle, const DskObjectId* pOid, DskBuffer** ppBuffer, ClassNumber classId, bool type, bool construct, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomGetLockStatus(const DskHandle* pHandle, const DskObjectId* pOid, LockType* type, LockDuration* duration, DskObjectId* pLockedBy, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomRegisterTerminationCallBack(const DskHandle* pNodeContextHandle, const DskHandle* pProcessHandle, JadeTerminationCallBack cb, const void* pParam, TerminationCallBackType, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomDeregisterTerminationCallBack(const DskHandle* pNodeContexthandle, const DskHandle* pProcessHandle, JadeTerminationCallBack cb, const void * pParam, TerminationCallBackType, LineNumber lineNo);
JOM_EXPORT int JOMAPI jomGetNodeContextHandle(const DskHandle* pProcessHandle, DskHandle* pNodeContextHandle);

typedef int (JOMAPI* JomInitialize)(DskHandle*, DskParam*, DskParam*, DskParam*);
typedef int (JOMAPI* JomFinalize)(const DskHandle*);
typedef int (JOMAPI* JomSignOn)(const DskHandle*, DskHandle*, DskHandle*, DskParam*, DskParam*, DskParam*, DskParam*, const DskParam*, const DskParam*, LineNumber);
typedef int (JOMAPI* JomSignOff)(const DskHandle*, UInt32);
typedef int (JOMAPI* JomInitializeApplication) (const DskHandle* pHandle, bool, const DskParam*, LineNumber lineNo);
typedef int (JOMAPI* JomFinalizeApplication) (const DskHandle* pHandle, bool, LineNumber lineNo);
typedef int (JOMAPI* JomBeginTransaction)(const DskHandle*, JomTransactionType, LineNumber);
typedef int (JOMAPI* JomEndTransaction)(const DskHandle*, JomTransactionType, LineNumber);
typedef int (JOMAPI* JomAbortTransaction)(const DskHandle*, JomTransactionType, LineNumber);
typedef int (JOMAPI* JomBeginLoad)(const DskHandle*, LineNumber);
typedef int (JOMAPI* JomEndLoad)(const DskHandle*, LineNumber);
typedef int (JOMAPI* JomBeginLock)(const DskHandle*, LineNumber);
typedef int (JOMAPI* JomEndLock)(const DskHandle*, LineNumber);
typedef int (JOMAPI* JomCreateObject)(const DskHandle*, DskObjectId*, ClassPersistence, DskParam*, DskParam*, LineNumber);
typedef int (JOMAPI* JomDeleteObject)(const DskHandle*, const DskObjectId*, DskParam*, DskParam*, LineNumber);
typedef int (JOMAPI* JomGetObject)(const DskHandle*, const DskObjectId*, DskParam*, LineNumber);
typedef int (JOMAPI* JomLockObject)(const DskHandle*, const DskObjectId*, LockType, LockDuration, LockWaitTime, unsigned int, unsigned int*, LineNumber);
typedef int (JOMAPI* JomUnlockObject)(const DskHandle*, const DskObjectId*, LineNumber);
typedef int (JOMAPI* JomGetLatestEdition)(const DskHandle*, const DskObjectId*, Edition*, LineNumber);
typedef int (JOMAPI* JomGetBufferEdition)(const DskHandle*, DskObjectId*, LineNumber);
typedef int (JOMAPI* JomUpdateEdition)(const DskHandle*, const DskObjectId*, LineNumber);
typedef int (JOMAPI* JomGetProperty)(const DskHandle*, const DskObjectId*, DskParam*, DskParam*, LineNumber);
typedef int (JOMAPI* JomGetPropertyDesc)(const DskHandle*, const DskObjectId*, DskParam*, DskParam*, LineNumber);
typedef int (JOMAPI* JomSetProperty)(const DskHandle*, const DskObjectId*, DskParam*, const DskParam*, LineNumber);
typedef int (JOMAPI* JomSendMsg)(const DskHandle*, const DskObjectId*, DskParam*, DskParam*, DskParam*, LineNumber);
typedef int (JOMAPI* JomInvokeMethod)(const DskHandle* pHandle, const DskObjectId* pTargetOid, const DskObjectId* pParamTargetContext, DskParam *pTargetMethod, DskParam *pInParam, DskParam *pOutParam, LineNumber lineNo);
typedef int (JOMAPI* JomCallPrimMethod)(const DskHandle*, TypeNum, DskParam*, DskParam*, DskParam*, DskParam*, LineNumber);
typedef int (JOMAPI* JomInheritMethod)(const DskHandle*, const DskObjectId*, DskParam*, DskParam*, LineNumber);
typedef int (JOMAPI* JomImportMethod)(const DskHandle*, const DskObjectId*, DskParam*, DskParam*, DskParam*, LineNumber);
typedef int (JOMAPI* JomSendEventMsg)(const DskHandle*, const DskObjectId*, DskParam*, DskParam*, DskParam*, unsigned int, int, unsigned int, int, LineNumber);
typedef int (JOMAPI* JomClearBuffers)(const DskHandle*, const DskObjectId*, LineNumber);
typedef int (JOMAPI* JomChangeAccessMode)(const DskHandle*, const DskParam*, const DskParam*, LineNumber);
typedef int (JOMAPI* JomBeginNotification)(const DskHandle*, DskParam*, DskParam*, const DskObjectId*, UInt32, UInt32, UInt32, UInt32, LineNumber);
typedef int (JOMAPI* JomEndNotification)(const DskHandle*, const DskObjectId*, UInt32, const DskParam*, const DskParam*, LineNumber);
typedef int (JOMAPI* JomCauseEvent)(const DskHandle*, const DskObjectId*, UInt32, UInt16, DskParam*, DskObjectId*, LineNumber);
typedef int (JOMAPI* JomCauseSDEEvent)(const DskHandle*, const DskObjectId*, UInt32, UInt16, DskParam*, DskObjectId*, LineNumber);
typedef int (JOMAPI* JomCauseSDSEvent)(const DskHandle*, const DskObjectId*, UInt32, UInt16, DskParam*, DskObjectId*, LineNumber);
typedef int (JOMAPI* JomCountQueuedNotifications)(const DskHandle*, int*, LineNumber);
typedef int (JOMAPI* JomSetNotificationDeliveryState)(const DskHandle*, bool, int*, LineNumber);
typedef int (JOMAPI* JomRespondsTo)(const DskHandle*, const DskObjectId*, ClassNumber, unsigned int*, LineNumber);
typedef int (JOMAPI* JomGetExecInstances)(const DskHandle*, DskObjectId*, DskObjectId*, DskObjectId*, DskObjectId*, DskObjectId*, DskObjectId*, DskObjectId*, DskObjectId*, LineNumber);
typedef int (JOMAPI* JomArmExceptionHandler)(const DskHandle*, const DskObjectId*, const DskObjectId*, DskParam*, DskParam*, ExceptionScope, LineNumber);
typedef int (JOMAPI* JomDisarmExceptionHandler)(const DskHandle*, const DskObjectId*, ExceptionScope, LineNumber);
typedef int (JOMAPI* JomRaiseException)(const DskHandle*, const DskObjectId*, ExceptionCause, LineNumber);
typedef int (JOMAPI* JomTerminate)(const DskHandle * pHandle, TerminateMode, LineNumber);
typedef int (JOMAPI* JomGetSystemStatus)(const DskHandle*, unsigned int*, unsigned int*, unsigned int*, unsigned int*, unsigned int*, unsigned int *, DskParam*, LineNumber);
typedef int (JOMAPI* JomCloneObject)(const DskHandle*, const DskObjectId*, DskBuffer**, ClassNumber, bool, bool, LineNumber);
typedef int (JOMAPI* JomRegisterTerminationCallBack)(const DskHandle*, const DskHandle*, JadeTerminationCallBack cb, const void * pParam, TerminationCallBackType, LineNumber lineNo);
typedef int (JOMAPI* JomDeregisterTerminationCallBack)(const DskHandle*, const DskHandle*, JadeTerminationCallBack cb, const void * pParam, TerminationCallBackType, LineNumber lineNo);
typedef int (JOMAPI* JomGetNodeContextHandle)(const DskHandle* pProcessHandle, DskHandle* pNodeContextHandle);

#ifndef JOMRES_EXPORT
#define JOMRES_EXPORT DllImport
#endif

JOMRES_EXPORT int JOMAPI jomGetMessageText(int num, Character msgString[], Size length);
JOMRES_EXPORT int JOMAPI jomGetMessageResourceText(int num, Character msgString[], Size length, UInt32 dwSeverity, UInt32 dwFacility);

typedef int (JOMAPI *jomGetMessageText_t)(int msgNum, Character message[], Size length);
typedef int (JOMAPI *jomGetMessageResourceText_t)(int msgNum, Character message[], Size length, UInt32 dwSeverity, UInt32 dwFacility);

#ifdef  __cplusplus
}
#endif /* __cplusplus */
#endif /* JOMCALLS_h */

