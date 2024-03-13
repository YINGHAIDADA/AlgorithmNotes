#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;


//2024-03-13 : 13:53:41

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

//2.cpp.
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag = 0;
        ListNode* res = new ListNode(-1);
        ListNode* prev = res;
        while(l1!=nullptr && l2!=nullptr)
        {
            ListNode* n = new ListNode((l1->val + l2->val + flag)%10);
            flag = (l1->val + l2->val + flag)/10;
            prev->next = n;
            prev = n;

            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode* tmp = l1!=nullptr?l1:l2;
        if(tmp!=nullptr)
        {
            if(flag==0)
                prev->next = tmp;
            else
            {
                while (tmp!=nullptr)
                {
                    ListNode* n = new ListNode((tmp->val + flag)%10);
                    flag = (tmp->val + flag)/10;
                    prev->next = n;
                    prev = n;
                    tmp = tmp->next;
                }
            }
        }
        if(flag!=0)
        {
            ListNode* n = new ListNode(flag);
            prev->next = n;
        }
        return res->next;
    }
};

int main()
{
    Solution sul;
    ListNode* l1 = new ListNode(9,new ListNode(9,new ListNode(9,new ListNode(9))));
    ListNode* l2 = new ListNode(9,new ListNode(9));
    auto res = sul.addTwoNumbers(l1,l2);
    return 0;
}