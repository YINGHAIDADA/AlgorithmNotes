#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//560. 和为 K 的子数组
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //前缀和 + 哈希表优化
        //mp 意义：键值为 和的值，val为出现的技术
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, prev = 0;
        for(auto& x:nums)
        {
            prev +=x;
            if(mp.find(prev - k) != mp.end())
            {
                count += mp[prev - k];
            }
            mp[prev]++;
        }
        
        return count;
    }
};

int main()
{
    Solution sul;
    vector<int> nums = {-1,-1,1};
    int k = 0;
    auto res = sul.subarraySum(nums,k);
    return 0;
}