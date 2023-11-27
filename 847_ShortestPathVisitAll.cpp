"""
847. Shortest Path Visiting All Nodes
You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.
"""

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        // total nodes
        int n = graph.size();
        
        // BFS queue of tuple <node, mask, cost> 
        queue<tuple<int, int, int>> q;
        
        // set to keep track of visited path
        set<pair<int,int>> vis;
        
        int all = (1<<n)-1; // if all nodes visited
        
        for(int i=0; i<n; i++)
        {
            int maskValue = (1<<i); // 2^i;
            
            tuple<int, int, int> t(i, maskValue, 1); // tuple for every node
            q.push(t);
            vis.insert({i,maskValue});
        }
        
        // BFS
        while(!q.empty())
        {
            tuple<int,int,int> curr = q.front();
            q.pop();
            
            // if mask value becomes all, we have visited all nodes so return cost-1
            if(get<1>(curr)==all)
                return get<2>(curr)-1;
            
            // Explore adjacent nodes
            for(auto neigh: graph[get<0>(curr)])
            {
                int bothVisitedMask = get<1>(curr); //current mask
                
                // MOving from one node to another, OR operation
                bothVisitedMask = bothVisitedMask | (1<<neigh);
                
                // make tuple of this path
                tuple<int,int,int> path(neigh, bothVisitedMask, get<2>(curr)+1);
                
                 
                // if this path is not explored i.e
                // if it is not present in our set then,
                if(vis.find({neigh, bothVisitedMask})==vis.end())
                {
                    q.push(path);
                    vis.insert({neigh, bothVisitedMask});
                }
            }
        }
        return -1;
    }
};