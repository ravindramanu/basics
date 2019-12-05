#include <stdio.h>

int givenarray[] = {5,7,2,8,4,9,0};

void swap(int * x,  int * y){
  int temp = *x;
  *x = *y;
  *y = temp;
}


void print_array(int array[], int size){
  printf("[ ");
  for(int i=0; i<(size-1); i++){
    printf("%d ", array[i]);
  }
  printf("]\n");
}

void selectionsort(int array[], int size){
  int i, j, min_index;
  for(i=0; i<(size-1); i++){
    min_index=i;
    for(j=i+1; j<(size-1); j++){
      if (array[min_index] > array[j]) {
        min_index = j;
      }
    }
    swap(&array[min_index], &array[i]);
  }
}

int main() {

  int arraysize = sizeof(givenarray)/sizeof(givenarray[0]);
  print_array(givenarray, arraysize);
  selectionsort(givenarray, arraysize);
  print_array(givenarray, arraysize);
  return 0;
}
