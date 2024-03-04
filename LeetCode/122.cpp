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
        int min_price = prices[0];
        int max_profit = 0;
        
        return max_profit;
    }
};
/*
其核心在于找局部最高点以及他之前的历史最低点
*/

int main()
{
Solution sul;
vector<int> prices = {2,100,1,5,6,4,3};
printf("%d",sul.maxProfit(prices));
return 0;
}