// 递归法
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p = head;
        int j = 0;
        while (p != nullptr){
            j++;
            p = p->next;
        }
        if (k > j) return head;

        ListNode *prev = head;
        ListNode *nex = prev->next;
        for (int i = 0; i < k - 1; i++){
            ListNode *temp = nex->next;
            nex->next = prev;
            prev = nex;
            nex = temp;
        }
        head->next = reverseKGroup(nex, k);
        return prev;
    }
};

// 迭代法