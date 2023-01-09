/****************************************************************************

				P R O P R I E T A R Y   N O T I C E

	This software, in whole and in every part, is proprietary to Jade Software
	Corporation Limited at Christchurch, New Zealand and is not to be
	reproduced, used or disclosed except upon prior written permission of Jade
	Software Corporation Limited.

	COPYRIGHT (c) JADE SOFTWARE CORPORATION LIMITED 2005 - ALL RIGHTS RESERVED

****************************************************************************/

#ifndef JOMSTR_h
#define JOMSTR_h

#include "jomtypes.h"

#ifdef __cplusplus

inline int JADE_DEREF_STRING(const DynamicDataHandler *pDynaHandler, Character*& pData)
{
	return pDynaHandler->callBack(JADE_DEREF_STRING_OP, pDynaHandler->pParam, (void**) &pData, 0);
}

inline int JADE_DEREF_STRING(DskParam* pParam, Character*& pData)
{
	return pParam->body.dataHandler.callBack(JADE_DEREF_STRING_OP, pParam, (void**) &pData, 0);
}

inline int JADE_GET_STRING(const DynamicDataHandler *pDynaHandler, Character *pDest, Size maxLen)
{
	return pDynaHandler->callBack(JADE_GET_STRING_OP, pDynaHandler->pParam, (void**) &pDest, &maxLen);
}

inline int JADE_GET_STRING(DskParam* pParam, Character *pDest, Size maxLen)
{
	return pParam->body.dataHandler.callBack(JADE_GET_STRING_OP, pParam, (void**) &pDest, &maxLen);
}

inline int JADE_SET_STRING(const DynamicDataHandler *pDynaHandler, const Character *pSource, Size length)
{
	return pDynaHandler->callBack(JADE_SET_STRING_OP, pDynaHandler->pParam, (void**) &pSource, &length);
}

inline int JADE_SET_STRING(DskParam* pParam, const Character *pSource, Size length)
{
	return pParam->body.dataHandler.callBack(JADE_SET_STRING_OP, pParam, (void**) &pSource, &length);
}

inline int JADE_RESIZE_STRING(const DynamicDataHandler *pDynaHandler, Size newLength)
{
	return pDynaHandler->callBack(JADE_RESIZE_STRING_OP, pDynaHandler->pParam, 0, &newLength);
}

inline int JADE_RESIZE_STRING(DskParam* pParam, Size newLength)
{
	return pParam->body.dataHandler.callBack(JADE_RESIZE_STRING_OP, pParam, 0, &newLength);
}

inline int JADE_STRING_LENGTH(const DynamicDataHandler *pDynaHandler, Size& len)
{
	return pDynaHandler->callBack(JADE_STRING_LENGTH_OP, pDynaHandler->pParam, 0, &len);
}

inline int JADE_STRING_LENGTH(DskParam* pParam, Size& len)
{
	return pParam->body.dataHandler.callBack(JADE_STRING_LENGTH_OP, pParam, 0, &len);
}

inline int 
JADE_STRING_MAX_LENGTH(const DynamicDataHandler *pDynaHandler, Size& len)
{
	return pDynaHandler->callBack(JADE_STRING_MAX_LENGTH_OP, pDynaHandler->pParam, 0, &len);
}

inline int JADE_STRING_MAX_LENGTH(DskParam* pParam, Size& len)
{
	return pParam->body.dataHandler.callBack(JADE_STRING_MAX_LENGTH_OP, pParam, 0, &len);
}

inline int JADE_GET_STRING_NO_NULL(const DynamicDataHandler *pDynaHandler, Character *pDest, Size maxLen)
{
	return pDynaHandler->callBack(JADE_GET_STRING_NO_NULL_OP, pDynaHandler->pParam, (void**) &pDest, &maxLen);
}

inline int JADE_GET_STRING_NO_NULL(DskParam* pParam, Character *pDest, Size maxLen)
{
	return pParam->body.dataHandler.callBack(JADE_GET_STRING_NO_NULL_OP, pParam, (void**) &pDest, &maxLen);
}

