class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> stck;
        while(head != nullptr){
            ans.push_back(head->val);
            while(!stck.empty() && head->val > ans[stck.top()]){
                ans[stck.top()] = head->val;
                stck.pop();
            }
           stck.push(ans.size() - 1);
           head = head->next;
        }
        while(!stck.empty()){
            ans[stck.top()] = 0;
            stck.pop();
        }
        return ans;
    }
};