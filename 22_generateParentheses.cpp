"""
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

"""
class Solution {
public:
    vector<string> res;
    void helper(int &n, string temp, int left, int right)
    {
        if(left==n && right==n)
        {
            res.push_back(temp);
        }
        else{
            if(left<n)
          helper(n, temp+"(", left+1, right);      
            if(right<left)
            helper(n, temp+")", left, right+1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string temp;
        helper(n, temp, 0, 0);   
        return res;
    }
};