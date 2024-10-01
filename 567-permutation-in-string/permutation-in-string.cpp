class Solution {
public:
    bool comp(int* count1, int* count2) {
        for (int i = 0; i < 26; i++) {
            if (count1[i] != count2[i]) {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int count1[26] = {0};

        for (int i = 0; i < s1.length(); i++) {
            count1[s1[i] - 'a']++;
        }

        int i = 0;
        int win = s1.size();
        int count2[26] = {0};
        while (i < win && i <s2.length()) {
            count2[s2[i] - 'a']++;
            i++;
        }

        if (comp(count1, count2)) {
            return 1;
        }

        while (i < s2.length()) {
            count2[s2[i]-'a']++;
            count2[s2[i - win] - 'a']--;
            if (comp(count1, count2)) {
                return true;
            }
            
            i++;
        }

        return 0;
    }
};