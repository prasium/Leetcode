"""
You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.
Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
"""
class Solution {
public:
    void dfs(vector<vector<int>> &g, int i, int j, int &m, int &n, vector<pair<int,int>> &v)
    {
       // Boundary conditions
        if(i<0||i>=m||j<0||j>=n||g[i][j]==0)
            return ;
        g[i][j]=0;
        v.push_back({i,j});
        // Explore 4 directions
        dfs(g,i-1,j,m,n, v);   // up
        dfs(g,i+1,j,m,n, v);   // down
        dfs(g,i,j-1,m,n, v);   // left
        dfs(g,i,j+1,m,n, v);   // right
        return; 
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
       
    // vector to store indices of island cells 1 and 2
    vector<pair<int,int>> i1;
    vector<pair<int,int>> i2;
    
        int ans = INT_MAX;
        int m = grid.size();
        int n = grid[0].size();
        int isle = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    isle++;
                    if(isle==1)
                       dfs(grid, i, j, m, n, i1);
                else if(isle==2)
                    dfs(grid, i, j, m, n, i2);
                }
            }
        }
            // Calculate smallest manhattan distance
        for(int i=0; i<i1.size();i++)
        {
            for(int j=0;j<i2.size();j++)
            {
                int dis = abs(i1[i].first-i2[j].first)+abs(i1[i].second - i2[j].second)-1;
                if(dis<ans)
                    ans = dis;
            }
        }
        
        return ans;
    }
};