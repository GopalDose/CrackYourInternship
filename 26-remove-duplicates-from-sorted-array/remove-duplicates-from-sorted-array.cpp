class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = 0;
        map<int, int> mp;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int i = 0;
        for(auto it:mp){
            nums[i] = it.first;
            i++;
            ans++;
        }
        return ans;
    }
};