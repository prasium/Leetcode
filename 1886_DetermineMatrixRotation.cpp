"""
Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.
Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
"""

class Solution {
public:
    bool rotate(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        // Transpose 
        for(int i=0;i<mat.size();i++)
        {
            for(int j=i+1; j<mat.size();j++)
            {
                swap(mat[i][j], mat[j][i]);
            }
        }
        // Flip rows
        for(int i=0; i<mat.size(); i++)
        {
            reverse(mat[i].begin(), mat[i].end());
        }
        // check with target
        return mat==target;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
            if(mat==target) // compare 0 deg
                return true;
        int n =mat.size();
        // 90 degree
        bool onerot = rotate(mat,target);
        // 180 degree
        bool secrot = rotate(mat,target);
        // 270 degree
        bool thirdrot = rotate(mat,target);
        return onerot||secrot||thirdrot;
    }
};
