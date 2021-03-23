//15. 3Sum
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


class Solution3 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        if (nums.size()<3){
            return v;
        }

        unordered_multiset<int> lookup;
        for(const auto& elem:nums){
            lookup.insert(elem);
        }

        map<set<int>,int> um;

        for(auto iter_i=lookup.begin();iter_i!=lookup.end();++iter_i){
            for(auto iter_j=lookup.begin();
                iter_j!=lookup.end()&&iter_j!=iter_i;
                advance(iter_j,1)){
                int fixed=*iter_i;
                int first=*iter_j;
                int second=-(fixed+first);
                auto iter=lookup.find(second);
                if(iter!=lookup.end()){
                    if(iter!=iter_i && iter!=iter_j){
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

class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        if (nums.size()<3){
            return v;
        }
        map<set<int>,int> um;

        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();++i){
            for(int j=0;j<nums.size()&&j!=i;++j){
                int fixed=nums[i];
                int first=nums[j];
                int second=-(fixed+first);
                auto iter=find(nums.begin(), nums.end(), second);
                if(iter!=nums.end()){
                    if(nums.begin()+i!=iter && nums.begin()+j!=iter){
                        set<int> s_answer;
                        s_answer.insert(fixed);
                        s_answer.insert(first);
                        s_answer.insert(second);
                        if (um.find(s_answer)==um.end()){
                            vector<int> answer={fixed, first, second};
                            v.push_back(answer);
                            um[s_answer]=1;
                        }
                    } else if(nums.begin()+i==iter){
                        if(iter+1!=nums.end() && *(iter+1)==second){
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
        }
        return v;
    }
};


int main()
{
    Solution s;
    vector<int> v;
    v={-1,0,1,2,-1,-4};
    //v={0};
    //v={1,2,-2,-1}; //answer: not [[2,-1,-1]] but 0
    v={0,0,0}; //answer: not [[2,-1,-1]] but 0
    s.threeSum(v);
    return 0;
}
