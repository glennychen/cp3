// https://leetcode.com/problems/merge-two-binary-trees/
#include <iostream>
#include <memory>
#include <vector>

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        //unique_ptr<TreeNode> root3 = make_unique<TreeNode>();
        TreeNode* root3 = new TreeNode();
        if (root1!=nullptr && root2!=nullptr) {
            root3->val = (root1->val+root2->val);
            root3->left = mergeTrees(root1->left, root2->left);
            root3->right = mergeTrees(root1->right, root2->right);
        } else if (root1!=nullptr && root2==nullptr) {
            root3->val = root1->val;
            root3->left = mergeTrees(root1->left, nullptr);
            root3->right = mergeTrees(root1->right, nullptr);
        } else if (root1==nullptr && root2!=nullptr) {
            root3->val = root2->val;
            root3->left = mergeTrees(nullptr, root2->left);
            root3->right = mergeTrees(nullptr, root2->right);
        } else {

        }

        return root3;
    }
};


int main()
{
    unique_ptr<TreeNode> tn = make_unique<TreeNode>();
    return 0;
}
