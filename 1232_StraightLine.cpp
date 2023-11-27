"""
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
"""
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int n = coordinates.size();
        int yD = coordinates[1][1]-coordinates[0][1];
        int xD = coordinates[1][0]-coordinates[0][0];
        for(int i=2; i<n; i++)
        {
            int xi = coordinates[i][0]-coordinates[0][0];
            int yi = coordinates[i][1]-coordinates[0][1];
        if(xi*yD != yi*xD)
                return false;
        }
        return true;
    }
};