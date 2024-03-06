#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

//15. 三数之和
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0; i <n-2; i++)
        {
            if(nums[i] >0)
                break;
            else if (i>0 && nums[i] == nums[i-1])
                continue;
            int j =i+1,k=n-1;
            while (j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0)
                {
                    res.push_back({nums[i],nums[j],nums[k]});

                    while(j<k && nums[j] == res.back()[1])
                        j++;
                    while(j<k && nums[k] == res.back()[2])
                        k--;
                }
                else if(sum > 0)
                    k--;
                else
                    j++;
            }
            
        }

        return res;
    }
};

int main()
{
    vector<int> nums = { 1,1,1,0,0,0,-1,-1,-1 };
    Solution sul;
    auto res = sul.threeSum(nums);
    return 0;
}
/*
第一想法是排列法检测结果是否为零，但存在复用元素的问题
*/