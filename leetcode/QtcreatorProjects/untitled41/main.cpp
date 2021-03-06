// Average of Levels in Binary Tree
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <memory>
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
        vector<double> average;
        average.push_back(root->val);

        if (root->left==nullptr && root->right==nullptr)
            return average;

        vector<TreeNode*> q; //std::vector is faster than std::deque
        q.push_back(root);

        // Run a modified BFS traversal for our binary tree
        while(!q.empty()){
            vector<TreeNode*> level_nodes;
            cout << level_nodes.size();
            for(const auto& elem:q){
                if(elem->left)
                    level_nodes.push_back(elem->left);
                if(elem->right)
                    level_nodes.push_back(elem->right);
            }
            q.clear();

            double sum=0;
            double size=level_nodes.size();
            for(const auto& elem:level_nodes){
                sum+=elem->val;
                if(elem->left||elem->right) {
                     q.push_back(elem);
                }
            }
            level_nodes.clear(); //no need to clear because it will re-initialize each loop, but clearer intention

            average.push_back(sum/size);
        }
        return average;
    }
};

int main()
{
    Solution s;

    TreeNode* justOne = new TreeNode(1);
    s.averageOfLevels(justOne);

    TreeNode* root = new TreeNode(3);
    TreeNode* t1 = new TreeNode(9);
    TreeNode* t2 = new TreeNode(20);
    TreeNode* t3 = new TreeNode(15);
    TreeNode* t4 = new TreeNode(7);
    root->left = t1; root->right=t2;
    t2->left=t3;t2->right=t4;
    s.averageOfLevels(root);

    return 0;
}
