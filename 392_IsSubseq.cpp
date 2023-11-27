"""
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
"""
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()==0)
            return true;
        if(t.length()<s.length())
            return false;
        int l1=0;
        for(int i=0; i<t.length();i++)
        {
            if(t[i]==s[l1])
                l1++;
        }
        return l1>=s.length();
    }
};