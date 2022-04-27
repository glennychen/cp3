#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int i=edges[0][0];
        if(i==edges[1][0]||i==edges[1][1]){
            return i;
        } else {
            return edges[0][1];
        }
    }
};
int main(int, char**) {
    std::cout << "Hello, world!\n";
}
