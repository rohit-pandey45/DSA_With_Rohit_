class LRUCache {
  private:
  
  public:
    class node {
        public:
            int key;
            int val;
            node* next = nullptr;
            node* prev = nullptr;
            node(int _key,int _val){
                key = _key;
                val = _val;
                next = prev = nullptr;
            }
    };
    node* head = new node(-1,-1);
    node* tail= new node(-1,-1);
    
    int capacity;
    unordered_map<int, node*> m;
    
    void addnode(node* newnode){
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    void deletenode(node* delnode){
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    public:
    LRUCache(int cap) {
        capacity = cap;
        head->next = tail;
        tail->prev = head;
    }
    

    int get(int key) {
        if(m.find(key) != m.end()){
            node* resnode = m[key];
            int res = resnode->val;
            m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            m[key] = head->next;
            return res;
        }
        return -1;
    }

        
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            node* existingnode = m[key];
            m.erase(key);
            deletenode(existingnode);
        }
        if(m.size() == capacity){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        m[key] = head->next;
    }
};