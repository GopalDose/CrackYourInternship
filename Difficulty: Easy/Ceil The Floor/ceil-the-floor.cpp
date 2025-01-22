//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User code template

class Solution {
  public:
  
    int lowB(int x, vector<int> &arr) {
        // code here
        int i =0;
        int j = arr.size()-1;
        int mid = 0;
        int ans = -1;
        while(i <= j){
            mid = (i+j)/2;
            if(arr[mid] <= x){
                ans = arr[mid];
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }
        
        return ans;
    }
    
    int upB(int x, vector<int> &arr) {
        // code here
        int i =0;
        int j = arr.size()-1;
        int mid = 0;
        int ans = -1;
        while(i <= j){
            mid = (i+j)/2;
            if(arr[mid] >= x){
                ans = arr[mid];
                j = mid-1;
            }
            else{
                i = mid +1;
            }
        }
        
        return ans;
    }
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        return {lowB(x, arr), upB(x, arr)};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n~\n";
    }
    return 0;
}
// } Driver Code Ends