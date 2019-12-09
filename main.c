#include <stdio.h>
#include <stdlib.h>
#include <math.h>	
#include <visa.h>

void main()
{
	unsigned char resultBuffer[256];				// holds input values before conversion
	ViStatus status = VI_SUCCESS;
	ViFindList resourceList;
	ViUInt32 num_inst;
	ViUInt32 resultCount;

	ViSession defaultRM, scopeHandle, FGHandle;		// scopeHandle, FGHandle
	ViChar description[VI_FIND_BUFLEN];





	status = viOpenDefaultRM(&defaultRM);
	if(status == VI_SUCCESS)
	{

		status = viFindRsrc(defaultRM,"USB[0-9]::0x0699?*INTSR",&resourceList,&num_inst,description);
		if(status == VI_SUCCESS)
		{

			status = viOpen(defaultRM,descrpition,	VI_NULL,VI_NULL,&scopeHandle);
			if(status == VI_SUCCESS)
			{
				printf("\nOpened %s\n",description);

				identify(scopeHandle, resultBuffer, resultCount);
				identify(FGHandle, resultBuffer, resultCount);
						
				printf("\nResult count = %d",resultCount);
				printf("\nResult buffer = %s\n",resultBuffer);

				ifOpened(scopeHandle, resultCount);

				getCurve(scopeHandle, dataBuffer, 2500); //getcurve for data points

				
				ret(scopeHandle, resultCount); 	//scale of scope
				printf("Scale is %s\n",ret);

				float volts;					//prints volts
				sscanf(ret,"%f",&volts);
				printf("\nvolts = %f",volts);
			





			}		


			else
			{
				printf("\nFailed to open %s",description);
			}
		}
		else
		{
			printf("\nCouldn't find any instruments");
		}
	}
	else
	{
		printf("\nFailed to open defaultRM");
	}
}
