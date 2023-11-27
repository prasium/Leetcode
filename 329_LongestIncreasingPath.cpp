"""
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
"""
class Solution {
public:
    int dir [4][2] = {{0,1}, {0,-1},{1,0},{-1,0}};
    int m,n;
    vector<vector<int>> dp;
    int solve(vector<vector<int>> &mat, int i, int j)
    {
        if(dp[i][j])
            return dp[i][j];
        
        dp[i][j]=1;
        
        for(int k=0;k<4;k++)
        {
            int x = i+dir[k][0], y = j+dir[k][1];
            
            if(x<0 || x>=m || y<0 || y>=n || mat[x][y]<=mat[i][j])
                continue;
            dp[i][j] = max(dp[i][j], 1+solve(mat,x,y));
        }
        return dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
         m = matrix.size();
         n = matrix[0].size();
        int maxPath = 0;
        dp.resize(m, vector<int> (n));
        for(int i=0; i<m;i++)
        {
            for(int j=0;j<n; j++)
            {
                maxPath = max(maxPath, solve(matrix, i, j));
            }
        }
        return maxPath;
    }
};