//https://leetcode.com/problems/maximum-units-on-a-truck/solution/
#define CATCH_CONFIG_MAIN
#include<catch2/catch_all.hpp>
#include <iostream>
#include <vector>

using namespace std;

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(),[](const auto& box1, const auto& box2){
        return box1[1]>box2[1]; //non-ascending order
    });

    int box_left=truckSize;
    int units=0;
    for(const auto& elem:boxTypes){
        int boxes=elem[0];
        int box_units=elem[1];
        if(box_left>=boxes){
            units+=boxes*box_units;
            box_left-=boxes;
        } else {
            units+=box_left*box_units;
            break;
        }
    }
    return units;
}

TEST_CASE( "Integer to Roman") {
    vector<vector<int>> v = {{1,3},{2,2},{3,1}};
    REQUIRE( maximumUnits(v,4) == 8 );

    vector<vector<int>> v2 = {{5,10},{2,5},{4,7},{3,9}};
    REQUIRE( maximumUnits(v2,10) == 91 );
}
