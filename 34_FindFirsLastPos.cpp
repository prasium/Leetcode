"""
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

"""
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        int left = 0, right = nums.size()-1;
        // First position
        while(left <= right)
        {
        int mid = left+ (right-left)/2;
        
            if(nums[mid]<target)
            {
                left = mid+1;
            }
            else if(nums[mid]>target){
                right = mid-1;
            }
            else
            {
                if(left==mid || nums[mid]!=nums[mid-1])
                {
                    res[0] = mid;
                    break;
                }
                else{
                    right = mid -1;
                    res[0] = mid-1;
                }
            }         
        }
        
        left = 0, right = nums.size()-1;
        // End position
            while(left <= right)
        {
        int mid = left+ (right-left)/2;
        
            if(nums[mid]<target)
            {
                left = mid+1;
            }
            else if(nums[mid]>target){
                right = mid-1;
            }
            else
            {
                if(right==mid || nums[mid]!=nums[mid+1])
                {
                    res[1] = mid;
                    break;
                }
                else{
                    left = mid+1;
                    res[1] = mid+1;
                }
            }         
        }
        return res;
    }
};