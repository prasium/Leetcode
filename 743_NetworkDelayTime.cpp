"""
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.


Example 1:

Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

"""
class Solution {
public:
    // Creating adjacency list (weight, destination)
    vector<pair<int,int>> adj[101];
    
    // Dijkstra's algorithm
    void dijkstra(int &src, int &n, vector<int> &pathCost)
    {
        // MinHeap for keeping smallest weight node first
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});
        
        // Initialize Src vertext as 0 dist.
        pathCost[src] = 0;
        
        while(!pq.empty())
        {
            int currNode = pq.top().second;
            int currNodeWeight = pq.top().first;
            pq.pop();
            
            if(currNodeWeight<=pathCost[currNode])
            {
            // Traverse adjancent nodes
                for(pair<int,int> e: adj[currNode])
                {
                    int timeCost = e.first;
                    int neighbour = e.second;
                    
                    if(currNodeWeight+timeCost< pathCost[neighbour])
                    {
                        pathCost[neighbour] = currNodeWeight+timeCost;
                        pq.push({pathCost[neighbour], neighbour});
                    }
                }
            }
                
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans = INT_MIN;
        // making adjacency list
        for(vector<int> t: times)
        {
            int src = t[0], des = t[1], weight = t[2];
            adj[src].push_back({weight, des});
        }
        // vector to store path cost
        vector<int> pathCost(n+1, INT_MAX);      
        // calling dijkstra algo
        dijkstra(k, n, pathCost);
        
        // maximum time delay
        for(int i=1; i<=n; i++)
            ans = max(ans, pathCost[i]);
        
        // Unreachable node is present
        if(ans==INT_MAX)
            return -1;
        
        return ans;
    }
};