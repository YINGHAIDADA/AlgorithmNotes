#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;


//2024-03-12 : 14:29:44

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

//141.环形链表
/**
 * Definition for singly-linked list.
 * */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/**/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next ==NULL)
            return false;
        ListNode* tu = head->next->next,*gui = head->next;
        while(tu && gui)
        {
            if(tu == gui)
                return true;
            tu = tu->next;
            if(tu == NULL)
                return false;
            tu = tu->next;
            gui = gui->next;
        }
        return false;
    }
};
//快慢指针，一块一慢

int main()
{
    Solution sul;
    ListNode *p;
    sul.hasCycle(p);
    return 0;
}