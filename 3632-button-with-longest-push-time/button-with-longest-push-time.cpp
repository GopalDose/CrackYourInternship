class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int maxi = events[0][1]; 
        int ans = events[0][0]; 

        for (int i = 1; i < events.size(); i++) {
            int duration = events[i][1] - events[i-1][1]; 
            if (maxi < duration || (maxi == duration && events[i][0] < ans)) {
                ans = events[i][0];
                maxi = duration; 
            }
        }
        return ans;
    }
};
