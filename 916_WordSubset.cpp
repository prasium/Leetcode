"""
You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including multiplicity.

    For example, "wrr" is a subset of "warrior" but is not a subset of "world".

A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order.
"""
class Solution {
public:
    vector<int> count(string s)
    {
        vector<int> arr(26);
        for(char c: s)
        {
            arr[c-'a']++;
        }
        return arr;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> bMax = count("");
        int i;
        for(string b: words2)
        {
            vector<int> bCount = count(b);
            for(i=0; i<26; i++)
                bMax[i] = max(bMax[i], bCount[i]);
        }
        
        vector<string> ans;
        for(string a: words1){
            vector<int> aCount = count(a);
            for(i=0; i<26; i++)
                if(aCount[i]<bMax[i])
                    break;
            if(i==26)
            ans.push_back(a);
        }
        return ans;
    }
};