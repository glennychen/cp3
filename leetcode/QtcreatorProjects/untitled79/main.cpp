#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool isHappy(int n) {
    vector<int> v;
    for(;;){
        int sum{0};
        while(n>0){
            sum+=pow(n%10,2);
            n/=10;
        }
        if(sum==1)
            return true;

        //use unorder_map to look up duplicate
        v.push_back(sum);
        auto iter=find(v.begin(), v.end(), sum);
        if (iter!=v.end())
            return false;

        n=sum;
    }
    return true;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
