"""
841. Keys and Rooms
There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.

Example 1:

Input: rooms = [[1],[2],[3],[]]
Output: true
Explanation: 
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.

"""
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // Hash Table fo storing the rooms that have been visited
        unordered_set<int> visited;
        // Insert Room 0 as its the entry point
        visited.insert(0);
        // For DFS
        stack<int> s;
        s.push(0);
        while(!s.empty())
        {
            // get current room
            int currentRoom = s.top();
            s.pop();
            // Fetch keys in current room
            vector<int> keys = rooms[currentRoom];
            // Iterate over each key
            for(auto k : keys)
            {
                if(visited.find(k)==visited.end())
                {
                    visited.insert(k);
                    s.push(k);
                }
            }
        }
        // if all rooms are visited return true
        return visited.size()==rooms.size();
    }
};