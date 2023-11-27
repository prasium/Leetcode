"""
We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.
Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4] and group2 [2,3].
"""

// Using BFS
class Solution {
public:
    // Bipartite graph have even length edge cycle.
    bool isPossible(vector<vector<int>> &adj, vector<int> &color, int node)
    {
        // Possible colors : [0,1]
        queue<int> q;
        q.push(node);
        color[node]=1; 
        // BFS
        while(!q.empty())
        {
                int cur = q.front();
                q.pop();
                for(auto neigh : adj[cur])
                {
                    // Odd cycle return false
                    if(color[neigh]==color[cur])
                        return false;
                    // If not colored insert into queue with alternate color
                    if(color[neigh]==-1)
                    {
                        color[neigh] = 1-color[cur];
                        q.push(neigh);
                    }
                }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
       
        // Adjacency list 
        vector<vector<int>> adj(n+1);
        // Filling the adj list
        for(int i=0; i<dislikes.size(); i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        // A color vector, init with -1
        vector<int> color (n+1, -1);
        for(int i=1; i<=n; i++)
        {
            // If not colored
            if(color[i]==-1)
            {
                // Call BFS else no need to call BFS
                if(!isPossible(adj, color, i))
                    return false;
            }
        }
        return true;
    }
};