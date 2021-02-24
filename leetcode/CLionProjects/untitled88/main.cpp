// https://leetcode.com/problems/find-all-the-lonely-nodes/
#include <iostream>
#include <vector>


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

using namespace std;
class Solution {
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> output;
        vector<int> v1;
        vector<int> v2;
        //while (root!=nullptr) { //wut
        if (root!=nullptr) {
            v1 = getLonelyNodes(root->left);
            v2 = getLonelyNodes(root->right);
            v1.insert(v1.end(), v2.begin(), v2.end());
            if (root->left != nullptr && root->right == nullptr){
                v1.push_back(root->left->val);
            } else if (root->left == nullptr && root->right != nullptr) {
                v1.push_back(root->right->val);
            }
            output.insert(output.end(), v1.begin(), v1.end());

        }
        return output;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
