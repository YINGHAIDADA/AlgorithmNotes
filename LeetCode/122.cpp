#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
//122.买卖股票的最佳时机II
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;
        int local_max_profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < min_price)
            {
                min_price = prices[i];
            }
            else if (prices[i] - min_price > local_max_profit)
            {
                local_max_profit = prices[i] - min_price;
            }
            
            if(i >0 && prices[i] < prices[i-1]){
                max_profit+=local_max_profit;
                local_max_profit = 0;
                min_price = prices[i];
            }
            else if (i == prices.size()-1)
            {
                local_max_profit = prices[i] - min_price;
                max_profit+=local_max_profit;
            }
        }
        
        return max_profit;
    }
};
/*
其核心在于找局部最高点以及他之前的历史最低点
*/

int main()
{
Solution sul;
vector<int> prices = {1,2,3,4,5};
printf("%d",sul.maxProfit(prices));
return 0;
}