/****************************************************************************

				P R O P R I E T A R Y   N O T I C E

	This software, in whole and in every part, is proprietary to Jade Software
	Corporation Limited at Christchurch, New Zealand and is not to be
	reproduced, used or disclosed except upon prior written permission of Jade
	Software Corporation Limited.

	COPYRIGHT (c) JADE SOFTWARE CORPORATION LIMITED 2005- ALL RIGHTS RESERVED

****************************************************************************/

/*******************************************************************************
				J O M    D E F I N E S
*******************************************************************************/

#ifndef JOMDEFS_h
#define JOMDEFS_h

#include "jomarch.h"

/* ini file defines*/
#if defined(UNIX)	
const Character JADEINIFILE[]  				= TEXT("jade.ini");
#else	
const Character JADEINIFILE[]  				= TEXT("Jade.ini");
#endif

const Character COMMANDLINE_SECTION[]		= TEXT("JadeCommandLine");
const Character APPSERVER_SECTION[]			= TEXT("JadeAppServer");
const Character AUTOUPDATE_SECTION[]		= TEXT("JadeAutoUpdate");
const Character CLIENTAPPRESTRICTIONS_SECTION[]= TEXT("JadeClientAppRestrictions");
const Character CLIENT_SECTION[] 			= TEXT("JadeClient");
const Character COMPILER_SECTION[]			= TEXT("JadeCompiler");
const Character DISTRIBUTEDTRANSACTIONPROCESSING_SECTION[]= TEXT("JadeDistributedTransactionProcessing");
const Character EXECUTEFLAGS_SECTION[]		= TEXT("JadeExecuteFlags");
const Character EXTRACTSORT_SECTION[]		= TEXT("JadeExtractSort");
const Character FONTSUBSTITUTIONS_SECTION[]	= TEXT("JadeFontSubstitutions");
const Character GENERICMESSAGING_SECTION[]	= TEXT("JadeGenericMessaging");
const Character INTERPRETEROUTPUTVIEWER_SECTION[]= TEXT("JadeInterpreterOutputViewer");
const Character INTERPRETER_SECTION[]		= TEXT("JadeInterpreter");
const Character JADEENVIRON_SECTION[]  		= TEXT("JadeEnvironment");
const Character JAVA_SECTION[]				= TEXT("JadeJava");
const Character LOADER_SECTION[]			= TEXT("JadeLoader");
const Character LOGSERVER_SECTION[]			= TEXT("JadeLogServer");
const Character LOG_SECTION[]				= TEXT("JadeLog");
const Character NETWORK_SECTION[]			= TEXT("JadeNetwork");
const Character ODBC_SECTION[]				= TEXT("JadeOdbc");
const Character PRINTING_SECTION[]			= TEXT("JadePrinting");
const Character PROFILER_SECTION[]			= TEXT("JadeProfiler");
const Character RDBI_SECTION[]				= TEXT("JadeRDBI");
const Character REORG_SECTION[]				= TEXT("JadeReorg");
const Character RPS_SECTION[]				= TEXT("JadeRPS");
const Character SAMPLING_SECTION[]			= TEXT("JadeSampling");
const Character SECURITY_SECTION[]			= TEXT("JadeSecurity");
const Character SERVER_SECTION[]  			= TEXT("JadeServer");
const Character SOUND_SECTION[]				= TEXT("JadeSound");
const Character STATISTICS_SECTION[]		= TEXT("JadeStatistics");
const Character THINCLIENT_SECTION[]		= TEXT("JadeThinClient");

const Character JADEBYTESCONTENTLIMIT_TAG[]	= TEXT("JadeBytesGetContentLimit");
const Character WORKDIRECTORY_TAG[]			= TEXT("JadeWorkDirectory");

const Character DELTADB_SECTION[]			= TEXT("DeltaDb");
const Character FAULTHANDING_SECTION[]		= TEXT("FaultHandling");
const Character JADE_SECTION[]				= TEXT("Jade");
const Character JADCLIENT_SECTION[] 		= TEXT("NonGuiClient");
const Character PERSISTENT_SECTION[]		= TEXT("PersistentDb");
const Character SDS_SECTION[]				= TEXT("SyncDbService");
const Character TRANSIENT_SECTION[]			= TEXT("TransientDb");
const Character TRAPCONTROL_SECTION[]		= TEXT("TrapControl");
const Character SENTINEL_SECTION[]			= TEXT("JadeSentinel");

