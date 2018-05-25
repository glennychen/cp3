#include <iostream>

using namespace std;

class wrinkle {
public:
  wrinkle(int i): a(++i), b(++i), x(++i) {cout << a<< b<< x;}
private:
  int a;
  int x;
  int b;
};

int main()
{
  wrinkle w(0); //print 1, 3, 2
  
  return 0;
}
