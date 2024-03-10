#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;


//2024-03-10 : 15:46:39

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

//48.旋转图像
class Solution {
public:
    void rotate_position(vector<int>& position, int n)
    {
        int temp = position[0];
        position[0] = position[1];
        position[1] = (n - temp - 1);
    }
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        int n = len;
        if(len == 1)
            return;
        if(len % 2 == 0)
            len = len/2;
        else
            len = len/2 + 1;
        for(int i = 0; i < len; i++)
        {
            for(int j = i; j < n-i-1; j++)
            {
                vector<int> position = {i,j};
                int temp = matrix[position[0]][position[1]];
                int next  =0,count = 0;
                while(true)
                {
                    rotate_position(position, matrix.size());
                    count++;
                    next = matrix[position[0]][position[1]];
                    matrix[position[0]][position[1]] = temp;
                    temp = next;
                    if(count == 4)
                        break;
                }
            }
        }
    }
};

/*
首先考虑如何选择作用范围可以覆盖整个矩阵，
当矩阵边长为奇数，则选择大小为二分之一加一大小的子矩阵作为遍历范围（从左上角选）
当为偶数，则选择二分之一的子矩阵
*/

int main()
{
    Solution sul;
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    sul.rotate(matrix);
    return 0;
}