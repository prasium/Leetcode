"""
For an integer array nums, an inverse pair is a pair of integers [i, j] where 0 <= i < j < nums.length and nums[i] > nums[j].

Given two integers n and k, return the number of different arrays consist of numbers from 1 to n such that there are exactly k inverse pairs. Since the answer can be huge, return it modulo 109 + 7.

Example 1:

Input: n = 3, k = 0
Output: 1
Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pairs.

"""
class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[1001][1001] = {1};
    int kInversePairs(int n, int k) {
        if(dp[n][k])
            return dp[n][k];
        
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=k; j++){
                dp[i][j] = (dp[i-1][j] + (j>0? dp[i][j-1]:0))%MOD;
                if(j>=i)
                    dp[i][j] = (MOD+ dp[i][j]-dp[i-1][j-i])%MOD;
            }
        }
        return dp[n][k];
    }
};