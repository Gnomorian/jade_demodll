/****************************************************************************

				P R O P R I E T A R Y   N O T I C E

	This software, in whole and in every part, is proprietary to Jade Software
	Corporation Limited at Christchurch, New Zealand and is not to be
	reproduced, used or disclosed except upon prior written permission of Jade
	Software Corporation Limited.

	COPYRIGHT (c) JADE SOFTWARE CORPORATION LIMITED 2005 - ALL RIGHTS RESERVED

****************************************************************************/

#pragma once

#define COLLECT_HPP

#include "jomarch.h"
#include "jomobjct.hpp"

#ifndef JOMOBJ_LINKAGE 
#define JOMOBJ_LINKAGE CLASS_IMPORT
#endif

typedef void (* doBlock) (const JomObj& aJomObj);
typedef void (JomObj::* memberDoBlock) (const JomObj& aJomObj);
typedef int (* cmpBlock) (const JomObj& x, const JomObj& y);

class DskObject;

class JOMOBJ_LINKAGE JomColl: public JomObj //abstract class
{
public:
	JomColl()				{ }
	virtual ~JomColl()		{ }

	//from the yet non-existant object class
	virtual unsigned size() const = 0;

	//own methods
	virtual JomObj*	add(JomObj*) = 0;
			void	add(const DskObject& object);
	virtual void	add(const DskObjectId&) = 0;
	virtual void	add(const ShortDskObjectId&) = 0;
			void	addAll(const JomColl& aJomColl)
							{ aJomColl.addYourself(this); }
	virtual void	addYourself(JomColl*) const = 0; 		
	virtual void	doLoop(doBlock) const = 0 ; 				 	
	virtual void	doLoop(JomObj&, memberDoBlock) const = 0;
	virtual bool	includes(const JomObj*) const = 0;
			bool	includes(const DskObject&) const;
	virtual bool	includes(const DskObjectId&) const = 0;
	virtual bool	includes(const ShortDskObjectId&) const = 0;
	virtual bool	next(JomObjp&) = 0;
	virtual void	growTo(unsigned anInteger) = 0;
};

typedef JomColl* JomCollp;
typedef JomColl* PJomColl;

const unsigned AHEAD_OPERATION_BREAKEVEN_VALUE = 2;

class JOMOBJ_LINKAGE OrderedJomColl: public JomColl
{
	unsigned		lastAheadOperationIndex;
	bool			useReadAhead;
	bool			useLockAhead;
	bool			useUnlockAhead;
	bool			resynching;
	LockType		lockType;

	void			grow()	{ growTo(contentsSize * 3 / 2 + 1); }
	void			doAhead();
	void			removeIndex(unsigned);

protected:
	JomObj**		pContents;
	unsigned		entries;
	unsigned		index;
	unsigned		contentsSize;

public:
	//from the yet non-existant object class

	//own methods
	OrderedJomColl(unsigned anInteger = 0);
	virtual ~OrderedJomColl();

	virtual void	growTo(unsigned anInteger);
	virtual JomObj* add(JomObj*);							
	virtual void	add(const DskObjectId&);
	virtual void	add(const ShortDskObjectId&);
	virtual void	addYourself(JomColl*) const;				
	JomObj*			at(unsigned) const;
	bool			back(JomObjp&);	 						
	virtual void	doLoop(doBlock) const;	 					
	virtual void	doLoop(JomObj&, memberDoBlock) const;	
	void			end()	{ index = entries; }	
	virtual bool	includes(const JomObj*) const;
	virtual bool	includes(const DskObjectId&) const;
	virtual bool	includes(const ShortDskObjectId&) const;
	virtual bool	next(JomObjp&);			 				
	JomObj*			remove(JomObj*);						
	unsigned		size() const 
							{ return entries; }
	void			start()	{ index = 1; lastAheadOperationIndex = 0; }	
    void			clear();
	void			enableReadAhead(bool);
	void			disableReadAhead();
	void			enableLockAhead(LockType);
	void			disableLockAhead();
	void			enableUnlockAhead();
	void			disableUnlockAhead();

	inline JomObjp& operator [] (unsigned index)
	{
		return pContents[ index ];
	}

	inline JomObjp& operator [] (unsigned index) const
	{
		return pContents[ index ];
	}

	inline JomObjp& operator [] (int index)
	{
		return pContents[ index ];
	}

	inline JomObjp& operator [] (int index) const
	{
		return pContents[ index ];
	}
};

class JOMOBJ_LINKAGE OrderedOidColl: public JomColl
{
	unsigned		lastAheadOperationIndex;
	bool			useReadAhead;
	bool			useLockAhead;
	bool			useUnlockAhead;
	bool			resynching;
	LockType		lockType;

	void			grow()	{ growTo(contentsSize * 3 / 2 + 1); }
	void			doAhead();
	void			removeIndex(unsigned);

protected:
	ShortDskObjectId*pContents;
	unsigned		entries;
	unsigned		index;
	unsigned		contentsSize;

public:
	OrderedOidColl(unsigned anInteger = 0);
	virtual ~OrderedOidColl();

	virtual void	growTo(unsigned anInteger);
	virtual JomObj* add(JomObj*);
	virtual void	add(const DskObjectId&);
	virtual void	add(const ShortDskObjectId&);
	virtual void	addYourself(JomColl*) const;				
	ShortDskObjectId*at(unsigned) const;
	bool			back(DskObjectId&);	 						
	bool			back(ShortDskObjectId&);	 						
	virtual void	doLoop(doBlock) const;	 					
	virtual void	doLoop(JomObj&, memberDoBlock) const;	
	void			end()	{ index = entries; }	
	virtual bool	includes(const JomObj*) const;
	virtual bool	includes(const DskObjectId&) const;
	virtual bool	includes(const ShortDskObjectId&) const;
	virtual bool	next(JomObjp&);
	virtual bool	next(DskObjectId&);			 				
	virtual bool	next(ShortDskObjectId&);			 				
			bool	next(DskObject&);
	void			remove(const ShortDskObjectId&);						
	unsigned		size() const 
							{ return entries; }
	void			start()	{ index = 1; lastAheadOperationIndex = 0; }	
    void			clear();
	void			enableReadAhead(bool);
	void			disableReadAhead();
	void			enableLockAhead(LockType);
	void			disableLockAhead();
	void			enableUnlockAhead();
	void			disableUnlockAhead();

	inline ShortDskObjectId& operator [] (unsigned index)
	{
		return pContents[ index ];
	}

	inline ShortDskObjectId& operator [] (unsigned index) const
	{
		return pContents[ index ];
	}

	inline ShortDskObjectId& operator [] (int index)
	{
		return pContents[ index ];
	}

	inline ShortDskObjectId& operator [] (int index) const
	{
		return pContents[ index ];
	}
};
