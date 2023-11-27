"""
Given an array of positive integers arr, calculate the sum of all possible odd-length subarrays.

A subarray is a contiguous subsequence of the array.

Return the sum of all odd-length subarrays of arr.
Input: arr = [1,2]
Output: 3
Explanation: There are only 2 subarrays of odd length, [1] and [2]. Their sum is 3.
"""
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0, n = arr.size();
        for(int i=0;i<n;i++)
        {
            // Occurence of each position
            int k = (i+1)*(n-i);
            // Odd length subarrays
            sum += ((k+1)/2 * arr[i]);
        }
        return sum;
    }
};