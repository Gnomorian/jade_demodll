/****************************************************************************

				P R O P R I E T A R Y   N O T I C E

	This software, in whole and in every part, is proprietary to Jade Software
	Corporation Limited at Christchurch, New Zealand and is not to be
	reproduced, used or disclosed except upon prior written permission of Jade
	Software Corporation Limited.

	COPYRIGHT (c; JADE SOFTWARE CORPORATION LIMITED 2020 - ALL RIGHTS RESERVED

****************************************************************************/

//*********************************************************************************
//	D E F I N E S   F O R   C L A S S E S   A N D   P R I M I T I V E   T Y P E S
//*********************************************************************************

#pragma once

// ---------- Defines some basic types ------------------------------------------ 
// moved them over from jomtypes.h to break dependency of jomtypno.h from jomtypes.h 

typedef Int32			TypeNum;
typedef Int32			ClassNumber;
typedef UInt32			SchemaNumber;
typedef UInt32			PackageNumber;
typedef UInt32			InterfaceNumber;

// ---------- Defines for schema number ranges ---------------------------------- 

const SchemaNumber ROOT_SCHEMA_NUM					= 1;
const SchemaNumber JADE_SCHEMA_NUM					= 2;
const SchemaNumber JADE_MONITOR_SCHEMA_NUM			= 4;
const SchemaNumber JADE_TOOLS_SCHEMA_NUM			= 5;
const SchemaNumber JADE_ATCG_GENERATOR_SCHEMA_NUM	= 6;														// schema number if AtcgGeneratorSchema is a subschema of Jade 
const SchemaNumber JADE_TEST_ROOT_SCHEMA_NUM		= 7;
const SchemaNumber JADE_TEST_JADE_SCHEMA_NUM		= 8;
const SchemaNumber JADE_TEST_JADE_MONITOR_SCHEMA_NUM	= 9;
const SchemaNumber JADE_TEST_JADE_TOOLS_SCHEMA_NUM		= 10;
const SchemaNumber MIN_USER_SCHEMA_NUM				= 100;
const SchemaNumber MAX_SCHEMA_NUM					= 65535;

// ---------- Defines for class number ranges ----------------------------------- 
const ClassNumber MIN_CLASS_NUM						= 1;
const ClassNumber MAX_CLASS_NUM						= 0x000FFFFF;												// 1,048,575 = 2 ^ 20 - 1 
	
const ClassNumber MIN_ROOT_SCHEMA_CLASS_NUM			= MIN_CLASS_NUM;											// 1  
const ClassNumber MAX_ROOT_SCHEMA_CLASS_NUM			= 2047;														// 2047 

// All class in the RootSchema can be remapped 
const ClassNumber MIN_REMAP_CLASS_NUM				= 1;
const ClassNumber MAX_REMAP_CLASS_NUM				= MAX_ROOT_SCHEMA_CLASS_NUM;

const ClassNumber MIN_USER_CLASS_NUM				= MAX_ROOT_SCHEMA_CLASS_NUM + 1;							// 2048 
const ClassNumber MAX_USER_CLASS_NUM				= 999999;													// 999,999 

const int USER_REMAP_OFFSET							= MAX_USER_CLASS_NUM + 1;									// ClassNumber is signed 

const ClassNumber MIN_USER_REMAP_CLASS_NUM			= MIN_REMAP_CLASS_NUM + USER_REMAP_OFFSET;					// 1,000,001 
const ClassNumber MAX_USER_REMAP_CLASS_NUM			= MAX_REMAP_CLASS_NUM + USER_REMAP_OFFSET;					// 1,002,047 

// We allow a maximum of 100 transient classes per process 
const unsigned MAX_TRANSIENT_CLASSES				= 100;
const ClassNumber MIN_TRANSIENT_CLASS_NUM			= 1002100;													// 1,002,100 
const ClassNumber MAX_TRANSIENT_CLASS_NUM			= MIN_TRANSIENT_CLASS_NUM + MAX_TRANSIENT_CLASSES - 1;		// 1,002,199 

// 400 ReportWriter classes 
const unsigned MAX_REPORTWRITER_CLASSES				= 400;
const ClassNumber MIN_REPORTWRITER_CLASS_NUM		= 1002200;													// 1,002,200 
const ClassNumber MAX_REPORTWRITER_CLASS_NUM		= MIN_REPORTWRITER_CLASS_NUM + MAX_REPORTWRITER_CLASSES - 1;// 1,002,599 

// 1,000 classes for other system schema classes, eg JadeMonitorSchema, JadeToolsSchema and ATCG 
const unsigned MAX_SYSTEMSCHEMA_CLASSES				= 1000;
const ClassNumber MIN_SYSTEMSCHEMA_CLASS_NUM		= 1003000;													// 1,003,000 
const ClassNumber MAX_SYSTEMSCHEMA_CLASS_NUM		= MIN_SYSTEMSCHEMA_CLASS_NUM + MAX_SYSTEMSCHEMA_CLASSES - 1;// 1,003,999 

// 10,000 classes for JadeSchema 
const ClassNumber MIN_JADE_SCHEMA_CLASS_NUM			= 1004000;													// 1,004,000 
const ClassNumber MAX_JADE_SCHEMA_CLASS_NUM			= 1014000;													// 1,014,000

// system test schemas (JadeTestRootSchema, JadeTestJadeSchema) can have the rest
const ClassNumber MIN_TEST_SCHEMA_CLASS_NUM			= 1014001;													// 1,014,001 
const ClassNumber MAX_TEST_SCHEMA_CLASS_NUM			= MAX_CLASS_NUM;											// 1,048,575 

// ------------------------------------------------------------------------------ 

// for now, mirror class numbers

const InterfaceNumber MAX_ROOT_SCHEMA_INTERFACE_NUM	= 768;
const InterfaceNumber MAX_ROOT_AND_JADE_INTERFACE_NUM= 1200;
const InterfaceNumber MAX_SYS_INTERFACE_NUM			= 1279;
const InterfaceNumber MIN_USER_INTERFACE_NUM		= 1280;
const InterfaceNumber MAX_INTERFACE_NUM				= 20379;

const PackageNumber MIN_USER_PACKAGE_NUM			= 4097;
const PackageNumber MAX_PACKAGE_NUM					= 32000;

const unsigned MAX_LOCALE_FORMATS					= 65535;
const unsigned MAX_TRANSLATABLE_STRINGS				= 65535;

// ----- Concrete (non-abstract; metaschema class numbers ----------------------- 
// 
// These are all the concrete classes that define the metaschema.  All of these 
// classes are defined in bootstrp.scm, and all have the boolean attribute 
// _systemBasic (which identifies whether or not a specific instance was created 
// by the bootstrap schema;. 

const ClassNumber DSKSCHEMA                        	= 1;
const ClassNumber DSKCLASS                         	= 2;
const ClassNumber DSKCOLLCLASS                     	= 3;
const ClassNumber DSKEXCEPTIONCLASS                	= 4;
const ClassNumber DSKGUICLASS                      	= 5;
const ClassNumber DSKPRIMTYPE                      	= 6;
const ClassNumber DSKPSEUDOTYPE                    	= 7;
const ClassNumber DSKJADEINTERFACE                 	= 8;
const ClassNumber DSKJADEINTERFACEMETHOD           	= 9;
const ClassNumber DSKFEATURE                       	= 10;
const ClassNumber DSKCOMPATTRIBUTE                 	= 11;
const ClassNumber DSKPRIMATTRIBUTE                 	= 12;
const ClassNumber DSKIMPLICITINVERSEREF            	= 13;
const ClassNumber DSKEXPLICITINVERSEREF            	= 14;
const ClassNumber DSKACTIVEXFEATURE                	= 15;
const ClassNumber DSKACTIVEXCLASS                  	= 16;
const ClassNumber DSKCONSTANT                      	= 17;
const ClassNumber DSKGLOBALCONSTANT                	= 18;
const ClassNumber DSKTRANSLATABLESTRING            	= 19;
// class number free for use              			  20
const ClassNumber DSKFUNCTION                      	= 21;
const ClassNumber DSKPATHEXPRESSION                	= 22;
const ClassNumber DSKJADEMETHOD                    	= 23;
const ClassNumber DSKEXTERNALMETHOD                	= 24;
const ClassNumber DSKLOCKPOLICY                    	= 25;
const ClassNumber DSKDBCLASSMAP                    	= 26;
const ClassNumber DSKDBFILE                        	= 27;
const ClassNumber DSKJADELOCALVAR                  	= 28;
const ClassNumber DSKINLINETYPEUSAGE               	= 29;
const ClassNumber DSKFEATUREUSAGE                  	= 30;
const ClassNumber DSKPARAMETER                     	= 31;
const ClassNumber DSKRETURNTYPE                    	= 32;
const ClassNumber DSKEXTERNALKEY                   	= 33;
const ClassNumber DSKMEMBERKEY                     	= 34;
const ClassNumber DSKINVERSE                       	= 35;
const ClassNumber DSKLIBRARY                       	= 36;
const ClassNumber DSKDATABASE                      	= 37;
const ClassNumber DSKDBSERVER                      	= 38;
const ClassNumber DSKCONSTANTCATEGORY              	= 39;
const ClassNumber DSKSCHEMAVIEW                    	= 40;
const ClassNumber DSKDELTAINFO                     	= 41;
const ClassNumber DSKUSERPROFILE                   	= 42;
const ClassNumber DSKROOTSCHEMAGLOBAL              	= 43;
const ClassNumber DSKROOTSCHEMAAPP                 	= 44;
const ClassNumber DSKLOCALE                        	= 45;
const ClassNumber DSKLOCALEFORMAT                  	= 46;
const ClassNumber DSKRELATIONSHIP                  	= 47;
const ClassNumber DSKJADEEXPOSEDCLASS              	= 48;
const ClassNumber DSKJADEEXPOSEDLIST               	= 49;
const ClassNumber DSKACTIVEXLIBRARY                	= 50;

// *******************************  N  O  T  E  ********************************* 
// The following number must be updated if the above class numbers exceed it!!    
const ClassNumber MAX_CONCRETE_METASCHEMA_CLASS_NUM = 50;
// ****************************************************************************** 


// ----- Other class numbers ---------------------------------------------------- 

// Abstract metaschema classes 
const ClassNumber DSKOBJECT                        	= 51;
const ClassNumber DSKSCHEMAENTITY                  	= 52;
const ClassNumber DSKTYPE                          	= 53;
const ClassNumber DSKJADEWEBSERVICESCLASS          	= 54;
const ClassNumber DSKJADEWEBSERVICESMETHOD         	= 55;
const ClassNumber DSKPROPERTY                      	= 56;
const ClassNumber DSKATTRIBUTE                     	= 57;
const ClassNumber DSKREFERENCE                     	= 58;
const ClassNumber DSKJADESCHEMAENTITYEXTENSION     	= 59;
const ClassNumber DSKSCRIPT                        	= 60;
const ClassNumber DSKROUTINE                       	= 61;
const ClassNumber DSKMETHOD                        	= 62;
const ClassNumber DSKSCRIPTELEMENT                 	= 63;
const ClassNumber DSKTYPEUSAGE                     	= 64;
const ClassNumber DSKKEY                           	= 65;
const ClassNumber DSKJADEWEBSERVICECONSUMERCLASS   	= 66;
// class number free for use              			  67
const ClassNumber DSKJADEWEBSERVICESOAPHEADERCLASS 	= 68;
const ClassNumber DSKJADEWEBSERVICEPROVIDERCLASS   	= 69;
// Generic collection classes 
const ClassNumber DSKCOLLECTION                    	= 70;
const ClassNumber DSKBTREE                         	= 71;
const ClassNumber DSKSET                           	= 72;
const ClassNumber DSKOBJECTSET                     	= 73;
const ClassNumber DSKDICTIONARY                    	= 74;
const ClassNumber DSKVIRTUALCOLL                   	= 75;
const ClassNumber DSKEXTKEYDICTIONARY              	= 76;
const ClassNumber DSKMEMBERKEYDICTIONARY           	= 77;
const ClassNumber DSKLIST                          	= 78;
const ClassNumber DSKARRAY                         	= 79;
const ClassNumber DSKOBJECTARRAY                   	= 80;
// class number free for use              			  81
const ClassNumber DSKACTIVEXLIBRARYGUIDDICT        	= 82;
const ClassNumber DSKJADEWEBSERVICECLASSCOLL       	= 83;
const ClassNumber DSKJADEWEBSERVICEMETHODSET       	= 84;
// Collection block classes 
const ClassNumber DSKCOLLECTIONBLOCK               	= 85;
const ClassNumber DSKLISTBLOCK                     	= 86;
const ClassNumber DSKBTREEBLOCK                    	= 87;
const ClassNumber DSKDICTBLOCK                     	= 88;
const ClassNumber DSKSETBLOCK                      	= 89;
const ClassNumber DSKJADEDATABLOCK                 	= 90;
const ClassNumber DSKARRAYBLOCK                    	= 91;
const ClassNumber DSKJADERTREEBLOCK                	= 92;
const ClassNumber MAX_COLLBLOCK_CLASS_NUM			= DSKJADERTREEBLOCK;
// class number free for use              			  93 thru 95
// Iterators 
const ClassNumber DSKITERATOR                      	= 96;
const ClassNumber DSKDICTITERATOR                  	= 97;
const ClassNumber DSKSETITERATOR                   	= 98;
const ClassNumber DSKARRAYITERATOR                 	= 99;
const ClassNumber DSKVCOLLITERATOR                 	= 100;
const ClassNumber DSKJADEDYNAMICPROPERTYCLUSTER    	= 101;
const ClassNumber DSKCLUSTER						= DSKJADEDYNAMICPROPERTYCLUSTER;
// class number free for use              			  102 thru 104
// Compiler/intepreter, etc 
const ClassNumber DSKJADEINTERPRETER               	= 105;
const ClassNumber DSKJADECOMPILER                  	= 106;
const ClassNumber DSKJADESCRIPT                    	= 107;
const ClassNumber DSKMETHODCALLDESC                	= 108;
const ClassNumber DSKOBJMETHODCALLDESC             	= 109;
const ClassNumber DSKPRIMMETHODCALLDESC            	= 110;
// Dictionaries 
const ClassNumber DSKSCHEMAENTITYNUMBERDICT        	= 111;
const ClassNumber DSKJADEINTERFACENDICT            	= 112;
const ClassNumber DSKJADEDYNAMICPROPERTYCLUSTERDICT	= 113;
// class number free for use              			  114
const ClassNumber DSKCLASSNDICT                    	= 115;
// class number free for use              			  116
const ClassNumber DSKPROPERTYNDICT                 	= 117;
const ClassNumber DSKMETHODNDICT                   	= 118;
const ClassNumber DSKDBFILENDICT                   	= 119;
const ClassNumber DSKDATABASENDICT                 	= 120;
const ClassNumber DSKDBCLASSMAPDICT                	= 121;
const ClassNumber DSKDBSERVERNDICT                 	= 122;
const ClassNumber DSKPRIMTYPENDICT                 	= 123;
const ClassNumber DSKTYPENDICT                     	= 124;
const ClassNumber DSKPSEUDOTYPENDICT               	= 125;
const ClassNumber DSKCONSTANTNDICT                 	= 126;
const ClassNumber DSKPROPERTYODICT                 	= 127;
const ClassNumber DSKRELATIONSHIPNDICT             	= 128;
const ClassNumber DSKACTIVEXCLASSGUIDDICT          	= 129;
const ClassNumber DSKLIBRARYNDICT                  	= 130;
const ClassNumber DSKLOCALENDICT                   	= 131;
const ClassNumber DSKCONSTCATEGORYNDICT            	= 132;
const ClassNumber DSKSCHEMAVIEWNDICT               	= 133;
const ClassNumber DSKAPPNAMEDICT                   	= 134;
const ClassNumber DSKSCHEMAENTITYNDICT             	= 135;
const ClassNumber DSKFUNCTIONNDICT                 	= 136;
const ClassNumber DSKUSERPROFILENDICT              	= 137;
const ClassNumber DSKJADEEXPOSEDCLASSNDICT         	= 138;
const ClassNumber DSKJADEEXPOSEDLISTNDICT          	= 139;
// Sets 
const ClassNumber DSKFORMSET                       	= 140;
const ClassNumber DSKINVERSESET                    	= 141;
const ClassNumber DSKFEATURESET                    	= 142;
const ClassNumber DSKSCRIPTSET                     	= 143;
const ClassNumber DSKROUTINESET                    	= 144;
const ClassNumber DSKDBCLASSMAPSET                 	= 145;
const ClassNumber DSKREFERENCESET                  	= 146;
const ClassNumber DSKSCHEMAVIEWSET                 	= 147;
const ClassNumber DSKCLASSSET                      	= 148;
const ClassNumber DSKPROPERTYSET                   	= 149;
const ClassNumber DSKTYPESET                       	= 150;
// Arrays
const ClassNumber DSKPARAMETERCOLL                 	= 151;
const ClassNumber DSKKEYCOLL                       	= 152;
const ClassNumber DSKPROPERTYCOLL                  	= 153;
const ClassNumber DSKJADELOCALVARCOLL              	= 154;
const ClassNumber DSKINLINEUSAGECOLL               	= 155;
const ClassNumber DSKFEATUREUSAGECOLL              	= 156;
const ClassNumber DSKCLASSCOLL                     	= 157;
const ClassNumber DSKCONSTANTCOLL                  	= 158;
const ClassNumber DSKMETHODCOLL                    	= 159;
const ClassNumber DSKDELTAINFOARRAY                	= 160;
// class number free for use              			  161 thru 163
// Class/PrimType/PseudoType dictionaries by number 
const ClassNumber DSKCLASSNUMBERDICT               	= 164;
const ClassNumber DSKPRIMTYPENUMBERDICT            	= 165;
const ClassNumber DSKPSEUDOTYPENUMBERDICT          	= 166;
const ClassNumber DSKBYTEARRAY                     	= 167;
const ClassNumber DSKINTEGER64ARRAY                	= 168;
// class number free for use              			  169
const ClassNumber DSKTIMESTAMPINTERVALARRAY        	= 170;
// Exception classes 
const ClassNumber DSKEXCEPTION                     	= 171;
const ClassNumber DSKSYSTEMEXCEPTION               	= 172;
const ClassNumber DSKFATALERROR                    	= 173;
const ClassNumber DSKNORMALEXCEPTION               	= 174;
const ClassNumber DSKFILEEXCEPTION                 	= 175;
const ClassNumber DSKINTEGRITYVIOLATION            	= 176;
const ClassNumber DSKLOCKEXCEPTION                 	= 177;
const ClassNumber DSKUSERINTERFACEEXCEPTION        	= 178;
// class number free for use              			  179
// Application/environmental classes 
const ClassNumber DSKWEBSESSIONSDICT               	= 180;
const ClassNumber DSKNOTIFICATIONEXCEPTION         	= 181;
const ClassNumber DSKDEADLOCKEXCEPTION             	= 182;
const ClassNumber DSKAPPLICATION                   	= 183;
const ClassNumber DSKGLOBAL                        	= 184;
const ClassNumber DSKSYSTEM                        	= 185;
const ClassNumber DSKNODE                          	= 186;
const ClassNumber DSKPROCESS                       	= 187;
const ClassNumber DSKWINDOW                        	= 188;
const ClassNumber DSKFORM                          	= 189;
const ClassNumber DSKPRINTER                       	= 190;
const ClassNumber DSKDEVELOPMENT                   	= 191;
const ClassNumber DSKDEVCONTROLCLASS               	= 192;
const ClassNumber DSKNODEDICT                      	= 193;
const ClassNumber DSKPROCESSDICT                   	= 194;
const ClassNumber DSKLOCK                          	= 195;
const ClassNumber DSKNOTIFICATION                  	= 196;
const ClassNumber DSKLOCKARRAY                     	= 197;
const ClassNumber DSKNOTIFICATIONARRAY             	= 198;
const ClassNumber DSKLOCALEFULLINFO                	= 199;
const ClassNumber DSKLOCALENAMEINFO                	= 200;
// class number free for use              			  201 thru 202
const ClassNumber DSKWEBSESSION                    	= 203;
const ClassNumber DSKWEBSESSIONMANAGER             	= 204;
const ClassNumber DSKCONNECTION                    	= 205;
const ClassNumber DSKNAMEDPIPE                     	= 206;
const ClassNumber DSKINTERNETPIPE                  	= 207;
// External Database Schema classes 
const ClassNumber DSKEXTERNALDATABASE              	= 208;
const ClassNumber DSKEXTERNALCLASS                 	= 209;
const ClassNumber DSKEXTERNALCOLLCLASS             	= 210;
const ClassNumber DSKEXTERNALREFERENCE             	= 211;
const ClassNumber DSKEXTERNALPRIMATTRIBUTE         	= 212;
const ClassNumber DSKEXTERNALSCHEMAMAP             	= 213;
const ClassNumber DSKEXTERNALDATABASEBYNAMEDICT    	= 214;
const ClassNumber DSKRELATIONALATTRIBUTE           	= 215;
const ClassNumber DSKRELATIONALTABLE               	= 216;
const ClassNumber DSKRELATIONALVIEW                	= 217;
const ClassNumber DSKRELATIONALVIEWDICT            	= 218;
const ClassNumber DSKRELATIONALATTRIBUTESET        	= 219;
const ClassNumber DSKRELATIONALTABLESET            	= 220;
// conditions, paths and lock policies 
const ClassNumber DSKREFERENCEPROPERTYSET          	= 221;
const ClassNumber DSKPATHEXPRESSIONNDICT           	= 222;
const ClassNumber DSKLOCKPOLICYNDICT               	= 223;
// Added for Jade HTML support 
const ClassNumber DSKJADEHTMLDOCUMENT              	= 224;
const ClassNumber DSKJADEHTMLDOCUMENTDICT          	= 225;
const ClassNumber DSKHTMLCLASS                     	= 226;
const ClassNumber DSKKEYUSAGE                      	= 227;
const ClassNumber DSKKEYUSAGECOLL                  	= 228;
// Added for Java Exposure 
const ClassNumber DSKJADEEXPOSEDFEATURE            	= 229;
const ClassNumber DSKJADEEXPOSEDFEATURENDICT       	= 230;
// Move 231 to 1262 as not required for bootstrap
// class number free for use              			  232 thru 244
// Dual user/system collections - see jomoid.hpp (isSystemOnlyCollection and isUserOnlyCollection)
const ClassNumber MIN_USER_ONLY_COLL				= 245;
const ClassNumber DSKKEYUSAGESET                   	= 245;
const ClassNumber DSKFEATUREUSAGESET               	= 246;
const ClassNumber DSKMEMBERKEYSET                  	= 247;
const ClassNumber DSKCONSTANTSET                   	= 248;
const ClassNumber DSKMETHODSET                     	= 249;
const ClassNumber DSKCOLLCLASSSET                  	= 250;
const ClassNumber DSKUSERPROPERTYSET               	= 251;
const ClassNumber DSKEXTERNALKEYSET                	= 252;
const ClassNumber DSKTYPEUSAGESET                  	= 253;
const ClassNumber DSKUSERDBCLASSMAPSET             	= 254;
const ClassNumber DSKSCHEMANDICT                   	= 255;
const ClassNumber DSKUSERTYPESET                   	= 256;
const ClassNumber DSKENTRYPOINTDICT                	= 257;
const ClassNumber DSKJADEEXPOSEDCLASSSET           	= 258;
const ClassNumber DSKSCHEMANUMBERDICT              	= 259;
const ClassNumber DSKJADEEVENTMETHODUSAGEDICT      	= 260;
const ClassNumber DSKJADEEXPOSEDFEATURESET         	= 261;
const ClassNumber MAX_USER_ONLY_COLL				= 261;
const ClassNumber MIN_SYS_ONLY_COLL					= 262;
const ClassNumber DSKSYSJADEEXPOSEDFEATURESET      	= 262;
const ClassNumber DSKSYSKEYUSAGESET                	= 263;
const ClassNumber DSKSYSFEATUREUSAGESET            	= 264;
const ClassNumber DSKSYSMEMBERKEYSET               	= 265;
const ClassNumber DSKSYSCONSTANTSET                	= 266;
const ClassNumber DSKSYSMETHODSET                  	= 267;
const ClassNumber DSKSYSCOLLCLASSSET               	= 268;
const ClassNumber DSKSYSPROPERTYSET                	= 269;
const ClassNumber DSKSYSEXTERNALKEYSET             	= 270;
const ClassNumber DSKSYSTYPEUSAGESET               	= 271;
const ClassNumber DSKSYSDBCLASSMAPSET              	= 272;
const ClassNumber DSKSYSSCHEMANDICT                	= 273;
const ClassNumber DSKSYSTYPESET                    	= 274;
const ClassNumber DSKSYSJADEEXPOSEDCLASSSET        	= 275;
const ClassNumber DSKSYSENTRYPOINTDICT             	= 276;
const ClassNumber DSKSYSSCHEMANUMBERDICT           	= 277;
const ClassNumber DSKSYSJADEEVENTMETHODUSAGEDICT   	= 278;
const ClassNumber MAX_SYS_ONLY_COLL					= 278;

// *******************************  N  O  T  E  ********************************* 
// The following number must be updated to match the highest class number above!  
const ClassNumber MAX_HARDCODED_SCHEMA_CLASSNO		= 278;
// ****************************************************************************** 

// Root Schema classes that may have persistent user instances (remap by adding USER_REMAP_OFFSET) 
const ClassNumber DSKJADECOLLECTIONOPERATION       	= 279;
const ClassNumber DSKINTERNALPSEUDOARRAYBOOLEAN    	= 280;
const ClassNumber DSKINTERNALPSEUDOARRAYINTEGER    	= 281;
const ClassNumber DSKINTERNALPSEUDOARRAYOBJECT     	= 282;
const ClassNumber DSKINTERNALPSEUDOARRAYSTRING     	= 283;
const ClassNumber DSKINTERNALPSEUDOARRAYPICTURE    	= 284;
const ClassNumber DSKCMDIALOG                      	= 285;
const ClassNumber DSKCMDCOLOR                      	= 286;
const ClassNumber DSKCMDFILEOPEN                   	= 287;
const ClassNumber DSKCMDFILESAVE                   	= 288;
const ClassNumber DSKCMDFONT                       	= 289;
const ClassNumber DSKCMDPRINT                      	= 290;
const ClassNumber DSKOLEBLOCK                      	= 291;
const ClassNumber DSKOLEOBJECT                     	= 292;
const ClassNumber DSKOLEARRAY                      	= 293;
const ClassNumber DSKFILENODE                      	= 294;
const ClassNumber DSKFILE                          	= 295;
const ClassNumber DSKFILEFOLDER                    	= 296;
const ClassNumber DSKSORTACTOR                     	= 297;
const ClassNumber DSKCONNECTIONEXCEPTION           	= 298;
const ClassNumber DSKSTRINGUTF8ARRAY               	= 299;
const ClassNumber DSKMULTIMEDIATYPE                	= 300;
const ClassNumber DSKSOUND                         	= 301;
const ClassNumber DSKRECTANGLE                     	= 302;
const ClassNumber DSKRECTANGLEARRAY                	= 303;
const ClassNumber DSKCONTROLORDLIST                	= 304;
const ClassNumber DSKCONTROLPROPNAMEDICT           	= 305;
const ClassNumber DSKCONTROLLOGICSET               	= 306;
// class number free for use              			  307 was DSKJADEDDXLOAD
const ClassNumber DSKFORMORDLIST                   	= 308;
const ClassNumber DSKMENUORDLIST                   	= 309;
const ClassNumber DSKSTRINGARRAY                   	= 310;
const ClassNumber DSKDATEARRAY                     	= 311;
const ClassNumber DSKTIMEARRAY                     	= 312;
const ClassNumber DSKREALARRAY                     	= 313;
const ClassNumber DSKINTEGERARRAY                  	= 314;
const ClassNumber DSKBINARYARRAY                   	= 315;
const ClassNumber DSKTIMESTAMPARRAY                	= 316;
const ClassNumber DSKBOOLEANARRAY                  	= 317;
const ClassNumber DSKDECIMALARRAY                  	= 318;
const ClassNumber DSKCHARACTERARRAY                	= 319;
const ClassNumber DSKPOINTARRAY                    	= 320;
const ClassNumber DSKFORMNAMEDICT                  	= 321;
const ClassNumber DSKOBJECTNAMEDICT                	= 322;
const ClassNumber DSKSCHEMACOLL                    	= 323;
const ClassNumber DSKTYPECOLL                      	= 324;
const ClassNumber DSKPROCESSSTACKARRAY             	= 325;
const ClassNumber DSKFEATUREARRAY                  	= 326;
const ClassNumber DSKFILENODEARRAY                 	= 327;
const ClassNumber DSKSORTACTORARRAY                	= 328;
const ClassNumber DSKDATEFORMAT                    	= 329;
const ClassNumber DSKTIMEFORMAT                    	= 330;
const ClassNumber DSKNUMBERFORMAT                  	= 331;
const ClassNumber DSKCURRENCYFORMAT                	= 332;
const ClassNumber DSKJADEMESSAGINGFACTORY          	= 333;
const ClassNumber DSKTCPIPCONNECTION               	= 334;
const ClassNumber DSKODBCEXCEPTION                 	= 335;
const ClassNumber DSKEXTERNALDBCONNECTION          	= 336;
const ClassNumber DSKEXTERNALDBPROFILE             	= 337;
const ClassNumber DSKEXTERNALDBDRIVERINFO          	= 338;
const ClassNumber DSKEXTERNALDBLOCKPROXY           	= 339;
const ClassNumber DSKEXTERNALOBJECT                	= 340;
const ClassNumber DSKEXTERNALSCHEMAENTITY          	= 341;
const ClassNumber DSKEXTERNALCOLUMN                	= 342;
const ClassNumber DSKEXTERNALFOREIGNKEY            	= 343;
const ClassNumber DSKEXTERNALINDEX                 	= 344;
const ClassNumber DSKEXTERNALINDEXKEY              	= 345;
const ClassNumber DSKEXTERNALPARAMETER             	= 346;
const ClassNumber DSKEXTERNALPRIMARYKEY            	= 347;
const ClassNumber DSKEXTERNALSTOREDPROCEDURE       	= 348;
const ClassNumber DSKEXTERNALTABLE                 	= 349;
const ClassNumber DSKEXTERNALCLASSMAP              	= 350;
const ClassNumber DSKEXTERNALCOLLCLASSMAP          	= 351;
const ClassNumber DSKEXTERNALPROPERTYMAP           	= 352;
const ClassNumber DSKEXTERNALATTRIBUTEMAP          	= 353;
const ClassNumber DSKEXTERNALREFERENCEMAP          	= 354;
const ClassNumber DSKEXTERNALSCRIPTELEMENTMAP      	= 355;
const ClassNumber DSKEXTERNALPARAMETERMAP          	= 356;
const ClassNumber DSKEXTERNALRETURNTYPEMAP         	= 357;
const ClassNumber DSKEXTERNALITERATOR              	= 358;
const ClassNumber DSKEXTERNALCOLLECTION            	= 359;
const ClassNumber DSKEXTERNALARRAY                 	= 360;
const ClassNumber DSKEXTERNALDICTIONARY            	= 361;
const ClassNumber DSKEXTERNALSET                   	= 362;
const ClassNumber DSKEXTERNALCOLUMNBYNAMEDICT      	= 363;
const ClassNumber DSKEXTERNALFOREIGNKEYBYNAMEDICT  	= 364;
const ClassNumber DSKEXTERNALINDEXBYNAMEDICT       	= 365;
const ClassNumber DSKEXTERNALTABLEBYNAMEDICT       	= 366;
const ClassNumber DSKEXTERNALSTOREDPROCBYNAMEDICT  	= 367;
const ClassNumber DSKEXTERNALATTRIBUTEMAPSET       	= 368;
const ClassNumber DSKEXTERNALCLASSMAPSET           	= 369;
const ClassNumber DSKEXTERNALCOLLCLASSMAPSET       	= 370;
const ClassNumber DSKEXTERNALFOREIGNKEYSET         	= 371;
const ClassNumber DSKEXTERNALREFERENCEMAPSET       	= 372;
const ClassNumber DSKEXTERNALTABLESET              	= 373;
const ClassNumber DSKEXTERNALCOLUMNARRAY           	= 374;
const ClassNumber DSKEXTERNALFOREIGNKEYARRAY       	= 375;
const ClassNumber DSKEXTERNALINDEXKEYARRAY         	= 376;
const ClassNumber DSKEXTERNALPARAMETERARRAY        	= 377;
const ClassNumber DSKEXTERNALTABLEARRAY            	= 378;
const ClassNumber DSKRELATIONALATTRIBUTEDICT       	= 379;
const ClassNumber DSKRELATIONALTABLEDICT           	= 380;
const ClassNumber DSKJADEDOTNETINVOKEEXCEPTION     	= 381;
const ClassNumber DSKJADEDBFILEPARTITION           	= 382;
const ClassNumber DSKJADEPATCHCONTROLDICT			= 383;	// NOT remapped - have to leave this in for LC 
const ClassNumber DSKDATAHANDLER                   	= 384;
const ClassNumber DSKFORMSLOADER                   	= 385;
const ClassNumber DSKJADEGENERICQUEUEMANAGER       	= 386;
const ClassNumber DSKJADEHTMLGENERATOR             	= 387;
const ClassNumber DSKJADEPATCHVERSION				= 388;	// NOT remapped 
const ClassNumber DSKJADEPATCHVERSIONDETAIL			= 389;	// NOT remapped 
const ClassNumber DSKJADEPATCHVERSIONDETAILDICT    	= 390;
const ClassNumber DSKRACOLLECTIONVALUE             	= 391;
const ClassNumber DSKRAMETHOD                      	= 392;
const ClassNumber DSKRAOID                         	= 393;
const ClassNumber DSKRAPROPERTY                    	= 394;
const ClassNumber DSKRARELATIONINDEX               	= 395;
const ClassNumber DSKRARELATIONKEY                 	= 396;
const ClassNumber DSKRARELATIONOID                 	= 397;
const ClassNumber DSKROOTSCHEMASESSION             	= 398;
const ClassNumber DSKRELATIONALTABLECLASS          	= 399;
const ClassNumber DSKRELATIONALTABLECOLLECTION     	= 400;
const ClassNumber DSKRELATIONALTABLERELATIONSHIP   	= 401;
const ClassNumber DSKRELATIONALTABLEXRELATIONSHIP  	= 402;
const ClassNumber DSKWEBHOTSPOT                    	= 403;
const ClassNumber DSKWEBINSERT                     	= 404;
const ClassNumber DSKWEBJAVAAPPLET                 	= 405;
const ClassNumber DSKTOOLBARPICTURE                	= 406;
const ClassNumber DSKWEBHTML                       	= 407;
const ClassNumber DSKJADEGENERICQUEUE              	= 408;
const ClassNumber DSKJADEDBFILEPARTITIONARRAY      	= 409;
const ClassNumber DSKJADEWINDOWLAYOUT              	= 410;
const ClassNumber DSKJADEWINDOWLAYOUTARRAY         	= 411;
const ClassNumber DSKJADEIFRAMEFORM                	= 412;
const ClassNumber DSKJADEUSERPROFILESHORTCUT       	= 413;
const ClassNumber DSKJADEEVENTMETHODUSAGE          	= 414;
const ClassNumber DSKINSPECTORINFO					= 415;
const ClassNumber DSKJADEVARIABLEARRAYITERATOR		= 416;
const ClassNumber DSKJADEUSERPROFILESHORTCUTBYACTION= 417;
const ClassNumber DSKJADEUSERPROFILESHORTCUTDICT   	= 418;
const ClassNumber DSKJADEPATCHVERSIONDICT			= 419;	// NOT remapped 
// class number free for use              			  420
const ClassNumber DSKPROGRESSDIALOG                	= 421;
const ClassNumber DSKJADEMULTIDIMENSIONALOBJECT    	= 422;
const ClassNumber DSKJADEGEOMETRY                  	= 423;
const ClassNumber DSKOBJECTLONGNAMEDICT            	= 424;
const ClassNumber DSKPROCESSWEBDICTIONARY          	= 425;
const ClassNumber DSKAPPLICATIONARRAY              	= 426;
const ClassNumber DSKPATCHVERSIONDETAILCOLL        	= 427;
const ClassNumber DSKJADEPRINTPREVIEWFIND          	= 428;
const ClassNumber DSKHUGESTRINGARRAY               	= 429;
const ClassNumber DSK_INSPECTORARRAY               	= 430;
const ClassNumber DSKJADEPRINTDATA                 	= 431;
const ClassNumber DSKJADEPRINTDIRECT               	= 432;
const ClassNumber DSKJADEREGION                    	= 433;
const ClassNumber DSKJADERTREEITERATOR             	= 434;
const ClassNumber DSKJADEBACKUPDATABASEDIALOG      	= 435;
const ClassNumber DSKJADERTREE                     	= 436;
const ClassNumber DSKJADEGENERICMESSAGE            	= 437;
const ClassNumber DSKJADEMEMBERKEYRTREE            	= 438;
const ClassNumber DSKJADEEXTERNALKEYRTREE          	= 439;
const ClassNumber DSKDATAHANDLEREXCEPTION          	= 440;
const ClassNumber DSKINTERNALPSEUDOARRAYITERATOR   	= 441;
const ClassNumber DSKJADESCHEMAUSERPROFILEDICT     	= 442;
const ClassNumber DSKJADESPATIALRTREE              	= 443;
const ClassNumber DSKBREAKPOINTSSET                	= 444;
const ClassNumber DSKJADEEDITORACCELKEYSSET        	= 445;
const ClassNumber DSKJADEUSERSLOBCONTAINER         	= 446;
const ClassNumber DSKJADEDYNAMICPRIMATTRIBUTE      	= 447;
const ClassNumber DSKJADEDYNAMICIMPLICITINVERSEREF 	= 448;
const ClassNumber DSKJADEDEBUGGERBREAKPOINT        	= 449;
const ClassNumber DSKJADEEDITORACCELKEYS           	= 450;
const ClassNumber DSKJADEDATABASEADMIN             	= 451;
const ClassNumber DSKJADELOG                       	= 452;
const ClassNumber DSKDBFILEARRAY                   	= 453;
const ClassNumber DSKINTERNALOLEOBJECT             	= 454;
const ClassNumber DSKJADEXAMLCONTROL               	= 455;
const ClassNumber DSKACTIVEXCONTROL                	= 456;
const ClassNumber DSKACTIVEXINTERFACE              	= 457;
const ClassNumber DSKIUNKNOWN                      	= 458;
const ClassNumber DSKIDISPATCH                     	= 459;
const ClassNumber DSKJADEWINDOWSTATE               	= 460;
const ClassNumber DSKJADEWINDOWSTATEBYNAMEDICT     	= 461;
const ClassNumber DSKJADEWINDOWSTATEARRAY          	= 462;
const ClassNumber DSKOBJECTBYOBJECTDICT            	= 463;
const ClassNumber DSKJADEREPORTWRITERMANAGER       	= 464;
const ClassNumber DSKJADEREPORTWRITERREPORT        	= 465;
const ClassNumber DSKOLE_AUTOMATION                	= 466;
const ClassNumber DSKINTERNALOLEBLOCK              	= 467;
const ClassNumber DSKJADESCHEMAUSERPROFILE         	= 468;
const ClassNumber DSKDEFAULTJADEUSERPROFILE        	= 469;
const ClassNumber DSKJADEUSERPROFILE               	= 470;
const ClassNumber DSKHYPERLINKARRAY                	= 471;
const ClassNumber DSKJADEEDITORPROFILE             	= 472;
const ClassNumber DSKJADEKEYMAPPROFILE             	= 473;
const ClassNumber DSKJADEROWCOLUMNDICTIONARY       	= 474;
const ClassNumber DSKJADESLOBCONTAINER             	= 475;
const ClassNumber DSKJADESLOBCONTAINERARRAY        	= 476;
const ClassNumber DSKJADEUSERCLASS                 	= 477;
const ClassNumber DSKROOTFILLER                    	= 478;
const ClassNumber DSKJADEINSERTSCHEMA              	= 479;
const ClassNumber DSK_JADEPROGRESSEVENTDIALOGSTATUS	= 480;
const ClassNumber DSKJADECONTEXT                   	= 481;
const ClassNumber DSKCONTROL                       	= 482;
const ClassNumber DSKMENUITEMDATA                  	= 483;
const ClassNumber DSKMENUITEM                      	= 484;
const ClassNumber DSKDEVCONTROLLOGICTYPES          	= 485;
const ClassNumber DSKDEVCONTROLPROPERTIES          	= 486;
const ClassNumber DSKDEVCONTROLTYPES               	= 487;
const ClassNumber DSKBASECONTROL                   	= 488;
const ClassNumber DSKSCROLLBAR                     	= 489;
const ClassNumber DSKBROWSEBUTTONS                 	= 490;
const ClassNumber DSKBUTTON                        	= 491;
const ClassNumber DSKCHECKBOX                      	= 492;
const ClassNumber DSKCOMBOBOX                      	= 493;
const ClassNumber DSKFOLDER                        	= 494;
const ClassNumber DSKFRAME                         	= 495;
const ClassNumber DSKGROUPBOX                      	= 496;
const ClassNumber DSKHSCROLL                       	= 497;
const ClassNumber DSKLABEL                         	= 498;
const ClassNumber DSKLISTBOX                       	= 499;
const ClassNumber DSKMULTIMEDIA                    	= 500;
const ClassNumber DSKOLECONTROL                    	= 501;
const ClassNumber DSKOCX                           	= 502;
const ClassNumber DSKOPTIONBUTTON                  	= 503;
const ClassNumber DSKPICTURE                       	= 504;
const ClassNumber DSKPROGRESSBAR                   	= 505;
const ClassNumber DSKSHEET                         	= 506;
const ClassNumber DSKSTATUSLINE                    	= 507;
const ClassNumber DSKTABLE                         	= 508;
const ClassNumber DSKTEXTBOX                       	= 509;
const ClassNumber DSKVSCROLL                       	= 510;
const ClassNumber DSKJADEPRINTPAGE                 	= 511;
const ClassNumber DSKJADEREPORT                    	= 512;
const ClassNumber DSKJADEPRINTDATAARRAY            	= 513;
const ClassNumber DSKDYNADICTIONARY                	= 514;
const ClassNumber DSKJADEAPPLICATIONPARAMETERS     	= 515;
const ClassNumber DSKJADEMASK                      	= 516;
const ClassNumber DSKJADEDYNAMICCOMPATTRIBUTE      	= 517;
const ClassNumber DSKACTIVEXATTRIBUTE              	= 518;
const ClassNumber DSKACTIVEXGUICLASS               	= 519;
const ClassNumber DSKJADEAUTOFONT                  	= 520;
const ClassNumber DSKJADEAUTOPICTURE               	= 521;
const ClassNumber DSKIJADEAUTOFONT                 	= 522;
const ClassNumber DSKIJADEAUTOFONTEVENTS           	= 523;
const ClassNumber DSKIJADEAUTOPICTURE              	= 524;
const ClassNumber DSKJADESKIN                      	= 525;
const ClassNumber DSKJADEDYNAMICEXPLICITINVERSEREF 	= 526;
const ClassNumber DSKACTIVEXLIBCOLL                	= 527;
const ClassNumber DSKJADETABLEELEMENT              	= 528;
const ClassNumber DSKJADETABLECELL                 	= 529;
const ClassNumber DSKJADETABLEROW                  	= 530;
const ClassNumber DSKJADETABLECOLUMN               	= 531;
const ClassNumber DSKJADETABLESHEET                	= 532;
const ClassNumber DSKACTIVEXMETHOD                 	= 533;
const ClassNumber DSKACTIVEXCONSTANT               	= 534;
const ClassNumber DSKACTIVEXAUTOMATION             	= 535;
const ClassNumber DSKJADEDOTNETVISUALCOMPONENT     	= 536;
const ClassNumber DSKJADEUSERCOLLCLASS             	= 537;
const ClassNumber DSKJADESSLCONTEXT                	= 538;
const ClassNumber DSKJADE_MICROSOFT_INTERNET_CTRL  	= 539;
const ClassNumber DSKJADE_WEBBROWSER               	= 540;
const ClassNumber DSKACTIVEXINVOKEEXCEPTION        	= 541;
const ClassNumber DSKJADEADHOCINDEXROOT            	= 542;
const ClassNumber DSKJADEREPORTWRITERSECURITY      	= 543;
const ClassNumber DSKJADEHTMLTYPE                  	= 544;
const ClassNumber DSKJADEHTMLATTRIBUTE             	= 545;
const ClassNumber DSKJADEADHOCINDEXDICT            	= 546;
const ClassNumber DSKJADEINTERNETTCPIPCONNECTION   	= 547;
const ClassNumber DSKJADEHTMLATTRIBUTEDICT         	= 548;
const ClassNumber DSKJADE_DWEBBROWSEREVENTS2       	= 549;
const ClassNumber DSKJADEWEBSESSIONEXPIREDID       	= 550;
const ClassNumber DSKJADEHTMLCOMMENT               	= 551;
const ClassNumber DSKJADEHTMLENTITYARRAY           	= 552;
const ClassNumber DSKJADEHTMLSELECTTYPE            	= 553;
const ClassNumber DSKJADEHTMLCLASS                 	= 554;
const ClassNumber DSKJADEHTMLOFFSETDICT            	= 555;
const ClassNumber DSKJADETRANSACTIONTRACE          	= 556;
const ClassNumber DSKJADESKINMAINT                 	= 557;
const ClassNumber DSKJADESKINSELECT                	= 558;
const ClassNumber DSKJADEADHOCINDEXBYNAME          	= 559;
const ClassNumber DSKJADEHTMLTEXT                  	= 560;
const ClassNumber DSKJADEHTMLTYPEARRAY             	= 561;
const ClassNumber DSKJADESKINSCOLL                 	= 562;
const ClassNumber DSKJADEQUERYRESULTITERATOR       	= 563;
const ClassNumber DSKJADEQUERY                     	= 564;
const ClassNumber DSKJADEQUERYRESULT               	= 565;
const ClassNumber DSKJADEQUERYRESULTOBJECT         	= 566;
const ClassNumber DSKJADEWEBSESSIONEXPIREDIDDICT   	= 567;
const ClassNumber DSKJADEX509CERTIFICATE           	= 568;
const ClassNumber DSKJADEHTMLENTITYNAMEDICT        	= 569;
const ClassNumber DSKJADEHTMLNAMEDICT              	= 570;
const ClassNumber DSKJADEADHOCINDEXBYMEMBERSHIP    	= 571;
const ClassNumber DSKJADESERIALPORT                	= 572;
const ClassNumber DSKJADETCPIPPROXY                	= 573;
const ClassNumber DSKJADEPATCHCONTROLINTERFACE     	= 574;
const ClassNumber DSKJADESLOBCONTAINERDICT         	= 575;
const ClassNumber DSKJADEDOCKBASE                  	= 576;
const ClassNumber DSKJADEDOCKBAR                   	= 577;
const ClassNumber DSKJADEDOCKCONTAINER             	= 578;
const ClassNumber DSKJADEPROFILER                  	= 579;
const ClassNumber DSKJADEEDITMASK                  	= 580;
const ClassNumber DSKSHAREDMEMORYCONNECTION        	= 581;
const ClassNumber DSKJADEDYNAMICOBJECT             	= 582;
const ClassNumber DSKJADEADHOCINDEX                	= 583;
const ClassNumber DSKJADEDYNAMICOBJECTARRAY        	= 584;
const ClassNumber DSKJADEPACKAGE                   	= 585;
const ClassNumber DSKJADEEXPORTEDPACKAGE           	= 586;
const ClassNumber DSKJADEIMPORTEDPACKAGE           	= 587;
const ClassNumber DSKJADEEXPORTEDFEATURE           	= 588;
const ClassNumber DSKJADEEXPORTEDMETHOD            	= 589;
const ClassNumber DSKJADEEXPORTEDPROPERTY          	= 590;
const ClassNumber DSKJADEEXPORTEDCONSTANT          	= 591;
const ClassNumber DSKJADEIMPORTEDFEATURE           	= 592;
const ClassNumber DSKJADEIMPORTEDMETHOD            	= 593;
const ClassNumber DSKJADEIMPORTEDPROPERTY          	= 594;
const ClassNumber DSKJADEIMPORTEDCONSTANT          	= 595;
const ClassNumber DSKJADEEXPORTEDENTITY            	= 596;
const ClassNumber DSKJADEEXPORTEDTYPE              	= 597;
const ClassNumber DSKJADEEXPORTEDCLASS             	= 598;
const ClassNumber DSKJADEIMPORTEDCLASS             	= 599;
const ClassNumber DSKJADEEXPORTEDINTERFACE         	= 600;
const ClassNumber DSKJADEIMPORTEDINTERFACE         	= 601;
const ClassNumber DSKJADEEXPORTEDPACKAGENDICT      	= 602;
const ClassNumber DSKJADEIMPORTEDPACKAGENDICT      	= 603;
const ClassNumber DSKJADEEXPORTEDCLASSNDICT        	= 604;
const ClassNumber DSKJADEIMPORTEDCLASSNDICT        	= 605;
const ClassNumber DSKJADEIMPORTEDCLASSNUMBERDICT   	= 606;
const ClassNumber DSKJADEEXPORTEDMETHODNDICT       	= 607;
const ClassNumber DSKJADEEXPORTEDPROPERTYNDICT     	= 608;
const ClassNumber DSKJADEEXPORTEDCONSTANTNDICT     	= 609;
const ClassNumber DSKJADEIMPORTEDMETHODNDICT       	= 610;
const ClassNumber DSKJADEIMPORTEDPROPERTYNDICT     	= 611;
const ClassNumber DSKJADEIMPORTEDCONSTANTNDICT     	= 612;
const ClassNumber DSKJADEEXPORTEDINTERFACENDICT    	= 613;
const ClassNumber DSKJADEIMPORTEDINTERFACENDICT    	= 614;
const ClassNumber DSKJADEIMPORTEDPACKAGESET        	= 615;
const ClassNumber DSKJADEEXPORTEDCLASSSET          	= 616;
const ClassNumber DSKJADEIMPORTEDCLASSSET          	= 617;
const ClassNumber DSKJADEEXPORTEDMETHODSET         	= 618;
const ClassNumber DSKJADEEXPORTEDPROPERTYSET       	= 619;
const ClassNumber DSKJADEEXPORTEDCONSTANTSET       	= 620;
const ClassNumber DSKJADEIMPORTEDMETHODSET         	= 621;
const ClassNumber DSKJADEIMPORTEDPROPERTYSET       	= 622;
const ClassNumber DSKJADEIMPORTEDCONSTANTSET       	= 623;
const ClassNumber DSKJADEEXPORTEDINTERFACESET      	= 624;
const ClassNumber DSKJADEIMPORTEDINTERFACESET      	= 625;
const ClassNumber DSKJADEIMPORTEDCONSTANTCOLL      	= 626;
const ClassNumber DSKJADEREORGRESTARTSTATE         	= 627;
const ClassNumber DSKJADESKINJADEMASK              	= 628;
const ClassNumber DSKJADEADHOCINDEXDIALOG          	= 629;
const ClassNumber DSKJADESKINLABEL                 	= 630;
const ClassNumber DSKJADESKINLISTBOX               	= 631;
const ClassNumber DSKJADESKINOLECONTROL            	= 632;
const ClassNumber DSKJADESKINOPTIONBUTTON          	= 633;
const ClassNumber DSKJADEADHOCINDEXBROWSER         	= 634;
const ClassNumber DSKJADEADHOCINDEXCONTROLLER      	= 635;
const ClassNumber DSKJADESKINPICTURE               	= 636;
const ClassNumber DSKJADESKINSCROLLBAR             	= 637;
const ClassNumber DSKJADESKINHSCROLL               	= 638;
const ClassNumber DSKJADESKINVSCROLL               	= 639;
const ClassNumber DSKJADESKINSHEET                 	= 640;
const ClassNumber DSKJADESKINSTATUSLINE            	= 641;
const ClassNumber DSKJADESKINTABLE                 	= 642;
const ClassNumber DSKJADESKINTEXTBOX               	= 643;
const ClassNumber DSKJADESKINFORM                  	= 644;
const ClassNumber DSKJADESKINWINDOWSTATEIMAGE      	= 645;
const ClassNumber DSKJADESKINCATEGORY              	= 646;
const ClassNumber DSKJADESKINMENU                  	= 647;
const ClassNumber DSKJADESKINSIMPLEBUTTON          	= 648;
const ClassNumber DSKJADESKINROOT                  	= 649;
const ClassNumber DSKJADESKINMAINTENANCE           	= 650;
const ClassNumber DSKJADEADHOCINDEXWORKER          	= 651;
const ClassNumber DSKJADEADHOCINDEXKEY             	= 652;
const ClassNumber DSKJADESKINSELECTION             	= 653;
const ClassNumber DSKJADEADHOCINDEXBYCLASSNUMBER   	= 654;
const ClassNumber DSKJADEMETHODCONTEXT             	= 655;
const ClassNumber DSKJADELOADER                    	= 656;
const ClassNumber DSKJADEDEVSECURITYINTERFACE      	= 657;
const ClassNumber DSKJADERICHTEXT                  	= 658;
const ClassNumber DSKJADESKINAPPLICATIONNAMEDICT   	= 659;
const ClassNumber DSKJADESKINCATEGORYNAMEDICT      	= 660;
const ClassNumber DSKJADESKINCONTROLNAMEDICT       	= 661;
const ClassNumber DSKJADESKINENTITYNAMEDICT        	= 662;
const ClassNumber DSKJADESKINFORMNAMEDICT          	= 663;
const ClassNumber DSKJADESKINMENUNAMEDICT          	= 664;
const ClassNumber DSKJADESKINSIMPLEBUTTONNAMEDICT  	= 665;
const ClassNumber DSKJADESKINWINDOWSTATENAMEDICT   	= 666;
const ClassNumber DSKJADERESTSERVICE               	= 667;
const ClassNumber DSKJADEQUEUE                     	= 668;
const ClassNumber DSKJADEWEBQUEUE                  	= 669;
const ClassNumber DSKJADEQUEUEMESSAGE              	= 670;
const ClassNumber DSKJADEWEBMESSAGE                	= 671;
const ClassNumber DSKJADESCHEMAENTITYVIEW          	= 672;
const ClassNumber DSKJADESCHEMAENTITYVIEWSET       	= 673;
const ClassNumber DSKJADESCHEMAENTITYVIEWNDICT     	= 674;
const ClassNumber DSKJADESCHEMAENTITYSET           	= 675;
const ClassNumber DSKJADELICENCEINFO               	= 676;
const ClassNumber DSKJADEFORMSDUMPER               	= 677;
const ClassNumber DSKJADECONNECTIONSET             	= 678;
const ClassNumber DSKCONTROLABOUTBOX               	= 679;
const ClassNumber DSKJADEADHOCINDEXOPERATION       	= 680;
const ClassNumber DSKJADEWEBSERVICE                	= 681;
const ClassNumber DSKJADEWSDLGENERATOR             	= 682;
const ClassNumber DSKJADEWSDLIMPORTER              	= 683;
const ClassNumber DSKJADESKINENTITY                	= 684;
const ClassNumber DSKJADESKINAPPLICATION           	= 685;
const ClassNumber DSKJADESKINAREA                  	= 686;
const ClassNumber DSKJADESKINWINDOW                	= 687;
const ClassNumber DSKJADESKINCONTROL               	= 688;
const ClassNumber DSKJADESKINBASECONTROL           	= 689;
const ClassNumber DSKJADESKINBROWSEBUTTONS         	= 690;
const ClassNumber DSKJADESKINBUTTON                	= 691;
const ClassNumber DSKJADESKINCHECKBOX              	= 692;
const ClassNumber DSKJADESKINCOMBOBOX              	= 693;
const ClassNumber DSKJADESKINFOLDER                	= 694;
const ClassNumber DSKJADESKINFRAME                 	= 695;
const ClassNumber DSKJADESKINGROUPBOX              	= 696;
const ClassNumber DSKJADESKINJADEDOCKBASE          	= 697;
const ClassNumber DSKJADESKINJADEDOCKBAR           	= 698;
const ClassNumber DSKJADESKINJADEDOCKCONTAINER     	= 699;
const ClassNumber DSKJADESKINJADEEDITMASK          	= 700;
const ClassNumber DSKJADEWEBSERVICEPROVIDER        	= 701;
const ClassNumber DSKJADEWEBSERVICECOLL            	= 702;
const ClassNumber DSKJADEXMLEXCEPTION              	= 703;
const ClassNumber DSKJADEXMLPARSER                 	= 704;
const ClassNumber DSKJADEXMLNODE                   	= 705;
const ClassNumber DSKJADEXMLDOCUMENT               	= 706;
const ClassNumber DSKJADEXMLDOCUMENTTYPE           	= 707;
const ClassNumber DSKJADEXMLPROCESSINGINSTRUCTION  	= 708;
const ClassNumber DSKJADEXMLELEMENT                	= 709;
const ClassNumber DSKJADEXMLCHARACTERDATA          	= 710;
const ClassNumber DSKJADEXMLTEXT                   	= 711;
const ClassNumber DSKJADEXMLCDATA                  	= 712;
const ClassNumber DSKJADEXMLCOMMENT                	= 713;
const ClassNumber DSKJADEXMLATTRIBUTE              	= 714;
const ClassNumber DSKJADEXMLNODEARRAY              	= 715;
const ClassNumber DSKJADEXMLATTRIBUTEARRAY         	= 716;
const ClassNumber DSKJADEWEBSOCKETDICTIONARY       	= 717;
const ClassNumber DSKJADESKINPROGRESSBAR           	= 718;
const ClassNumber DSKJADEXMLDOCUMENTPARSER         	= 719;
const ClassNumber DSKJADEMETADATAANALYZER          	= 720;
const ClassNumber DSKJADESKINJADERICHTEXT          	= 721;
const ClassNumber DSKJADEWEBSERVICECONSUMER        	= 722;
const ClassNumber DSKJADEWEBSERVICESOAPHEADER      	= 723;
const ClassNumber DSKJADEXMLELEMENTARRAY           	= 724;
const ClassNumber DSKJADEWEBSERVICESCLASSEXTENSION 	= 725;
const ClassNumber DSKJADEWEBSERVICEEXPOSUREPROPERTY	= 726;
const ClassNumber DSKJADESESSIONHEADER             	= 727;
const ClassNumber DSKJADEWEBSERVICEEXPOSURECLASS   	= 728;
const ClassNumber DSKJADEWEBSERVICEEXPOSUREPROPDICT	= 729;
const ClassNumber DSKJADEWEBSERVICEEXPOSURECLSDICT 	= 730;
const ClassNumber DSKJADEXMLNODESET                	= 731;
const ClassNumber DSKJADEHTTPCONNECTION            	= 732;
const ClassNumber DSKJADEWEBSERVICEMANAGER         	= 733;
const ClassNumber DSKVERSIONINFO                   	= 734;
const ClassNumber DSKBRANCHINFO                    	= 735;
const ClassNumber DSKAPPLICATIONCONTEXT            	= 736;
const ClassNumber DSKJADEWEBSERVICESTATISTICS      	= 737;
const ClassNumber DSKJADESOAPEXCEPTION             	= 738;
const ClassNumber DSKJADEWEBSERVICESHOWSTATS       	= 739;
const ClassNumber DSKJADEIDENTIFIERARRAY           	= 740;
const ClassNumber DSKJADEAUDITACCESS               	= 741;
const ClassNumber DSKJADEWEBSERVICEEXPOSUREPROPCOLL	= 742;
const ClassNumber DSKJADETEXTEDIT                  	= 743;
const ClassNumber DSKJADEEDITOR                    	= 744;
const ClassNumber DSKJADEAACLASS                   	= 745;
const ClassNumber DSKJADEINTERFACECOLL             	= 746;
const ClassNumber DSKJADELONGSTRINGARRAY           	= 747;
const ClassNumber DSKJADEXMLELEMENTDICT            	= 748;
const ClassNumber DSKJADEADHOCINDEXAUDITENTRY      	= 749;
const ClassNumber DSKRARPSPROPERTY                 	= 750;
const ClassNumber DSKJADEMULTIWORKERTCPTRANSPORT   	= 751;
const ClassNumber DSKJADEMULTIWORKERTCPCONNECTION  	= 752;
const ClassNumber DSKJADEWEBAPPEXTENSION           	= 753;
const ClassNumber DSKJADEHTMLATTRIBUTEOFFSETDICT   	= 754;
const ClassNumber DSKEXTERNALRPSCLASSMAP           	= 755;
const ClassNumber DSKEXTERNALRPSCLASSMAPSET        	= 756;
const ClassNumber DSKRAPARAMETER                   	= 757;
const ClassNumber DSKRELATIONALTABLECOLLECTIONMETH 	= 758;
const ClassNumber DSKJADEBYTESPROXY                	= 759;
const ClassNumber DSKJADEBYTES                     	= 760;
const ClassNumber DSKJADEENCRYPTEDSCRIPTEXTENSION  	= 761;
const ClassNumber DSKJADEADHOCINDEXCHASEINFO       	= 762;
const ClassNumber DSKJADELASTPATCHDETAILDICT       	= 763;
const ClassNumber DSKJADESOAPPARSER                	= 764;
const ClassNumber DSKJADEADHOCINDEXKEYSBYCLASSANDPROPERTYNUMBER	= 765;
const ClassNumber DSKJADEJSON                      	= 766;
const ClassNumber DSKINTERNALPSEUDOARRAYCONTROL    	= 767;
const ClassNumber DSKLOCKCONTENTIONINFO            	= 768;
const ClassNumber DSKJADEDOTNETTYPE                	= 769;
const ClassNumber DSKJADEMESSAGINGEXCEPTION        	= 770;
const ClassNumber DSKJADEWEBSERVICEUNKNOWNHDRARRAY 	= 771;
const ClassNumber DSKJADEWEBSERVICEUNKNOWNHEADER   	= 772;
const ClassNumber DSKJADELOGICALCERTIFIER          	= 773;
const ClassNumber DSKJADEUPGRADEADMIN              	= 774;
const ClassNumber DSKJADEODBCSERVER                	= 775;
const ClassNumber DSKJADEAACLASSBYNAMEDICT         	= 776;
const ClassNumber DSKJADEAACLASSDICT               	= 777;
const ClassNumber DSKINTERNALPSEUDOARRAYMENUITEM   	= 778;
const ClassNumber DSKJADECONTROLPARENTINFO         	= 779;
const ClassNumber DSKSETMERGEITERATOR              	= 780;
const ClassNumber DSKJADESOLUTIONMODEL             	= 781;
const ClassNumber DSKJADESOLUTIONMODELENTITY       	= 782;
const ClassNumber DSKJADESOURCEPARCEL              	= 783;
const ClassNumber DSKJADEFILEARTIFACT              	= 784;
const ClassNumber DSKJADESOLUTIONFILEARTIFACT      	= 785;
const ClassNumber DSKJADEPROJECTFILEARTIFACT       	= 786;
const ClassNumber DSKJADESOURCEFILEARTIFACT        	= 787;
const ClassNumber DSKJADESOURCEFOLDERARTIFACT      	= 788;
const ClassNumber DSKJADESCHEMAPROJECT             	= 789;
const ClassNumber DSKJADESOLUTIONMODELBUILDER      	= 790;
const ClassNumber DSKJADESOLUTIONMODELSERVICE      	= 791;
const ClassNumber DSKJADEWEBSOCKET                 	= 792;
const ClassNumber DSKJADEWEBSOCKETMSG              	= 793;
const ClassNumber DSKJADEWEBSOCKETSERVER           	= 794;
const ClassNumber DSKWEBSOCKETEXCEPTION            	= 795;
const ClassNumber DSKEXCEPTIONHANDLERDESC          	= 796;
const ClassNumber DSKMERGEITERATOR                 	= 797;
const ClassNumber DSKJADETESTCASE                  	= 798;
const ClassNumber DSKJADETESTDIALOG                	= 799;
const ClassNumber DSKJADESOLUTIONPROJECT           	= 800;
const ClassNumber DSKJADEPROJECTBYUUIDDICT         	= 801;
const ClassNumber DSKJADESOURCEPARCELBYUUIDDICT    	= 802;
const ClassNumber DSKJADESOURCEFILEARTIFACTARRAY   	= 803;
const ClassNumber DSKJADESOURCEFILEARTIFACTBYUUIDDICT	= 804;
const ClassNumber DSKJADEEVENTPUBLISHER            	= 805;
const ClassNumber DSKJADESOURCEITEMHELPER          	= 806;
const ClassNumber DSKJADETESTRUNNER                	= 807;
const ClassNumber DSKJADEODBCVIEW					= 808;
const ClassNumber DSKJADERPSMAPPING					= 809;
const ClassNumber DSKJADESOURCEPARCELITEMIFSET     	= 810;
const ClassNumber DSKJADECUSTOMPROJECT             	= 811;
const ClassNumber DSKJADESOURCEPARCELHELPER        	= 812;
const ClassNumber DSKJADEVERSIONEDARTIFACT         	= 813;
const ClassNumber DSKJADESOURCEITEMSET             	= 814;
const ClassNumber DSKJADESDSMONITOR                	= 815;
const ClassNumber DSKJADEPROJECTARRAY              	= 816;
const ClassNumber DSKJADEVERSIONEDARTIFACTARRAY    	= 817;
const ClassNumber DSKJADESOURCEFILEGROUPSET        	= 818;
// class number free for use              			  819
const ClassNumber DSKJADESOURCEPARCELARRAY         	= 820;
const ClassNumber DSKJADESOURCEFILEGROUP           	= 821;
const ClassNumber DSKJADESOURCEPARCELSET           	= 822;
const ClassNumber DSKJADESOURCEFILEMAP             	= 823;
const ClassNumber DSKJADESOURCEFILEMAPSET          	= 824;
const ClassNumber DSKOBJECTBYUUIDDICT              	= 825;
const ClassNumber DSKJADETIMEZONEBYYEARDICT			= 826;
const ClassNumber DSKJADECOMPILERMESSAGEDEFN		= 827;
const ClassNumber DSKJADECOMPILERMESSAGEDEFNDICT	= 828;
const ClassNumber DSKJADECOMPILERMESSAGECONFIG		= 829;
// class number free for use              			  830
const ClassNumber DSKJADEPROJECT                   	= 831;
const ClassNumber DSKJADESOLUTION                  	= 832;
// class number free for use              			  833 thru 836
const ClassNumber DSKJADETIMEZONE					= 837;
// class nubmer free for use						  838 thry 839
// Generic Interface classes
const ClassNumber DSKJADEGENERICTYPE				= 840;
// Generic Interfaces spare							  841
const ClassNumber DSKJADEGENERICTYPESET				= 842;
const ClassNumber DSKJADEGENERICARGUMENTARRAY		= 843;
const ClassNumber DSKJADEGENERICTYPEARRAY			= 844;
// Generic Interfaces spare							  845
const ClassNumber DSKJADEINTERFACEENCODINGDICT		= 846;
// Generic Interfaces spare							  847 thru 848

