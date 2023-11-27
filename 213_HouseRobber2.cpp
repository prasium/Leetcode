"""
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

"""
class Solution {
public:
    int rob(vector<int>& nums) {
        int h1,h2, n = nums.size();
        if(n==1)
            return nums[0];
        else if(n==2)
            return max(nums[0], nums[1]);
        int dp[n];
        // Ignoring the last element
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2;i<n-1;i++)
        {
            dp[i]= max(dp[i-2]+nums[i], dp[i-1]);
        }
        h1 = dp[n-2];
        //Ignoring the first element
        dp[1]= nums[1];
        dp[2]= max(nums[1],nums[2]);
        for(int i=3;i<n;i++)
        {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        h2 = dp[n-1];
        return max(h1,h2);
        
    }
};