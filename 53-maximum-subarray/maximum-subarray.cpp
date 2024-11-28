class Solution {
public:

    int solve(vector<int> &nums, int start, int end){
        if(start == end){
            return nums[start];
        }
        int LeftSum = INT_MIN, RightSum = INT_MIN;
        int mid = (start+end)/2;
        int maxLeft = solve(nums, start,mid);
        int maxRight = solve(nums, mid+1, end);

        int leftBorder = 0, RightBorder = 0;
        for(int i= mid; i >=start; i--){
            leftBorder += nums[i];
            if(LeftSum < leftBorder) LeftSum =leftBorder;
        }

        for(int i= mid+1; i <=end; i++){
            RightBorder += nums[i];
            if(RightSum < RightBorder) RightSum =RightBorder;
        }

        int cross = LeftSum + RightSum;
        return max(cross, max(maxLeft, maxRight));
    }
    int maxSubArray(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};