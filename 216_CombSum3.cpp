"""
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
"""
class Solution {
public:
    void helper(vector<vector<int>> &v, vector<int> temp, int target, int &k)
    {  
        if(temp.size()==k && target==0)
        {
           v.push_back(temp);
            return ;
        }
        if(temp.size()<k)
        {
            
        for(int i=temp.empty()?1: temp.back()+1 ; i<=9; i++)
        {
            if(target-i<0)
                break;
            temp.push_back(i);
            helper(v, temp, target-i, k);   
            temp.pop_back();
        }
        }
        return ; 
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(res, temp, n, k);
        return res;
    }
};