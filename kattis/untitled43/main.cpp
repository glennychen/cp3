#include <iostream>
#include <string>
#include <vector>
#include <math.h>

int main() {
    int test_cases;
    std::cin >> test_cases;

    for (int t=0;t<test_cases;++t) {
        std::string input;
        std::cin >> input;
        int n = sqrt(input.size()); // because it is a square

        std::string::const_iterator it = input.begin();
        std::vector<std::vector<char>> v;
        for (int i = 0; i < n; ++i) {
            std::vector<char> vv;
            for (int j = 0; j < n; ++j) {
                vv.push_back(*it);
                ++it;
            }
            v.push_back(vv);
        }

        // encoding the input (this is not required for the problem)
        it = input.begin();
        std::vector<std::vector<char>> v2(v);
        for (int j = n - 1; j >= 0; --j) {
            for (int i = 0; i < n; ++i) {
                v2[i][j] = *it;
                ++it;
            }
        }

        // decoding the (encrypted) input
        std::vector<std::vector<char>> v3(v);
        int v3_row = 0;
        for (int j = n - 1; j >= 0; --j) {
            for (int i = 0; i < n; ++i) {
                char c = v[i][j];
                v3[v3_row][i] = c;
            }
            ++v3_row;
        }

        for (int i = 0; i < v3.size(); ++i) {
            for (int j = 0; j < v3.size(); ++j) {
                std::cout << v3[i][j];
            }
        }

        std::cout << '\n';
    }
    return 0;
}
