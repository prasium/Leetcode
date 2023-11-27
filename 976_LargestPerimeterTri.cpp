"""
976. Largest Perimeter Triangle
Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.

Example 1:
Input: nums = [2,1,2]
Output: 5
"""
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int perimeterMax = 0;
        int n = nums.size();
        // Sort array in descending order
        sort(nums.begin(),nums.end(), greater<int> ());
        // Start from the third element, check triple if it makes a valid triangle
        for(int i=2;i<n;i++)
        if(nums[i-2]<(nums[i-1]+nums[i]))
            return (nums[i]+nums[i-1]+nums[i-2]); // return sum
        return 0;
    }
};