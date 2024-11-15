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
    void deleteNode(ListNode* node) {
        ListNode * nxt = node->next;
        ListNode* prev = node;
        // ListNode * prev_prev = NULL;
        while(nxt->next != NULL){
            prev->val = nxt->val;
            prev = nxt;
            nxt = nxt->next;
        }
        prev->val = nxt->val;
        prev->next = NULL;
        // prev_prev->next = NULL;
        // delete prev;
    }
};