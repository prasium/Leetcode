/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];

        int left = 0, right = nums.size()-1;
        int mid;

        if(nums[0]!=nums[1])
        return nums[0];

        if(nums[right]!=nums[right-1])
        return nums[right];
        
        while(left<=right)
        {
            mid = left+(right-left)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
            return nums[mid];
            if((nums[mid]==nums[mid+1] && mid%2==0) || (nums[mid]==nums[mid-1] && mid%2!=0))
            {
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return nums[left];
    }
};