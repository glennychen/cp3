#include <iostream>

using namespace std;

int main()
{
  unsigned u =10, u2=42;
  cout << u2-u << endl;
  cout << u -u2 << endl; // study, wrap around

  int i = 10, i2=42;
  cout << i2 - i << endl;
  cout << i - i2 << endl;

  cout << i -u << endl; // study, print 0
  cout << u - i << endl; //study, print 0

  unsigned char c1 =0, c2=1;
  cout << c1 -c2 << endl; // study, wrap around, unsigned char, 0-255 inclusive

  unsigned char c3 = -1;
  cout << c3 << endl;

  cout << " a b c d ef g"
    " a b c d eee" << endl;

  int m = 9; cout << m << endl;
  //int m1 = 09; cout << m1 << endl;
  cout << 314159E-5L << endl;
  cout << 1E-3F << endl;

  
  return 0;
}
