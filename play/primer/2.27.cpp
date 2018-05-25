#include <iostream>

using namespace std;

int main()
{
  //int i=-1, &r=2; //invalid initialization of non-const reference of type ‘int&’ from an rvalue of type ‘int’
  //int *const p2 = &i2; ‘i2’ was not declared in this scope
  const int i = -1, &r=1; // correct
  //const int  *const p3 = &i2; // ‘i2’ was not declared in this scope
  //const int *p1 =&i2;// ‘i2’ was not declared in this scope
  //const int &const r2; //r2’ declared as reference but not initialized
  const int i2=i, &r3=i; // correct
  
}
