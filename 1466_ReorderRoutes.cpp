"""
1466. Reorder Routes to Make All Paths Lead to the City Zero
There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.
"""
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        
        int minReroute = 0;
        // visited cities array
        vector<bool> visited(n,false);
        vector<vector<int>> adj(n), back(n);
        
        // for bfs
        queue<int> q;
        q.push(0);
        
        // Filling the adjacency lists
        for(auto con: connections)
        {
            adj[con[0]].push_back(con[1]);
            back[con[1]].push_back(con[0]);
        }
        
        // BFS
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            visited[curr] = true;
            
            // Change direction for all outwards facing arrows
            for(auto from: adj[curr])
            {
                // Increase count if they facing outwards and not visited
                if(!visited[from])
                {
                    minReroute++;
                    q.push(from);
                }
            }
            
            // Push other nodes to visit every city
            for(auto to : back[curr])
            {
                if(!visited[to])
                q.push(to);
            }
            
        }
        return minReroute;
            
    }
};