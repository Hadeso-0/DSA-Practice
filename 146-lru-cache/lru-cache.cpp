class node{
    public:
    int data;
    int key;
    node* next;
    node* prev;
    node(int key, int data){
        this->key = key;
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};
class LRUCache {
    unordered_map<int, node*> mp;
    node* head;
    node* tail;
    int cap;
public:
    LRUCache(int capacity) {
        this->head = new node(-1, -1);
        this->tail = new node(-1, -1);
        head->next = tail;
        tail->prev = head;
        this->cap = capacity;
    }
    
    void addnode(node* p){
        p->next = head->next;
        head->next = p;
        p->next->prev = p;
        p->prev = head;
    }
    void deletenode(node* p){
        p->prev->next = p->next;
        p->next->prev = p->prev;
        p->prev = NULL;
        p->next = NULL;
    }
    void printlist(int key){
        node* t = head;
        cout<<key<<"-> ";
        while(t!= NULL) {
            cout<<t->data<<" ";
            t = t->next;
        }
        cout<<" ==== ";
        t = tail;
        while(t!= NULL) {
            cout<<t->data<<" ";
            t = t->prev;
        }
        cout<<endl;
    }
    int get(int key) {
        // printlist(key);
        if(mp.find(key) == mp.end()) // key not found
        {
            return -1;
        }
        else{
            node* p = mp[key];
            int val = p->data;
            mp.erase(key);
            deletenode(p);
            addnode(p);
            mp[key] = head->next;
            return val;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) // key already exist
        {
            // update
            node* p = mp[key];
            deletenode(p);
            mp.erase(key);
        }
        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */