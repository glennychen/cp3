//Design HashMap
//https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/588/week-1-march-1st-march-7th/3663/

#include <iostream>
#include <array>
using namespace std;

// review open addressing: no need to linked list bucket, but storing to the next or other table, more CPU cache friendly
// review simple std::unordered_map (bucket and linked list), linked list not CPU cache friendly

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        arr.fill(-1);
    }

    /** simple hash function, open addressing, no collision, no linear probing, no double hashing */
    int hash(int key){
       return key;
    }
    /** value will always be non-negative. */
    void put(int key, int value) {
        arr[hash(key)]=value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return arr[hash(key)];
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        arr[hash(key)]=-1;
    }
private:
    // All keys and values will be in the range of [0, 1000000].
    const static int N = 1000000+1;
    array<int,N> arr;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

/**
All keys and values will be in the range of [0, 1000000].
The number of operations will be in the range of [1, 10000].
Please do not use the built-in HashMap library.
**/

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
