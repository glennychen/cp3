//Swapping Nodes in a Linked List
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapNodes(ListNode* head, int k) {
    if(head==nullptr || head->next==nullptr)
        return head;

    ListNode* runner=head->next; //remember runner will run first
    ListNode* mid=head;
    ListNode* headptr=head;
    int length=2;
    for(;;){
        if(runner->next){
            runner=runner->next;
            ++length;
        } else {
            mid=headptr->next; //1,2,3,4: 3
            break;
        }

        if(runner->next){
            runner=runner->next;
            ++length;
        } else {
            mid=headptr->next; //[1,2,3]: 2 [1,2,3,4,5]: 3 true mid
            break;
        }
        headptr=headptr->next;
    }

    headptr=head;
    for(int i=1;i<k;++i){
        headptr=headptr->next;
    }

    ListNode* midptr=mid;
    if(length%2==1){
        if(headptr==mid)
            return head;

        if(k<length/2){
            int steps=(length+1)/2-k;
            while(steps--){
                midptr=midptr->next;
            }
        }else{
            int steps=length-k;
            midptr=head;
            while(steps--){
                midptr=midptr->next;
            }
        }
    } else {
        if(k<length/2){
            int steps=(length)/2-k; //note not "length-1"
            while(steps--){
                midptr=midptr->next;
            }
        }else{
            int steps=length-k;
            midptr=head;
            while(steps--){
                midptr=midptr->next;
            }
        }
    }

    int tmp=headptr->val;
    headptr->val=midptr->val;
    midptr->val=tmp;
    return head;
}

int main()
{

}

//[7,9,6,6,7,8,3,0,9,5]
//5
//[1]
//1
//[1,2]
//1
//[1,2,3]
//2
//[100,90]
//2
//[91,56,48,77,91,96,55,53,68]
//7
