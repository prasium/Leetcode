class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int totalKids = candies.size();
        vector<bool> kidsResult(totalKids, false);
        int maxCandies = 0;
        for (int i = 0; i < totalKids; i++)
        {
            maxCandies = max(maxCandies, candies[i]);
        }
        for (int i = 0; i < totalKids; i++)
        {
            kidsResult[i] = (candies[i] + extraCandies >= maxCandies) ? true : false;
        }
        return kidsResult;
    }
};