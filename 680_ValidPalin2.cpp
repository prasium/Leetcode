"""
Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

Example 1:

Input: s = "aba"
Output: true

"""
class Solution {
public:
    bool checkPal(string s, int left, int right)
    {
        while(left<right)
        {
            if(s[left]!=s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int j = s.length()-1;
        int i = 0;
        int count = 0;
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return checkPal(s,i+1,j) || checkPal(s, i, j-1);
            }
            i++;
            j--;
        }
        
        return true;
    }
};