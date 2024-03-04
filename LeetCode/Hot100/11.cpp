#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//11. 盛最多水的容器
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right = height.size()-1;
        int max_area = 0;
        while(left<right)
        {
            int area = min(height[left],height[right])*(right-left);
            if(area > max_area)
            {
                max_area = area;
            }
            
            if(height[left]<height[right])
                left++;
            else
                right--;
        }
        return max_area;
    }
};

int main()
{
    vector<int> nums = {1,8,6,2,5,4,8,3,7};
    Solution sul;
    cout<<sul.maxArea(nums)<<endl;
    return 0;
}