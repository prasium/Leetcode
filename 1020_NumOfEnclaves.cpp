"""
1020. Number of Enclaves
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
"""
class Solution {
public:
    void dfs(int i, int j, int &r, int &c, vector<vector<int>> &grid)
    {
        // Boundary Conditions check
        if(i<0|| i>=r || j<0 || j>=c || grid[i][j]==0)
            return;
        // Sink the island
        grid[i][j] = 0;
        // Traverse in all four directions
        dfs(i+1, j, r, c, grid);
        dfs(i, j+1, r, c, grid);
        dfs(i-1, j, r, c, grid);
        dfs(i, j-1, r, c, grid);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        // Answer var to keep count of islands not on off grid
        int ans = 0;
        // Rows and columns of grid
        int r= grid.size();
        int c= grid[0].size() ;
        // Sink all the Islands on the boundary and their connections.
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if((i==0||j==0||i==r-1||j==c-1) && grid[i][j]==1)
                {
                   dfs(i, j, r, c, grid);
                }
            }
        }
        
        // Count all the remaining islands in the grid
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(grid[i][j]==1)
                {
                   ans++;
                }
            }
        }
        
        return ans;
    }
};