// regex classes
const ClassNumber DSKJADEREGEXLIBRARY              	= 849;
const ClassNumber DSKJADEREGEX                     	= 850;
const ClassNumber DSKJADEREGEXCAPTURE              	= 851;
const ClassNumber DSKJADEREGEXMATCH                	= 852;
const ClassNumber DSKJADEREGEXPATTERN              	= 853;
const ClassNumber DSKJADEREGEXRESULT               	= 854;
const ClassNumber DSKJADEREGEXEXCEPTION            	= 855;

const ClassNumber DSKINTERNALPSEUDOARRAY           	= 856;
const ClassNumber DSKDISPLAYWEBERROR               	= 857;
const ClassNumber DSKPRINTINGDIALOG                	= 858;
// class number free for use              			  859
const ClassNumber DSKJADEPRINTPAGESELECT           	= 860;
const ClassNumber DSKJADEPRINTSELECTEDPAGES        	= 861;
const ClassNumber DSKJADEPRINTPREVIEW              	= 862;
const ClassNumber DSKJADE_IWEBBROWSER2             	= 863;
const ClassNumber DSKJADEHTMLENTITY                	= 864;
const ClassNumber DSKJADERICHTEXTFINDREPLACE       	= 865;
const ClassNumber DSKJADERICHTEXTPOPUPMENU         	= 866;
const ClassNumber DSKJADERICHTEXTPARAGRAPH         	= 867;
// class number free for use              			  868
const ClassNumber DSKJADERICHTEXTINSERTTABLE       	= 869;
const ClassNumber DSKJADEQUERYCONTEXT              	= 870;
const ClassNumber DSKJADEIDENTIFIERMAPPER           = 871;
// class number free for use              			  872
const ClassNumber DSKABOUTINSPECTOR                	= 873;
const ClassNumber DSKCALLSTACKBROWSER              	= 874;
const ClassNumber DSKINSPECTOR                     	= 875;
// class number free for use              			  876 thru 878
const ClassNumber DSKINSPECTORFINDTYPE             	= 879;
const ClassNumber DSKJADEADDPARAMETER              	= 880;
const ClassNumber DSKJADEFOLDERBROWSER             	= 881;
const ClassNumber DSKJADEINSPECTORWORKSPACE        	= 882;
const ClassNumber DSKJADELICENCERESTRICTIONSPLASH  	= 883;
const ClassNumber DSKJADELOGICALCERTIFIERDIALOG    	= 884;
const ClassNumber DSKJADEPARAMETERLIST             	= 885;
const ClassNumber DSKJADEWEBBROWSER                	= 886;
const ClassNumber DSKMULTICONFIRMATIONDIALOG       	= 887;
const ClassNumber DSKOLEINSERT                     	= 888;
const ClassNumber DSKSCHEMAINSPECTOR               	= 889;
const ClassNumber DSKSCHEMAINSPECTORLOGON          	= 890;
const ClassNumber DSKVIEWSUPERSCHEMASDIALOG        	= 891;
const ClassNumber DSKWEBAPPLICATION                	= 892;
const ClassNumber DSKWEBSESSIONIDDIALOG            	= 893;
const ClassNumber DSKJADELOGICALCERTIFIERSETTRANIDDIALOG = 894;
// class number free for use              			  895 thru 899
// Annotations basic classes
const ClassNumber DSKJADEANNOTATIONCLASS			= 900; // subclassOf Class
const ClassNumber DSKJADEANNOTATIONALIASDICT		= 901;
const ClassNumber DSKJADEANNOTATIONTAG				= 902;
const ClassNumber DSKJADEANNOTATIONCONTRACT			= 903;
const ClassNumber DSKJADEANNOTATION					= 904; // abstract, instance of JadeAnnotationClass, also all subclasses
const ClassNumber DSKJADEANNOTATIONTAGARRAY			= 905;
// Annotation spare									  906 thru 907
const ClassNumber DSKJDOITERABLE					= 908;
const ClassNumber DSKJDOITERABLENAME				= 909;
const ClassNumber DSKJDOITERABLEVALUE				= 910;
const ClassNumber DSKJDOITERABLETYPE				= 911;
const ClassNumber DSKJDOITERATOR					= 912;
const ClassNumber DSKJDOITERATORNAME				= 913;
const ClassNumber DSKJDOITERATORVALUE				= 914;
const ClassNumber DSKJDOITERATORTYPE				= 915;
// class number free for use              			  916 thru 1079
// Extended dual collection ranges
const ClassNumber MIN_SYS_ONLY_COLL_EX              = 1080;
const ClassNumber DSKSYSJADEINTERFACESET            = 1080;
// class number free								  1081 thru 1088
const ClassNumber MAX_SYS_ONLY_COLL_EX              = 1089;
const ClassNumber MIN_USER_ONLY_COLL_EX             = 1090;
const ClassNumber DSKJADEINTERFACESET               = 1090;
const ClassNumber MAX_USER_ONLY_COLL_EX             = 1099;
// System Annotations - persistent 
const ClassNumber DSKJADESYSTEMANNOTATION			= 1100; // abstract
const ClassNumber DSKJADEUSAGEANNOTATION			= 1101;
const ClassNumber DSKJADEDEPRECATEDANNOTATION		= 1102;
const ClassNumber DSKJADEDISPLAYNAMEANNOTATION		= 1103;
const ClassNumber DSKJADEVALUESANNOTATION			= 1104;
const ClassNumber DSKJADESERIALIZEANNOTATION		= 1105;
const ClassNumber DSKJADEREQUIREDCLAIMANNOTATION	= 1106; // abstract
const ClassNumber DSKJADEREQUIREDDELEGATECLAIMANNOTATION = 1107;
const ClassNumber DSKJADEREQUIREDONEOFVALUECLAIMANNOTATION = 1108;
const ClassNumber DSKJADEREQUIREDSINGLEVALUECLAIMANNOTATION = 1109;
// class number reserved for annotations   			  1110 thru 1139

