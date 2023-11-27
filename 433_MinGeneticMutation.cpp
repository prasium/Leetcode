"""
A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string start to a gene string end where one mutation is defined as one single character changed in the gene string.

    For example, "AACCGGTT" --> "AACCGGTA" is one mutation.

There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

Given the two gene strings start and end and the gene bank bank, return the minimum number of mutations needed to mutate from start to end. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.

 

Example 1:

Input: start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1
"""
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        // For gene mutation
        char genes[4] = {'A','C', 'G', 'T'};
        
        // Hash Set for searchig the gene bank
        unordered_set<string> dict(bank.begin(),bank.end());
        
        if(dict.find(end)==dict.end()) 
            return -1;
        
        // Queue for BFS
        queue<string> q;
        q.push(start);
    
        // count of mutations
        int mutations = 0;
        
        // BFS
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0; i<n;i++)
            {
                string s = q.front();
                q.pop();
                
                if(s==end)
                    return mutations;
                // current done
                dict.erase(s);
                for(int j=0; j<8; j++)
                {
                    char c = s[j];
                    for(int k=0; k<4; k++)
                    {
                        s[j]=genes[k];
                        if(dict.find(s)!=dict.end())
                        {
                            q.push(s);
                        }
                    }
                    s[j]=c;
                }
            }
            mutations++;
        }
        return -1;
    }
};
