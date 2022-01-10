//https://leetcode.com/problems/number-of-valid-words-in-a-sentence/
#include <string>
#include <vector>
#include <cctype>
#include <sstream>
using namespace std;

class Solution {
public:
    string modifyString(string s) {
      if(s.size()==1){
	return "a";
      }
      
      for(int i=0;i<s.size();++i){
	if(s[i]=='?'){
	  bool not_found=true;
	  char replacement='a';
	  
	  while(not_found){
	    if(i==0){
	      if(s[i+1]!=replacement){
		s[i]=replacement;
		not_found=false;
	      }
	    }else if(i==s.size()-1){
	      if(s[i-1]!=replacement){
		s[i]=replacement;
		not_found=false;
	      }
	    }else {
	      if(s[i+1]!=replacement && s[i-1]!=replacement){
		s[i]=replacement;
		not_found=false;
	      }
	    }
	    replacement+=1;
	  }
	}
      }
      return s;
    }
};

int main()
{
  Solution s;
  vector<string> v{"alice and bob love leetcode", "i think so too", "this is great thanks very much"};
  return 0;
}

