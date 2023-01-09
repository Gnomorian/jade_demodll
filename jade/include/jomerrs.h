/****************************************************************************

				P R O P R I E T A R Y   N O T I C E

	This software, in whole and in every part, is proprietary to Jade Software
	Corporation Limited at Christchurch, New Zealand and is not to be
	reproduced, used or disclosed except upon prior written permission of Jade
	Software Corporation Limited.

	COPYRIGHT (c) JADE SOFTWARE CORPORATION LIMITED 2005 - ALL RIGHTS RESERVED

****************************************************************************/

/*******************************************************************************
		J O M    E R R O R    C O D E S
*******************************************************************************/

#ifndef JOMERRS_h
#define JOMERRS_h

#define DEFAULT_HELP_BOOK 	TEXT("JADEMsgs.pdf")

// Message Catalog Support : Severity Names
#define		JADE_SEVERITY_SUCCESS			0x0
#define		JADE_SEVERITY_INFORMATION		0x1
#define		JADE_SEVERITY_WARNING			0x2
#define		JADE_SEVERITY_ERROR				0x3

// Message Catalog Support : Facility Names
#define		JADE_FACILITY_JADMSGS			0x100
#define		JADE_FACILITY_SERVICES			0x101

//  Do not remove the //__ directives used by jom resource build to insert
//  comments in the jommsg.eng file

/*__beginres	System */
//__
//__		JADE Object Manager Error Messages ( 2 - 1299 )
//__
#define	J_OK 					       				0    /*No error*/
#define UNDEFINED_MESSAGE_NUMBER					1	 /*Undefined message number*/
#define UNDEFINED_CPP_EXCEPTION    					3    /*Caught an unexpected C++ exception*/
#define OBJECT_NOT_FOUND	       					4
#define UNDEFINED_SEH_EXCEPTION    					5    /*Caught an unexpected SEH exception*/
#define BRANCH_NOT_FOUND               				6    /*The designated object branch does not exist [obsolete] */
#define PUREVIRTUAL_CPP_EXCEPTION					7    /*Caught an unexpected C++ Pure Virtual Call exception*/
#define INVALID_ADDRESS 	       					8
#define ILLEGAL_ERROR								9	 /*Illegal error [obsolete]*/
#define SUBOBJECT_LOCKED               				10	/* [obsolete] */
#define OWNEROBJECT_LOCKED             				11	/* [obsolete] */
#define OBJECT_NOT_PRESENT	       					12  /* Cannot access object in an offline file or offline file partition */
#define UNEXPECTED_STD_EXCEPTION					13  /* Caught an unexpected C++ Standard Library exception*/
#define SERVER_TIMEOUT		       					30
#define USER_EXITCODE_VALUE_32	       				32	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_33	       				33	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_34	       				34	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_35	       				35	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_36	       				36	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_37	       				37	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_38	       				38	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_39	       				39	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_40	       				40	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_41	       				41	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_42	       				42	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_43	       				43	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_44	       				44	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_45	       				45	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_46	       				46	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_47	       				47	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_48	       				48	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_49	       				49	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_50	       				50	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_51	       				51	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_52	       				52	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_53	       				53	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_54	       				54	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_55	       				55	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_56	       				56	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_57	       				57	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_58	       				58	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_59	       				59	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_60	       				60	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_61	       				61	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_62	       				62	/* Node::userExitCode reserved value for users */
#define USER_EXITCODE_VALUE_63	       				63	/* Node::userExitCode reserved value for users */
#define GENERAL_OS_API_ERROR						64  /*Operating system or runtime error occurred, refer to jommsg.log*/
#define BUFFER_OVERRUN								-99	 /*Over ran a buffer, memory has been corrupted*/
#define FATAL_OUT_OF_MEMORY							-100 /*A memory allocation request failed*/
#define	INVALID_LIBRARY								123
#define BUFFER_ON_DIFFERENT_NODE					124	 /*Cannot access memory buffer created on a different node*/
#define JADE_INIFILE_DOESNOTEXIST					125	 /*The specified or default Jade INI file does not exist*/
#define BUFFER_TOO_SMALL							126	 /*Supplied buffer size is too small*/
#define METHOD_ONLY_SINGLE_USER						131	 /*This method can only be executed in single user*/
#define INVALID_PARAMETER_TYPE	       				1000 /*Invalid parameter type*/
#define INVALID_DIRECTORY		       				1001
#define INVALID_PARAMETER_VALUE	       				1002 /*Invalid parameter value*/
#define CLASS_NOT_FOUND								1003 /*Class definition not found in schema branch*/
#define CLOSED_CLASS		       					1004 /*Class is closed*/
#define CLASS_IS_ALREADY_OPEN	       				1005 /*Class is already open [obsolete]*/
#define LIBRARY_NOT_FOUND							1006
#define SUBOBJECT_MANUAL_DELETE	       				1007 /*Cannot manually delete an exclusive subobject*/
#define ENTRY_POINT_NOT_IN_LIBRARY     				1008
#define CANNOT_SET_SUBOBJECT_REFERENCE 				1009
#define INVALID_MESSAGE                				1010 /*The requested method is not defined for the Type of the receiver*/
#define INVALID_PROPERTY               				1011 /*The requested property is not defined for this object class*/
#define CANNOT_MODIFY_SYSTEM_OBJECT    				1012
#define SHARED_REFENCE_TO_SUBOBJECT    				1013 /*Shared reference to subobject*/
#define AGENT_ERROR                    				1014
#define CLASS_AGENT_MISMATCH           				1015
#define SUBOBJECT_MANUAL_CREATE	       				1016 /*Cannot manually create an exclusive subobject*/
#define INVALID_SERVER_MODE		       				1017
#define NO_MEMORY_FOR_BUFFERS          				1018
#define CANNOT_LOAD_SCHEMA             				1019
#define TOO_MANY_CLASSES               				1020
#define INVALID_CLASS_FOR_PROPERTY     				1021
#define INVALID_TYPE_FOR_COLL_MEMBERSHIP			1022 /*Type is incompatible with foreach collection membership*/
#define INVALID_TYPE_FOR_TARGET_VARIABLE			1023 /*Type is incompatible with foreach target variable */
#define NO_CLASSMAP_DEFINED_FOR_CLASS  				1024
#define ALREADY_IN_TRANSACTION_STATE   				1025
#define NOT_IN_TRANSACTION_STATE       				1026
#define OBJECT_LOCKED                  				1027
#define OBJECT_NOT_NAILED							1028 /*This process does not have the object's buffer nailed*/
#define RETRY_LOCK									1029 /*Internal use only*/
#define RETRY_LOCK_WITH_INFO						1030 /*Internal use only*/
#define HARDCODED_SCHEMA_CLASS_UPDATE				1031 /*Cannot update a bootstrap schema class*/
#define CLEAR_BUFFERS_IN_TRANSACTION				1032 /*Cannot clear buffers in transaction state*/
#define DUPLICATED_OBJECT              				1034
#define STRING_TOO_LONG                				1035
#define NO_SUPER_SCHEMA_AGENT						1036 /*Failed to find superschema agent*/
#define NO_SUPER_SCHEMA_CLASS_DESC					1037 /*Failed to find class descriptor in superschema*/
#define NO_BASE_CLASS_DESC							1038 /*Failed to find base class descriptor for subschema copy*/
#define JADE_SCHEMA_AGENT_OPEN_FAILED				1039 /*Failed to open JADE schema agent*/
#define SCHEMA_AGENT_OPEN_FAILED					1040 /*Failed to open schema agent*/
#define ROOT_SCHEMA_AGENT_OPEN_FAILED				1041 /*Failed to open root schema agent*/
#define INVALID_HANDLE	               				1042
#define CANNOT_CREATE_ABSTRACT						1043 /*Cannot create instances of an abstract class*/
#define APPLICATION_FORCE_SIGN_OFF					1044 /*Application received a forced sign off request*/
#define ASSOC_BUFFERS_LEADER_NOT_LOCKED				1045
#define	INVALID_CLASS_NUMBER           				1046
#define	INVALID_LOCK_TYPE              				1047
#define UPDATE_OUTSIDE_TRANSACTION     				1048
#define DATABASE_IS_UNAVAILABLE        				1049
#define DUPLICATED_USER_ID							1050 /*Duplicated user id [obsolete]*/
#define	INVALID_SCHEMA_AGENT						1051
#define TOO_MANY_USERS								1052 /*Too many users*/
#define ALREADY_IN_LOAD_STATE          				1053 /*Already in load state [obsolete]*/
#define NOT_IN_LOAD_STATE              				1054 /*Not in load state [obsolete]*/
#define INTERNAL_TRANSACTION_TRACE_INCONSISTENCY	1055 /*Internal transaction trace information is inconsistent*/
#define INCOMPATIBLE_SCHEMA_FILE       				1056
#define INCOMPATIBLE_SCHEMARC_DLL      				1057 /*Incompatible jomscm library*/
#define SET_SCHEMA_IN_TRANSACTION					1058 /*Cannot set a schema in transaction state*/
#define MIGHT_HAVE_SHARED_LOCK						1059 /*Internal use only*/
#define CLASS_STILL_HAS_SUBCLASS       				1060 /*Class still has subclasses*/
#define CLASS_IS_STILL_REFERENCED      				1061 /*Class is referenced by other classes*/
#define KNL_INVALID_CTXHANDLE						1062 /*Invalid context handle passed to kernel*/
#define FILE_HAS_CLASSMAP	       					1063 /*File still has class maps assigned*/
#define DB_HAS_FILE		       						1064 /*Database still has a file assigned*/
#define NOTE_EXISTS		      						1065 /*Notification for this OID already set*/
#define NOTE_DOES_NOT_EXIST	       					1066 /*Notification not set for this OID*/
#define NOTE_BAD_SYSTEM_EVENT      					1067 /*Notification to system events can only be set on persistent objects*/
#define FEATURE_NOT_AVAILABLE          				1068 /*Feature not available in this release*/
#define NOT_LATEST_VERSION	       					1069 /*The object is not the latest version*/
#define CLASS_STILL_HAS_METHODS						1070 /*Class still has methods [obsolete]*/
#define CANNOT_INHERIT_METHOD	       				1071
#define OBJECT_DELETED		       					1072 /*Object has been deleted in the current transaction*/
#define INVALID_PUT_OBJECT	       					1073
#define USER_MUST_LOGOFF	       					1074
#define CANNOT_FORCE_OFF_USER						1075 /*Cannot force off user*/
#define UNKNOWN_SERVER_COMMAND						1076 /*Unknown server command [obsolete]*/
#define INVALID_USER_ID								1077 /*User id is invalid [obsolete]*/
#define INVALID_CLIENT_REQUEST	       				1078 /*Client request is invalid*/
#define ACCESS_MODE_VIOLATION	       				1079
#define DOUBLE_CALL_TO_JOM		       				1080 /*Double call to JADE Object Manager*/
#define DEADLOCK				       				1081
#define NOTE_NO_MEMORY			       				1082 /*No memory available for notification*/
#define NOTE_NO_WINDOW_HANDLE	       				1083 /*No windows handle on Begin notification [obsolete]*/
#define INVALID_DATABASE_USAGE	       				1084
#define READ_ONLY_DATABASE		       				1085
#define TYPE_GUARD_FAILED		       				1086 /*Class of object is invalid in this context*/
#define TYPE_INVERSE_INVALID	       				1087 /*Inverse is invalid [obsolete]*/
#define UPDATE_TO_AUTOMATIC_VAR	       				1088 /*Cannot manually update an automatic reference*/
#define CONTEXT_ERROR			       				1089
#define NULL_OBJECT_REFERENCE						1090 /*Attempted access via null object reference*/
#define BINARY_TOO_LONG                				1091
#define OBJECT_NOT_AVAILABLE						1092
#define	INVALID_LOCK_DURATION          				1093
#define	INCOMPATIBLE_RESCTRICTED_CODE_ACCESS		1094 /*Cannot use this code version of JADE with a non-evaluation database [obsolete]*/
#define	INCOMPATIBLE_RESCTRICTED_DATABASE_ACCESS	1095 /*Cannot use this code version of JADE with an evaluation database [obsolete]*/
#define EXCEEDED_CLASS_MAX_INSTANCES				1096 /*Exceeded the maximum number of instances allowed for a class [obsolete]*/
#define EXCL_COLL_CANNOT_HAVE_SUBOBJECT				1097 /*Exclusive collections cannot have subobject properties*/
#define TOO_MANY_PROPERTIES							1098 /*Exceeded the maximum number of properties allowed for a class [obsolete]*/
#define NO_INVERSE_FOR_KEY_PATH						1099 /*Key path component does not have an inverse to its prior component: refer to jommsg.log*/

#define ALREADY_VERSIONED							1100 /*The target object is already versioned*/
#define INTERFACE_STILL_HAS_SUBINTERFACES			1101 /*Interface still has subinterfaces*/
#define INTERFACE_STILL_HAS_IMPLEMENTORS			1102 /*Interface still has implementors*/
#define ALREADY_SIGNED_ON							1103 /*Already signed on*/
#define COULD_NOT_TERMINATE_ALL_USERS				1104 /*Could not terminate all user processes*/
#define COULD_NOT_CLOSE_ALL_USER_CLASSES			1105 /*Could not close all user classes*/
#define UPDATE_FROZEN_OBJECT						1106 /*Can not update a frozen object*/
#define TRANSIENT_INSTANCE_NOT_ALLOWED				1107 /*The current operation cannot be performed on a transient instance*/
#define TOO_MANY_INTERFACES            				1108
#define TOO_MANY_SCHEMAS							1109
#define TOO_MANY_TRANSLATABLE_STRINGS				1110
#define TOO_MANY_LOCALE_FORMATS						1111
#define FEATURE_DEPRECATED							1112 /*Feature has been deprecated*/
#define INVALID_INTERFACE							1113 /*Receiver does not implement the specified interface*/
#define INVALID_OPERATION_FOR_INTERFACE				1114 /*The specified interface does not define this operation*/
#define INVALID_NOTIFICATION_METHOD_SIGNATURE		1115 /*The corresponding sysNotification or userNotification method has an incompatible signature*/
#define INVALID_TIMEREVENT_METHOD_SIGNATURE			1116 /*The corresponding timerEvent method has an incompatible signature*/
//#define COULD_NOT_CLEAR_ALL_CLIENT_CACHES			1117 /*Could not clear all client node caches [obsolete]*/
#define JOM_METHOD_ABORTED_CONDITIONALLY			1118 /*Method conditionally aborted*/
#define NODE_IS_FINALIZING							1119 /*Node is terminating*/
#define PROCESS_LIMIT_REACHED						1120 /*The maximum number of processes are already signed on*/
#define UNVERSION_LOCK_ERROR						1121 /*Cannot delete versioned object due to lock conflicts*/
#define TOO_MANY_EXPORTEDPACKAGES					1122
#define UNNUMBERED_EXPORTEDPACKAGE					1123 /*ExportedPackage has not been numbered*/
#define STRINGUTF8_TOO_LONG			 				1124 /*StringUtf8 too long*/
#define CANNOT_MAKE_VERSION_TO_SELF					1125 /*Cannot make an object a version of itself*/
#define CANNOT_THAW_CLASS_IN_USE					1126 /*Cannot conditionally change volatility from frozen if class is currently open*/
#define	REPLY_DEFERRED								1127 /*INTERNAL USE ONLY NOT USER VISIBLE*/
#define INVALID_TARGET_PROCESS						1128 /*The target process is not valid*/
//#define CHECK_INTERRUPT_QUEUE						1129 /*Internal [obsolete]*/
#define ATTEMPT_TO_INVOKE_NOTIMPLEMENTED_METHOD		1130 /*Cannot invoke a method marked notImplemented*/
#define CONTENTION_STATS_ALREADY_ACTIVE				1131 /*Another process is currently in control of lock contention statistics*/
#define WBEM_CONNECTION_ERROR					    1132 /*WBEM interface error when connecting or disconnecting*/
#define WBEM_QUERY_ERROR							1133 /*WBEM interface error when querying data*/
#define COLL_HEADER_NOT_ON_CALL_STACK				1134 /*Collection block accessed not via a collection header method*/
#define VERSIONING_NOT_SUPPORTED					1135 /*Versioning is not supported on this platform*/
#define WBEM_PROHIBITED_CLASS_NAME					1136 /*WBEM class name is not valid*/
#define INTERNAL_DATAPACKET_INCONSISTENCY			1137 /*An internal data packet inconsistency was detected*/
#define OBJECT_TRACKING_ALREADY_ACTIVE				1138 /*Object tracking is already active*/
#define OBJECT_TRACKING_NOT_ACTIVE					1139 /*Object tracking is not active*/
#define LOCK_STATE_OBJECT_LOCKED					1140 /*An implied lock (due to lock state) could not be obtained*/
#define WBEM_TOO_MUCH_DATA							1141 /*WBEM data exceeded maximum allowable size*/
#define INVALID_INSTANCE_LIFETIME					1142 /*Lifetime of Class instance is invalid*/
#define METADATA_PARENT_NOT_DEFINED					1143 /*Metadata parent object is not defined*/
#define CLASS_ACCESS_FREQUENCIES_DISABLED			1144 /*Class access frequency counters are not enabled*/
#define CANNOT_DELETE_RECEIVERS_PARENT_OBJECT		1145 /*Cannot delete the parent object of the receiver*/
#define INTERVENING_UPDATE							1146 /*The object was updated before the lock upgrade completed*/
#define	INVALID_INTRA_PROCESS_REQUEST				1147 /*Invalid intra process request*/
#define APPLICATION_SIGNON_RESTRICTED				1148 /*Application signon from this node is restricted*/
#define TOO_MANY_AUXILIARY_NODES					1149 /*The maximum number of auxiliary nodes are already active*/
#define INVALID_OBJECT_VOLATILTY_VALUE				1150 /*Invalid Object Volatility Value*/
#define TOO_MANY_CLASSMAPS							1151 /*More than one class mapped to this DbFile*/
#define CANNOT_PARTITION_COLLCLASS					1152 /*Collection class cannot be partitioned*/
#define LOCK_TIMED_OUT								1153 /*Operation aborted due to a lock timeout*/
#define METHOD_TRACKING_NOT_ALLOWED					1154 /*Method tracking is not allowed*/
#define TRANSACTION_TRACE_ALREADY_STARTED			1155 /*Transaction trace is already currently started for this process*/
#define TRANSACTION_TRACE_NOT_STARTED				1156 /*Transaction trace is not currently started for this process*/
#define IS_CURRENT_TRANSACTION_TRACE_OBJECT			1157 /*The object is currently being used for transaction tracing*/
#define METHOD_STACK_NOT_EMPTY						1158 /*The method stack is non-empty*/
#define ILLEGAL_UPDATE								1159 /*Update not allowed*/
#define BG_REQUEST_NOT_COMPLETED					1160 /*Background Process request was not completed*/
#define BG_PROCESS_LOCK_ERROR						1161 /*Background Process request encountered a lock error*/
#define NOT_DELTA_DB_CAPABLE						1162 /*The system is not Delta Database capable*/
#define DELTA_DB_PROCESSES_NOT_IDLE					1163 /*Could not change delta database mode because not all processes are idle*/
#define EDITION_MISMATCH							1164 /*Parent-subobject edition mismatch*/
#define DUPLICATE_DELTA_DB_TRANSITION_REQUEST		1165 /*A delta database transition request is already in progress*/
#define NODE_ALREADY_INITIALISED					1166 /*Node already initialised*/
#define EXCEEDED_MAXIMUM_LOCK_LEVEL					1167 /*Exceeded the maximum load state/lock state nesting level*/
#define TOO_MANY_NODES								1168 /*Exceeded the maximum number of nodes allowed*/
#define NODE_NOT_INITIALISED						1169 /*Node is not initialised*/
#define NODE_HAS_FINALISED							1170 /*Node has finalised*/
#define CONFIGURATION_STRING_READONLY				1171 /*Configuration string is readonly*/
#define ONLY_ONE_LOCAL_SERVER_ALLOWED				1172 /*Only one local server node is allowed*/
#define	CLASS_DEFINITION_INCOMPLETE					1173 /*Class definition incomplete*/
#define	CLASS_IN_USE								1174 /*Class is in use by another process*/
//#define OWNER_IS_OBSOLETE							1175 /*Internal use only [obsolete]*/			    
#define INSTANCES_EXIST								1176 /*Operation not permitted: instances of this class or a subclass exist*/
#define DYNAMIC_PROPERTY_CONVERSION_ERROR			1177 /*The value of the Dynamic Property is not valid for the current property definition*/
#define DYNAMIC_PROPERTY_CONVERSION_INVALID			1178 /*The type of the Dynamic Property value is not valid for type of the current property definition*/
#define DUPLICATE_FEATURE_NUMBER					1179 /*A feature with this number is already defined*/
#define ERROR_SIGNING_OFF_PROCESS					1180 /*An error occurred during Process sign off: refer to jommsg.log*/
#define LOGICAL_CERTIFY_ERRORS         				1182 /*Logical or Meta Certify errors encountered*/
#define METHODS_IN_ERROR							1183 /*Uncompiled or in error methods remain*/
#define INVALID_TYPE_MESSAGE                		1184 /*The requested method is not defined as a type method*/
#define INVALID_TYPE_MESSAGE_CALL            		1185 /*Invalid call to a type method*/
#define TOO_MANY_DATABASES							1186 /*Exceeded the maximum number of databases allowed*/
#define TRANSACTION_INTEGRITY_VIOLATION				1187 /*Attempt to change transaction state within a constructor or destructor*/
#define CONSTRUCTOR_NOT_CALLED						1188 /*Constructor not called*/
#define CONSTRUCTOR_ALREADY_CALLED					1189 /*Constructor already called*/
#define INVALID_PARAMETER_FILE_REFERENCE			1190 /*A Batch Extract parameter file references a class or method that does not exist in the Schema*/
#define ILLEGAL_MESSAGE                				1191 /*The requested method cannot be called*/
#define FEATURE_RESTRICTED							1192 /*Feature is restricted to system processes*/
#define INVERSE_VALUE_DUPLICATED					1193 /*Internal error - Attempt to add duplicate value to a collection with an inverse*/
#define INVERSE_VALUE_NOT_FOUND						1194 /*Internal error - Entry not found in a collection with an inverse*/
#define DEFAULT_CLASSMAP_NOT_DEFINED				1195 /*Default class map not defined for database*/

