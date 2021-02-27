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
    vector<int> postorder(Node* root) {
        vector<int> output;
        if (root==nullptr) return output;
        if (!root->children.empty()) {
            for(const auto& elem: root->children){
                //return postorder(elem); //bug
                vector<int> children_output = postorder(elem);
                //copy is slowerer than vector.insert?
                copy(children_output.begin(),
                     children_output.end(),
                     back_inserter(output));
            }
        }
        output.push_back(root->val); //remember to push yourself in
        return output;
    }
};

class DFS_playing_Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> output;
        if (root==nullptr || root->children.empty()) return output;
        deque<Node*> t_queue;
        vector<Node*> v_all;

        for(const auto& child: root->children){

        }

        for(auto iter=root->children.rbegin();
            iter!=root->children.rend();
            ++iter) {
            t_queue.push_back(*iter);
            v_all.push_back(*iter);
        }

        while(!t_queue.empty()){
            const auto t = t_queue.front();
            t_queue.pop_front();

            if (t!=nullptr){
                // for(const auto& child: t->children){
                //     t_queue.push_back(child);
                //     v_all.push_back(child); //BUG,: this give PreOrder?
                // }
                for(auto iter=t->children.rbegin();
                    iter!=t->children.rend();
                    ++iter) {
                    t_queue.push_back(*iter);
                    v_all.push_back(*iter);
                }
            }
        }

        //rverse(v_all.begin(), v_all.end());
        for(const auto& elem: v_all){
            output.push_back(elem->val);
        }
        output.push_back(root->val);
        return output;

    }
};
int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
