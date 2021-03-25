//384. Shuffle an Array
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    default_random_engine re{};
    uniform_int_distribution<int> dist;
    vector<int> arr;
    vector<int> original;
    Solution(vector<int>& nums):arr(nums), original(nums) {
//        int length=arr.size();
//        int all_possibilities=factorial(200) noooooo
        int low=1;
        int high=pow(nums.size(), 3);//enough?
        dist=uniform_int_distribution<>{low, high};
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        auto shuffle_count=dist(re);
        //cout<<shuffle_count;
        while(shuffle_count--){
            next_permutation(arr.begin(), arr.end());
        }
        for(const auto&elem:arr){
            cout<<elem;
        }
        cout<<endl;
        return arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
int main()
{
    vector<int> v;
    v={1, 2, 3};
    Solution s(v);
    s.shuffle();
    s.shuffle();
    s.shuffle();

    return 0;
}
