//Add One Row to Tree
#include <iostream>
#include <vector>
#include <deque>

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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1){
            TreeNode* new_root=new TreeNode(v);
            new_root->left=root;
            new_root->right=nullptr; //just be explicit
            root=new_root;
            return root;
        }

        //Prepare BFS
        vector<TreeNode*> queue;
        queue.push_back(root);
        int depth=1;
        vector<TreeNode*> level_nodes;
        while(!queue.empty()){
            for(const auto& elem:queue){ // Collect all children
                if(elem->left) {
                    //level_nodes.push_back(elem);//wut
                    level_nodes.push_back(elem->left);
                }
                if(elem->right) {
                    //level_nodes.push_back(elem);//wut
                    level_nodes.push_back(elem->right);
                }
            }

            if(depth!=d-1){
                queue.clear(); // clear old root(s); prepaer a new set sub-roots
                               // the children in this level will become the roots for the next level
                for(const auto& elem:level_nodes){
                    queue.push_back(elem);
                }
                level_nodes.clear();
                ++depth;
            } else if (depth==(d-1)){
                //now we have the queue: the root(s); those roots at level (d-1)
                //now we have the level nodes
                for(const auto& elem:queue){
                    if (elem->left){
                        TreeNode* inserted_root_left=new TreeNode(v);
                        inserted_root_left->left=elem->left;
                        elem->left=inserted_root_left;
                    } else if(elem->left==nullptr){
                        TreeNode* inserted_root_left=new TreeNode(v);
                        elem->left = inserted_root_left;
                    }


                    if (elem->right){
                        TreeNode* inserted_root_right=new TreeNode(v);
                        inserted_root_right->right=elem->right;
                        elem->right=inserted_root_right;
                    } else if(elem->right==nullptr){
                        TreeNode* inserted_root_right=new TreeNode(v);
                        elem->right=inserted_root_right;
                    }
                }
                level_nodes.clear();//explicit
                queue.clear();//no need to process the next level
            }
        }
        return root;
    }
};


int main()
{
    TreeNode* t4=new TreeNode(4);
    TreeNode* t2=new TreeNode(2);
    TreeNode* t3=new TreeNode(3);
    TreeNode* t1=new TreeNode(1);
    t4->left=t2;
    t2->left=t3;
    t2->right=t1;
    Solution s;
    s.addOneRow(t4,1,3);
    return 0;
}


//[4,2,null, 3, 1, null, null]
//1
//3

//[4,2,6,3,1,5]
//1
//2

//add to the edge
//[1,2,3,4]
//5
//4
