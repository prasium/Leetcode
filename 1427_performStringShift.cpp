class Solution
{
public:
    string stringShift(string s, vector<vector<int>> &shift)
    {
        int offset = 0, length = s.length();
        if (length == 0)
            return s;
        for (int i = 0; i < shift.size(); i++)
        {
            int direction = shift[i][0];
            int amount = shift[i][1];
            offset += (direction == 0 ? -amount : amount);
        }
        offset = (offset % length + length) % length;
        if (offset == 0)
        {
            return s;
        }
        return s.substr(length - offset) + s.substr(0, length - offset);
    }
};