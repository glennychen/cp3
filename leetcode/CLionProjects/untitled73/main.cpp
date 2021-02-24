// https://leetcode.com/problems/decompress-run-length-encoded-list
#include <iostream>
#include <vector>

using namespace std;
vector<int> decompressRLElist(vector<int>& nums) {
    vector<int> output;
    //reduce transform? transform? accumulate?
    for(auto iter=nums.begin();iter!=nums.end();iter=iter+2){
        int freq = *iter;
        int value = *(iter+1);
        //no raw loop? any stl to copy an element n times?
        for (int i = 0; i < freq; ++i) {
            output.push_back(value);
        }
    }
    return output;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
