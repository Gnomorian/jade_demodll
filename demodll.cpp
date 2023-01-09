/****************************************************************************

				P R O P R I E T A R Y   N O T I C E

	This software, in whole and in every part, is proprietary to Jade Software
	Corporation Limited at Christchurch, New Zealand and is not to be reproduced,
	used or disclosed except upon prior written permission of Jade Software
	Corporation Limited.

	COPYRIGHT (c) JADE SOFTWARE CORPORATION LIMITED 2004 - ALL RIGHTS RESERVED

****************************************************************************/

//
// demodll.cpp - sample external methods
//

#include <windows.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include <array>
#include <filesystem>
#include <algorithm>

#include "jomarch.h"
#include "jomcalls.h"
#include "joscalls.h"
#include "jomdefs.h"
#include "jomerrs.h"
#include "jommco.hpp"
#include "jommthno.h"
#include "jomobj.hpp"
#include "jomobjct.hpp"
#include "jomparam.hpp"
#include "jomtypes.h"
#include "jomtypno.h"

class SomeClass
{
public:
	void doSomething() const {}
};
SomeClass* pSomeClass{};

// Unicode/locale-aware replacements for C Run-Time library functions used here

inline Character* mystrupr(Character string[])
{
	pSomeClass->doSomething();
	return CharUpper(string);
}

inline Size mystrlen(const Character string[])
{
	return static_cast<Size>(lstrlen(string));
}

inline Character* mystrcpy(Character dest[], const Character source[])
{
	return lstrcpy(dest, source);
}

inline Character* mystrcat(Character dest[], const Character source[])
{
	return lstrcat(dest, source);
}

extern "C" DllExport BOOL CALLBACK
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_PROCESS_DETACH:
	case DLL_THREAD_DETACH:
	default:
	break;
	}

	return TRUE;
}

/*******************************************************************************

	Example 1:		Object method with one input parameter and a return value

	Jade definition:JadeScript::addTen(i :Integer):Integer
						is demoAddTen in demodll;

	Description:  	Adds 10 to the number passed as a parameter and returns
					this value.

	Parameters      pBuffer	points to the pBuffer containing the receiver object
					pParam  format = Integer
							contains the number passed as a parameter
					pReturn format = Integer
							used to return an integer value

*******************************************************************************/

extern "C" DllExport int JOMAPI demoAddTen(DskBuffer*, DskParam* pParam, DskParam* pReturn)
{
	Integer i;

	/* get the integer value passed in pParam */
	int result = paramGetInteger(*pParam, i);
	CHECK_RESULT;

	/* pass the new value back in pReturn */
	return paramSetInteger(*pReturn, i + 10) ;
}

/*******************************************************************************

	Example 2:		Object method with two input parameters and a return value

	Jade definition:JadeScript::addTogether(i, j :Integer):Integer
											is demoAddTogether in demodll;

	Description:  	Adds the 2 numbers passed as paramters together and returns
					this value.

	Parameters      pBuffer	points to the pBuffer containing the receiver object
					pParam  format = DskParamList
							contains the numbers passed as parameters
					pReturn format = Integer
							used to return an integer value

*******************************************************************************/

extern "C" DllExport int JOMAPI demoAddTogether(DskBuffer*, DskParam* pParams, DskParam* pReturn)
{
	Integer i, j;
	DskParam *pParam;

	/*	Get each parameter from the list in pParam */
	int result = paramGetParameter(*pParams, 1, pParam);
	CHECK_RESULT;
	result = paramGetInteger(*pParam, i);
	CHECK_RESULT;
	result = paramGetParameter(*pParams, 2, pParam);
	CHECK_RESULT;
	result = paramGetInteger(*pParam, j);
	CHECK_RESULT;

	/* add the two numbers together return in pReturn */
	return paramSetInteger(*pReturn, i + j);
}

/*******************************************************************************

	Example 3:		Object method with one input-output string parameter

	Jade definition:JadeScript::toUpper(s :String io)
						is demoToUpper in demodll;

	Description:  	Converts the string in s to upper case

	Parameters      pBuffer	points to the pBuffer containing the receiver object
					pParam  format = string
					pReturn not used

*******************************************************************************/

