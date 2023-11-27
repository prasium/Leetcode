"""
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

    KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
    int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.

Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]
"""

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int s;
    
    KthLargest(int k, vector<int>& nums) {
        s = k;
        for (int n : nums) 
            pq.push(n);
        
    }
    
    int add(int val) {
           pq.push(val);
        while (pq.size() > s) 
            pq.pop();
        return pq.top();
   }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */