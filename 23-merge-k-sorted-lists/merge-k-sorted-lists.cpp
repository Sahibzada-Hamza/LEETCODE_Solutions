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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        vector<int> vec;
        for(int i=0;i<n;i++){
            ListNode* temp=lists[i];
            while(temp!=NULL){
                vec.push_back(temp->val);
                temp=temp->next;
            }
        }
        if(vec.empty())return NULL;
        sort(vec.begin(),vec.end());
        ListNode* ans=new ListNode(vec[0]);
        ListNode* temp=ans;
        for(int i=1;i<vec.size();i++){
            ListNode* newnode=new ListNode(vec[i]);
            temp->next=newnode;
            temp=temp->next;

        }
        return ans;
        
    }
};