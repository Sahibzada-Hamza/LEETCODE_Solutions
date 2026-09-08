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
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        unordered_map<Node*,Node*> map;
        Node* newhead=new Node(head->val);
        Node* oldtemp=head->next;
        Node* newtemp=newhead;
        map[head]=newhead;
        while(oldtemp!=nullptr){
            Node* Copynode=new Node(oldtemp->val);
            map[oldtemp]=Copynode;
            newtemp->next=Copynode;
            oldtemp=oldtemp->next;
            newtemp=newtemp->next;
        }
        oldtemp=head;
        newtemp=newhead;
        while(oldtemp!=nullptr){
            newtemp->random=map[oldtemp->random];
            oldtemp=oldtemp->next;
            newtemp=newtemp->next;
        }
        return newhead;
    }
};