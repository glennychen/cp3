//https://leetcode.com/problems/maximum-depth-of-binary-tree/
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

int maxDepth(TreeNode* root) {
    if(root==nullptr)
        return 0;
    int id=root->val;
    int i,j;
    i=j=0;
    if(root->left){
        i=maxDepth(root->left);
    }
    if(root->right){
        j=maxDepth(root->right);
    }
    //POST-order traversal, root to report last
    return 1+max(i,j);
}

int main()
{

    using t=TreeNode;
    t* t3=new t(3);
    t* t9=new t(9);
    t* t20=new t(20);
    t* t15=new t(15);
    t* t7=new t(7);
    t3->left=t9;
    t3->right=t20;
    t20->left=t15;
    t20->right=t7;
    int a=maxDepth(t3);

    return 0;
}
