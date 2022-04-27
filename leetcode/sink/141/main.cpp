#include <iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* runner=head->next;
        while(head){        
            head=head->next;
            if(runner && runner->next){
                runner=runner->next->next;
                if (runner==head) return true;
            }            
        }
        return false;
    }
};

int main(int, char**) {
    std::cout << "Hello, world!\n";
}
