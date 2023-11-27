"""
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
"""

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pArr(26, 0);
        vector<int> sArr(26,0);
        vector<int> ans;
        int sLen = s.length(), pLen = p.length();
        if(sLen<pLen)
            return {};
        
        for(int i=0; i<pLen; i++)
        {
            pArr[p[i]-'a']++;
            sArr[s[i]-'a']++;
        }
        // If starting first pLen char form anagram add em
        if(pArr==sArr)
            ans.push_back(0);
        // Sliding Window
        for(int i=pLen; i<sLen; i++)
        {
            sArr[s[i-pLen]-'a']--;
            sArr[s[i]-'a']++;
            
            if(pArr==sArr)
                ans.push_back(i-pLen+1);
        }
        return ans;
    }
};