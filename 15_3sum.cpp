"""
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

"""
class Solution {
public:
    unordered_map<int,int> ump;
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n<3)
            return res;
      
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++)
            ump[nums[i]]=i;
        
        for(int i=0; i<n-2; i++)
        {
            if(nums[i]>0){
                break;
            }
            for(int j=i+1; j<n-1; j++){
                int reqd = -1*(nums[i]+nums[j]);
                if(ump.count(reqd) && ump.find(reqd)->second>j){
                    res.push_back({nums[i], nums[j], reqd});
                }
                j=ump.find(nums[j])->second;
            }
            i = ump.find(nums[i])->second;
        }
        return res;
    }
};