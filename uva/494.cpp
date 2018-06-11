// Uva 494 - Kindergarten Counting Game
// https://www.geeksforgeeks.org/regex-regular-expression-in-c/
//http://en.cppreference.com/w/cpp/iterator/istream_iterator

#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string s, string split_string)
{
  regex reg(split_string);
  sregex_token_iterator iter(s.begin(), s.end(), reg, -1);
  sregex_token_iterator end;
  vector<string> vec(iter, end);

  //copy(iter, end, ostream_iterator<string>(cout, "\n"));
  return vec;
}

int main() {
  regex word("[a-zA-Z]+");
  //regex word("\\w+");
  string input;
  while(getline(cin, input)){
    if (!cin) break;
    //    cout << input << endl;
    //    smatch m;
    //    regex_search(input, m, word);
    //    cout << m.size() << endl;
    //    int count = 0;
    //    for (const auto& e: m){
    //      cout << e << " " ;
    //      ++count;
    //    }
    //    cout << count << endl;

    string output = regex_replace(input, word, " ");
    vector<string> output_v = split(output, " ");
    cout << input << endl;
    for(const auto& e:output_v){
      cout << "e:" << e << " ";
    }
    cout << endl;
    cout << output_v.size() << endl;
    //istringstream iss(input);
    //    vector<string> tokens {istream_iterator<string>{iss},
    //	                   istream_iterator<string>{}};

    //    int count=0;
    //    for(const auto& token:tokens){
    //      string output = regex_replace(token, word, " ");
    //      auto index = output.find(" ");
    //      if (index != string::npos) {
    //	++count;
    //      }
    //    }

    //    cout << count << endl;

    //cout << tokens.size() << endl;
  }
  return 0;
}
