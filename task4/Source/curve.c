#include <stdio.h>
#include <stdlib.h>
#include <math.h>




int movingAvg(int *ptrArrNumbers, long *ptrSum, int position, int length, int nextNumber)
{
  *ptrSum = *ptrSum - ptrArrNumbers[position] + nextNumber;	//Subtract the oldest number from the prev sum, add the new number
  
  ptrArrNumbers[position] = nextNumber;		//Assign the nextNumber to the position in the array
 
  return *ptrSum / length;		//return the average
}





int main(int argc, char *argv[])
{
  // a sample array of numbers 
  int sample[] = {50, 10, 20, 18, 20, 100, 18, 10, 13, 500, 50, 40, 10};
  
  // the size of this array represents how many numbers will be used to calculate the average

  int arrNumbers[5] = {0};

  int position = 0;
  int newAvg = 0;
  long sum = 0;


  int length = sizeof(arrNumbers) / sizeof(int);
  int count = sizeof(sample) / sizeof(int);


  for(int i = 0; i < count; i++)
  {

    newAvg = movingAvg(arrNumbers, &sum, position, length, sample[i]);
    printf("The new average is %d\n", newAvg);
    position++;


    if (position >= length)
    {
      position = 0;
    }

  }

  return 0;
}