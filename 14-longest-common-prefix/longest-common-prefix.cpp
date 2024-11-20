class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        while(true){
            char ch = 0;
            for(auto st : strs){
                if(i >= st.length()){
                    ch = 0;
                    break;
                }
                if(ch == 0){
                    ch = st[i];
                }
                if(st[i] != ch){
                    ch = 0;
                    break;
                }
            }
            if(ch == 0){
                break;
            }
            i++;
        }
        return strs[0].substr(0,i);
    }
};