#include <iostream>

using namespace std;

int main()
{

  int i=0, &r1=i;
  double d=0, &r2=d;
  r2=3.14159; cout << r2 << endl;
  r2=r1; cout << r2 << endl;
  i = r2; cout << i << endl;
  r1 = d;

  return 0;
}
