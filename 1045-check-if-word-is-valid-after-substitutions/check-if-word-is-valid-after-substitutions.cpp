class Solution {
public:
    bool isValid(string s) {
        if (s[0] != 'a')
            return 0;
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a') {
                st.push('a');
            } else if ( s[i] == 'b') {
                if (!st.empty() && st.top() == 'a')
                    st.push('b');
                else
                    return false;
            } else if (s[i] == 'c' && !st.empty()) {
                if (!st.empty() && st.top() == 'b') {
                    st.pop();
                    if (!st.empty() && st.top() == 'a') {
                        st.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};