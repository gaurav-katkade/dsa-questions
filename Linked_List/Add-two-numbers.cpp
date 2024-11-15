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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        ListNode * temp1 = l1;
        ListNode * temp2 = l2;
        ListNode * newhead = new ListNode();
        ListNode * dummy = newhead; 
        int val = 0;
        int rem = 0;
        while(temp1 != NULL && temp2 != NULL){         
            val = temp1->val + temp2->val + rem;
            cout<<val<<" ";
            rem = val/10;

            newhead->next = new ListNode(val%10);
            newhead = newhead->next; 

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1 != NULL ){
            val = temp1->val + rem;

             newhead->next = new ListNode(val%10);
            newhead = newhead->next; 

            rem = val/10;
            temp1 = temp1->next;
        }
        while(temp2 != NULL){
            val = temp2->val + rem;

            newhead->next = new ListNode(val%10);
            newhead = newhead->next; 

            rem = val/10;
            temp2 = temp2->next;
        }
        if(rem > 0){
            newhead->next = new ListNode(rem%10);
            newhead = newhead->next; 
        }
        return dummy->next;
    }
};