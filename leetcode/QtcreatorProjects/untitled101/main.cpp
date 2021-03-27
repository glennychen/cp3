//1773. Count Items Matching a Rule
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int index=-1;
        if(ruleKey=="type")
            index=0;
        else if(ruleKey=="color")
            index=1;
        else
            index=2; //ruleKey="name"

        int count=0;
        for(const auto&elem: items){
            if(elem[index]==ruleValue)
                ++count;
        }
        return count;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
