"""
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

"""
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int p=0, q=0;
        for(int i=0; i<s.length();i++)
        {
            if(s[i]=='#')
            {
                p--;
              p = max(0,p);
            }else
            {
                s[p]=s[i];
                p++;
            }
        }
        for(int i=0; i<t.length();i++)
        {
            if(t[i]=='#')
            {
                q--;
             q = max(0,q);
            }else
            {
                t[q]=t[i];
                q++;
            }
        }
        if(p!=q)
            return false;
        
        for(int i=0;i<p;i++)
        {
            if(s[i]!=t[i])
                return false;
        }
        return true;
    }
};