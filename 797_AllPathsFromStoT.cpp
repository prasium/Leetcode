"""
797. All Paths From Source to Target
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

 Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
"""
//BFS Solution
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       vector<vector<int>> res;
        queue<vector<int>> q;
        // vector to store current path
        vector<int> path;
        // Destination node
        int dest = graph.size()-1;
        // Source Node
        path.push_back(0);
        q.push(path);
        // BFS
        while(!q.empty())
        {
            path = q.front();
            q.pop();
            int lastNode = path.back();
            if(dest == lastNode)
                res.push_back(path);
            vector<int> neighbours = graph[lastNode];
            for(auto ele : neighbours)
            {
                vector<int> v(path);
                v.push_back(ele);
                q.push(v);
            }
        }
        return res;
    }
};

//DFS
class Solution {
public:
    int dest;
    vector<vector<int>> res;
    vector<int> temp;
    void dfs(vector<vector<int>>& graph, int currNode = 0) {
	    // updating temp
        temp.push_back(currNode);
		// and either updating res with it if dest is reached
        if (currNode == dest) res.push_back(temp);
		// or callling dfs again recursively
        else for (int node: graph[currNode]) {
            dfs(graph, node);
        }
        // backtracking with tmp
		temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dest = graph.size() - 1;
        dfs(graph);
        return res;
    }
};