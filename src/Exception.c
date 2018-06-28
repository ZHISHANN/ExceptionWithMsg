#include "CException.h"
#include "unity.h"
#include <stdio.h>
#include "Exception.h"
#include <malloc.h>
#include <stdarg.h>


void throwError(int errorCode,char *format, ...){
	va_list valist;
	int neededSize;
	char *buffer;
	Exception *ex = (Exception *)malloc(sizeof(Exception));

	va_start(valist,format);
	neededSize = vsnprintf(NULL,0,format,valist) + 1;
	buffer = malloc(neededSize);
	vsnprintf(buffer,neededSize,format,valist);
	va_end(valist);
	ex->errorCode = errorCode;
	ex->errorMsg = buffer;
	Throw(ex);
}

void freeError(Exception *ex)
{
  if(ex){
    if (ex->errorMsg)
      free(ex->errorMsg);
    free(ex);
  }
}
