class Solution {
public:
    int maxScore(string s) {
        int ones = 0;
        for (auto i : s) {
            if (i == '1')
                ones++;
        }
        int ans = 0;
        int zero = 0;
        if (s[0] == '0') {
            zero = 1;
        }
        else{
            ones--;
        }
        ans = max(ans, ones + zero);
        for (int i = 1; i < s.length()-1; i++) {
            if (s[i] == '0')
                (++zero);
            else
                (--ones);
            ans = max(ans, ones + zero);
        }
        return ans;
    }
};