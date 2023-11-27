"""
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

    All the visited cells of the path are 0.
    All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).

The length of a clear path is the number of visited cells of this path.
Input: grid = [[0,1],[1,0]]
Output: 2
"""
class Solution {
public:
    // Possible directions we can take from the cell
    int dir [8][2] ={
        {0,1}, // right
        {0,-1}, //left
        {1,0}, // down
        {-1,0}, // up
        {1,1},// diagonal bottom right
        {1,-1}, // diagonal up right
        {-1,1}, // diag up left
        {-1,-1} // diag up right
        };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n =grid.size(); // nxn matrix
        // if (0,0) || (n-1,n-1) is not 0 then no clear path
        if(grid[0][0]==1||grid[n-1][n-1]==1)
            return -1;
        
        // Queue of vector, (x,y,step)
        queue<vector<int>> q;
        // Push Initial cell and mark it as visited 
        q.push({0,0,1});
        grid[0][0]=1;
        
        // BFS
        while(!q.empty())
        {
         int size=q.size();
            while(size>0)
            {
                // fetch front element of queue
                vector<int> cell = q.front();
                q.pop();
                // If we reach the destination return path length
                if(cell[0]==n-1&&cell[1]==n-1)
                    return cell[2];
                // Explore adjacent neighbours in 8 directions
                for(auto d: dir)
                {
                    int r = cell[0]+d[0];
                    int c = cell[1]+d[1];
                    
                    // Check visit state and boundary cond.
                    if(r>=0&&c>=0&&r<n&&c<n&&grid[r][c]==0){
                        // push current coordinate in queue
                        q.push({r,c,cell[2]+1});
                        // visited current cell
                        grid[r][c]=1;
                    }       
                }
                size--;
            }
        }
        return -1;
    }
};