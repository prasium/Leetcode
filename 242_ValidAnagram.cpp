"""
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true

"""
class Solution {
public:
    bool isAnagram(string s, string t) {
        int ch[256]={0};
        for(int i=0;i<s.size();i++)
        {
            ch[s[i]]++;
        }
        for(int i=0;i<t.size();i++)
        {
            ch[t[i]]--;
        }
        for(int i=0;i<256;i++)
        {
            if(ch[i]!=0)
                return false;
        }
        return true;
    }
};