// https://open.kattis.com/problems/electricaloutlets
#include <iostream>

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int k;
        std::cin >> k;
        int total_appliance_to_power = 0;
        for (int j = 0; j < k; ++j) {
            int l;
            std::cin >> l;
            total_appliance_to_power += l;
        }
        int outlet_needed_to_power_next = k-1;
        std::cout << (total_appliance_to_power - outlet_needed_to_power_next) << '\n';
    }
    return 0;
}
