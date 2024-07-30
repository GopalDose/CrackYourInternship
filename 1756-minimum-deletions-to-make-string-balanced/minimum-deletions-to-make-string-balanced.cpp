class Solution {
public:
    int minimumDeletions(string s) {
        int aCount = 0;
        for(auto &ch : s) aCount += (ch == 'a');
        int minDeletions = INT_MAX;
        int bCount = 0;
        for(auto &ch : s){
            aCount -= (ch == 'a');
            minDeletions = min(minDeletions, aCount + bCount);
            bCount += (ch == 'b');
        }
        return minDeletions;
    }    
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();