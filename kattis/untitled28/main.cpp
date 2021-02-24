// https://open.kattis.com/problems/heartrate

// TODO: fix it, the answer is not correct

#include <iostream>
#include <math.h>
#include <iomanip>

int main() {
    double n, b, p, BPM, ABPM, min_t, max_t;

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> b >> p;

        BPM = 60*(b/p);
        if (b/p>1) {
            min_t = floor(b / p);
        }
         max_t = 2*(b/p)-min_t;
        // t = b/p (If t is the amount of time (in seconds) between each beat of your heart)

        ABPM = 60/(b/p);

        std::cout << std::fixed;
        std::cout << std::setprecision(4);
        std::cout << 60*min_t << " " << BPM << " " << 60*max_t;

    }

    return 0;
}
