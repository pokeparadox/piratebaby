#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "23";
	static const char MONTH[] = "05";
	static const char YEAR[] = "2011";
	static const char UBUNTU_VERSION_STYLE[] = "11.05";
	
	//Software Status
	static const char STATUS[] = "Alpha";
	static const char STATUS_SHORT[] = "a";
	
	//Standard Version Type
	static const long MAJOR = 1;
	static const long MINOR = 0;
	static const long BUILD = 362;
	static const long REVISION = 2015;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 514;
	#define RC_FILEVERSION 1,0,362,2015
	#define RC_FILEVERSION_STRING "1, 0, 362, 2015\0"
	static const char FULLVERSION_STRING[] = "1.0.362.2015";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 362;
	

}
#endif //VERSION_H
