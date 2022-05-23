"""
You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.

 

Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.

"""
class Solution {
public:
    int dp[601][101][101]={};
    
    int find(vector<pair<int,int>> &p, int ind, int ones, int zeros)
    {
        int n = p.size();
        
        if(ind==n || (zeros==0 && ones==0))
            return 0;
        
        if(dp[ind][ones][zeros]!=-1)
            return dp[ind][ones][zeros];
        
        if(p[ind].first>ones || p[ind].second>zeros)
            return dp[ind][ones][zeros]= find(p, ind+1, ones, zeros);
        
        int include = 1+find(p, ind+1, ones-p[ind].first, zeros-p[ind].second);
        int exclude = find(p, ind+1, ones, zeros);
        
        return dp[ind][ones][zeros]=max(include, exclude);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
    
        vector<pair<int,int>> p; 
        memset(dp,-1, sizeof(dp));
        
        for(auto i : strs)
        {
            int one =0, zero=0;
            for(auto j : i)
                (j=='1')? one++ : zero++;
            
            p.push_back({one, zero});
        }
        int ans = find(p, 0, n, m);
        return ans;
    }
};