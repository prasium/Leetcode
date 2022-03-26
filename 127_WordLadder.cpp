"""
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

    Every adjacent pair of words differs by a single letter.
    Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
    sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is hit -> hot -> dot -> dog -> cog, which is 5 words long.
"""
// BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        // Creating a hash set
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        // If not present in wordlist return 0 
        if(dict.count(endWord)==0)
            return 0;
        
        // Initial answer
        int ladder = 1;
        // BFS
        queue<string> q;
        q.push(beginWord);
        while(!q.empty())
        {
            int s = q.size();
            for(int i=0; i<s; i++)
            {
                string curr = q.front();
                q.pop();
                
                // Iterate through characters of current string
                for(int j=0; j<curr.length(); j++)
                {
                    string word = curr;
                    // try all possible alphabet on that char and check in set
                    for(char c='a'; c<='z'; c++)
                    {      
                        // modify the char
                        word[j] = c;
                        // if its same continue
                        if(word==curr)
                            continue;
                        // if we reach end word return level + 1
                        if(word==endWord)
                            return ladder+1;
                        // if the word contains in dictionary push in queue continue BFS
                        if(dict.count(word))
                        {
                            q.push(word);
                            dict.erase(word);
                        }
                    }
                }
            }
            ladder++;
        }
        return 0;
    }
};