"""
There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.
Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
"""
class Solution {
public:
    void dfs(int src, vector<bool> &vis, vector<vector<int>> &connections)
    {
        // Mark it as visited 
        vis[src] = true;
        // Explore connected networks
        for(auto it: connections[src])
        {
            if(!vis[it])
            dfs(it,vis,connections);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        // we need minimum n-1  edges to connect n computers
        if(n>m+1)
            return -1;
        // Create an adjacency list for connections of each computer
        vector<vector<int>> graph(n);
        // Fill the list
        for(auto c: connections)
        {
             graph[c[0]].push_back(c[1]);
             graph[c[1]].push_back(c[0]);
        }
        // Number of isolated computers stored in this variable
        int operations = 0;
        // visited array 
        vector<bool> visited(n ,false);
        for(int i=0; i<n;i++)
        {
            // if not visited, increase disjoint computer and explore its connections
                if(!visited[i])
                {
                    operations++;
                    dfs(i,visited,graph);
                }
        }
        // answer is n-1 edges required to make em comnected 
        return operations-1;
    }
};