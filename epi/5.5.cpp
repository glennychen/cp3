// EPI 5.5 P.50
#include <iostream>
#include <vector>

using namespace std;

// v is sorted
vector<int> remove_duplicate(vector<int>& v)
{
  if (v.size() == 0 || v.size() == 1) return v;

  int duplicate_value;
  int first_vacant_index = -1;
  for (int i=0; i< v.size()-1; ++ i) {
    if (v[i] == v[i+1]) {
      duplicate_value = v[i+1];
      if (first_vacant_index == -1) first_vacant_index = i + 1;
    } else {
      if (first_vacant_index != -1) {
	v[first_vacant_index] = v[i + 1];
	first_vacant_index += 1;
      }
    }
  }
  return v;
}
int main() {
  vector<int> v{2,3,4,5,7,11,11,11,13};
  // v = {1, 1, 1, 1, 2};
  v = {1, 11, 13, 14, 14, 14, 16, 17, 18, 18, 18, 19, 20};
  vector<int> v2 = remove_duplicate(v);
  return 0;
}
