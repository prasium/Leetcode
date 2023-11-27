"""
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
"""
// Approach 1
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Transpose the matrix
        for(int i=0;i<n;i++)
        {
            for(int j=i+1; j<n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Flip the matrix horizontally
        for(int i=0;i<n/2;i++)
        {
            for(int j=0; j<n; j++)
            {
                swap(matrix[j][i], matrix[j][n-i-1]);
            }
        }
    }
};

//Approach 2 Rotate Group of 4 cells
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.size();
        for (int i = 0; i < (n + 1) / 2; i ++) {
            for (int j = 0; j < n / 2; j++) {
                int temp = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
                matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 -i];
                matrix[j][n - 1 - i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
}