// UVA 10038 -Jolly Jumpers
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_jolly(vector<int> &v) {
  vector<bool> v_diff(v.size(), false);

  if (v.size() == 0) return false; // A possible case?
  if (v.size() == 1) return true;  // Any sequence of a single integer is a jolly jumper
  //    // Note: based on def, we want the sequence of Jolly Jumpers, it's not just abs(diff) is 1 for "consecutive pairs"
  //    int diff_prev;
  //    int diff_current;
  //    for (int i = 0; i < v.size() - 1; ++i) {
  //        if (i == 0) {
  //            diff_prev = abs(v[i] - v[i + 1]);
  //        } else {
  //            diff_current = abs(v[i] - v[i + 1]);
  //            if (abs(diff_prev - diff_current) != 1) {
  //                return false;
  //            }
  //            diff_prev = diff_current; // Note: remember to update the diff_prev for the next loop
  //        }
  //    }
  for (int i = 0; i < v.size() - 1; ++i) {
    int diff = abs(v[i] - v[i + 1]);
    //if (diff < 1 || diff > v.size() || v_diff[diff-1] == true ) { // incorrect

    //  1 through size-1
    if (diff == 0 || diff > v.size()-1 || v_diff[diff] == true ) {
      return false;
    }
    v_diff[diff] = true;
  }

  return true;
}

int main() {
  int k, j;

  while (scanf("%d", &k) != EOF) {
    vector<int> v;
    while (k--) {
      scanf("%d", &j);
      v.push_back(j);
    }

    // cout << (is_jolly(v) ? "Jolly" : "Not jolly") << endl;
    is_jolly(v) ? cout << "Jolly" : cout << "Not jolly";
    cout << endl;
  }

  return 0;

}
