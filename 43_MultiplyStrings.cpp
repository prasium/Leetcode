"""
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"

"""
class Solution {
public:
    string multiply(string num1, string num2) {
     if(num1=="0" || num2=="0")
         return "0";
        
        int m = num1.length(), n = num2.length();
        vector<int> res(m+n, 0); // there would be m+n digits in result
        
        for(int i=m-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                res[i+j+1] += (num1[i]-'0') * (num2[j]-'0');
                res[i+j] += res[i+j+1]/10;
                res[i+j+1] = res[i+j+1]%10;
            }
        }
        string result = "";
        int i = 0;
        while(res[i]==0)
            i++;
        
        while(i<res.size())
            result += to_string(res[i++]);
        
        return result;
    }
};