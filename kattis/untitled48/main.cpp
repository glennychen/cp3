// https://open.kattis.com/problems/symmetricorder
#include <iostream>
#include <deque>
#include <string>

// Better algorithms?
int main() {
    int n;
    std::cin >> n;
    int k = 0;
    while (n!=0) {
        std::deque<std::string> input;
        std::deque<std::string> output;
        for (int i = 0; i < n; ++i) {
            std::string s;
            std::cin >> s;
            input.push_back(s);
        }

        if (n%2 == 1) {
            output.push_back(input.back());
            input.pop_back();
            while (!input.empty()) {
                if (input.size()==1) {
                    output.push_front(input.back());
                    input.pop_front();
                } else {
                    output.push_back(input.back());
                    input.pop_back();
                    output.push_front(input.back());
                    input.pop_back();
                }
            }
        } else {
            output.push_back(input.back());
            input.pop_back();
            while (!input.empty()) {
                if (input.size()==1) {
                    output.push_front(input.back());
                    input.pop_back();
                } else {
                    output.push_front(input.back());
                    input.pop_back();
                    output.push_back(input.back());
                    input.pop_back();
                }
            }
        }

        std::cout << "SET " << ++k << '\n';
        for (const auto& element: output) {
            std::cout << element << '\n';
        }
        std::cin >> n;
    }
    return 0;
}

/*
 *
 * /home/bps/CLionProjects/untitled48/cmake-build-debug/untitled48
1
123
SET 1
123
2
123
123
SET 2
123
123
3
1
12
123
SET 3
1
123
12
4
1
12
123
1234
SET 4
1
123
1234
12
5
1
12
123
1234
12345
SET 5
1
123
12345
1234
12
6
1
12
123
1234
12345
123456
SET 6
1
123
12345
123456
1234
12
7
1
12
123
1234
12345
123456
1234567
SET 7
1
123
12345
1234567
123456
1234
12
6
Jim
Ben
Zoe
Joey
Frederick
Annabelle
 */