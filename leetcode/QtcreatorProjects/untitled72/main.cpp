#include <iostream>
#include <vector>
#include <random>
#include <functional>
//Generate Random Point in a Circle

using namespace std;

class Solution {
public:

    double radius, x_center, y_center;
    default_random_engine re{};
    uniform_real_distribution<> dis_x;
    uniform_real_distribution<> dis_y;

    Solution(double radius, double x_center, double y_center):
        radius{radius}, x_center{x_center}, y_center{y_center} {

        double low_x=x_center-radius;
        double high_x=x_center+radius;
        double low_y=y_center-radius;
        double high_y=y_center+radius;
        dis_x=uniform_real_distribution<>{low_x,high_x };
        dis_y=uniform_real_distribution<>{low_y,high_y};
    }

    vector<double> randPoint() {

        vector<double> v;
        for(;;){
            auto x=dis_x(re);
            auto y=dis_y(re);
            double delta_x, delta_y;
            delta_x=x-x_center;
            delta_y=y-y_center;
            double length= sqrt(pow(delta_x,2)+pow(delta_y,2));
            if (length<=radius){
                vector<double> v={x,y};
                return v;
            }
        }

        return v;
    }
};

int main()
{
    //Solution s(1,0,0);
    Solution s(10,5,-7.5);
    vector<double> v;
    v=s.randPoint();
    v=s.randPoint();
    v=s.randPoint();
    v=s.randPoint();
    v=s.randPoint();
    v=s.randPoint();
    v=s.randPoint();
    v=s.randPoint();
    v=s.randPoint();
    v=s.randPoint();
    return 0;
}
