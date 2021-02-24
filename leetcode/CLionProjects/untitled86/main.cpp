// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * TODO: You can solve the problem in O(1) memory using bits operation. use shift left operation ( << ) and or operation ( | ) to get the decimal value in one operation.
 *
 */

int getDecimalValue(ListNode* head) {
    static int exponent;
    int sum = 0;

// SAME bug, you the most signification digit is on the left
//    while(head!=nullptr) {
//        int current_value = head->val;
//        for (int i = 0; i < exponent; ++i) {
//            current_value = current_value << 1;
//        }
//        sum = sum | current_value;
//
//        ++exponent;
//        head=head->next;
//    }
//    return sum;
    if (head->next==nullptr) {
        exponent = 0; //remember to reset! of exponent will not become 0 after all recurrsions are finished
        return head->val;
    }
    sum = getDecimalValue(head->next);
    ++exponent;
    //return (sum) || ((head->val) << exponent);//what
    return (sum) | ((head->val) << exponent);
}

int NORMAL_VERSION_getDecimalValue(ListNode* head) {
    int sum = 0;
    int exponent = 0;

    ListNode *tmp_head = head;
    while (tmp_head != nullptr) {
        ++exponent;
        tmp_head = tmp_head->next;
    }

    while (head != nullptr) {
        --exponent;
        sum += head->val * pow(2, exponent);
        //--exponent; //bug, expoent starts from 0 to n-1
        head = head->next;
    }

    return sum;
}

int Traverse_to_end_getDecimalValue(ListNode* head) {
    int sum = 0;
    int exponent = 0;

    ListNode *tmp_head = head;
    while (tmp_head != nullptr) {
        ++exponent;
        tmp_head = tmp_head->next;
    }

    while (head != nullptr) {
        --exponent;
        sum += head->val * pow(2, exponent);
        //--exponent; //bug, expoent starts from 0 to n-1
        head = head->next;
    }

    return sum;
}


int MEMORY_LIMIT_EXCEEDgetDecimalValue(ListNode* head) {
//    if (head!=nullptr) { //what

//    while(head!=nullptr) { // bug the most signification is on the left
//        sum+= head->val * pow(2, exponent);
//
//        ++exponent;
//        head = head->next;
//    }
//    return sum;

    vector<int> binary;
    while(head!=nullptr) {
        binary.push_back(head->val);
    }
    reverse(binary.begin(), binary.end());
    int sum = 0;
    for (int exponent = 0; exponent < binary.size(); ++exponent) {
        int index = exponent;
        sum += binary[index] * pow(2, exponent);
    }
    return sum;
}

int main() {
    int exponent=0;
    int out = 1*pow(2, exponent);
    out = 1*pow(2, ++exponent);
    out = 1*pow(2, ++exponent);
    return 0;
}
