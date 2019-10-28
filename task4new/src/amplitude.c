#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "amplitude.h"

double find_amplitude(double* data, int size) //function to find the amp
{
	float max=0;
	float min=0;
	float amplitude;

	for(int i=0; i<size; i++)		//finds max points of data
	{
		if(data[i]>max)
		{
			max=data[i];
		}
	}
	
	for(int i=0; i<size; i++)		//finds min points of data
	{
		if(data[i]<min)
		{
			min=data[i];
		}
	}

	amplitude = (max-min)/2;		//calculates amp

	return (amplitude);
}