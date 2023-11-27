"""

"""
class Solution {
public:
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int m = maze.size();
    int n = maze[0].size();
    // Queue to store coordinates(x,y) and distance
        queue<vector<int>> q;
    
    // Insert entrance point in queue and mark it as visited/create a wall
        q.push({entrance[0],entrance[1],0});
        maze[entrance[0]][entrance[1]]= '+';
    //BFS 
        while(!q.empty())
        {
            vector<int> v = q.front();
            q.pop();
            
            // if cell is at border and is not the entrance return the distance
            if((v[0]==0||v[0]==m-1||v[1]==0||v[1]==n-1) && (maze[v[0]][v[1]]!='+'))
            {
                return v[2];
            }
            // Explore 4 directions
            for(auto d:dir)
            {
                int x = v[0]+d[0];
                int y = v[1]+d[1];
                if(x>=0 && x<m && y>=0 && y<n && maze[x][y]=='.')
                {
                    // Add coordinates and 1 to the current distance
                    q.push({x,y,v[2]+1});
                    maze[x][y]='*';
                }
            }
        }
        return -1;
    }
};