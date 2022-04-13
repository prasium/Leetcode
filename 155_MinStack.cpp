"""
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

    MinStack() initializes the stack object.
    void push(int val) pushes the element val onto the stack.
    void pop() removes the element on the top of the stack.
    int top() gets the top element of the stack.
    int getMin() retrieves the minimum element in the stack.

"""

// Using two stacks
class MinStack {
public:
    stack<int> s1,s2;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if(s1.empty())
        {
            s2.push(val);
        }
        else if(val<=s2.top())
        {
            s2.push(val);
        }
        s1.push(val);
    }
    
    void pop() {
        if(s1.empty())
            return;
        if(s1.top()==s2.top())
            s2.pop();
        s1.pop();
        
    }
    
    int top() {
        if(s1.empty())
            return -1;
        return s1.top();
    }
    
    int getMin() {
        if(s1.empty())
            return -1;
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// Using LinkedList
class MinStack {
public:
    struct Node{
        int val, mn;
        Node* next;
        Node(int _val, int _mn, Node*_next = NULL){
            val = _val;
            mn = _mn;
            next = _next;
        }
    }*head;
    void push(int val) {
        if(!head){
            head = new Node(val, val);
        } 
        else{
            head = new Node(val, min(val, head->mn), head);
        }
    }
    
    void pop() {
        if(!head) return ;
        Node* temp = head;
        head = head->next;
        delete(temp);
    }
    
    int top() {
        if(!head) return -1;
        return head->val;
    }
    
    int getMin() {
        if(!head) return -1;
        return head->mn;
    }
};