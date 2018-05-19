// 272 - TEX Quotes
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  string line;
  bool first_quote = true;
  while(getline(cin, line)){
    for(int i=0;i<line.size();++i){
      if(line[i]=='"'){
	if (first_quote) {
	  cout << "``";
	} else {
	  cout << "\'\'";
	}
	first_quote = !first_quote;
      } else {
	cout << line[i];
      }
    }
    if (!cin.eof()) {
      // assuming there is a new line form the input, how to fix this?
      cout << endl;
    }
    //        string::size_type found = line.find("\""); // p.657 STL reference
    //        if (found != string::npos) {
    //            if(first_quote) {
    //                line[found] = '`';
    //                line.insert(found, "`"); // not inserting char but string?
    //                first_quote = false;
    //            } else {
    //                line[found] = '\'';
    //                line.insert(found, "'");
    //                first_quote = true;
    //            }
    //        }
    //
    //        cout << line << endl;
  }
  return 0;
}
