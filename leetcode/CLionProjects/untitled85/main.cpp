// https://leetcode.com/problems/find-anagram-mappings/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
    unordered_map<int, int> m_b_index;
    for (int i = 0; i < B.size(); ++i) {
        //m_b_index[i] = B[i]; //wut
        m_b_index[B[i]] = i;

        // TODO: how to handle duplicate
        // Requirement is quite relaxed: If there are multiple answers, output "any" of them.
    }

    vector<int> output;
    for (int i = 0; i < A.size(); ++i) {
        auto itr = m_b_index.find(A[i]); // assume key always there
        output.push_back(itr->second);
    }
    return output;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
