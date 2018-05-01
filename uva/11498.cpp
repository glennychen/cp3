//UVA11498
#include <iostream>
#include <string>

using namespace std;


string check_border(int a, int b, int c, int d)
{
  if (a==c || b == d) return "divisa";
  if (c > a) { //"E"
    if (d > b) return "NE";
    if (d < b) return "SE";
  }
  if (c < a) { //W
    if (d>b) return "NO";
    if (d<b) return "SO";
  }
}
int main() {
  int k;
  int a, b, c, d;
  cin >> k;
  while (k > 0) {
    cin >> a >> b;
    for (int i=0; i<k; ++i) {
      cin >> c >> d;
      cout << check_border(a, b, c, d) << endl;
    }
    cin >> k;
  }

  return 0;
}
