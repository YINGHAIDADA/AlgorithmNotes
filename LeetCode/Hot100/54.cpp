#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;


//2024-03-10 : 14:11:41

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

//54.螺旋矩阵
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int top=0, left=0, right=matrix[0].size()-1, bottom=matrix.size()-1;
        int i= top,j = left;
        int dir = 0; //0:right,1:down,2:left,3:up
        while(top<=bottom && left<=right)
        {
            res.push_back(matrix[i][j]);
            if(dir == 0)
            {
                if(j == right)  { dir = 1; i++; top++; }
                else    j++;
            }
            else if(dir == 1)
            {
                if(i == bottom)  { dir = 2; j--; right--; }
                else    i++;
            }
            else if (dir == 2)
            {
                if(j == left)  { dir = 3; i--; bottom--; }
                else    j--;
            }
            else
            {
                if(i == top)  { dir = 0; j++; left++; }
                else    i--;
            }
        }
        return res;
    }
};

int main()
{
    Solution sul;
    vector<vector<int>> matrix = { {1,2,3},{4,5,6},{7,8,9} };
    auto res = sul.spiralOrder(matrix);
    return 0;
}