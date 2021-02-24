// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

double average(vector<int>& salary) {
    std::sort(salary.begin(), salary.end());
    double sum = std::accumulate(salary.begin()+1, salary.end()-1, 0);
    return double(sum)/double(salary.size()-2); //https://stackoverflow.com/questions/7571326/why-does-dividing-two-int-not-yield-the-right-value-when-assigned-to-double
}

int main() {
    std::vector<int> v1 = {4000,3000,1000,2000};
    double ave = average(v1);
    v1 = {1000,2000,3000};
    ave = average(v1);
    v1 = {6000,5000,4000,3001,2000,1000};
    ave = average(v1);
    return 0;
}
