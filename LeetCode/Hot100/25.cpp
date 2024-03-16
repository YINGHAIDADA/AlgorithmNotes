#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;


//2024-03-15 : 14:14:10

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

//25.K 个一组翻转链表

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
    ListNode* reverseList(ListNode* last, ListNode* l, ListNode* r) {
        last->next = r;
        last = l;
        ListNode* curr = l;
        ListNode* prev  =nullptr;
        ListNode* res = r->next;
        while (curr != res) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return res;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* l = head,*r,*res,*next;
        ListNode* prev = new ListNode(-1,head);
        res = prev;
        int count = 0;
        while(l){
            r = l;
            count = 1;
            for(int i=1; i<k; i++)
            {
                if(r->next){
                    r= r->next;
                    count++;
                }
                else
                    break;
            }
            if(count == k)
            {
                next = reverseList(prev,l,r);
                prev = l;
                l= next;
            }
            else
            {
                prev->next = l;
                break;
            }
        }
        return res->next;
    }
};

int main()
{
    Solution sul;
    ListNode* head = new ListNode({1,2,3,4,5});
    auto res = sul.reverseKGroup(head,2);
    return 0;
}