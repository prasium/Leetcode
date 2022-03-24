"""
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

    void push(int x) Pushes element x to the back of the queue.
    int pop() Removes the element from the front of the queue and returns it.
    int peek() Returns the element at the front of the queue.
    boolean empty() Returns true if the queue is empty, false otherwise.

Notes:

    You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
    Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

"""
class MyQueue {
public:
    stack<int> s;
    stack<int> aux;
    int front;
    MyQueue() {
        s = stack<int> ();
        aux = stack<int> ();
    }
    // Making Push O(1) and Pop O(n)
    void push(int x) {
        s.push(x);  
    }
    
    int pop() {
        // Element to pop is bottom of stack s
        // Transfer to aux stack till s is empty
        if(aux.empty()){
        while(!s.empty())
        {
            int val = s.top();
            aux.push(val);
            s.pop();
        }
        }
        // Pop the top of aux
        int del = aux.top();
        aux.pop();
        return del;
    }
    
    int peek() {
        if(aux.empty()){
        while(!s.empty())
        {
            int val = s.top();
            aux.push(val);
            s.pop();
        }
        }
        return aux.top();
    }
    
    bool empty() {
        return s.empty()&&aux.empty();
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