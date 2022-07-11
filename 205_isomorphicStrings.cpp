"""
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
"""
class Solution {
public:
    bool helper(string s, string t)
    {
          unordered_map<char, char> ump;
        for(int i=0; i<s.length(); i++)
        {
            if(!ump.count(s[i]))
            {
            ump[s[i]]=t[i];
            }
            else if(ump[s[i]]!=t[i]){
                return false;
            }
        }
        return true;
        
    }
    bool isIsomorphic(string s, string t) {
      if(s.empty())
          return true;
         return helper(s, t) && helper(t, s);
    }
};