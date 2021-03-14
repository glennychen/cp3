#define CATCH_CONFIG_MAIN
#include<catch2/catch_all.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//https://leetcode.com/problems/how-many-apples-can-you-put-into-the-basket/

int maxNumberOfApples(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    constexpr int MAX=5000;
    int count=0;
    int total=0;
    for(const auto& elem: arr){
        total+=elem;
        if(total>MAX){
            break;
        }
        ++count;
    }
    return count;
}

TEST_CASE( "maxNumberOfApples") {
    vector<int> v{100,200,150,1000};
    REQUIRE( maxNumberOfApples(v) == 4 );

    v={900,950,800,1000,700,800};
    REQUIRE( maxNumberOfApples(v) == 5 );
}
