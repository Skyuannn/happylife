// 哈希集合法
class Solution{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        unordered_set<struct ListNode *> hash;
        struct ListNode *temp = headA;
        while (temp->next != NULL){
            hash.insert(temp);
            temp = temp->next;
        }

        temp = headB;
        while (temp != NULL){
            if (hash.count(temp)){
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
};

// 双指针法
class Solution{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *head1 = headA;
        ListNode *head2 = headB;

        if (head1 == nullptr || head2 == nullptr){
            return nullptr;
        }
        
        while (head1 != head2){
            head1 = head1 == nullptr ? headB : head1->next;
            head2 = head2 == nullptr ? headA : head2->next;
        }
        return head1;
    }
};