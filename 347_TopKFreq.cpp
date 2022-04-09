"""
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

"""
class Solution {
public:
    
    static bool comp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second>b.second;
        
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        map<int, int> mp;
        if(k>nums.size())
            return ans;
        for(int n : nums)
        {
            mp[n]++;
        }
        vector<pair<int, int>> vp;
        for(auto &i: mp)
            vp.push_back(i);
        
        sort(vp.begin(), vp.end(), comp);
        int i =0;
        for(auto it = vp.begin(); it!=vp.end(); it++)
        {    if(i==k)
                break;
         ans.push_back(it->first);
        i++;
        }
        return ans;
    }
};