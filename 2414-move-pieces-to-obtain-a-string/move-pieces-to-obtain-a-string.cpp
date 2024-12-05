class Solution {
public:
    bool canChange(string start, string target) {
        string snu = removeU(start);
        string tnu = removeU(target);
        
        if (snu != tnu) 
            return false;
        
        int n = start.length();
        int j = 0;
        
        for (int i = 0; i < n; i++) {
            if (start[i] == 'L') {
                while (j < n && target[j] != 'L') j++;
                if (j > i) return false;
                j++;
            }
            else if (start[i] == 'R') {
                while (j < n && target[j] != 'R') j++;
                if (j < i) return false;
                j++;
            }
        }
        
        return true;
    }
    
private:
    string removeU(const string& s) {
        string result;
        for (char c : s) {
            if (c != '_') result += c;
        }
        return result;
    }
};