//https://leetcode.com/problems/number-of-valid-words-in-a-sentence/
#include <string>
#include <vector>
#include <cctype>
#include <sstream>
using namespace std;

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
      int res=0;
      for(int i=0;i<nums.size();++i){
	for(int j=i+1;j<nums.size();++j){
	  if(abs(nums[i]-nums[j])==k) ++res;
	}
      }
      return res;
    }
};

int main()
{
  Solution s;
  vector<string> v{"alice and bob love leetcode", "i think so too", "this is great thanks very much"};
  return 0;
}

