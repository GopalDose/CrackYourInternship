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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* tempA = list1;
        ListNode* tempB = list2;
        ListNode* ans = new ListNode(0, NULL);
        ListNode* ans1 = ans;
        while (tempA && tempB) {
            if (tempA->val > tempB->val) {
                ListNode* con = new ListNode(tempB->val, NULL);
                ans->next = con;
                ans = ans->next;
                tempB = tempB->next;
            }
            else{
                ListNode* con = new ListNode(tempA->val, NULL);
                ans->next = con;
                ans = ans->next;
                tempA = tempA->next;
            }
        }

        while (tempA) {
            ListNode* con = new ListNode(tempA->val, NULL);
            ans->next = con;
            ans = ans->next;
            tempA = tempA->next;
        }

        while (tempB) {
            ListNode* con = new ListNode(tempB->val, NULL);
            ans->next = con;
            ans = ans->next;
            tempB = tempB->next;
        }

        return ans1->next;
    }
};