const ClassNumber DSKJADETEXTSEARCHCRITERIA			= 1140;

const ClassNumber DSKJADEDDXLOADER					= 1141;
const ClassNumber DSKJADEDDBLOADERBASE              = 1142;
const ClassNumber DSKJADEDDBLOADER                  = 1143;
const ClassNumber DSKJADELOADERRESULTS				= 1144;
const ClassNumber DSKJADECONSOLEBINDINGS            = 1145;
const ClassNumber DSKJADEFORMSLOADER				= 1146;
const ClassNumber DSKJADELOADERWORKINGS             = 1147;
const ClassNumber DSKJADELOADERMODEL                = 1148;
const ClassNumber DSKJADELOADEROPTIONS              = 1149;

const ClassNumber DSKJADESOURCEEXTRACTOR			= 1150;
const ClassNumber DSKJADESOURCEEXTRACTOPTIONS		= 1151;
const ClassNumber DSKJADEEXTRACTORSTREAM			= 1152;

const ClassNumber DSKJADERPSDATAPUMP               	= 1153;
const ClassNumber DSKJADEFORMPRESENTER				= 1154;
const ClassNumber DSKJADEINSPECTTOOLBARPRESENTER	= 1155;
const ClassNumber DSKJADEUSERPREFERENCESPRESENTER	= 1156;
const ClassNumber DSKJADEUSERPREFERENCESSUPPRESSIONPRESENTER = 1157;
const ClassNumber DSKJADEMSGBOXSUPPRESSIBLEPRESENTER = 1158;
// class number free for use						  1159

