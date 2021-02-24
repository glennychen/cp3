// https://leetcode.com/problems/range-sum-of-bst/
#include <iostream>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


//review in order, pre order, and post order traversal
int rangeSumBST(TreeNode* root, int low, int high) {
    int left_sum = 0;
    int right_sum = 0;
    while(root!=nullptr) {
        left_sum = rangeSumBST(root->left, low, high);
        right_sum = rangeSumBST(root->right, low, high);

        int val = root->val;
        //if (val>=low || val<=high) { //bug between low and high, not low or high
        if (val>=low && val<=high) {
            return left_sum+right_sum+val;
        }
        return left_sum+right_sum;
    }
    return 0;
}

int main() {

    return 0;
}
