#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	/* how to commetns tuff */ 
	//how to comment a single line
/*
	float angle;
	//setting a variable 
	float opp[30];
	int i;

	for(//angle =0; angle <= M_PI/2; angle +=M_PI/20) 
		i=0; i<30;i++)
	{
		angle = (M_PI/2)*(i/30.0);
		opp[i] = hypot * sin(angle);	//works in radians

		printf("opposite side = %f cm", opp[i]); 
		printf("angle 5 = %f",opp[4]);
	}
*/
	float data [32] ={0.068038, 0.173967, 0.439303, 0.615258, 0.789436, 0.770980,
	 0.890924, 1.034431, 0.955555, 0.991579, 0.919359, 0.857244, 0.680064, 0.558250, 
	 0.473129, 0.278329, 0.027142, -0.151631, -0.454363, -0.534177, -0.803847, -0.882892, 
	 -0.996433, -0.919950, -1.068664, -1.000596, -0.997921, -0.909708, -0.607322, -0.611919, 
	 -0.380097, -0.127268};

	float mean;
	float std_dev;

	/*	Here you can put the code to find the standard deviation of the data array	*/
	/*  ==== START OF YOUR CODE ==== */
	int i;
 	float sum;
 	float root;
float brac;	

 	sum = mean = std_dev = brac = 0;			//sets float to 0 

	for(i=0;i<32;++i)							//adds up all the numbers 
	{
		sum += data[i];
	}

	mean = sum/32;								//calculates the mean 

									//calling std_dev formula inside root sign

	for(i=0; i<32; ++i)
	{
		brac += pow(data[i] - mean, 2);	 		//calculates the inside root sign
	}

	
    root= brac/31;
    std_dev = pow(root, 0.5);					//standard deviation formula 

	/*  ==== END OF YOUR CODE ==== */
	/* These lines will output the results to console */

	printf("\nMean = %f", mean);
	printf("\nStandard deviation = %f", std_dev);

	
	return 0;  // Functions which return a value MUST contain at least one return statement
}