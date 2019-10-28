  
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "smooth_curve.h"


double smooth_curve(double* data, int size, int points)  //fuction to smooth curve 
{
	FILE *input_file;
	float average;
	float sum;
	int round=0, i=0;

	if(points>size) return 0; //if number of points takent is bigger than data size, begining part 

	input_file = fopen("smooth_curve.dat", "w"); //open smooth_curve.dat

	if(input_file != NULL) //check if file is open
	{
		for(int i=0; i<(size-points); i++)      //ending part where #of points is bigger than data size 
		{	
			sum=0;

			for(int k=0; k<points; k++)
			{
				sum+= data[i+k];             
			}
			average = sum/points;						//averages the data points 
			fprintf(input_file, "%f\n", average);		//prints the average of the curve into smooth_curve.dat 
		}
	}
	fclose(input_file); 				//closes file 
}
