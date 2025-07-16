class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        int oddCount = 0, evenCount = 0, alternatingCount = 0;
        int prevParity = -1;
        for (int num : nums)
        {
            if (num % 2 == 0)
            {
                evenCount++;
                if (prevParity == -1 || prevParity == 1)
                {
                    alternatingCount++;
                }
            }
            else
            {
                oddCount++;
                if (prevParity == -1 || prevParity == 0)
                {
                    alternatingCount++;
                }
            }
            prevParity = num % 2;
        }
        return max(alternatingCount, max(oddCount, evenCount));
    }
};