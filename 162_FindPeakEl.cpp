"""
A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞.

You must write an algorithm that runs in O(log n) time.
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
"""
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int beg = 0, end = nums.size();
        if(end-1==beg)
            return 0;
        if(nums[0]>nums[1])
            return 0;
        if(nums[end-1]>nums[end-2])
            return end-1;
        beg =1 , end = end -2;
        while(beg<=end)
        {
            int mid = beg + (end-beg)/2;
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])
            {
                return mid;
            }else if(nums[mid]<nums[mid-1])
            {
                end = mid-1;
            }
            else if(nums[mid]<nums[mid+1]){
                beg = mid+1;
            }
        }
    
    return -1;
    }
};