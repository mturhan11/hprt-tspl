#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <iconv.h>
#include <string.h>
#include "tspl_sdk_api.h"

char *FileLines[48];
int FileLineCount=0;

char* substring(const char* str, size_t begin, size_t len)
{
  if (str == 0 || strlen(str) == 0 || strlen(str) < begin || strlen(str) < (begin+len))
    return 0;

  return strndup(str + begin, len);
}

int readfile(char* filename)
{
	FILE* filePointer;
	int bufferLength =2048;
	int i;
	char buffer[bufferLength];

	filePointer = fopen(filename, "r");

	if (filePointer == NULL){
	    printf("File not found. %s", filename);
	    return 0;
	}
	i=0;
	while (fgets(buffer, bufferLength, filePointer))  {
		FileLines[i]=strndup(buffer,sizeof(buffer));
		i=i+1;
	}
	FileLineCount=i;
	fclose(filePointer);

	return i;
}

int main(int argc, char *argv[])
{

	void *phandle = NULL;
	int result = 0;
    char error_msg[1024] = {0};
    int DLLSurumu=0;
    int AppSurumu=2;
    char argVersion[]="-v";
    char argHelp[]="-h";
    char* codePage="1254";

    system("clear");

    DLLSurumu= TSPL_GetDllVersion(NULL);

    if( argc < 2 ) {
          printf("Arguments not set.\n");
          printf("Please type -h for instructions\n");
    } else if (argc ==2)
    {
    	if (strcmp(argv[1],argVersion)==0)
    	   {
    			printf("Application version: 0.%d\n",AppSurumu);
    			printf("Library 'libtspl_sdk.so' version: %d\n",DLLSurumu);
    	   }
    	else if (strcmp(argv[1],argHelp)==0)
    	   {
    	    	printf("=========================================\n");
    	    	printf("= HPRT TSPL Print Tool v0.%d             =\n",AppSurumu);
    	    	printf("=========================================\n");
    	    	printf("	-v			Show version\n");
    	    	printf("	-h			Show help\n");
    	    	printf("	-d			Show debug info\n");
    	    	printf("\n");
    	    	printf("	-a			Auto connect without name,vid,pid\n");
    	    	printf("	-c<arg>			Connect with usb or network\n");
    	    	printf("	-n<printername>		Set the printer name\n");
    	    	printf("	-vid<vid>		Set the printer vid\n");
    	    	printf("	-pid<pid>		Set the printer pid\n");
    	    	printf("	-ip<ip>,<port>		Set the printer ip\n");
    	    	printf("	-P<filename>		Print the text file with TSPL\n");
    	    	printf("\n");
    	    	printf("FOR USB\n");
    	    	printf("=========================================\n");
    	    	printf("Example 1: hprt -cusb -nLPQ58 -vid0x20d1 -pid0x7008 -P/temp/printfile.txt\n");
    	    	printf("Example 2: hprt -cusb -a -P/temp/printfile.txt\n");
    	    	printf("\n");
    	    	printf("FOR NETWORK\n");
    	    	printf("=========================================\n");
    	    	printf("Example 3: hprt -cnetwork -nLPQ58 -ip192.168.1.21,9100 -P/temp/printfile.txt\n");
    	   }
    	else
    	{
    		printf("Unknown arguments.\n");
    	}
    } else
    {

    	char a[]="-a",c[]="-c",n[]="-n",vid[]="-vid",pid[]="-pid",p[]="-P",ip[]="-ip",d[]="-d";
    	char *aVal="",*cVal="",*nVal="",*vidVal="",*pidVal="",*pVal="",*ipVal="",*dVal="no",*ValCmp="yes";
    	for (int i = 0; i < argc; i++)
    	{
    		if (strcmp(strndup(argv[i],2),d)==0) {dVal="yes";}
    		if (strcmp(strndup(argv[i],2),a)==0) {aVal="yes";}
    		if (strcmp(strndup(argv[i],2),c)==0) {cVal=substring(argv[i],2, strlen(argv[i])-2);}
    		if (strcmp(strndup(argv[i],2),n)==0) { nVal =substring(argv[i],2, strlen(argv[i])-2);}
    		if (strcmp(strndup(argv[i],4),vid)==0) { vidVal =substring(argv[i],4, strlen(argv[i])-4);}
    		if (strcmp(strndup(argv[i],4),pid)==0) { pidVal =substring(argv[i],4, strlen(argv[i])-4);}
    		if (strcmp(strndup(argv[i],2),p)==0) { pVal = substring(argv[i],2, strlen(argv[i])-2);}
    		if (strcmp(strndup(argv[i],3),ip)==0) { ipVal = substring(argv[i],3, strlen(argv[i])-3);}
    	}

    	if (strcmp(aVal,"yes")==0)
    	{
			nVal="LPQ58";
			vidVal="0x20d1";
			pidVal="0x7008";
    	}

    	if (strcmp(dVal,ValCmp)==0)
    	{
    		printf("Auto Connect: %s\n",aVal);
    		printf("Connect Type: %s\n",cVal);
    		printf("Name: %s\n",nVal);
    		printf("vid: %s\n",vidVal);
    		printf("pid: %s\n",pidVal);
    		printf("IP Address: %s\n",ipVal);
    		printf("Document: %s\n",pVal);
    	}

    	if (readfile(pVal)!=0)
    	{
    					result = PrinterCreator(&phandle, nVal);

    		    	    if (0 != result)
    		    	    {
    		    	        FormatError(result, 0, (unsigned char*)error_msg, 0, sizeof(error_msg));
    		    	        printf("\n");
    		    	        printf("= ERROR ==============================\n");
    		    	        printf("%s\n", error_msg);
    		    	        printf("\n");
    		    	        return 0;
    		    	    }

    		    	    char ConnectionString[1024]="";
    		    	    if (strcmp(cVal,"usb")==0)
    		    	    {
    		    	    	strcat(ConnectionString,"USB");
    		    	    	strcat(ConnectionString,",");
    		    	    	strcat(ConnectionString,nVal);
    		    	    	strcat(ConnectionString,",vid=");
    		    	    	strcat(ConnectionString,vidVal);
    		    	    	strcat(ConnectionString,",pid=");
    		    	    	strcat(ConnectionString,pidVal);
    		    	    } else
    		    	    {
    		    	    	strcat(ConnectionString,"NET,");
    		    	    	strcat(ConnectionString,ipVal);
    		    	    }

    		    	    if (strcmp(dVal,ValCmp)==0)
    		    	        {
    		        			printf("Document Text (%d lines) :\n",FileLineCount);
    		        			for (int j = 0; j < FileLineCount; j++)
    		    	    	    {
    		        				printf("%s",FileLines[j]);
    		    	    	    }
    		    	        	printf("Connection String: %s\n",ConnectionString);
    		    	        }

    		    	    result = PortOpen(phandle, ConnectionString);
    		    	    if (0 != result)
    		    	    {
    		    	        FormatError(result, 0, (unsigned char*)error_msg, 0, sizeof(error_msg));
    		    	        printf("\n");
    		    	        printf("= ERROR ==============================\n");
    		    	        printf("%s\n", error_msg);
    		    	        printf("\n");
    		    	    }
    		    	    else
    		    	    {
    		    	        result = TSPL_ClearBuffer(phandle);
    		    	        result = TSPL_Setup(phandle,58,30,7,10,1,3,30);
    		    	        result = TSPL_SetTear(phandle,1);
    		    	        result = TSPL_SetCodePage(phandle,codePage);
    		    	        result = TSPL_Direction(phandle,1);
    		    	        //result = TSPL_Text(phandle, 10, 0, 3, 0, 1, 1, "Bilecik Agiz Ve Dis Sagligi Merkezi Binasi");

    		    	        for (int j = 0; j < FileLineCount; j++)
    		    	        {
    		    	        	// SIZE, DIRECTION and OFFSET
    		    	        	if (strstr(FileLines[j],"SIZE")!=NULL)
    		    	        	{
    		    	        		//
    		    	        	}
    		    	        	if (strstr(FileLines[j],"DIRECTION")!=NULL)
    		    	        	{
    		    	        		//
    		    	        	    		    	        	}
    		    	        	if (strstr(FileLines[j],"OFFSET")!=NULL)
    		    	        	{
    		    	        		//;
    		    	        	}
    		    	        	if (strstr(FileLines[j],"TEXT")!=NULL)
    		    	            {
    		    	        		//printf("%s",strstr(FileLines[j],"TEXT"));
    		    	        		char *StringText = strstr(FileLines[j],"TEXT");
    		    	        		char *Text[48];
    		    	        		int x=0;
    		    	        		StringText = substring(StringText,5,strlen(StringText)-5);
    		    	        		Text[x] = strtok(StringText,",");
    		    	        		while(Text[x] != NULL)
    		    	        		{
    		    	        			Text[++x] = strtok(NULL,",");
    		    	        		}
    		    	        		Text[2]=substring(Text[2],1,strlen(Text[2])-2);
    		    	        		Text[6]=substring(Text[6],1,strlen(Text[6])-3);
    		    	        		int TextInt[x];
    		    	        		for (int y = 0; y < x; y++)
    		    	        			{
    		    	        		    	//printf("%s \n",Text[y]);
    		    	        		    	sscanf(Text[y], "%d",&TextInt[y]);
    		    	        		    }
    		    	        			result = TSPL_Text(phandle,TextInt[0],TextInt[1],TextInt[2],
    		    	        								TextInt[3],TextInt[4],TextInt[5],
															Text[6]);
    		    	            }
    		    	        	if (strstr(FileLines[j],"BARCODE")!=NULL)
    		    	        	{
    		    	        	    //printf("%s",strstr(FileLines[j],"BARCODE"));
    		    	        	    char *StringBarcode = strstr(FileLines[j],"BARCODE");
    		    	        	    char *Barcode[48];
    		    	        	    int x=0;
    		    	        	    StringBarcode = substring(StringBarcode,8,strlen(StringBarcode)-8);
    		    	        	    Barcode[x] = strtok(StringBarcode,",");
    		    	        	    while(Barcode[x] != NULL)
    		    	        	    {
    		    	        	    	Barcode[++x] = strtok(NULL,",");
    		    	        	    }
    		    	        	    Barcode[2]=substring(Barcode[2],1,strlen(Barcode[2])-2);
    		    	        	    Barcode[8]=substring(Barcode[8],1,strlen(Barcode[8])-3);
    		    	        	    int BarcodeInt[x];
    		    	        	    for (int y = 0; y < x; y++)
    		    	        	    {
    		    	        	    	//printf("%s \n\n",Barcode[y]);
    		    	        	    	sscanf(Barcode[y], "%d",&BarcodeInt[y]);
    		    	        	    }

    		    	        	    result = TSPL_BarCode(phandle,BarcodeInt[0],BarcodeInt[1],0,
    		    	        	    		BarcodeInt[3],BarcodeInt[4],BarcodeInt[5],
											BarcodeInt[6],BarcodeInt[7],Barcode[8]);
    		    	        	}
    		    	        }
    		    	        /*result = TSPL_Text(phandle, 10,25,3,0,1,1,"ELANUR KILIC");
    		    	        result = TSPL_Text(phandle, 10,50,3,0,1,1,"55111364124");
    		    	        result = TSPL_Text(phandle, 10,75,3,0,1,1,"KADIN / 12 yil 9 ay");
    		    	        result = TSPL_Text(phandle, 10,100,3,0,1,1,"Hekim: SAMIRE SEZGIN");
    		    	        result = TSPL_Text(phandle, 10,125,3,0,1,1,"Poliklinik - Samire SEZGIN - (Nobet)(Adsm)");
    		    	        result = TSPL_Text(phandle, 10,150,3,0,1,1,"Tarih: 11.04.2021 14:23");
    		    	        result = TSPL_Text(phandle, 10,175,3,0,1,1,"Vaka : Normal");
*/
    		    	        result = TSPL_Print(phandle, 1, 1);

    		    	        /*
    		    	        SIZE 58 mm, 25 mm
    		    	        DIRECTION 1,0
    		    	        REFERENCE 0,0
    		    	        OFFSET 0 mm
    		    	        SET PEEL OFF
    		    	        SET TEAR ON
    		    	        CLS
    		    	        TEXT 10,0,"3",0,1,1,"Bilecik Agiz Ve Dis Sagligi Merkezi Binasi"
    		    	        BARCODE 200,30,"128",60,0,0,2,2,"55111364124"
    		    	        TEXT 10,25,"3",0,1,1,"ELANUR KILIC"
    		    	        TEXT 10,50,"3",0,1,1,"55111364124"
    		    	        TEXT 10,75,"3",0,1,1,"KADIN / 12 yil 9 ay"
    		    	        TEXT 10,100,"3",0,1,1,"Hekim: SAMIRE SEZGIN"
    		    	        TEXT 10,125,"3",0,1,1,"Poliklinik - Samire SEZGIN - (Nobet)(Adsm)"
    						TEXT 10,150,"3",0,1,1,"Tarih: 11.04.2021 14:23"
    						TEXT 10,175,"3",0,1,1,"Vaka : Normal"
    						PRINT 1,1
    						*/
    		    	    }
    		    	    result = PortClose(phandle);
    		    	    result = PrinterDestroy(phandle);
    	}


    }

	return result;
}