extern "C" DllExport int JOMAPI demoToUpper(DskBuffer*, DskParam* pParam, DskParam*)
{
	Character *pBuf;

	/* Get the string passed in pParam */
	int result = paramGetString(*pParam, pBuf);
	CHECK_RESULT;

	/* Use paramSetString to return the string, converted to upppercase, in
	   the format expected by the sender using pParam */
	return paramSetString(*pParam, mystrupr(pBuf), mystrlen(pBuf));
}

/*******************************************************************************

	Example 4A:		Object method with return value only.  Method invokes
					another Jade method.

	Jade definition:JadeScript::getClassName():String
						is demoGetClassName in demodll;

	Description:  	Returns the class name of the receiver object in uppercase.
					To do this we send a getName message to our receiver object.
					getName is an Jade method.

	Parameters      pBuffer	points to the pBuffer containing the receiver object
					pParam  not used
					pReturn format = string
							used to return a string containing the class name

*******************************************************************************/

extern "C" DllExport int JOMAPI demoGetClassName(DskBuffer* pBuffer, DskParam*, DskParam* pReturn)
{
	DskParam in, out;
	std::array<Character, MAX_IDENTIFIER_LENGTH + 1> buf;

	/* declare the receiver object so we can use the jomobj C++ wrappers */
	DskObject self(&pBuffer->oid);

	/* The getName method for Object returns the class name for the receiver
	   Initialise the input DskParam structure.  This is not used so can
	   set as being a parameter of undefined type*/
	int result = paramSetUndefined(in);
	CHECK_RESULT;

	/* Initialise the JadeString DskParam structure for getName method */
	result =  paramCreateJadeString( &out, buf.data(), static_cast<Size>(buf.size()));
	CHECK_RESULT;

	/* Invoke the Jade method */
	result = self.sendMsg(TEXT("getName"), &in, &out, __LINE__);
	CHECK_RESULT;
	/* Get the string returned by the getname method */

	Character* pBuf{ nullptr };
	result = paramGetString(out, pBuf);
	CHECK_RESULT;

	/* return the class name in uppercase in pReturn */
	result = paramSetString(*pReturn, mystrupr(pBuf));
	CHECK_RESULT;

	/* Delete the JadeString pBuffer */
	return paramDeleteJadeString(&out);
}

/*******************************************************************************

	Example 4B:		Object method with return value only.  Method invokes
					another external method.

	Jade definition:JadeScript::getOid() :String
						is demoGetOid in demodll;

	Description:  	Returns the oid of the receiver object.  To do this we send
					a getOidString message to our receiver object.  getOidString
					is an external method.

	Parameters      pBuffer	points to the pBuffer containing the receiver object
					pParam  not used
					pReturn format = string
							used to return a string containing the oid

*******************************************************************************/

extern "C" DllExport int JOMAPI demoGetOid(DskBuffer* pBuffer, DskParam*, DskParam* pReturn)
{
	/* declare the receiver object so we can use the jomobj C++ wrappers */
	DskObject self(&pBuffer->oid);

	/* The getOidString method for Object returns the oid as a string
	   The input DskParam structure is not used so a null can passed */
	auto result{ self.sendMsg(TEXT("getOidString"), nullptr, pReturn, __LINE__) };
	CHECK_RESULT;

	/* The string returned by the getOidString method has been placed directly
	   in the return buffer */
	return J_OK;
}

/*******************************************************************************

	Example 5A:		Primitive method with one parameter and a return value.

	Jade definition:Integer::toThePowerOf(i :Integer):Integer
						is demoToThePowerOf in demodll;

	Description:  	Returns the primitive value raised to the power of i.

	Parameters      pBuffer	points to the pBuffer containing the receiver object
					pParam  format = Integer
					pReturn format = Integer
							used to return the result

*******************************************************************************/