// JadeWebTokens 
const ClassNumber DSKJADEJWTLIBRARY					= 1160;
const ClassNumber DSKJADEJWKSHANDLERIMPL			= 1161;
const ClassNumber DSKJADEJWTGENERATOR				= 1162;
// JadeJWTLibrary spare								  1163 thru 1166
const ClassNumber DSKJADEJWTMODEL					= 1167; // abstract
const ClassNumber DSKJADEJWKSAUTHPROVIDERRESPONSE	= 1168;
const ClassNumber DSKJADEJWKSHANDLER				= 1169;
const ClassNumber DSKJADEJWTCLAIM					= 1170;
const ClassNumber DSKJADEJWTPARSER					= 1171;
const ClassNumber DSKJADEJWTVALIDATOR				= 1172;
const ClassNumber DSKJADEJSONWEBTOKEN				= 1173;
const ClassNumber DSKJADEJWTCLAIMARRAY				= 1174;
const ClassNumber DSKJADEREQUIREDCLAIMARRAY			= 1175;

// JADE REST Client classes: 1176-1184
const ClassNumber DSKJADERESTCLIENT					= 1176;
const ClassNumber DSKJADERESTREQUEST				= 1177;
const ClassNumber DSKJADERESTRESPONSE				= 1178;
const ClassNumber DSKJADERESTPROXY					= 1179;
const ClassNumber DSKJADERESTDATAMODELPROXY			= 1180;
const ClassNumber DSKJADERESOURCEPROXY				= 1181;
const ClassNumber DSKJADERESTPROXYHOOK				= 1182;
// JADE REST Client spare							  1183
const ClassNumber DSKJADEANYVALUEDICT				= 1184;

