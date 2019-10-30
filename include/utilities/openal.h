#ifndef OPEN_AL_H
#define OPEN_AL_H


#ifdef _MSC_VER	
	#pragma comment(lib, "OpenAL32.lib")
/*	#pragma comment(lib, "pthreadVCE2.lib")
	#pragma comment(lib, "pthreadVSE2.lib")
	#pragma comment(lib, "pthreadVC2.lib")
*/
#endif

#ifdef OPENAL_ENABLED

#include <al.h>
#include <alc.h>

//#include "../../Utils/header/Logger.h"
//#include "../../Utils/header/MyString.h"

#include "utilities/logging.h"

void CheckOpenALError(const char* stmt, const char* fname, int line);
std::string GetOpenALErrorString(int errID);


inline std::string GetOpenALErrorString(int errID)
{	
	if (errID == AL_NO_ERROR)
	{
		return "";
	}

	if(errID == AL_INVALID_NAME)
    {
        return "Invalid name";
    }
    else if(errID == AL_INVALID_ENUM)
    {
        return " Invalid enum ";
    }
    else if(errID == AL_INVALID_VALUE)
    {
        return " Invalid value ";
    }
    else if(errID == AL_INVALID_OPERATION)
    {
        return " Invalid operation ";
    }
    else if(errID == AL_OUT_OF_MEMORY)
    {
        return " Out of memory like! ";
    }

    return " Don't know ";	
}

inline void CheckOpenALError(const char* stmt, const char* fname, int line)
{
	
	ALenum err = alGetError();
    if (err != AL_NO_ERROR)
    {		
//FIXME!		logMsg("OpenAL error %08x, (%s) at %s:%i - for %s", err, GetOpenALErrorString(err).GetConstString(), fname, line, stmt);
        //abort();
    }
};

#ifndef AL_CHECK
#ifdef _DEBUG
       #define AL_CHECK(stmt) do { \
            stmt; \
            CheckOpenALError(#stmt, __FILE__, __LINE__); \
        } while (0);
#else
    #define AL_CHECK(stmt) stmt
#endif
#endif

#endif

#endif
