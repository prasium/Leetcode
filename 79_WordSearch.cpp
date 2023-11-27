"""
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example 1:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

"""
class Solution {
    private:
    int m, n;
    public:
    bool dfs(vector<vector<char>> &board, string word, int x, int y)
    {
        if(!word.size())
            return true;
        
        if(x<0 || y<0 || x>=m || y>=n || board[x][y]!=word[0])
            return false;
        
       char c = board[x][y];
        board[x][y]='#'; // visited
        string sub = word.substr(1);
        //Recurse for remaining word
        bool res = dfs(board, sub, x+1, y)||
            dfs(board, sub, x, y+1)||
            dfs(board, sub, x-1, y)||
            dfs(board, sub, x, y-1);
        // unmark for back track
        board[x][y]=c;
        
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(dfs(board, word,i,j))
                    return true;
        return false;
    }
};