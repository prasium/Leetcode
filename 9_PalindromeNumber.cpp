class Solution {
public:
    bool isPalindrome(int x) {
       if(x<0)
        return false;
       
       if(x!=0 && x%10==0)
        return false;

        int reverse = 0;
        //reverse till half point of number
        while(x>reverse)
        {
            reverse = reverse*10 + x%10;
            x/=10;
        }        
        return reverse == x || reverse/10 ==x;
    }
};