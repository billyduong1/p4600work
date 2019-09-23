#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

	FILE * input_file;			//makes it into a file

	float i=0;
    float x=0;
    float y=0;

    input_file = fopen("sin_function","w");		//names the file in a text form
    
    for(i=0; i<360; ++i)		//angles to 6360 deg
    {
    	x = i*(M_PI/180);   	//calc to radians
    	y = sin(x);				//the sine of that radian

    	printf("The Sine of %f is %f\n", x, y);		
    	fprintf(input_file,"\n%f %f",x,y);		//prints the x and y to the words deoc 
	    

    }

    fclose(input_file);		//closes the file 

    return 0;
}