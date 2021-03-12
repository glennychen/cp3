#define CATCH_CONFIG_MAIN
#include<catch2/catch_all.hpp>
#include<vector>
#include<string>

using namespace std;

//Coin Change

int coinChange(vector<int>& coins, int amount)
{
    constexpr int INF=9999999;
    vector<int> dp(amount+1);
    for(auto& elem:dp){
        elem=9999999;
    }

    //e.g. [1,2,5] to build 11
    dp[0]=0;
    vector<pair<int, int>> coin_amount;
    for(int amt=1;amt<=amount;++amt){
        for(const auto& coin:coins){
            if (amt-coin<0)
                continue;
            //dp[amt]=min(dp[amt-coin], dp[amt-1]+1); //what
            int old=dp[amt];
            int update=dp[amt-coin]+1; //1 mean one more step
            if(update<old){
                dp[amt]=min(update, old);
                coin_amount.push_back({coin, amt});
            }
        }
    }

    return dp[amount] == INF ? -1: dp[amount];
}
namespace s1{
int coinChange(vector<int>& coins, int amount) {
    if(amount==0)
        return 0;

    sort(coins.begin(), coins.end(), greater<int>());
    auto last=remove_if(coins.begin(),coins.end(),[amount](const auto& elem){
        return elem>amount;
    });
    coins.erase(last, coins.end());

    int steps=0;
    int new_amount=amount;
    for(const auto& coin:coins){
        int x=new_amount/coin;
        if (x>0){
            while(x--){
                ++steps;
                new_amount-=coin;
            }
        }
    }
    if(new_amount==0){
        return steps;
    }

    sort(coins.begin(), coins.end());
    for(auto iter=coins.begin();iter!=coins.end();++iter){
        vector<int> subset(iter, coins.end());
        do{
            int steps=0;
            int new_amount=amount;
            for(const auto& coin:subset){
                int x=new_amount/coin;
                if (x>0){
                    while(x--){
                        ++steps;
                        new_amount-=coin;
                    }
                }
            }
            if(new_amount==0){
                return steps;
            }
        } while(next_permutation(subset.begin(), subset.end()));
    }

    return -1;
}
};

TEST_CASE( "Integer to Roman") {
    vector<int>v{1,2,5};
    REQUIRE( coinChange(v,11) == 3 );

//    v={2};
//    REQUIRE( coinChange(v,3) == -1 );

//    v={1};
//    REQUIRE( coinChange(v,0) == 0 );

//    v={1};
//    REQUIRE( coinChange(v,1) == 1 );

//    v={1};
//    REQUIRE( coinChange(v,2) == 2 );

//    v={186,419,83,408};
//    REQUIRE( coinChange(v,6249) == 20 );
}
