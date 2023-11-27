"""
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
"""
// Using Custom sort Comp
class Solution {
public:
   static int squareDist(vector<int> &pt)
    {
        return ((pt[0] *pt[0])+ (pt[1]*pt[1]));
    }
    
   static bool comp(vector<int> &x, vector<int> &y)
    {
        return squareDist(x) < squareDist(y);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), comp);
        vector<vector<int>> res(points.begin(), points.begin()+k);
        return res;
    }
};

// Using Priority Queue
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> maxPQ;
        for (int i = 0 ; i < points.size(); i++) {
            pair<int, int> entry = {squaredDistance(points[i]), i};
            if (maxPQ.size() < k) {
                // Fill the max PQ up to k points
                maxPQ.push(entry);
            } else if (entry.first < maxPQ.top().first) {
                // If the max PQ is full and a closer point is found,
                // discard the farthest point and add this one
                maxPQ.pop();
                maxPQ.push(entry);
            }
        }
        
        // Return all points stored in the max PQ
        vector<vector<int>> answer;
        while (!maxPQ.empty()) {
            int entryIndex = maxPQ.top().second;
            maxPQ.pop();
            answer.push_back(points[entryIndex]);
        }
        return answer;
    }