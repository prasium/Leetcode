"""
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
"""
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longestCons = 0;
        unordered_set<int> us;
        for(int num: nums)
        {
            us.insert(num);
        }
        
        for(auto it : us){
            if(!us.count(it-1)){
                int currNum = it;
                int currStreak = 1;
                while(us.count(currNum+1)){
                    currNum++;
                    currStreak++;
                }
                longestCons = max(longestCons, currStreak);
            }
        }
        return longestCons;
    }
};