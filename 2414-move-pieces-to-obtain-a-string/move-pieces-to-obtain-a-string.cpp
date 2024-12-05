class Solution {
public:
    bool canChange(string start, string target) {
        int size = start.length();
        int i = 0;
        int j = 0;

        while (i < size || j < size) {
            if (start[i] == '_' && target[j] == '_') {
                i++;
                j++;
            } else if (start[i] == '_')
                i++;
            else if (target[j] == '_')
                j++;
            else if (start[i] != target[j])
                return false;
            else if (start[i] == 'L' && i < j)
                return false;
            else if (start[i] == 'R' && i > j)
                return false;
            else {
                i++;
                j++;
            }
        }

        return true;
    }
};