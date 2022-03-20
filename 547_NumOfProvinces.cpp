"""
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
"""
class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &isConnected)
    {
        // mark the city as visited
        isConnected[i][j] = 0;
        // Recurse for the further connected cities 
        for(auto c = 0; c< isConnected.size(); c++)
        {
            if(isConnected[j][c]==1)
                dfs(j,c,isConnected);
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int numProvinces = 0;
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0; j<isConnected[0].size(); j++)
            {
                 // if city is connected do dfs traversal of connected cities
                if(isConnected[i][j]==1)
                {
                    // After dfs we will have only count of disjoint provinces.
                    numProvinces++;
                    dfs(i,j,isConnected);
                } 
            }
        }
        return numProvinces;
    }
};

