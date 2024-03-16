#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;


//2024-03-14 : 09:28:03

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

//24.两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* next,*res,*cur;
        ListNode* prev = new ListNode(-1,head);
        if(head == nullptr || head->next == nullptr) return head;
        cur = head;
        next = head->next;
        res = next;
        while(true){
            cur->next = next->next;
            next->next = cur;
            prev->next = next;
            prev = cur;
            if(cur->next == nullptr || cur->next->next == nullptr) break;
            cur = cur->next;
            next = cur->next;
        }
        return res;
    }
};

int main()
{
    Solution sul;
    ListNode* head = new ListNode({1,2,3,4});
    auto res = sul.swapPairs(head);
    return 0;
}