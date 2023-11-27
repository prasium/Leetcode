"""
A certain bug's home is on the x-axis at position x. Help them get there from position 0.

The bug jumps according to the following rules:

    It can jump exactly a positions forward (to the right).
    It can jump exactly b positions backward (to the left).
    It cannot jump backward twice in a row.
    It cannot jump to any forbidden positions.

The bug may jump forward beyond its home, but it cannot jump to positions numbered with negative integers.

Given an array of integers forbidden, where forbidden[i] means that the bug cannot jump to the position forbidden[i], and integers a, b, and x, return the minimum number of jumps needed for the bug to reach its home. If there is no possible sequence of jumps that lands the bug on position x, return -1
Input: forbidden = [14,4,18,1,15], a = 3, b = 15, x = 9
Output: 3
Explanation: 3 jumps forward (0 -> 3 -> 6 -> 9) will get the bug home.
"""
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        // Visited Set
        unordered_set<int> visited;
        
        for(int i=0; i<forbidden.size(); i++)
            visited.insert(forbidden[i]);
        
        // Queue for num pos and backward cond criteria
        queue<pair<int,int>> q;
        q.push({0,0});
        int minJumps = 0;
        
        // BFS
        while(!q.empty())
        {
            int s= q.size();
            for(int i=0; i<s ;i++)
            {
                pair<int,int> p = q.front();
                q.pop();
                int num = p.first;
                if(num==x)
                    return minJumps;
                
                if(visited.find(num)!=visited.end())
                    continue;
                
                visited.insert(num);
                // 1 indicate backward
                if(p.second == 0 && num-b>=0)
                    q.push({(num-b),1});
                // 0 indicate forward
                if(num<=2000+b)
                    q.push({(num+a),0});
            }
            minJumps++;
        }
        return -1;
    }
};