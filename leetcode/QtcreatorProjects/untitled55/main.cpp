#define CATCH_CONFIG_MAIN
#include<catch2/catch_all.hpp>
#include<vector>
#include<string>
#include <iostream>
#include <bitset>

using namespace std;

//https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/submissions/
vector<int> sortByBits(vector<int>& arr) {
    vector<pair<int,int>> v;
    for(const auto& elem:arr){
        int one_bits=bitset<32>(elem).count();
        v.push_back({elem, one_bits});
    }
    sort(v.begin(),v.end(),[](const auto& elem1, const auto& elem2){
       //return elem1.second<elem2.second; //when number of bits are the same, sort by decimal
       if (elem1.second==elem2.second)
           return elem1.first<elem2.first;
       return elem1.second<elem2.second;
    });
    vector<int> res;
    for(const auto& elem:v){
        res.push_back(elem.first);
    }
    return res;
}

TEST_CASE( "Integer to Roman") {
    vector<int> v1{0,1,2,3,4,5,6,7,8};
    vector<int> a1{0,1,2,4,8,3,5,6,7};
    REQUIRE( sortByBits(v1) == a1  );

    vector<int> v{1024,512,256,128,64,32,16,8,4,2,1};
    vector<int> a{1,2,4,8,16,32,64,128,256,512,1024};
    REQUIRE( sortByBits(v) == a  );

    vector<int> v3{2,3,5,7,11,13,17,19};
    vector<int> a3{2,3,5,17,7,11,13,19};
    REQUIRE( sortByBits(v3) == a3  );

    vector<int> v4{10,100,1000,10000};
    vector<int> a4{10,100,10000,1000};
    REQUIRE( sortByBits(v4) == a4  );
}
