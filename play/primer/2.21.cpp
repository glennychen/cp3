#include <iostream>

using namespace std;

int main()
{
  int i=0;
  double* dp = &i; //cannot convert int* to double* in initialization
  int *ip = i; //cannot convert from int to int*
  int *p = &i;
  
}
