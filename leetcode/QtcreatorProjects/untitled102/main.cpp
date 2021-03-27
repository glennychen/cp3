#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_set<int> um;
        for(const auto& elem:arr){
            um.insert(elem);
        }

        for(const auto& elem:pieces){
            if(um.find(elem[0])==um.end()){
                return false;
            }
            if(elem.size()>1){
                auto iter=find(arr.begin(), arr.end(), elem[0]);
                for(int i=0;i<elem.size();++i){
                    if(*iter!=elem[i])
                        return false;
                    ++iter;
                }
            }
        }
        return true;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

//[37,69,3,74,46]
//[[37,69,3,74,46]]
