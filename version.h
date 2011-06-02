#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "02";
	static const char MONTH[] = "06";
	static const char YEAR[] = "2011";
	static const char UBUNTU_VERSION_STYLE[] = "11.06";
	
	//Software Status
	static const char STATUS[] = "Alpha";
	static const char STATUS_SHORT[] = "a";
	
	//Standard Version Type
	static const long MAJOR = 1;
	static const long MINOR = 1;
	static const long BUILD = 531;
	static const long REVISION = 3023;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 756;
	#define RC_FILEVERSION 1,1,531,3023
	#define RC_FILEVERSION_STRING "1, 1, 531, 3023\0"
	static const char FULLVERSION_STRING[] = "1.1.531.3023";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 131;
	

}
#endif //VERSION_H