extern "C" DllExport int JOMAPI demoToThePowerOf(TypeNum, DskParam* primitiveValue, DskParam* pParam, DskParam* pReturn)
{
	Integer i, j;

	int result = paramGetInteger(*primitiveValue, i);
	CHECK_RESULT;
	result = paramGetInteger(*pParam, j);
	CHECK_RESULT;

	auto ri = static_cast<Real>(i);
	auto rj = static_cast<Real>(j);

	/* return the string in buf to the sender using pReturn */
	return paramSetInteger(*pReturn, static_cast<Integer>(lround(pow(ri, rj))), USAGE_CONSTANT);
}

/*******************************************************************************

	Example 5B:		Primitive method with one parameter.  This modifies the
					value of the primitive.

	Jade definition:Integer::meToThePowerOf(i :Integer)
						is demoMeToThePowerOf in demodll updating;

	Description:  	Raises an integer to the power of i.

	Parameters      pBuffer	points to the pBuffer containing the receiver object
					pParam  format = Integer
					pReturn not used

*******************************************************************************/

extern "C" DllExport int JOMAPI demoMeToThePowerOf(TypeNum, DskParam* primitiveValue, DskParam* pParam, DskParam*)
{
	Integer i, j;

	int result = paramGetInteger(*primitiveValue, i);
	CHECK_RESULT;
	result = paramGetInteger(*pParam, j);
	CHECK_RESULT;

	auto ri = static_cast<Real>(i);
	auto rj = static_cast<Real>(j);

	/* return the string in buf to the sender using pReturn
	   (round the real result to the nearest integer) */
	return paramSetInteger(*primitiveValue, static_cast<Integer>(lround(pow(ri, rj))));
}

/*******************************************************************************

	Example 6:		Object method with no parameters and no return value.
					Method is a constructor for the DemoObject Class.

	Jade definition:DemoObject::create()
						is demoCreate in demodll;

	Description:  	Sets maxSetting to 10 and minSetting to 1 for the
					receiver object.

	Parameters      pBuffer	points to the pBuffer containing the receiver object
					pParam  not used
					pReturn not used

*******************************************************************************/

extern "C" DllExport int JOMAPI demoCreate(DskBuffer* pBuffer, DskParam*, DskParam*)
{
	/* declare the receiver object so we can use the jomobj C++ wrappers */
	DskObject self(&pBuffer->oid);

	/* Use the setProperty method to set maxSetting & minSetting for the
	   receiver object */
	auto result{ self.setProperty(TEXT("maxSetting"), 10, __LINE__) };
	CHECK_RESULT;

	return self.setProperty(TEXT("minSetting"), 1, __LINE__);
}

/*******************************************************************************

	Example 7:		Object method to sort a (transient) integer array.

	Jade definition:IntegerArray::sort()
						is demoIntegerArraySort in demodll;

	Description:  	Sorts the receiving object (an integer array).

					An Iterator is used to copy the Jade integer array to a local
					(C) array prior to sorting.  The elements in the sorted array are then copied
					back into the original (Jade) array.

					NOTE: the signature of collection methods contains a nameless
					pointer to 'void'.  This parameter is reserved for internal use,
					but must be declared.

	Parameters      pBuffer	points to the pBuffer containing the receiver object
					pParam  not used
					pReturn not used

*******************************************************************************/