const Character ENABLESENTINEL_TAG[]		= TEXT("EnableSentinel");
const Character DUMPDIRSELECTOR_TAG[]		= TEXT("ProcessDumpDirectory");
const Character CRASHLOGDIRSELECTOR_TAG[]	= TEXT("CrashLogDirectory");
const Character ENABLEOUTPUTCALLBACK_TAG[]	= TEXT("EnableOutputCallback");
const Character ENABLESYMNOISY_TAG[]		= TEXT("EnableSymNoisy");
const Character DEFAULTDUMPDIR_VALUE[]		= TEXT("ProcessDumps");
const Character CRASHLOGDIR_VALUE[]			= TEXT("CrashLogs");
const bool		ENABLESENTINEL_DEFAULT		= true;

const Character RUN_AS_SERVICE_TAG[]		= TEXT("RunAsService");
const bool	    DEFAULT_RUN_AS_SERVICE		= false;

const Character INI_DEFAULT_TAG[]			= TEXT("<default>");
const Character INI_NONE_TAG[]				= TEXT("<none>");

#ifndef TRUE
#define TRUE  								1
#endif

#ifndef FALSE
#define FALSE 								0
#endif

/* this macro is useful for determining the size of an array of structures, or characters */
#define NUM_ELEMS(b)						(Size(sizeof(b) / sizeof(*(b))))

const Character JADEEXE[]					= TEXT("jade");
const Character JADLOADEXE[]				= TEXT("jadload");
const Character JADLOADBEXE[]				= TEXT("jadloadb");
const Character JADRAPEXE[]					= TEXT("jadrap");
const Character JADSERVEXE[]				= TEXT("jadserv");
const Character JADRAPB[]					= TEXT("jadrapb");
const Character JADCLIENTEXE[]				= TEXT("jadclient");
const Character APPSERVEREXE[]				= TEXT("jadapp");
const Character APPSERVERBEXE[]				= TEXT("jadappb");
const Character JDBUTILBEXE[]				= TEXT("jdbutilb");
const Character JDBUTILEXE[]				= TEXT("jdbutil");
const Character JADREGBEXE[]				= TEXT("jadregb");
const Character JADREGEXE[]					= TEXT("jadreg");
const Character JVERINFOEXE[]				= TEXT("jverinfo");
const Character JDBADMINEXE[]				= TEXT("jdbadmin");
const Character JDBREORGEXE[]				= TEXT("jdbreorg");
const Character JDBCRYPTEXE[]				= TEXT("jdbcrypt");
const Character JOOBDBSERVEREXE[]			= TEXT("JoobDatabaseServer");
const Character JOOBLOADEXE[]				= TEXT("joobload");
const Character JOOBMGMTSERVEREXE[]			= TEXT("JoobManagementServer");
const Character JOOBODBCSERVEREXE[]			= TEXT("JoobOdbcServer");
const Character JOOBREGEXE[]				= TEXT("joobreg");
const Character ODBCINSTEXE[]				= TEXT("odbcinst");

const Character JOMSYSLIB[]					= TEXT("jomsys");;
const Character JOMSUPPLIB[]				= TEXT("jomsupp");
const Character JOMSYSDBLIB[]				= TEXT("jomdb");
const Character JOMREMOTELIB[]				= TEXT("jomsrvr2");
const Character MEMORY_DB[]					= TEXT("jommdb");
const Character JADPMAP[]					= TEXT("jadpmap");
const Character JOMLIB[]					= TEXT("jom");
const Character JADEDITLIB[]				= TEXT("jadedit");
const Character JADPRINTLIB[]				= TEXT("jadprnt");
const Character JOMSECLIB[]					= TEXT("jomsec");
const Character JRPSODBCLIB[]				= TEXT("jrpsodbc");
const Character JADNETLIB[]					= TEXT("jadnet");
const Character JADCNETLIB[]				= TEXT("jadcnet");
const Character JADINETLIB[]				= TEXT("jadinet");
const Character JOMUTILLIB[]				= TEXT("jomutil");
const Character JOMOSLIB[]					= TEXT("jomos");
const Character JADEXPATLIB[]				= TEXT("jadexpat");
#ifdef ROOTSCHEMA_JOOB
const Character JOMSCMLIB[]					= TEXT("joobscm");
#else
const Character JOMSCMLIB[]					= TEXT("jomscm");
#endif
const Character INC_SERVER_LIB[]			= TEXT("jominc");
const Character JOMREORGLIB[]				= TEXT("jomreog");