inline int JADE_APPEND_STRING(const DynamicDataHandler *pDynaHandler, const Character *pSource, Size length)
{
	return pDynaHandler->callBack(JADE_APPEND_STRING_OP, pDynaHandler->pParam, (void**) &pSource, &length);
}

inline int JADE_APPEND_STRING(DskParam* pParam, const Character *pSource, Size length)
{
	return pParam->body.dataHandler.callBack(JADE_APPEND_STRING_OP, pParam, (void**) &pSource, &length);
}

inline int JADE_DEREF_STRING_LENGTH(const DynamicDataHandler *pDynaHandler, Character*& pData, Size& len)
{
	return pDynaHandler->callBack(JADE_DEREF_STRING_LENGTH_OP, pDynaHandler->pParam, (void**) &pData, &len);
}

inline int JADE_DEREF_STRING_LENGTH(DskParam* pParam, Character*& pData, Size& len)
{
	return pParam->body.dataHandler.callBack(JADE_DEREF_STRING_LENGTH_OP, pParam, (void**) &pData, &len);
}

inline int JADE_DELETE_STRING(DskParam* pParam)
{
	return pParam->body.dataHandler.callBack(JADE_DELETE_STRING_OP, pParam, 0, 0);
}

inline int JADE_DEREF_BINARY(const DynamicDataHandler *pDynaHandler, BYTE*& pData)
{
	return pDynaHandler->callBack(JADE_DEREF_BINARY_OP, pDynaHandler->pParam, (void**) &pData, 0);
}

inline int JADE_DEREF_BINARY(DskParam* pParam, BYTE*& pData)
{
	return pParam->body.dataHandler.callBack(JADE_DEREF_BINARY_OP, pParam, (void**) &pData, 0);
}

inline int JADE_GET_BINARY(const DynamicDataHandler *pDynaHandler, BYTE *pDest, Size maxLen)
{
	return pDynaHandler->callBack(JADE_GET_BINARY_OP, pDynaHandler->pParam, (void**) &pDest, &maxLen);
}

inline int JADE_GET_BINARY(DskParam* pParam, BYTE *pDest, Size maxLen)
{
	return pParam->body.dataHandler.callBack(JADE_GET_BINARY_OP, pParam, (void**) &pDest, &maxLen);
}

inline int JADE_SET_BINARY(const DynamicDataHandler *pDynaHandler, const BYTE *pSource, Size length)
{
	return pDynaHandler->callBack(JADE_SET_BINARY_OP, pDynaHandler->pParam, (void**) &pSource, &length);
}

inline int JADE_SET_BINARY(DskParam* pParam, const BYTE *pSource, Size length)
{
	return pParam->body.dataHandler.callBack(JADE_SET_BINARY_OP, pParam, (void**) &pSource, &length);
}

inline int JADE_RESIZE_BINARY(const DynamicDataHandler *pDynaHandler, Size newLength)
{
	return pDynaHandler->callBack(JADE_RESIZE_BINARY_OP, pDynaHandler->pParam, 0, &newLength);
}

inline int JADE_RESIZE_BINARY(DskParam* pParam, Size newLength)
{
	return pParam->body.dataHandler.callBack(JADE_RESIZE_BINARY_OP, pParam, 0, &newLength);
}

inline int JADE_BINARY_LENGTH(const DynamicDataHandler *pDynaHandler, Size& len)
{
	return pDynaHandler->callBack(JADE_BINARY_LENGTH_OP, pDynaHandler->pParam, 0, &len);
}

inline int JADE_BINARY_LENGTH(DskParam* pParam, Size& len)
{
	return pParam->body.dataHandler.callBack(JADE_BINARY_LENGTH_OP, pParam, 0, &len);
}

inline int JADE_BINARY_MAX_LENGTH(const DynamicDataHandler *pDynaHandler, Size& len)
{
	return pDynaHandler->callBack(JADE_BINARY_MAX_LENGTH_OP, pDynaHandler->pParam, 0, &len);
}

inline int JADE_BINARY_MAX_LENGTH(DskParam* pParam, Size& len)
{
	return pParam->body.dataHandler.callBack(JADE_BINARY_MAX_LENGTH_OP, pParam, 0, &len);
}

