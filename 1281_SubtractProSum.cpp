""" 1281. Subtract the Product and Sum of Digits of an Integer.
Given an integer number n, return the difference between the product of its digits and the sum of its digits. 
Example 1:

Input: n = 234
Output: 15 
Explanation: 
Product of digits = 2 * 3 * 4 = 24 
Sum of digits = 2 + 3 + 4 = 9 
Result = 24 - 9 = 15

"""

class Solution {
public:
    int subtractProductAndSum(int n) {
        // variables to store product and sum of digits
        int product = 1, sum = 0;
        // while input is greater than 0
        while(n>0)
        {
            //fetch current right most digit, add to sum and multiply with product
            int digit = n%10;
            product *= digit;
            sum += digit;
            // Divide the input by base 10 to omit right most digit, move to left digits
            n/=10;
        }
        // Return difference
        return (product-sum);
    }
};