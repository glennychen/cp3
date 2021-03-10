//Integer to Roman
#define CATCH_CONFIG_MAIN
#include<catch2/catch_all.hpp>
#include <string>

using namespace std;

string intToRoman(int num) {
    string output;
    if(num<10000&&num>=1000){
        int M=num/1000;
        while(M--){
            output.push_back('M');
            num-=1000;
        }
    }
    if(num<1000&&num>=100){
        if(num/100==9){
            output.push_back('C');
            output.push_back('M');
            num-=900;
        } else if(num/100==4){
            output.push_back('C');
            output.push_back('D');
            num-=400;
        } else{
            int D=num/500;
            if(D){
                output.push_back('D');
                num-=500;
            }
            int C=num/100;
            while(C--){
                output.push_back('C');
                num-=100;
            }
        }
    }
    if(num<100&&num>=10){
        if(num/10==9){
            output.push_back('X');
            output.push_back('C');
            num-=90;
        } else if(num/10==4){
            output.push_back('X');
            output.push_back('L');
            num-=40;
        } else {
            int L=num/50;
            if(L){
                output.push_back('L');
                num-=50;
            }
            int X=num/10;
            while(X--){
                output.push_back('X');
                num-=10;
            }
        }
    }
    if(num<10){
        if(num==9){
            output.push_back('I');
            output.push_back('X');
            num-=9;
        } else if (num==4){
            output.push_back('I');
            output.push_back('V');
            num-=4;
        } else {
            int V=num/5;
            if(V){
                output.push_back('V');
                num-=5;
            }
            int I=num/1;
            while(I--)
                output.push_back('I');
                num-=1;
        }
    }
    return output;;
}

TEST_CASE( "Integer to Roman") {
    REQUIRE( intToRoman(3) == "III" );
    REQUIRE( intToRoman(4) == "IV");
    REQUIRE( intToRoman(8) == "VIII");
    REQUIRE( intToRoman(9) == "IX" );
    REQUIRE( intToRoman(10) == "X" );
    REQUIRE( intToRoman(20) == "XX" );
    REQUIRE( intToRoman(58) == "LVIII" );
    REQUIRE( intToRoman(68) == "LXVIII" );
    REQUIRE( intToRoman(1994) == "MCMXCIV" );
    REQUIRE( intToRoman(2356) == "MMCCCLVI" );
    REQUIRE( intToRoman(3998) == "MMMCMXCVIII" );
}
