"""
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

"""
class Solution {
public:
int dictionaryContains(string word, vector<string> &dict)
{
    for(int i=0;i<dict.size();i++)
    {
        if(dict[i].compare(word)==0)
        return true;
    }
    return false;
}

    bool wordBreak(string s, vector<string>& wordDict) {
        // { Driver Code Starts
//Initial template for C++

    //code here
    int n = s.length();
    
    if(n==0)
    return true;
    
    bool wordBreak[n+1];
    // init with false
    memset(wordBreak,0,sizeof(wordBreak));

    for(int i=1;i<=n;i++)
    {
         // if wb[i] is false, then check if current prefix can make it true.
        if(wordBreak[i]==false&&dictionaryContains(s.substr(0,i),wordDict))
        wordBreak[i]=true;
        
        if(wordBreak[i])
        {
            if(i==n)
            return true;
            
            for(int j=i+1;j<=n;j++)
            {
                
                if(wordBreak[j]==false && dictionaryContains(s.substr(i,j-i),wordDict))
                wordBreak[j]=true;
                
                if(j==n && wordBreak[j]==true)
                return true;
            }
        }
    }
    return false;
    
}
    
};