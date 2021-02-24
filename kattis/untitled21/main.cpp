// https://open.kattis.com/problems/cardtrick2
#include <iostream>
#include <queue>

int main() {
    int T;
    int n; //num_cards;
    std::deque<int> q; //Double-Enable-Queue
    std::cin >> T;
    for (int i = 0; i < T; ++i) {
        std::cin >> n;
        std::deque<int> q;
        // std::swap(q, empty);
        q.push_back(n);
        for (int j = n-1; j > 0 ; --j) {
            q.push_front(j);
            for (int k = 0; k < j ; ++k) {
                q.push_front(q.back());
                q.pop_back();
            }
        }
        for(const auto& element: q) {
            std::cout << element << " ";
        }
    }
    return 0;
}

//int main() {
//    int T;
//    int n; //num_cards;
//    std::vector<int> v;
//    std::queue<int> q;
//    std::cin >> T;
//    for (int i = 0; i < T; ++i) {
//        std::cin >> n;
//
//        std::vector<int> empty_vector;
//        std::swap(v, empty_vector);
//        for (int j = 0; j < n; ++j) {
//            v.push_back(j+1);
//        }
//
//        bool answer_found = false;
//        do {
//            //Review how to empty stl containers
//            std::queue<int> empty;
//            std::swap(q, empty);
//
//            for (int j = 0; j < v.size(); ++j) {
//                q.push(v[j]);
//            }
//            for (int j = 0; j < v.size(); ++j) {
//                // move from front to back, 1 time in first iteration, 2 times in second iteration
//                for (int k = 0; k < j+1; ++k) {
//                    q.push(q.front());
//                    q.pop();
//                }
//                // each iteration, pop out the front card
//                int current_deal_card = q.front();
//                q.pop();
//
//                // answer found in this permutation
//                if (j+1 == n && current_deal_card == n) {
//                    for(const auto& element: v) {
//                        std::cout << element;
//                    }
//                    std::cout << std::endl;
//                    answer_found = true;
//                    break;
//                } else {
//                    // this permutation is not a solution
//                    continue;
//                }
//            }
//        } while (std::next_permutation(v.begin(), v.end()) && !answer_found);
//    }
//    return 0;
//}
