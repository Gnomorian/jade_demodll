/****************************************************************************

				P R O P R I E T A R Y   N O T I C E

	This software, in whole and in every part, is proprietary to Jade Software
	Corporation Limited at Christchurch, New Zealand and is not to be
	reproduced, used or disclosed except upon prior written permission of Jade
	Software Corporation Limited.

	COPYRIGHT (c) JADE SOFTWARE CORPORATION LIMITED 2009 - ALL RIGHTS RESERVED

****************************************************************************/

#ifndef JOSCALLS_h
#define JOSCALLS_h

#include "jomtypes.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef JOS_EXPORT
#ifdef JOS_SOURCE
#define JOS_EXPORT  DllExport
#else
#define JOS_EXPORT  DllImport
#endif
#endif /* JOS_EXPORT */

/*
	Following external functions are implemented in jomutil
*/

extern "C" JOS_EXPORT int JOMAPI josIniFileGetFileName(Character fileName[], Size size);

extern "C" JOS_EXPORT int JOMAPI josIniFileGetBoolean(const Character * pIniFileName, const Character * pSection, const Character * pKey, bool bDefault, bool & bValue);
extern "C" JOS_EXPORT int JOMAPI josIniFileGetSInteger(const Character * pIniFileName, const Character * pSection, const Character * pKey, Integer64 sDefault, Integer64 & sValue);
extern "C" JOS_EXPORT int JOMAPI josIniFileGetUInteger(const Character * pIniFileName, const Character * pSection, const Character * pKey, UInteger64 uDefault, UInteger64 & uValue);
extern "C" JOS_EXPORT int JOMAPI josIniFileGetString(const Character * pIniFileName, const Character * pSection, const Character * pKey, const Character * pDefault, Character* pValue, Size size);

extern "C" JOS_EXPORT int JOMAPI josIniFileSetBoolean(const Character * pIniFileName, const Character * pSection, const Character * pKey, bool bValue);
extern "C" JOS_EXPORT int JOMAPI josIniFileSetSInteger(const Character * pIniFileName, const Character * pSection, const Character * pKey, bool bMultipliers, Integer64 sValue);
extern "C" JOS_EXPORT int JOMAPI josIniFileSetUInteger(const Character * pIniFileName, const Character * pSection, const Character * pKey, bool bMultipliers, UInteger64 uValue);
extern "C" JOS_EXPORT int JOMAPI josIniFileSetString(const Character * pIniFileName, const Character * pSection, const Character * pKey, const Character * pValue);

extern "C" JOS_EXPORT int JOMAPI josGetDirectoryJade(Character pathName[], Size size);
extern "C" JOS_EXPORT int JOMAPI josGetDirectoryJadeBin(Character pathName[], Size size);
extern "C" JOS_EXPORT int JOMAPI josGetDirectoryJadeLib(Character pathName[], Size size);
extern "C" JOS_EXPORT int JOMAPI josGetDirectoryJadeTemp(Character pathName[], Size size);

extern "C" JOS_EXPORT int JOMAPI josCharacterToAnsi(const Character * pSource, char target[], Size sizeOfTargetInChar );
extern "C" JOS_EXPORT int JOMAPI josCharacterToUnicode(const Character * pSource, wchar_t target[], Size sizeOfTargetInWChar );

extern "C" JOS_EXPORT int JOMAPI josCharacterToUnicode(const Character * pSource, wchar_t target[], Size sizeOfTargetInWChar );

extern "C" JOS_EXPORT void JOMAPI josDskDateToGregorian(const DskDate date, DayType &day, MonthType &month, YearType &year);
extern "C" JOS_EXPORT void JOMAPI josDskTimeStampToGregorianHMSm(const DskTimeStamp * pDatetime, DayType &day, MonthType &month, YearType &year, int &dayOfWeek, int &hour, int &minute, int &second, int &milliSec);
extern "C" JOS_EXPORT int  JOMAPI josDskTimeStampCompare(const DskTimeStamp & datetimeA, const DskTimeStamp & datetimeB);

extern "C" JOS_EXPORT bool JOMAPI jomDecimalFromReal(Real real, DskDecimal* pResult);
extern "C" JOS_EXPORT bool JOMAPI jomDecimalFromInt64Scale(Int64 unscaled, Int32 scale, DskDecimal* pResult);
extern "C" JOS_EXPORT bool JOMAPI jomDecimalFromString(const Character string[], DskDecimal* pResult);
extern "C" JOS_EXPORT bool JOMAPI jomDecimalToReal(const DskDecimal* pDskDecimal, Real* pResult);
extern "C" JOS_EXPORT bool JOMAPI jomDecimalToString(const DskDecimal* pDskDecimal, Character* pResult, Size size, unsigned decimalPlaces);
extern "C" JOS_EXPORT int  JOMAPI jomDecimalCompare(const DskDecimal* pDskDecimal1, const DskDecimal* pDskDecimal2);

#ifdef  __cplusplus
}
#endif /* __cplusplus */
#endif /* JOSCALLS_h */
