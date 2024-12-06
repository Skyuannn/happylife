// 较短的链表用0补齐末尾
class Solution{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
        ListNode *newNode = new ListNode(0), *head = newNode;
        int sum = 0, add = 0;
        while (l1 || l2){
            sum = (l1? l1->val : 0) + (l2? l2->val : 0) + add;
            int n = sum % 10;
            add = sum / 10;
            head->next = new ListNode(n);
            head = head->next;
            l1 = l1? l1->next : 0;
            l2 = l2? l2->next : 0;
        }
        if (add) head->next = new ListNode(add);
        return newNode->next;
    }
};