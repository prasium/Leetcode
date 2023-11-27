"""
Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Implementation the MyCircularQueue class:

    MyCircularQueue(k) Initializes the object with the size of the queue to be k.
    int Front() Gets the front item from the queue. If the queue is empty, return -1.
    int Rear() Gets the last item from the queue. If the queue is empty, return -1.
    boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
    boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
    boolean isEmpty() Checks whether the circular queue is empty or not.
    boolean isFull() Checks whether the circular queue is full or not.

You must solve the problem without using the built-in queue data structure in your programming language. 
Input
["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 3, true, true, true, 4]
"""

class MyCircularQueue {
public:
    int maxSize;
    int size, i, j;
    vector<int> v;
    
    MyCircularQueue(int k) {
        size = 0;
        maxSize = k;
        v = vector<int> (k, 0);
        i=0;
        j=-1;
    }
    
    bool enQueue(int value) {
        if(size==maxSize)
            return false;
        if(++j == maxSize)
            j = 0;
        v[j] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(size==0)
            return false;
        if(++i == maxSize)
            i=0;
        size--;
        return true;
    }
    
    int Front() {
        return size==0? -1: v[i];
    }
    
    int Rear() {
        return size==0? -1: v[j];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==maxSize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */