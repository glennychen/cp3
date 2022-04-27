//https://leetcode.com/problems/print-immutable-linked-list-in-reverse/
#include <iostream>


  // This is the ImmutableListNode's API interface.
  // You should not implement it, or speculate about its implementation.
  class ImmutableListNode {
  public:
     void printValue(); // print the value of the node.
     ImmutableListNode* getNext(); // return the next node.
  };
 

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        if(head){
            printLinkedListInReverse(head->getNext());
            head->printValue();
        }        
    }
};

int main(int, char**) {
    std::cout << "Hello, world!\n";
}
