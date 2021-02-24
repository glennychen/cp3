// https://leetcode.com/problems/design-parking-system/
#include <iostream>

using namespace std;

class ParkingSystem {
public:
    // a good question to review "The 7 defaults"
    ParkingSystem() = default;

    ParkingSystem(int big, int medium, int small) : big{big}, medium{medium}, small{small} {
    }

    ParkingSystem(const ParkingSystem &pk) = delete;

    ParkingSystem &operator=(const ParkingSystem &pk) = delete;

    ParkingSystem(ParkingSystem &&pk) = delete;

    //ParkingSystem&& operator=(ParkingSystem&& pk) { //wrong, just return reference, not duble &&
    ParkingSystem &operator=(ParkingSystem &&pk) = delete;

    ~ParkingSystem() = default;

    bool addCar(int carType) {
        // use class enum?
        if (carType == 1) {
            if (big > 0) {
                --big;
                return true;
            }
            return false;
        }
        if (carType == 2) {
            if (medium > 0) {
                --medium;
                return true;
            }
            return false;
        }
        if (carType == 3) {
            if (small > 0) {
                --small;
                return true;
            }
            return false;
        }

        //handle default?
        return false;
    }

private:
    int big, medium, small;
};

int main() {
    ParkingSystem *obj = new ParkingSystem(1, 1, 0);
    bool param_1 = obj->addCar(1);
    bool param_2 = obj->addCar(2);
    bool param_3 = obj->addCar(3);
    bool param_4 = obj->addCar(1);

    return 0;
}
