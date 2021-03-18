//https://leetcode.com/problems/palindrome-linked-list/
#include <iostream>

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
    ListNode* revert(ListNode *head){
        if(head==nullptr)
            return head;
        ListNode* node=revert(head->next);
        if(node) //remember to check
            node->next=head;
        head->next=nullptr;
        return head;
    }

    bool isPalindrome(ListNode* head) {
        if (head==nullptr)
            return true;
        ListNode* headptr=head;
        ListNode* runner=head;
        while(runner && runner->next){
            headptr=headptr->next;
            runner=runner->next->next;
        }
        ListNode* middleptr=headptr; //middle
        ListNode* middleptr2=headptr; //a copy of the middle

        while(middleptr && middleptr->next!=nullptr){
            middleptr=middleptr->next;
        }
        ListNode* lastptr=middleptr; //get the last node, which will become the head backward

        revert(middleptr2);

        while(head && lastptr && head!=middleptr){
            if (head->val != lastptr->val)
                return false;

            head=head->next;
            lastptr=lastptr->next;
        }

        return true;
    }
};
int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
