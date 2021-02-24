// https://open.kattis.com/problems/ptice
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

std::string generate_sequence(std::string base_sequence, int length) //no need to pass by reference because C11 move?
{
    std::string new_sequence = base_sequence; //use copy initialize or copy assignment?
    while(new_sequence.size() < length) {
        new_sequence += base_sequence;
    }
    return new_sequence;
}

int get_score(const std::string sequence, const std::string& answer)
{
    // C++ Zip when? C++17? or C++20

    int score = 0;
    for (int i = 0; i < answer.size(); ++i) {
        if (answer[i] == sequence[i]) ++score;
    }
    return score;
}

int main() {
    std::unordered_map<std::string, std::string> players;
    players["Adrian"] = "ABC";
    players["Bruno"] = "BABC";
    players["Goran"] = "CCAABB";

    int n;
    std::string answer;
    std::cin >> n;
    std::cin >> answer;

    std::unordered_map<std::string, int> players_scores;
    for (const auto& p: players) {
        std::string sequence = generate_sequence(p.second, answer.size());
        int score = get_score(sequence, answer);
        players_scores[p.first] = score;
    }

    //std::unordered_map<std::string, int>::iterator it;
    auto max_score_iter = std::max_element(players_scores.begin(), players_scores.end(),
                     [&](const std::pair<std::string, int> p1, const std::pair<std::string, int> p2){
                     return p1.second < p2.second;
    });

    std::cout << max_score_iter->second << std::endl;
    for (const auto& ps: players_scores) {
        if (ps.second == max_score_iter->second) std::cout << ps.first << std::endl;
    }

//    while (it != players_scores.end()) {
//        std::cout << it->first;
//    }

    //practice lambda, transform reduce
//    std::max_element(players.begin(), players.end(),
//                     [&](const std::pair<std::string, std::string> p1, const std::pair<std::string, std::string> p2){
//                         std::string sequence_1 = generate_sequence(p1.second, answer.size());
//                         int score_1 = get_score(sequence_1, answer);
//
//                         std::string sequence_2 = generate_sequence(p2.second, answer.size());
//                         int score_2 = get_score(sequence_2, answer);
//        return score_1 < score_2;
//    });

    return 0;
}
