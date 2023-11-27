"""
Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
"""

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int beg =0, end = 0, n = nums.size();
        int sum =0, len=INT_MAX;
        while(end<n)
        {
            sum+=nums[end];
            end++;
            while(sum>=target){
                len = min(len, end-beg);
                sum-=nums[beg];
                beg++;
            }
        }
        return len==INT_MAX? 0:len;
    }
};