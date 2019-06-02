/*Problem statement: +-/*
  * Use OOPS
  * Use c++
  */
#include <iostream>
using namespace std;

class Operand {
private:
  double operand;

public:
  Operand(double operand){
    this->operand = operand;
  }

  Operand(){}

  Operand operator + (Operand const &obj){
    Operand tempobj;
    tempobj.operand = operand + obj.operand;
    return tempobj;
  }

  Operand operator - (Operand const &obj){
    Operand tempobj;
    tempobj.operand = operand - obj.operand;
    return tempobj;
  }

  Operand operator * (Operand const &obj){
    Operand tempobj;
    tempobj.operand = operand * obj.operand;
    return tempobj;
  }

  Operand operator / (Operand const &obj){
    Operand tempobj;
    tempobj.operand = operand / obj.operand;
    return tempobj;
  }

  void print(){
    std::cout << "The variable value is " << operand << '\n';
  }
};


int main() {
  Operand a(10.24), b(0.64), c;
  c = b / a;
  c.print();
  return 0;
}
