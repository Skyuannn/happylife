// 哈希表法
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *> hash;
        Node *p = head;
        while (p != NULL){
            Node *newhead = new Node(p->val);
            hash[p] = newhead;
            p = p->next;
        }
        p = head;
        while (p != NULL){
            hash[p]->next = hash[p->next];
            hash[p]->random = hash[p->random];
            p = p->next;
        }
        return hash[head];
    }
};

// 递归法+哈希表法
class Solution{
public:
    unordered_map<Node *, Node *> hash;
    Node *copyRandomList(Node *head) {
        if (head == nullptr) return nullptr;
        if (!hash.count(head)){
            Node *newhead = new Node(head->val);
            hash[head] = newhead;
            newhead->next = copyRandomList(head->next);
            newhead->random = hash[head->random];
        }
        return hash[head];
    }
};