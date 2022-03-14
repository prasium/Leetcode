"""
200. Number of Islands
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
"""

class Solution {
public:
    int dfs(vector<vector<char>> &grid, int i, int j)
    {
        if(i<0||i>=grid.size() || j<0||j>=grid[i].size() || grid[i][j]=='0')
            return 0;
        grid[i][j]='0'; // sink the island
        dfs(grid, i+1,j); // Move down
        dfs(grid, i, j+1); // Move right
        dfs(grid, i-1, j); // Move up
        dfs(grid, i, j-1); // Move left
        return 1; // return 1 after sinking all neigbouring 1s to 0s
        
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0)
            return 0;
        int countIslands = 0;
        for(int i=0;i < grid.size();i++)
        {
            for(int j=0; j<grid[i].size(); j++)
            {
                if(grid[i][j]=='1')
                {
                    countIslands += dfs(grid, i, j);
                }
            }
        }
        return countIslands;
    }
};