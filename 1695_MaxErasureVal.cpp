"""
You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

 

Example 1:

Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].

"""

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n =nums.size();
        long long presum[n+1], ans =0;
        presum[0]=0;
        for(int i =0; i<n; i++)
            presum[i+1]=presum[i]+nums[i];
        
        unordered_map<int, int> check;
        
        for(int i=0, j=0; i<n; i++)
        {
            j = max(j, check[nums[i]]);
            ans = max(ans, presum[i+1]-presum[j]);
            check[nums[i]]= i+1;
        }
    return ans;
    }
    
};