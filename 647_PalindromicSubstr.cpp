"""
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

"""
class Solution {
public:
    int n, dp[1001][1001];
    int helper(string &s, int i, int j)
    {
        if(i>=j)
            return dp[i][j]=1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        dp[i][j] = s[i]==s[j]? helper(s, i+1, j-1) : 0;
        return dp[i][j];
    }
    int countSubstrings(string s) {
        n = s.length();
        memset(dp, -1, sizeof(dp));
        int ans = 0, i=0, j=n-1;
        for(int i=0; i<n;i++)
            for(int j=i; j<n; j++)
                ans+= helper(s, i, j);
        return ans;
    }
};