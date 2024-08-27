class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int s = 0;
        int e = arr.size() - 1;

        int mid = s +(e-s)/2;
        while(s<e){
            if(arr[mid] < arr[mid+1]){
                s = mid+1;
            }
            else{
                e = mid;
            }
            mid = s +(e-s)/2;
        }
        return s;
    }
};