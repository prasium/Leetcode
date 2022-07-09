"""
You are given a 0-indexed integer array nums and an integer k.

You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside the boundaries of the array. That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.

You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j] for each index j you visited in the array.

Return the maximum score you can get.
"""
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> dq; // Monotonic queue
        int curr = 0;
        
        for(int i= nums.size()-1; i>=0; i--)
        {
            // Get curr max element, the front index of queue store max element's index
            curr = nums[i] + (dq.empty()?0: nums[dq.front()]);
        
        
            // Remove all smaller results as they wont be used
            while(!dq.empty() && curr>nums[dq.back()])
                dq.pop_back();
            
            // Insert current index into monoqueue
            dq.push_back(i);
            
            //Erase all the indices in queue that are greater than or equal to i+1
            if(dq.front()>=i+k)
                dq.pop_front();
            
            nums[i]=curr; //use input array as aux array
            
        }
        return curr;
    }
};