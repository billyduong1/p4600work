#include <stdio.h>
#include <stdlib.h>
#include <math.h>	
#include <visa.h>


ViStatus set_voltage(ViSession handle, float volts)
{
	char command[36];
	sprintf(command,"CH1:scale %E\n", volts );
	ViStatus status = viwrite(handle, command, strlen(command), &resultcount);
	return status;
}



ViStatus get_curve(ViSession handle, char* dataBuffer, int npoints )
{
	ViUInt32 resultCount;
	int resultcount;
	int status;
	viWrite(handle, "CURV?\n", 6, &resultCount);
	sleep(2);
	status = viRead(handle, dataBuffer, npoints, &resultCount);
	return status;
}



void main(int argc, char** argv)
{
	unsigned char resultBuffer[256],division[30];
	ViStatus status = VI_SUCCESS;
	ViFindList resourceList;
	ViUInt32 num_inst;
	ViUInt32 resultCount;
.
	ViSession defaultRM, scopeHandle;
	ViChar description[VI_FIND_BUFLEN];
	char dataBuffer[2500];

	int y[2500];
	float fdataBuffer[2500];
	int lsb;
	float voltscale;
	float conversion;
	int msb;


	status = viOpenDefaultRM(&defaultRM);

	if(status == VI_SUCCESS)
	{
		status = viFindRsrc(defaultRM,"USB[0-9]::?*INSTR",	&resourceList,&num_inst,description);
		if(status == VI_SUCCESS)
		{
			status = viOpen(defaultRM,description,	VI_NULL,VI_NULL,&scopeHandle);

			if(status == VI_SUCCESS)
			{
				printf("\nOpened %s\n",description);

				viWrite(scopeHandle,"*IDN?\n",6,&resultCount);
				viRead(scopeHandle,resultBuffer,256,&resultCount);

				printf("\nResult count = %d",resultCount);
				printf("\nResult buffer = %s\n",resultBuffer );

				viWrite(scopeHandle,"CH1:SCA?\n",9,&resultCount); 	//conversion to voltage scale of the scope 
                viRead(scopeHandle,division,256,&resultCount);
                sscanf(division,"%f",&voltscale);					//calls the division into a float 
                //printf("\nscale = %fV\n",voltscale);
                conversion = voltscale*8/256;						//voltscale and conversion wont print 
                //printf("conversion scale = %f\n",conversion);
				

				set_voltage(scopeHandle, 1000);				//sets voltage
				get_curve(scopeHandle,dataBuffer, 2500);		//sets curve # of points 



				for(int i = 0; i<2500; i++)
				{
					y[i] = dataBuffer[i];						//turns each point into a databuffer
					//printf("\nRead = %d",y);
				}

				

				for(int n =0; n<2500; n++)
				{
					fdataBuffer[n] = y[n];						//turns databuffer into float databuffer
					printf("\nVoltage = %f",fdataBuffer[n]);
				}
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