"""
Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

    For example, "ace" is a subsequence of "abcde".

 
"""
class Solution {
public:
    int checkSub(string &w, string &s)
    {
        int ptr1 = 1;
        int i = s.find(w[0]);
        if(i==-1)
            return 0;
        while(ptr1<w.length()){
            i = s.find(w[ptr1], i+1);
            if(i==-1)
                return 0;
            ptr1++;
        }
        return 1;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        for(string w : words)
        {
            if(checkSub(w, s))
                count++;
        }
        return count;
    }
};