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

//238. 除自身以外数组的乘积
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> front(nums.size(),0),back(nums.size(),0),res(nums.size(),0);
        int sum = 1;
        for(int i = 0;i<nums.size();i++)
        {
            sum *= nums[i];
            front[i] = sum;
        }
        sum = 1;
        for(int i = nums.size()-1;i>=0;i--)
        {
            sum *= nums[i];
            back[i] = sum;
        }
        for(int i = 0;i<nums.size();i++)
        {
            if(i ==0)
                res[i] = back[i+1];
            else if(i == nums.size()-1)
                res[i] = front[i-1];
            else
            res[i] = front[i-1] * back[i+1];
        }
        return res;
        
    }
};

int main()
{
    Solution sul;
    vector<int> nums = { 1,2,3,4 };
    auto res =sul.productExceptSelf(nums);
    return 0;
}