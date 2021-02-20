class LRUCache {
public:
    struct Node{
        int key, val;
        Node *left, *right;
        Node(int _key, int _val):key(_key), val(_val),left(nullptr),right(nullptr){}
    }*L, *R;

    int n;
    unordered_map<int, Node*> hash;
 
    LRUCache(int capacity) {
        n = capacity;
        L = new Node(-1, -1);
        R = new Node(-1, -1);
        L -> right = R;
        R -> left = L;
    }

    void insert(Node *p){
        p->right = L->right;
        p->left = L;
        L->right->left = p;
        L->right = p;
        /*p -> right = L -> right;
        L -> right -> left = p;
        L -> right = p;
        p -> left = L;*/
    }
    void remove(Node *p){
        p -> right -> left = p -> left;
        p -> left -> right = p -> right;
    }


    int get(int key) {
        if(hash.count(key) == 0) return -1;
        Node *p = hash[key];
        remove(p);
        insert(p);
        return p -> val;
    }
    
    void put(int key, int value) {
        if(hash.find(key) != hash.end()){
            Node *p = hash[key];
            p -> val = value;
            remove(p);
            insert(p);
        }
        else{
            Node *p = new Node(key, value);
            if(n == hash.size()){
                Node *q = R -> left;
                remove(q);
                hash.erase(q -> key);
            }
            hash[key] = p;
            insert(p);
        }
    }


};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */