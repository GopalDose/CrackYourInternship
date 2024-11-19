class Solution {
public:
    bool isPalindrome(int x) {
        int num = x;
        int res = 0;

        while (num > 0) {
            if (res > INT_MAX / 10) {
                return false; 
            }

            res = res * 10 + num % 10;
            num /= 10;
        }

        return res == x;
    }
};