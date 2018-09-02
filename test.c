#include<stdio.h>
#include<time.h>
#include <stdlib.h>
#include<string.h>


#define DEBUG 1


#define LOGDEBUG_0(fmt)  if(DEBUG) PRINT0("[%s %s %d %s]: " fmt,TIMENOW,__FILE__,__LINE__,__FUNCTION__)
#define PRINT0(fmt, ...) fprintf(TARGETFILE1,fmt, __VA_ARGS__)



#define TARGETFILE1  FileName1()
//#define TIMENOW timeNow()
#define TIMENOW timeNow2()

static inline FILE * FileName1()
{
	FILE *fp1=NULL;
	fp1 = fopen("/home/harish/learning/C/logTest1.log","w+");
    if(fp1 != NULL )
    {
    	printf("File is created successfully \n");
    	return fp1;
    }
    else
    	return NULL;

}

static inline char * timeNow()
{
	//static char *buffer[64];
	//time_t tim=time(NULL);
	time_t tim;
	time(&tim);
 	char *c_time=ctime(&tim);
 	//strncpy(buffer,64,c_time);
 	//printf("%s",c_time);
 	if(c_time != NULL)
 	{
 		printf("Time calculated successfully \n");
 		return c_time;
 		//return buffer;
 	}

	return NULL;
}

static inline char *timeNow2() {
    static char buffer[64];
    time_t rawtime;
    struct tm *timeinfo;
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    
    strftime(buffer, 64, "%Y-%m-%d %H:%M:%S", timeinfo);
    printf("Time calculated successfully \n");
    
    return buffer;
}

int main(int argc, char const *argv[])
{
	/* code */

 	LOGDEBUG_0("Hello this is log print debug statement test1");
 
	return 0;
}
