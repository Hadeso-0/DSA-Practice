struct Node{
    int _key;
    int _val;
    int _cnt;
    public:
    Node* next;
    Node* prev;

    Node(int key, int val){
        this->_key = key;
        this->_val = val;
        this->_cnt = 1;
        next = NULL; prev = NULL;
    }
    int getKey(){
        return this->_key;
    }
    int getVal(){
        return this->_val;
    }
    int getCnt(){
        return this->_cnt;
    }
    void setVal(int val){
        this->_val = val;
    }
    void increaseCnt(){
        this->_cnt += 1;
    }

};
class List{
    public:
    Node* head;
    Node* tail;
    int length;
    List(){
        length = 0;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head; 
    }

    void push(Node* p){
        p->next = head->next;
        head->next = p;

        p->next->prev = p;
        p->prev = head;
        
        ++length;
    }

    void removeNode(Node* p){
        p->prev->next = p->next;
        p->next->prev = p->prev;
        
        p->next = NULL;
        p->prev = NULL;
    
        --length;
    }
};
class LFUCache {
    int capacity;
    unordered_map<int, List*> frq2List;
    unordered_map<int, Node*> key2Node;
    int min_frq;
    
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->min_frq = 0;
        frq2List.clear();
        key2Node.clear();
        frq2List[1] = new List();
    }

    void updateFreqList(Node* n){
        key2Node.erase(n->getKey());
        frq2List[n->getCnt()]->removeNode(n);
        
        if((n->getCnt() == min_frq) && (frq2List[min_frq]->length == 0)){
            ++min_frq;
        }

        n->increaseCnt();
        int newCnt = n->getCnt();
        if( frq2List.find(newCnt) == frq2List.end()){
            frq2List[newCnt] = new List();
        } 

        frq2List[newCnt]->push(n);
        key2Node[n->getKey()] = n;
        // cout<<"Updated"<<n->getKey()<<" to "<<n->getVal()<<endl;
    }
    
    int get(int key) {
        if(key2Node.find(key) == key2Node.end()){ 
            // cout<<-1<<endl;
            return -1;
        }

        Node* cur = key2Node[key];
        int ans = cur->getVal();
        updateFreqList(cur);
        // cout<<ans<<endl;
        return ans;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;

        if(key2Node.find(key) != key2Node.end()){
            // Updating the node
            Node* cur = key2Node[key];
            cur->setVal(value);
            updateFreqList(cur);
            return;
        }
        else{
            if(key2Node.size() == capacity){
                // Max Capacity Reached -> Delete the key with least freq

                // remove least recent element of frq2List[min_frq]
                Node* top = frq2List[min_frq]->tail->prev;
                int k = top->getKey();
                int v = top->getVal();
                key2Node.erase(k);
                frq2List[min_frq]->removeNode(top);
                // cout<<"removed "<<k<<","<<v<<endl;
        
                delete top;
            }
            
            // add the new key
            Node* cur = new Node(key, value);
            key2Node[key] = cur;
            min_frq = 1;
            frq2List[min_frq]->push(cur);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */