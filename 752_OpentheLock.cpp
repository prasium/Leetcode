"""
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

 

Example 1:

Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation: 
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".

"""

class Solution {
public:
    
    vector<string> neighbours(const string &curr)
    {
        vector<string> res;
        for(int i=0; i<4; i++)
        {
            for(int j = -1; j<=1; j+=2)
            {
                string combi = curr;
                combi[i] = (combi[i]-'0'+ j+10)%10 + '0';
                res.push_back(combi);
            }
        }
        return res;
    }
    
    int openLock(vector<string>& deadends, string target) {
        // Deadends dictionary
        unordered_set<string> dict(deadends.begin(), deadends.end());
        // If deadend is intial point then return -1
        if(dict.find("0000")!=dict.end())
            return -1;
        // Queue for BFS
        queue<string> q;
        q.push("0000"); // Initial combination
        
        int minTurns = 0;
        
        // BFS
        while(!q.empty())
        {
            int s = q.size();
            for(int i=0;i<s;i++)
            {
                string curr = q.front();
                q.pop();
               
                if(curr==target)
                    return minTurns;
                
                for(auto neigh : neighbours(curr))
                {
                    if(dict.count(neigh))
                        continue;
                    dict.insert(neigh); // Visited
                    q.push(neigh);
                }
            }
            minTurns++;
        }
        return -1;
    }
};