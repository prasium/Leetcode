"""
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

"""
class Solution {
public:
   vector<vector<int> >dp;
int minDistance(string& word1, string& word2) {
	// dp[i][j] will denote minimum steps required to equalize word1[i:end] and word[2:j:end]
	dp.resize(size(word1) + 1, vector<int>(size(word2) + 1, 1000));
	return solve(word1, word2, 0, 0);
}
int solve(string &w1, string &w2, int i, int j) {
	if(i == size(w1) && j == size(w2)) return 0;
	if(i == size(w1) || j == size(w2)) return max(size(w1) - i, size(w2) - j);
	if(dp[i][j] != 1000) return dp[i][j];  // directly return stored answer if already computed before
	if(w1[i] == w2[j]) return solve(w1, w2, i + 1, j + 1);
	return dp[i][j] = 1 + min(solve(w1, w2, i + 1, j), solve(w1, w2, i, j + 1));

    }
};