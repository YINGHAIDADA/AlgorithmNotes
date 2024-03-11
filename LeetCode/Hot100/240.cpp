#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;


//2024-03-11 : 17:30:41

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

//240.搜索二维矩阵 II
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int m = matrix.size();
        vector<int> node = { 0, n - 1 };
        while (node[0] < m && node[1] >= 0)
        {
            if(target == matrix[node[0]][node[1]])  return true;
            else if (target > matrix[node[0]][node[1]]) node[0] += 1;
            else    node[1] -= 1;
        }
        return false;
    }
};
/*
将矩阵看为一个图，从右上角为根节点，向左是变小向下是变大
*/

int main()
{
    Solution sul;
    vector<vector<int>> matrix = { {-1,3} };
    int target = 3;
    sul.searchMatrix(matrix, target);
    return 0;
}