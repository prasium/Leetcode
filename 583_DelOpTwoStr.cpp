"""
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

"""
class Solution {
public:
int minDistance(string& word1, string& word2) {
    int m = word1.length(), n =word2.length();
    int dp [m+1][n+1];
    for(int i=0; i<=m ; i++){
        for(int j=0; j<=n; j++){
            if(i==0 ||j==0)
                dp[i][j]= i+j;
            else if(word1[i-1]==word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else 
                dp[i][j] = 1+ min(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}
};