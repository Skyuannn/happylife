#include <iostream>
#include <unordered_map>
using namespace std;

struct LRUNode {
    int key, value;
    LRUNode *prev;
    LRUNode *next;
    LRUNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    LRUNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, LRUNode *> hash;
    int size;
    int capacity;
    LRUNode *head;
    LRUNode *tail;

public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        head = new LRUNode();
        tail = new LRUNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!hash.count(key)) {
            return -1;
        }
        LRUNode *node = hash[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (!hash.count(key)) {
            LRUNode *node = new LRUNode(key, value);
            hash[key] = node;
            addToHead(node);
            ++size;
            if (size > capacity) {
                LRUNode *removed = moveTail();
                hash.erase(removed->key);
                delete(removed);
                --size;
            }
        }
        else {
            LRUNode *node = hash[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(LRUNode *node) {
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }

    void removeNode(LRUNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(LRUNode *node) {
        removeNode(node);
        addToHead(node);
    }

    LRUNode *moveTail() {
        LRUNode *node = tail->prev;
        removeNode(node);
        return node;
    }
};