const Character BOOTCACTLIB[]				= TEXT("bootcact");
const Character JLNCOMPLIB[]				= TEXT("jlncomp");
const Character JLNINTERPLIB[]				= TEXT("jlnintp");
const Character JLNCTABLIB[]				= TEXT("jlnctab");
const Character ACTIVEXLIB[]				= TEXT("jadeactivex");
const Character ACTIVEXTHINLIB[]			= TEXT("jadeactivexthin");
const Character DOTNETTHINLIB[]				= TEXT("jadedotnetthin");
const Character JADEGMLIB[]					= TEXT("jadegm");

const Character ROOT_SCHEMA[]				= TEXT("RootSchema");
const Character JADE_SCHEMA[]				= TEXT("JadeSchema");
const Character JADE_MONITOR_SCHEMA[]		= TEXT("JadeMonitorSchema");
const Character JADE_TOOLS_SCHEMA[]			= TEXT("JadeToolsSchema");
const Character JADE_REPORT_WRITER_SCHEMA[]	= TEXT("JadeReportWriterSchema");
const Character JADE_ATCG_GENERATOR_SCHEMA[]= TEXT("JadeAtcgGeneratorSchema");
const Character JADE_TEST_ROOT_SCHEMA[]		= TEXT("JadeTestRootSchema");
const Character JADE_TEST_JADE_SCHEMA[]		= TEXT("JadeTestJadeSchema");
const Character JADE_TEST_JADE_MONITOR_SCHEMA[] = TEXT("JadeTestJadeMonitorSchema");
const Character JADE_TEST_JADE_TOOLS_SCHEMA[] = TEXT("JadeTestJadeToolsSchema");

const Character ROOT_SCHEMA_APP[]			= TEXT("RootSchemaApp");
const Character JADE_APP[]					= TEXT("Jade");
const Character JADE_PAINTER_APP[]			= TEXT("JadePainter");
const Character JADE_TRANSLATOR_APP[]		= TEXT("JadeTranslator");
const Character JADE_DEBUGGER_APP[]			= TEXT("JadeDebugger");
const Character JADE_REORG_APP[]			= TEXT("JadeReorgApp");
const Character JADE_DBREORG_APP[]			= TEXT("JadeDbReorgApp");
const Character JADE_LOADER_APP[]			= TEXT("JadeLoader");
const Character JADE_LOADER_NON_GUI_APP[]	= TEXT("JadeLoaderNonGui");
const Character JADE_FILE_LOADER_APP[]		= TEXT("JadeFileLoader");
const Character JADE_FILE_LOADER_NON_GUI_APP[]= TEXT("JadeFileLoaderNonGui");
const Character JADE_SCHEMA_LOADER_APP[]	= TEXT("JadeSchemaLoader");
const Character JADE_BATCH_EXTRACT_APP[]	= TEXT("JadeBatchExtract");
const Character JADE_SERVER_INTERNAL_APP[]	= TEXT("JadeServerInternal");
const Character JADE_ASYNCH_WORKER_APP[]	= TEXT("JadeAsynchConnectionWorker");
const Character JADE_PRIMARY_SERVER_APP[]	= TEXT("JadePrimaryServerAgentApp");
const Character JADE_RPS_BACKGROUND_APP[]	= TEXT("JadeRpsBackgroundApp");
const Character JADE_RPS_DATAPUMP[]			= TEXT("JadeRpsDataPump");
const Character JADE_RPS_DATA_LOAD[]		= TEXT("JadeRpsDataLoad");
const Character JADE_DATABASE_ADMIN[]		= TEXT("JadeDatabaseAdmin");
const Character JADE_DATABASE_BACKUP[]		= TEXT("JadeDatabaseBackup");
const Character JADE_WEB_SERVIVE_MONITOR_APP[]= TEXT("JadeWebServiceMonitor");
const Character JADE_ATCG_RECORD_APP[]		= TEXT("JadeAtcgRecordApp");
const Character JADE_ATCG_REPLAY_APP[]		= TEXT("JadeAtcgReplayApp");
const Character JADE_ATCG_JADE_APP[]		= TEXT("JadeAtcgJade");
const Character JADE_REGISTER_APP[]			= TEXT("JadeRegisterApp");
const Character JADE_CONVERT_DB_APP[]		= TEXT("JadeConvertDb");
const Character AD_HOC_INDEX_CONTROLLER_APP[] = TEXT("AdHocIndexControllerApp");
const Character JADE_UNIT_TEST_APP[]		= TEXT("JadeUnitTest");
const Character JADE_UNIT_TEST_RUN_APP[]    = TEXT("JadeUnitTestRun");
const Character JADE_HEALTH_CHECK_APP[]		= TEXT("JadeHealthCheckApp");
const Character JADE_WORKSPACE_APP[]		= TEXT("JadeWorkspaceApp");
const Character JADE_WORKSPACE_NON_GUI_APP[] = TEXT("JadeWorkspaceNonGuiApp");

