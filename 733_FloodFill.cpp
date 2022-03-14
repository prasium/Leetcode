"""
733. Flood Fill
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

Return the modified image after performing the flood fill.
"""

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]==newColor)
            return image;
        fill(image,sr,sc,image[sr][sc],newColor);
        return image;
    }
    void fill(vector<vector<int>>& image, int i, int j, int color, int newColor)
    {
        if(i<0||i>=image.size() || j<0||j>=image[i].size() || image[i][j] != color)
            return ;
        
        //set Color
        image[i][j]=newColor;
        
        fill(image, i+1, j, color, newColor);
        fill(image, i-1, j, color, newColor);
        fill(image, i, j+1, color, newColor);
        fill(image, i, j-1, color, newColor);
    }
};