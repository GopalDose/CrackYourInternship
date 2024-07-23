class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> freq;
        for(auto it:nums){
            freq[it]++;
        }

        sort(nums.begin(), nums.end(), [&](int n1, int n2){
            if(freq[n1] != freq[n2]){
                return freq[n1] < freq[n2];
            }
            else{
                return n1 > n2;
            }
        });
        return nums;
    }
};