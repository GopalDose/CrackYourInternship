class Solution {
public:
    string reorganizeString(string s) {
        int ch[26] = {0};
        for(int i = 0; i<s.length(); i++){
            ch[s[i] - 'a']++;
        }

        int maxFreq = 0;
        char maxFrech;

        for(int i = 0; i <26; i++){
            if(maxFreq < ch[i]){
                maxFreq = ch[i];
                maxFrech = 'a' + i;
            }
        }
        int index = 0;
        while(maxFreq > 0 && index <s.length()){
            s[index] = maxFrech;
            index+=2;
            maxFreq--;
        }

        if(maxFreq != 0){
            return "";
        }
        ch[maxFrech-'a'] = 0;
        for(int i = 0; i <26; i++){
            while(ch[i] > 0){
                index = index>= s.length() ? 1 : index;
                s[index] = 'a' + i;
                ch[i]--;
                index+=2;
            }
        }

        return s;
    }
};