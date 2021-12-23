//https://leetcode.com/problems/merge-two-sorted-lists/solution/
#include <iostream>
 struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
     };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1==nullptr && list2==nullptr) return nullptr;
        ListNode* list3=nullptr;
        ListNode* head=nullptr;
        while(list1!=nullptr || list2!=nullptr){
            if (list1==nullptr){
                while(list2!=nullptr){
                    ListNode *n=new ListNode(list2->val, list2->next);
                    if(!head){
                        head=list3=n;
                        list2=list2->next;
                    } else {
                        list3->next=n;
                        list3=list3->next;
                        list2=list2->next;
                    }
                }
            } else if (list2==nullptr){
                while(list1!=nullptr){
                    ListNode *n=new ListNode(list1->val, list1->next);
                    if(!head){
                        head=list3=n;
                        list1=list1->next;
                    } else {
                        list3->next=n;
                        list3=list3->next;
                        list1=list1->next;
                    }
                }
            } else {
                int val1=list1->val;
                int val2=list2->val;
                if (val1<val2){
                    if(head==nullptr){
                        ListNode* n = new ListNode(list1->val, list1->next);
                        head=list3=n;
                    } else {
                        ListNode *n=new ListNode(list1->val, nullptr);
                        list3->next=n;
                        list3=list3->next;
                    }
                    if(list1) {
                        list1 = list1->next;
                    }
                }  else {
                    if(head==nullptr){
                        ListNode* n = new ListNode(list2->val, list2->next);
                        head=list3=n;
                    } else {
                        ListNode *n = new ListNode(list2->val, nullptr);
                        list3->next=n;
                        list3=list3->next;
                    }
                    if(list2){
                        list2=list2->next;
                    }
                }
            }
        }
        return head;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
//    ListNode *l3=new ListNode(4, nullptr);
//    ListNode *l2=new ListNode(2, l3);
//    ListNode *l1=new ListNode(1, l2);
//
//    ListNode *j3=new ListNode(4, nullptr);
//    ListNode *j2=new ListNode(3, j3);
//    ListNode *j1=new ListNode(1, j2);

    Solution s = Solution();
    s.mergeTwoLists(l1, j1);
    return 0;
}
