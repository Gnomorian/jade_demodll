/****************************************************************************

				P R O P R I E T A R Y   N O T I C E

	This software, in whole and in every part, is proprietary to Jade Software
	Corporation Limited at Christchurch, New Zealand and is not to be
	reproduced, used or disclosed except upon prior written permission of Jade
	Software Corporation Limited.

	COPYRIGHT (c) JADE SOFTWARE CORPORATION LIMITED 2005 - ALL RIGHTS RESERVED

****************************************************************************/

#ifndef JOMPROXY_H
#define JOMPROXY_H

#ifndef JOMPROXY_LINKAGE	
#define JOMPROXY_LINKAGE	DllImport
#endif

JOMPROXY_LINKAGE DskObject * JOMAPI createInst(const DskObjectId &);
JOMPROXY_LINKAGE DskObject * JOMAPI createInst(const ShortDskObjectId &);
JOMPROXY_LINKAGE DskObject * JOMAPI createInst(ClassNumber classNo);
JOMPROXY_LINKAGE DskObject * JOMAPI newProxy(const DskObjectId &);

#endif /* JOMPROXY_H */

