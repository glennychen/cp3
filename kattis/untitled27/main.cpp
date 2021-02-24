#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    int n, m, total_outcome;
    std::vector<int> d1, d2;
    std::map<int, int> frequency;
    std::cin >> n >> m;
    total_outcome = n*m;

    for (int i = 1; i <= n; ++i) {
        d1.push_back(i);
    }
    for (int i = 0; i <= m; ++i) {
        d2.push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            frequency[i+j] += 1;
        }
    }
    //can use auto
    //review lambda
    std::map<int, int>::const_iterator it =
            std::max_element(frequency.begin(), frequency.end(),
                             [](const std::pair<int, int>& p1, const std::pair<int, int>& p2)
                             {return p1.second < p2.second;});
    for (const auto& element: frequency) {
        // std::map already sorted by keys
        if (element.second == (*it).second) {
            std::cout << element.first << std::endl;
        }
    }

    return 0;
}
