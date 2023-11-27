"""
You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the array after sorting it.
"""
class Solution {
public:
   static bool compare(const int &a, const int &b)
    {
        int c1 = __builtin_popcount(a);
        int c2 =  __builtin_popcount(b);
        if(c1==c2)
            return a<b;
        return c1<c2;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(), compare);
            return arr;
    }
};