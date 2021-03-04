// Intersection of Two Linked Lists
#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };

 class Solution {
 public:

     int getLength(ListNode *head){
         int length=0;
         while(head!=nullptr) {
             head=head->next;
             ++length;
         }
         return length;
     }

     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         int lengthA = getLength(headA);
         int lengthB = getLength(headB);
         //if (headA==headB) return headA; //bug [3], [2,3]
         if(lengthA>lengthB){
             int distance = lengthA-lengthB;
             while(distance--){
                 headA=headA->next;
             }
         } else if(lengthA<lengthB){
             int distance = lengthB-lengthA;
             while(distance--){
                 headB=headB->next;
             }
         }

         if (headA==headB) return headA; //interctipon at first check

         while(headA!=nullptr){
             if(headA->next!=headB->next) {
                 headA = headA->next;
                 headB = headB->next;
             }
             if(headA->next==headB->next){
                 return headA->next;
             }
         }
         return nullptr;
     }

     ListNode* traverseOne(ListNode *head) {
         if (head==nullptr){
             return head;
         }
         traverseOne(head->next);
     }
     ListNode* traverseTwo(ListNode *headA, ListNode *headB) {


         if (headA->next==nullptr && headB->next==nullptr
                 && headA!=headB){
             //do not intercept
             return nullptr;
         }



         if (headA!=nullptr && headB!=nullptr
                 &&headA->next !=nullptr
                 &&headB->next !=nullptr){
             traverseTwo(headA->next, headB->next);
         }

         //A is longer than B
         if (headA->next!=nullptr && headB==nullptr ){
             traverseOne(headA->next);
             //now tail is sync

         }
         //B is longer than A
         if (headA->next==nullptr && headB->next!=nullptr ){
             traverseOne(headB->next);
             //no tail is sync
             //head a null
             //head b->next is null

         }




         //visit(head)
         return headA;

     }

 };

//bug can't traverse in sync
namespace s1 {
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headA!=nullptr || headB!=nullptr) {
            if (headA!=nullptr && headA->next!=nullptr) headA = headA->next;
            if (headB!=nullptr && headB->next!=nullptr) headB = headB->next;
            if(headA!=nullptr && headB!=nullptr && headA==headB) return headA;
        }
        return nullptr;
    }
};
}

int main()
{

    return 0;
}
