class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> p;
        for(int i = 0 ; i  < piles.size(); i++){
            p.push(piles[i]);
        }

        while(k--){
            int maxele = p.top();
            p.pop();
            maxele = maxele - floor(maxele/2);
            p.push(maxele);
        }
        int sum = 0;
        while(!p.empty()){
            int maxele = p.top();
            p.pop();
            sum += maxele;
        }
        return sum;
    }
};