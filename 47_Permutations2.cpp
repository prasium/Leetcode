"""
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]

"""
class Solution {
public:
    // a set to avoid duplicate permutation
    unordered_set<string> us;
    void helper(vector<int> &nums, vector<vector<int>> &res, vector<int> temp, vector<bool> &seen)
    {
        // Insert when permutation found
        if(temp.size()==nums.size())
        {
            string s; 
            for(auto t:temp)
            {
                s+=to_string(t);
            }
            if(!us.count(s))
            res.push_back(temp);
            us.insert(s);
            return;
        }
        // Backtracking
        for(int i=0; i<nums.size();i++)
        {
            if(!seen[i])
            {
            temp.push_back(nums[i]);
            seen[i]=true;
            helper(nums, res, temp, seen);
            temp.pop_back();
            seen[i]=false;
        }
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> seen(nums.size());
        helper(nums, res, temp, seen);
        return res;
    }
};