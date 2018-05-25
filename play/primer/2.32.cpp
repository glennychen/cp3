#include <iostream>

using namespace std;

int main()
{
  //int null =0, *p = null; //invalid conversion from ‘int’ to ‘int*’
  constexpr int* null = 0;
  constexpr int *p = null;
}
