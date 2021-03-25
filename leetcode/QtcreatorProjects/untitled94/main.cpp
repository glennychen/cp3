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
            bool found=false;
            if(iter->second!=0){
                //a lower bound is found
                while(iter->second==1&&iter!=mm.end()){
                    ++iter;
                }
                if(iter!=mm.end()){
                    aa.push_back(iter->first);
                    iter->second=1; //used
                    found=true;
                }
            }

            if(!found){
                //lower bound not found
                //pick the smallest that is not used
                for(auto& elem:mm){
                    if(elem.second==-1){
                        aa.push_back(elem.first);
                        elem.second=1; //used
                        break;
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

[2,0,4,1,2]
[1,3,0,0,2]

[2,0,4,1,2]
[1,3,0,0,2]

[15448,14234,13574,19893,6475]
[14234,6475,19893,15448,13574]
