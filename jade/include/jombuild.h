/****************************************************************************

		  P R O P R I E T A R Y   N O T I C E

	This software, in whole and in every part, is proprietary to Jade Software
	Corporation Limited at Christchurch, New Zealand and is not to be reproduced,
	used or disclosed except upon prior written permission of Jade Software
	Corporation Limited.

	COPYRIGHT ( C ) JADE SOFTWARE CORPORATION LIMITED 2022 - ALL RIGHTS RESERVED

****************************************************************************/

#ifndef JOMBUILD_h
#define JOMBUILD_h

#define JADE_BUILD_VERSION_MAJOR 		22
#define JADE_BUILD_VERSION_MINOR 		0
#define JADE_BUILD_VERSION_BUILD    	1

// Construct the linking check function name
#define MAKEMODULEVERSIONFUNC3(mod,maj,min,build)	moduleVersion_##mod##_##maj##_##min##_##build
#define MAKEMODULEVERSIONFUNC2(mod,maj,min,build)	MAKEMODULEVERSIONFUNC3(mod,maj,min,build)
#define MAKEMODULEVERSIONFUNC(mod)					MAKEMODULEVERSIONFUNC2(mod, JADE_BUILD_VERSION_MAJOR, JADE_BUILD_VERSION_MINOR, JADE_BUILD_VERSION_BUILD)

// Each JADE DLL exports a function named using MAKEMODULEVERSIONFUNC, 
// For example, the function name exported by jomutil.dll is "moduleVersion_jomutil_9_9_0".

// Importers can use the following to ensure that the importing dll/exe, the jomutil.lib and the jomutil.dll are consistent:
// Declaration:
//		extern "C" DllImport int JOMAPI MAKEMODULEVERSIONFUNC(jomutil)();
// Invocation:
//		int jomutilpatch = MAKEMODULEVERSIONFUNC(jomutil)();
//
// If this file does not match the jomutil.lib then the Linker complains, for example:
// 		mysource.obj : error LNK2019: unresolved external symbol __imp_moduleVersion_jomutil_7_0_7 referenced in function MyVersionChecker
//
// At runtime if the importer version (and the jomutil.lib version) do not match jomutil.dll then the Dynamic Linker complains:
//		The procedure entry point moduleversion_jomutil_7_0_8 could not be located in the dynamic library jomutil.dll.

#endif /*JOMBUILD_h*/
