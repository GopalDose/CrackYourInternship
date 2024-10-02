class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<int> isP(n+1, true);

        for(int i = 2; i<n; i++){
            if(isP[i]){
                count++;
                for(int j = 2*i; j<n; j+=i){
                    isP[j] = false;
                }
            }
        }
        return count;
    }
};