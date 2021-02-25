// https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/
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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* current = head;
        ListNode* before_delete = head;
        while (current != nullptr) {
            while(m-- > 0){
                if (current->next == nullptr) return head;
                before_delete = current;
                current = current->next;
            }
            while(n-- > 0 && current != nullptr){
                ListNode* to_be_deleted = current;
                current = current->next;
                delete to_be_deleted;
            }
            before_delete->next = current;
            current = current->next;
        }
        return head;
    }
};

int main()
{

    return 0;
}
