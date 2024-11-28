class Solution {
public:
    bool solve(vector<int> &count, vector<int> &qua, int index){
        if(index == qua.size()) return true;

        for(int i = 0; i <count.size(); i++){
            if(count[i] >= qua[index]){
                count[i] -= qua[index];
                if(solve(count, qua, index+1)){
                    return true;
                }
                count[i] += qua[index];
            }
        }
        return false;
    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> mp;
        for(auto i:nums)
            mp[i]++;
        vector<int> count;
        for(auto i:mp)
            count.push_back(i.second);
        sort(quantity.rbegin(), quantity.rend());
        return solve(count, quantity, 0);

    }
};