#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "02";
	static const char MONTH[] = "07";
	static const char YEAR[] = "2011";
	static const char UBUNTU_VERSION_STYLE[] = "11.07";
	
	//Software Status
	static const char STATUS[] = "Alpha";
	static const char STATUS_SHORT[] = "a";
	
	//Standard Version Type
	static const long MAJOR = 1;
	static const long MINOR = 2;
	static const long BUILD = 932;
	static const long REVISION = 5168;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 1623;
	#define RC_FILEVERSION 1,2,932,5168
	#define RC_FILEVERSION_STRING "1, 2, 932, 5168\0"
	static const char FULLVERSION_STRING[] = "1.2.932.5168";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 132;
	

}
#endif //VERSION_H
