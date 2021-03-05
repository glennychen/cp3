// Average of Levels in Binary Tree
#include <iostream>
#include <vector>
using namespace std;


// Definition for a binary tree node.
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

    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> v;
        if(root!=nullptr){
            v=averageOfLevels(root->right);
            v=averageOfLevels(root->left);
        }
        return v;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
