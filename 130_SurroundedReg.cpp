"""
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.
Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
"""
class Solution {
public:
    int dir[4][2]= {{0,1},{0,-1},{1,0},{-1,0}};
    
    void dfs(vector<vector<char>> &grid, int i, int j, int &m, int &n)
    {
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]!='O')
            return ;
        
        // Mark it with other char than O and X
        grid[i][j]='#';
        dfs(grid, i+1, j, m, n);
        dfs(grid, i, j+1, m, n);
        dfs(grid, i-1, j, m, n);
        dfs(grid, i, j-1, m, n);
        
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        
        for(int i=0; i<m; i++)
        {
            dfs(board,i,0, m, n);
            dfs(board,i,n-1, m, n);
        }
        
        for(int i=0; i<n; i++)
        {
            dfs(board,0, i, m, n);
            dfs(board,m-1,i, m, n);
        }
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j]=='O')
                board[i][j]='X';
                else if(board[i][j]=='#')
                board[i][j]='O';
            }
        }
    }
};