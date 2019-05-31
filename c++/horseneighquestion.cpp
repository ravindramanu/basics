/*
 *
 * Problem statement:
 * nei = -1
 * neighneigh = 1
 * neingeighh = 2
 * Count the number minimum of possible horses as shown above
 *
 */

 #include <iostream>
 #include <string>
 using namespace std;

 int noOfHorses(const char * character){

   const char * prevChar = character;
   int score = 0;

   while (*character) {
     switch (*character) {
       case 'n': {
         ++score;
         break;
       }
       case 'e': {
         (*prevChar == 'n')? (++score) : (--score);
         break;
       }
       case 'i':{
         (*prevChar == 'e')? (++score) : (--score);
         break;
       }
       case 'g':{
         (*prevChar == 'i')? (++score) : (--score);
         break;
       }
       case 'h':{
         (*prevChar == 'g')? (++score) : (--score);
         break;
       }
       default: break;
     }
     prevChar = character;
     ++character;
   }


   if (score%5 == 0 && score != 0) {
     return 1;
   }
   else if (score%2 == 0) {
     return 2;
   }
   else {
     return -1;
   }
 }

int main() {

  char test[4] = "nei";
  char test2[11] = "neighneigh";
  char test3[11] = "neingeighh";
  char test5[6] = "neigh";

  int numberOfHorses = noOfHorses(test);
  std::cout << "Number of horses:" << numberOfHorses << '\n';
  numberOfHorses = noOfHorses(test2);
  std::cout << "Number of horses:" <<  numberOfHorses << '\n';
  numberOfHorses = noOfHorses(test3);
  std::cout << "Number of horses:" <<  numberOfHorses << '\n';
  numberOfHorses = noOfHorses(test5);
  std::cout << "Number of horses:" <<  numberOfHorses << '\n';

  return 0;
}
