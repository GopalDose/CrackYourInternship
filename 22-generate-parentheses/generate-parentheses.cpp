class Solution {
public:
    void solve(vector<string> &ans, int uopen, int uclose,int ropen, int rclose, string str){
        if(ropen == 0 && rclose == 0){
            ans.push_back(str);
            return;
        }
        if(ropen > 0){
            solve(ans, uopen+1, uclose, ropen-1, rclose,str+'(');
        }
        if(uopen > uclose){
            solve(ans, uopen, uclose+1, ropen, rclose-1 ,str+ ')');
        }
    }
    vector<string> generateParenthesis(int n) {
        int uopen = 0;
        int uclose = 0;
        int ropen = n;
        int rclose = n;
        vector<string> ans;
        solve(ans, uopen, uclose, ropen, rclose,"");
        return ans;
    }
};