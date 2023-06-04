//2651. Calculate Delayed Arrival Time
#include <iostream>
using namespace std;

class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime+delayedTime)%24;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
