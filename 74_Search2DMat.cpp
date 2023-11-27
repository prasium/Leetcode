"""
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
"""
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n =matrix[0].size();
        
        int left = 0, right = m-1;
        
        // Find row index
        int i=0;
        
        while(left <= right)
        {
            int mid = left+ (right-left)/2;
            if(matrix[mid][0]==target)
            {
                return true;
            }
            else if(matrix[mid][0]<target){
                i = mid;
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }         
        }
        
        left = 0, right = n-1;
        // Find col index
            while(left <= right)
        {
        int mid = left+ (right-left)/2;
            if(matrix[i][mid]==target)
            {
                return true;
            }
            else if(matrix[i][mid]<target){
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }         
        }
        return false;
    }
};