#ifndef ERROR_H_
#define ERROR_H_

/*///////////////////////////////////////////////////////////////////
// "error_code" definitions
///////////////////////////////////////////////////////////////////*/
#define RESLUT_SUCCESS					        0		// no error

/*///////////////////////////////////////////////////////////////////
// common  error code definitions
///////////////////////////////////////////////////////////////////*/
#define E_INVALID_PARAMETER			                           -1
#define E_NOT_ENOUGH_BUFFER			                           -2
#define E_INVALID_MODEL_TYPE			                           -3
#define E_NOT_SUPPORT				                           -4
#define E_BAD_HANDLE					                   -6
#define E_NOT_IMPLEMENTED				                   -7
#define E_INVALID_MODEL				                           -8
#define E_NOT_ENOUGH_MEMORY			                           -9
#define E_NOT_TARGET_PRINTER                                               -10
#define E_INVALID_ENVIRONMENT                                              -11    

/* Image Error */
#define E_OPEN_FILE_ERROR				                   -20
#define E_LOAD_IMAGE_ERROR				                   -21
#define E_ANALYSIS_IMAGE_ERROR			                           -22
#define E_IMAGE_BAD_SIZE				                   -25

/* Data is not correct */
#define E_INVALID_DATA                                                     -30    

#define E_BASE                                                             -100
/* Driver */ 
#define E_DRIVER_INCORRECT_DATA                                            -101
#define E_DRIVER_PRINTER_STATE_ERROR                                       -102
/* IO */

/* io setting error */
#define E_IO_ERROR					                   -300
#define E_IO_INVALID_SETTING		 	                           -301    
#define E_IO_NAME_TOO_LONG			                           -302
#define E_IO_OS_VERSION_TOO_LOW		                                   -304

#define E_IO_INVALID_HANDLE			                           -308
#define E_IO_PORT_NOT_OPEN				                   -309
#define E_IO_PORT_ALREADY_OPEN			                           -310

/* io open error */
#define E_IO_OPEN_FAILED				                   -311   
/* io attr get/set error */
#define E_IO_GETATTR_ERROR				                   -312    
#define E_IO_SETATTR_ERROR				                   -313
/* io write error */
#define E_IO_WRITE_FAILED				                   -321    
#define E_IO_WRITE_TIMEOUT				                   -322    
/* io readerror */
#define E_IO_READ_FAILED				                   -331    
#define E_IO_READ_TIMEOUT				                   -332  
/* io flush error */
#define E_IO_FLUSH_FAILED				                   -341
/* serial port error */
#define E_IO_SERIAL_INVALID_BAUDRATE	                                   -351
#define E_IO_SERIAL_INVALID_HANDSHAKE	                                   -352
/* ethernet port error*/
#define E_IO_EHTERNET_CONNECT_ABORT                                        -361
/* USB port error */
#define E_IO_INVALID_USB_PATH	                                           -371
#define E_IO_USB_DEVICE_NOT_FOUND	                                   -372
#define E_IO_USB_DEVICE_BUSY	                                           -373
// msr track
#define E_MSR_TRACK_NOT_READY			                           -401
// smard card
#define E_SMART_CARD_NOT_READY			                           -411
//encrypt head
#define E_EH_SET_ERROR				                           -501
#define E_EH_DECRYPT_ERROR				                   -511
#endif

/* Extern LIBUSB error */
#define E_IO_LIBUSB_E_START	                                           -1100
#define E_IO_LIBUSB_E_END				                   -1200
/** Success (no error) */
#define E_LIBUSB_SUCCESS                                                   -1100
/** Input/output error */   
#define E_LIBUSB_ERROR_IO                                                  -1101
/** Invalid parameter */
#define E_LIBUSB_ERROR_INVALID_PARAM                                       -1102
/** Access denied (insufficient permissions) */
#define E_LIBUSB_ERROR_ACCESS                                              -1103
/** No such device (it may have been disconnected) */
#define E_LIBUSB_ERROR_NO_DEVICE                                           -1104
/** Entity not found */
#define E_LIBUSB_ERROR_NOT_FOUND                                           -1105
/** Resource busy */
#define E_LIBUSB_ERROR_BUSY                                                -1106
/** Operation timed out */
#define E_LIBUSB_ERROR_TIMEOUT                                             -1107
/** Overflow */
#define E_LIBUSB_ERROR_OVERFLOW                                            -1108
/** Pipe error */
#define E_LIBUSB_ERROR_PIPE                                                -1109
/** System call interrupted (perhaps due to signal) */
#define E_LIBUSB_ERROR_INTERRUPTED                                         -1110
/** Insufficient memory */
#define E_LIBUSB_ERROR_NO_MEM                                              -1111
/** Operation not supported or unimplemented on this platform */
#define E_LIBUSB_ERROR_NOT_SUPPORTED                                       -1112
/** Other error */
#define E_LIBUSB_ERROR_OTHER                                               -1199


