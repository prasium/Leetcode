"""
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

"""
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        // Queue for BFS
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                // if cell is 0 push it into queue, else mark it as not filled distance(-1)
                if(mat[i][j]==0)
                    q.push({i,j});
                else
                    mat[i][j]=-1;
            }
        }
        
        int level = 0;
        int dir[4][2] = {{0,1}, {0,-1},{1,0},{-1,0}};
        // BFS
        while(!q.empty())
        {
            level++;
            int size = q.size();
            while(size-->0)
            {
                pair<int,int> p = q.front();
                q.pop();
                // Explore all adjacent directions level wise
                for(auto d: dir)
                {
                    int r = p.first+d[0];
                    int c = p.second+d[1];
                 
                // Check boundary conditions and matrix visited state, (-1 not visited)
                if(r<0||r>=m||c<0||c>=n|| mat[r][c]!=-1)
                    continue;
                // Mark the distance as the current level of queue
                    mat[r][c] = level;
                // Push current cell in queue
                    q.push({r,c});
                }
            }
        }
        return mat;
    }
};