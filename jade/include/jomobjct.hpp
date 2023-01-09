/****************************************************************************

				P R O P R I E T A R Y   N O T I C E

	This software, in whole and in every part, is proprietary to Jade Software
	Corporation Limited at Christchurch, New Zealand and is not to be
	reproduced, used or disclosed except upon prior written permission of Jade
	Software Corporation Limited.

	COPYRIGHT (c) JADE SOFTWARE CORPORATION LIMITED 2005 - ALL RIGHTS RESERVED

****************************************************************************/

#ifndef JOMOBJCT_hpp
#define JOMOBJCT_hpp

#include <stdlib.h>

#include "jomtypes.h"

/* 'default' structure member alignment (packing) */
#ifdef JADE_64BIT_NODE
#include "jompack8.h"
#else
#include "jompack4.h"
#endif

#ifndef JOMOBJ_LINKAGE
#define JOMOBJ_LINKAGE CLASS_IMPORT
#endif /* JOMOBJ_LINKAGE */

// hash value for a pointer
inline HashValue pointerHash(const void* p)
{ 
#if defined(JADE_64BIT_NODE)
	// 64 bit pointer, 32 bit hash value: just add the two 32 bit values
	return (HashValue) ((size_t(p) & 0xFFFFFFFF) + ((size_t(p) >> 32) & 0xFFFFFFFF));
#else
	// 32 bit pointer, 32 bit hash value: just return the value of the pointer
	return (HashValue) size_t(p);
#endif
}

class JOMOBJ_LINKAGE JomObj
{
	int		referenceCount;

public:
	JomObj()						{ referenceCount = 0; }
	virtual ~JomObj();

	int				referenceInc()	{ return ++referenceCount; }
	int				referenceDec()	{ return --referenceCount; }
	int				refCount() const{ return referenceCount; }

	virtual HashValue hash() const	{ return pointerHash(this); }
    virtual HashValue hashNumber() const;

	virtual bool	isEqual(const JomObj& x) const { return this == &x; } // if not reimplemented do id test
	virtual bool	isEqual(const Character[]) const;		// must be reimplemented
	virtual bool	isEqual(unsigned number) const;			// must be reimplemented

	bool			operator == (const JomObj& anObj) const		{ return isEqual(anObj); }
	bool			operator != (const JomObj& anObj) const		{ return !isEqual(anObj); }
	bool			operator == (const Character string[]) const{ return isEqual(string); }
	bool			operator != (const Character string[]) const{ return !isEqual(string); }
	bool			operator == (unsigned number) const			{ return isEqual(number); }
	bool			operator != (unsigned number) const			{ return !isEqual(number); }

	// Overload the new and delete operators to force the pairing of the calls for
    // alloc and free to the same module for all JomObjs.
	void*			operator new(size_t);
	void			operator delete(void*);
};

typedef JomObj*		JomObjp;
typedef JomObj*		PJomObj;

#include "jompack0.h"				/* restore structure member alignment (packing) */

#endif /* JOMOBJCT_hpp */