extern "C" DllExport int JOMAPI demoIntegerArraySort(void*, DskBuffer* pBuffer, DskParam*, DskParam*)
{
	/* declare the receiver object so we can use the jomobj C++ wrappers */
	DskArray self(&pBuffer->oid);

	/* determine the size of the array */
	UInt32 size;
	auto result{ self.getSize(&size) };
	CHECK_RESULT;

	if (size)
	{
		std::vector<Integer> array(size);

		/* use an iterator to copy the contents of the collection (a Jade integer
		   array) to local (C) array */
		DskIterator iterator;
		result = self.createIterator(&iterator);
		CHECK_RESULT;

		result = iterator.reset();
		CHECK_RESULT;

		DskParam entry, entryValid;
		result = paramSetInteger(entry);
		CHECK_RESULT;
		result = paramSetBoolean(entryValid);
		CHECK_RESULT;

		Boolean isValid;

		unsigned i = 0;

		/* iterate each entry in the array and copy to local storage */
		do
		{
			result = iterator.sendMsg(TEXT("next"), &entry, &entryValid, __LINE__);
			CHECK_RESULT;

			/* the iterator sets 'entryValid' to false when there are
			   no more entries */
			result = paramGetBoolean(entryValid, isValid);
			CHECK_RESULT;

			if (isValid)
			{
				result = paramGetInteger(entry, array[i++]);
				CHECK_RESULT;
			}
		}
		while (isValid);

		result = iterator.deleteObject();
		CHECK_RESULT;

		/* now sort the array */
		std::sort(array.begin(), array.end());

		DskParam paramList, index;

		/* the 'replace' method on Array expects two input parameters,
		   for convenience initialise a parameter list now */
		result = paramSetParameter(paramList, 1, &index);
		CHECK_RESULT;
		result = paramSetParameter(paramList, 2, &entry);
		CHECK_RESULT;

		/* now replace the entries in the original array with the sorted values */
		for (i = 0; i < size; i++)
		{
			result = paramSetInteger(index, i + 1);
			CHECK_RESULT;
			result = paramSetInteger(entry, array[i]);
			CHECK_RESULT;

			auto result = self.sendMsg(TEXT("replace"), &paramList, nullptr, __LINE__);
			CHECK_RESULT;
		}
	}

	return J_OK;
}

/*******************************************************************************

	Example 8:		Object method to two (transient) sorted integer arrays into
					another integer array (the receiver).

	Jade definition:IntegerArray::merge(array1, array2 : IntegerArray)
						is demoIntegerArrayMerge in demodll;

	Description:  	Iterators are used to scan the two input arrays appending the
					smaller entry at each iteration to the receiving array.

					NOTE: the signature of collection methods contains a nameless
					pointer to 'void'.  This parameter is reserved for internal use,
					but must be declared.

	Parameters      pBuffer	points to the pBuffer containing the receiver object
					pParams a parameter list pointing to the two input (sorted) integer arrays
					pReturn not used

*******************************************************************************/

/*
	Derive an interface class for an iterator from the DskIterator class.

	Instances of this class inherit the behaviuor of the C++ proxy class
	DskIterator, and define their own behaviour to retrieve the next integer
	(the "nextInteger" method)
*/

class IntegerArrayIterator : public DskIterator
{
public:

	IntegerArrayIterator() = default;
	~IntegerArrayIterator() = default;

	Boolean nextInteger(Integer& entry) const
	{
		DskParam nextEntry, entryValid;

		(void)paramSetInteger(nextEntry);
		(void)paramSetBoolean(entryValid);

		auto result{ sendMsg(TEXT("next"), &nextEntry, &entryValid, __LINE__) };
		if (result != J_OK)
			return false;

		/* the iterator sets 'entryValid' to false when there are
		   no more entries */
		Boolean isValid;
		(void)paramGetBoolean(entryValid, isValid);

		if (isValid)
			(void)paramGetInteger(nextEntry, entry);

		return isValid;
	}
};

