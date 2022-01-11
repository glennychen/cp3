//https://leetcode.com/problems/number-of-valid-words-in-a-sentence/
#include <string>
#include <vector>
#include <cctype>
#include <sstream>
#include <map>
using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
      map<int, int> umseats;
      map<int, int> umstudents;
      for(const auto& elem: seats){
	++umseats[elem];
      }
      for(const auto& elem: students){
	++umstudents[elem];
      }
      int res=0;
      for(auto iter1=umseats.begin(),iter2=umstudents.begin(); iter1!=umseats.end();){
	int seat=iter1->first;
	int student=iter2->first;	
	if(umstudents.find(seat)!=umstudents.end()&&umstudents[seat]>0){
	  --umstudents[seat];
	  --umseats[seat];
	} else if(iter1->second>0 && iter2->second>0){
	  res+=abs(seat-student);
	  --umseats[seat];
          --umstudents[student];
	}

	if(iter1->second==0){
	  ++iter1;
	}
	if(iter2->second==0){
	  ++iter2;
	}	
      }
      return res;
    }
  /*
    223  
    112
   */
};

int main()
{
  Solution s;
  vector<string> v{"alice and bob love leetcode", "i think so too", "this is great thanks very much"};
  s.minMovesToSeat(v,v);
  return 0;
}

