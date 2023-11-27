"""
You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.
Input: mat = [[1,2],[3,4]], r = 2, c = 4
Output: [[1,2],[3,4]]
"""
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if((r*c)!=(m*n))
            return mat;
        
        vector<vector<int>> res(r,vector<int> (c));
     
        int k = 0, l =0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                
                res[i][j] = mat[k][l];
                if(l==n-1)
                { 
                    k++;
                    l=0;
                }
                else{
                    l++;
                }
            }
        }
        return res;
            
    }
};