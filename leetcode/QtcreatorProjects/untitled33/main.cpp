// Single-Row Keyboard
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> m;

        int i=0;
        for(const auto& c:keyboard){
            m[c]=i++;
        }

        //STL? Adjacent distance
        int distance=0;
        distance+=m[*word.begin()];
        for(auto first=word.begin(), next=first+1;
            next!=word.end();
            ++first,++next){
            distance+=abs(m[*first]-m[*next]);
        }

        return distance;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
