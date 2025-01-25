//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int lowerBound(vector<int> &arr){
        int s = 0;
        int e = arr.size()-1;
        int mid = 0;
        int ans = arr.size();
        while(s<=e){
            mid = (s+e)/2;
            if(arr[mid] >= 1){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        
        return ans;
    }
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        
        int count = 0;
        int index = -1;
        
        for(int i = 0; i<arr.size(); i++){
            int cnt = arr[i].size() - lowerBound(arr[i]);
            if(cnt > count){
                count = cnt;
                index = i;
            }
        }
        
        return index;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after the integer input
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        cout << obj.rowWithMax1s(mat);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends