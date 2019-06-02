/*
 * BINARY SEARCH:
 * - It is mandaory that the data be sorted ahead of time in order to use
 *   this search algorithm. This doesnt work on unsorted data.
 * - It is a fast search algorithm which uses divide and conquer technique
 *
 */

#include <iostream>
using namespace std;

// Given an array of integers that is sorted ahead of time.
int A[10] = {0,1,2,3,4,5,6,7,8,9};

// search method
bool search(int array[], int length, int key){

  bool found = false;
  int lowerbound = 0, upperbound = length, midpoint;

  while (1) {
    std::cout << "lowerbound : " << lowerbound << " upperbound : " << upperbound << '\n';
    if (upperbound < lowerbound) {
      std::cout << "exit condition" << '\n';
      break;
    }
    midpoint = lowerbound + ((upperbound - lowerbound)/2);
    std::cout << "Mid point calculated: " << midpoint << '\n';

    if(key < A[midpoint]){
      upperbound = midpoint - 1;
      std::cout << "Upper bound changed: " << upperbound << '\n';
    }
    else if (key > A[midpoint]) {
      lowerbound = midpoint + 1;
      std::cout << "Lower bound changed:" << lowerbound << '\n';
    }
    else if (A[midpoint] == key){
      found = true;
      break;
    }
  }

  return found;

}

// Main driver program
int main(){

  int length = *(&A + 1) - A;

  if (search(A, length, 19)) {
    std::cout << "Element found" << '\n';
  }
  return 0;
}
