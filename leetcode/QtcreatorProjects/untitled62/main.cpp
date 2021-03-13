// Check If a String Contains All Binary Codes of Size K
#define CATCH_CONFIG_MAIN
#include<catch2/catch_all.hpp>
#include <string>
#include <unordered_map>

using namespace std;

bool hasAllCodes(string s, int k) {
    unordered_map<string, int> um;
    int length=k;
    for(int pos=0;pos+length<=s.size();++pos){
        string sub=s.substr(pos,length);
            ++um[sub];
    }
    return um.size()>=pow(2,k);
}

TEST_CASE("hasAllCodes") {
    REQUIRE( hasAllCodes("00110110",2) == true );
    REQUIRE( hasAllCodes("00110",2) == true );
    REQUIRE( hasAllCodes("0110",1) == true );
    REQUIRE( hasAllCodes("0110",2) == false );
    REQUIRE( hasAllCodes("0000000001011100",4) == false );
}
