"""
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

    s = s1 + s2 + ... + sn
    t = t1 + t2 + ... + tm
    |n - m| <= 1
    The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...

Note: a + b is the concatenation of strings a and b.
"""
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m1 = s1.length(), m2 = s2.length(), m3 = s3.length();
        vector<vector<int>> dp(m1+1, vector<int> (m2+1,0));
        
        if(m3 != m1+m2){
            return false;
        }
        for(int i=m1;i>=0;i--){
            for(int j=m2;j>=0;j--){
                int k=i+j;
                if(i==m1&&j==m2){
                    dp[i][j]=1;
                }
                else if(s3[k]==s2[j]&&s3[k]==s1[i]){
                    dp[i][j]= dp[i+1][j]||dp[i][j+1];
                }
                else if(s1[i]==s3[k]){
                    dp[i][j]= dp[i+1][j];
                }
                else if(s3[k]==s2[j]){
                    dp[i][j]= dp[i][j+1];
                }
                else{
                    dp[i][j]= false;
                }  
            }
        }
        return dp[0][0];
    }
};