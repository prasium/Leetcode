"""
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

"""
class Solution {
public:
   void generateSubs(int index,vector<int> nums, vector<int> curr, vector<vector<int>> &subs)
    {
        subs.push_back(curr);
        for(int i=index;i<nums.size();i++)
        {
            curr.push_back(nums[i]);
            generateSubs(i+1,nums,curr,subs);
            curr.erase(curr.end()-1);
        }
   }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> c;
        generateSubs(0,nums,c,subs);
        return subs;
 
    }
};