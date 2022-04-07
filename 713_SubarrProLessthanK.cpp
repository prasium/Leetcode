"""
Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

 

Example 1:

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

"""
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)
            return 0;
        int prod = 1, ans = 0, i = 0;
        for(int j = 0; j<nums.size(); j++)
        {
            prod*=nums[j];
            while(prod>=k)
                prod/=nums[i++];
            ans += j-i+1;
        }
        return ans;
    }
};