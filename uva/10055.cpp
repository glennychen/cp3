// UVA 10055 - Hashmat the Brave Warrior
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  long long a, b; // sizeof(long long) >= sizeof(long), at least 64 bits
  while(scanf("%lld %lld", &a, &b) != EOF) {
    cout << abs(a-b) << endl;
  }
  return 0;
}
