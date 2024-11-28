class Solution {
public:
    void solve(vector<int> &cand, int index, int target, vector<vector<int>> &ans, vector<int> single){
        if(target == 0){
            ans.push_back(single);
            return;
        }
        if(target < 0){
            return;
        }

        for(int i = index; i<cand.size(); i++){
            single.push_back(cand[i]);
            solve(cand, i, target-cand[i], ans, single);
            single.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> single;
        solve(candidates, 0, target, ans, single);
        return ans;
    }
};