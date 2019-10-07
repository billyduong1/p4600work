#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/* JAMES: Good but what if array_length = 0?  */

float find_mean(float* input, int array_length) 		//function to calc the mean
{ 
    int i=0;
    float sum=0;
    float avg;
    for(i=0;i<array_length;i++)
    {
    	sum += input[i];
    }
    avg=sum/array_length;
    return avg;
} 




float find_standard_deviation(float* input, int count)			//function to calc the standard dev 
{
	int i=0; 
	float brac;
	float root=0;
	float deviation=0;

/* JAMES: This is going to recalculate the mean for EVERY element of the standard deviation which means 
the data will be looped through at least count*count times  */

	for(i=0; i<count; ++i)					
	{
		brac += pow(input[i] - find_mean(input,count), 2);	 		//calculates the inside root sign
	}
	root= brac/(count-1);
    deviation = pow(root, 0.5);
    return deviation;
}




void main(int argc ,char** argv)
{
	FILE * input_file;
	input_file = fopen(argv[1],"r");	//opens input_file

	float a;float b; int c=0; int i=0;

	if(input_file !=NULL)		//works if its open
	{
		while(fscanf(input_file,"%f %f",&a,&b)!=EOF)		//counts how much memory needed 
		{
			++i;
		}
	}

	printf("%d",i); 		//just to make sure the count is correct 



	rewind (input_file);		//closes the inputfile 

	float x[i];float y[i];


	for(c=0;c<i;c++)
	{
		fscanf(input_file,"%f %f",&x[c],&y[c]);

	}

	fflush(stdout);
	
	float mean;
	float std_dev;


	mean = find_mean(y,i);
	std_dev = find_standard_deviation(y,i);


	printf("\nMean = %f", mean);
	printf("\nStandard deviation = %f", std_dev);

	
	
}