const Character JADEITERABLEIF[]			= TEXT("JadeIterableIF");
const Character JADEREVERSEITERABLEIF[]		= TEXT("JadeReverseIterableIF");

#define	CLASSNUM_FMT						TEXT("%u")
#define	CLASSNUM_FMTn(n)					TEXT("%") TEXT(#n) TEXT("u")
#define	CLASSNUM_FMTs(s)					TEXT("%") TEXT(s) TEXT("u")
#define	TYPENUM_FMT							TEXT("%u")
#define	SCHEMANUM_FMT						TEXT("%u")
#define	FEATURENUM_FMT						TEXT("%hu")

/* specific formats for above types */
#define	INSTID_FMT							UI64_FMT
#define	INSTID_FMTn(n)						TEXT("%") TEXT(#n) UI64_FMT_STR
#define	INSTID_FMTs(s)						TEXT("%") TEXT(s) UI64_FMT_STR
#define	OBJLEN_FMT							UI32_FMT
#define	BUFFSIZE_FMT						UI32_FMT
#define	FILESIZE_FMT						UI64_FMT
#define	FILEOFFSET_FMT						UI64_FMT

#define STR_TO_OID_FMT						CLASSNUM_FMT TEXT(".") INSTID_FMT TEXT(".") CLASSNUM_FMT TEXT(".%u.%u")
#define STR_TO_SHTOID_FMT					CLASSNUM_FMT TEXT(".") INSTID_FMT

const int CLASSNUM_DIGITS					= sizeof "1048575" - 1;						// 2 ^ 20 - 1
const int INSTID_DIGITS						= sizeof "18446744073709551615" - 1;
const int SUBID_DIGITS						= sizeof "65535" - 1;
const int SUBLEVEL_DIGITS					= sizeof "255" - 1;
const int OID_DOT							= sizeof "." - 1;

const int OID_DIGITS						= CLASSNUM_DIGITS + OID_DOT + INSTID_DIGITS + OID_DOT + CLASSNUM_DIGITS + OID_DOT + SUBLEVEL_DIGITS + OID_DOT + SUBID_DIGITS;
const int SHORTOID_DIGITS					= CLASSNUM_DIGITS + OID_DOT + INSTID_DIGITS;

const unsigned UNBOUNDED_LENGTH				= UINT_MAX;		/* length of unbounded slob or blob */
const unsigned MAX_EMBEDDED_STRING_NTSCHARLENGTH= 540;		/* In Characters, includes a null */
const unsigned MAX_EMBEDDED_STRINGUTF8_CHARLENGTH= 540;		/* In Characters */
const unsigned MAX_EMBEDDED_BINARY_BYTELENGTH= 540;			/* In bytes */
const unsigned MAX_BINARY_LENGTH			= INT_MAX;		/* length internally is limited to (Max_Integer) 2GB */
const unsigned MAX_STRING_LENGTH			= INT_MAX;		/* length internally is limited to (Max_Integer) 2GB */
const unsigned MAX_STRINGUTF8_LENGTH		= INT_MAX;		/* length internally is limited to (Max_Integer) 2GB */
const unsigned MAX_DATABASES				= 15;
const unsigned MAX_CALL_LEVELS				= 256;
const unsigned MAX_GLOBAL_EXCEPTION_HANDLERS= 128;
const unsigned MAX_LOCAL_EXCEPTION_HANDLERS	= 128;			/* this limit is per called method */

