/*

Using Two pointer approach

*/


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
        if(list1 == NULL){
            return list2;
        }else if(list2==NULL){
            return list1;
        }
        ListNode * temp = new ListNode(-200);
        ListNode * newHead = temp;
        ListNode * l = list1;
        ListNode * r = list2;
        while(l != NULL && r != NULL){
            if(l->val <= r->val){
                temp->next = l;
                temp = l;
                l = l->next;
            }else{
                temp->next = r;
                temp = r;
                r = r->next;
            }
        }
        while(l != NULL){
            temp->next = l;
            temp = l;
            l = l->next;
        }
        while(r != NULL){
            temp->next = r;
            temp = r;
            r = r->next;
        }
        return newHead->next;
    }
};

// Brute force

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
        ListNode* temp = list1;
        vector<int>arr;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        temp = list2;
        while(temp!= NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        sort(arr.begin(),arr.end());
        ListNode* dummyNode = new ListNode(-1);
        temp = dummyNode;
        for(auto it:arr){
           ListNode* mynode = new ListNode(it);
           temp->next = mynode;
           temp = temp->next;
        }
        return dummyNode->next;
    }
};