""
    "
    You are given two strings word1 and word2.Merge the strings by adding letters in alternating order,
    starting with word1.If a string is longer than the other, append the additional letters onto the end of the merged string.

                                                              Return the merged string.Input : word1 = abc,
                                                                                               word2 = pqr
                                                                                                   Output : apbqcr
                                                                                                                Explanation : The merged string will be merged as so : word1 : a b c
                                                                                                                                                                                   word2 : p q r
                                                                                                                                                                                               merged : a p b q c r
                                                                                                                                                                                                        ""
                                                                                                                                                                                                        "
                                                                                                                                                                                                        class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string res;
        int m = word1.length();
        int n = word2.length();
        int i = 0, j = 0, k = 0;
        while (i < m && j < n)
        {
            if (k % 2 == 0)
                res += word1[i++];
            else
                res += word2[j++];
            k++;
        }
        while (i < m)
        {
            res += word1[i++];
            k++;
        }
        while (j < n)
        {
            res += word2[j++];
            k++;
        }
        return res;
    }
};
// Another Solution
class Solution2
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int m = word1.length();
        int n = word2.length();
        int i = 0, j = 0;
        string result = "";
        while (i < m && j < n)
        {
            result += word1[i];
            i++;
            result += word2[j];
            j++;
        }
        while (i < m)
        {
            result += word1[i];
            i++;
        }
        while (j < n)
        {
            result += word2[j];
            j++;
        }
        return result;
    }
};