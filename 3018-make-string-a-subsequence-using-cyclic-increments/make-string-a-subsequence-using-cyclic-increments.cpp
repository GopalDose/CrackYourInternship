class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        if(str1.length() < str2.length()) return false;
        int j = 0;
        int len = str2.length();
        for(auto s: str1){
            if(j < len && (str2[j]-s + 26)%26 <= 1) j++;
        }
        return j == len;
    }
};