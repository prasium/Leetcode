"""
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

"""
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        
        vector<int> ans(n,0);
        stack<int> s;
   
        for(int i=0;i<n;i++)
        {
            // get current temperature
            int currTemp = temperatures[i];
            // while monotonic stack is not empty and current temp is warmer than top
            while(!s.empty() && temperatures[s.top()]<currTemp)
            {
                int preDay = s.top();
                s.pop();
                ans[preDay] = i-preDay;
            }
            s.push(i);
        }
        return ans;
    }
};