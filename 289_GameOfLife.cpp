"""
The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

    Any live cell with fewer than two live neighbors dies as if caused by under-population.
    Any live cell with two or three live neighbors lives on to the next generation.
    Any live cell with more than three live neighbors dies, as if by over-population.
    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.
Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
"""
class Solution {
public:
  int liveNeighbours(vector<vector<int>>& curr, int i, int j, int m, int n) {
	int lives = 0;
	if(i>0) {
		//check the upper neighbour
		if(curr[i-1][j] == 1) lives++;
	}
	if(i<m-1) {
		//check the lower neighbour
		if(curr[i+1][j] == 1) lives++;
	}
	if(j>0) {
		//check the left neighbour
		if(curr[i][j-1] == 1) lives++;
	}
	if(j<n-1) {
		//check the right neighbour
		if(curr[i][j+1] == 1) lives++;
	}

	if(i>0 && j>0) {
		if(curr[i-1][j-1] == 1) lives++;
	}
	if(i>0 && j<n-1) {
		if(curr[i-1][j+1] == 1) lives++;
	}
	if(i<m-1 && j>0) {
		if(curr[i+1][j-1] == 1) lives++;
	}
	if(i<m-1 && j<n-1) {
		if(curr[i+1][j+1] == 1) lives++;
	}
	return lives;
}
void gameOfLife(vector<vector<int>>& board) {
	vector<vector<int>> curr = board;
	int m = board.size();
	int n = board[0].size();
	for(int i = 0; i<m; i++) {
		for(int j = 0; j<n; j++) {
			int ln = liveNeighbours(curr, i, j, m, n);
			if(board[i][j] == 0) {
				//currently dead
				//can become alive if has exactly three live neighbours
				if(ln == 3) {
					board[i][j] = 1;
				}
			}
			else if(board[i][j] == 1) {
				//<2 -> die
				//==2 || ==3 live
				//>3 ->die
				if(ln < 2 || ln > 3) {
					board[i][j] = 0;
				}
			}
		}
    }
    }
};