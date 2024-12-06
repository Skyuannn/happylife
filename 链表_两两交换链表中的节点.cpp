// 递归
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *nex = head->next;
        head->next = swapPairs(nex->next);
        nex->next = head;
        return nex;
    }
};

// 迭代
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *newhead = new ListNode(-1, head);
        ListNode *prev = newhead;
        if (head == nullptr || head->next == nullptr) return head;
        while (prev->next != nullptr && prev->next->next != nullptr){
            ListNode *node1 = prev->next;
            ListNode *node2 = node1->next;
            prev->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            prev = node1;
        }
        return newhead->next;
    }   
};