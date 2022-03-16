"""
1905. Count Sub Islands
You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.
An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.
Return the number of islands in grid2 that are considered sub-islands.
Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.
"""
class Solution {
public:
    void dfs(vector<vector<int>> &g1, vector<vector<int>> &g2, int i, int j, int &m, int &n, bool &flag)
    {
        // Check boundaries and island presence in grid 2
        if(i<0 || i>=m || j<0 || j>=n || g2[i][j]==0)
            return;
        // Check for island presence in grid 1 and grid 2 if not in grid 1 then set flag false
        if(g1[i][j]!=1 && g2[i][j]==1)
        {
            flag=false;
            return;
        }
       // Sink the current island in both grids 
        g1[i][j] = 0;
        g2[i][j] = 0;
        
        // Traverse in 4 directions
        dfs(g1,g2,i-1,j,m, n, flag);
        dfs(g1,g2,i+1,j,m, n, flag);
        dfs(g1,g2,i,j-1,m, n, flag);
        dfs(g1,g2,i,j+1,m, n, flag);
        
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        int m = grid1.size();
        int n = grid1[0].size();
        for(int i=0; i<m; i++)
        {
         for(int j=0; j<n; j++)
         {
             // Set flag true on every index
             bool flag = true; 
             // If grid2 has an island traverse dfs
             if(grid2[i][j]==1)
             {
                dfs(grid1, grid2, i, j, m, n, flag);
                // If flag is true then increase sub island count
                 if(flag)
                 count++;
             }
         }
        }
        return count;
    }
};