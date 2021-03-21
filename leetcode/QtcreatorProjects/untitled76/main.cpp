//Swap Nodes in Pairs
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
      ListNode* swap(ListNode* head){
          if(head==nullptr || head->next==nullptr)
              return head;
          ListNode* new_head=swap(head->next->next);


  //         head->next->next=head; //bug
  //         head->next=new_head; //bug
          ListNode* first=head;
          ListNode* second=head->next;

          first->next=new_head;
          second->next=first;

          return second;

      }

      ListNode* swapPairs(ListNode* head) {
          return swap(head);
      }
  };


int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
