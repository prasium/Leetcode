"""
You are keeping score for a baseball game with strange rules. The game consists of several rounds, where the scores of past rounds may affect future rounds' scores.

At the beginning of the game, you start with an empty record. You are given a list of strings ops, where ops[i] is the ith operation you must apply to the record and is one of the following:

    An integer x - Record a new score of x.
    "+" - Record a new score that is the sum of the previous two scores. It is guaranteed there will always be two previous scores.
    "D" - Record a new score that is double the previous score. It is guaranteed there will always be a previous score.
    "C" - Invalidate the previous score, removing it from the record. It is guaranteed there will always be a previous score.

Return the sum of all the scores on the record.
Input: ops = ["5","2","C","D","+"]
Output: 30
"""
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int ans = 0;
        stack<int> stk;
        for(string i : ops)
        {
         if(i == "+")
            {
                int v1 = stk.top();
                stk.pop();
                int v2 = stk.top();
                stk.push(v1);
                stk.push(v1 + v2);
            }
            else if(i == "D")
            {
                stk.push(stk.top()*2);
            }
            else if(i == "C")
            {
             stk.pop();
            }
            else
            {
                stk.push(stoi(i)); 
            }
        }
        
        while(!stk.empty())
        {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};