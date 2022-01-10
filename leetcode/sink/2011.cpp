https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
#include <string>
#include <vector>

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
      int ans=0;
      for(const auto& elem: operations){
	if(elem[1]=='+') ++ans;
	else --ans;
      }
      return ans;
    }
};

int main()
{
  return 0;
}
