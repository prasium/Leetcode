"""
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
"""
class Solution {
public:
    bool isPalindrome(string s) {
        
        int i=0,n=s.size(),j=n-1;
        string trim="";
        bool f=false;
        for(int i=0;i<n;i++)
        {
            if((s[i]>=65&&s[i]<=90)||(s[i]>=97)&&(s[i]<=122)||(s[i]>=48)&&(s[i]<=57))
            {
                f=true;
                trim+=tolower(s[i]);
            }
       }
        if(!f)
            return true;
        i=0;
        n=trim.size(),j=n-1;
        while(i<=n/2)
        {
            if(trim[i++]!=trim[j--])
                return false;
        }
        return true;
    
    }
};