#define INSTANCETYPE_OFF_BITS_MASK			0x7fff
#define INSTANCETYPE_ON_BITS_MASK			0x8000
#define HAS_NEXT_VERSION_BIT_MASK			0x4000
#define SHAREABILITY_OFF_BITS_MASK			0xdfff
#define SHAREABILITY_ON_BITS_MASK			0x2000
/* 03Sep2004:A bit to indicate suppression of constructors and destructors */
#define SKELETON_ON_BITS_MASK				0x1000
#define SKELETON_OFF_BITS_MASK				0xefff
#define VOLATILITY_ON_BITS_MASK				0x0C00
#define VOLATILITY_OFF_BITS_MASK			0xf3ff

const unsigned VOLATILITY_OFFSET			= 8;

/*DskBuffer cacheBits bits*/
#define CACHE_BIT_HAS_BEEN_WRITTEN			0x0001
#define CACHE_BIT_IS_COLL_HEADER			0x0002
#define CACHE_BIT_IS_OBSOLETE				0x0004
#define CACHE_BIT_IS_NOT_INSTANTIATED		0x0008
#define CACHE_BIT_IS_JADEBYTES				0x0010
#define CACHE_BIT_IS_JADEDATABLOCK			0x0020
#define CACHE_BIT_IS_RAWSINGLEFILE			0x0040
#define CACHE_BIT_DO_CACHE_BLOCKS			0x0080
#define CACHE_BIT_IS_NON_RESIDENT			0x0100
#define CACHE_BIT_LOCAL_ONLY_LOCK			0x0200
#define CACHE_BIT_IS_READ_LOCK				0x0400
#define CACHE_BIT_MAY_HAVE_CLUSTERS			0x0800
#define CACHE_BIT_HAS_BEEN_SENT				0x1000
#define CACHE_BIT_DELETE_CLUSTERS			0x2000

#define CLEAR_HAS_BEEN_WRITTEN(a)			a &= (UInt16)~CACHE_BIT_HAS_BEEN_WRITTEN
#define SET_HAS_BEEN_WRITTEN(a)				a |= CACHE_BIT_HAS_BEEN_WRITTEN
#define CLEAR_IS_COLL_HEADER(a)				a &= (UInt16)~CACHE_BIT_IS_COLL_HEADER
#define SET_IS_COLL_HEADER(a)				a |= CACHE_BIT_IS_COLL_HEADER
#define CLEAR_IS_OBSOLETE(a)				a &= (UInt16)~CACHE_BIT_IS_OBSOLETE
#define SET_IS_OBSOLETE(a)					a |= CACHE_BIT_IS_OBSOLETE
#define CLEAR_IS_NON_RESIDENT(a)			a &= (UInt16)~CACHE_BIT_IS_NON_RESIDENT
#define SET_IS_NON_RESIDENT(a)				a |= CACHE_BIT_IS_NON_RESIDENT
#define CLEAR_LOCAL_ONLY_LOCK(a)			a &= (UInt16)~CACHE_BIT_LOCAL_ONLY_LOCK
#define SET_LOCAL_ONLY_LOCK(a)				a |= CACHE_BIT_LOCAL_ONLY_LOCK
#define CLEAR_IS_NOT_INSTANTIATED(a)		a &= (UInt16)~CACHE_BIT_IS_NOT_INSTANTIATED
#define SET_IS_NOT_INSTANTIATED(a)			a |= CACHE_BIT_IS_NOT_INSTANTIATED
#define CLEAR_IS_READ_LOCK(a)				a &= (UInt16)~CACHE_BIT_IS_READ_LOCK
#define SET_IS_READ_LOCK(a)					a |= CACHE_BIT_IS_READ_LOCK
#define CLEAR_MAY_HAVE_CLUSTERS(a)			a &= (UInt16)~CACHE_BIT_MAY_HAVE_CLUSTERS
#define SET_MAY_HAVE_CLUSTERS(a)			a |= CACHE_BIT_MAY_HAVE_CLUSTERS
#define CLEAR_HAS_BEEN_SENT(a)				a &= (UInt16)~CACHE_BIT_HAS_BEEN_SENT
#define SET_HAS_BEEN_SENT(a)				a |= CACHE_BIT_HAS_BEEN_SENT
#define CLEAR_DELETE_CLUSTERS(a)			a &= (UInt16)~CACHE_BIT_DELETE_CLUSTERS
#define SET_DELETE_CLUSTERS(a)				a |= CACHE_BIT_DELETE_CLUSTERS

