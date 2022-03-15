"""
191. Number of 1 Bits
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
"""

class Solution {
public:
    int hammingWeight(uint32_t n) {
        // variable to keep count of 1 bits
        int count = 0 ;
        while(n>0) // while input is positive
        {
            if(n&1==1) // if the Least significant bit is 1 increment count
                count++;
            n=n>>1; // shift 1 bit right in input
        }
        return count;
    }
};