// 哈希表法
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> hash;
        while (head != nullptr){
            if (hash.count(head)) return head;
            hash.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};

// 快慢指针法
class Solution{
public:
    ListNode *detectCycle(ListNode *head){
        ListNode *fast = head, *slow = head;
        if (head == nullptr || head->next == nullptr) return nullptr;

        while (fast != nullptr){
            if (fast->next == nullptr) return nullptr;
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow){
                ListNode *temp = head;
                while (temp != slow) {
                    temp = temp->next;
                    slow = slow->next;
                }
                return temp;
            }
        }
        return nullptr;
    }
};