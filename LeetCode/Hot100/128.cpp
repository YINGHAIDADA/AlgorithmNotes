#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

//128. 最长连续序列
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1)
            return nums.size();
        
        set<int> s(nums.begin(), nums.end());
        int max = 1, tmp = 1, prev = 0;
        set<int>::iterator it = s.begin();
        prev = *it;
        it++;
        while (it != s.end())
        {
            if(*it == prev + 1)
            {
                tmp++;
                max = max > tmp ? max : tmp;
            }
            else
                tmp = 1;
            prev = *it;
            it++;
        }
        return max;
    }
};

int main()
{
    Solution sul;
    vector<int> nums = { 9,1,4,7,3,-1,0,5,8,-1,6 };
    auto res = sul.longestConsecutive(nums);
    return 0;
}