"""
695. Max Area of Island
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.

Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
"""

class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &grid)
    {
        // Checking bounds
        if(i<0||i>=grid.size() || j<0|| j>=grid[i].size() || grid[i][j]==0)
            return 0;
        // initialize area to 1 since element is 1
        int countArea=1; 
        grid[i][j]=0; // sink the island by setting it to 0
        // explore neighbours add to area if they are also 1
        countArea += dfs(i+1, j, grid); // down
        countArea += dfs(i, j+1, grid); // right
        countArea += dfs(i-1, j, grid); // up
        countArea += dfs(i, j-1, grid); // left
        return countArea;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // var to store maxArea of Island
        int maxArea =0;
        // traversing the grid
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {   
                // If the current index has an island explore the neighbours
                if(grid[i][j]==1)
                {
                    maxArea = max(maxArea, dfs(i,j, grid));
                }
            }
        }
        return maxArea;
    }
};