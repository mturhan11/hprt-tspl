#ifndef _SDK_COMMON_API_H
#define _SDK_COMMON_API_H

#ifdef LINUX
#define SDK_API __attribute__ ( (visibility( "default" ) ) )
#define CALL_STACK
#define TCHAR char
#else
#include <tchar.h>

#ifdef EXPORT_STDCALL
#define CALL_STACK __stdcall
#else
#define CALL_STACK __cdecl
#endif
#ifndef SDK_API
#ifdef __cplusplus
#define SDK_API //extern "C" __declspec( dllexport )  --- 使用模块定义文件.
#else
#define SDK_API //__declspec( dllexport )
#endif
#endif
#endif

SDK_API void CALL_STACK FormatError( int errorNo, int langid, unsigned char* buf, int pos, int bufSize );

SDK_API int CALL_STACK PrinterCreator( void** phandle, const TCHAR* model );

SDK_API int CALL_STACK SetLog(int enable, const TCHAR* path);

SDK_API void* CALL_STACK PrinterCreatorS( char* model );

SDK_API int CALL_STACK PrinterDestroy( void* handle );

SDK_API int CALL_STACK PortOpen( void* handle, const TCHAR* ioSettings );

SDK_API int CALL_STACK DriverPortOpen( void* handle, const TCHAR* driverName );

SDK_API int CALL_STACK PortClose( void* handle );

SDK_API int CALL_STACK DirectIO( void* handle, unsigned char* writedata, unsigned int writeNum, unsigned char* readData, unsigned int readNum, unsigned int* preadedNum );

SDK_API int CALL_STACK WriteData( void* handle, unsigned char* writeData, unsigned int writeNum );

SDK_API int CALL_STACK ReadData( void* handle, unsigned char* readData, unsigned int readNum, unsigned int* preadedNum );

SDK_API int CALL_STACK ReadDataEOF( void* handle, unsigned char* readData, unsigned int offSet, unsigned int bufLength, unsigned char soh, unsigned char eof, unsigned int* preadedNum );

SDK_API int CALL_STACK SendCommand( void* handle, char* writedata);


#endif
