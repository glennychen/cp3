//https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/
#include <string>
#include <vector>
#include <cctype>
#include <sstream>
using namespace std;
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
      int max_words=0;
      for(const auto& elem: sentences){
	int count=0;
	string word;
	stringstream ss(elem);
	while(ss>>word){
	  ++count;
	}
	max_words=max(max_words, count);
	ss.clear();
      }
      return max_words;
    }
};

int main()
{
  Solution s;
  vector<string> v{"alice and bob love leetcode", "i think so too", "this is great thanks very much"};
  s.mostWordsFound(v);
  return 0;
}
