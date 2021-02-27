// https://leetcode.com/problems/n-ary-tree-postorder-traversal/
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> output;
        if (root==nullptr) return output;
        output.push_back(root->val); //remember to push yourself in
        if (!root->children.empty()) {

            for(const auto& elem: root->children){
                //return postorder(elem); //bug
                vector<int> children_output = preorder(elem);
                //copy is slowerer than vector.insert?
                copy(children_output.begin(),
                     children_output.end(),
                     back_inserter(output));
            }
        }
        //output.push_back(root->val); //remember to push yourself in
        return output;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
