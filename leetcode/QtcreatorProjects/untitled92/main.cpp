#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        if (nums.size()<3){
            return v;
        }


        unordered_map<int, int> lookup;
        for(const auto& elem:nums){
            //lookup.insert(elem);
            ++lookup[elem];
        }

        map<set<int>,int> um;

        for(auto iter_i=lookup.begin();iter_i!=lookup.end();++iter_i){
            for(auto iter_j=lookup.begin();
                iter_j!=lookup.end()/*&&iter_j!=iter_i*/;
                advance(iter_j,1)){

                if (iter_j->first==iter_i->first && iter_j->second==1){
                    continue;
                }

                int fixed=iter_i->first;
                int first=iter_j->first;
                int second=-(fixed+first);
                auto iter=lookup.find(second);
                if(iter!=lookup.end()){
                    bool should_insert=false;
                    if(iter!=iter_i && iter!=iter_j){
                        should_insert=true;
                    }else{

                    }

                    if(should_insert){
                        set<int> s_answer;
                        s_answer.insert(fixed);
                        s_answer.insert(first);
                        s_answer.insert(second);
                        if (um.find(s_answer)==um.end()){
                            vector<int> answer={fixed, first, second};
                            v.push_back(answer);
                            um[s_answer]=1;
                        }
                    }
                }
            }

        }
         return v;
    }
 };

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