const unsigned USER_SCHEMA_METHOD_NUM_BASE	= 1000;
const unsigned PROPERTY_LENGTH_BYTES		= 2;

#define CHECK_RESULT						if (result) return result
#define	OUT_ON_RESULT						if (result) goto out
#define BREAK_ON_RESULT						if (result) break
#define RETURN_ON_RESULT					if (result) return
#define RETURN_RESULT(r)    			    { result = r; return; }

const Character DEFAULT_SUBUSERID[]			= TEXT("default");

const Character CONSTRUCTOR_NAME[]			= TEXT("create");
const Character DESTRUCTOR_NAME[]			= TEXT("delete");

/* pDbUser->status values - sign on state of a user	*/
#define USER_CONNECTING						1
#define USER_FULLY_CONNECTED				4
#define USER_FORCED_OFF						6

/* JOM LIMITS	*/
const unsigned int MAX_DB_NAME         		= 20; 				/* max length of db name with \0 	*/

#define MAX_PATH_NAME						JADE_MAX_PATH
const unsigned int MAX_TRACE_OPTIONS		= 20;
const unsigned int HEAP_CHUNK_SIZE			= 65535;
const unsigned int MIN_IO_BUFFER_SIZE		= 32000 * sizeof(Character);
const unsigned int MAX_LOCK_WAIT_TIME		= 0x7FFFFFFF;

/* bit values for options attribute of class Routine */
const int Options_EncryptedSource			= 0x0001;
const int Options_HasPseudoMethodCallParam  = 0x0002;
const int Options_IsTypeMethod				= 0x0004;
const int Options_IsReceiverByReference		= 0x0008;
const int Options_IsGenerated				= 0x0010;

/* values for Script::status */
const int SCRIPT_NOT_COMPILED				= 0;				/* RootSchema::Script::ScriptNotCompiled */
const int SCRIPT_COMPILED					= 1;				/* RootSchema::Script::ScriptCompiled */

/* Include application types that support invocation of the Exception::showDialog method in the following string 
	GUI_APPLICATION							G
	WEB_APPLICATION							W
*/
const Character APPTYPE_UHE_DO_SHOWDIALOG[]	= TEXT("GWL");

/* Windows message numbers */
#if defined(UNIX)
const int WM_DESTROY						= 0x0002;
const int WM_QUIT							= 0x0012;
const int WM_TIMER							= 0x0113;
const int WM_USER							= 0x0400;
#endif
const int WM_THREAD_CALLBACK 				= WM_USER + 7010;
const int WM_EMERGENCY_SHUTDOWN				= WM_USER + 7011;
const int WM_THREAD_QUIT	 				= WM_USER + 7012;
const int WM_SIGNOFF_USER					= WM_USER + 7013;
const int WM_THREADWRAPPED_CALLBACK			= WM_USER + 7016;

/* execution locations  */
const int LOC_APP_SERVER					= 0;				/* RootSchema::ExecutionLocation::CurrentLocation */
const int LOC_DATABASE_SERVER				= 1;				/* RootSchema::ExecutionLocation::DatabaseServer */
const int LOC_PRESENTATION_CLIENT			= 2;				/* RootSchema::ExecutionLocation::PresentationClient */

/* getExecutingMethod flag values */
const unsigned int REMOTE_TRANSACTION_STATE_MASK	= 0x0001;
const unsigned int SERVER_EXECUTION_CONTEXT_MASK	= 0x0002;

/* Schema formsManagement styles */
const BYTE SCHEMA_FORMSMGMNT_MULTI_MULTI	= 0;				/* multiple definition, multiple translation */
const BYTE SCHEMA_FORMSMGMNT_SINGLE_SINGLE	= 1;				/* single definition, single translation */
const BYTE SCHEMA_FORMSMGMNT_SINGLE_MULTI	= 2;				/* single definition, multiple translation */
const BYTE SCHEMA_FORMSMGMNT_DEFAULT		= SCHEMA_FORMSMGMNT_MULTI_MULTI;

#endif /* JOMDEFS_h */
