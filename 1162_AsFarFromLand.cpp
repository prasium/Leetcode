"""
1162. As Far from Land as Possible
find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

Example 1:
Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.

"""
class Solution {
public:
    bool isValid(int x, int y, vector<vector<int>> &g, int m, int n)
    {
        // Checking boundaries and if its land 
        if(x<0 || x>=n || y<0|| y>=m || g[x][y]==1)
            return false;
        return true;    
    }
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
    
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0; j<n; j++)
            {
                // Push all the indices of land in queue
                if(grid[i][j]==1)
                    q.push({i,j});
            }
        }
        // if queue contains only 0s or only 1s then it will return -1
        if(q.empty()|| q.size()==m*n)
            return -1;
        
        // Initialize count as -1, because first count will be of queue size having all lands
        int count = -1;
        // BFS
        while(!q.empty())
        {
            int s = q.size();
            while(s--)
            {
                pair<int,int> p = q.front();
                q.pop();
                for(int i = 0;i<4;i++)
                {
                    int disX = dx[i]+p.first;
                    int disY = dy[i]+p.second;
                    if(isValid(disX, disY, grid, m, n))
                    {
                        // Convert water to land so its doesnt occur again
                        grid[disX][disY]=1;
                        q.push({disX, disY});
                    }
                }
            }
            count++;
        }
        return count;
    }
};