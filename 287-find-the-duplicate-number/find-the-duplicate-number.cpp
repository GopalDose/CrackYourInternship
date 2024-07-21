class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++){
            int index = abs(nums[i]);
            if(nums[index] > 0){
                nums[index] *= -1;
            }
            else{
                return index;
            }
        }
        return -1;
    }
};