"""

There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

    There are no self-edges (graph[u] does not contain u).
    There are no parallel edges (graph[u] does not contain duplicate values).
    If v is in graph[u], then u is in graph[v] (the graph is undirected).
    The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.

A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.
Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.
"""
// DFS
class Solution {
public:
    bool dfs(vector<vector<int>> &g, int node, int col, vector<bool> &vis, vector<int> &color)
    {
        // Mark current node as visited and set color
        vis[node]=true;
        color[node]=col;
        // Explore children
        for(auto child: g[node])
        {
            // if not visited and dfs returns false
            if(!vis[child] && !dfs(g, child, 1-col, vis, color))
                return false;
            // if color of adjacent child is same as color of current node return false
            if(color[node]==color[child])
                return false;
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, 0);
        vector<int> color(n, -1);
        for(int i=0; i<n; i++)
        {
            // If not visited and dfs returns false
            if(vis[i]==0 && dfs(graph, i, 1, vis, color)== false)
                return false;
        }
        
        return true;
    }
};