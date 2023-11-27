"""
 Given an array, rotate the array to the right by k steps, where k is non-negative.
 Link : https://leetcode.com/problems/rotate-array/
 Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
"""

// Naive Approach, TC: O(n*k)
class Solution {
public:
    vector<int> rotRight(vector<int>& nums){
        int n = nums.size();
        int last = nums[n-1];
        for(int i=n-1;i>=1;i--)
        {
            nums[i]=nums[i-1];
        }
        nums[0] = last;
        return nums;
    }
    void rotate(vector<int>& nums, int k) {
      
        for(int i=1;i<=k;i++)
        {
            rotRight(nums);
        }
    }
};

// Other approach, TC: O(n), SC: O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      int n = nums.size();
        vector<int> res(n);
        for(int i=0;i<n;i++)
        {
            int targetInd = (i+k)%n;
            res[targetInd] = nums[i];
        }
        for(int i=0;i<n;i++)
            nums[i]=res[i];
        
    }
};  

// Space Efficient Approach
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       k = k%nums.size();
        reverse(nums.begin(),nums.begin()+nums.size()-k);
        reverse(nums.begin()+nums.size()-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};