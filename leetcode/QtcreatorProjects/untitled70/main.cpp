#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int maxProfit(vector<int>& prices, int fee) {
    int local_min=5001;
    int local_max=0;

    //first one
    //buy, profit=-prices[0], the first one, buy, cost is prices[0]
    //sell, can't sell, profit =0;
    //max profit(-prices[0], 0), 0
    //dp[0]=0

    //dp[1]=
    //buy, profit=-prices[1]
    //sell, profit=prices[1]-fee-(when I bought? each element from 0 to 1, 2, 3...k-1

    //dp[2]
    //buy, profit=-prices[2]
    //sell, profit=prices[2]-fee-(when I bought? each element from 0 to 1, 2, 3...k-1
    if (prices.size() < 2)
        return 0;
    //base case
    int sold = 0, hold = 0 - prices[0];
    for (int i = 1; i < prices.size(); i++) {
      hold = max(hold, sold - prices[i]); //if you hold again=buy= -prices[i], sold-buy= profit
      sold = max(sold, hold + prices[i] - fee); //if you sell, sell what you old + price[i]-fee
     }
     return sold;
}


int main()
{
    vector<int> v{1,3,2,8,4,9};
    maxProfit(v,2);
    return 0;
}
