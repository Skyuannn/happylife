// 递归法
class Solution{
public:
    ListNode *reverseList(ListNode *head){
        if (!head || !head->next){
            return head;
        }
        ListNode *newhead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
};


// 迭代法 *
class Solution{
public:
    ListNode *reverseList(ListNode *head){
        ListNode *pre, *cur, *next;
        pre = nullptr;
        cur = head;
        while (cur != nullptr)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head = pre;
        return head;
        
    }
};