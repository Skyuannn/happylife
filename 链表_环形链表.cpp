// 哈希表法
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> hash;

        while (head != NULL){
            hash.insert(head);
            head = head->next;
            if (hash.count(head)){
                return true;
            }
        }
        return false;
    }
};

// 快慢指针法1
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        if (head == NULL || head->next == NULL) return false;
        
        while (fast != NULL){
            slow = slow->next;
            if (fast->next == NULL) return false;
            fast = fast->next->next;
            if (fast == slow) return true;
        }
        return false;
    }
};

// 快慢指针2
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        if (head == NULL || head->next == NULL) return NULL;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};