inline int JADE_APPEND_BINARY(const DynamicDataHandler *pDynaHandler, const BYTE *pSource, Size length)
{
	return pDynaHandler->callBack(JADE_APPEND_BINARY_OP, pDynaHandler->pParam, (void**) &pSource, &length);
}

inline int JADE_APPEND_BINARY(DskParam* pParam, const BYTE *pSource, Size length)
{
	return pParam->body.dataHandler.callBack(JADE_APPEND_BINARY_OP, pParam, (void**) &pSource, &length);
}

inline int JADE_DEREF_BINARY_LENGTH(const DynamicDataHandler *pDynaHandler, BYTE*& pData, Size& len)
{
	return pDynaHandler->callBack(JADE_DEREF_BINARY_LENGTH_OP, pDynaHandler->pParam, (void**) &pData, &len);
}

inline int JADE_DEREF_BINARY_LENGTH(DskParam* pParam, BYTE*& pData, Size& len)
{
	return pParam->body.dataHandler.callBack(JADE_DEREF_BINARY_LENGTH_OP, pParam, (void**) &pData, &len);
}

inline int JADE_DELETE_BINARY(DskParam* pParam)
{
	return pParam->body.dataHandler.callBack(JADE_DELETE_BINARY_OP, pParam, 0, 0);
}

inline int JADE_DEREF_STRINGUTF8(const DynamicDataHandler *pDynaHandler, StringUtf8Info& pData)
{
	return pDynaHandler->callBack(JADE_DEREF_STRINGUTF8_OP, pDynaHandler->pParam, (void**) &pData, 0);
}

inline int JADE_DEREF_STRINGUTF8(DskParam* pParam, StringUtf8Info& pData)
{
	return pParam->body.dataHandler.callBack(JADE_DEREF_STRINGUTF8_OP, pParam, (void**) &pData, 0);
}

inline int JADE_GET_STRINGUTF8(const DynamicDataHandler *pDynaHandler, StringUtf8Info& pDest, Size maxLen)
{
	return pDynaHandler->callBack(JADE_GET_STRINGUTF8_OP, pDynaHandler->pParam, (void**) &pDest, &maxLen);
}

inline int JADE_GET_STRINGUTF8(DskParam* pParam, StringUtf8Info& pDest, Size maxLen)
{
	return pParam->body.dataHandler.callBack(JADE_GET_STRINGUTF8_OP, pParam, (void**) &pDest, &maxLen);
}

inline int JADE_SET_STRINGUTF8(const DynamicDataHandler *pDynaHandler, const StringUtf8Info& pSource)
{
	return pDynaHandler->callBack(JADE_SET_STRINGUTF8_OP, pDynaHandler->pParam, (void**) &pSource, 0);
}

inline int JADE_SET_STRINGUTF8(DskParam* pParam, const StringUtf8Info& pSource)
{
	return pParam->body.dataHandler.callBack(JADE_SET_STRINGUTF8_OP, pParam, (void**) &pSource, 0);
}

inline int 
JADE_RESIZE_STRINGUTF8(const DynamicDataHandler *pDynaHandler, Size newSize)
{
	return pDynaHandler->callBack(JADE_RESIZE_STRINGUTF8_OP, pDynaHandler->pParam, 0, &newSize);
}

inline int JADE_RESIZE_STRINGUTF8(DskParam* pParam, Size newSize)
{
	return pParam->body.dataHandler.callBack(JADE_RESIZE_STRINGUTF8_OP, pParam, 0, &newSize);
}

inline int JADE_STRINGUTF8_SIZE(const DynamicDataHandler *pDynaHandler, Size& sz)
{
	return pDynaHandler->callBack(JADE_STRINGUTF8_SIZE_OP, pDynaHandler->pParam, 0, &sz);
}

inline int JADE_STRINGUTF8_SIZE(DskParam* pParam, Size& sz)
{
	return pParam->body.dataHandler.callBack(JADE_STRINGUTF8_SIZE_OP, pParam, 0, &sz);
}

inline int JADE_STRINGUTF8_LENGTH(const DynamicDataHandler *pDynaHandler, Size& len)
{
	return pDynaHandler->callBack(JADE_STRINGUTF8_LENGTH_OP, pDynaHandler->pParam, 0, &len);
}

