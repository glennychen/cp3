// Uva 494 - Kindergarten Counting Game
// https://www.geeksforgeeks.org/regex-regular-expression-in-c/
//http://en.cppreference.com/w/cpp/iterator/istream_iterator

#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
  regex word("[a-zA-Z]+");
  string input;
  while(getline(cin, input)){
    if (!cin) break;
    smatch m;
    regex_search(input, m, word);
    int count = 0;
    for (const auto e: m){
      ++count;
    }
    cout << count << endl;
    //    string output = regex_replace(input, word, " ");
    //    istringstream iss(output);
    //    vector<string> tokens {istream_iterator<string>{iss},
    //	                   istream_iterator<string>{}};
    //    cout << tokens.size() << endl;
  }
  return 0;
}
