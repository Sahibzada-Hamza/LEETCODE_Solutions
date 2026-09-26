class LRUCache {
private:
    class Node {
    public:
        Node* next;
        Node* prev;
        int key;
        int val;
        Node(int k, int v){
            key = k;
            val = v;
            next = prev = NULL;
        }
    };
    Node* head;
    Node* tail;
    void addNode(Node* newnode){
        Node* oldnext = head->next; // 3-4-5 4
        head->next = newnode;
        newnode->next = oldnext;
        newnode->prev = head;
        oldnext->prev = newnode;
    }
    void deleteNode(Node* oldNode){//3-4-5-6
        Node* next = oldNode->next;
        Node* prev = oldNode->prev;
        prev->next = next;
        next->prev = prev;
    }
    int limit;
    unordered_map<int,Node*> map;
public:
    LRUCache(int capacity) {
        limit = capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;    
    }
    
    int get(int key) {
        if(map.find(key)==map.end()){
            return -1;
        }
        Node* ansNode=map[key];
        int ans=ansNode->val;
        map.erase(key);
        deleteNode(ansNode);
        addNode(ansNode);
        map[key]=ansNode;
        return ans;    
    }
    
    void put(int key, int val) {
        // if node exists
        if(map.find(key)!=map.end()){
            Node* oldnode=map[key];
            map.erase(key);
            deleteNode(oldnode);
        }
        if(map.size()==limit){
            Node* lru=tail->prev;
            map.erase(lru->key);
            deleteNode(lru);
        }
        Node* newnode= new Node(key,val);
        addNode(newnode);
        map[key]=newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */