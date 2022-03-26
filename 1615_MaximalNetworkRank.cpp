"""
There is an infrastructure of n cities with some number of roads connecting these cities. Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.

The network rank of two different cities is defined as the total number of directly connected roads to either city. If a road is directly connected to both cities, it is only counted once.

The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.

Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.
Input: n = 4, roads = [[0,1],[0,3],[1,2],[1,3]]
Output: 4
Explanation: The network rank of cities 0 and 1 is 4 as there are 4 roads that are connected to either 0 or 1. The road between 0 and 1 is only counted once.
"""
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        // to store degree of each city node
        vector<int> nodes(n,0);
        // matrix to keep track of road connection bw two cities set to 1
        vector<vector<int>> grid (n, vector<int>(n,0));
        
        for(int i = 0; i<roads.size(); i++)
        {
            int from = roads[i][0];
            int to = roads[i][1];
            
            // Degree of each node
            nodes[from]++;      
            nodes[to]++;
            
            // Since roads are bidirectional set i,j and j,1 as 1
            grid[from][to]=1;
            grid[to][from]=1;
        }
        
        int ans = INT_MIN;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                // add degrees of i,j 
                int sum = nodes[i] + nodes[j];
                
                // if grid has value 1, they have direct road so subtract one 
                if(grid[i][j]==1)
                    sum-= 1;
                // maximal value
                ans = max(sum, ans);
            }
        }
        return ans;
    }
};