extern "C" DllExport int JOMAPI demoIntegerArrayMerge(void*, DskBuffer* pBuffer, DskParam* pParams, DskParam*)
{
	/* declare the objects so we can use the jomobj C++ wrappers */
	DskArray self(&pBuffer->oid), array1, array2;

	DskParam* pParam = nullptr;

	/* dereference the two input parameters */
	auto result{ paramGetParameter(*pParams, 1, pParam) };
	CHECK_RESULT;
	result = paramGetOid(*pParam, array1.oid);
	CHECK_RESULT;

	result = paramGetParameter(*pParams, 2, pParam);
	CHECK_RESULT;
	result = paramGetOid(*pParam, array2.oid);
	CHECK_RESULT;

	/* use iterators to scan the contents of the collections (Jade integer arrays) */
	IntegerArrayIterator iterator1, iterator2;

	result = array1.createIterator(&iterator1);
	CHECK_RESULT;
	result = array2.createIterator(&iterator2);
	CHECK_RESULT;

	result = iterator1.reset();
	CHECK_RESULT;
	result = iterator2.reset();
	CHECK_RESULT;

	Integer entry1, entry2;

	/* fetch the first entry from each array */
	Boolean isValid1 = iterator1.nextInteger(entry1);
	Boolean isValid2 = iterator2.nextInteger(entry2);

	/* keep iterating until reaching the end of both arrays */
	while (isValid1 || isValid2)
	{
		Integer smaller;

		/* determine the smaller entry, unless one array is finished */
		if (!isValid2 || (isValid1 && entry1 < entry2))
		{
			/* array2 is finished, or entry1 is smaller */
			smaller = entry1;

			/* fetch the next entry from array1 */
			isValid1 = iterator1.nextInteger(entry1);
		}
		else if (!isValid1 || (isValid2 && entry2 < entry1))
		{
			/* array1 is finished, or entry2 is smaller */
			smaller = entry2;

			/* fetch the next entry from array2 */
			isValid2 = iterator2.nextInteger(entry2);
		}
		else
		{
			/* entries are the same - duplicates are removed */
			smaller = entry1;

			/* fetch the next entry from each array */
			isValid1 = iterator1.nextInteger(entry1);
			isValid2 = iterator2.nextInteger(entry2);
		}

		result = self.sendMsg(TEXT("add"), smaller, __LINE__);
		CHECK_RESULT;
	}

	result = iterator1.deleteObject();
	CHECK_RESULT;
	return iterator2.deleteObject();
}

extern "C" DllExport int JOMAPI demoExceptionHandler(DskBuffer*, DskParam*, DskParam* pReturn)
{
	MessageBox(nullptr, TEXT("Exception"), TEXT("demoExceptionHandler"), MB_OK);

	return paramSetInteger(*pReturn, E_PASS_BACK);
}


/*******************************************************************************

	Example 9:		External Function with one input parameter and a return value

	Description:  	Same example as Example 1, but uses External Function call interface,
					rather then External Method interface.
					Adds 10 to the number passed as a parameter and returns this value.

*******************************************************************************/

extern "C" DllExport int JOMAPI demoAddTenFunction(int i)
{
	return i + 10;
}

/*******************************************************************************

	Example 10:		Schema file encryption hooks.

	Description:	The source code of JADE methods in a schema extract file can
					optionally be encrypted and decrypted. JADE provides a default
					encryption algorithm, however you can use your own algorithm
					by supplying the hook routines encryptSchemaSource()
					and decryptSchemaSource().

					The following example hooks encrypt the source using a simple
					substitution cipher. An encryption identifier is prepended to
					each encrypted source to identify the algorithm used.
					On decryption, an error is returned if the identifier does not
					match.

*******************************************************************************/

static const Character encryptionId[] = TEXT("demo");
static const Size encryptionIdLen = (sizeof(encryptionId) / sizeof(Character)) - 1;

extern "C" DllExport int JOMAPI encryptSchemaSource(const BYTE*	inData,
					Size		inLength,
					BYTE**		pOutData,
					Size*		pOutLength)
{
	static Character* outBuff = nullptr;
	static Size outBuffLen = 0;
	unsigned int i, j;

	// We'll work in characters instead of bytes to handle Unicode.
	Character* inBuff = REINTERPRET_CAST(Character*,CONST_CAST(BYTE*,inData));
	Size inLen = inLength / sizeof(Character);

	//Re-allocate our output buffer if necessary.
	Size outLen = inLen + encryptionIdLen;
	if (outLen > outBuffLen)
	{
		delete [] outBuff;
		outBuffLen = outLen;
		outBuff = new Character[outBuffLen];
	}

	//Insert our encryption algorithm identifier at the start of the output buffer.
	for (i = 0; i < encryptionIdLen; i++)
		outBuff[i] = encryptionId[i];

	// Encrypt the input buffer into our output buffer.
	for (i = 0, j = encryptionIdLen; i < inLen ; i++, j++)
		// Add 1 to the value of each displayable character.
		if (inBuff[i] >= TEXT('\x20') && inBuff[i] < TEXT('\x7e'))
			outBuff[j] = STATIC_CAST(Character,inBuff[i] + 1);
		else
			outBuff[j] = inBuff[i];

	*pOutData = REINTERPRET_CAST(BYTE*,outBuff);
	*pOutLength = outLen * sizeof(Character);
	return J_OK;
}

