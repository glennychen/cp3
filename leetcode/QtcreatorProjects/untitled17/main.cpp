// https://leetcode.com/problems/search-in-a-binary-search-tree/
#include <iostream>

using namespace std;



 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root==nullptr) return root;
        if (root->val==val) return root;
        if (root->val>val) return searchBST(root->left, val);
        return searchBST(root->right, val);
    }

    TreeNode* Iterative_searchBST(TreeNode* root, int val) {
        while(root!=nullptr && root->val!=val){
            root = val>root->val ? root->right:root->left;
        }
        return root;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
