// https://open.kattis.com/problems/prva
// TODO: study: combine vector, vector reserve, most vex paring in c++, split string with istringstream

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> split(std::string input)
{
    std::vector<std::string> v;
    std::string token;
    std::istringstream token_stream(input);
    while (std::getline(token_stream, token, '#')) {
        v.push_back(token);
    }
    return v;
}

std::vector<std::string> get_horizontal_words(const std::vector<std::vector<char>> v, const int r, const int c)
{
    //a#bc
    std::vector<std::string> all_words;
    std::vector<std::string> line_tokens;
    for (int i = 0; i < r; ++i) {
        std::string s = "";
        for (int j = 0; j < c; ++j) {
            s += v[i][j]; //c++ string + costy? even with move support?
        }
        line_tokens = split(s);
        for(auto s: line_tokens) {
            if (s.size()>=2) all_words.push_back(s);
        }
    }
    return all_words;
}

std::vector<std::string> get_vertical_string(const std::vector<std::vector<char>> v, const int r, const int c)
{
    //a#bc
    std::vector<std::string> all_words;
    std::vector<std::string> line_tokens;
    for (int j = 0; j < c; ++j) {
        std::string s = "";
        for (int i = 0; i < r; ++i) {
            s += v[i][j]; //c++ string + costy? even with move support?
        }
        line_tokens = split(s);
        for(auto s: line_tokens) {
            if (s.size()>=2) all_words.push_back(s);
        }
    }
    return all_words;
}

int main() {
    std::vector<std::vector<char>> vvc;
    std::vector<std::string> hwords, vwords;
    int r, c;
    std::cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        std::vector<char> vc;
        std::string s;
        std::cin >> s;
        for (int j = 0; j < c; ++j) {
            //v[i].push_back(s[j]); // v[i] can cause out of range, undefined behavior, so remember to initialize vector
            vc.push_back(s[j]);
        }
        vvc.push_back(vc);
    }
    hwords = get_horizontal_words(vvc, r, c);
    vwords = get_vertical_string(vvc, r, c);
    std::vector<std::string> all_words;
    all_words.reserve(hwords.size()+ vwords.size());
    all_words.insert(all_words.end(), hwords.begin(), hwords.end());
    all_words.insert(all_words.end(), vwords.begin(), vwords.end());
    std::string lexicographically_smallest = all_words[0];
    for (const auto& word: all_words) {
        if (word < lexicographically_smallest) {
            lexicographically_smallest = word;
        }
    }
    std::cout << lexicographically_smallest;

    return 0;
}
