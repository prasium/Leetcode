// Brute Force.
class Solution
{
public:
    bool isSubstr(string s1, string s2, int substrPrefixLength)
    {
        int m = s1.length(), n = s2.length();
        // If either of the string length is not completely divisible by divisor return false.
        if (m % substrPrefixLength > 0 && n % substrPrefixLength > 0)
        {
            return false;
        }
        string base = s1.substr(0, substrPrefixLength);
        // Quotient: how many times its divisble by base substr
        int n1 = m / substrPrefixLength, n2 = n / substrPrefixLength;
        string temp1 = "", temp2 = "";
        for (int i = 0; i < n1; i++)
        {
            temp1 += base;
        }
        for (int i = 0; i < n2; i++)
        {
            temp2 += base;
        }
        return temp1 == s1 && temp2 == s2;
    }
    string gcdOfStrings(string str1, string str2)
    {
        // Find smallest string of both the inputs str1 and str2
        string smallestStr = str1.length() < str2.length() ? str1 : str2;
        // For each iteration remove a character if function returns false, check till one char is left.
        for (int i = smallestStr.length(); i >= 1; i--)
        {
            if (isSubstr(str1, str2, i))
            {
                return str1.substr(0, i);
            }
        }
        return "";
    }
};
// Elegant Sol.
class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        // If order of str1 and str2 not equal then return empty string
        if (str1 + str2 != str2 + str1)
        {
            return "";
        }
        // Find GCD length return substring
        int gcdS1S2 = gcd(str1.length(), str2.length());
        return str1.substr(0, gcdS1S2);
    }
};