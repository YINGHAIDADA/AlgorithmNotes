#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <deque>

using namespace std;


//2024-03-13 : 17:33:03

class Timer
{
public:
    Timer() { Reset(); }
    void Reset() { m_Start = std::chrono::high_resolution_clock::now(); }
    float Elapsed(){
        return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - m_Start).count() * 0.001f * 0.001f * 0.001f;}
    float ElapsedMillis() { return Elapsed() * 1000.0f; }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_Start;
};

//239.滑动窗口最大值
//超时
// class Solution {
// public:
//     int maxInWindow(vector<int>& nums, int begin,int end)
//     {
//         int index = begin;
//         for(int i = begin; i <= end; i++)
//         {
//             if (nums[i]>nums[index])
//             {
//                 index = i;
//             }
//         }
//         return index;
//     }
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> result;
//         if (nums.size() == 1)
//             return nums;
//         int max = maxInWindow(nums,0,k-1);
//         result.push_back(nums[max]);
//         for(int i = 1; i <= nums.size() - k; i++)
//         {
//             if(i == max+1)
//             {
//                 max = maxInWindow(nums, i, i+k-1);
//             }
//             else if(nums[i+k-1]>nums[max])
//             {
//                 max = i+k-1;
//             }

//             result.push_back(nums[max]);
//         }
//         return result;
//     }
// };
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() == 0 || k == 0) return {};
        deque<int> deque;
        vector<int> res(nums.size() - k + 1);
        for(int j = 0, i = 1 - k; j < nums.size(); i++, j++) {
            // 删除 deque 中对应的 nums[i-1]
            if(i > 0 && deque.front() == nums[i - 1])
                deque.pop_front();
            // 保持 deque 递减
            while(!deque.empty() && deque.back() < nums[j])
                deque.pop_back();
            deque.push_back(nums[j]);
            // 记录窗口最大值
            if(i >= 0)
                res[i] = deque.front();
        }
        return res;
    }
};
//单调队列

int main()
{
    Solution sul;
    vector<int> nums = {1,-1};
    int k = 1;
    auto res =sul.maxSlidingWindow(nums,k);
    return 0;
}