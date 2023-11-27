"""
Given a matrix and a target, return the number of non-empty submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.
"""
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n = matrix[0].size(), ans = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=1; j<n; j++)
                matrix[i][j] += matrix[i][j-1];
        }
        
        unordered_map<int, int> count;
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                count = {{0,1}};
                int curr = 0;
                for(int k=0; k<m; k++){
                    curr+= matrix[k][j]- (i>0? matrix[k][i-1]:0);
                    ans+= count.find(curr-target)!=count.end()?count[curr-target]:0;
                    count[curr]++;
                }
            }
        }
        return ans;
    }
};