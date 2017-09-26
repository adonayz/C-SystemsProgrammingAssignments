
#include <stdio.h>
#include <stdlib.h>
#include "connect.h"

/*Consumes an array and its size(number of elements) and produces the average of
 *the array, as well as its elements with highest and lowest values.*/
int analyze_array(int array_in[], int size){
  int counter;//for loop counter
  int total= 0;//will store the sum of elements
  int average;//will store average of array elements
  int highest= array_in[0]; //initializes variable by setting first element as value
  int lowest= array_in[0]; //initializes variable by setting first element as value

  if(size<1){

    printf("%d is not a valid entry for size. Size should be greater than 1 to calculate average.\n",size);
    return 1;//Indicates error

  }

  for(counter = 0; counter < size; counter++){
    int current = array_in[counter];//stores the element that is currently being acces from the array
    total+= current;// adds current number to the total

    if(current>highest){//compares current element with the previous/highest element
      highest = current;
    }

    if(current<lowest){//compares current element with the previous.lowest element
      lowest = current;
    }
  }
  average = total/size;//divides total value after for loop with size to find average
  printf("The average of the elements of the array is %d\n", average);
  printf("The element with the highest value is %d\n",highest);
  printf("The element with the lowest value is %d\n", lowest);

  return 0;// Indicates success

}
