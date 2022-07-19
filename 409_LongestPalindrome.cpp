"""
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.
"""

class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        int count[128] = {0};
        for(int i=0; i<s.length(); i++)
        {
            count[s[i]]++;
        }
        for(int i=0; i<128; i++)
        {
            ans = ans + count[i]/2*2;
            if(ans%2==0 && count[i]%2==1)
                ans++;
        }
        return ans;
    }
};