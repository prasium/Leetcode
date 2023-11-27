"""
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]] 
"""
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n,vector<int> (n));
        int left = 0, right = n-1, top = 0, bottom = n-1;
        int sq = n*n, num = 1;
        while(num<=sq)
        {
            for(int i=left;i<=right && num<=sq;i++)
            {
                mat[top][i]=num;
                num++;
            }
            top++;
       
            for(int i=top;i<=bottom && num<=sq;i++)
            {
                mat[i][right]=num;
                num++;
            }
            right--;
            
            for(int i=right;i>=left && num<=sq ;i--)
            {
                mat[bottom][i]=num;
                num++;
            }
            bottom--;
          
            for(int i=bottom;i>=top && num<=sq; i--)
            {
                mat[i][left]=num;
                num++;
            }
            left++;
        }
        return mat;
    }
};