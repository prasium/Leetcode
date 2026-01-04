class Solution
{
public:
    bool confusingNumber(int n)
    {
        int mainNum = n, revNum = 0;
        while (n != 0)
        {
            int digit = n % 10;
            if (digit == 2 || digit == 3 || digit == 4 || digit == 5 || digit == 7)
            {
                return false;
            }
            revNum *= 10;
            revNum += ((digit == 6 || digit == 9) ? (digit == 6 ? 9 : 6) : digit);
            n /= 10;
        }
        return revNum != mainNum;
    }
};