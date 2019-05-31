/*
 * String problem statement: "Alpha is a god dog , that barks."
 * From examination that the number of words are 7.
 * Iterate over the characters in the long string and remove any , and .
 * every space bar --> increment word count.
 */

#include <string>
#include <iostream>
using namespace std;

// Rules: 1. Sentence can have white spaces, commas and periods.

const char * problem1 = "Alpha is a god dog, that barks";
const char * problem5 = "Alpha is a god dog , that barks.";
const char * problem4 = "Alpha is a god dog , that barks ";
const char * problem2 = "Alpha is a god dog , that barks .";
const char * problem3 = "Alpha is a god dog , that barks . ";

int noOfWords (const char * character){

  bool discardFlag = false;
  int wordCount = 0;

  while (*character) {
    if ((*character == ' ') || (*character == '.') || (*character == ',')) {
      discardFlag = true;
    }
    else if (discardFlag == true) {
      if (!((*character == ' ') || (*character == '.') || (*character == ','))) {
        ++wordCount;
      }
      discardFlag = false;
    }
    ++character;
  }

  return ++wordCount;
}

int main(){
  int a = noOfWords(problem1);
  std::cout << a << '\n';
  a = noOfWords(problem5);
  std::cout << a << '\n';
  a = noOfWords(problem4);
  std::cout << a << '\n';
  a = noOfWords(problem2);
  std::cout << a << '\n';
  a = noOfWords(problem3);

  std::cout << a << '\n';
  return 0;
}
