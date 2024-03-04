#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>


using namespace std;

//232.用栈实现队列
class MyQueue {
private:
deque<int> dq;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        dq.push_back(x);
    }
    
    int pop() {
        int res = dq.front();
        dq.pop_front();
        return res;
    }
    
    int peek() {
        return dq.front();
    }
    
    bool empty() {
        return dq.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);

    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();
    return 0;
}