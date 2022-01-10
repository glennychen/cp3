//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_price=INT_MAX;
        int max_profit=0;
        for(const auto& elem: prices){
            buy_price=min(buy_price, elem);
            max_profit=max(max_profit, elem-buy_price);
        }
        return max_profit;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
