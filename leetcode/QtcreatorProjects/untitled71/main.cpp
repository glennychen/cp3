#include <iostream>


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

using namespace std;


  ListNode* reverseHelper(ListNode* head){

      if(head==nullptr)
          return head;

      if(head->next){
          ListNode* new_head=reverseHelper(head->next);
          new_head->next=head;
          head->next=nullptr;
          return head;
      } else {
          return head;
      }
  }
 ListNode* reverseList(ListNode* head) {
     ListNode* reverseHead=head;
      while(reverseHead && reverseHead->next){
         reverseHead=reverseHead->next;
     }
     reverseHelper(head);
     return reverseHead;
 }

int main()
{
    ListNode* n5=new ListNode(5);
    ListNode* n4=new ListNode(4,n5);
    ListNode* n3=new ListNode(3,n4);
    ListNode* n2=new ListNode(2,n3);
    ListNode* n1=new ListNode(1,n2);
    ListNode* a=reverseList(n1);
    return 0;
}
