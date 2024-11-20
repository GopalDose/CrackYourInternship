class Solution {
public:
    bool isV(char ch) {
        if(ch >= 'A' && ch <= 'Z'){
            ch = ch - 'A' +'a';
        }
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int start = 0;
        int end = s.length() - 1;
        while (start < end) {
            if (isV(s[start]) && isV(s[end])) {
                swap(s[start], s[end]);
                start++;
                end--;
            } else if (!isV(s[start])) {
                start++;
            } else {
                end--;
            }
        }
        return s;
    }
};