class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        int maxi = 0;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
            if(mp[nums[i]] >= (nums.size()/2) && mp[maxi] < mp[nums[i]]){
                maxi = nums[i];
            }
        }
        return maxi;
    }
};