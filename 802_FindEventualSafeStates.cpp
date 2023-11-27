"""
There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
"""
class Solution {
public:
     // Set for Cycle and Safe nodes
        unordered_set<int> cycleNodes;
        unordered_set<int> safeNodes;
       
    // dfs function
    bool dfs(vector<vector<int>> &g, int src, unordered_set<int> &vis)
    {
        // If node is safe return true
        if(safeNodes.find(src)!=safeNodes.end())
            return true;
        // If node is a part of cycle return false
        if(cycleNodes.find(src)!=cycleNodes.end())
            return false;

        // If curr node is visited already its a part of cycle
        if(vis.find(src)!=vis.end())
        {
            cycleNodes.insert(src);
                return false;
        }
        
        // Mark current node as visited
        vis.insert(src);
        
        // Traverse path from src to other nodes
        for(auto node : g[src])
        {
            // if child is in cycle parent must be in cycle as well
            if(!dfs(g, node, vis))
            {
               cycleNodes.insert(src);
                return false;
            }
        }
        
        // Terminal state node is safe
        safeNodes.insert(src);
        return true;
        
        
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // resultant vector
        vector<int> res;
        // set for visited nodes
        unordered_set<int> visited;
        
        for(int i=0; i<graph.size(); i++)
        {
            if(dfs(graph, i, visited))
                res.push_back(i);
        }
        return res;
    }
};