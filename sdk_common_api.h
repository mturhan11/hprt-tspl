#ifndef _SDK_COMMON_API_H
#define _SDK_COMMON_API_H

#ifdef LINUX
#define SDK_API __attribute__ ( (visibility( "default" ) ) )
#define CALL_STACK
#define TCHAR char
#else
#include "auto_tchar.h"

#ifdef EXPORT_STDCALL
#define CALL_STACK __stdcall
#else
#define CALL_STACK __cdecl
#endif
#ifndef SDK_API
#ifdef __cplusplus
#define SDK_API extern "C"//extern "C" __declspec( dllexport )  --- ʹ��ģ�鶨���ļ�.
#else
#define SDK_API extern "C"//__declspec( dllexport )
#endif
#endif
#endif

SDK_API void  FormatError( int errorNo, int langid, unsigned char* buf, int pos, int bufSize );

SDK_API int  PrinterCreator( void** phandle, const TCHAR* model );

SDK_API int  SetLog(int enable, const TCHAR* path);

SDK_API void*  PrinterCreatorS( char* model );

SDK_API int  PrinterDestroy( void* handle );

SDK_API int  PortOpen( void* handle, const TCHAR* ioSettings );

SDK_API int  DriverPortOpen( void* handle, const TCHAR* driverName );

SDK_API int  PortClose( void* handle );

SDK_API int  DirectIO( void* handle, unsigned char* writedata, unsigned int writeNum, unsigned char* readData, unsigned int readNum, unsigned int* preadedNum );

SDK_API int  WriteData( void* handle, unsigned char* writeData, unsigned int writeNum );

SDK_API int  ReadData( void* handle, unsigned char* readData, unsigned int readNum, unsigned int* preadedNum );

SDK_API int  ReadDataEOF( void* handle, unsigned char* readData, unsigned int offSet, unsigned int bufLength, unsigned char soh, unsigned char eof, unsigned int* preadedNum );

SDK_API int  SendCommand( void* handle, char* writedata);


#endif
