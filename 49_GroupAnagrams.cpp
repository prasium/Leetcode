"""
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
"""

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> ump;
        
        for(int i=0;i<strs.size();i++)
        {
            string word = strs[i];
            sort(word.begin(),word.end());
            
            if(ump.find(word)!=ump.end())
            {
                ump[word].push_back(strs[i]);
            }
            else{
                ump[word].push_back(strs[i]);
            }
        }
        vector<vector<string>> res;
        for(auto it=ump.begin();it!=ump.end();it++)
        {
            res.push_back(it->second);
        }
        return res;
    }
};