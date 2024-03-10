#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;


//2024-03-10 : 13:37:41

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

//41.缺失的第一个正数
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> zheng(100000,0);
        int min=1;
        for(auto& x:nums)
        {
            if(x>0&&x<=100000)
                zheng[x-1] = 1;
        }
        return distance(zheng.begin(), find(zheng.begin(), zheng.end(), 0)) + 1;
    }
};

int main()
{
    Solution sul;
    vector<int> nums = { 1,2,0 };
    auto res = sul.firstMissingPositive(nums);
    return 0;
}