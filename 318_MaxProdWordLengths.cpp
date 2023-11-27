"""
Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.

 

Example 1:

Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn".

"""
class Solution {
public:
    bool commonCheck(bitset<26> &a, bitset<26> &b)
    {
        for(int i=0; i<26;i++)
            if(a[i]&&b[i])
                return true;
        
        return false;
    }
    int maxProduct(vector<string>& words) {
        int n =words.size(), res = 0;
        vector<bitset<26>> letters(n);
        for(int i =0; i<n; i++)
        {
            for(auto &c : words[i])
                letters[i][c-'a']=1;
           
            for(int j=0; j<i; j++)
            {
                if(!commonCheck(letters[i], letters[j]))
                    res = max(res, int(words[i].size()*words[j].size()));
            }
        }
        return res;
    }
};