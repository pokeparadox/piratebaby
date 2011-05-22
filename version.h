#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "21";
	static const char MONTH[] = "05";
	static const char YEAR[] = "2011";
	static const char UBUNTU_VERSION_STYLE[] = "11.05";
	
	//Software Status
	static const char STATUS[] = "Alpha";
	static const char STATUS_SHORT[] = "a";
	
	//Standard Version Type
	static const long MAJOR = 1;
	static const long MINOR = 0;
	static const long BUILD = 354;
	static const long REVISION = 1963;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 507;
	#define RC_FILEVERSION 1,0,354,1963
	#define RC_FILEVERSION_STRING "1, 0, 354, 1963\0"
	static const char FULLVERSION_STRING[] = "1.0.354.1963";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 354;
	

}
#endif //VERSION_H
