class node{
    public:
    int key;
    int value;
    node* next;
    node*prev;
    node(int key,int value){
        this->key = key;
        this->value = value;
        next = NULL;
        prev = NULL;
    }
};
class LRUCache {
public:
    node * head = new node(-1,-1);
    node * tail = new node(-1,-1);
    unordered_map<int,node*>umap;
    int size;
    LRUCache(int capacity) {
        head->next = tail;
        head->prev = NULL;
        tail->prev = head;
        tail->next = NULL;
        size = capacity;
    }
    void deletenode(node * temp){
        node*tempPrev = temp->prev;
        node*tempNext = temp->next;
        tempPrev->next = tempNext;
        tempNext->prev = tempPrev;
        delete(temp);

    }
    void addnode(node * temp){
        node * headNext = head->next;
        head->next = temp;
        temp->prev = head;
        temp->next = headNext;
        headNext->prev = temp;
    }
    int get(int key) {
        int val = -1;
        if(umap.find(key)==umap.end()){
            return -1;
        }else{
            node * temp =umap[key];
            val = temp->value;
            deletenode(temp);
            node * temp1 = new node(key,val);
            addnode(temp1);
            umap[key] = temp1;
        }
        return val;
    }
    
    void put(int key, int value) {
        if(umap.find(key)!=umap.end()){
            node* temp = umap[key];
            deletenode(temp);
        }else if(umap.size()==size){
            umap.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        node* temp = new node(key,value);
        addnode(temp);
        umap[key] = temp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */