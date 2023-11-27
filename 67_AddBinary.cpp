"""
Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"

"""
class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.length(), n2 = b.length();
        string res = "";
        int i = n1-1, j= n2-1, carry = 0;
        while(i>=0 || j>=0 || carry)
        {
            if(i>=0 && a[i--]=='1')
                carry++;
            if(j>=0 && b[j--]=='1')
                carry++;
            res.insert(0, carry%2!=0? "1":"0");
            carry>>=1;
        }
         return res;
    }
};