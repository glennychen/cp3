// 11172 Relational Operator

#include <iostream>

using namespace std;

int main() {
  int sets;
  cin >> sets;
  char array[sets];
  for(int i=0; i< sets; ++i) {
    int a, b;
    cin >> a >> b;
    if (a>b) array[i] = '>';
    if (a<b) array[i] = '<';
    if (a==b) array[i] = '=';
  }
  for(int i=0; i< sets; ++i) {
    cout << array[i] << endl;
  }
  return 0;
}
