#include <stdio.h>

int givenarray[] = {5,7,2,8,4,9,0};

void swap(int * x, int * y) {
  int temp = *x;
  *x=*y;
  *y=temp;
}

void print_array(int array[], int size){
  printf("[ ");
  for(int i=0; i<(size-1); i++){
    printf("%d ", array[i]);
  }
  printf("]\n");
}

void bubblesort(int array[], int size){
  int i, j;

  for(i=0; i<(size-1); i++){
    for(j=i+1; j<(size-1); j++){
      if (array[j] < array[i]) {
        swap(&array[j], &array[i]);
      }
    }
  }
}

int main(){
  int arraysize = sizeof(givenarray)/sizeof(givenarray[0]);
  print_array(givenarray, arraysize);
  //bubblesort(givenarray, arraysize);
  //print_array(givenarray, arraysize);
  return 0;
}
