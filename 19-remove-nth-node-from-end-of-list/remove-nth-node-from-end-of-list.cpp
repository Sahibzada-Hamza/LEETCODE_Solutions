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
            return NULL;
        }
        if(head->next==NULL && n==1){
            delete head;
            return NULL;
        }
        ListNode* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
//         //tail=last Node
        int curr=1;
        ListNode* temp=head;//1
        while(curr<n){
            while(temp->next!=tail){
                temp=temp->next;//4
            }
            tail=temp;//4
            temp=head;
            curr++;
        }
//         //tail=remove able node
          
        ListNode* NodetoDelete=tail;
        ListNode* prev=head;
        if(NodetoDelete==head){
            ListNode* newhead=head->next;
            delete head;
            return newhead;
        }
        while(prev->next!=tail){
            prev=prev->next;
        }
//         //prev->temp->next
        prev->next=NodetoDelete->next;
        delete NodetoDelete;
        return head;    
     }
};
