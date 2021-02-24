// https://open.kattis.com/problems/bela
#include <iostream>
#include <map>
#include <string>

std::map<char, int> get_dominant_table()
{
    std::map<char, int> m;
    m['A'] = 11;
    m['K'] = 4;
    m['Q'] = 3;
    m['J'] = 20;
    m['T'] = 10;
    m['9'] = 14;
    m['8'] = 0;
    m['7'] = 0;
    return m;
}

std::map<char, int> get_non_dominant_table()
{
    std::map<char, int> m;
    m['A'] = 11;
    m['K'] = 4;
    m['Q'] = 3;
    m['J'] = 2;
    m['T'] = 10;
    m['9'] = 0;
    m['8'] = 0;
    m['7'] = 0;
    return m;
}

int main() {
    int N; // num of hands
    char B; // value of dominant suit
    std::map<char, int> dt = get_dominant_table();
    std::map<char, int> non_dt = get_non_dominant_table();
    int total_value = 0;

    std::cin >> N >> B;

    for(int i=0;i<N;++i) {
        for(int j=0;j<4;++j) {
            std::string s;
            char card, suit;
            std::cin >> s;
            card = s[0];
            suit = s[1];
            if (suit == B) {
                //dominant
                total_value += dt[card];
            } else {
                //not dominant
                total_value += non_dt[card];
            }
        }
    }
    std::cout << total_value;
    return 0;
}


