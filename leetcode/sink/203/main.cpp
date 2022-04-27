//https://leetcode.com/problems/remove-linked-list-elements/
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
    ListNode* removeElements(ListNode* head, int val) {
        //ListNode* sentinel;
        //unique_ptr<ListNode> sentinel(new Listnode);
        auto sentinel = make_unique<ListNode>(0);
        ListNode* prev=sentinel.get();
        sentinel->next = head;
        while(head){
            if(head->val==val){
                prev->next=head->next;
                ListNode* temp_head=head;                
                head=prev->next;
                delete temp_head;
            } else {
                prev=head;
                head=head->next;
            }
        }
        return sentinel->next;
    }
};

class SolutionX {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* new_head=head;
        while(head){
            if(head->val==val){
                if( head==new_head){
                    head=head->next;
                    new_head=head;
                }
                //bug in [1,2,2,1], remove 2
                
            } else if(head->next && head->next->val==val){
                if(head->next->next==nullptr){
                    head->next=nullptr;
                } else {
                    head->next=head->next->next;                
                }
                head=head->next;
            } else {
                head=head->next;         
            }
        }
        return new_head;
    }
};


class SolutionNoSentinel {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* new_head;
        ListNode* prev;
        prev=nullptr;
        new_head=head;
        while(head){
            if(head->val==val){
                if( head==new_head){
                    prev=head;
                    head=head->next;
                    new_head=head;
                } else {
                    prev->next=head->next;
                    head=head->next;
                }                
            } else if(head->next && head->next->val==val){
                if(head->next->next==nullptr){
                    head->next=nullptr;
                } else {
                    head->next=head->next->next;                
                }
                prev=head;
                head=head->next;                
            } else {
                prev=head;
                head=head->next;         
            }
        }
        return new_head;
    }
};
int main(int, char**) {
    std::cout << "Hello, world!\n";
}
