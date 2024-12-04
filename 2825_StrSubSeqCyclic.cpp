class Solution
{
public:
    bool canMakeSubsequence(string str1, string str2)
    {
        int s1Ptr = 0, s2Ptr = 0;
        while (s1Ptr < str1.length() && s2Ptr < str2.length())
        {
            if (str1[s1Ptr] == str2[s2Ptr] || str1[s1Ptr] + 1 == str2[s2Ptr] || str1[s1Ptr] - 25 == str2[s2Ptr])
            {
                s2Ptr++;
            }
            s1Ptr++;
        }
        return s2Ptr == str2.length();
    }
};