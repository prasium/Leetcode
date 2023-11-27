"""
1254. Number of Closed Islands
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
Return the number of closed islands.
Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).
"""
class Solution {
public:
    bool isClosed(vector<vector<int>> &grid, int i, int j, int &r, int &c)
    {
        // If elements is a water body || or visited then return true
        if(grid[i][j]==1|| grid[i][j]==-1)
            return true;
        
        // If its on the perimeter return false
        if(i==0 || i>=r-1 || j==0 || j>=c-1)
            return false;
        
        grid[i][j]=-1; // mark the current as visited
        
        bool left = isClosed(grid, i, j-1, r, c);
        bool up = isClosed(grid, i-1, j, r, c);
        bool down = isClosed(grid, i+1, j, r, c);
        bool right = isClosed(grid, i, j+1, r, c);
        
        return left&&up&&down&&right;
    }
    int closedIsland(vector<vector<int>>& grid) {
        
        int rows = grid.size(); 
        int col = grid[0].size(); 
        int count = 0; // keeps track of closed islands
        
        // Visit the matrix except the perimeter as they cant be closed islands
        for(int i=1;i<rows-1;i++)
        {
            for(int j=1;j<col-1;j++)
            {
                // If its a land && closed increase the count
                if(grid[i][j]==0 && isClosed(grid, i, j, rows, col))
                    count++;
            }
        }
        return count;
    }
};