extern "C" DllExport int JOMAPI decryptSchemaSource(const BYTE*	inData,
					Size		inLength,
					BYTE**		pOutData,
					Size*		pOutLength)
{
	constexpr int InvalidEncryptionId{ 1 };

	// We'll work in characters instead of bytes to handle Unicode.
	Character* inBuff = REINTERPRET_CAST(Character*,CONST_CAST(BYTE*,inData));
	Size inLen = inLength / sizeof(Character);

	// Check that the input buffer contains our encryption identifier.
	if (inLen < encryptionIdLen)
		return InvalidEncryptionId;

	for (unsigned int i = 0; i < encryptionIdLen; i++)
	{
		if (inBuff[i] != encryptionId[i])
			return InvalidEncryptionId;
	}

	// Decrypt the input buffer in place.
	for (unsigned int i = encryptionIdLen; i < inLen; i++)
	{
		// Subtract 1 from the value of each printable character.
		if (inBuff[i] > TEXT('\x20') && inBuff[i] <= TEXT('\x7e'))
			inBuff[i] = STATIC_CAST(Character, inBuff[i] - 1);
	}

	*pOutData = REINTERPRET_CAST(BYTE*,inBuff + encryptionIdLen);
	*pOutLength = (inLen - encryptionIdLen) * sizeof(Character);
	return J_OK;
}

/*******************************************************************************

	Example 11:		The 3 calls required for JADE development security

********************************************************************************/

/*******************************************************************************

	Description:  	getLogFilename
					A function to get the path to the log file demodll will use.
					It also demonstrates the use of Jade supplied
					utility C functions provided "joscall.h".  It puts the log
					file in the same directory as the jommsg.log as defined in
					the jade.ini file

*******************************************************************************/
std::filesystem::path getLogFilename()
{
	std::array<Character, JADE_MAX_PATH + 1> iniFile;
	auto result{ josIniFileGetFileName(iniFile.data(), static_cast<Size>(iniFile.size())) };
	if (result != J_OK)
		return {};

	std::array<Character, JADE_MAX_PATH + 1> logDirectory;
	result = josIniFileGetString(iniFile.data(), LOG_SECTION, TEXT("LogDirectory"), TEXT("logs"), logDirectory.data(), static_cast<Size>(logDirectory.size()));
	if (result != J_OK)
		return {};

	std::filesystem::path path(logDirectory.data());
	path /= TEXT("jadeDevelopment.log");

	return path;
}

static std::wofstream jadedevlog{getLogFilename(), std::ios_base::app};

/*******************************************************************************

	Description:  	jadeDevelopmentUserInfo
					called once when the user attempts to sign on (can be called
					again if the previous signon was rejected

	Parameters      userName  - the user sign on id
					password  - the password entered on the Jade Sign on screen

	*******************************************************************************/
extern "C" DllExport int JOMAPI jadeDevelopmentUserInfo(const Character* userName, const Character* /*password*/)
{
	//do the necessary user id/password validation here

	jadedevlog << TEXT("jadeDevelopmentUserInfo         userName=") << userName << std::endl;
	jadedevlog.flush();

	return J_OK;
}

/************************************************************************************

	Description:  	jadeDevelopmentFunctionSelected
					called for every function performed within the JADE development
					environment.

	Parameters      userName  - the user sign on id
					taskName  - the task about to be performed
					enityName - the entity that the task is to performed on

**************************************************************************************/

extern "C" DllExport int JOMAPI jadeDevelopmentFunctionSelected(const Character* userName, const Character* taskName, const Character* entityName)
{
	//do the necessary user/task validation here

	jadedevlog	<< TEXT("jadeDevelopmentFunctionSelected userName=") << userName
				<< TEXT(", taskName=") << taskName
				<< TEXT(", entityName=") << entityName << std::endl;
	jadedevlog.flush();
	return J_OK;
}

