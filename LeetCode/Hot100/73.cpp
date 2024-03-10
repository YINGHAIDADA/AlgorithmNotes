#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;


//2024-03-10 : 14:03:00

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

//73.矩阵置零
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> point;
        for(int i =0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    point.push_back({i,j});
                }
            }
        }
        for(auto& x:point)
        {
            int i=x[0],j=0;
            while(j<matrix[i].size())
                matrix[i][j++] = 0;
            i=0;j = x[1];
            while(i<matrix.size())
                matrix[i++][j] = 0;
        }
    }
};

int main()
{
    Solution sul;
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    sul.setZeroes(matrix);
    return 0;
}