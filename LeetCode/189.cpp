#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//189轮转数组
class Solution {
public:
    static int gcd(int a, int b)
    {
        while(b != 0)
        {
            int c = a % b;
            a = b;
            b = c;
        }
        return a;
    }
    static void rotate(std::vector<int>& nums, int k) {
        int len = nums.size();
        // int half = len/2;
        if(k == len || k == 0)
            return;
        int gcd_num = gcd(len,k);
        if(gcd_num == 1)
        {
            int inst = k%len;
            int prev = nums[inst], next = 0;
            nums[inst] = nums[0];
            while( inst != 0)
            {
                next = nums[(inst+k)%len];
                nums[(inst+k)%len] = prev;
                prev = next;
                inst = (inst+k)%len;
            }
        }
        else
        {
            int count = 0;
            while(count < gcd_num)
            {
                int inst = (count+k)%len;
                int prev = nums[inst], next = 0;
                nums[inst] = nums[count];
                while( inst != count)
                {
                    next = nums[(inst+k)%len];
                    nums[(inst+k)%len] = prev;
                    prev = next;
                    inst = (inst+k)%len;
                }
                count++;
            }
        }
        
    }
};

int main()
{
    std::vector<int> nums = {1,2,3,4,5,6};
    int k = 4;
    Solution::rotate(nums,k);
    return 0;
}