class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int start = 0;
        int end = arr.size() -1;
        int mid;

        while(end  - start >= k){
            if(x-arr[start] > arr[end]-x){
                start++;
            }
            else{
                end--;
            }
        }
        return vector<int>(arr.begin() + start, arr.begin() + start + k);
    }
};