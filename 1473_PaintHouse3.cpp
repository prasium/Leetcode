"""
There is a row of m houses in a small city, each house must be painted with one of the n colors (labeled from 1 to n), some houses that have been painted last summer should not be painted again.

A neighborhood is a maximal group of continuous houses that are painted with the same color.

    For example: houses = [1,2,2,3,3,2,1,1] contains 5 neighborhoods [{1}, {2,2}, {3,3}, {2}, {1,1}].

Given an array houses, an m x n matrix cost and an integer target where:

    houses[i]: is the color of the house i, and 0 if the house is not painted yet.
    cost[i][j]: is the cost of paint the house i with the color j + 1.

Return the minimum cost of painting all the remaining houses in such a way that there are exactly target neighborhoods. If it is not possible, return -1.

 

Example 1:

Input: houses = [0,0,0,0,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
Output: 9
Explanation: Paint houses of this way [1,2,2,1,1]
This array contains target = 3 neighborhoods, [{1}, {2,2}, {1,1}].
Cost of paint all houses (1 + 1 + 1 + 1 + 5) = 9.

"""
class Solution {
public:
    int dp[101][21][101];
    int helper(int curr, int p, int t, vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target)
    {
        if(t>target)
        {
            return INT_MAX/2;
        }
        if(curr==m)
        {
            return (t==target)?0:INT_MAX/2;
        }
        if(dp[curr][p][t]!=-1)
            return dp[curr][p][t];
        else{
            int ans = INT_MAX/2;
            //not painted
            if(houses[curr]==0)
            {
                for(int i=0; i<n ;i++)
                {
                    ans = min(ans, cost[curr][i]+helper(curr+1,i+1,(p==i+1)?t:t+1, houses, cost, m, n, target));
                }
            }
            else{
                ans= min(ans, helper(curr+1,houses[curr], (houses[curr]==p)?t:t+1, houses, cost, m, n, target ));
            }
            return dp[curr][p][t] = ans;
        }
        
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int ans = helper(0, 0, 0, houses, cost, m, n, target);
        return ans==INT_MAX/2?-1: ans;
    }
};