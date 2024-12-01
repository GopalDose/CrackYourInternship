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
    int getlength(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        int len = getlength(head);
        if(len == 0) return 0;

        int rotateA = (k%len);
        if(rotateA == 0) return head;
        int newHeadp = len-rotateA-1;
        ListNode* temp = head;
        for(int i = 0; i < newHeadp; i++){
            temp = temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next = 0;

        ListNode* it = newHead;
        while(it->next){
            it = it->next;
        }
        it->next = head;
        return newHead;
    }
};