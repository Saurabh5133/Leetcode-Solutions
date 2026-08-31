class Node
{
    public:
    int key;
    int val;

    Node* prev;
    Node* next;

    Node(int k, int v)
    {
        key = k; val = v;
        prev = NULL; next = NULL;
    }
};


class LRUCache {

    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> mpp;

    void addNode(Node* node)
    {
        Node* prevNode = tail->prev;

        prevNode->next = node;
        node->next = tail;
        node->prev = prevNode;
        tail->prev = node;
    }

    void removeNode(Node* node)
    {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void moveToFront(Node* node)
    {
        removeNode(node);
        addNode(node);
    }

public:
    LRUCache(int capacity) {

        this->capacity = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head->next = tail;
        tail->prev = head;

    }
    
    int get(int key) {

        if(mpp.find(key) == mpp.end())
            return -1;

        Node* node = mpp[key];
        moveToFront(node);

        return node->val;
        
    }
    
    void put(int key, int value) {

        if(mpp.find(key) != mpp.end())
        {
            Node* node = mpp[key];

            node->val = value;

            moveToFront(node);

            return;
        }

        Node* newNode = new Node(key,value);
        mpp[key] = newNode;
        addNode(newNode);

        if(mpp.size() > capacity)
        {
            Node* lru = head->next;
            removeNode(lru);

            mpp.erase(lru->key);

            delete lru;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */