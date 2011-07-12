#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "11";
	static const char MONTH[] = "07";
	static const char YEAR[] = "2011";
	static const char UBUNTU_VERSION_STYLE[] = "11.07";
	
	//Software Status
	static const char STATUS[] = "Alpha";
	static const char STATUS_SHORT[] = "a";
	
	//Standard Version Type
	static const long MAJOR = 1;
	static const long MINOR = 2;
	static const long BUILD = 1134;
	static const long REVISION = 6274;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 2109;
	#define RC_FILEVERSION 1,2,1134,6274
	#define RC_FILEVERSION_STRING "1, 2, 1134, 6274\0"
	static const char FULLVERSION_STRING[] = "1.2.1134.6274";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 334;
	

}
#endif //VERSION_H
