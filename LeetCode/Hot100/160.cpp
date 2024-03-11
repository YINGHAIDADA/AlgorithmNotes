#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;


//2024-03-11 : 20:16:19

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

//160.cpp.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *duiqi(ListNode *pA, ListNode *pB, ListNode *headA, ListNode *headB, int count)
    {
        int lenA = count;
        while (pB!=NULL)
        {
            pB = pB->next;
            count++;
        }
        int lenB = count;
        int diff = lenB - lenA;
        pB = headB;pA = headA;
        while (diff>0)
        {
            pB = pB->next;
            diff--;
        }
        while (pA!=pB)
        {
            pA = pA->next;
            pB = pB->next;
        }
        return pA;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA, *pB = headB;
        int count = 0;
        while(pA!=NULL && pB!=NULL && pA!=pB)
        {
            pA = pA->next;
            pB = pB->next;
            count++;
        }
        if(pA==NULL && pB==NULL) return NULL;
        else if (pA == NULL)
        {
            return duiqi(pA,pB,headA,headB,count);
        }
        else if (pB == NULL)
        {
            return duiqi(pB,pA,headB,headA,count);
        }

        return pA;
    }
};

int main()
{
    Solution sul;
    // auto res = sul.();
    return 0;
}