/************************************************************************************

	Description:  	jadeDevelopmentPatchControl
					called for every function performed within the JADE development
					environment.

	Parameters      userName		- the user sign on id
					patchDetails	- <entity-patch-number>:<user-patch-number>:<status>
					enityName		- the entity that the task is to performed on
					entityType		- class of the object being modified.
					operation		- type of operation (Add, Update, or Delete)

**************************************************************************************/
extern "C" DllExport int JOMAPI jadeDevelopmentPatchControl(const Character* userName, const Character*	patchDetails, const Character* entityName,
															const Character* entityType, const Character* operation)
{
	//do the necessary user/task validation here

	jadedevlog << TEXT("jadeDevelopmentPatchControl     userName=") << userName
		<< TEXT(", patchDetails=") << patchDetails
		<< TEXT(", entityName=") << entityName
		<< TEXT(", entityType=") << entityType
		<< TEXT(", operation=") << operation << std::endl;
	jadedevlog.flush();
	return J_OK;
}

/************************************************************************************

	Description:  	jadeDevelopmentExceptionHandler
					called locally (on the client or server depending on where it has been armed) to handle an exception.

					ini file key (server): JadeSecurity.DevelopmentSecurityLibrary
					ini file key (client): JadeSecurity.ClientDevelopmentSecurityLibrary

	Parameters      pDskBuffer		- exception handler receiver instance buffer
					pParams			- exception handler parameters
										Exception instance (oid)
										optional user-defined parameters
					pReturn			- exception handler return value (Integer)

**************************************************************************************/

extern "C" DllExport int JOMAPI jadeDevelopmentExceptionHandler(DskBuffer*, DskParam* pParams, DskParam* pReturn)
{
	
	if (!jadedevlog.bad())
	{
		// ignore the first parameter - the Exception instance
		DskParam* pParam;
		int result = paramGetParameter(*pParams, 2, pParam);
		CHECK_RESULT;

		// optional user-defined parameters. refer to jadeDevelopmentMethodServer() for the code that arms this handler
		Character* pParamUserName;
		result = paramGetString(*pParam, pParamUserName);
		CHECK_RESULT;
		result = paramGetParameter(*pParams, 3, pParam);
		CHECK_RESULT;
		Character* pParamTaskName;
		result = paramGetString(*pParam, pParamTaskName);
		CHECK_RESULT;
		result = paramGetParameter(*pParams, 4, pParam);
		CHECK_RESULT;
		Character* pParamEntityName;
		result = paramGetString(*pParam, pParamEntityName);
		CHECK_RESULT;

		jadedevlog	<< TEXT("jadeDevelopmentExceptionhandler userName=") << pParamUserName
					<< TEXT(", taskName=") << pParamTaskName
					<< TEXT(", entityName=") << pParamEntityName << std::endl;
		jadedevlog.flush();
	}

	// return Ex_Resume_Next;
	return paramSetInteger(*pReturn, E_RESUME);
}

/************************************************************************************

	Description:  	jadeDevelopmentMethodServer
					called on the server as required.

					called from serverExecution method: RootSchema::Application::jadeDevelopmentMethodServer(parameters : ParamListType io) serverExecution;

					ini file key (client): JadeSecurity.ClientDevelopmentSecurityLibrary

	Parameters      pDskBuffer		- Application instance buffer
					pParams			- user defined parameters (variable)
					pReturn			- user defined return value (variable)

**************************************************************************************/

extern "C" DllExport int JOMAPI jadeDevelopmentMethodServer(DskBuffer* /*pDskBuffer*/, DskParam* pParams, DskParam* /*pReturn*/)
{
	if (!jadedevlog.bad())
	{
		DskParam* pParam;
		int result = paramGetParameter(*pParams, 1, pParam);
		CHECK_RESULT;
		Character* pParamUserName;
		result = paramGetString(*pParam, pParamUserName);
		CHECK_RESULT;
		result = paramGetParameter(*pParams, 2, pParam);
		CHECK_RESULT;
		Character* pParamTaskName;
		result = paramGetString(*pParam, pParamTaskName);
		CHECK_RESULT;
		result = paramGetParameter(*pParams, 3, pParam);
		CHECK_RESULT;
		Character* pParamEntityName;
		result = paramGetString(*pParam, pParamEntityName);
		CHECK_RESULT;

		jadedevlog	<< TEXT("jadeDevelopmentMethodServer userName=") << pParamUserName
					<< TEXT(", taskName=") << pParamTaskName
					<< TEXT(", entityName=") << pParamEntityName << std::endl;
		jadedevlog.flush();
	}

	return J_OK;
}

