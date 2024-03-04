#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//283. 移动零
// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
// 请注意 ，必须在不复制数组的情况下原地对数组进行操作。

// 示例 1:

// 输入: nums = [0,1,0,3,12]
// 输出: [1,3,12,0,0]
// 示例 2:

// 输入: nums = [0]
// 输出: [0]
 
// 提示:

// 1 <= nums.length <= 104
// -231 <= nums[i] <= 231 - 1
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int inst = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                if(nums[inst] == 0){
                    nums[inst] = nums[i];
                    nums[i] = 0;
                }
                else
                    inst++;
            }
        }
    }
};
/*
第二次思考，只用一遍遍历来解决，移动非零元素至零下标
*/


int main()
{
vector<int> nums = {0,1,0,3,12};
Solution sul;
sul.moveZeroes(nums);
return 0;
}