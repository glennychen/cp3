// UVA 514 Rails
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
  for(;;) {
    int n;
    cin >> n;
    if (n==0) break;

    for (;;) {
      int input;
      cin >> input;
      if (input == 0) {
	cout << endl;
	break;
      }

      stack<int> station;
      stack<int> source_stack;
      for (int i=n;i>0;--i) {
	source_stack.push(i);
      }

      vector<int> v;
      v.push_back(input);
      for (int i=1; i<n; ++i) {
	cin >> input;
	v.push_back(input);
      }

      auto it = v.begin();
      while(!source_stack.empty() && it != v.end()) {
	//                int tmmtop= station.top(); cannot call top() on empty stack?
	int tmpit = *it;
	if (!station.empty() && station.top() == *it) {
	  station.pop();
	  ++it;
	} else if(source_stack.top() == *it) {
	  source_stack.pop();
	  ++it;
	  // no need to push *it to station, since it will get pop right after
	} else {
	  station.push(source_stack.top());
	  source_stack.pop();
	}
      }

      if (source_stack.empty() && !station.empty()) {
	for(;;) {
	  if (it != v.end() && station.top() == *it ) {
	    station.pop();
	    ++it;
	  } else {
	    break;
	  }
	}
      }

      if (station.empty()) {
	cout << "Yes" << endl;
      } else {
	cout << "No" << endl;
      }
    }
  }

  return 0;
}
