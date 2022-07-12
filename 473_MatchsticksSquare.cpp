"""
You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Return true if you can make this square and false otherwise.

Example 1:

Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.

"""
class Solution {
public:
    // DFS
   bool helper(vector<int> &sL, vector<int> &mS, int ind, int target)
   {
       if (ind == mS.size())
            return sL[0] == sL[1] && sL[1] == sL[2] && sL[2] == sL[3];
       
        for (int i = 0; i < 4; i++) {
            if (sL[i] + mS[ind] > target) 
                continue;
            int j = i;
            while (--j >= 0) 
                if (sL[i] == sL[j]) 
                    break;
            if (j != -1) continue;
            sL[i] += mS[ind];
            if (helper(sL, mS, ind + 1, target))
                return true;
            sL[i] -= mS[ind];
        }
        return false;   
   }
    
    bool makesquare(vector<int>& matchsticks) {
          if (matchsticks.size() < 4)
              return false;
        int sum = 0;
        for (int val: matchsticks) {
            sum += val;
        }
        if (sum % 4 != 0) 
            return false;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());  
        vector<int> sidesLength(4, 0);
        return helper(sidesLength, matchsticks, 0, sum/4);
    }
};