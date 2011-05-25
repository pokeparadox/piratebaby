#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "25";
	static const char MONTH[] = "05";
	static const char YEAR[] = "2011";
	static const char UBUNTU_VERSION_STYLE[] = "11.05";
	
	//Software Status
	static const char STATUS[] = "Alpha";
	static const char STATUS_SHORT[] = "a";
	
	//Standard Version Type
	static const long MAJOR = 1;
	static const long MINOR = 0;
	static const long BUILD = 372;
	static const long REVISION = 2068;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 523;
	#define RC_FILEVERSION 1,0,372,2068
	#define RC_FILEVERSION_STRING "1, 0, 372, 2068\0"
	static const char FULLVERSION_STRING[] = "1.0.372.2068";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 372;
	

}
#endif //VERSION_H
