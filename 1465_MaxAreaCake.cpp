"""
You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:

    horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
    verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.

Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a large number, return this modulo 109 + 7.
"""
class Solution {
public:
  
int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        const long long MOD = 1000000007;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
    
        int hC = horizontalCuts.size();
        int vC = verticalCuts.size();
        
        // n cuts n+1, pieces
        vector<int> heights(hC+1,0);
        heights[0]= horizontalCuts[0];
        for(int i=1; i<hC; i++)
        {
            heights[i] = horizontalCuts[i]-horizontalCuts[i-1];
        }
        heights[hC] = h-horizontalCuts[hC-1];
        
        
        // n cuts n+1, pieces
        vector<int> widths(vC+1,0);
        widths[0]= verticalCuts[0];
        for(int i=1; i<vC; i++)
        {
            widths[i] = verticalCuts[i]-verticalCuts[i-1];
        }
        widths[vC] = w-verticalCuts[vC-1];
        
        long long heightMax = *max_element(heights.begin(), heights.end());
        long long widthMax = *max_element(widths.begin(), widths.end());
        return (int)(heightMax%MOD*widthMax%MOD);
    }
};
