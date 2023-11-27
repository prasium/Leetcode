"""
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
"""
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return true;
        int ans = 0;
        for(int i=0; i<n && ans>=i; i++)
        {
            ans = max(nums[i]+i, ans);
        }
        return ans>=n-1;
    }
};