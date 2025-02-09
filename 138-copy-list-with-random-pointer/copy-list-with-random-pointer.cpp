/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* helper(Node* head, unordered_map<Node*, Node*> &mp){
        if(head == NULL) return 0;

        Node* newNode = new Node(head->val);
        mp[head] = newNode;
        newNode->next = helper(head->next, mp);
        if(head->random){
            newNode->random = mp[head->random];
        }
        return newNode;
    }

    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        return helper(head, mp);
    }
};