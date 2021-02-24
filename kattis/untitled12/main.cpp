#include <iostream>

int main() {
    int best_contestant_index; //1...5
    int best_score = 0;

    for (int i=0;i<5; ++i) {
        int current_sum = 0;
//        while (std::cin >> score) { //bug
//            current_sum += score;
//        }
        for (int j=0;j<4;++j) {
            int score;
            std::cin >> score;
            current_sum += score;
        }
        if (current_sum > best_score) {
            best_contestant_index = i+1;
            best_score = current_sum;
        }
    }
    std::cout << best_contestant_index << " " << best_score;
    return 0;
}
