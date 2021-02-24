// https://leetcode.com/problems/design-an-ordered-stream/
#include <iostream>
#include <vector>
using namespace std;

class OrderedStream {
public:
    OrderedStream(int n): v(n), itr(v.begin()) {
        // what is a nice way to initialize a vector with n element in
        // a constructor
        //itr = v.begin();
    }

    vector<string> insert(int idKey, string value) {
        //idKey index starts with 1
        v[idKey-1] = value;
        if (*itr == "") {
            return vector<string>();
        } else {
            vector<string> ret;
            while (itr != v.end() && *itr !="") {
                ret.push_back(*itr);
                ++itr;
            }
            return ret;
        }
    }
private:
    vector<string> v;
    vector<string>::const_iterator itr;
};
/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */

int main() {

    return 0;
}
