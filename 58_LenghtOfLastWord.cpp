"""
Given a string s consisting of some words separated by some number of spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

"""
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length(), i=n-1, j=0;
        for(i;i>=0&&s[i]==' ';i--);  // ignoring trailing spaces
        for(i;i>=0&&s[i]!=' ';i--,j++);
            return j;
    }
};