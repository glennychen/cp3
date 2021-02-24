//https://leetcode.com/problems/jewels-and-stones/
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int numJewelsInStones(string jewels, string stones) {
    unordered_map<char, int> frequency;
    for(const auto& elem:stones) {
        ++frequency[elem];
    }
    int total = 0;
    for(const auto& elem:jewels) {
        total += frequency[elem];
    }
    return total;
}
int main() {
    string jewels = "aA";
    string stones = "aAAbbbb";
    numJewelsInStones(jewels, stones);
    jewels = "z";
    stones = "ZZ";
    numJewelsInStones(jewels, stones);
    return 0;
}
