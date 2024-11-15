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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL||k==0)return head;
        int n = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            n++;
        }
        temp = head;;
        int p = n-(k%n);
        if(p==n)return head;
        for(int i=0;i<p-1;i++){
            temp = temp->next;
        }
        ListNode*newhead = temp->next;
        temp->next = NULL;
        temp = newhead;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = head;
        return newhead;
    }
};