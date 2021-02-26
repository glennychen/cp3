//https://leetcode.com/problems/increasing-order-search-tree/
#include <iostream>
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

//static TreeNode* new_root[]


//[2,1,4,null,null,3]
//   2
//1     4
//n n 3
class Solution {
public:
    vector<TreeNode*> v;
    void inorder(TreeNode* root){
        if (root!=nullptr){
            inorder(root->left);
            v.push_back(root);
            inorder(root->right);
        }
    }
    TreeNode* build_tree(vector<TreeNode*> v){
        if (v.empty()) return nullptr;

        auto iter=v.begin();
        for(iter=v.begin();iter<v.end()-1;++iter){
           (*iter)->right = *(iter+1);
           (*iter)->left = nullptr; //remember to update the left child to empty
        }

        //remember to reset the last element too
        (*iter)->right = nullptr;
        (*iter)->left = nullptr;

        return *(v.begin());
    }

    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return build_tree(v);;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
