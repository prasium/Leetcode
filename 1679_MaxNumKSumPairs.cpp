"""
You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.

 

Example 1:

Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
"""
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        //Two Sum variation
        int count =0;
        // two ptrs
        // sort(nums.begin(), nums.end());
        // int i =0, j = nums.size()-1;
        // while(i<j)
        // {
        //     int sum = nums[i]+nums[j];
        //     if(sum==k)
        //     {
        //         i++;
        //         j--;
        //         count++;
        //     }
        //     else if(sum<k)
        //     {
        //         i++;
        //     }
        //     else{
        //         j--;
        //     }
        // }
        // using hashtable
        unordered_map<int,int> ump;
        for(auto num:nums)
        {
            if(ump[k-num])
            {
                ump[(k-num)]--;
                ump[num]--;
                count++;
            }
            ump[num]++;
        }
        return count++;
        
    }
};