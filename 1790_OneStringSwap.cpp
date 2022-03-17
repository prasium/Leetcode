"""
You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.
"""
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
          if(s1==s2)
              return true;
        int hash[26] ={0};
        int diff = 0;
        for(int i=0;i<s1.length();i++)
        {
            hash[s1[i]-'a']++;
            hash[s2[i]-'a']--;
            if(s1[i]!=s2[i])
                diff++;
        }
        for(int i=0;i<26;i++)
        {
            if(hash[i]>0||diff>2)
                return false;
         }
            return true;
        
    }
};