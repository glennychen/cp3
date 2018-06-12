#include <iostream>
#include <string>

using namespace std;

int main()
{
  string a, b;
  cin >> a >> b; // you can read two strings in one line
  if (a == b) cout << "Equal" << endl;
  if (a < b) cout << b << " is larger" << endl;
  if (a > b ) cout << a << " is larger" << endl;

  return 0;
}
