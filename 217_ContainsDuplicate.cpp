"""
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Input: nums = [1,2,3,1]
Output: true
"""

// Using Set
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++)
        {
            if(s.count(nums[i]))
            return true;
            s.insert(nums[i]);
        }
        return false;
    }
};

// Using Sort
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
            if(nums[i]==nums[i+1])
                return true;
        
        return false;
    }
};
