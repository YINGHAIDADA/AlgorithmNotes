#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

//42. 接雨水
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int ans = 0;
        for (int i = 0; i < height.size(); i++) {
            if(stk.empty() || height[stk.top()] >= height[i])
                stk.push(i);
            else {
                while (!stk.empty() && height[stk.top()] < height[i])
                {
                    int top = stk.top();
                    stk.pop();
                    if (stk.empty()) continue;
                    ans += (min(height[i], height[stk.top()]) - height[top]) * (i - stk.top() - 1);
                }
                stk.push(i);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sul;
    vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    auto res = sul.trap(height);
    return 0;
}