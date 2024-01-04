//422. Valid Word Square
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            string word = words[i];
            if(word.size()>words.size()) return false;
            for (int j = 0; j < word.size(); ++j) {
                if(words[j][i]!=word[j]) return false;
            }
        }
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
