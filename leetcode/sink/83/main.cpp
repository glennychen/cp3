//https://leetcode.com/problems/remove-duplicates-from-sorted-list/
#include <iostream>
#include <memory>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==nullptr) return head;

        auto sentinel = make_unique<ListNode>(0);
        ListNode* prev;
        ListNode* curr;

        sentinel->next = head;
        prev = sentinel.get();        
        curr = head;

        while(curr){
            if (curr->next == nullptr)
                return sentinel->next;
            else if (curr->val == curr->next->val){
                prev->next=curr->next;
                delete curr;
                curr=prev->next;
            } else {
                prev=curr;
                curr=curr->next;
            }
        }
        return sentinel->next;        
    }
};


int main(int, char**) {
    std::cout << "Hello, world!\n";
}
