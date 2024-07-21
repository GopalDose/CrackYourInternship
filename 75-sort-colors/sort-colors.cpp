class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i =0, start = 0;
        int last = nums.size()-1;
        while(i <= last){
            if(nums[i] == 0){
                swap(nums[i], nums[start]);
                i++;
                start++;
            }
            else if(nums[i] == 1){
                i++;
            }
            else if(nums[i] == 2){
                swap(nums[i], nums[last]);
                last--;
            }
        } 
    }
};

