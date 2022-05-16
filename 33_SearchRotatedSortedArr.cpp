"""There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

"""
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int beg =0,end=nums.size()-1;
        int mid;
        while(beg<=end)
        {
            mid=beg+(end-beg)/2;
            if(nums[mid]==target)
                return mid;
            
            if(nums[beg]<=nums[mid]){
                if(nums[beg]<=target&&nums[mid]>target)
            {
                end = mid-1;
            }else{
                    beg=mid+1;
                }
            }
            else {
                if(target>nums[mid]&&target<=nums[end])
            {
                beg=mid+1;
            }else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};