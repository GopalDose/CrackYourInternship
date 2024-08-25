class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroes = 0;
        int ones = 0;
        int twos = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeroes++;
            }
            if (nums[i] == 1) {
                ones++;
            }
            if (nums[i] == 2) {
                twos++;
            }
        }

        int i = 0;
        while (zeroes--) {
            nums[i] = 0;
            i++;
        }
        while (ones--) {
            nums[i] = 1;
            i++;
        }
        while (twos--) {
            nums[i] = 2;
            i++;
        }
    }
};