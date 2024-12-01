class Solution {
public:
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
};