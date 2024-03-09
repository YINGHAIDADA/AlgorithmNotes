#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

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

//53. 最大子数组和
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        Timer timer;
        timer.Reset();
        int max = nums[0];
        int sum = 0;
        for(auto& x:nums)
        {
            sum += x;
            if(sum > max)
            {
                max = sum;
            }
            if(sum < 0)
            {
                sum = 0;
            }
        }
        cout << "time: " << timer.ElapsedMillis() << endl;
        return max;
    }
};

int main()
{
    Solution sul;
    vector<int> nums = {-3, -2, -1, -4, -5};
    auto res = sul.maxSubArray(nums);
    return 0;
}