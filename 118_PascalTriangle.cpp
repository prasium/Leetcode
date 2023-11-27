"""
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it
"""
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        for(int i=0; i<numRows; i++)
        {
         vector<int> temp;
        for(int j=0; j<=i; j++)
        {
            if(j==0||j==i)
                temp.push_back(1);
            else
                temp.push_back(pascal[i-1][j-1]+pascal[i-1][j]);
        }
            pascal.push_back(temp);
        }
        return pascal;
    }
};
