"""
You are given an integer array nums and an integer k.

For each index i where 0 <= i < nums.length, change nums[i] to be either nums[i] + k or nums[i] - k.

The score of nums is the difference between the maximum and minimum elements in nums.

Return the minimum score of nums after changing the values at each index.
Input: nums = [1], k = 0
Output: 0
Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0.
"""
class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        
        // Sort the nums vector
        sort(nums.begin(), nums.end());
        // Max Score that would be possible if we increase one and decrease one 
        // would lie between extreme elements
        ans = nums[n-1]-nums[0];
        int l = nums[0]+k, r = nums[n-1]-k;
        int maxScore = 0, minScore = 0 ;
        for(int i=0; i<n-1; i++)
        {
           maxScore = max(nums[i]+k, r);
           minScore = min(nums[i+1]-k, l);
           ans = min(ans, maxScore-minScore);
        }
     /*
     Cause there are two segments (A[0]+K, A[1]+K, ..., A[i]+K, A[i+1]-K, ..., A[n]-K), the first one is on the left of the current point (A[i] + K is the last element of the first segment), the second one is on the right of the current point (A[i + 1] - K is the first element of the second segment). For the first segment, the smallest element is left, the largest is A[i] + K; For the second segment, A[i + 1] - K is the smallest element, the largest is right. Thus, for each point, the largest element should be either A[i] + K or right, the smallest element should be either left or A[i + 1] - K.
     */
        return ans;
    }
};