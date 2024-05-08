//225 implement-stack-using-queues/
#include <stack>
#include <queue>
using namespace std;
class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;
    MyStack()
    {
    }

    void push(int x)
    {
        queue<int> &a = q1.empty() ? q2 : q1;
        a.push(x);
    }

    int pop()
    {
        queue<int> &a = q1.empty() ? q1 : q2; // empty
        queue<int> &b = q1.empty() ? q2 : q1;
        int t;
        while (b.size() != 1)
        {
            a.push(b.front());
            b.pop();
        }
        t = b.front();
        b.pop();
        return t;
    }

    int top()
    {
        queue<int> &a = q1.empty() ? q1 : q2; // empty
        queue<int> &b = q1.empty() ? q2 : q1;
        int t;
        while (b.size() != 1)
        {
            a.push(b.front());
            b.pop();
        }
        t = b.front();
        b.pop();
        a.push(t);
        return t;
    }

    bool empty()
    {
        return q1.empty() &&q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */