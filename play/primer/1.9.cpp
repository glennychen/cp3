#include <iostream>

using namespace std;

int main()
{
  int sum = 0;
  int n = 50;
  while (n<=100) {
    sum += n;
    ++n;
  }
  cout << sum << endl;
  return 0;
}
