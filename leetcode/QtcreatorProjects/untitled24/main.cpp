// https://leetcode.com/problems/number-of-recent-calls/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//132ms, 58mb
//616/132 times faster, but still use a lot of memory
class RecentCounter {
public:
    RecentCounter() {
        Request.reserve(1000); //At most 10000 calls will be made to ping.
        NewDistance=0;
    }

    int ping(int t) {
        Request.push_back(t);
        auto iter = find_if(Request.begin()+NewDistance, Request.end(), [=](auto elem){
            return elem>=t-3000;
        });
        NewDistance = distance(Request.begin(), iter);
        return distance(iter, Request.end());
    }
private:
    vector<int> Request;
    int NewDistance;
};
namespace s2 {
class RecentCounter {
public:
    RecentCounter() {
        Request.reserve(1000); //At most 10000 calls will be made to ping.
    }

    int ping(int t) {
        Request.push_back(t);
        auto iter = find_if(Request.begin(), Request.end(), [=](auto elem){
            return elem>=t-3000;
        });
        return distance(iter, Request.end());
    }
private:
    vector<int> Request;
};
}

namespace s1{
//616ms 58MB
class RecentCounter {
public:
    RecentCounter() {

    }

    int ping(int t) {
        Request.push_back(t);
        return count_if(Request.begin(), Request.end(), [=](auto elem){
            return elem>=t-3000;
        });
    }
private:
    vector<int> Request;
};
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