#define CLASS_NEEDS_REORG							1200 /*Class needs reorganization*/
#define KERNEL_STACK_OVERFLOW	  					1201
#define ALREADY_IN_CACHE							1202 /*Internal Status- The object is already present in the cache*/
#define INVALID_EXCEPTION_CLASS						1203
#define INVALID_EXCEPTION_INSTANCE					1204
#define JOM_METHOD_ABORTED							1205 /*Method aborted*/
#define EXCEPTION_HANDLERS_STACK_OVERFLOW			1206
#define INVALID_PRIM_NUMBER							1207 /*Invalid primitive number*/
#define INVALID_SCHEMA_INSTANCE						1208 /*Invalid schema instance [obsolete]*/
#define APPLICATION_TERMINATE_REQUEST				1209
#define DUPLICATED_RELATIONSHIP_REFERENCE			1210
#define OBJECT_HAS_REFERENCES						1211 /*Cannot delete an object that has references*/
#define REFERENCE_INVERSE_MISSING					1212
#define INVALID_SCHEMA								1213
#define INVALID_APPLICATION							1214
#define PERSISTENT_TRANSIENT_REFERENCE				1215 /*Persistent objects cannot reference transient objects*/
#define ATTEMPT_TO_INVOKE_ABSTRACT_METHOD			1216 /*Cannot invoke an abstract method*/
#define APPLICATION_TERMINATED						1217
#define INVALID_TRANSIENT_OBJECT					1218 /*Invalid transient object [obsolete]*/
#define INVALID_CALLING_THREAD						1219
#define LOCAL_FILE_MISMATCH							1220
#define	OBJECT_LOCKED_LOCALLY						1221
#define ATTEMPT_TO_DELETE_ENV_OBJECT				1222 /*Cannot delete a currently active environmental object*/
#define CANNOT_ESTABLISH_INVERSE					1223
#define AUTOMATIC_LOCK_IGNORED						1224
#define LOCK_CANNOT_BE_CONTINUED					1225
#define UNINITIALIZED_NOTIFICATION_TARGET			1226
#define NOTIFICATION_SUBSCRIBER_NOT_FOUND			1227
#define ALREADY_IN_REMOTE_TRANSACTION_STATE   		1228
#define NOT_IN_LOCAL_TRANSACTION_STATE       		1229
#define UPDATE_OUTSIDE_LOCAL_TRANSACTION     		1230
#define INVALID_EXCEPTION_CODE		 				1231
#define NO_TYPE_FOR_PROPERTY						1232 /*Property has an undefined type: refer to jommsg.log*/
#define NO_TYPE_FOR_FEATURE							1233 /*Feature has an undefined type: refer to jommsg.log*/
#define SLOB_OR_BLOB_ZERO_SUBID						1234 /*Slob or blob property has a zero sub id: refer to jommsg.log*/
#define UPGRADE_NOT_RUN								1235 /*Required database upgrade has not been run*/
#define SYSTEM_CLASS_CREATE_NOT_ALLOWED				1236 /*Cannot create this instance of a system class or subclass: refer to jommsg.log*/
#define SYSTEM_CLASS_DELETE_NOT_ALLOWED				1237 /*Cannot delete this instance of a system class or subclass: refer to jommsg.log*/
#define EXCEPTION_HANDLER_INVALID_RETURN_CODE		1238
#define NESTED_EXCEPTIONS_LIMIT_EXCEEDED			1239
#define TOO_MANY_SUBOBJECTS							1240 /*Exceeded the maximum number of sub-objects allowed for a class*/
#define TOO_MANY_SLOBS_AND_BLOBS					1241 /*Exceeded the maximum number of slobs and blobs allowed for a class*/
#define REMOTE_EXECUTION_ABORTED 					1242 /*A method executing in another node was aborted*/
#define SYSTEM_SUBCLASS_NOT_ALLOWED					1243 /*Subclass of system class not allowed: refer to jommsg.log [obsolete]*/
#define	INVALID_APPLICATION_TYPE					1244 /*Invalid application type*/
#define	INCORRECT_APPLICATION_TYPE					1245 /*Incorrect application type*/
#define AUTOMATIC_UPDATE_ABORTED					1246
#define BUFFER_ERROR								1247
#define USER_SERVER_METHOD_NOT_ALLOWED				1248 /*Cannot execute a user schema server method in this process*/
#define NO_LIBRARY_FOR_METHOD						1249 /*Attempt to access method in an undefined library: refer to jommsg.log [obsolete]*/
#define MAP_METHOD_KEY_CHG_NOT_ALLOWED				1250 /*Attempt to change key value in a mapping method get operation: refer to jommsg.log*/
#define KERNEL_TERMINAL_STACK_OVERFLOW				1251 /*A stack overflow exception handler exceeded 20 call levels*/
#define TRANSACTION_MUST_BE_ABORTED					1252
#define	APPLICATION_STARTUP_TIMEOUT					1253 /*Application did not complete signon within the specified startup waitTime*/
#define INVALID_TRANSIENT_CLASS_NUMBER				1254
#define INVALID_TRANSIENT_CLASS						1255
#define TRANSIENT_SUPERCLASS_NOT_ALLOWED			1256 /*A transient class cannot be the superclass of another class*/
#define TRANSIENT_CLASS_ALREADY_REGISTERED			1257 /*Transient class already registered with this number: refer to jommsg.log*/
#define TRANSIENT_CLASS_NOT_ALLOWED					1258 /*The current operation cannot be performed on a transient class*/
#define TRANSIENT_COLL_CLS_NOT_ALLOWED				1259 /*Transient subclasses of Collection are not allowed*/
#define TOO_MANY_TRANSIENT_CLASSES					1260 /*Exceeded the maximum number of transient classes allowed for a process*/
#define INVALID_TRANSIENT_CLASS_PROP				1261 /*Invalid transient class property [obsolete]*/
#define TRANSIENT_CLS_CANNOT_BE_CHANGED				1262 /*Transient class is open and cannot be changed [obsolete]*/
#define TRANS_CLS_NON_SHARED_TRANS_ONLY				1263 /*Cannot create persistent or shared transient instances of a transient class*/
#define INVALID_TYPE_FOR_PROPERTY					1264 /*Invalid type for property*/
#define ENVOBJ_OPERATION_OUT_OF_SCOPE				1265 /*Environmental object operation is out of scope for process*/
#define INVALID_TRANSIENT_SHARING					1266 /*A non-shared transient object is being accessed by another process*/
#define	NOTE_INFO_OBJECT_TOO_BIG					1267 /*Notification info object too big*/
#define ALREADY_IN_TRANSIENT_TRANSACTION_STATE		1268 /*Already in transient transaction state*/
#define NOT_IN_TRANSIENT_TRANSACTION_STATE			1269 /*Not in transient transaction state*/
#define UPDATE_OUTSIDE_TRANSIENT_TRANSACTION		1270 /*Update outside transient transaction*/
#define OPERATION_PROHIBITED						1271 /*An attempt was made to perform an operation eg. beginTransaction etc that is prohibited in this context.*/
#define DUPLICATED_ARRAY_INVERSE_VAL				1272 /*Attempt to add duplicate element to array with inverse*/
#define INVALID_CONSTRAINT             				1273 /*The requested constraint is not defined for this object class*/
#define NO_INVERSE_FOR_CONSTRAINT_PATH				1274 /*Constraint path component does not have an inverse to its prior component: refer to jommsg.log [obsolete]*/
#define FEATURE_NOT_DEFINED							1275 /*Feature not defined so do not set inverse*/
#define POTENTIAL_CACHE_INCONSISTENCY				1276 /*Potential cache inconsistency*/
#define LOCK_QUEUE_RETRY							1277 /*Lock waiting on queue to be retried*/
#define ESTABLISHED_INVERSE_BROKEN					1278 /*Change in a constraint removed all inverses*/
#define AUTOMATIC_DELETE_ABORTED					1279
#define DELETE_CHILDREN_NOT_COMPLETE				1280 /*Delete children operation left children undeleted*/
#define CREATE_IMPLICIT_PACKAGE_FAILED				1281 /*Failed to open implicit package agent [obsolete]*/
#define CANNOT_DISARM_ACTIVE_EX_HANDLER				1282 /*An exception handler cannot be disarmed while it is active*/
#define PACKAGE_AGENT_OPEN_FAILED					1283 /*Failed to open package agent*/
#define SIGNON_IS_DISABLED							1284 /*User sign-on is currently disabled*/
#define CLASS_CREATE_NOT_ALLOWED					1285 /*Cannot create instance of a class: refer to jommsg.log*/
#define CLASS_DELETE_NOT_ALLOWED					1286 /*Cannot delete instance of a class: refer to jommsg.log*/
#define SUBCLASSED_FINAL_CLASS						1287 /*Cannot subclass a final class: refer to jommsg.log*/
#define MAXIMUM_INSTANCE_ID_REACHED					1288 /*No more instances can be created because the instance id is at the maximum value*/
#define SHARED_TRANSIENT_REFERENCE					1289 /*Shared transient objects cannot reference non-shared transient objects*/
#define NODE_SAMPLING_NOT_ACTIVE					1290 /*Node sampling is not currently active [obsolete]*/
#define INVALID_GUI_REQUEST							1291 /*GUI request not allowed in this context*/
#define LOCAL_EXCEPTION_HANDLERS_OVERFLOW			1292 /*Maximum number of local exception handlers exceeded*/
#define UPGRADE_NOT_COMPLETE						1293 /*Required database upgrade has not been completed*/
#define OBJECT_IS_DIRTY								1294 /*Cannot read object modified by a different user*/
#define UPDATE_NONENVIRONMENTAL_OBJECT				1295 /*Cannot update a non-environmental object on a Secondary database*/
#define SDS_TRANSACTION_OVERLAP						1296 /*SDS Transaction Overlap*/
#define YIELD_SDS_LOCK								1297 /*Internal Kernel Status*/
#define SDS_CAUSE_EVENT_IMMED_INVALID				1298 /*Immediate sdsCauseEvent is not allowed in this SDS context*/
#define APPLICATION_NOT_SIGNED_ON					1299 /*The Application has not signed on*/

/*__beginres	Collection   */

//__
//__		Collection Error Messages   (1300 - 1350)
//__
#define COLL_INVALID_INDEX		       				1300 /*Array index out of bounds*/
#define COLL_ENTRY_NOT_FOUND						1301 /*Entry not found in collection*/
#define COLL_DESCRIPTION_INVALID					1302 /*Collection description invalid*/
#define COLL_NOT_ATTACHED							1303 /*Iterator has no collection to iterate*/
#define COLL_START_NOT_SUPPORTED					1304 /*Start from only valid for dictionaries*/
#define COLL_INVALID_KEYOP							1305 /*Relative key operation not valid for Start*/
#define DICT_ITER_MISMATCH							1306 /*Iterator not associated with this dictionary*/
#define COLL_INVALID_SUBOBJECT_REF					1307 /*Cannot pass an exclusive subobject reference to this method*/
#define COLLECTION_UPDATED							1308 /*Cannot update an array during iteration*/
#define DUPLICATED_BTREE_VALUE	 	  				1309 /*Object already added to this set or dictionary*/
#define DUPLICATED_KEY								1310 /*Key already used in this dictionary*/
#define COLL_NULL_REFERENCE							1311 /*Null object reference cannot be passed as a value argument to a collection method*/
#define COLL_INVALID_TYPE							1312 /*Class of value passed to a collection method incompatible with membership*/
#define	ITER_NO_VCOLL_BACK							1313 /*Cannot iterate a virtual collection backwards*/
#define DICT_INVALID_KEY_ORDINAL					1314 /*The ordinal position of the requested key is out of range*/
#define COLL_BLOCK_REMAP_CONFLICT					1315 /*New collection block oid mapped differently to existing blocks*/
#define COLL_ACCESS_PATH_INVALID					1316 /*Collection access path no longer current*/
#define	ITER_GROUP_OP_NOT_VALID						1317 /*Object group operations not valid for collection containing primitive types*/
#define	DYNADICT_DEFINITION_INCOMPLETE				1318 /*Dynamic dictionary definition incomplete*/
#define	DYNADICT_MEMBERTYPE_UNKNOWN					1319 /*Dynamic dictionary membership not set*/
#define	COLLECTION_NOT_EMPTY						1320 /*Operation invalid - collection not empty*/
#define	DYNADICT_KEYS_REQUIRED						1321 /*Dynamic dictionary keys not defined*/
#define	DICT_KEYS_TOO_LONG							1322 /*Total key size exceeds 512 characters*/
#define	DYNADICT_REQUIRES_MEMBER_KEYS				1323 /*Dynamic dictionary operation requires member keys*/
#define	DYNADICT_REQUIRES_EXTERNAL_KEYS				1324 /*Dynamic dictionary operation requires external keys*/
#define	DYNADICT_KEYLENGTH_REQUIRED					1325 /*String or binary key requires a non-zero length*/
#define	DYNADICT_DEFINITION_CLOSED					1326 /*Cannot change dictionary specification after endKeys called*/
#define	DYNADICT_UNFIT_TO_PASS						1327 /*Dynamic dictionary definition cannot span nodes*/
#define	HETEROGENEOUS_ITERS_INVALID					1328 /*Iterators cannot be shared between heterogeneous platforms*/
#define	COLL_BLOCKSIZE_LIMIT_EXCEEDED				1329 /*Requested collection block size exceeds block size limit*/
#define INVALID_FOR_DELETE_WHEN_EMPTIED				1330 /*Operation invalid for collections marked delete when emptied [obsolete]*/
#define INVALID_UNLESS_DELETE_WHEN_EMPTIED			1331 /*Operation invalid for collections not marked delete when emptied [obsolete]*/
#define JADEBYTES_BOUNDS_ERROR						1332 /*JadeBytes access is out of bounds*/
#define JADEBYTES_NOT_EMPTY							1333 /*JadeBytes not empty*/
#define	DICT_ITER_KEYS_TOO_LONG						1334 /*DictIterator keys too long to support resynch*/
#define	DICT_ITER_NO_CURRENT_KEY					1335 /*DictIterator has no current key*/
#define JADEBYTES_INSTANTIATED						1336 /*Cannot change singleFile or unaudited attribute after instantiation*/
#define	COLL_BLOCKSIZE_TOO_SMALL					1337 /*Collection block size cannot be set to less than 4 entries per block*/
#define COLL_BLOCK_STRUCTURE_ERROR					1338 /*Collection block structure error*/
#define JADESPATIAL_DIFFERENT_DIMENSIONS			1339 /*Shapes have different number of dimensions*/
#define JADESPATIAL_RTREE_ERROR						1340 /*The operation could not be completed due to errors in the spatial data tree*/ 
#define JADESPATIAL_REGION_NOT_FOUND				1341 /*The region is not present in the spatial data tree*/ 
#define JADEBYTES_DATA_TOO_LONG       				1342 /*JadeBytes maximum content size exceeded*/
#define JADESPATIAL_RTREE_UPDATED					1343 /*Cannot update an RTree during iteration*/
#define	JADESPATIAL_NOT_SUPPORTED					1344 /*Spatial operation not supported*/
#define JADESPATIAL_GEOS_C_ERROR					1345 /*Spatial library error*/ 
#define JADESPATIAL_DUPLICATED_RTREE_VALUE			1346 /*Object already added to this RTree*/
#define HISTORY_STACK_OVERFLOW						1347 /*Collection history stack overflow*/
#define JADEBYTES_IS_READONLY						1348 /*Cannot update a ReadOnly JadeBytes instance*/
#define JADEBYTES_UNAUDITED_NEEDS_SINGLE			1349 /*JadeBytes unaudited can only be set true when singleFile is true*/
#define JADEBYTES_READONLY_NEEDS_SINGLE				1350 /*JadeBytes readOnly can only be set true when singleFile is true*/
#define JADEBYTES_SINGLEFILE_ONLY					1351 /*JadeBytes feature only supported on instances with singleFile true*/
#define	DYNADICT_KEY_CHANGED						1352 /*Dynamic dictionary key property definition has been changed*/
/*__endres  */

/*__beginres	System   */
//__
//__		Miscellaneous Runtime Errors	(1400 - 1599)
//__
#define DUPLICATE_TIMER								1400 /*The receiver has already registered a timer with the specified tag*/
#define	START_TIMER_FAILED							1401 /*The operating system failed to start the timer*/
#define INVALID_DATE								1402 /*Date is not valid*/
#define NULL_DATE									1403 /*Operation is not valid because Date is null*/
#define INVALID_TIME_ARG							1404 /*hours, minutes, and seconds parameters are not valid*/
#define GET_INSTALL_DIR_FAILED						1405 /*Failed to obtain the JADE installation directory*/
#define JOM_INTEGER_OVERFLOW						1406 /*Result of expression overflows Integer precision*/
#define INVALID_ARGUMENT							1407 /*Invalid argument passed to method*/
#define CLASS_CANNOT_PERSIST 						1408 /*Cannot create a persistent instance of this class*/
#define COMPRESS_FAILED								1409 /*Compress operation failed*/
#define UNCOMPRESS_FAILED							1410 /*Uncompress operation failed*/
#define UNKNOWN_SYSTEM_FILE							1411 /*Attempt to add unknown system file*/
#define SYSTEM_FILE_DELETE							1412 /*Cannot delete system file [obsolete]*/
#define STRING_BOUNDS_ERROR							1413 /*Index used in string operation is out of bounds*/
#define PARAM_NUMBER_MISMATCH						1414 /*Method called with an incorrect number of parameters*/
#define JOM_INTERNAL_ERROR							1415 /*An internal JADE software exception occurred*/
#define INTL_UNICODE_TO_ANSI_FAILED					1416 /*Unicode to Ansi conversion failed*/
#define INTL_ANSI_TO_UNICODE_FAILED					1417 /*Ansi to Unicode conversion failed*/
#define INTL_ILLEGAL_UTF8_BYTE_SEQUENCE				1418 /*Unicode UTF8 file contains illegal byte sequence*/
#define START_APP_LOCK_ERROR						1419 /*The application could not be started due to a lock error*/
#define BASE64_DECODE_FAILED						1420 /*Base64 Decoding failed*/
#define HTML_ESC_DECODE_FAILED						1421 /*Decoding an HTML ESC sequence failed*/
#define DECIMAL_OVERFLOW							1422 /*Result of expression overflows Decimal precision*/
// Dynamic Object Errors
#define	DYNAOBJ_INDEX_OUT_OF_RANGE					1423 /*Dynamic Object property index out of range*/
#define DYNAOBJ_INVALID_STATE						1424 /*Dynamic Object not correctly initialised*/
#define	DYNAOBJ_PROPERTY_NAME_TOO_LONG				1425 /*Dynamic Object property name too long*/
#define	DYNAOBJ_PROPERTY_TYPE_MISMATCH				1426 /*Dynamic Object property type mismatch*/
#define	DYNAOBJ_PROPERTY_NAME_MISMATCH				1427 /*Dynamic Object property name mismatch*/
#define CALLER_NEEDS_RECOMPILE						1428 /*Calling methods needs to be recompiled [obsolete]*/
#define JAA_NODE_MISMATCH							1429 /*Cannot access a JadeAuditAccess object created on a different Node*/
#define JAA_NO_OBJECT								1430 /*Current record is not an Object [obsolete]*/
#define JAA_BAD_FILE_FORMAT							1431 /*Invalid class number map file format*/
#define JAA_CLASS_ALREADY_MAPPED					1432 /*Class map is already defined [obsolete]*/
#define	DYNAOBJ_PROPERTY_NAME_CONFLICT				1433 /*Dynamic Object property name conflict*/
#define INTL_UNICODE_CODEPOINT						1434 /*Invalid code point when converting Unicode character*/
#define TIMER_EXPIRED								1435 /*Requested timer has expired/timed out*/
#define JADE_LOG_FILE_NOT_OPEN						1436 /*Required log file is not currently open*/
#define INTL_UNICODE_FAT_CODEPOINT					1437 /*UNICODE codepoints greater than U+FFFF not supported*/
#define INTL_UTF8_CHAR_TO_NATIVE_FAILED				1438 /*UTF8 character to Native character conversion failed*/
#define INTL_NATIVE_TO_UTF8_FAILED					1439 /*Native string to UTF8 string conversion failed*/
#define JOM_INTEGER64_OVERFLOW						1440 /*Result of expression overflows Integer64 precision*/
#define JOM_BYTE_OVERFLOW							1441 /*Result of expression overflows Byte precision*/
#define INTL_UTF8_SURROGATE_CHARACTER				1442 /*Obsolete - StringUtf8 values containing surrogate characters are not supported*/
#define MEMORYADDRESS_NODE_INVALID					1443 /*MemoryAddress is not valid for current Node*/
#define INTL_UTF16_SURROGATE_SEQUENCE				1444 /*Invalid Unicode UTF-16 surrogate sequence*/
#define INTL_UNSUPPORTED_CODEPAGE					1445 /*Supplied codepage, or codepage derived from LCID is unsupported on this system*/
#define JOM_INTEGER_UNDERFLOW						1446 /*Result of expression underflowed Integer precision*/
#define JOM_INTEGER64_UNDERFLOW						1447 /*Result of expression underflowed Integer64 precision*/
#define OUT_OF_MEMORY								1448 /*A memory allocation request failed*/
#define TOO_MANY_TRANSIENT_ONLY_CLASSES				1449 /*Exceeded the maximum number of transient only classes allowed for a process [obsolete]*/
#define PACKAGE_AGENT_OPEN_FAILED_INCOMPLETE		1450 /*An incomplete package can not be opened*/
#define DELTA_ID_DOES_NOT_EXIST						1451 /*Delta identifier does not exist*/
#define STRING_PRINTF_FORMAT_ERROR					1452 /*String printf format text missing or invalid*/
#define STRING_PRINTF_OVERFLOW						1453 /*String printf text exceeds maxLength*/
#define SYSTEMSEQUENCENUMBER_NAME_INVALID			1454 /*The SystemSequenceNumber name is invalid*/
#define SYSTEMSEQUENCENUMBER_VALUE_NEGATIVE			1455 /*The SystemSequenceNumber initial value cannot be negative*/
#define SYSTEMSEQUENCENUMBER_OVERFLOW				1456 /*The SystemSequenceNumber has reached the maximum value (Max_Integer64)*/
#define	DTNC_FORMATTER_POPULATE_ERROR				1457 /*Error populating Formatter from locale info. See jommsg.log*/
#define	DTNC_FORMATTER_NOT_POPULATED				1458 /*Formatter has not been populated*/
#define	DTNC_LCID_UNRECOGNISED						1459 /*LCID parameter value is not recognized*/
#define	DTNC_INVALID_DATE_TIME_FORMAT_STRING		1460 /*Invalid format string passed to Date/Time formatter. See jommsg.log*/
#define	DTNC_LCID_NOT_INSTALLED						1461 /*LCID parameter value is not an installed locale*/
#define	DTNC_SETTHREADLOCALE_ERROR					1462 /*SetThreadLocale failed*/
#define	DTNC_LCID_NOT_INSTALLED_THIN				1463 /*LCID parameter value is not an installed locale on Thin Client machine*/
#define	DTNC_THIN_SETTHREADLOCALE_ERROR				1464 /*SetThreadLocale failed at Thin Client machine*/
#define DYNAOBJ_INCOMPATIBLE_FORMAT					1465 /*Incompatible Dynamic object format, eg. Ansi to Unicode*/
#define UNIT_TEST_UNABLE_TO_RUN						1466 /*Unable to run a unit test*/
#define UNIT_TEST_TESTS_FAILED						1467 /*Unit tests failed*/
#define INVALID_TIMEZONE							1468 /*Invalid time zone*/
#define TIMEZONE_NOT_FOUND							1469 /*Time zone not found*/
#define INCOMPATIBLE_RETRIEVED_VALUE_TYPE			1470 /*Retrieved value type is incompatible with as clause type*/
#define INCOMPATIBLE_DEFERRED_UPDATE				1471 /*Deferred update is incompatible with prior updates*/
#define DUPLICATED_METHOD_MOCK						1472 /*Method mock already exists*/
#define METHOD_MOCK_NOT_FOUND						1473 /*Method mock not found*/
#define METHOD_MOCK_NOT_DELETED						1474 /*Method mock not deleted*/
#define METHOD_MOCKING_NOT_ENABLED					1475 /*Method mocking is not enabled*/
#define METHOD_MOCK_MULTIPLE_SCHEMAS				1476 /*Method mock type declared in multiple schemas*/
#define METHOD_MOCKING_NOT_SYSTEMONLY				1477 /*Method mocking a systemOnly method is not allowed */
/*__endres  */
	
#define INVALID_SR_HANDLE              				1600 /*Handle in remote procedure call request is invalid*/
/* Reserve 100 error for the INVALID_SR_HANDLE so we can add the request type
  need to consider how to do this in jomresld */

  /*__beginres	System */

  //__
  //__		Security Error Messages	(1700 - 1750)
  //__
#define	SECURITY_VIOLATION							1700 /*Connection refused due to security violation*/
#define	SECURITY_INVALID_ID							1701 /*User id or password is invalid*/
#define	SECURITY_NON_ENCRYPTED_MSG					1702 /*Encryption enabled, but non encrypted RPC message received*/
#define	SECURITY_ENCRYPTED_MSG						1703 /*Encryption not enabled, but encrypted RPC message received*/
#define	SECURITY_CRC_CHECK_FAILED					1704 /*Cyclic redundancy check on encrypted message failed*/
#define	SECURITY_AUTH_INIT_FAILED					1705 /*Authentication enabled, but failed to initialize*/
#define	SECURITY_ENCRYPT_INIT_FAILED				1706 /*Encryption enabled, but failed to initialize*/
#define	SECURITY_ENCRYPTION_FAILED					1707 /*rpcEncryptMessage failed*/
#define	SECURITY_DECRYPTION_FAILED					1708 /*rpcDecryptMessage failed*/
#define SECURITY_DEV_MISSING_LIBRARY				1711 /*Development Security library not found*/
#define SECURITY_DEV_MISSING_ENTRY_POINT			1712 /*Development Security missing entry points*/
#define SECURITY_DEV_FAILED							1713 /*Development Security failed*/

/*__endres  */

/*__beginres	System */

//__
//__		Locale Management and Formatting Error Messages	(1800 - 1899)
//__
#define	DTNC_TEXT_INCOMPLETE						1800 /*The text is valid but incomplete */
#define	DTNC_VALUE_OVERFLOWS_TYPE					1801 /*The magnitude of the value exceeds the maximum value of the datatype*/
#define	DTNC_INVALID_CHARACTER						1802 /*Source character does not match the format rules*/
#define	DTNC_UNRECOGNISED_DIGIT						1803 /*Source character is not a recognised digit*/
#define	DTNC_TOO_MANY_WHOLE_DIGITS					1804 /*Too many significant digits before decimal point*/
#define	DTNC_TOO_MANY_FRACTION_DIGITS				1805 /*Too many significant digits after decimal point*/
#define	DTNC_EMPTY_SOURCE							1806 /*Source text is null or blank*/
#define	DTNC_FRAC_GTR_SIG_DIGITS					1807 /*Max fractional digits > max significant digits*/
#define	DTNC_EXPECTED_SIGN							1808 /*Expected sign*/
#define	DTNC_NEED_DIGIT_AFTER_GROUPSEP				1809 /*Group separator must be followed by a digit*/
#define	HPN_OVERFLOW								1810 /*HighPrecisionNumber overflowed*/
#define	HPN_INVALID_DIGIT							1811 /*HighPrecisionNumber received non-decimal value*/
#define	DTNC_DECIMAL_POINT_NOT_ALLOWED				1812 /*Decimal point not allowed*/
#define	DTNC_SIGN_NOT_ALLOWED						1813 /*Sign not allowed*/
#define	DTNC_TOO_MANY_SIGNIFICANT_DIGITS			1814 /*Too many significant digits in total*/
#define	DTNC_TEXT_NEEDS_ONE_DIGIT					1815 /*Text must contain at least one digit character*/
#define	DTNC_CURRENCY_POSITION_WRONG				1816 /*Currency symbol positioned incorrectly*/
#define	DTNC_INVALID_DAY_NUMBER						1817 /*Day number is out of range*/
#define	DTNC_INVALID_MONTH_NUMBER					1818 /*Month number is out of range*/
#define	DTNC_NEED_DIGIT_BEFORE_GROUPSEP				1819 /*Group separator must be preceded by at least one digit*/
#define	DTNC_MIXED_ASCII_AND_NATIVE_DIGITS			1820 /*Source text has mixed ASCII and native digits*/
#define	DTNC_DOES_NOT_MATCH							1821 /*Internal error*/
#define	DTNC_NATIVE_DIGITS_DISALLOWED				1822 /*Text limited to ASCII digits*/
#define	DTNC_MISSING_CLOSE_PARENTHESIS				1823 /*Text missing balancing closing parenthesis*/
#define	DTNC_SIGN_POSITION_WRONG					1824 /*Sign positioned incorrectly*/
#define	DTNC_MISSING_OPEN_PARENTHESIS				1825 /*Text has unbalanced closing parenthesis*/
#define	DTNC_DATE_ERAS_NYI							1826 /*Date eras (g format) not yet implemented*/
#define	DTNC_INVALID_SECONDARY_DAY					1827 /*Secondary day number does not match primary*/
#define	DTNC_INVALID_SECONDARY_MONTH				1828 /*Secondary month does not match primary*/
#define	DTNC_INVALID_YEAR_NUMBER					1829 /*Year number is out of range*/
#define	DTNC_INVALID_SECONDARY_YEAR					1830 /*Secondary year does not match primary*/
#define	DTNC_NON_GEORGIAN_NYI						1831 /*Internal error*/
#define	DTNC_DAY_VS_MONTH_VS_YEAR					1832 /*The day, month, year combination is invalid*/
#define	DTNC_WEEKDAY_VS_DATE						1833 /*The weekday name does not match the date*/
#define	DTNC_INVALID_SECONDARY_DAYNAME				1834 /*Secondary day name does not match primary*/
#define	DTNC_INVALID_DAY_NAME						1835 /*Not a recognised day name*/
#define	DTNC_INVALID_HOUR_NUMBER					1836 /*Hour number is out of range*/
#define	DTNC_INVALID_MINUTE_NUMBER					1837 /*Minute number is out of range*/
#define	DTNC_INVALID_SECOND_NUMBER					1838 /*Second number is out of range*/
#define	DTNC_INVALID_AMPM							1839 /*Unrecognised AM/PM designator*/
#define	DTNC_INVALID_MILLISECOND					1840 /*Fractional second is out of range*/
#define	DTNC_INVALID_SECONDARY_HOUR					1841 /*Secondary hour does not match primary*/
#define	DTNC_INVALID_SECONDARY_MINUTE				1842 /*Secondary minute does not match primary*/
#define	DTNC_INVALID_SECONDARY_SECOND				1843 /*Secondary second does not match primary*/
#define	DTNC_INVALID_SECONDARY_MILLISEC				1844 /*Secondary millisecond does not match primary*/
#define	DTNC_AMPM_VS_24HOUR							1845 /*AM/PM designator does not match hour number*/
#define	DTNC_INVALID_ERA_NAME						1846 /*Unrecognised era name*/
#define	DTNC_INVALID_SECONDARY_ERA					1847 /*Secondary era name does not match primary*/
#define	DTNC_MISSING_DAY_NUMBER						1848 /*Day number text is missing*/
#define	DTNC_MISSING_DAY_NAME						1849 /*Day name text is missing*/
#define	DTNC_MISSING_MONTH_NUMBER					1850 /*Month number text is missing*/
#define	DTNC_MISSING_MONTH_NAME						1851 /*Month name text is missing*/
#define	DTNC_MISSING_YEAR_NUMBER					1852 /*Year number text is missing*/
#define	DTNC_MISSING_HOUR_NUMBER					1853 /*Hour number text is missing*/
#define	DTNC_MISSING_MINUTE_NUMBER					1854 /*Minute number text is missing*/
#define	DTNC_MISSING_SECOND_NUMBER					1855 /*Second number text is missing*/
#define	DTNC_INVALID_MONTH_NAME						1856 /*Unrecognised month name*/
#define	DTNC_PARTIAL_MONTH_NAME						1857 /*Partially matched month name*/
#define	DTNC_PARTIAL_AMPM							1858 /*Partially matched AM/PM designator*/
#define	DTNC_PARTIAL_ERA							1859 /*Partially matched era name*/

#define	DTNC_REAL_CONVERSION_ERROR					1870 /*Error encountered converting Real to display text*/
#define	DTNC_SHORT_DATE_FORMATTING_ERROR			1871 /*Error encountered converting Date to short display text*/
#define	DTNC_LONG_DATE_FORMATTING_ERROR				1872 /*Error encountered converting Date to long display text*/
#define	DTNC_PARTIAL_MATCH							1873 /*Internal error*/


/*__endres  */

/*__beginres	Database   */

//__
//__		Database Engine Error Messages (3001 - 3199)
//__
#define DB_MIN_ERRORCODE							3000 /*INTERNAL*/
#define DB_MAX_ERRORCODE							3199 /*INTERNAL*/
#define DB_FILE_ALREADY_OPEN						3001 /*Cannot open a file that is already open*/
#define DB_FILE_NOT_OPEN		       				3002 /*Cannot use file - not open*/
#define DB_MAX_FILES_EXCEEDED	       				3003 /*Exceeded maximum allowed files for database*/
#define DB_FILE_UNMAPPED		       				3004 /*Required DB file not included in RPS database*/
#define DB_OBJECT_RESIZE_IN_REORG					3005 /*INTERNAL*/
#define DB_WRONG_LOG_FILE_FORMAT					3006 /*INTERNAL*/
// avail 3007 - 3008
#define DB_PARTITION_UNSPECIFIED					3009 /*File encrypted and partition unspecified*/
#define DB_INVALID_UPDATE_VERSION					3010 /*Update version for illegal object type*/
#define DB_INVALID_HANDLE              				3011 /*Invalid database handle*/
#define DB_NOT_IN_TRAN_STATE           				3012 /*Cannot update outside of transaction state*/
#define DB_FREE_SPACE_ERROR        					3013 /*An error was encountered by DB file free space management*/
#define DB_WRONG_LOG_FILE							3014 /*Transaction journal timestamp mismatch*/
#define	DB_ROLE_CHANGE_IN_PROGRESS					3015 /*Database role change in progress*/
#define DB_DUPLICATED_OID							3016 /*An object with the same OID already exists in the database*/
#define DB_TRANSACTION_IN_PROGRESS					3017 /*Operation not allowed while database transactions are in progress*/
#define DB_MEMORY_ERROR								3018 /*A database memory allocation request failed*/
#define DB_DIRECTORY_NOT_FOUND       				3019 /*Database control file directory not found*/
#define DB_FILE_ACCESS_DENIED 	       				3020 /*Access to a database file or directory denied*/
#define DB_FILE_OPEN_FAILED	       					3021 /*Open of a database file failed*/
#define DB_INCOMPATIBLE_FILE_FORMAT    				3022 /*Illegal attempt to open a file in an unsupported format*/
#define DB_FILE_REQUIRES_RECOVERY					3023 /*Database file requires recovery*/
#define DB_DUPLICATE_BTR		       				3024 /*Database duplicate begin transaction*/
#define DB_JOURNAL_DIRECTORY_INVALID 				3025 /*Database journal directory not valid on this machine*/
#define DB_MODE_CONFLICT               				3026 /*Database mode conflict*/
#define DB_USAGE_CONFLICT              				3027 /*Database usage conflict*/
#define DB_FILE_SHARING_VIOLATION      				3028 /*Database file is in use by another process*/
#define DB_AUDIT_ERROR                 				3029 /*Database audit error*/
#define DB_CF_VERSION_MISMATCH         				3030 /*Database control file version not supported*/
#define DB_CONTROL_FILE_MISSING        				3031 /*Database control file is required but was not found*/
#define DB_DUPLICATE_VERSIONINFO       				3032 /*Cannot create an object version that already exists*/
#define DB_DISK_FULL       							3033 /*A database write encountered an out of disk condition*/
#define DB_COMPACT_FAILED              				3034 /*File compaction terminated due to error*/
#define DB_CERTIFY_ERROR               				3035 /*Errors encountered certifying file*/
#define DB_FILE_NOT_FOUND		       				3036 /*The database file being opened is required but was not found*/
#define DB_NO_WRITE_ACCESS		       				3037 /*No write access to database file*/
#define DB_INVALID_OBJECT_TYPE	       				3038 /*Database object TYPE does not match requested type*/
#define DB_SIZE_MISMATCH             				3039 /*Schema to Database object size mismatch*/
#define DB_LOCKED_NO_AUDIT		       				3040 /*Database is locked due to crash while not audited*/
#define DB_CONTROL_FILE_ERROR	       				3041 /*Error accessing the Database control file*/
#define DB_CANT_DELETE_FILE		       				3042 /*Unable to delete file*/
#define DB_CANT_RENAME_FILE		       				3043 /*Unable to rename file*/
#define DB_NO_BACKUP			       				3044 /*Unable to find backup file (.BAK)*/
#define DB_DIRECTORY_INVALID 	      				3045 /*Database directory not valid*/
#define DB_REORG_FAILED                				3046 /*File reorganization terminated due to error*/
#define DB_REORG_INTERRUPTED	       				3047 /*A prior file reorganization was prematurely interrupted*/
#define DB_EDITION_INVALID		       				3048 /*Object edition invalid*/
#define DB_EDITION_OUT_OF_DATE	       				3049 /*Object edition out of date*/
#define DB_RECONSTRUCT_ERROR           				3050 /*File reconstruct failed*/
#define DB_USER_ABORT	             				3051 /*Operation aborted by user request*/
#define DB_NOT_INITIALISED             				3052 /*Database engine not initialized*/
#define DB_INVALID_FILENAME            				3053 /*Database File name not valid for file system*/
#define DB_INVALID_FILENUM            				3054 /*Cannot access invalid file number*/
#define DB_ALREADY_INITIALISED         				3055 /*Database already initialized*/
#define DB_FILE_CLOSE_ERROR							3056 /*Error encountered closing database file*/
#define DB_FILE_TIMESTAMP_MISMATCH					3057 /*Database file timestamp does not match control file*/
#define DB_INITIALISE_FAILED						3058 /*Database engine failed to start*/
#define DB_LOCKED_FOR_REORG							3059 /*Database is locked for reorganization*/
#define DB_FILE_EOF        							3060 /*Database read past the current end of file*/
#define DB_IO_ERROR        							3062 /*Unexpected I/O error encountered accessing database file*/
#define DB_NO_FILE_CONTROL_REC						3063 /*Database file control record was not found*/
#define DB_OBJECT_NOT_RESIDENT						3064 /*Object record not resident in cache*/
#define DB_LOG_SYNCH_EXCEPTION						3065 /*Record sequence exception in transaction journal*/
#define DB_PATH_CHANGED								3066 /*Database file not found in original directory [obsolete]*/
#define	DB_INVALID_DATABASE_ROLE					3067 /*Invalid database role*/
#define DB_INCOMPATIBLE_LOG_FORMAT     				3068 /*Transaction journal format not supported*/
#define	DB_REORG_ACTIVE								3069 /*The Database Reorg Manager is still active*/
#define DB_RECOVERY_COMPACT_DISC 					3070 /*Recovery across a file compaction is not currently possible [obsolete]*/
#define DB_FILE_EXISTS			 					3071 /*User disallowed replacing an existing database file*/
#define DB_LOCKED_EXCLUSIVE		       				3072 /*Database locked for exclusive access*/
#define DB_STATE_DISCONTINUITY						3073 /*Recovery across no audit usage is not possible*/
#define DB_FILE_PATH_NOT_FOUND       				3074 /*Database file directory was not found*/
#define DB_DIRTY_READ			       				3075 /*Cannot read object modified by a different user [obsolete]*/
#define DB_ILLEGAL_OBJECT_UPDATE       				3076 /*Illegal update of uncommitted object buffer*/
#define DB_QUIETPOINT_TIMEOUT						3077 /*Maximum time to wait for quiet point was exceeded*/
#define DB_BTREE_ERROR								3078 /*Unexpected error accessing btree*/
#define DB_LOCKED_FOR_ARCHIVE						3079 /*Database is locked for archive backup*/
#define DB_SCHEMA_NOT_READONLY						3080 /*Database was not initialized in read only schema mode*/
#define DB_USER_BUSY								3081 /*A re-entrant call was made for the same database user*/
#define DB_ILLEGAL_FILENAME_CHANGE					3082 /*Attempt to change the name or number of an existing database file*/
#define DB_ILLEGAL_SYSFILE_UPDATE					3083 /*Cannot update read only system file*/
#define DB_NOT_IN_BACKUP_STATE						3084 /*Cannot perform this operation when not in backup state*/
#define	DB_BTREE_OP_UNDO_FAILED						3085 /*Failed to undo BTree operation - state is not done*/
#define DB_SYSTEM_DIRECTORY_NOT_FOUND				3086 /*Database system file directory not found*/
#define DB_FILE_REQUIRES_CONVERSION					3087 /*Database file requires upgrading to 64-bit indexes [obsolete]*/
#define DB_UPGRADE_ERROR               				3088 /*Errors encountered upgrading file*/
#define DB_UPGRADE_NOT_REQUIRED        				3089 /*Database file doesn't require an upgrade*/
#define DB_UPGRADE_NOT_SUPPORTED       				3090 /*File upgrade from this version not supported*/
#define DB_ALREADY_IN_BACKUP_STATE					3091 /*Database is already in backup state*/
#define DB_INVALID_BACKUP_MODE						3092 /*Attempt to use invalid backup mode for a backup transaction*/
#define DB_CANNOT_CLOSE_LOG							3093 /*Cannot close transaction journal during an online backup*/
#define DB_RECOVERY_REQUIRED						3094 /*Cannot perform this operation when database requires recovery*/
#define DB_BACKUP_DIRECTORY_REQUIRED				3095 /*The backup directory parameter cannot be null for this operation*/
#define DB_OPERATION_INVALID_MODE					3096 /*The attempted database operation is not valid in its current mode*/
#define DB_WRONG_LOG_FILE_VERSION					3097 /*Transaction journal is not the correct edition*/
#define DB_FILE_CHECKSUM_ERROR						3098 /*A database file checksum error was encountered*/
#define DB_FILE_HEADER_ERROR						3099 /*Database file header record is invalid*/
#define DB_ILLEGAL_TRANSIENT_OID					3100 /*Illegal transient object reference sent to persistent DB*/
#define DB_ILLEGAL_PERSISTENT_OID					3101 /*Illegal persistent object reference sent to transient DB*/
#define DB_BACKUP_INVALID							3102 /*Database state not valid for roll-forward recovery*/
#define DB_CHARACTER_ENCODING_MISMATCH				3103 /*Database character set encoding not compatible with the software*/
#define DB_INCOMPATIBLE_PLATFORM					3104 /*Process opening database is running on an incompatible OS platform*/
#define DB_NON_LOCAL_DRIVE							3105 /*Non local drive not supported*/
#define DB_INVALID_FILE_ADDRESS						3106 /*Database file access at invalid address*/
#define DB_WRONG_RECORD_TYPE           				3107 /*Fetched record type doesn't match expected type*/
#define DB_WRONG_RECORD_LENGTH         				3108 /*Fetched record length doesn't match expected length*/
#define DB_OID_MISMATCH		         				3109 /*Fetched record OID doesn't match requested OID*/
#define DB_ROLLFORWARD_DATETIME_ERROR				3110 /*Roll-forward terminate date-time antedates audit trail*/
#define DB_SYSTEM_RESOURCE_ERROR					3111 /*Insufficient system resources*/
#define DB_AUDIT_SIZE_ERROR            				3112 /*Database transaction audit file has exceeded maximum size*/
#define DB_RECOVERY_ERROR            				3113 /*Database recovery not possible - fatal error encountered*/
#define DB_CHECKSUM_ERROR							3114 /*Checksum mismatch in fetched data*/
#define DB_REQUEST_BUFFER_TOO_SMALL					3115 /*GetObject request buffer too small*/
#define DB_FILE_LOCKED_FOR_REORG					3116 /*Database file is locked for reorganization*/
#define DB_INVALID_METHOD_CATEGORY					3117 /*Invalid database method category*/
#define	DB_INVALID_METHOD							3118 /*Database method not supported*/
#define DB_INVALID_CONTROL_ATTRIBUTE				3119 /*Invalid control file attribute*/
#define DB_FILE_NOT_DEFINED		       				3120 /*The database file is not defined in the control file*/
#define DB_FILE_NOT_CREATED		       				3121 /*The database file or file partition is not created*/
#define	DB_VALUE_RANGE_ERROR						3122 /*Parameter value is out of range*/
#define	DB_OBJECT_ACCESS_DISABLED					3123 /*Access to objects in this secondary database is currently disabled*/
#define	DB_BACKUP_INCOMPLETE						3124 /*Backup is incomplete or backupinfo corrupted*/
#define DB_JOURNAL_NOT_FOUND	       				3125 /*A required transaction journal was not found*/
#define DB_END_JOURNAL_ERROR						3126 /*Roll-forward terminate journal value is invalid*/
#define DB_OSM_ENTRY_NOT_FOUND						3127 /*Object State Manager: Entry not found*/
#define DB_SIZE_RESTRICTION_EXCEEDED				3128 /*Licensed database size exceeded*/
#define DB_CF_ALREADY_UPGRADED         				3129 /*Database control file does not require upgrade*/
#define DB_LOG_SYNCH_FAILURE						3130 /*Invalid record sequence data in transaction journal*/
#define DB_CLASS_VERSION_MISMATCH					3131 /*Class version of journal record does not match requested version*/
#define DB_BACKUP_FORMAT_UNSUPPORTED				3132 /*Backup format not supported with this release*/
#define DB_CLASS_NOT_DEFINED						3133 /*RDBI - need to define class to RDBMS*/
#define DB_SYSTEMFILE_VERSION_ERROR					3134 /*Inconsistent system file versions*/
#define DB_AUDIT_HEADER_EXCEPTION					3135 /*Null Audit header exception*/
#define DB_INVALID_OBJECT_INCARNATION				3136 /*INTERNAL invalid_object_incarnation*/
#define DB_BTREE_REDO_ERROR							3137 /*Error encountered Redoing a BTree operation*/
#define DB_BTREE_UNDO_ERROR							3138 /*Error encountered Undoing a BTree operation*/
#define DB_BLOCK_UNDO_ERROR							3139 /*Error encountered Undoing a block operation*/
#define DB_PARTITION_CONTROL_ERROR	  				3140 /*Error accessing a database partition control file*/
#define DB_FILE_NOT_PARTITIONED						3141 /*Partition operation not valid: file is not partitioned*/
#define DB_FILE_INSTANTIATED						3142 /*Cannot change the partitioned state of an instantiated file*/
#define DB_PARTITION_NOT_FOUND						3143 /*Database Partition not found*/
#define DB_PARTITION_OFFLINE						3144 /*Cannot access an offline file partition*/
#define DB_PARTITION_LOCKED							3145 /*Database partition is locked for admin*/
#define DB_PARTITION_RANGE_ERROR					3146 /*Partition ID or partition index is out of range - refer to jommsg.log*/
#define DB_PARTITION_REQUIRED						3147 /*Operation not valid: partition required for object creation*/
#define DB_REORG_BTREE_FASTBUILD_PARAM				3148 /*Reorganization collection FastBuild invalid parameter*/
#define DB_REORG_BTREE_FASTBUILD_IOERROR			3149 /*Reorganization collection FastBuild I/O error*/
#define DB_REORG_BTREE_FASTBUILD_ASSERT				3150 /*Reorganization collection FastBuild assert failed*/
#define DB_REORG_BTREE_FASTBUILD_CONSTRUCT			3151 /*Reorganization collection FastBuild construction error*/

// avail 3152

#define DB_FILE_INVALID_RECORD_SIZE					3153 /*Invalid record size for database file*/
#define DB_FILE_INVALID_BUFFER_SIZE					3154 /*Invalid buffer size for database file*/
#define DB_FILE_IO_MODE_CONFLICT					3155 /*Read/write operation conflicts with file mode*/
#define DB_IN_BACKUP_STATE							3156 /*Cannot perform this operation when in backup state*/
#define DB_REORG_PREDECESSOR_JOB_FAILED				3157 /*Predecessor reorg job was unsuccessful*/
#define DB_PARTITION_METHOD_EXECUTION_FAILED		3158 /*Partition method execution failed*/
#define DB_PARTITION_NOT_ASSIGNED					3159 /*Partition not assigned*/
#define DB_SINGLE_UDR_PARTITION_NOT_ASSIGNED		3160 /*Partition for parent of single file UDR has not been assigned*/
#define DB_PARTITION_MODULUS_RANGE_ERROR			3161 /*Partition modulus cannot be set to a value outside the range of 1 to 1024*/
#define DB_FILE_OFFLINE								3162 /*Cannot access an offline database file*/
#define DB_FILE_PARTITIONED							3163 /*Cannot perform this operation on a partitioned database file*/
#define DB_REORG_MUTATE_WITHOUT_MAPPINGS			3164 /*Reorganization has no map entries for class mutate*/
#define DB_PARTITION_ONLINE							3165 /*Operation not valid for an online partition*/
#define DB_PARTITION_FROZEN							3166 /*Creation window cannot include frozen partitions*/
#define DB_PARTITION_NOT_EMPTY						3167 /*Cannot perform this operation on a non-empty partition*/
#define DB_REORG_BTREE_FASTBUILD_REPLAY				3168 /*Reorganization collection FastBuild replay error*/
#define DB_RB_STACK_BOUNDS_EXCEEDED					3169 /*Rollback stack boundary error*/
#define DB_LOCKED_FOR_ROLLBACK						3170 /*Database is locked for rollback*/
#define DB_DELTADB_ID_MISMATCH						3171 /*Delta database ID mismatch*/
#define DB_ILLEGAL_IN_DELTAMODE						3172 /*Operation not permitted when database is in delta mode*/
#define DB_FILE_NOT_BACKED_UP						3173 /*File not backed up*/
#define DB_MAKEBACKUPINFO_TIMESTAMP_ERROR			3174 /*Base backupinfo is newer than delta backupinfo*/
#define DB_MAKEBACKUPINFO_PARTITIONING_MISMATCH		3175 /*Partitioned status of file differs in base and delta backupinfo files*/
#define DB_MAKEBACKUPINFO_BASE_NOT_FULL_BACKUP		3176 /*Base backupinfo is not full backup*/
#define DB_INVALID_BLOCK_TYPE						3177 /*Fetched block type does not match expected type*/
#define DB_FILE_INIT_INCOMPLETE						3178 /*File unusable - initialisation incomplete*/
#define DB_FILE_REQUIRES_ENCRYPTION					3179 /*The file must be created as an encrypted file*/
#define DB_FILE_LOCKED								3180 /*Operation not permitted on this file*/
#define DB_INCOMPLETE_JOURNAL						3181 /*Attempt to replay incomplete journal*/
#define DB_RAWUDR_IS_READONLY						3182 /*SingleFile JadeBytes file is ReadOnly*/
#define DB_INIFILE_INVALID							3183 /*Database INI file is missing or invalid*/

#define DB_REORG_DUALUPDATE_FAILED 	  	  		    3184 /*A dual update failed during an online reorganization. It must be aborted*/
#define DB_REORG_SAVE_RESTARTSTATE_FAILED			3185 /*Updating the reorg restart state from the database failed*/

#define DB_PARTITION_PURGING						3186 /*Operation not valid: partition being purged or dropped*/
#define DB_PARTITION_ALREADY_SET					3187 /*Object buffer partition may only be set during create*/
#define DB_RETRY_OPERATION							3188 /*Internal use only*/
#define DB_ILLEGAL_WHEN_DB_UNAUDITED				3189 /*Operation not permitted when database has files or partitions with unaudited=true*/
#define DB_ILLEGAL_WHEN_FILE_UNAUDITED				3190 /*Operation not permitted on file or partition with unaudited=true*/
#define DB_LOCKED_FOR_SNAPSHOT						3191 /*Database is locked for snapshot backup*/
#define DB_EARLY_SNAPSHOT_RECOVERY_TERMINATION		3192 /*Snapshot recovery terminated before end-snapshot condition established*/
#define DB_ROLLFORWARD_SERIALNUMBER_ERROR			3193 /*Roll-forward terminate serial number is earlier than audit trail*/
#define DB_ROLLFORWARD_BACKUP_RECOVERY_CONFLICT		3194 /*Roll-forward terminate before backup recovery complete*/
#define DB_CLASS_NOT_VALID_FOR_FILE					3195 /*Class not valid for file*/

//__
//__		Synchronised Database Service Error Messages
//__
#define SDS_INCOMPLETE_JOURNAL						3200 /*SDS Attempt to replay incomplete journal*/
#define	SDS_NOT_INITIALIZED							3201 /*SDS not initialized*/
#define	SDS_MISSING_NAME							3202 /*SDS MyName parameter not found in INI file*/
#define	SDS_MISSING_PRIMARY_NAME					3203 /*SDS PrimaryServerName parameter not found in INI file*/
#define	SDS_SECONDARY_NOT_ATTACHED					3204 /*SDS secondary not attached*/
#define	SDS_INVALID_COMMAND							3205 /*SDS invalid command*/
#define SDS_ILLEGAL_ON_SECONDARY					3206 /*Operation not permitted on a secondary database*/
#define SDS_ILLEGAL_ON_PRIMARY						3207 /*Operation not permitted on a primary database*/
#define	SDS_SECONDARY_NOT_FOUND						3208 /*SDS named secondary server not found*/
#define	SDS_TAKEOVER_FAILED							3209 /*SDS takeover operation failed*/
#define	SDS_MAX_SECONDARIES_EXCEEDED				3210 /*SDS maximum secondary servers exceeded*/
#define	SDS_TRACKER_BUSY							3211 /*SDS tracker thread is busy*/
#define SDS_RESPONSE_TIMEOUT						3212 /*SDS a response was not received within a reasonable timeframe*/
#define SDS_REORG_INVALIDATES_BACKUP				3213 /*SDS backup terminated by replay of reorg or compact*/
#define SDS_LEGAL_ONLY_ON_SECONDARY					3214 /*Operation only permitted on a secondary database*/
#define SDS_TRANSACTION_NOT_FOUND					3215 /*SDS Transaction not found or already committed*/
#define SDS_INVALID_TRAN_STATUS						3216 /*SDS Transaction status not valid*/
#define SDS_UPGRADE_VERSION_MISMATCH				3217 /*SDS Upgrade version mismatch*/
#define	SDS_NAME_CONFLICT							3218 /*SDS secondary server name conflict*/
#define SDS_SECONDARY_SINGLE_USER_NOT_ALLOWED		3219 /*Cannot run SDS secondary server in SingleUser*/
#define	SDS_PRIMARY_CONNECTED						3220 /*Operation not permitted when primary is connected*/
#define	SDS_PRIMARY_NOT_CONNECTED					3221 /*SDS primary not connected*/
//__
//__		Relational Population Service Error Messages
//__
#define	RPS_NOT_INITIALIZED							3250 /*RPS not initialized*/
#define	RPS_NOT_SUPPORTED							3251 /*RPS operation not supported*/
#define RPS_INTERNAL_ERROR							3252 /*RPS Internal Error*/
#define RPS_MAPPING_MISMATCH						3253 /*RPS Mapping mismatch with Target Relational DB*/
#define	RPS_RELATIONALDB_ERROR						3254 /*RPS Target Relational DB - SQL operation failed*/
#define RPS_INSTANCEID_MISMATCH						3255 /*RPS instance ID mismatch with Target Relational DB*/
#define RPS_STATE_MISMATCH							3256 /*RPS DB state is later than Target Relational DB*/
#define RPS_DB_NOT_OPEN								3257 /*RPS Target Relational DB not opened by this application*/
#define RPS_DUPLICATED_KEY							3258 /*RPS Insert row failed due to a duplicated key*/
#define RPS_ZEROROWS_AFFECTED						3259 /*RPS SQL update failed - zero rows updated or deleted*/
#define RPS_MULTIROWS_AFFECTED						3260 /*RPS SQL update failed - multiple rows updated or deleted*/
#define RPS_INVALID_STORAGEMODE						3261 /*RPS Invalid storage mode*/
#define RPS_ADMIN_HALT								3262 /*RPS Reorg admin halt required*/
#define RPS_DB_OPEN_FAILED							3263 /*RPS Failed to open target Relational DB*/
#define RPS_LEGAL_ONLY_ON_RPS						3264 /*Operation only permitted on RPS node*/
#define RPS_DATAPUMP_ALREADY_RUNNING				3265 /*RPS DataPump Application already running*/
#define RPS_NOT_DATAPUMP_APP						3266 /*Application not defined as DataPump Application in ini file*/
//#define RPS_NOT_INIT_AS_DATAPUMP_APP				3267 /*Application not initialized as DataPump Application*/
#define RPS_DATAPUMP_NOT_RUNNING					3268 /*RPS DataPump application not running*/
#define RPS_EXTRACT_REQUEST_ERROR					3269 /*RPS Extract Request Error*/
#define RPS_DB_ALREADY_OPEN							3270 /*RPS Relational DB already opened by this application*/
#define RPS_DB_OPEN_OTHER_APP						3271 /*RPS Relational DB already opened by another application*/
#define RPS_VALID_ONLY_FOR_RPSMAP					3272 /*Operation is only permitted on RPS Mapping*/
#define RPS_TABLENAME_NOT_FOUND						3273 /*RPS Table name not found in RPS Mapping*/
#define RPS_RELATIONALDB_CONNECTION_ERROR			3274 /*RPS Target Relational DB - SQL operation connection failure*/
#define RPS_OIDINSTANCEID_VALUE_TOO_LARGE			3275 /*RPS Oid InstanceId value is too large for Oid Mapping Option*/
#define RPS_OIDCLASSNUMBER_VALUE_TOO_LARGE			3276 /*RPS Oid ClassNumber value is too large for Oid Mapping Option*/
#define RPS_CANNOT_INITIALISE_FROM_UPDATING_BACKUP	3277 /*Cannot create an RPS node from a standard updating backup*/
#define RPS_CANNOT_INITIALISE_FROM_RECOVERY			3278 /*Cannot change role to RPS when database requires recovery*/

//__
//__		Database Encryption Error Messages (3301 - 3399)
//__
#define DBCRYPT_ENCRYPTION_NOT_SUPPORTED			3301 /*Database encryption is not supported on this platform*/
#define DBCRYPT_CANNOT_DISABLE_ENCRYPTION			3302 /*Database encryption cannot be disabled until all files have been decrypted*/
#define DBCRYPT_ENCRYPTION_DISABLED					3303 /*Database encryption has not been enabled*/
#define DBCRYPT_DENY_FILE_ENCRYPT					3304 /*Database system files cannot be encrypted*/
#define DBCRYPT_NOTHING_TO_APPLY					3305 /*Database has no files with pending encryption changes*/

#define DBCRYPT_MODULE_UNUSABLE						3321 /*DbCrypt module uninitialised or terminating*/
#define DBCRYPT_INTERNAL_STATE_ERROR				3322 /*DbCrypt internal error*/
#define DBCRYPT_NO_MEMORY							3323 /*DbCrypt memory allocation failure*/
#define DBCRYPT_CALLBACK_MISMATCH					3324 /*DbCrypt DB callback table version mismatch*/
#define DBCRYPT_CALLBACK_HANDLE_ERR					3325 /*DbCrypt internal error*/
#define DBCRYPT_WINCRYPT_ERROR						3326 /*Windows Cryptography error. See jommsg.log*/
#define DBCRYPT_CRYPTINFO_ERROR						3327 /*Database cryptInfo error. See jommsg.log*/
#define DBCRYPT_OBJECT_STILL_ENCRYPTED				3328 /*DbCrypt failed to decrypt object*/
#define DBCRYPT_TESTER								3329 /*DbCrypt internal error*/
#define DBCRYPT_PRECONDITION						3330 /*DbCrypt internal error*/
#define DBCRYPT_DECRYPT_LOST_CONFIDENCE				3331 /*DbCrypt decryption failure*/
#define DBCRYPT_OBJECT_NOT_ENCRYPTED				3332 /*Object is not encrypted*/
#define DBCRYPT_FILE_IS_DATABASE_ISNT				3333 /*File is marked encrypted but database has encryption disabled*/
#define DBCRYPT_REMOTE_ERROR						3334 /*DbCrypt internal error*/
#define DBCRYPT_REORG_NEEDS_INIT					3335 /*DbCrypt internal error*/
#define DBCRYPT_REORG_LOAD_DUP_FILE					3336 /*DbCrypt internal error*/
#define DBCRYPT_REORG_FILE_NOT_LOADED				3337 /*DbCrypt internal error*/
#define DBCRYPT_REORG_LOAD_DUP_PARTITION			3338 /*DbCrypt internal error*/
#define DBCRYPT_REORG_PARTITION_NOT_LOADED			3339 /*DbCrypt internal error*/
#define DBCRYPT_REORG_NYI							3340 /*DbCrypt internal error*/
#define DBCRYPT_DECRYPT_SIZE_MISMATCH				3341 /*DbCrypt decrypted object size does not match expected size*/
#define DBCRYPT_APPLY_PENDING_ERROR					3342 /*DbCrypt internal error*/
#define DBCRYPT_FILE_NULLCRYPTION					3343 /*DbCrypt internal error*/
#define DBCRYPT_MASTER_KEY_MISSING					3344 /*DbCrypt Master Key not present in account key store*/
#define DBCRYPT_MANDATORYFULLENCRYPTION_VS_CREATE	3345 /*DbCrypt Cannot create user objects in unencrypted files*/
#define DBCRYPT_MPC_FILE_NOT_LOADED					3346 /*DbCrypt internal error*/
#define DBCRYPT_REORG_PARTITION_PLAINTEXT			3347 /*DbCrypt internal error*/
#define DBCRYPT_FILE_CRYPT_STATE_UNKNOWN			3348 /*DbCrypt file crypt status is unknown*/
#define DBCRYPT_DELTA_MODE_NOT_SUPPORTED			3349 /*Delta mode cannot be activated when database encryption is enabled*/
#define DBCRYPT_ENCRYPT_EDITION_ZERO				3350 /*DbCrypt cannot encrypt object edition zero*/
#define DBCRYPT_INVALID_CTXHANDLE					3352 /*Invalid context handle passed to DbCrypt module*/
#define DBCRYPT_OBJECT_ENCRYPTED_FILE_ISNT			3353 /*Attempt to store encrypted object in unencrypted file*/
//__
//__		Database Reorganisation Error Messages
//__
#define REORG_INVALID_INSTANCES 					3400 /*Unable to reorganize class: refer to JOMREORG.LOG*/
#define REORG_MEMORY_ERROR     						3401 /*Out of memory*/
#define REORG_IO_ERROR								3402 /*Unable to create temporary reorganization mapping file [obsolete]*/
#define REORG_NO_MAP_FILE							3403 /*Reorg map file not created*/
#define REORG_USER_CANCELLED           				3404 /*Reorg operation cancelled by user request*/
#define REORG_CLASS_IN_USE							3405 /*Class is in use by another process*/
#define REORG_CONSTRAINT_NOT_COMPILED				3406 /*Constraint is not compiled*/
#define REORG_RESTART_DATA_EXISTS					3407 /*An incomplete reorg must be either restarted or aborted*/
#define REORG_FAILED								3408 /*Database reorganization failed*/
#define REORG_INVALID_SYSTEM_SCHEMA					3409 /*Database reorganization of system schema disallowed*/
#define REORG_UPGRADE_DISSALLOWED					3410 /*Unicode database cannot be reorganized for upgrade [obsolete]*/
#define REORG_ON_SECONDARY_DISSALLOWED				3411 /*Database reorganized cannot be initiated from a Secondary Server*/
#define REORG_RESTART_LOAD							3412 /*Previous incomplete schema load must be restarted*/
#define REORG_WAIT_FOR_TRANSITION					3413 /*Reorg is suspended waiting for the transition to be initiated*/
#define REORG_RESTART_FAILED						3414 /*Reorg cannot be restarted, reorg must be aborted*/
#define REORG_UNVERSION_FAILED						3415 /*Schema cannot be unversioned, dependent schemas exist*/
#define REORG_SCHEMA_COMPILE_IN_PROGRESS			3416 /*Reorg cannot be initiated when a schema compile is in progress*/
#define REORG_TRANSITION_SINGLE_USER				3417 /*Transition must be initiated in singleuser if production mode is set*/
#define REORG_IN_PROGRESS							3418 /*Database reorganization in progress*/
#define REORG_UNVERSION_FAILED_LOAD					3419 /*Schema cannot be unversioned after onlyStructuralVersioning load */
#define REORG_RPS_PRIMARY_EXTRACT_FAILED			3420 /*RPS reorg extract on primary failed */
#define REORG_AUX_NODE_UNCONFIGURED					3421 /*Reorg auxiliary server node has not been configured */
#define REORG_AUX_NODE_UNINITIALISED				3422 /*Reorg auxiliary server node has not been initialised */
#define REORG_AUX_NODE_ERROR						3423 /*Reorg auxiliary server node error*/
#define REORG_FASTBUILD_KEYPATH_ERROR				3424 /*Reorg error chasing keypath for fastbuild extract*/
#define REORG_FASTBUILD_DUPLICATE_KEY				3425 /*Reorg collection FastBuild found duplicate key entry*/
#define REORG_RESTART_REQUIRES_REORG_JOURNAL		3426 /*Reorg restart requires reorgJournal - restore it or abort the reorg*/
#define REORG_JOURNAL_CORRUPT						3427 /*Reorg journal is corrupt - abort the reorg*/

#define REORG_CARETAKER_ERROR						3428 /*An error occurred in a database reorg caretaker operation*/



/*__endres  */

/*__beginres	DbServer   */
//__
//__	 	Server Remote Interface Error Messages
//__
#define SR_MAX_CONNS_EXCEEDED	       				3500 /*Exceeded server maximum connections*/
#define SR_INVALID_CONNTYPE	       					3501 /*Invalid server connection type*/
#define SR_INVALID_HANDLE              				3502 /*Incorrect handle returned in response*/
#define	SR_CALLBACK_NOT_SUPPORTED					3503 /*Callback connection not supported for this network type*/
#define	SR_REMOTE_DISCONNECTED						3504 /*Remote node disconnected*/
#define	SR_FATAL_NETWORK_ERROR						3505 /*Fatal network error*/
#define	SR_RPC_VERSION_MISMATCH						3506 /*Remote Procedure Call version mismatch*/
#define	SR_CHDD_REGISTRATION_FAILURE				3507 /*Client HostData registration failure*/
#define	SR_SHDD_REGISTRATION_FAILURE				3508 /*Server HostData registration failure*/
#define	SR_MAX_CALL_LEVEL_EXCEEDED					3509 /*RPC maximum callLevel exceeded*/
#define	SR_INVALID_NET_SPECIFICATION				3510 /*Invalid network specification*/
#define	SR_REQUEST_BUFFER_TOO_SMALL					3511 /*Buffer too small to complete request*/
#define SR_AUTOUPGRADE_VERSION_MISMATCH				3512 /*Automated upgrade version mismatch*/
#define	SR_JDI_VERSION_MISMATCH						3513 /*Jade Data Interchange version mismatch*/
#define	SR_DISTMGMT_VERSION_MISMATCH				3514 /*Distributed Management version mismatch*/
#define	SR_FILESERVER_STARTED						3515 /*Distributed Management FileServer was started on this connection*/
#define	SR_DUAL_TCP_ESTABLISHED						3516 /*Dual TCP connection established*/
#define	SR_MNGMNT_REPLY_TRUNCATED					3517 /*Reply to management request truncated*/
#define	SR_REMOTE_MNGMNT_RQST_FAILURE				3518 /*Remote management request failed*/
#define	SR_LARGE_BUFFER_ALLOC_FAILURE				3519 /*Large request buffer allocation failed*/
#define SR_INTRA_PROCESS_RQST_FAILURE				3520 /*Remote intra process request failed*/
#define SR_CONNECTION_NOT_LISTENING					3521 /*Internal error*/
#define SR_RPC_INVALID_CTXHANDLE					3522 /*Invalid context handle passed to RPC*/
#define SR_CONNECTION_NOT_CONNECTED					3523 /*Internal error*/
#define SR_INVALID_SERVER_URI						3524 /*Invalid server URI*/
#define SR_INVALID_ENVIRONSERVER_IDENTITY			3525 /*Invalid environment/server identity*/
#define SR_WRONG_ENVIRONSERVER_IDENTITY				3526 /*Environment/server identity mismatch*/
#define SSPIAUTH_MODULE_UNUSABLE					3570 /*SSPIAuth Internal error*/
#define SSPIAUTH_NO_MEMORY							3571 /*SSPIAuth memory allocation failure*/
#define SSPIAUTH_NO_STATE							3572 /*SSPIAuth state storage not allocated*/
#define SSPIAUTH_SSPI_ERROR							3573 /*SSPIAuth SSPI error. See jommsg.log*/
#define SSPIAUTH_SPN_MISSING						3574 /*INI entry [Client] SspiAuthServicePrincipalName is required*/
#define SSPIAUTH_SECPKG_MISSING_CAPS				3575 /*SSPIAuth securityPackage does not support required capabilities*/
#define SSPIAUTH_AUTHORIZATION_FAILURE				3576 /*SSPIAuth client node access could not be authorized*/
#define SSPIAUTH_CRYPT_BUFFER_OVERFLOW				3577 /*SSPIAuth Internal error*/
#define SSPIAUTH_ENCRYPTION_ERROR					3578 /*SSPIAuth encryption error*/
#define SSPIAUTH_DECRYPTION_ERROR					3579 /*SSPIAuth decryption error*/

/*__beginres	RDBI   */
//__
//__	 	Relational Database Interface Error Messages
//__
#define	RDBI_MISSING_INI_PARAM						3800 /*RDBI initialization parameter missing*/
#define RDBI_CLASS_NOT_DEFINED						3801 /*RDBI class not defined*/
/*__endres  */

/* RANGE 4000-4999 reserved for interpreter see intperrs.h */

/*__endres  */

/*__beginres	File   */
//__
//__	 	File Handling Error Messages
//__
#define F_FILE_OPEN_FAILED	     					5001 /*Cannot open file*/
#define F_FILE_ACCESS_DENIED	   					5002 /*Requested access to file not permitted*/
#define F_FILE_NOT_FOUND	       					5003 /*Requested file not found*/
#define F_READ_INCOMPLETE	      					5004 /*File read operation incomplete*/
#define F_WRITE_INCOMPLETE	     					5005 /*File write operation incomplete*/
#define F_SEEK_FAILED			  					5006 /*Cannot set file pointer*/
#define F_FILE_NOT_OPEN	        					5007 /*Required file is not currently open*/
#define F_FILE_REPLACE_DENIED	  					5008 /*Cannot overwrite existing file*/
#define F_END_OF_FILE								5009 /*Cannot read past the end of file*/
#define F_IO_MODE_CONFLICT	     					5010 /*Read/write operation conflicts with file mode*/
#define F_READ_TOO_BIG								5011 /*Record truncated to maxRecordSize characters*/
#define F_UNICODE_TO_ANSI_FAILED					5012 /*Unicode to Ansi conversion failed*/
#define F_ANSI_TO_UNICODE_FAILED					5013 /*Ansi to Unicode conversion failed*/
#define F_RENAME_TO_DIFFERENT_DEV					5014 /*Cannot rename a file to a different device*/
#define F_RENAME_FAILED								5015 /*Attempt to rename a file failed*/
#define F_DELETE_FAILED								5016 /*Attempt to delete a file failed*/
#define F_BINARY_READ_ON_TEXT_FILE					5017 /*Cannot perform a binary read on a file opened as text*/
#define F_BINARY_WRITE_ON_TEXT_FILE 				5018 /*Cannot perform a binary write on a file opened as text*/
#define F_TEXT_READ_ON_BINARY_FILE  				5019 /*Cannot perform a string read on a file opened as binary*/
#define F_TEXT_WRITE_ON_BINARY_FILE 				5020 /*Cannot perform a string write on a file opened as binary*/
#define F_INVALID_FILE_KIND							5021 /*Cannot open a file with an invalid kind property*/
#define F_NOT_UNICODE_ODD_BYTES						5022 /*File cannot be opened as Unicode as it contains an odd number of bytes*/
#define F_CREATE_DIRECTORY_FAILED 					5023 /*Directory with the specified name could not be created*/
#define F_DIRECTORY_NOT_FOUND						5024 /*Requested file directory was not found*/
#define F_DIRECTORY_REMOVE_FAILED					5025 /*Specified directory could not be removed*/
#define F_FILE_ALREADY_OPEN	     					5026 /*File already open*/
#define F_DIRECTORY_INVALID							5027 /*Requested file directory name is not valid*/
#define F_FILE_PATH_NOT_FOUND       				5028 /*Requested file directory not found*/
#define F_INVALID_FILENAME            				5029 /*File name not valid for file system*/
#define F_FILE_SHARING_VIOLATION      				5030 /*File is in use by another process*/
#define F_OUT_OF_DISK      							5031 /*A file write encountered an out of disk condition*/
#define F_FILE_CLOSE_ERROR							5032 /*Error encountered closing file*/
#define F_IO_ERROR        							5033 /*An unexpected I/O error occurred accessing file*/
#define F_COPY_FAILED								5034 /*Attempt to copy a file failed*/
#define F_IO_NODE_MISMATCH							5035 /*Cannot access a file opened by a different Node*/
#define F_FILE_KIND_MISMATCH						5036 /*Cannot open file, the kind property is different to actual file kind*/
#define F_FILE_KIND_UTF32_UNSUPPORTED				5037 /*Unicode UTF32 file kinds not supported[obsolete]*/
#define F_ILLEGAL_UTF8_BYTE_SEQUENCE				5038 /*Unicode UTF8 file contains illegal byte sequence*/
#define F_FILE_KIND_UTF8_UNSUPPORTED				5039 /*Unicode UTF8 file kind not supported*/
#define F_SYSTEM_RESOURCE_ERROR						5040 /*Insufficient system resources*/
#define F_NONPAGED_RESOURCE_ERROR					5041 /*Insufficient non-paged system resources [obsolete]*/
#define F_PAGED_RESOURCE_ERROR						5042 /*Insufficient paged system resources [obsolete]*/
#define F_WORKING_SET_QUOTA_ERROR					5043 /*Insufficient working set quota [obsolete]*/
#define F_COMMITMENT_LIMIT_ERROR					5044 /*Insufficient page file resources [obsolete]*/
#define F_BROKEN_SYMLINK							5045 /*Broken symbolic link*/
#define F_FILE_IS_OPEN								5046 /*File is currently open*/
#define F_INVALID_RECORD_SIZE						5047 /*Invalid record size*/
#define F_INVALID_BUFFER_SIZE						5048 /*Invalid buffer size*/

/*__endres  */

/*__beginres	MultiMedia   */

//__
//__	 	Multi-Media Handling Error Messages
//__
#define MM_MEDIAFILE_ERROR							5101 /*Error accessing multimedia file*/
#define MM_MEDIADEVICE_ERROR 						5102 /*Error accessing multimedia device*/

/*__endres  */

/*__beginres	System   */

#define OUT_OF_RESOURCE								5200 /*Out of resources for operation*/
#define	THREAD_ALLOC_FAILED							5201 /*Thread allocation failed*/
#define	THREAD_START_FAILED							5202 /*Thread start failed*/
#define	THREAD_CREATE_FAILED						5203 /*Thread create failed*/

/*__endres  */

/*__beginres	SortActor   */

//__
//__	 	SORT Handling Error Messages
//__
#define SORT_FILE_NOT_OPEN							5301 /*Sort target file not present*/
#define SORT_CREATE_TEMP_FILE_FAILED 				5302 /*Sort temporary file not created*/
#define SORT_TEMP_FILE_WRITE_FAILED					5303 /*Sort temporary file write failed*/
#define SORT_TEMP_FILE_CLOSE_FAILED					5304 /*Sort temporary file close failed*/
#define SORT_NEGATIVE_OFFSET						5305 /*Sort negative offsets not allowed*/
#define SORT_NEGATIVE_FIELDNO						5306 /*Sort negative offsets not allowed*/
#define SORT_ONLY_ONE_RECORD						5307 /*Only one record found in the sort file buffer*/
#define SORT_COPY_TEMP_PATH_FAILED					5308 /*Call to GetTempPath failed in JomSort*/
#define SORT_COPY_TEMP_FILE_FAILED					5309 /*Call to GetTempFileName failed in JomSort*/
#define SORT_BUFFER_ALLOCATION_FAILED 				5310 /*Cannot set the IO Buffer*/
#define SORT_MMIO_GETINFO_FAILED					5311 /*Cannot access File IO*/
#define SORT_MMIO_ADVBUF_FAILED						5312 /*IO block failed to advance*/
#define SORT_UNICODE_NOT_SUPPORTED					5313 /*UNICODE is not currently supported with extractSort*/
#define SORT_MOVED_SORTED_FILE						5314 /*Move sorted file to output failed*/
#define SORT_SORTACTORARRAY_INVALID					5315 /*Cannot use SortActorArray without any elements*/
#define SORT_NUMERIC_OVERFLOW						5316 /*Overflow or underflow of a numeric sort field*/
#define SORT_APPSERVER_ONLY							5317 /*Sort input/output files must be on appServer*/
#define SORT_FILE_LENGTH_ERROR						5318 /*Sort input file must be multiple of recordsize*/
#define SORT_MISSING_EOL							5319 /*Last record missing end-of-line delimiter*/
#define SORT_BAD_INPUT								5320 /*Unable to process all input in the file*/

/*__endres  */

/*__beginres	System   */
//__
//__	 	License Error Messages
//__
#define REGISTERCOY_INVALID 						5500 /*Registered license name is invalid*/
#define CHECKSUM_INVALID 							5501 /*License key is invalid*/
#define SERIAL_INCOMPLETE 							5502 /*License key is incomplete*/
#define DEVELOPMENT_LICENSES_EXCEEDED				5503 /*You have exceeded the number of Development Licenses*/
#define PROCESS_LICENSES_EXCEEDED					5504 /*You have exceeded the number of Process Licenses*/
#define UNREGISTERED_COPY 							5505 /*This is an unregistered copy*/
#define EXPIRYDATE_EXPIRED 							5506 /*The expiry date of this copy has passed*/
#define PRIMARY_LICENSE_REQUIRED					5507 /*A Primary Database license key is required for installation*/
#define JUICEOPTION_NOT_LICENSED					5508 /*The Juice Option is not currently licensed [obsolete]*/
#define REPWRTROPTION_NOT_LICENSED					5509 /*The ReportWriter Option is not currently licensed [obsolete]*/
#define RESTRICT_KEY_NOT_VALID						5510 /*Free Developer License cannot be used to register this system*/
#define RESTRICT_VER_NOUPDATE						5511 /*Updating the license information for a restricted release is not permitted [obsolete]*/
#define REGISTER_GENERAL							5512 /*An unknown error occurred while trying to register the database*/
#define REGISTER_INVALIDPARAMETER					5513 /*One or more of the parameters specified was invalid*/
#define JADEVERSION_INVALID							5517 /*License does not match version of Jade*/
#define RESTRICTION_NOT_COMPACT__LICENCE			5518 /*Non-compact license can not be used on compact device*/
#define RESTRICTION_COMPACT_LICENCE					5519 /*Compact license can not be used on non-compact device*/
#define INVALID_LICENCE_TYPE						5520 /*Invalid License Type*/
#define EXCEEDED_MAXIMUM_CPU_SOCKETS				5521 /*Number of CPU sockets exceeds the maximum allowed by the license*/
#define JOOB_LICENCE_REQUIRED						5522 /*A JOOB license key is required for installation*/
#define INVALID_KEY_FILE							5523 /*The specified license key file is invalid*/
#define KEY_FILE_ACCESS_ERROR						5524 /*Could not access the specified license key file*/
/*__endres  */

/*__beginres	System   */
//__
//__	 	Jom Data Interchange Error Messages
//__
#define	JDI_REGISTRATION_NOMEM						5700 /*No memory for Object Description*/
#define JDI_INVALID_CLASSID 						5701 /*Jom DataInterchange Invalid ClassId*/
#define JDI_INVALID_HOST_HANDLE 					5702 /*Jom DataInterchange Invalid Host Description Handle*/
#define JDI_INVALID_DATA_HANDLE 					5703 /*Jom DataInterchange Invalid Data Description Handle*/
#define JDI_INVALID_ARRAY_CONVERT					5704 /*Jom DataInterchange not array definition*/
#define JDI_CONVERSION_FAILURE						5705 /*Jom DataInterchange generic conversion error, see jommsg.log*/
#define JDI_UNICODE_TRANSLATION_FAILED				5706 /*Jom DataInterchange Invalid codepage translation*/
#define JDI_STRING_RESIZE_SMALLER					5707 /*Jom DataInterchange String size decreased*/
#define JDI_STRING_RESIZE_LARGER					5708 /*Jom DataInterchange String buffer too small*/
#define JDI_STRING_TRUNC_AND_TRANSLAT				5709 /*Jom DataInterchange Object has multiple problems with strings*/
#define JDI_POSSIBLE_TRANSLATION_FAIL				5710 /*Jom DataInterchange Internal detection of possible translation failure*/
#define JDI_BUFFER_TOO_SMALL						5711 /*Jom DataInterchange Buffer too small*/
/*__endres  */

/*__beginres	System   */
//__
//__	 	Jom Internal Management Message Exchange Errors
//__
#define	MGMTMSG_INVALID_REQUESTGROUP				5900 /*MgmtMsg Invalid request group*/
#define	MGMTMSG_INVALID_REQUEST						5901 /*MgmtMsg Invalid request*/
#define	MGMTMSG_DATASIZE_TOO_BIG					5902 /*MgmtMsg data size too big*/
#define	MGMTMSG_INVALID_PRIORITY_TYPE				5903 /*MgmtMsg Invalid priority type*/
#define	MGMTMSG_INVALID_RESPONSE_TYPE				5904 /*MgmtMsg Invalid response type*/
#define	MGMTMSG_TARGETNODE_NOT_FOUND				5905 /*MgmtMsg Target node not found*/
#define	MGMTMSG_TARGETNODE_NO_BGTHRD				5906 /*MgmtMsg Target node no ServerBgThread*/
#define	MGMTMSG_SERVERNODE_ONLY						5907 /*MgmtMsg limited to server node*/
/*__endres  */

// ------------------------------------------------------------------------
// Codes in the range 6000-6999 are reserved for the compiler
// ------------------------------------------------------------------------
// ------------------------------------------------------------------------
// Codes in the range 7000-7999 are reserved for syntax errors.  When the
// compiler is expecting a particular grammar symbol, it generates an error
// code with a value of 7000 + symbolNum.
// ------------------------------------------------------------------------

//		8000-8255 Used by external database access see include/sys/extdberr.h
//		8256-8499 Used by ODBC see include/sys/odbcerrs.h

/*__beginres	Loader   */
//__
//__	 	Loader Error Messages
//__
#define LOAD_SUPERSCHEMA_NOT_FOUND					8500 /*Superschema not specified or found*/
#define LOAD_REORG_FAILED 							8501 /*Reorganisation during load failed*/
#define	LOAD_READ_ONLY_SCHEMA						8502 /*Cannot load into read only schema*/
#define	LOAD_FORM_BUILD_DATA						8503 /*Unable to generate Forms from their descriptions*/
#define	LOAD_REPORTWRITER_NOT_FOUND					8504 /*The Report Writer is not installed in this system*/
#define	LOAD_REPORTVIEW_FAILED  					8505 /*The specified Report file could not be loaded*/
#define	LOAD_REPORTDEFN_FAILED  					8506 /*The specified Report Definitions file could not be loaded*/
#define	LOAD_REPORTDEFN_PARTIAL  					8507 /*The specified Report Definitions file could only be partially loaded*/
#define	LOAD_SCHEMA_NOT_FOUND  						8508 /*The specified schema could not be found*/
#define	LOAD_SCHEMA_DELETE_FAILED  					8509 /*The specified schema could not be deleted*/
#define	LOAD_METHODS_IN_ERROR  						8510 /*Methods in error were detected by the schema load*/
#define LOAD_REORG_REQUIRED 						8511 /*Reorganisation is required*/
#define LOAD_CANCELLED								8512 /*Load cancelled*/
#define LOAD_INVALID_COMMAND_FILE_FORMAT			8513 /*Invalid command file format*/
#define	LOAD_COMMAND_FILE_ERROR  					8514 /*One or more commands in command file did not complete successfully - refer to jommsg.log [obsolete]*/
#define LOAD_COMMAND_FILE_FAILED					8515 /*Command file processing failed - refer to jommsg.log*/
#define PATCHSET_INV_JVERSTAG						8521 /*JadeFiletypeVersiontag line has invalid format*/
#define LOAD_CTRLCLS_REORG_REQUIRED 				8525 /*Reorganisation is required prior to DDB/DDX load*/
#define LOAD_FORMS_FAILED							8526 /*DDB/DDX load failed*/
#define LOAD_SCHEMA_INCOMPLETE						8527 /*Load results in one or more incomplete schemas*/
#define LOAD_NOAPPORGLOBAL   						8528 /*No Application or Global specified*/
#define LOAD_NODEFAULTMAPFILE  						8529 /*No Default Map File specified*/
#define LOAD_NOTAVAILABLE    						8530 /*Load functionality not available*/
#define LOAD_FORMS_FAILED_WITH_INFO					8531 /*DDB/DDX load failed {additionalText}*/


/*__endres  */

/*__beginres	JADEXML   */
//__
//__	 	Jade Git API Errors (8600-8699)
//__
#define	JADEGIT_ERROR_BASE							8600 /*Jade Git API errors*/
#define	JADEGIT_CANCELLED							8601 /*Jade Git operation is cancelled*/
#define	JADEGIT_FAIL								8602 /*General Git operation error*/
#define	JADEGIT_AMBIGUOUSSPECIFICATION				8603 /*Ambiguous Git reference, object, or path*/
#define	JADEGIT_BAREREPOSITORY						8604 /*Operation requires a working directory*/
#define	JADEGIT_CHECKOUTCONFLICT					8605 /*Checkout prevented by conflicting changes*/
#define	JADEGIT_EMPTYCOMMIT							8606 /*Commit operation would create an 'empty' Commit*/
#define	JADEGIT_ENTRYEXISTS							8607 /*Error attempting to create a resource that already exists*/
#define	JADEGIT_INVALIDSPECIFICATION				8608 /*Specification is incorrect*/
#define	JADEGIT_LOCKEDFILE							8609 /*Attempting to open a locked file*/
#define	JADEGIT_NAMECONFLICT						8610 /*Duplicate name for a Git resource*/
#define	JADEGIT_NONFASTFORWARD						8611 /*Push operation would lose commits*/
#define	JADEGIT_NOTFOUND							8612 /*Specified Git resource does not exist*/
#define	JADEGIT_MERGEFETCHHEADNOTFOUND				8613 /*Required Fetch for Merge was not part of a Pull operation*/
#define	JADEGIT_PEEL								8614 /*Git object cannot be found from Tag*/
#define	JADEGIT_RECURSESUBMODULES					8615 /*Error is encountered while recursing through submodules*/
#define	JADEGIT_REPOSITORYNOTFOUND					8616 /*Repository path is invalid*/
#define	JADEGIT_UNBORNBRANCH						8617 /*Operation requires a non-empty Branch*/
#define	JADEGIT_UNMATCHEDPATH						8618 /*Explicit paths could not be matched*/
#define	JADEGIT_UNMERGEDINDEXENTRIES				8619 /*Operation requires a fully merged index*/
#define	JADEGIT_AUTHORIZATION                       8620 /*Repository authentication*/
#define	JADEGIT_TRANSFERPROTOCOL					8621 /*Network protocol or transfer error*/
#define	JADEGIT_AUTHENTICATION						8622 /*Repository authorization issue*/
#define	JADEGIT_CERTIFICATE_ERROR					8623 /*Cannot access the repository server due to a certificate problem*/

/*__endres  */



/*__beginres	Upgrade   */
#define UPGRADE_GENERAL 							8701 /*General Upgrade error code*/
#define UPGRADE_ASSERT	 							8702 /*Internal <description> [obsolete]*/
#define UPGRADE_METHODNOSOURCE						8703 /*Method could not be recompiled - no source present*/
#define UPGRADE_REORGSTODO 							8705 /*Outstanding reorganisations were detected in this database*/
#define UPGRADE_INVALIDPARAMETER					8706 /*The parameter <parameter> specified for the Upgrade is invalid*/
#define UPGRADE_TOOEARLYAVERSION					8707 /*The version of JADE of the Source System '<src path>' is too early for this version of the Upgrade Utility [obsolete]*/
#define UPGRADE_TOOLATEAVERSION						8708 /*The version of JADE of the Source System '<src path>' is too late for this version of the Upgrade Utility [obsolete]*/
#define UPGRADE_RESTRICTEDCLASSES					8709 /*Instances of restricted classes were detected in this database [obsolete]*/
#define UPGRADE_CHECKEDOUTMETHODS					8710 /*Checked out methods were detected in this database*/
#define UPGRADE_METHODSINERROR						8711 /*Uncompiled or in error methods were detected in this database*/
#define UPGRADE_MISSINGWEBSESSION					8712 /*A Session Class definition is missing from a super schema in this database [obsolete]*/
#define UPGRADE_TOOMANYWEBSESSIONS					8713 /*Too many WebSession subclasses on a schema [obsolete]*/
#define UPGRADE_DBOPENMODE 							8721 /*Unable to open the database in the required mode [obsolete]*/
#define UPGRADE_ANSI_UNICODE_MISMATCH				8722 /*Cannot upgrade an Ansi database with Unicode files or vice versa*/
#define UPGRADE_VALIDATEFAILED						8723 /*Upgrade validation failed: refer to jommsg.log*/
#define UPGRADE_REPORTWRITER_EXISTS					8724 /*Cannot upgrade if JadeReportWriterSchema is present*/

/*__endres  */

/*__beginres	JAX   */
//__
//__	 	Jade ActiveX Exposure Errors
//__
#define	JAX_INVALID_PARAMETER						8800 /*Parameter is invalid*/
#define	JAX_NOT_CORRECTLY_INITIALIZED				8801 /*The JADE ActiveX Exposure Library has not been correctly initialized*/
#define	JAX_SIGNON_TO_ATTACHED_SESSION				8802 /*Attempt to sign on to previously attached session*/
#define	JAX_INVALID_SIGNOFF							8803 /*Attempt to sign off without sign on*/
#define	JAX_INVALID_UNSUBSCRIPTION					8804 /*Attempt to unsubscribe without subscription*/
#define	JAX_INVALID_DETACH							8805 /*Attempt to Detach session without attach*/
/*__endres  */

/*__beginres	JADEXML   */
//__
//__	 	Jade XML Errors (8900-8950)
//__
#define	JADEXML_PARSER_CREATE_FAILED				8900 /*XML parser could not be created*/
#define	JADEXML_PARSER_ERROR						8901 /*XML parser error*/
#define	JADEXML_ROOT_ELEMENT_ALREADY_DEFINED		8902 /*XML root element is already defined*/
#define	JADEXML_DOCTYPE_ALREADY_DEFINED				8903 /*XML Document Type is already defined*/
#define	JADEXML_NULL_NODE							8904 /*XML node cannot be null*/
#define	JADEXML_INVALID_HIERARCHY_REQUEST			8905 /*XML hierarchy request is invalid*/
#define	JADEXML_STRING_TO_UTF8_FAILED				8906 /*XML Jade string to UTF8 conversion failed*/
#define	JADEXML_UTF8_TO_STRING_FAILED				8907 /*XML UTF8 to Jade string conversion failed*/
#define JADEXML_PARSER_NODE_MISMATCH				8908 /*Cannot access an XML parser created by a different node*/
#define JADEXML_INVALID_CLASS_MAPPING				8909 /*XML class mapping is invalid*/
#define JADEXML_CANNOT_PARSE_PERSISTENT				8910 /*Cannot parse XML document into a persistent object*/
/*__endres  */

/*__beginres	JADEREGEX   */
//__
//__	 	Jade Regex Errors (8950-8999)
//__

#define JERR_REGEX_FAILED							8950 /*General RegexLibrary failure*/
#define JERR_REGEX_SEARCH_FAILED					8951 /*Regex failed during an operation*/
#define JERR_REGEX_INVALID_PATTERN					8952 /*Regex failed with an invalid pattern*/
#define JERR_REGEX_DIFFERENT_NODE					8953 /*Attempt to use Regex from a different node*/
#define JERR_REGEX_UTF8_VALIDITY_FAILED				8954 /*Pattern or search text UTF8 validity checks failed*/
#define JERR_REGEX_PATTERN_NOT_COMPILED				8955 /*Pattern was not compiled before doing a Regex operation*/
#define JERR_REGEX_OPERATION_TIMEOUT				8956 /*A Regex operation took too long and timed out*/
#define JERR_REGEX_OPERATION_CANCELLED				8957 /*A Regex operation was either interrupted or forced off*/

/*__endres  */

// ------------------------------------------------------------------------
// Codes in the range 10000-10999 are reserved for compiler warnings
// ------------------------------------------------------------------------

/*__beginres	JADEWS   */
//__
//__	 	Jade Web Service Errors (11000-11099)
//__
#define	JADEWS_MSGBOX								11000 /*Message Box message returned as an exception*/
#define JADEWS_NO_WEBSERVICE_CLASS  				11001 /*Web Service class %s does not exist*/
#define JADEWS_NO_WEBSERVICE_METHOD					11002 /*Web Service method %s does not exist*/
#define JADEWS_INVALID_PARAMETER_TYPE				11003 /*Parameter %s to method %s must be of type %s*/
#define JADEWS_LICENCES_EXCEEDED					11004 /*Number of licenses exceeded*/
#define JADEWS_RESPONSE_TIME_EXCEEDED				11005 /*Minimum response time exceeded for this request*/
#define JADEWS_SESSION_ENDED						11006 /*Session has been ended*/
#define JADEWS_SESSION_TIMED_OUT					11007 /*Session has timed out*/
#define JADEWS_SERVICE_UNAVAILABLE					11008 /*Service is currently unavailable*/
#define JADEWS_VERSION_MISMATCH						11009 /*There is a version mismatch for the requested service*/
#define JADEWS_NO_WEBSERVICE_PARAM					11010 /*Web Service parameter %s of method %s does not exist*/
#define JADEWS_INVALID_RESPONSE						11051 /*Unrecognised response from service*/
#define JADEWS_SERVICE_FAULT						11052 /*The service returned a fault message*/
#define JADEWS_ENUM_FAULT							11053 /*Property value for an enumerated property is not valid*/
#define JADEWS_STRING_TOO_LONG						11054 /*String or Binary property has exceeded its maximum defined length*/
#define JADEWS_DECIMAL_OVERFLOW						11055 /*Result of expression overflows Decimal precision*/
#define JADEWS_INVALID_REQUEST						11056 /*The requested message type is invalid*/
#define JADEWS_MISSING_EXPOSURE_LIST				11057 /*Web Service exposed list does not exist*/
#define JADEWS_SUBCLASS_NOT_FOUND  					11058 /*A property referenced a sub-class instance that is not in the exposure*/
#define JADEWS_INTEGER_OVERFLOW						11059 /*Result of expression overflows Integer precision*/
#define JADEWS_WSDL_GENERATION_FAILED				11081 /*WSDL Generation Failed */
#define JADEWF_INVALID_SEQUENCE						11091 /*Submitted HTML form is out of sequence*/
/*__endres  */

/*__beginres	JADERS   */
//__
//__	 	Jade Rest Service Errors (11100-11199)
//__
#define JADERS_NO_RESTSERVICE_CLASS  				11101 /*Class referenced in Rest Services request does not exist*/
#define JADERS_NO_RESTSERVICE_METHOD				11102 /*Requested Rest Service method does not exist*/
#define JADERS_USAGE_OUTPUT_PARAMETER				11103 /*A parameter of the called method is usage output*/
#define JADERS_INVALID_PARAMETER_TYPE				11104 /*A parameter type of the called method is not supported by Rest Services*/
#define JADERS_OBJECT_PARAMETER_MISSING				11105 /*The object parameter required by called Rest Services method was not supplied*/
#define JADERS_PARAMETER_SIGNATURE_MISMATCH			11106 /*The signature of the called Rest Services method does not match the supplied url entities*/
#define JADERS_CIRCULAR_REFERENCES_XML				11107 /*The Rest Service response xml cannot be generated because circular reference handling is disabled*/
#define JADERS_CIRCULAR_REFERENCES_JSON				11108 /*The Rest Service response json cannot be generated because the same object is referenced twice*/
#define JADERS_SERVICE_FAULT						11109 /*The Rest service returned a fault message*/
#define JADERS_INVALID_REQUEST						11110 /*The Rest service requested message is invalid*/
#define JADERS_INVALID_RESPONSE						11111 /*Unrecognised response from Rest service*/
#define JADERS_REST_NODE_MISMATCH					11112 /*Cannot access a Rest Services object created by a different node*/
#define JADERS_TOO_MANY_OBJECT_PARAMETERS			11113 /*The called Rest Service method can only have one object parameter*/
#define JADERS_JSON_BAD_NUMBER						11114 /*Invalid numeric value encountered in Json*/
#define JADERS_JSON_BAD_STRING						11115 /*Invalid string value encountered in Json*/
#define JADERS_JSON_BAD_IDENTIFIER					11116 /*Invalid identifier encountered in Json*/
#define JADERS_JSON_UNMATCHED_ARRAY_DELIMITER		11117 /*Unmatched array delimiter encountered in Json*/
#define JADERS_JSON_UNMATCHED_DELIMITER				11118 /*Unmatched delimiter encountered in Json*/
#define JADERS_JSON_UNEXPECTED_CHAR					11119 /*Unexpected character encountered in Json*/
#define JADERS_JSON_INCOMPLETE						11120 /*Json definition is incomplete*/
#define JADERS_JSON_INVALID_BINARY					11121 /*Json binary value is invalid*/
#define JADERS_JSON_INVALID_DATE					11122 /*Json date value is invalid*/
#define JADERS_JSON_REF_NOT_FOUND					11123 /*The reference tag in the Json text was not previously encountered*/
#define JADERS_JSON_REF_DUPLICATED					11124 /*Duplicate reference tag in the Json text*/
#define JADERS_RESTSERVICE_METHOD_PROTECTED			11125 /*Requested Rest Service method is protected*/
#define JADERS_RESTSERVICE_NOT_INITIALISED			11126 /*A Rest Service method was called but the service was never initialised*/
#define JADERS_RESTSERVICE_NO_WEB_MSG				11127 /*JadeRestService.reply was called but there is no web message to reply to*/
#define JADERS_RESTSERVICE_METHODIS_TYPEMETHOD		11128 /*Requested Rest Service method is a Type Method and cannot be called from Rest Services*/

#define JADE_JSON_NODE_MISMATCH						11151 /*Cannot access a JadeJson object created by a different node*/
#define JADE_JSON_CIRCULAR_REFERENCES_JSON			11152 /*The json cannot be generated because the same object is referenced twice*/
#define JADE_JSON_UNKNOWN_TYPE						11153 /*The type found in the Json is unknown*/
#define JADE_JSON_PARSE_TYPE						11154 /*The type of the object to decode is invalid*/
/*__endres  */

/*__beginres	APPSERVTCCB   */
//__
//__		Thin Client Connection Balancing Error Messages	(15901 - 15999)
//__
#define	TCCB_NODE_NOT_APPSERVER						15901 /*TCCB Node is not an App Server*/
#define	TCCB_CONFIG_ERR_GROUP_NAME					15902 /*TCCB AppServerGroupName missing or invalid*/
#define	TCCB_CONFIG_ERR_NODE_NAME					15903 /*TCCB [JadeAppServer]NodeName missing or invalid*/
#define	TCCB_CONFIG_ERR_ADRSPORT					15904 /*TCCB Unencrypted Address,Port missing or invalid*/
#define	TCCB_CONFIG_ERR_SSLADRSPORT					15905 /*TCCB SSL Address,Port missing or invalid*/
#define	TCCB_AMC_DLL_LOAD_ERR						15906 /*TCCB DLL (jadegm) missing or entrypoint not found*/
#define	TCCB_AMC_TEST_ERR							15907 /*TCCB Invoke picker method test error - see jommsg.log*/
#define	TCCB_NO_PICKER_PROCESSOR					15908 /*TCCB All picker processors have terminated*/
#define	TCCB_UNKNOWN_GROUP							15909 /*TCCB No AppServers registered with specified group name*/
#define	TCCB_GROUP_IS_FULL							15910 /*TCCB AppServer group cannot accept additional ThinClients*/
#define	TCCB_PICKER_TIMEOUT							15911 /*TCCB Timeout selecting AppServer*/
/*__endres  */

//		16000-19999 Used by JADE development environment
//      16000-16099 for very general purpose unexpected errors that require the msg text in this file
/*__beginres	Loader   */
//__
//__	 	JADE Development Environment Error Messages
//__

#define DEV_USER_ABORT								16000 /*A JADE user cancelled an operation*/
#define DEV_CALL_TO_OBSOLETE_METHOD					16001 /*A call was made to an obsolete method*/
#define DEV_UNDEF_CONSOLE_CALLBACK					16002 /*A call was made to a console method that does not have a defined callback*/
#define DEV_UNHANDLED_CODE_PATH						16003 /*Unhandled code path detected*/
#define DEV_PRECONDITION_VIOLATION					16004 /*Precondition contract violation*/
#define DEV_ASSERT_FAILURE 							16005 /*A JADE assertion test failed*/

//__
//__	 	16100-16199 DataHandler errors
//__

#define DHExceptionClassNeedsReorg					16101 /*Class needs reorg [obsolete]*/
#define DHExceptionClassNotFound					16102 /*The class was not found in the current schema branch*/
#define DHExceptionExpectedToken					16103 /*Expected token*/
#define DHExceptionFileNotAvailable					16104 /*The specified file is not available*/
#define DHExceptionInvalidClass						16105 /*The class is invalid in this context*/
#define DHExceptionInvalidForms						16106 /*The forms have invalid entries*/
#define DHExceptionUnexpectedToken					16107 /*Unexpected token*/
#define DHExceptionUsingDefaultLocales				16108 /*The form will be assigned the definitions of the default locale*/
#define DHExceptionInvalidReference					16109 /*Unknown references were detected in the loaded definition*/
#define DHExceptionInvalidRefOnGlobal				16110 /*The property of your Global object has an invalid reference*/
#define DHExceptionInvalidFormOnApp					16111 /*The form for the application is missing from the loaded definition*/
#define DHExceptionInvalidParentOnCtrl				16112 /*The parent of the control on the form is missing from the loaded definition*/
#define DHExceptionIncompatibleFormat				16113 /*The format of the DDB file is incompatible with this version of Jade*/
#define DHExceptionReadStmtError					16114 /*Expected more input than was available*/
#define DHExceptionApplicationExists				16115 /*Application exists [obsolete]*/
#define DHExceptionPatchControl						16116 /*Patch Control Check failed*/
#define DHExceptionAppUsedInPackage					16117 /*Application used in one or more packages and cannot be deleted*/
#define DHExceptionVersioningFailed					16118 /*Versioning failed*/
#define DHExceptionRpsMappingInvalid				16119 /*The RPS Mapping columns do not match the Jade definitions*/
#define DHExceptionInvalidSchema					16120 /*The DDB/DDX file specifies a schema that does not exist*/
#define DHExceptionHtmlDocParsing    				16121 /*Parsing HTMLDocument failed*/
/*__endres  */


/*__beginres	NetConnection   */

//__
//__	 	Connection Error Messages
//__
#define	CONN_INITIALIZATION_FAILED					31000	/*Connection failed to initialize*/
#define	CONN_NO_HOST								31001	/*Connection no target host name specified*/
#define	CONN_HOST_NOT_FOUND							31002	/*Connection target host not found*/
#define	CONN_INVALID_PORT							31003	/*Connection invalid port specification*/
#define CONN_CONNECT_ERROR			   				31004	/*Connection failed to connect*/
#define	CONN_BIND_FAILED							31005	/*Connection bind failed*/
#define	CONN_LISTEN_FAILED							31006	/*Connection listen failed*/
#define	CONN_ACCEPT_FAILED							31007	/*Connection accept failed*/
#define CONN_READ_ERROR								31008	/*Connection read error*/
#define	CONN_WRITE_ERROR							31009	/*Connection write error*/
#define	CONN_CLOSE_ERROR							31010	/*Connection close error*/
#define	CONN_INVALID_STATE							31011	/*Connection invalid state for requested operation*/
#define	CONN_READ_PENDING							31012	/*Connection read operation is already pending*/
#define	CONN_ATTRIBUTE_READ_ONLY					31013	/*Connection attribute cannot be modified directly*/
#define	CONN_NOTIFY_FAILED							31014	/*Connection PostThreadMessage for event notification failed*/
#define	CONN_NO_MEMORY								31015	/*Connection memory allocation failed*/
#define	CONN_INTERNAL_ERROR							31016	/*Connection internal error*/
#define	CONN_CONNECTION_CLOSED						31017	/*Connection was closed*/
#define	CONN_REQUEST_CANCELLED						31018	/*Connection request cancelled*/
#define	CONN_NO_MESSAGE								31019	/*Connection no message name for asynchronous method*/
#define	CONN_METHOD_NOT_FOUND						31020	/*Connection receiver does not have specified method*/
#define	CONN_METHOD_RETURN_VALUE					31021	/*Connection receiver method must not return a value*/
#define	CONN_CLASS_VALIDATION_ERROR					31022	/*Connection receiver object class validation error*/
#define	CONN_RECEIVER_OBJECT_NULL					31023	/*Connection receiver object specification is NULL*/
#define	CONN_METHOD_VALIDATION_ERROR				31024	/*Connection receiver method validation error*/
#define	CONN_RETURN_VALIDATION_ERROR				31025	/*Connection receiver method return type validation error*/
#define	CONN_LOADLIBRARY_ERROR						31026	/*Connection failed to load dynamic library*/
#define	CONN_LOADMETHOD_ERROR						31027	/*Connection failed to find method in library*/
#define	CONN_AUTHENTICATION_ERROR					31028	/*Connection authentication failure*/
#define	CONN_ENCRYPTION_ERROR						31029	/*Connection encryption error*/
#define	CONN_DECRYPTION_ERROR						31030	/*Connection decryption error*/
#define	CONN_INVALID_CONNECTION						31031	/*Connection invalid connection*/
#define	CONN_NOT_TRANSIENT							31032	/*Connection may not be a persistent object*/
#define	CONN_INVALID_PARAMETER_TYPE					31033	/*Connection invalid parameter type*/
#define	CONN_INVALID_BUFFER_SIZE					31034	/*Connection negative or zero buffer size invalid*/
#define	CONN_LISTEN_PENDING							31035	/*Connection listen operation is already pending*/
#define	CONN_READ_TIMEOUT							31036	/*Connection read timeout*/
#define	CONN_WRITE_TIMEOUT							31037	/*Connection write timeout*/
#define	CONN_LISTEN_TIMEOUT							31038	/*Connection listen timeout*/
#define	CONN_INVALID_INVOCATION						31039	/*Connection invalid invocation*/
#define	CONN_INVALID_DELIMITER_SIZE					31040	/*Connection delimiter size invalid*/
#define	CONN_BUFFER_FULL							31041	/*Connection readUntil buffer full*/
#define	CONN_UNSUPPORTED_PARAMETER					31042	/*Connection method and/or parameter unsupported (yet)*/
#define	CONN_PROXY_MISMATCH							31043	/*Connection proxy mismatch or proxy not defined*/
#define	CONN_SSLCONTEXT_MISMATCH					31044	/*Connection sslContext mismatch or sslContext not defined*/
#define	CONN_NO_NAME								31045	/*Connection no name was specified*/
#define	CONN_INVALID_PARAMETER_VALUE				31046	/*Connection invalid parameter value*/
#define	CONN_DELIMITER_NOT_FOUND					31047	/*Connection delimiter not found*/
#define	CONN_SSL_NO_CIPHER							31048	/*Connection SSL no cipher*/
#define	CONN_SSL_NO_CERTIFICATE						31049	/*Connection SSL no certificate*/
#define	CONN_SSL_INVALID_METHOD_TYPE				31050	/*Connection SSL invalid method type*/
#define	CONN_EMPTY_PARAM_LIST						31051	/*Connection method called with empty parameter list*/
/*__endres  */

/*__beginres	MultiWorkerTcpTransport   */

