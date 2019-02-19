// 11799 - Horror Dash
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int i=0; i<T; ++i){
    int N;
    cin >> N;
    vector<int> v;
    for (int j=0;j<N;++j){
      int speed;
      cin >> speed;
      v.push_back(speed);
    }

    //use std::max_element()
    int max = *max_element(v.begin(), v.end());
    cout << "Case " << i+1 << ": " << max << endl;
  }
}
