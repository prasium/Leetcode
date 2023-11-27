"""
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
"""

class Solution {
public:
    void backtrack(vector<int> &candidates, int start, int target, vector<int> &temp, vector<vector<int>> &res)
    {
        if(target<0)
            return ;
        if(target==0)
        {
            res.push_back(temp);
            return ;
        }
        for(int i=start; i<candidates.size();i++)
        {
            if(i==start||candidates[i]!=candidates[i-1])
            {
                temp.push_back(candidates[i]);
                backtrack(candidates,i+1,target-candidates[i],temp,res);
                temp.erase(temp.end()-1);
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        backtrack(candidates, 0, target, temp, res);
        return res;
    }
};