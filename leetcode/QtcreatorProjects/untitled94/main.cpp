// Advantage Shuffle
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        //unordered_multimap<int,int> uma; //elemnt, used
        multimap<int,int> mm;
        for(const auto& elem:A){
            mm.insert({elem,-1});
        }

         vector<int> aa;
        for(int i=0;i<B.size();++i){
            auto iter=mm.lower_bound(B[i]+1);
            if(iter->second!=0){
                //a lower bound is found
                while(iter->second==1&&iter!=mm.end()){
                    ++iter;
                }
                if(iter!=mm.end()){
                    aa.push_back(iter->first);
                    iter->second=1; //used
                }
            } else { /*if(iter->second==0){*/
                //lower bound not found
                //pick the smallest that is not used
                for(auto& elem:mm){
                    if(elem.second==-1){
                        aa.push_back(elem.first);
                        elem.second=1; //used
                    }
                }
            }
        }

        return aa;
    }
};


int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
