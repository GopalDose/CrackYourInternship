class Solution {
public:
    int minimumPushes(string word) {
        vector<int> v(26,0);
        for(int i=0;i<word.size();i++)
        {
            v[word[i]-'a']++;
        }
        sort(v.rbegin(),v.rend());
        int mul=1,it=0,ans=0;
        for(int i=0;i<26;i++)
        {
            it++;
            if(it>8)
            {
                mul++;
                it=1;
            }
            ans+=(mul*(v[i]));
        }
        return ans;
    }
};