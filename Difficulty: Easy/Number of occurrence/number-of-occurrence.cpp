//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int lowerB(vector<int> arr, int x){
      int i = 0; int j = arr.size()-1;
      int mid = 0;
      while(i <= j){
          mid = (i+j)/2;
          if(arr[mid] < x){
              i = mid+1; 
          }
          else{
              j = mid-1;
          }
      }
      return j;
  }
  int upperB(vector<int> arr, int x){
      int i = 0; int j = arr.size()-1;
      int mid = 0;
      while(i <= j){
          mid = (i+j)/2;
          if(arr[mid] <= x){
              i = mid+1; 
          }
          else{
              j = mid-1;
          }
      }
      return j;
  }
  
    int countFreq(vector<int>& arr, int target) {
        // code here
        return (upperB(arr, target) - lowerB(arr, target));
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends