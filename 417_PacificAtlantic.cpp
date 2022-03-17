"""
417. Pacific Atlantic Water Flow
https://leetcode.com/problems/pacific-atlantic-water-flow/
"""

class Solution {
public:
    
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1, 0}};
    void dfs(vector<vector<int>> &heights, int i, int j, int prev, vector<vector<bool>> &ocean)
    {
        //Boundary check
        if(i<0||i>=heights.size()||j<0||j>=heights[i].size())
            return;
        // If height is less than prev height than return
        if(heights[i][j]<prev || ocean[i][j]==true)
            return;
        
        ocean[i][j]=true;
        for(auto d: dir)
        {
         dfs(heights,i+d[0],j+d[1],heights[i][j],ocean);   
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        // Creating result matrix
        vector<vector<int>> res;
        
        if(heights.size()==0|| heights[0].size()==0)
            return res;
        
        // Creating boolean matrices for pacific and atlantic
        vector<vector<bool>> atlantic(m,vector<bool> (n,false));
        vector<vector<bool>> pacific(m,vector<bool> (n, false));
        // DFS Approach
        //     Fill Row
        for(int i=0;i<m;i++)
        {
            dfs(heights,i,0,INT_MIN,pacific);
            dfs(heights,i,n-1,INT_MIN,atlantic);
        }
 //       Fill Column 
        for(int i=0;i<n;i++)
        {
            dfs(heights,0,i,INT_MIN,pacific);
            dfs(heights,m-1,i,INT_MIN,atlantic);
        }
  
        // Result evaluation
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                // If both are true then we can add the indices to the result
                if(pacific[i][j] && atlantic[i][j])
                    res.push_back({i,j});
            }
        }
        
        // Return result
        return res;
    }
};