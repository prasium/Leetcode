"""
Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.

As the answer can be very large, return it modulo 10^9 + 7.
Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
Output: 20
Explanation: 
Enumerating by the values (arr[i], arr[j], arr[k]):
(1, 2, 5) occurs 8 times;
(1, 3, 4) occurs 8 times;
(2, 2, 4) occurs 2 times;
(2, 3, 3) occurs 2 times.
"""

class Solution {
public:
    
    int threeSumMulti(vector<int>& arr, int target) {
    unordered_map<int, int> ump; 
    int ans = 0, n = arr.size();
    const long long MOD = 1e9+7;
        for(int i=0; i<n; i++)
        {
            ans = (ans+ ump[target - arr[i]])%MOD;
            for(int j=0; j<i; j++)
            {
                ump[arr[i]+arr[j]]++;
            }
        }
        return ans;
    }
};