"""
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.
Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
"""
class Solution {
public:
    vector<vector<int>> adjList;
    vector<vector<int>> bridges;
    int time;
       // keeps track of connected node with lowest discovery time
        vector<int> low;
        // keeps track of when a node is discovered
        vector<int> dis;
        // keeps track of node's parent
        vector<int> par;
        
    
    void dfs(int node)
    {
        // update discovery and low values for node thats not visited earlier, increase timer
        low[node] = dis[node] = time++;
        
        for(int i=0; i<adjList[node].size(); i++)
        {
            int child = adjList[node][i];
            // if node not visited before
            if(dis[child]==-1)
            {
                // parent of child node is current node
                par[child]=node;
                dfs(child);
                
                // during backtrack update low value of parent to check for back edge
                low[node] = min(low[node], low[child]);
                
                // if edge is a bridge and not a backedge from child to its parents or any of 
                // its ancestors, push it in bridges
                if(low[child]>dis[node])
                    bridges.push_back({node,child});
            }
            //check for single back edge
            else if(child!=par[node]){
                low[node] = min(low[node],dis[child]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
     
        time = 0;
        adjList.resize(n);
        low.resize(n,-1);
        dis.resize(n,-1);
        par.resize(n,-1);
        
        // Create adj list
        for(vector<int> conn : connections)
        {
            adjList[conn[0]].push_back(conn[1]);
            adjList[conn[1]].push_back(conn[0]);
        }
        // Bridge: An edge whose removal increase the non connected componnent in graph
        // Find number of bridges using tarjan's algo
        for(int i=0; i<n; i++)
        {
            if(dis[i]==-1)
                dfs(i);
        }
        
        return bridges;
    }
};