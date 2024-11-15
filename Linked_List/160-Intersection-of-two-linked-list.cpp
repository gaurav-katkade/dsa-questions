/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
  find the lenght 
  which one has greater len


*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * dummy1 = headA;
        ListNode * dummy2 = headB;
        int l1=0,l2=0;
        while(dummy1 != NULL){
            l1++;
            dummy1 = dummy1->next;
        }
        while(dummy2 != NULL){
            l2++;
            dummy2 = dummy2->next;
        }
        dummy1 = headA; dummy2 = headB;
        if(l1 > l2){
            while(l1 != l2){
                dummy1 = dummy1->next;
                l1--;
            }
        }
        if(l1 < l2){
            while(l1 != l2){
                dummy2 = dummy2->next;
                l2--;
            }
        }
        while(dummy1 != NULL && dummy2 != NULL){
            if(dummy1==dummy2){
                return dummy1;
            }
            dummy1 = dummy1->next;
            dummy2 = dummy2->next;
        }
        return NULL;
    }
};