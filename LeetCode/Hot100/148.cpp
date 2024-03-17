#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;


//2024-03-16 : 15:54:14

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

//148.cpp.
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ListNode(const vector<int>& v){
        if(v.empty()) return;
        this->val = v[0];
        ListNode *p = this;
        for(int i = 1; i < v.size(); ++i){
            p->next = new ListNode(v[i]);
            p = p->next;
        }
    }
};
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        bool flag = true;
        ListNode* p = head;
        while(1)
        {
            p = head;
            while(p->next != nullptr)
            {
                if(p->val > p->next->val)
                {
                    int t = p->val;
                    p->val = p->next->val;
                    p->next->val = t;
                    flag = false;
                }
                p = p->next;
            }
            if(flag) break;
            else flag = true;
        }
        return head;
        //return mergeSort(head);
    }
};

int main()
{
    Solution sul;
    ListNode* head = new ListNode({4,2,1,3});
    ListNode* head1 = new ListNode({-1,5,3,4,0});
    
    auto res = sul.sortList(head);
    return 0;
}