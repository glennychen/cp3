#include <iostream>
#include <vector>

using namespace std;

int main() {
  int set_num = 1;
  for(;;) {
    int num_stacks = 0;

    cin >> num_stacks;
    if (num_stacks==0) break;

    vector<int> v;
    int stack;
    int min_moves = 0;
    int total_bricks = 0;
    int average = 0;
    for (int i=0; i<num_stacks; ++i) {
      cin >> stack;
      v.push_back(stack);
      total_bricks += stack;
    }

    average = total_bricks/num_stacks;

    for(const auto& vec: v) {
      if (vec < average) {
	min_moves += average - vec;
      }
    }

    cout << "Set #" << set_num << endl;
    cout << "The minimum number of moves is " << min_moves << "." << endl;
    cout << endl; // per output requirement

    ++set_num;
  }
  return 0;
}
