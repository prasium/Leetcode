"""
1523. Count Odd Numbers in an Interval Range
Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).
Example 1:

Input: low = 3, high = 7
Output: 3
Explanation: The odd numbers between 3 and 7 are [3,5,7].
"""
class Solution {
public:
    int countOdds(int low, int high) {
        // count of numbers / 2 on avg
        int count = ((high-low)+1)/2;
        if(low%2==0 && high%2==0)
        {
            return count;
        }
        else if(low%2!=0 && high%2!=0)
        {
            return count+1;
        }
        else{
            return count;
        }
    }
};