"""
Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.
Example 1:

Input: n = 12
Output: 21
"""
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i= s.length()-2;
        for(; i>=0; i--)  // from right to left find first smaller element from its right
        {
            if(s[i]<s[i+1])
                break;
        }
        
    // if it doesn't exist, return -1
        if(i<0)
            return -1;
          // find the number x' in the right side which is just greater than x
        for(int j=s.length()-1; j>i; j--)
        {
            if(s[j]>s[i])
            { 
                swap(s[i], s[j]);
                break;
            }
        }
        // reverse right side to make it in increasing order
        reverse(s.begin()+i+1, s.end());
        long res = stol(s);
        return res>INT_MAX? -1:res;
    }
};