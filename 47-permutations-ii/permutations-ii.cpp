class Solution {
public:
    void solve(vector<int> &nums, int index, set<vector<int>> &st){
        if(index >= nums.size()){
            st.insert(nums);
            return;
        }

        for(int i = index; i<nums.size(); i++){
            swap(nums[i], nums[index]);
            solve(nums, index+1, st);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         set<vector<int>> ans;
         solve(nums, 0, ans);
         vector<vector<int>> ans1;
         for(auto i : ans){
            ans1.push_back(i);
         }
         return ans1;
    }
};