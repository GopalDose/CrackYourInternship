class Solution {
public:
    void solve(unordered_map<string, double>& mp, vector<vector<string>>& pairs,
               vector<double>& rates) {
        for (int tp = 0; tp < pairs.size(); tp++) {
            for (int i = 0; i < pairs.size(); i++) {
                mp[pairs[i][1]] =
                    max(mp[pairs[i][1]], mp[pairs[i][0]] * rates[i]);
                mp[pairs[i][0]] =
                    max(mp[pairs[i][0]], mp[pairs[i][1]] / rates[i]);
            }
        }
    }
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1,
                     vector<double>& rates1, vector<vector<string>>& pairs2,
                     vector<double>& rates2) {
        unordered_map<string, double> mp;
        mp[initialCurrency] = 1;
        solve(mp, pairs1, rates1);
        solve(mp, pairs2, rates2);
        return mp[initialCurrency];
    }
};