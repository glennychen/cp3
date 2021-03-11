//https://leetcode.com/problems/minimum-depth-of-binary-tree/
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

int minDepth(TreeNode* root) {
    if(root==nullptr)
        return 0;
    int i{0}, j{0};
    if(root->left && root->right){
        i=minDepth(root->left);
        j=minDepth(root->right);
        return 1+min(i,j); //obvious case, pick the smaller result between left and right
    }
    if(root->left==nullptr && root->right){
        j=minDepth(root->right);
        return 1+j; //might not reach the leaf node, so need to keep going
    }
    if(root->left && root->right==nullptr){
        i=minDepth(root->left);
        return 1+i; //might not reach the leaf node, so need to keep going
    }else{
        return 1;
    }
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
