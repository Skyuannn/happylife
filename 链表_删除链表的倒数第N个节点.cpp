// 栈
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *newhead = new ListNode(-1, head);
        ListNode *temp = newhead;
        stack<ListNode *> st;
        while (temp != nullptr){
            st.push(temp);
            temp = temp->next;
        }
        for (int i = 0; i < n; i++){
            st.pop();
        }
        ListNode *prev = st.top();
        prev->next = prev->next->next;
        return newhead->next;
    }
};

// 计算链表长度
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        ListNode *p = head;
        int all = 0;
        while (p != nullptr){
            all++;
            p = p->next;
        }

        if (head == nullptr || head->next == nullptr) return nullptr;
        if (n == all) return head->next;
        for (int j = 0; j < all; j++) {
            if (j == all - n - 1){
                temp->next =  temp->next->next;
                return head;
            }
            else temp = temp->next;
        }
        return head;
    }
};