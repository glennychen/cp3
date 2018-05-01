// 11727 Cost Cutting
#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main() {
  const int MEDIAN_INDEX = 1;
  int t;
  int a, b, c;
  cin >> t;

  for(int i=0; i<t; ++i) {
    cin >> a >> b >> c;
    array<int, 3> arr = {a, b, c};
    sort(arr.begin(), arr.end());
    cout << "Case " << i+1 << ": " << arr[MEDIAN_INDEX] << endl; // remember to output the new line at the end
  }
}
