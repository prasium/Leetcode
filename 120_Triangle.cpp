"""
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

"""
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       int n=triangle.size();
        int mem[n];
        int m= n-1;
        
        for(int i=0;i<triangle[m].size();i++)
            mem[i]=triangle[m][i];
        
        for (int i=triangle.size()-2; i>=0; i--)
            for(int j=0;j<triangle[i].size();j++)
                mem[j]= triangle[i][j]+min(mem[j],mem[j+1]);
        return mem[0];
    }
};