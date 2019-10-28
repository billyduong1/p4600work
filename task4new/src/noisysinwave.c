#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "noisysinwave.h"

double noisysinwave(int size)
{
	FILE * input_file; //makes it into a file 

    float x=0;
    float y=0;
    int i =0;

	input_file = fopen("noisysinwave.dat","w");	//names the file "noisysinwave"


	srand(time(NULL));		//gives me random numbers based on system time 
	//int r = rand();


	//float r = rand()%10;	//varies r into 10%


 for(i=0; i<360; ++i)			//angles to 360 deg
    {

    	x = i*(M_PI/180);   	//calc to radians
    	y = sin(x);				//the sine of that radian

    	float r = (float)rand()/(float)RAND_MAX;

    	y+=(r/10);

    	printf("%f\n",y);		
    	fprintf(input_file,"\n%f", y);		//prints the x and y to the words deoc 
	    
	}

	fclose(input_file);		//closes the file 


	return 0;
}