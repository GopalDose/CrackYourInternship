class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence); 
        string word;
        int position = 1; 
        
        while (ss >> word) {
            if (word.find(searchWord) == 0) { 
                return position;
            }
            position++;
        }
        
        return -1;  
    }
};
