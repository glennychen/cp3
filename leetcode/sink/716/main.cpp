//https://leetcode.com/problems/max-stack/
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;


class MaxStack {
public:
    MaxStack() {
        
    }
    
    void push(int x) {
        l.emplace_front(x);
    }
    
    int pop() {
        int front = l.front();
        l.pop_front();
        return front;
    }
    
    int top() {
        return *(l.begin());
    }
    
    int peekMax() {
        return *(max_element(l.begin(), l.end()));
    }
    
    int popMax() {
        auto elem = max_element(l.begin(), l.end());
        auto it = find(l.begin(), l.end(), *elem);
        l.erase(it);
        return *elem;
    }
private:
    list<int> l;
};

int main(int, char**) {
    std::cout << "Hello, world!\n";
}
