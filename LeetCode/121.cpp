#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
//121.买卖股票的最佳时机
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int max_profit = 0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]<min_price)
            {
                min_price = prices[i];
            }
            else if (prices[i] - min_price > max_profit)
            {
                max_profit = prices[i] - min_price;
            }
            
        }
        return max_profit;
    }
};
/*
其核心在于假设我们已经在历史的某一天买入了，
在每一天要想获得最大利润就需要我们买入的是历史最低价，
所以当我们遇到历史最低价时就替换我们的最低价记录，
但是并不代表我们在遇到历史最低价前不能获得最大利润，如[2,100,1,2,3]
历史最低价只能代表从当天开始往后能获得最大利润，所以在没碰到1的时候我们的最大利润已经确立了
*/

int main()
{
Solution sul;
vector<int> prices = {2,100,1,5,6,4,3};
printf("%d",sul.maxProfit(prices));
return 0;
}