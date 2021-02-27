#include <iostream>
#include <array>
#include <deque>
#include <vector>
#include <numeric>

using namespace std;


//class MovingAverage {
//public:
//    /** Initialize your data structure here. */

//    MovingAverage() = delete;

//    MovingAverage(int size):size{size} {

//    }

//    double next(int val) {
//        d.push_back(val);
//        if (d.size() <= this->size) {
//            return static_cast<double>(accumulate(d.begin(), d.end(), 0))/ d.size();
//        } else {
//            d.pop_front();
//            //return static_cast<double>(accumulate(d.end()-this->size, d.end(),0))/this->size; //deque no - on iterator
//            return static_cast<double>(accumulate(d.begin(), d.end(), 0)) /this->size;
//        }
//    }
//private:
//    int size;
//    deque<int> d;
//};

class MovingAverage {
public:
    /** Initialize your data structure here. */

    MovingAverage() = delete;

    MovingAverage(int size):size{size}, sum{0} {
        v.reserve(size);
    }

    pair<double, size_t> get_sum_and_size(const vector<int>& v)
    {
         if (v.size()<=this->size){
            sum += v.back();
            return pair(sum, v.size());
        } else {
            vector<int>::const_iterator window_start = v.end()-size;
            sum += v.back() - *(window_start-1);
            return pair(sum, size);
        }
    }
    double next(int val) {
        v.push_back(val);
        auto [sum, window_size] =  get_sum_and_size(v);
        return sum/window_size;
    }
private:
    int size;
    double sum;
    vector<int> v;
};


int main()
{
    MovingAverage* obj = new MovingAverage(3);
    obj->next(1);
    obj->next(10);
    obj->next(3);
    obj->next(5);
    return 0;
}
