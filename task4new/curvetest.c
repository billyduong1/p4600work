#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "amplitude.h"
#include "smoothcurve.h"




void main(int argc, char** argv)
{
	float a;
	int count=0;
	int count2=0;
	float amplitude;


	FILE *input_file;
	input_file = fopen(argv[1],"r");		//opens file



	if(input_file != NULL)		//works if open
	{
		while(fscanf(input_file,"%f",&a) != EOF)		//counts how much memory needed
		{
			count++;
		}
		double data[count];

		rewind(input_file);				
		for(int i=0;i<count;i++)
		{
			if(fscanf(input_file,"%lf",&data[i]) == EOF) 
			{
				break;
			}
		}
		fclose(input_file);


		amplitude = find_amplitude(data,count);
		printf("AMPLITUDE = %f\n", amplitude);		







		input_file = fopen("noisysinwave.dat","r");

		if(input_file != NULL)		//works of open
		{
			while(fscanf(input_file,"%f",&a) != EOF)		//how much memory needed 
			{
				count2++;
			}
			double data2[count2];

			rewind(input_file);
			for(int i=0;i<count2;i++)
			{
				if(fscanf(input_file,"%lf",&data2[i]) == EOF)
				{
					break;
				}
			}
			fclose(input_file);
			smooth_curve(data2, count2, 5);		//uses the data from noisysinwave.dat to calc smooth curve 
		}
		


	}
	else
	{
		printf("Couldn't open the target file");
		return;
	}

	

}