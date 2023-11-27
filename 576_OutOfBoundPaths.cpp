"""
There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.
"""
class Solution {
public:
    int dp[51][51][52];
    const int MOD = 1e9+7;
    
    int helper(int &m, int &n, int N, int r, int c)
    {
        // Out of boundary
        if(r<0 || c<0 || r==m || c==n)
            return 1;
        // Out of moves
        if(N==0)
            return 0;
        int ans = 0;
        if(dp[r][c][N]!=-1)
            return dp[r][c][N];
        
        ans = (ans+ helper(m, n, N-1, r+1, c))%MOD;
        ans = (ans+ helper(m, n, N-1, r, c+1))%MOD;
        ans = (ans+ helper(m, n, N-1, r-1, c))%MOD;
        ans = (ans+ helper(m, n, N-1, r, c-1))%MOD;
        return dp[r][c][N] = ans;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return helper(m, n, maxMove, startRow, startColumn);
    }
};