"""
You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.

You are given two arrays redEdges and blueEdges where:

    redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
    blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.

Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.
Example 1:

Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
Output: [0,1,-1]

"""
class Solution {
public:
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        // answer vector
        vector<int> ans(n);
        
        // Adjacency lists
        vector<vector<int>> red(n);
        vector<vector<int>> blue(n);
        
        // Adj list of red
        for(int i=0;i<redEdges.size();i++)
        {
            red[redEdges[i][0]].push_back(redEdges[i][1]);
        }
        
        // Adj list of blue
        for(int i=0;i<blueEdges.size();i++)
        {
            blue[blueEdges[i][0]].push_back(blueEdges[i][1]);
        }
        
        // for bfs
        queue<pair<int,int>> q;
        
         //pair.first stores the min distance to reach node through blue color
        //pair.second stores the min dist to reach node through red color 
        vector<pair<int,int>> res(n, {INT_MAX,INT_MAX});
        //1 represents blue
        //-1 represents red
        res[0]={0,0};
        
        q.push({0,-1});
        q.push({0, 1});
        
        //currDist is the distance from node 0  to the nodes in the queue in Alternative edges
        int currDist = 0;
        while(!q.empty())
        {
            int s = q.size();
            // for each node check if shortes dist exists in alt way
            for(int i=0; i<s; i++)
            {
                pair<int,int> p = q.front();
                q.pop();
                
                // if incoming color is red add nodes of blue edge viz a viz
                if(p.second==1)
                {
                     //blue 
                    //check for red adjacency list
                    for(auto x:red[p.first])
                    {
                        if(res[x].second > currDist+1)
                        {
                            q.push({x,-1});
                            res[x].second=currDist+1;
                        }
                    }
                }
                else{
                      //red
                    //check for blue adj list
                    for(auto x:blue[p.first])
                    {
                        if(res[x].first > currDist+1)
                        {
                            q.push({x,1});
                            res[x].first=currDist+1;
                        }
                    }
                }
            }
            
                currDist++;
        }
        
        for(int i=0; i<n; i++)
        {
            int minm = min(res[i].first, res[i].second);
            ans[i]=(minm==INT_MAX)? -1: minm;
        }
        
        return ans;    
    }
};