// class number free for use              			  1185
const ClassNumber DSKJADELOADERTASK                 = 1186;
const ClassNumber DSKJADELOADERTASKARRAY            = 1187;
const ClassNumber DSKJADELOADERFILETASK             = 1188;
const ClassNumber DSKJADELOADERDELEGATES            = 1189;

const ClassNumber DSKJADETESTMOCK					= 1190;

// PatchHistory	  1191 thru 1209 

const ClassNumber DSKJADEPATCHHISTORY				= 1191;
const ClassNumber DSKJADEPATCHIDENTITY				= 1192;
const ClassNumber DSKJADEPATCHREVISIONBASE			= 1193;         // need flexibility around actual persistence
const ClassNumber DSKJADEPATCHREVISION			    = 1194;
const ClassNumber DSKJADEPATCHRECORD				= 1195;
const ClassNumber DSKJADEPATCHSEARCHPARAMS          = 1196;
const ClassNumber DSKJADEPATCHCONTROLINTERFACE2     = 1197;
const ClassNumber DSKJADEPATCHREVISIONBYDATETIMEUPDATEDDICT = 1198;
const ClassNumber DSKJADEPATCHREVISIONBYDEVELOPERDICT          = 1199;
const ClassNumber DSKJADEPATCHDIFFER                 = 1200;
const ClassNumber DSKJADEPATCHRECORDBYOPENSTATUSPATCHIDDICT = 1201; 
const ClassNumber DSKJADEPATCHREVISIONBYENTITYNAMEHASHMAP   = 1202;
const ClassNumber DSKJADEPATCHRECORDBYDATETIMEOPENEDDICT    = 1203;
const ClassNumber DSKJADEPATCHRECORDBYPATCHNUMDICT		    = 1204;
const ClassNumber DSKJADEPATCHRECORDBYTICKETDICT		    = 1205;
const ClassNumber DSKJADEPATCHREVISIONARRAY				    = 1206;
const ClassNumber DSKJADEPATCHRECORDBYPATCHIDANDSCHEMADICT  = 1207;
const ClassNumber DSKJADEPATCHRESTARTINFO				    = 1208;
const ClassNumber DSKJADEPATCHRECORDARRAY					= 1209;

