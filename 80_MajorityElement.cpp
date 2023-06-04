class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> ump;
        for (int i = 0; i < nums.size(); i++)
        {
            ump[nums[i]]++;
        }
        int majority = 0, ans;
        for (auto a : ump)
        {
            if (a.second > majority)
            {
                ans = a.first;
            }
            majority = max(majority, a.second);
        }
        return ans;
    }
};