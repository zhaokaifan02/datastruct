//232 Implement Queue From stack
#include <stack>
#include <iostream>
using namespace std; 

class MyQueue {
public:
    std::stack<int> s1;
    std::stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s1.empty())
        {
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int t = s2.top();
        s2.pop();
        return t;
    }
    
    int peek() {
                if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int t = s2.top();
        return t;
    }
    
    bool empty() {
        return s1.empty()&&s2.empty();
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