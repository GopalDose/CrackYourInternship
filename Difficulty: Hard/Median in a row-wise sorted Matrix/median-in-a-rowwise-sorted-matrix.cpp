//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int lessEle(vector<vector<int>> mat, int mid){
        int ans = 0;
        for(int i = 0; i<mat.size();i++){
            ans += upper_bound(mat[i].begin(), mat[i].end(), mid)-mat[i].begin();
        }
        return ans;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int mini  = INT_MAX;
        int maxi = INT_MAX;
        
        for(int i = 0; i < mat.size(); i++){
            mini = min(mini, mat[i][0]);
            maxi = max(maxi, mat[i][mat[0].size()-1]);
        }
        
        int mid = 0;
        int res = (mat.size()*mat[0].size() +1)/2;
        while(mini<= maxi){
            mid = (mini+maxi)/2;
            int cnt = lessEle(mat, mid);
            if(res <= cnt){
                maxi = mid-1;
            }
            else{
                mini = mid+1;
            }
        }
        
        return mini;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends