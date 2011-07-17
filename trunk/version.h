#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "14";
	static const char MONTH[] = "07";
	static const char YEAR[] = "2011";
	static const char UBUNTU_VERSION_STYLE[] = "11.07";
	
	//Software Status
	static const char STATUS[] = "Alpha";
	static const char STATUS_SHORT[] = "a";
	
	//Standard Version Type
	static const long MAJOR = 1;
	static const long MINOR = 2;
	static const long BUILD = 1146;
	static const long REVISION = 6364;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 2191;
	#define RC_FILEVERSION 1,2,1146,6364
	#define RC_FILEVERSION_STRING "1, 2, 1146, 6364\0"
	static const char FULLVERSION_STRING[] = "1.2.1146.6364";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 346;
	

}
#endif //VERSION_H
