class node{
    public:
    int data;
    int row;
    int col;

    node(int a, int b, int c){
        data = a;
        row = b;
        col = c;
    }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;

        priority_queue<node*, vector<node*>, compare> pq;
        for(int i = 0; i<nums.size(); i++){
            int ele = nums[i][0];
            mini = min(ele, mini);
            maxi = max(ele, maxi);
            pq.push(new node(ele, i, 0));
        }

        int ansStart = mini;
        int ansEnd = maxi;

        while(!pq.empty()){
            node* temp = pq.top();
            pq.pop();
            int data = temp->data;
            int row = temp->row;
            int col = temp->col;

            mini = data;

            if(maxi - mini < ansEnd - ansStart){
                ansStart = mini;
                ansEnd = maxi; 
            }

            if(col + 1 < nums[row].size()){
                maxi = max(maxi, nums[row][col+1]);
                node* newNode = new node(nums[row][col+1], row, col+1);
                pq.push(newNode);
            }
            else{
                break;
            }
        }
        vector<int> ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;

    }
};