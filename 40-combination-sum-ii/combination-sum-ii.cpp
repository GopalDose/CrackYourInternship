class Solution {
public:
    void solve(vector<int> &cand, int index, int target, set<vector<int>> &ans, vector<int> single){
        if(target == 0){
            ans.insert(single);
            return;
        }
        if(target < 0){
            return;
        }

        for(int i = index; i<cand.size(); i++){
            if(i > index && cand[i] == cand[index]) continue;
            single.push_back(cand[i]);
            solve(cand, i+1, target-cand[i], ans, single);
            single.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> ans;
        vector<int> single;
        solve(candidates, 0, target, ans, single);
        vector<vector<int>> ans1;
        for(auto i:ans){
            ans1.push_back(i);
        }
        return ans1;
    }
};