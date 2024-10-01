//2347
//https://leetcode.com/problems/best-poker-hand/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_map<int, int> m_rank;
        unordered_map<char, int> m_suit;
        bool flush=false; bool threekind=false; bool pair=false;
        for (const auto& elem: suits) {
            m_rank[elem]++;
            if(m_rank[elem]==5) flush=true;
        }
        for (const auto& elem: ranks) {
            m_suit[elem]++;
            if(m_suit[elem]==3) threekind=true;
            if(m_suit[elem]==2) pair=true;
        }
        if(flush) return "Flush";
        else if (threekind) return "Three of a Kind";
        else if (pair) return "Pair";
        return "High Card";
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
