class Solution {
public:
    void solve(vector<string> &ans, int open, int close, string str){
        if(open == 0 && close == 0){
            ans.push_back(str);
            return;
        }

        if(open > 0){
            solve(ans, open-1, close, str+'(');
        }
        if(open < close){
            solve(ans, open, close-1,str+ ')');
        }
    }
    vector<string> generateParenthesis(int n) {
        int open = n;
        int close = n;
        vector<string> ans;
        solve(ans, open, close, "");
        return ans;
    }
};