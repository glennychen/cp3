#include <iostream>

int main() {
    int n;
    std::cin >> n;
    // 0: start 1 edge 2 vertex
    // 1: 2e 3v
    // 2: 4e 5v
    // 3: 8e 9v
    int num_side_edges = 1;
    int num_vertex;
    for(int i=0;i<n;++i) {
        num_side_edges *= 2;
    }
    num_vertex = num_side_edges + 1;  // edge = n, vertex = edge + 1
    std::cout << num_vertex * num_vertex;
    return 0;
}
