// UVA 10189 - Minesweeper
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int field_num = 1;
  for (;;) {

    int n, m;
    cin >> n >> m;
    cin.ignore(); // a getline() below
    if (n==0 && m==0) break;

    if(field_num==1) {}
    else { cout << endl;}

    vector<vector<string>> vi(n);
    for (int i = 0; i < n; ++i) {
      vector<string> vii(m);
      string input;
      getline(cin, input);
      for (int j = 0; j < m; ++j) {
	vii[j] = input[j];
      }
      vi[i] = vii;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
	if (vi[i][j] == "*") continue;

	int count = 0;

	if ((i-1) >= 0) {
	  if ((j-1)>=0 && vi[i - 1][j - 1] == "*") ++count;
	  if (vi[i - 1][j] == "*") ++count;
	  if ((j+1)<m && vi[i - 1][j + 1] == "*") ++count;
	}

	if ((j-1)>=0 && vi[i][j - 1] == "*") ++count;
	if ((j+1)<m && vi[i][j + 1] == "*") ++count;

	if ((i+1) < n) {
	  if ((j-1)>=0 && vi[i + 1][j - 1] == "*") ++count;
	  if (vi[i + 1][j] == "*") ++count;
	  if ((j+1)<m && vi[i + 1][j + 1] == "*") ++count;
	}

	vi[i][j] = to_string(count);
      }
    }

    cout << "Field #" << field_num << ":" << endl;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
	cout << vi[i][j];
      }
      cout << endl;
    }

    ++field_num;
  }


  //    for(const auto& e: vi){
  //        for(const auto& ee: e) {
  //            cout << ee << " ";
  //        }
  //    }
  return 0;
}
