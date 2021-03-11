#define CATCH_CONFIG_MAIN
#include<catch2/catch_all.hpp>
#include<vector>
#include<string>
#include <deque>
#include <iostream>
#include <bitset>

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


int maxDepth(Node* root) {
    if(root==nullptr) return 0;

    deque<Node*> q;
    q.push_back(root);
    //int depth=1;
    int depth=0;
    while(!q.empty()){
        ++depth;
        size_t breath=q.size();
        while(breath--){
            vector<Node*> children=q.front()->children;
            q.pop_front();
            if(!children.empty()){
                //++depth;//bug
                for(const auto&elem:children){
                    q.push_back(elem);
                }
            }
        }
        //++depth; //bug, maybe no children, so can't add depth
//        if(!q.empty())
//            ++depth;
    }
    return depth;
}

TEST_CASE( "Integer to Roman") {
    vector<int> v1{0,1,2,3,4,5,6,7,8};
    vector<int> a1{0,1,2,4,8,3,5,6,7};
    Node* node;
    REQUIRE( maxDepth(node) == 3  );

}
