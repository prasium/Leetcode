"""
Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

 

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

"""
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> s;
        int l = nums.size(), r=0;
        for(int i=0; i<nums.size();i++)
        {
            while(!s.empty() && nums[s.top()]>nums[i])
            {
                l = min(l, s.top());
                s.pop();
             }
            s.push(i);
        }
        while(!s.empty())
        s.pop();
        for(int i=nums.size()-1; i>=0; i--)
        {
            while(!s.empty() && nums[s.top()]<nums[i])
            {
                r = max(r, s.top());
                s.pop();
            }
            s.push(i);
        }
        return r-l>0? r-l+1: 0;
    }
};