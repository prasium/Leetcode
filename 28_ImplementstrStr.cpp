"""
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

 

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2

"""
class Solution {
public:
    int strStr(string haystack, string needle) {
       int n=haystack.size();
        int m=needle.size();
        for(int i=0;i<=n-m;i++)
        {
            int j=0;
            while(j<m && haystack[i+j]==needle[j])
            {
                j++;
            }
            if(j==m)
                return i;
        }
            return -1;
    }
};