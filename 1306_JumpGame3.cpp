"""
Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

Notice that you can not jump outside of the array at any time.

Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 
"""
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();
        
        // Visited Array
        vector<bool> visited(n, false);
        
        // Create a queue that stores index-value pair
        queue<pair<int,int>> q;
        
        // Push initial start position
        q.push({start, arr[start]});
        
        // BFS
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            if(!visited[p.first])
            {
                // If we reach index with value 0 return true
                if(p.second==0)
                {
                    return true;
                }
                int rightInc = p.first+p.second;
                int leftInc = p.first-p.second;
                // Check boundaries of left Increment and right increment
                if(leftInc>=0)
                {
                    q.push({leftInc,arr[leftInc]});
                }
                if(rightInc<n)
                {
                    q.push({rightInc,arr[rightInc]});   
                }
                // Mark current index visited
                visited[p.first]=true;
            }
        }
        
        return false;
    }
};