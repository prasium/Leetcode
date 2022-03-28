"""
Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.
"""

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // duplicate  string remove ffirst and last char and find original string in it
        return (s+s).substr(1, 2*s.length()-2).find(s)!=-1;
    }
};