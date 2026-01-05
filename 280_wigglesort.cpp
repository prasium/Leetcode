class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        // Even indices will be smaller to their neighbour odd indices
        // Odd indices will be greater to their neighbout even indices
        for (int i = 1; i < nums.size(); i++)
        {
            if (i % 2 == 0 && nums[i - 1] < nums[i])
            {
                swap(nums[i - 1], nums[i]);
            }
            else if (i % 2 == 1 && nums[i - 1] > nums[i])
            {
                swap(nums[i - 1], nums[i]);
            }
        }
    }
};