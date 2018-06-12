#include <iostream>
#include <string>

using namespace std;

int main()
{
  string line;
  while(getline(cin,line)) { // read the whole line into a string
    cout << line;
    cout << endl; // the getline will discard the newline character
    break;
  }

  string word
  while(cin >> word) {
    cout << word;
  }
  return 0;
}
