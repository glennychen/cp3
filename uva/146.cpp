// UVA 146 - ID Codes
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  string input;
  for(;;){
    cin >> input;
    if (input == "#") break;
    if (next_permutation(input.begin(), input.end())) {
      for(const auto& e:input) {
	cout << e;
      }
      cout << endl;
    } else {
      cout << "No Successor" << endl;
    }
  }
  return 0;
}
