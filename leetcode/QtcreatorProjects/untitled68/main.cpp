#define CATCH_CONFIG_MAIN
#include<catch2/catch_all.hpp>
#include <iostream>
#include <vector>
#include <stack>

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
    int get_value(string s){
        int end=s.find('(');
        if (end==string::npos){
            return stoi(s);
        }
        return stoi(s.substr(0,end));
    }

    string get_child(string s)
    {
        //int index;
        int index{0};//remember to initialize, this is local, not global
        stack<char> my_stack;
        for(const auto& elem:s){
            if(elem=='('){
                my_stack.push('(');
            } else if(elem==')'){
                my_stack.pop();
            }
            if(my_stack.empty()){
                break;
            }
            ++index;
        }
        return s.substr(1,index-1);//remember to -1
    }

    TreeNode* str2tree(string s) {
        if(s.size()==0)
            return nullptr;

        int root_val = get_value(s);
        int current_index=to_string(root_val).size();
        TreeNode* root=new TreeNode(root_val);

        string left, right;
        TreeNode* left_node;
        TreeNode* right_node;
        if (current_index<s.size()){
            left=get_child(s.substr(current_index));
            left_node=str2tree(left);
            root->left=left_node;
            //int tmp=current_index+left.size()+2; //debug only
            if(current_index+left.size()+2<s.size()){
                right=get_child(s.substr(current_index+left.size()+2));
                right_node=str2tree(right);
                root->right=right_node;
            }
        }
        return root;
    }
};


TEST_CASE( "Integer to Roman") {
    Solution s;

//    TreeNode* t2=new TreeNode(2);
//    TreeNode* t3=new TreeNode(3);
//    TreeNode* t1=new TreeNode(1);
//    t2->left=t3;
//    t2->right=t1;
//    REQUIRE(s.str2tree("-22(3)(1)")==t2);

//    TreeNode* t6=new TreeNode(6);
//    TreeNode* t5=new TreeNode(5);
//    t6->left=t5;
//    REQUIRE(s.str2tree("6(5)")==t6);


    TreeNode* t4=new TreeNode(4);
    TreeNode* t2=new TreeNode(2);
    TreeNode* t3=new TreeNode(3);
    TreeNode* t1=new TreeNode(1);
    TreeNode* t6=new TreeNode(6);
    TreeNode* t5=new TreeNode(5);
    t4->left=t2;
    t4->right=t6;
    t2->left=t3;
    t2->right=t1;
    t6->left=t5;
    REQUIRE(s.str2tree("-4(2(3)(1))(6(5))")==t4);


}
