#include <stdio.h>

int givenarray[] = {0,2,4,5,7,8,9};
int givenkey = 4;

int binarysearch(int array[], int lo_index, int hi_index, int key){

  int mid = (lo_index+hi_index)/2;

  printf("Low: %d High: %d Mid: %d \n", lo_index, hi_index, mid);

  if (array[mid] == key) {
    printf("Key equal to mid. Key: %d, Array[%d]: %d\n", key, mid, array[mid]);
    return 0;
  }
  else if (key < array[mid]) {
    printf("Key less than mid. Key: %d, Array[%d]: %d\n", key, mid, array[mid]);
    binarysearch(array, lo_index, (mid-1), key);
  }
  else if (key > array[mid]) {
    printf("Key more than mid. Key: %d, Array[%d]: %d\n", key, mid, array[mid]);
    binarysearch(array, (mid+1), hi_index, key);
  }
  else
    return -1;

  return 0;
}

int main(){
  int arraysize = sizeof(givenarray)/sizeof(givenarray[0]);
  int loidx = 0;
  int hiidx = arraysize - 1;

  int result = binarysearch(givenarray, loidx, hiidx, givenkey);
  (result == 0) ? printf("Key found.\n") : printf("Key not found.\n");
  return 0;
}
