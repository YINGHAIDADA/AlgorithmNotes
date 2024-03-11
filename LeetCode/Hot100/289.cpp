#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;


//2024-03-11 : 12:19:15

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

//289.生命游戏
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> change;
        for (int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++)
            {
                
            }
        }
    }
};

int main()
{
    Solution sul;
    vector<vector<int>> board = { {0,1,0},{0,0,1},{1,1,1},{0,0,0} };
    sul.gameOfLife(board);
    return 0;
}