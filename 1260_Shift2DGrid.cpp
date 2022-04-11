"""
Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

In one shift operation:

    Element at grid[i][j] moves to grid[i][j + 1].
    Element at grid[i][n - 1] moves to grid[i + 1][0].
    Element at grid[m - 1][n - 1] moves to grid[0][0].

Return the 2D grid after applying shift operation k times.

"""

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> res(m, vector<int> (n, 0));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int newCol = (j+k)%n;
                int countShift = (j+k)/n;
                int newRow = (i+countShift)%m;
                res[newRow][newCol] = grid[i][j];
            }
        }
        return res;
    }
};