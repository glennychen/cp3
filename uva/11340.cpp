#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;


int main() {
  const int ASCII = 255; // can we assume this?
  int num_tests;
  int num_paid_characters;
  int article_lines;
  string line;
  int pay_in_cents;
  cin >> num_tests;
  for(int i=0; i< num_tests; ++i) {
    vector<int> vec(ASCII, 0);
    cin >> num_paid_characters;
    for(int j=0;j<num_paid_characters; ++j) {
      char character;
      int cents;
      cin >> character >> cents;

      // Direct Addressing Table (like a hash table). CP3 p45
      // here, (int) char return a number, which can be served as the unique hash index
      vec[(int)character] = cents;
    }

    pay_in_cents = 0;
    cin >> article_lines; // cin will remove the new line character?
    getline(cin, line); // why?
    for (int k=0; k< article_lines; k++) {
      getline(cin, line);
      //cout << "k" << k << " " << line << endl;
      for(const auto& s: line) { // observe the element, use "const auto&"
	const char c = s; // The exact type when traversing std::string?
	pay_in_cents += vec[(int)c];
      }
    }
    //cout << pay_in_cents << endl;
    ios_base::fmtflags f( cout.flags() );
    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << (double) pay_in_cents/100 << "$";
    cout.flags(f);
    cout << endl;
  }


  return 0;
}
