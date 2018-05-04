// UVA 10226 - Hardwood Species

#include <iostream>
#include <map>
#include <string>
#include <iomanip>
// std::map emplace, insert, remove, associate insert is slower, make_pair with brace-init
using namespace std;
int main() {
  int num_tests;
  string line;
  cin >> num_tests;
  cin.ignore(); // discard a single new line character

  getline(cin, line); // discard the blank line per the input format
  for (int i=0; i< num_tests; ++i) {
    map<string, pair<int, double>> woods;

    string tree_name;
    int size = 0;
    for(;;) {
      getline(cin, line);
      if (line.size() == 0) {
	break;
      } else if (!cin && cin.eof()){
	break;
	cout << "infinite" << endl;
      }
      auto pos = woods.find(line);
      //if (!pos) { // error: not the way to test the end position
      if (pos != woods.end()) {
	woods[line].first += 1;
      } else {
	woods.insert({line, {1, 0.0}});
      }
      ++size;
    }

    for (auto& m: woods) {
      // m.second.second = m.second.first/size; // int / will return int, not what we want here
      m.second.second = m.second.first/(double)size * 100;
    }

    for (auto m: woods) {
      cout << fixed << setprecision(4) ;
      cout << m.first << " " << m.second.second << endl;
    }

    //cout << endl; // error, this print out one extra line at the end
    if (i != num_tests-1) cout << endl;
  }
  return 0;
}
