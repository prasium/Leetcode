"""
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

    For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".

A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

 

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].

"""
class Solution {
public:
    static bool cmp(const string &s1, const string &s2){
        return s1.length()<s2.length();
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        unordered_map<string, int> ump;
        int res = 0;
        for(string word: words){
            for(int i=0; i<word.length(); i++)
            {
                string pred = word.substr(0,i) + word.substr(i+1);
                ump[word] = max(ump[word], ump.find(pred)==ump.end()?1: ump[pred]+1); 
            }
            res = max(res, ump[word]);
        }
        return res;
    }
};