"""
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

"""
class Solution {
public:
    string expand(string str, int beg, int end)
    {
        while((beg>=0&&end<str.length()) && (str[beg]==str[end]))
        {
            beg--;
            end++;
        }
        return str.substr(beg+1,end-beg-1);
    }
    
    string longestPalindrome(string s) {
            if(s.empty() ||s.length()==1)
                return s;
        string longestPalin = "";
        for(int i=0;i<s.length();i++)
        {
            string temp = expand(s,i,i);
            if(temp.length()>longestPalin.length())
                longestPalin = temp;
            
             temp = expand(s,i,i+1);
            if(temp.length()>longestPalin.length())
                longestPalin = temp;
            
        }
        return longestPalin;
    }
    
    
};