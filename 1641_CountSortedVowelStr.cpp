"""
Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

 

Example 1:

Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].
"""

class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1, vector<int>(5,1));
        for(int i=1; i<=n; i++)
        {
            int sum = 0;
            for(int j=4; j>=0; j--)
            {
            if(i==1 || j==4)
            {
                dp[i][j]= 1;         
            }
            else{
                dp[i][j] = dp[i][j+1] + dp[i-1][j];
            }
            }
          }
        int ans = 0;
        for(int i=0;i<5;i++)
            ans+=dp[n][i];
        return ans;
    }
};