/************************************************************************************

	Description:  	jadeDevelopmentMethodClient
					called on the client as required.

					called from clientExecution method: RootSchema::Application::jadeDevelopmentMethodClient(parameters : ParamListType io) clientExecution;

					ini file key (client): JadeSecurity.ClientDevelopmentSecurityLibrary

	Parameters      pDskBuffer		- Application instance buffer
					pParams			- user defined parameters (variable)
					pReturn			- user defined return value (variable)

**************************************************************************************/

extern "C" DllExport int JOMAPI jadeDevelopmentMethodClient(DskBuffer* /*pDskBuffer*/, DskParam* pParams, DskParam* /*pReturn*/)
{
	if (!jadedevlog.bad())
	{
		DskParam* pParam;
		int result = paramGetParameter(*pParams, 1, pParam);
		CHECK_RESULT;
		Character* pParamUserName;
		result = paramGetString(*pParam, pParamUserName);
		CHECK_RESULT;
		result = paramGetParameter(*pParams, 2, pParam);
		CHECK_RESULT;
		Character* pParamTaskName;
		result = paramGetString(*pParam, pParamTaskName);
		CHECK_RESULT;
		result = paramGetParameter(*pParams, 3, pParam);
		CHECK_RESULT;
		Character* pParamEntityName;
		result = paramGetString(*pParam, pParamEntityName);
		CHECK_RESULT;

		jadedevlog	<< TEXT("jadeDevelopmentMethodClient userName=") << pParamUserName
					<< TEXT(", taskName=") << pParamTaskName
					<< TEXT(", entityName=") << pParamEntityName << std::endl;
	}

	return J_OK;
}

/************************************************************************************

	Description:  	jadeDevelopmentMessageBox
					called on the client to display a message box. by default this displays the default Message Box.
					if confirmation to the user is not required, maybe because a message box has already been displayed 
					in a call to jadeDevelopmentMethodClient(), the return value should be set to MB_OK:

					called from clientExecution method: RootSchema::Application::jadeDevelopmentMessageBox(parameters : ParamListType io) clientExecution;

					ini file key (client): JadeSecurity.ClientDevelopmentSecurityLibrary

	Parameters      pDskBuffer		- Application instance buffer
					pParams			- message box parameters
										message : String
										title : String
										flags : Integer
					pReturn			- message box return value (Integer)

**************************************************************************************/

DllExport int JOMAPI jadeDevelopmentMessageBox(DskBuffer* pDskBuffer, DskParam* pParams, DskParam* pReturn)
{
	// use this code if a message box not required
	// return paramSetInteger(*pReturn, MB_OK);

	DskParam* pMessageParam;
	int result = paramGetParameter(*pParams, 1, pMessageParam);
	CHECK_RESULT;
	DskParam* pTitleParam;
	result = paramGetParameter(*pParams, 2, pTitleParam);
	CHECK_RESULT;
	DskParam* pFlagsParam;
	result = paramGetParameter(*pParams, 3, pFlagsParam);
	CHECK_RESULT;

	ShortDskParam methodParam;
	result = paramSetCString(methodParam, TEXT("msgBox"));
	CHECK_RESULT;

	ShortDskParam params;
	result = paramSetParamList(params, pMessageParam, pTitleParam, pFlagsParam);
	CHECK_RESULT;

	// redirect to RootSchema::Application::msgBox(message, title, flags) : Integer
	return jomSendMsg(JomDefaultProcessHandle, &pDskBuffer->oid, (DskParam*) &methodParam, (DskParam*) &params, pReturn, __LINE__);
}
