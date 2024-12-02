class Solution {
public:
    string decodeString(string s) {
        stack<string> st;

        for(auto ch : s){
            string toRepeat = "";
            if(ch == ']'){
                while(!st.empty() && st.top() != "["){
                    toRepeat += st.top();
                    st.pop();
                }
                st.pop();
                string numberTimes = "";
                while(!st.empty() && isdigit(st.top()[0])){
                    numberTimes += st.top();
                    st.pop();
                }
                reverse(numberTimes.begin(), numberTimes.end());
                int n = stoi(numberTimes);

                string curr = "";
                while(n--){
                    curr += toRepeat;
                }
                st.push(curr);
            }else{
                string temp(1, ch);
                st.push(temp);
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};