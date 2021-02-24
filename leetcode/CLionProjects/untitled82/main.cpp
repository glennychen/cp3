// https://leetcode.com/problems/count-of-matches-in-tournament/
#include <iostream>
int numberOfMatches(int n) {
    int matches=0;
    while(n>1) {
        if (n%2==0) {
            matches += n/2;
            n/=2;
        } else {
            matches += (n-1)/2;
            n = (n-1)/2+1;
        }
    }
    return matches;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
