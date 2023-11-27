"""
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

"""
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int j=n-1;
        for(int i=0;i<n/2;i++)
        {
            char temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            j--;
        }
        
    }
};