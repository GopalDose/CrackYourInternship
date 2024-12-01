/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while (tempA && tempB) {
            if (tempA == tempB) {
                return tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }
        if (!tempA && !tempB) {
            return 0;
        }
        int countA = 0;
        int countB = 0;
        if (tempA) {
            while (tempA) {
                countA++;
                tempA = tempA->next;
            }
            while(countA--){
                headA = headA->next;
            }
        } else {
            while (tempB) {
                countB++;
                tempB = tempB->next;
            }
            while(countB--){
                headB = headB->next;
            }
        }

        cout << countA << " " << countB;
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};