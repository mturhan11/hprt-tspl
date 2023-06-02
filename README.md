# hprt-tspl

=========================================
= HPRT TSPL Print Tool v0.2             =
=========================================
	-v			Show version
	-h			Show help
	-d			Show debug info

	-a			Auto connect without name,vid,pid
	-c<arg>			Connect with usb or network
	-n<printername>		Set the printer name
	-vid<vid>		Set the printer vid
	-pid<pid>		Set the printer pid
	-ip<ip>,<port>		Set the printer ip
	-P<filename>		Print the text file with TSPL

FOR USB
=========================================
Example 1: hprt -cusb -nLPQ58 -vid0x20d1 -pid0x7008 -P/temp/printfile.txt
Example 2: hprt -cusb -a -P/temp/printfile.txt

FOR NETWORK
=========================================
Example 3: hprt -cnetwork -nLPQ58 -ip192.168.1.21,9100 -P/temp/printfile.txt


SAMPLE BARCODE
=========================================
SIZE 58 mm, 25 mm
DIRECTION 1,0
REFERENCE 0,0
OFFSET 10 mm
SET PEEL OFF
SET TEAR ON
CLS
TEXT 10,10,"3",0,1,1,"xxxx"
BARCODE 200,40,"128",40,0,0,2,2,"55111364124"
TEXT 10,35,"3",0,1,1,"xxx"
TEXT 10,60,"3",0,1,1,"1234567890"
TEXT 10,85,"3",0,1,1,"F / 12"
TEXT 10,110,"3",0,1,1,"sadsda"
TEXT 10,135,"3",0,1,1,"asdasdad"
TEXT 10,160,"3",0,1,1,"asdad"
TEXT 10,185,"3",0,1,1,"asdasd"
PRINT 1,1
