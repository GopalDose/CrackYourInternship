class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        
        int step = 0;
        int factor = 2;
        
        while (n > 1) {
            step += n%factor == 0 ? factor : 0;
            n = n%factor == 0 ? n/factor : n;
            factor += n%factor == 0 ? 0 : 1;
        }
        
        return step;
    }
};