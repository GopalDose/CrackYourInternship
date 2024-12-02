class Solution {
    vector<int> preSmallest(vector<int> h){
        vector<int> ans(h.size());
        stack<int> st;
        st.push(-1);
        for(int i = 0 ; i<h.size(); i++){
            int curr = h[i];
            while(st.top() != -1 && h[st.top()] >= curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> nextSmallest(vector<int> h){
        vector<int> ans(h.size());
        stack<int> st;
        st.push(-1);
        for(int i = h.size()-1 ; i>=0; i--){
            int curr = h[i];
             while(st.top() != -1 && h[st.top()] >= curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> n = nextSmallest(heights);
        vector<int> p = preSmallest(heights);
        int maxi = INT_MIN;

        for(int i = 0 ; i<heights.size(); i++){
           int len = heights[i];
           if(n[i] == -1) n[i] = heights.size();
           int width = n[i]-p[i]-1;
           int area = width * len;
           maxi = max(maxi, area);
        }
        return maxi;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>  ans;
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0; i<n; i++){
            vector<int> t;
            for(int j = 0; j<m; j++){
                t.push_back(matrix[i][j] - '0');
            }
            ans.push_back(t);
        }

        int area = largestRectangleArea(ans[0]);
        for(int i = 1; i<n; i++){
            for(int j = 0; j<m; j++){
                ans[i][j] = (ans[i][j]) ? (ans[i][j] + ans[i-1][j]) : 0;
            }
            area = max(area, largestRectangleArea(ans[i]));
        }
        return area;
    }
};