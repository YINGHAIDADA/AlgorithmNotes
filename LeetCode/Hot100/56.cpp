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

//56. 合并区间
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        auto cmp  = [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; };
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> temp = intervals[0];
        if(intervals.size() == 1) { res.push_back(temp); return res; }
        for (int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] <= temp[1])  temp[1] = max(temp[1], intervals[i][1]);
            else
            {
                res.push_back(temp);
                temp = intervals[i];
            }

            if(i == intervals.size() - 1)   res.push_back(temp);
        }
        return res;
    }
};

int main()
{
    Solution sul;
    vector<vector<int>> intervals = {{1,3}};
    auto res = sul.merge(intervals);
    return 0;
}