class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> result;
    int n = words.size();
    int i = 0;

    while (i < n) {
        int lineLen = words[i].length();
        int last = i + 1;

        while (last < n && lineLen + words[last].length() + (last - i) <= maxWidth) {
            lineLen += words[last].length();
            last++;
        }

        string line = words[i];
        int spaces = maxWidth - lineLen;
        int gaps = last - i - 1;

        if (last == n || gaps == 0) {  
            for (int j = i + 1; j < last; j++) {
                line += " " + words[j];
            }
            line += string(maxWidth - line.length(), ' '); 
        } else {
            int spacePerGap = spaces / gaps;
            int extraSpaces = spaces % gaps;

            for (int j = i + 1; j < last; j++) {
                int extra = j - i <= extraSpaces ? 1 : 0;
                line += string(spacePerGap + extra, ' ') + words[j];
            }
        }
        result.push_back(line);
        i = last;
    }
    return result;
}
};