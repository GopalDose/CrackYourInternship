class Solution {
public:
    bool check(string s,int i,int j){
        while(i <= j){
            if(s[i] != s[j])
                return false;
            
            i++;
            j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int start = 0; 
        int last = s.length()-1;
        while(start <= last){
            if(s[start] != s[last])
                return check(s, start+1, last) || check(s, start, last-1);
            
            start++;
            last--;
        }
        return true;
    }
};