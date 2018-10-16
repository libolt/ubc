#ifndef _DATA_TYPES_H
#define _DATA_TYPES_H

#if WIN32
	#include "windows.h"
#else
	typedef signed char INT8;
	typedef unsigned char UINT8;
	typedef signed short INT16;
	typedef unsigned short UINT16;
	typedef unsigned int UINT32;
	typedef int INT32;
	typedef char CHAR;
	typedef short SHORT;
	typedef long LONG;
	typedef int INT;
	typedef unsigned int UINT;
	typedef unsigned long DWORD;
	typedef unsigned char BYTE;
	typedef unsigned short WORD;
	typedef float FLOAT;
	typedef double DOUBLE;
	typedef bool BOOL;

	#ifndef nullptr
	#ifdef __cplusplus
	#define nullptr    0
	#else
	#define nullptr    ((void *)0)
	#endif
	#endif

	#ifndef FALSE
	#define FALSE               0
	#endif

	#ifndef TRUE
	#define TRUE                1
	#endif
#endif

#endif
