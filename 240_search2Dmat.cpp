"""
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.

"""
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i=0, j=n-1; i<m && j>=0;)
        {
            if(matrix[i][j]<target)
            {
             i++;   
            }else if(matrix[i][j]>target)
            {
                j--;
            }
            else{
            return true;
            }
        }
        return false;
    }
};