#include <stdio.h>
#include <stdlib.h>

int main()
{
	float input;

	do
	{
	printf("please enter a number");
	int correct = scanf("%f",&input);

	if (correct==1)
	{
		printf("\n the number you entered %f is correct",input);
	}
	else (correct=0);
	{
		printf("\n that is not a number");
	}
	


	printf("\nscanf returned %d. input was %f", correct,input);


}
