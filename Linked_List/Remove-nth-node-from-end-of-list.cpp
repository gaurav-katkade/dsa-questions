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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        if(head == NULL){
            return NULL;
        }
        ListNode* temp = head;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        cout<<len;
        temp = head;
        if(len == n){
            return head->next;
        }
        for(int i=1;i<len - n;i++){
            temp = temp->next;
        }
        if(temp->next != NULL){
            ListNode * temp2 = temp->next->next;
            temp->next = temp2;
        }else{
            temp->next = NULL;
        }
        return head;
    }
};
// Optimal
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i=1;i<=n;i++){
            fast = fast ->next;
        }
        if(fast == NULL){
            return slow->next;
        }
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};