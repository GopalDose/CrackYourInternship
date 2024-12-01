/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};
        ListNode* prev = head;
        if (!prev)
            return ans;
        ListNode* curr = head->next;
        if (!curr)
            return ans;
        ListNode* succ = head->next->next;
        if (!succ)
            return ans;

        int cp1 = -1;
        int cp2 = -1;
        int i = 0;
        int mini = INT_MAX;
        while (succ) {
            if ((prev->val > curr->val && curr->val < succ->val) ||
                (prev->val < curr->val && curr->val > succ->val)) {
                if (cp1 == -1) {
                    cp1 = i;
                } else {
                    mini = min(mini, i - cp2);
                }
                cp2 = i;
            }
            prev = prev->next;
            succ = succ->next;
            curr = curr->next;
            i++;
        }
        if (cp1 != -1 && cp2 != cp1) {
            ans[0] = mini;
            ans[1] = cp2 - cp1;
        }

        return ans;
    }
};