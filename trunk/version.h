#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "13";
	static const char MONTH[] = "06";
	static const char YEAR[] = "2011";
	static const char UBUNTU_VERSION_STYLE[] = "11.06";
	
	//Software Status
	static const char STATUS[] = "Alpha";
	static const char STATUS_SHORT[] = "a";
	
	//Standard Version Type
	static const long MAJOR = 1;
	static const long MINOR = 1;
	static const long BUILD = 692;
	static const long REVISION = 3861;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 1005;
	#define RC_FILEVERSION 1,1,692,3861
	#define RC_FILEVERSION_STRING "1, 1, 692, 3861\0"
	static const char FULLVERSION_STRING[] = "1.1.692.3861";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 292;
	

}
#endif //VERSION_H
