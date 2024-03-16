#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;


//2024-03-15 : 14:39:15

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

//138.随机链表的复制
/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
    Node(int _val, Node* r) {
        val = _val;
        next = NULL;
        random = r;
    }
    Node(const vector<vector<int>>& v)
    {
        if(v.empty()) return;
        this->val = v[0][0];
        Node *p = this;
        for(int i = 1; i < v.size(); ++i){
            p->random = 
            p->next = new Node(v[i][0]);

            p = p->next;
        }
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
    }
};

int main()
{
    Solution sul;
    Node* head  = new Node({{7,13},{11,10},{1,12},{1,3},{0,6}});
    auto res = sul.copyRandomList(head);
    return 0;
}