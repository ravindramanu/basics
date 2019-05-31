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

int noOfWords2(const char * character){
  const char * prevchar = character;
  int wordCount = 0;

  while (*character) {
    if ((!((*character) == ' ' || (*character == '.') || (*character == ','))) \
    && *prevchar== ' ' ) {
      ++wordCount;
    }
    prevchar = character;
    ++character;
  }

  if (!((*character) == ' ' || (*character == '.') || (*character == ','))) {
    ++wordCount;
  }
  return wordCount;
}

int main(){
  int a = noOfWords2(problem1);
  std::cout << a << '\n';
  a = noOfWords2(problem5);
  std::cout << a << '\n';
  a = noOfWords2(problem4);
  std::cout << a << '\n';
  a = noOfWords2(problem2);
  std::cout << a << '\n';
  a = noOfWords2(problem3);

  std::cout << a << '\n';
  return 0;
}
