"""
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

 

Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"

"""
class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.length(), n2 = num2.length();
        int carry = 0;
        int i = n1-1, j = n2-1, sum=0;
        string res = "";
        while(i>=0 || j>=0)
        {
            if(i>=0&&j>=0)
                sum = num1[i--]-'0' + num2[j--]-'0' + carry;
            else if(i>=0)
                sum = num1[i--]-'0' + carry;
            else if(j>=0)
                sum = num2[j--]-'0' + carry;
            carry = sum/10==0?0:1;
            res.insert(0, to_string(sum%10));
        }
        if(carry)
            res.insert(0,"1");
        return res;
    }
};