inline int JADE_STRINGUTF8_LENGTH(DskParam* pParam, Size& len)
{
	return pParam->body.dataHandler.callBack(JADE_STRINGUTF8_LENGTH_OP, pParam, 0, &len);
}

inline int JADE_STRINGUTF8_MAX_LENGTH(const DynamicDataHandler *pDynaHandler, Size& maxsz)
{
	return pDynaHandler->callBack(JADE_STRINGUTF8_MAX_LENGTH_OP, pDynaHandler->pParam, 0, &maxsz);
}

inline int JADE_STRINGUTF8_MAX_LENGTH(DskParam* pParam, Size& maxsz)
{
	return pParam->body.dataHandler.callBack(JADE_STRINGUTF8_MAX_LENGTH_OP, pParam, 0, &maxsz);
}

inline int JADE_APPEND_STRINGUTF8(const DynamicDataHandler *pDynaHandler, const StringUtf8Info& pSource)
{
	return pDynaHandler->callBack(JADE_APPEND_STRINGUTF8_OP, pDynaHandler->pParam, (void**) &pSource, 0);
}

inline int JADE_APPEND_STRINGUTF8(DskParam* pParam, const StringUtf8Info& pSource)
{
	return pParam->body.dataHandler.callBack(JADE_APPEND_STRINGUTF8_OP, pParam, (void**) &pSource, 0);
}

inline int JADE_DELETE_STRINGUTF8(DskParam* pParam)
{
	return pParam->body.dataHandler.callBack(JADE_DELETE_STRING_OP, pParam, 0, 0);
}

#else /* __cplusplus */

/* macros to call Interpreter call back function */
#define JADE_DEREF_STRING(pDynaHandler, pString) 				\
	(pDynaHandler)->callBack(JADE_DEREF_STRING_OP, (pDynaHandler)->pParam, &pString, 0);

#define JADE_GET_STRING(pDynaHandler, pDest, maxLen) 			\
	(pDynaHandler)->callBack(JADE_GET_STRING_OP, (pDynaHandler)->pParam, &pDest, &maxLen);

#define JADE_SET_STRING(pDynaHandler, pSource, len)  			\
	(pDynaHandler)->callBack(JADE_SET_STRING_OP, (pDynaHandler)->pParam, &pSource, &len);

#define JADE_RESIZE_STRING(pDynaHandler, newLength)        		\
	(pDynaHandler)->callBack(JADE_RESIZE_STRING_OP, (pDynaHandler)->pParam, 0, &newLength);

#define JADE_STRING_LENGTH(pDynaHandler, pLength) 				\
	(pDynaHandler)->callBack(pDynaHandler)->pParam(JADE_STRING_LENGTH_OP, (pDynaHandler)->pParam, 0, pLength);

#define JADE_STRING_MAX_LENGTH(pDynaHandler, pLength) 				\
	(pDynaHandler)->callBack(pDynaHandler)->pParam(JADE_STRING_MAX_LENGTH_OP, (pDynaHandler)->pParam, 0, pLength);

#define JADE_GET_STRING_NO_NULL(pDynaHandler, pDest, maxLen) 			\
	(pDynaHandler)->callBack(JADE_GET_STRING_NO_NULL_OP, (pDynaHandler)->pParam, &pDest, &maxLen);

#define JADE_APPEND_STRING(pDynaHandler, pSource, len)  			\
	(pDynaHandler)->callBack(JADE_APPEND_STRING_OP, (pDynaHandler)->pParam, &pSource, &len);

#define JADE_DEREF_STRING_LENGTH(pDynaHandler, pData, len) \
	(pDynaHandler)->callBack(JADE_DEREF_STRING_LENGTH_OP, (pDynaHandler)->pParam, &pData, &len);

#define JADE_DELETE_STRING(pDynaHandler) \
	(pDynaHandler)->callBack(JADE_DELETE_STRING_OP, (pDynaHandler)->pParam, 0, 0);

#define JADE_DEREF_BINARY(pDynaHandler, pString) 				\
	(pDynaHandler)->callBack(JADE_DEREF_BINARY_OP, (pDynaHandler)->pParam, &pString, 0);

