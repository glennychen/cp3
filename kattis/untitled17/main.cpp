// https://open.kattis.com/problems/faktor
#include <iostream>

int main() {
    int article;
    int impact;
    std::cin >> article >> impact;
    int citation = article*impact;
    citation -= 1;
    // Review c++ integer division
    while (citation%article !=0) {
        citation -= 1;
    }
    std::cout << citation+1;
    return 0;
}
