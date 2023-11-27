"""
Given an m x n matrix, return all elements of the matrix in spiral order.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
"""
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int total = m*n;
        // vector of size (m*n) that will store resultant spiral order
        vector<int> res(total);
        // keeps count of elements 
        int c = 0;
        // vars for boundaries of top left right down
        int top = 0, bot = m-1, left = 0, right = n-1;
        // while all the elements are not traversed
        while(c<total)
        {
            // Moving left to right
            for(int i=left; i<=right && c<total; i++)
            {
                res[c++]=matrix[top][i];
            }
            // Now increase the top ptr we have traversed that row
            top++;
            
            // Moving top to bottom
             for(int i=top; i<=bot  && c<total; i++)
            {
                res[c++]=matrix[i][right];
            }
            // Covered right most column decrease it by 1
            right--;
            
            
            // Moving right to left
            for(int i=right; i>=left  && c<total; i--)
            {
                res[c++]=matrix[bot][i];
            }
            // Covered bottom most column decrease it by 1
            bot--;
             
            // Move bottom to top
            for(int i=bot; i>=top  && c<total; i--)
            {
                res[c++]=matrix[i][left];
            }
            // Covered left most column increase by 1
            left++;
        }
        return res;
    }
};