#define JADE_GET_BINARY(pDynaHandler, pDest, maxLen) 			\
	(pDynaHandler)->callBack(JADE_GET_BINARY_OP, (pDynaHandler)->pParam, &pDest, &maxLen);

#define JADE_SET_BINARY(pDynaHandler, pSource, len)  			\
	(pDynaHandler)->callBack(JADE_SET_BINARY_OP, (pDynaHandler)->pParam, &pSource, &len);

#define JADE_RESIZE_BINARY(pDynaHandler, newLength)        		\
	(pDynaHandler)->callBack(JADE_RESIZE_BINARY_OP, (pDynaHandler)->pParam, 0, &newLength);

#define JADE_BINARY_LENGTH(pDynaHandler, pLength) 				\
	(pDynaHandler)->callBack(JADE_BINARY_LENGTH_OP, (pDynaHandler)->pParam, 0, pLength);

#define JADE_BINARY_MAX_LENGTH(pDynaHandler, pLength) 				\
	(pDynaHandler)->callBack(JADE_BINARY_MAX_LENGTH_OP, (pDynaHandler)->pParam, 0, pLength);

#define JADE_APPEND_BINARY(pDynaHandler, pSource, len)  			\
	(pDynaHandler)->callBack(JADE_APPEND_BINARY_OP, (pDynaHandler)->pParam, &pSource, &len);

#define JADE_DEREF_BINARY_LENGTH(pDynaHandler, pData, len) \
	(pDynaHandler)->callBack(JADE_DEREF_BINARY_LENGTH_OP, (pDynaHandler)->pParam, &pData, &len);

#define JADE_DELETE_BINARY(pDynaHandler) \
	(pDynaHandler)->callBack(JADE_DELETE_BINARY_OP, (pDynaHandler)->pParam, 0, 0);

#define JADE_DEREF_STRINGUTF8(pDynaHandler, pString) 				\
	(pDynaHandler)->callBack(JADE_DEREF_STRINGUTF8_OP, (pDynaHandler)->pParam, &pString, 0);

#define JADE_GET_STRINGUTF8(pDynaHandler, pDest, maxLen) 			\
	(pDynaHandler)->callBack(JADE_GET_STRINGUTF8_OP, (pDynaHandler)->pParam, &pDest, &maxLen);

#define JADE_SET_STRINGUTF8(pDynaHandler, pSource, len)  			\
	(pDynaHandler)->callBack(JADE_SET_STRINGUTF8_OP, (pDynaHandler)->pParam, &pSource, &len);

#define JADE_RESIZE_STRINGUTF8(pDynaHandler, newLength)        		\
	(pDynaHandler)->callBack(JADE_RESIZE_STRINGUTF8_OP, (pDynaHandler)->pParam, 0, &newLength);

#define JADE_STRINGUTF8_SIZE(pDynaHandler, pSize) 				\
	(pDynaHandler)->callBack(pDynaHandler)->pParam(JADE_STRINGUTF8_SIZE_OP, (pDynaHandler)->pParam, 0, pSize);

#define JADE_STRINGUTF8_LENGTH(pDynaHandler, pLength) 				\
	(pDynaHandler)->callBack(pDynaHandler)->pParam(JADE_STRINGUTF8_LENGTH_OP, (pDynaHandler)->pParam, 0, pLength);

#define JADE_STRINGUTF8_MAX_LENGTH(pDynaHandler, pSize) 				\
	(pDynaHandler)->callBack(pDynaHandler)->pParam(JADE_STRINGUTF8_MAX_LENGTH_OP, (pDynaHandler)->pParam, 0, pSize);

#define JADE_APPEND_STRINGUTF8(pDynaHandler, pSource)  			\
	(pDynaHandler)->callBack(JADE_APPEND_STRINGUTF8_OP, (pDynaHandler)->pParam, &pSource, 0);

#define JADE_DELETE_STRINGUTF8(pDynaHandler) \
	(pDynaHandler)->callBack(JADE_DELETE_STRINGUTF8_OP, (pDynaHandler)->pParam, 0, 0);

#endif /* __cplusplus */

#endif /* JOMSTR_h */
