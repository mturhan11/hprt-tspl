#ifndef TSPL_SDK_API_H
#define TSPL_SDK_API_H

#ifdef LINUX

#define SDK_API __attribute__ ((visibility("default")))
#define CALL_STACK
#define TCHAR char
#else

#include "auto_tchar.h"
#ifdef EXPORT_STDCALL
#define CALL_STACK __stdcall
#else
#define CALL_STACK __cdecl
#endif

#ifdef __cplusplus
#define SDK_API extern "C"//"C" __declspec(dllexport)
#else
#define SDK_API extern "C"//__declspec(dllexport)
#endif

#endif

#include "sdk_common_api.h"

SDK_API int  TSPL_SelfTest( void* handle );

SDK_API int  TSPL_PrintImage( void* handle, int xPos, int yPos, int mode, const char* fileName );

SDK_API int  TSPL_Setup( void* handle, int labelWidth, int labelHeight, int speed, int density, int type, int gap, int offset );

SDK_API int  TSPL_ClearBuffer( void* handle );

SDK_API int  TSPL_Box( void* handle, int xStart, int yStart, int xEnd, int yEnd, int thickness );

SDK_API int  TSPL_BarCode( void* handle, int xPos, int yPos, int codeType, int height, int readable, int rotation, int narrow, int wide, const char* data );

SDK_API int  TSPL_QrCode( void* handle, int xPos, int yPos, int eccLevel, int width, int mode, int rotation, int model, int mask, const char* data );

SDK_API int  TSPL_Text( void* handle, int xPos, int yPos, int font, int rotation, int xMultiplication, int yMultiplication, const char* content );

SDK_API int  TSPL_Print( void* handle, int num, int copies );

SDK_API int  TSPL_FormFeed( void* handle );

SDK_API int  TSPL_SetTear( void* handle, int enable );

SDK_API int  TSPL_SetRibbon( void* handle, int ribbon );

SDK_API int  TSPL_Offset( void* handle, int distance );

SDK_API int  TSPL_Direction( void* handle, int direction );

SDK_API int  TSPL_Feed( void* handle, int len );

SDK_API int  TSPL_Home( void* handle );

SDK_API int  TSPL_Learn( void* handle );

SDK_API int  TSPL_GetDllVersion( void* handle );

SDK_API int  TSPL_GetSN( void* handle, char* sn );

SDK_API int  TSPL_GetPrinterStatus(void* handle, int* status);

SDK_API int  TSPL_SetCodePage( void* handle, char* codepage );

SDK_API int  TSPL_PDF417( void* handle, int xPos, int yPos, int width, int height, int rotate, char* option, const char* data );

SDK_API int  TSPL_Block( void* handle, int xPos, int yPos, int width, int height, int font, int rotate, int xMultiplication, int yMultiplication, int space, int alginment, const char* data );

SDK_API int  TSPL_Reverse( void* handle, int xPos, int yPos, int width, int height );

SDK_API int  TSPL_GapDetect(void* handle, int paperLength, int gapLength);

SDK_API int  TSPL_BitMap(void* handle, int xPos, int yPos, int mode, int width, int height,  unsigned char* data);
 /*
 * SDK_API char*  CALL_STACK PrtGetPrinterID(void* handle,char* id);
 */
#endif

