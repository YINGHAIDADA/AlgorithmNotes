#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;


//2024-03-12 : 14:11:24

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

//234.cpp.
/**
 * Definition for singly-linked list.

 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() 
        : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int count = 0;
        ListNode* p = head;
        int flag = 0;
        while(p)
        {
            count++;
            p = p->next;
        }
        if(count%2 !=0)
            flag = 1;
        count = count/2;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (count > 0) {
            count--;
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if(flag)
            curr = curr->next;
        while(curr && prev)
        {
            if(curr->val != prev->val)
                return false;
            curr = curr->next;
            prev = prev->next;
        }
        return true;
    } 
};

int main()
{
    Solution sul;
    ListNode* p;
    sul.isPalindrome(p);
    return 0;
}