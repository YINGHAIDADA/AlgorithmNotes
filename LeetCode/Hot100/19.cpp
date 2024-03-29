#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;


//2024-03-13 : 14:43:22

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

//19.删除链表的倒数第 N 个结点
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
    int countDown(ListNode* head, int n)
    {
        if(head->next ==nullptr)
            return 1;
        int res = countDown(head->next,n);

        if(res == -1)
            return -1;

        if(res == n)
        {
            head->next = head->next->next;
            return -1;
        }
        return res +1;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pHead = new ListNode(-1,head);

        int res = countDown(pHead,n);
        if(res == 1){
            ListNode* p =nullptr;
            return p;
        }
        return pHead->next;
    }
};

int main()
{
    Solution sul;
    ListNode* head = new ListNode({1,2,3,4,5});
    auto res = sul.removeNthFromEnd(head,2);
    return 0;
}