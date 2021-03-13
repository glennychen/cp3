// https://leetcode.com/problems/middle-of-the-linked-list/
#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* middleNode(ListNode* head) {
    if(head->next==nullptr)
        return head;

    ListNode* runner=head->next;
    for(;;){
        head=head->next;
        if(runner->next)
            runner=runner->next;

        //1,2,3, so return 2
        if(runner->next==nullptr)
            return head;
        //1,2,3,4, so return 3
        runner=runner->next;
        if(runner->next==nullptr)
            return head->next;
    }
    return head;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