const ClassNumber DSKJADETHEME								= 1210;
const ClassNumber DSKJADETHEMEINFO							= 1211;
const ClassNumber DSKJADETHEMEDICT							= 1212;
const ClassNumber DSKJADETHEMECATALOG						= 1213;
const ClassNumber DSKJADTHEMECATALOGTEMPLATE				= 1214;

const ClassNumber DSKJADEPATCHMODEL						    = 1215;
const ClassNumber DSKJADEPATCHUSERINFO						= 1216;
const ClassNumber DSKJADEPATCHCONTROLCONFIG					= 1217;
const ClassNumber DSKJADEPATCHHISTORYARRAY 					= 1218;
const ClassNumber DSKJADEPATCHRECORDBYDATEUPDATEDRANGEDICT  = 1219;
const ClassNumber DSKJADEPATCHRECORDBYENTITYNAMEHASHMAP		= 1220;
const ClassNumber DSKJADEPATCHHISTORYMIGRATION				= 1221;
const ClassNumber DSKJADEPATCHHELPER						= 1222;
const ClassNumber DSKJADEPATCHRUNTIMECACHE					= 1223;

/* Patch History reserve upto 1229 */

const ClassNumber DSKJADEMSGBOXSUPPRESSIBLE					= 1230;
const ClassNumber DSKJADESUPPRESSIONFLAGS					= 1231;
const ClassNumber DSKJADESUPPRESSIONINFO					= 1232;

// JADE OpenAPI Generation classes: 1233-1246
const ClassNumber DSKJADEOPENAPI						= 1233;
const ClassNumber DSKJADEOPENAPICOMPONENT				= 1234;
const ClassNumber DSKJADEOPENAPICOMPONENTGENERATOR		= 1235;
const ClassNumber DSKJADEOPENAPICOMPONENTPROPERTY		= 1236;
const ClassNumber DSKJADEOPENAPIDESCRIPTION				= 1237;
const ClassNumber DSKJADEOPENAPIEXTERNALDOCSGENERATOR	= 1238;
const ClassNumber DSKJADEOPENAPIGENERATOR				= 1239;
const ClassNumber DSKJADEOPENAPIINFOGENERATOR			= 1240;
const ClassNumber DSKJADEOPENAPIPARAMETERDESCRIPTION	= 1241;
const ClassNumber DSKJADEOPENAPIPATHDESCRIPTION			= 1242;
const ClassNumber DSKJADEOPENAPIPATHGENERATOR			= 1243;
const ClassNumber DSKJADEOPENAPIRESOURCEDESCRIPTION		= 1244;
const ClassNumber DSKJADEOPENAPISERVERDESCRIPTION		= 1245;
const ClassNumber DSKJADEOPENAPISERVERGENERATOR			= 1246;

// JADE OpenAPI Generation collection classes: 1247-1205

const ClassNumber DSKJADEOPENAPICOMPONENTDICT			= 1247;
const ClassNumber DSKJADEOPENAPICOMPONENTPROPERTYDICT	= 1248;
const ClassNumber DSKJADEOPENAPIPARAMETERDESCRIPTIONDICT = 1249;
const ClassNumber DSKJADEOPENAPIPATHDESCRIPTIONDICT		= 1250;
const ClassNumber DSKJADEOPENAPIRESOURCEDICT			= 1251;
const ClassNumber DSKJADEOPENAPISERVERDESCRIPTIONDICT	= 1252;
//  class number free for use						  1253 thru 1254
const ClassNumber DSKJADEDATATRANSFEROBJECT             = 1255;
const ClassNumber DSKJADESCHEMAMODELDTO                 = 1256;
const ClassNumber DSKJADEDBFILEDTO                      = 1257;
/* Jade DTO reserve upto 1259 */

const ClassNumber DSKJADECOMPILERRESULT					= 1260;
const ClassNumber DSKJADECOMPILERMESSAGEARRAY			= 1261;
const ClassNumber DSKJADECOMPILERMESSAGE				= 1262;
const ClassNumber DSKJADEDEPENDENCYEDGE					= 1263;
const ClassNumber DSKJADEDEPENDENCYGRAPH                = 1264;
const ClassNumber DSKJADESCHEMADEPENDENCYGRAPH          = 1265;
// class number free for use              			  1266 thru 2047
// ----- end of RootSchema class numbers ---------------------------------------- 

// ----- RootSchema Interface numbers ------------------------------------------- 
const InterfaceNumber DSKJADEMULTIWORKERTCPTRANSPORTIF	= 1;
const InterfaceNumber DSKJADEGENERICMESSAGINGIF			= 2;
const InterfaceNumber DSKJADERPSNOTIFICATIONIF			= 3;
const InterfaceNumber DSKJADERPSDATAPUMPIF				= 4;
const InterfaceNumber DSKJADETESTLISTENERIF				= 5;
const InterfaceNumber DSKJADERELATIONALATTRIBUTEIF		= 6;
const InterfaceNumber DSKJADERELATIONALQUERYPROVIDERIF	= 7;
const InterfaceNumber DSKJADERELATIONALENTITYIF			= 8;
const InterfaceNumber DSKJADEDBADMINNOTIFICATIONIF		= 9;
const InterfaceNumber DSKJADESOURCEITEMIF				= 10;
const InterfaceNumber DSKJADESOURCEPARCELITEMIF			= 11;
const InterfaceNumber DSKJADESUPPRESSIONMODELIF			= 12;
const InterfaceNumber DSKJADEUSERPREFERENCESSUPPRESSIONVIEWIF	= 13;
const InterfaceNumber DSKJADEMSGBOXSUPPRESSIBLEVIEWIF	= 14;
const InterfaceNumber DSKJADEANYVALUEDICTIF				= 15;
const InterfaceNumber DSKJADETHEMEMODELIF				= 16;
const InterfaceNumber DSKJADEEXTRACTORWRITEOPIF			= 17;
const InterfaceNumber DSKJADEITERATORIF					= 18;
const InterfaceNumber DSKJADEITERABLEIF					= 19;
const InterfaceNumber DSKJADEREVERSIBLEITERATORIF		= 20;
const InterfaceNumber DSKJADEREVERSIBLEITERABLEIF		= 21;

const InterfaceNumber DSKJADEPATCHIDENTITYIF			= 22;
const InterfaceNumber DSKJADEPATCHENTITYIF				= 23;
const InterfaceNumber DSKJADEPATCHRUNTIMECACHEIF		= 24;
const InterfaceNumber DSKJADEPATCHUSERINFOIF			= 25;
const InterfaceNumber DSKJADEPATCHCONTROLCONFIGIF		= 26;


// ----- JadeSchema class numbers ----------------------------------------------- 
const ClassNumber DSKDOTNETIMPORT					= 1004017;
const ClassNumber DSKDOTNETIMPORTABSTRACT			= 1004018;
const ClassNumber DSKDOTNETIMPORTASSEMBLY			= 1004019;
const ClassNumber DSKDOTNETIMPORTENUMMEMBER			= 1004020;
const ClassNumber DSKDOTNETIMPORTEVENT				= 1004021;
const ClassNumber DSKDOTNETIMPORTMETHOD				= 1004022;
const ClassNumber DSKDOTNETIMPORTPARAMETER			= 1004023;
const ClassNumber DSKDOTNETIMPORTPROPERTY			= 1004024;
const ClassNumber DSKDOTNETIMPORTTYPE				= 1004025;
const ClassNumber DSKDOTNETIMPORTCLASS				= 1004026;
const ClassNumber DSKDOTNETIMPORTENUM				= 1004027;
const ClassNumber DSKDOTNETIMPORTTYPEINFO			= 1004028;

const ClassNumber DSKJADEDEBUGGER					= 1004048;

// ----- end of JadeSchema class numbers ---------------------------------------- 

// ----- Pseudo type numbers ---------------------------------------------------- 
const TypeNum SELFTYPE								= 1;
const TypeNum INSTANCETYPE							= 2;
const TypeNum MEMBERTYPE							= 3;
const TypeNum KEYTYPE								= 4;
const TypeNum PARAMLISTTYPE							= 5;
const TypeNum PROPERTYLISTTYPE						= 6;
const TypeNum PSEUDOMETHODCALLTYPE					= 7;
const TypeNum EXCLUDEDIMPORTEDTYPE					= 8;
	
// ----- Primitive type numbers with historic PFormat compatible values --------- 
// - used by bootstrp compiler

const TypeNum DSKCSTRING_PRIMITIVE					= 1;   // zero terminated string. (C string) 
const TypeNum DSKINTEGER_PRIMITIVE					= 4;
const TypeNum DSKANY_PRIMITIVE						= 5;
const TypeNum DSKCHARACTER_PRIMITIVE				= 6;
const TypeNum DSKBOOLEAN_PRIMITIVE					= 7;
const TypeNum DSKPOINT_PRIMITIVE 					= 8;
const TypeNum DSKBINARY_PRIMITIVE 					= 11;
const TypeNum DSKDATE_PRIMITIVE 					= 16;
const TypeNum DSKTIME_PRIMITIVE 					= 17;
const TypeNum DSKTIMESTAMP_PRIMITIVE 				= 18;
const TypeNum DSKDECIMAL_PRIMITIVE 					= 19;
const TypeNum DSKREAL_PRIMITIVE 					= 21;	
const TypeNum DSKINTEGER64_PRIMITIVE 				= 42;
const TypeNum DSKMEMORYADDRESS_PRIMITIVE 			= 44;
const TypeNum DSKSTRINGUTF8_PRIMITIVE 				= 51;
const TypeNum DSKBYTE_PRIMITIVE 					= 52;
const TypeNum DSKTIMESTAMPINTERVAL_PRIMITIVE		= 53;
const TypeNum DSKTIMESTAMPOFFSET_PRIMITIVE			= 57;

// MAX_SYSTEM_PRIMITIVES must be greater than or equal to the highest primitive type number
const TypeNum MAX_SYSTEM_PRIMITIVES					= DSKTIMESTAMPOFFSET_PRIMITIVE;	// 57 