//__
//__	 	MultiWorkerTcpTransport Error Messages
//__
#define	CONN_MWTT_NYI								31101	/*MultiWorkerTransport feature not yet implemented*/
#define	CONN_READYONLY_AFTER_BEGIN					31102	/*MultiWorkerTransport property is readOnly after beginListening*/
#define	CONN_REQUIRES_BEGINLISTEN					31103	/*MultiWorkerTransport beginListening has not been called*/
#define	CONN_INVALID_WORKER_STATUS					31104	/*MultiWorkerTransport invalid worker status*/
#define	CONN_UNKNOWN_WORKERID						31105	/*MultiWorkerTransport unknown workerId*/
#define	CONN_WORKER_NOT_ASSIGNED					31106	/*MultiWorkerTransport connection not assigned to worker*/
#define	CONN_ALREADY_BOUND							31107	/*MultiWorkerTransport connection already bound to another worker*/
#define	CONN_USEROBJ_NONSHAREDTRAN					31108	/*MultiWorkerTransport userObject cannot be nonSharedTransient*/
#define	CONN_INVALID_MWTTRANSPORT					31109	/*MultiWorkerTransport internal error*/
#define	CONN_INVALID_MWTMANAGER						31110	/*MultiWorkerTransport internal error*/
#define	CONN_DOUBLE_MWTMANAGER						31111	/*MultiWorkerTransport internal error*/
#define	CONN_FOUND_TERMINATING_MWTMANAGER			31112	/*MultiWorkerTransport internal error*/
#define	CONN_MWTMANAGER_INIT						31113	/*MultiWorkerTransport internal error*/
#define	CONN_MWTMANAGER_WAKEUP_SOCKS				31114	/*MultiWorkerTransport internal error*/
#define	CONN_MWTCONN_NO_SOCKET						31115	/*MultiWorkerTransport internal error*/
#define	CONN_DIFFERENT_CLASS						31116	/*MultiWorkerTransport different MWTT class/subclass*/
#define	CONN_BEGINLISTEN_REFUSED					31117	/*MultiWorkerTransport beginListening refused by validateServerProcess*/
#define	CONN_MISSING_SYSINFO						31118	/*MultiWorkerTransport internal error*/
#define	CONN_MISSING_TCPCONN						31119	/*MultiWorkerTransport internal error*/
#define	CONN_CALLBACK_EXCEPTION						31120	/*MultiWorkerTransport internal error*/
#define	CONN_INVALID_IOBUFFER						31121	/*MultiWorkerTransport internal error*/
#define CONN_WORKER_NOT_BOUND						31122	/*MultiWorkerTransport connection not bound to worker*/
#define	CONN_UNKNOWN_CONNID							31123	/*MultiWorkerTransport unknown connectionId*/
#define	CONN_WRITED8_EXCEEDS_99999999				31124	/*MultiWorkerConnnection writeD8 message exceeds 99,999,999 bytes*/
#define	CONN_READD8BUFF_BAD_LENGTH					31125	/*MultiWorkerConnnection readD8Buffered found invalid length*/
#define	CONN_GETBUFFERED_NO_GOOD_READ				31126	/*MultiWorkerConnnection getBufferedChunk not preceded by successful readBuffered*/
#define	CONN_NOT_CONNECTED							31127	/*MultiWorkerConnnection state not connected*/
#define	CONN_ALREADY_ASSIGNED						31128	/*MultiWorkerTransport already assigned*/
#define CONN_ALREADY_CLOSED						31129   /*Connection has timed out and has been closed*/
/*__endres  */

/*__internal	OpenSLP   */
//__
//__	 	OpenSLP Error Messages,  (31200 - 31249) - SLP error number
//__
#define	CONN_SLP_OK									31200	/*SLP Successfull operation*/
#define	CONN_SLP_LANGUAGE_NOT_SUPPORTED				31201	/*SLP No DA or SA information in requested language*/
#define	CONN_SLP_PARSE_ERROR						31202	/*SLP SA or DA indicated a protocol error*/
#define	CONN_SLP_INVALID_REGISTRATION				31203	/*SLP No DA accepted the registration*/
#define	CONN_SLP_SCOPE_NOT_SUPPORTED				31204	/*SLP The SA request included a scope that is not supported*/
#define	CONN_SLP_AUTHENTICATION_ABSENT				31205	/*SLP The UA or SA failed to send an authenticator for requests or registrations in a protected scope*/
#define	CONN_SLP_AUTHENTICATION_FAILED				31207	/*SLP When a authentication on an SLP message failed*/
#define	CONN_SLP_INVALID_UPDATE						31213	/*SLP An update for a non-existing registration was issued or different values from initial registration*/
#define	CONN_SLP_REFRESH_REJECTED					31215	/*SLP The SA attempted to refresh a registration more frequently than the minimum refresh interval*/
#define	CONN_SLP_NOT_IMPLEMENTED					31217	/*SLP If an unimplemented feature is used, this error is returned*/
#define	CONN_SLP_BUFFER_OVERFLOW					31218	/*SLP An outgoing request overflowed the maximum network MTU size*/
#define	CONN_SLP_NETWORK_TIMED_OUT					31219	/*SLP When no reply can be obtained in the time specified by the configured timeout interval for a unicast request*/
#define	CONN_SLP_NETWORK_INIT_FAILED				31220	/*SLP If the network cannot initialize properly, this error is returned.  Will also be returned if an SA or DA agent (slpd) can not be contacted*/
#define	CONN_SLP_MEMORY_ALLOC_FAILED				31221	/*SLP Out of memory error*/
#define	CONN_SLP_PARAMETER_BAD						31222	/*SLP If a parameter passed into an interface is bad*/
#define	CONN_SLP_NETWORK_ERROR						31223	/*SLP The failure of networking during normal operations causes this error*/
#define	CONN_SLP_INTERNAL_SYSTEM_ERROR				31224	/*SLP A basic failure of the API causes this error to be returned. This occurs when a system call or library fails.  The operation could not recover*/
#define	CONN_SLP_HANDLE_IN_USE						31225	/*SLP The C API callback functions are not permitted to recursively call into the API on the same SLPHandle*/
#define	CONN_SLP_TYPE_ERROR							31226	/*SLP */
#define	CONN_SLP_RETRY_UNICAST						31227	/*SLP */
/*__endinternal  */


/* Service Eventlog Messages,  (31250 - 31299), see include/sys/services.hpp */

/* Serial Port Error Messages, (31300 - 31399), see include/sys/serialport.hpp */


/*__beginres	Network Proxy   */

//__
//__	 	Network Proxy Error Messages
//__
#define	PROXY_NO_MEMORY								31500	/*NetworkProxy memory allocation failed*/
#define	PROXY_UNSUPPORTED_PROXYTYPE					31501	/*NetworkProxy proxyType not (yet) supported*/
#define	PROXY_REQUEST_CANCELLED						31502	/*NetworkProxy proxy request was cancelled*/
#define	PROXY_READ_FAILED							31503	/*NetworkProxy network read failed*/
#define	PROXY_WRITE_FAILED							31504	/*NetworkProxy network write failed*/
#define PROXY_SECPKG_NOTSUPPORTED					31505	/*NetworkProxy Authentication package not supported*/
#define PROXY_SECPKG_CREDENTIALS					31506	/*NetworkProxy Bad credentials, domain/username/password wrong*/
#define PROXY_SECPKG_APIERROR						31507	/*NetworkProxy Unexpected error from Security API*/
#define PROXY_INVALID_HANDSHAKE						31508	/*NetworkProxy Bad handshake protocol*/
#define PROXY_FAILED_CREDENTIALS					31509	/*NetworkProxy Unable to obtain credentials*/
#define PROXY_CANCEL_CREDENTIALS					31510	/*NetworkProxy User does not want to supply credentials*/
#define	PROXY_INTERNAL_ERROR						31511	/*NetworkProxy internal error*/
#define	PROXY_NO_NETWORK							31512	/*NetworkProxy no network specified*/
#define	PROXY_UNSUPPORTED_BROWSERTYPE				31513	/*NetworkProxy unsupported browser type*/

/*__endres  */

/*__beginres	WebSocket    */

//__
//__	 	WebSocket Error Messages
//__
#define	WEB_SOCKET_PROTOCOL_ERROR					31600	/*WebSocket Protocol Error*/

/*__endres  */


/*__beginres	X509 Certificate   */

//__
//__	 	X509 certificate error messages
//__
#define	X509_NO_MEMORY								32500	/*X509Certificate memory allocation failed*/
#define	X509_ATTRIBUTE_READ_ONLY					32501	/*X509Certificate attribute is ReadOnly*/
#define	X509_ATTRIBUTE_WRITE_ONLY					32502	/*X509Certificate attribute is WriteOnly*/
#define	X509_INVALID_CERTIFICATE					32503	/*X509Certificate invalid certificate*/
#define	X509_NO_CERTIFICATE_FILE					32504	/*X509Certificate no Certificate file specified*/
#define	X509_INVALID_CERTIFICATE_FILE				32505	/*X509Certificate invalid Certificate file name or contents*/
#define	X509_INVALID_PRIVATEKEY_FILE				32506	/*X509Certificate invalid PrivateKey file name or contents*/
#define	X509_PRIV_PUB_KEY_MISMATCH					32507	/*X509Certificate private and public key mismatch*/
#define	X509_INVALID_PARAMETER_TYPE					32508	/*X509Certificate invalid parameter type*/
#define	X509_NO_PEER_CERTIFICATE					32509	/*X509Certificate no peer certificate*/
#define	X509_SET_DH_FAILED							32510	/*X509Certificate setting dh failed*/
#define	X509_INVALID_PRIVATEKEY						32511	/*X509Certificate invalid privatekey*/
#define	X509_INVALID_CERTIFICATE_DATA				32512	/*X509Certificate invalid certificate data*/
#define	X509_INVALID_PRIVATEKEY_DATA				32513	/*X509Certificate invalid privatekey data*/
#define	X509_BUFFER_TOO_SMALL						32514	/*X509Certificate destination buffer too small*/
#define	X509_FILE_READ_FAILED						32515	/*X509Certificate file read operation failed*/
#define	X509_FILE_WRITE_FAILED						32516	/*X509Certificate file write operation failed*/
#define	X509_UNSUPPORTED_FILE_FORMAT				32517	/*X509Certificate unsupported file format*/
#define	X509_OPENFILE_FAILED						32518	/*X509Certificate failed to open specified file*/

/*__endres  */

/*__beginres	X509 Certificate Manager   */

//__
//__	 	X509 certificate manager error messages
//__
#define	X509MGR_NO_MEMORY							32600	/*X509CertificateManager memory allocation failed*/
#define	X509MGR_NO_OPENSSL_CONFIGFILE				32601	/*X509CertificateManager no OpenSSL configuration file specified*/
#define	X509MGR_CONFIGFILE_ERROR					32602	/*X509CertificateManager error in OpenSSL configuration file*/
#define	X509MGR_CONFIGFILE_LOOKUP_ERROR				32603	/*X509CertificateManager OpenSSL configuration file lookup error*/
#define	X509MGR_FILE_OPEN_ERROR						32604	/*X509CertificateManager file open failed*/
#define	X509MGR_FILE_READ_ERROR						32605	/*X509CertificateManager file read failed*/
#define	X509MGR_FILE_NOT_OPEN						32606	/*X509CertificateManager file is not open*/
#define	X509MGR_INTERNAL_ERROR						32607	/*X509CertificateManager internal error, check log for specific information*/
#define	X509MGR_INVALID_PARAMETER					32608	/*X509CertificateManager invalid parameter*/
#define	X509MGR_CRL_LOAD_ERROR						32609	/*X509CertificateManager CRL load error*/

/*__endres  */

/*__beginres	OmniORB   */

//__
//__	 	OmniORB Error Messages
//__
#define	OMNIORB_INITIALIZATION_FAILED				33000	/*OmniORB failed to initialize*/
#define	OMNIORB_NOT_INITIALIZED						33001	/*OmniORB object not initialized*/
#define	OMNIORB_ALREADY_INITIALIZED					33002	/*OmniORB object was already initialized*/
#define	OMNIORB_INVALID_OBJECT						33003	/*OmniORB invalid object*/
#define	OMNIORB_NO_MEMORY							33004	/*OmniORB no memory*/
#define	OMNIORB_SERVER_INIT_FAILED					33005	/*OmniORB server initialize failed*/
#define	OMNIORB_SERVER_START_FAILED					33006	/*OmniORB server start failed*/
#define	OMNIORB_SERVER_SHUTDOWN_FAILED				33007	/*OmniORB server shutdown failed*/
#define	OMNIORB_SERVER_ALREADY_ACTIVE				33008	/*OmniORB server already active*/
#define	OMNIORB_CLIENT_INIT_FAILED					33009	/*OmniORB client initialize failed*/
#define	OMNIORB_NOT_TRANSIENT						33010	/*OmniORB object is not transient*/
#define OMNIORB_INVALID_IIOPPORT					33011	/*OmniORB invalid or no iiop port*/

/*__endres  */

/*__beginres	Connection   */

//__
//__	 	SharedMemory Error Messages
//__
#define	SHAREDMEMORY_UNSUPPORTED_ARCHITECTURE		33500	/*SharedMemory unsupported hardware or OS architecture*/
#define	SHAREDMEMORY_CREATE_FAILED					33501	/*SharedMemory create failed*/
#define	SHAREDMEMORY_OPEN_FAILED					33502	/*SharedMemory open failed*/
#define	SHAREDMEMORY_MAPPING_FAILED					33503	/*SharedMemory mapping failed*/
#define	SHAREDMEMORY_UNMAPPING_FAILED				33504	/*SharedMemory unmapping failed*/
#define	SHAREDMEMORY_CLOSEHANDLE_FAILED				33505	/*SharedMemory close failed*/
#define	SHAREDMEMORY_GET_MEMORY_OVERRUN				33506	/*SharedMemory overrun on get operation*/
#define	SHAREDMEMORY_PUT_MEMORY_OVERRUN				33507	/*SharedMemory overrun on put operation*/
#define	SHAREDMEMORY_NOT_INITIALIZED				33508	/*SharedMemory not initialized*/
#define	SHAREDMEMORY_NO_MEMORY_SEGMENT				33509	/*SharedMemory no memory segment allocated*/

/*__endres	*/

/*__beginres	Multiple Servers   */

//__
//__	 	Kernel
//__
#define	INVALID_SECONDARY_SERVER					34000	/*Secondary Server has not been initialized*/
#define	ALREADY_SIGNED_ON_TO_SERVER					34001	/*Process already signed on to secondary server*/
#define	NOT_SIGNED_ON_TO_SERVER						34002	/*Process is not signed on to secondary server*/
#define	SERVER_ALREADY_INTIALIZED					34003	/*Process already signed on to secondary server*/

/*__endres  */


/*__beginres	Multiple Servers   */

//__
//__	 	Inter Node Communications
//__
#define	INC_NO_MEM									35000	/*INC - no memory*/
#define	INC_INVALID_CHANNEL							35001	/*INC - invalid channel*/
#define	INC_LISTENER_ALREADY_STARTED				35002	/*INC - listener already started*/
#define	INC_LISTENER_SETUP_FAILED					35003	/*INC - listener setup failed*/
#define	INC_CONNECT_FAILED							35004	/*INC - failed to establish network connection*/
#define	INC_NO_LISTENER_WAS_SPECIFIED				35005	/*INC - no listener network was specified*/
#define	INC_NETWORK_IN_USE							35006	/*INC - network already in use*/
#define	INC_CHANNEL_IN_USE							35007	/*INC - channel is already in use*/
#define	INC_INVALID_NETWORK_TYPE					35008	/*INC - invalid or unsupported network type*/
#define	INC_INVALID_NET_SPECIFICATION				35009	/*INC - invalid network specification*/
#define	INC_INVALID_METHOD_CALL						35010	/*INC - invalid method call for this network type*/
#define	INC_INVALID_STATE_FOR_OPERATION				35011	/*INC - invalid state for operation*/
#define	INC_NETWORK_INITIALIZE_FAILED				35012	/*INC - network initialize failed*/
// spare											35013
#define	INC_VERSION_MISMATCH						35014	/*INC - protocol version mismatch*/
#define	INC_INVALID_HANDLE							35015	/*INC - invalid handle*/
#define	INC_COMMUNICATION_ERROR						35016	/*INC - communication error*/
#define	INC_REMOTE_DISCONNECTED						35017	/*INC - remote host disconnected*/
#define	INC_INVALID_MIN_CHANNELS					35018	/*INC - invalid value for minimum channels*/
#define	INC_FINALIZE_REQUESTED						35019	/*INC - remote requested finalize*/
#define	INC_INVALID_CHANNEL_OPTION					35020	/*INC - invalid channel option*/
#define	INC_ACCESS_DENIED							35021	/*INC - access denied*/
#define	INC_PASSED_TO_FILESERVER					35022	/*INC - Network passed on to FileServer*/
#define	INC_COMPATIBILITY_MISMATCH					35023	/*INC - node compatibility mismatch*/

/*__endres  */

/*__beginres	Inter Node File Transfer   */

//__
//__	 	File Transfer / Jade Admin Error Messages
//__
#define	FTP_NO_MEMORY								35500	/*FileTransfer - no memory*/
#define	FTP_CHECKSUMBUFFER_TOO_SMALL				35501	/*FileTransfer - checksum buffer size too small*/
#define	FTP_FILE_NOT_OPEN							35502	/*FileTransfer - file not open*/
#define	FTP_FILE_TRANSFER_FAILED					35503	/*FileTransfer - data corrupted (MD5) during transfer*/
#define	JADEADMIN_PROTOCOL_ERROR					35504	/*Jadeadmin - auto upgrade found a protocol error*/

/*__endres	*/


/*__beginres	Application   */

	// 36000 - 36999 = Java VM and Interface errors [obsolete]

/*__endres  */


/*__beginres	Fatal Network errors   */

//__
//__		Fatal Client Server Network error codes
//__
#define NET_BADID									-101 /*Invalid client id number*/
#define NET_NOPEN   								-102 /*Network connection not open*/
#define NET_NOMEM    								-103 /*Out of memory for network command*/
#define NET_CONNECT_FAILED							-104 /*Failed to establish network connection*/
#define NET_STREAM_IOERROR							-105 /*Read/Write error on network*/
#define NET_DOWN									-106 /*Network not available*/
#define NET_NORESOURCE								-107 /*Out of resource*/
#define NET_INTERNAL_ERROR							-108 /*Network Internal Error: check log*/
#define NET_MSG_TOO_BIG								-109 /*Network maximum message length exceeded*/
#define	NET_SIGNON_DISABLED							-110 /*User signon currently disabled on server*/
#define	NET_HOST_NOT_FOUND							-111 /*Host not found*/
#define NET_WAIT_FAILED								-112 /*Wait for receiver failed*/
#define	NET_SERVER_NETINIT_FAILED					-113 /*Server Network initialization failed*/
#define	NET_RESPONSE_TIMEOUT						-117 /*Network response timeout [obsolete]*/
#define	NET_CONNECTION_LOST							-118 /*Network connection lost*/
#define	NET_REMOTE_DISCONNECTED						-119 /*Remote node closed connection*/
#define	NET_JOMSRVR_LOAD_FAILED						-120 /*Unable to load jomsrvr DLL*/

/*__endres  */


#endif /* JOMERRS_h */

