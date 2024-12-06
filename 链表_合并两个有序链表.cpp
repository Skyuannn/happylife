// 递归法
struct Solution{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;
        else if (list1->val > list2->val){
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
};

// 迭代法
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *newhead = new ListNode(-1);
        ListNode *prev = newhead;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val > list2->val) {
                prev->next = list2;
                prev = list2;
                list2 = list2->next;
            }
            else {
                prev->next = list1;
                prev = list1;
                list1 = list1->next;
            }
        }
        prev->next = list1 == nullptr? list2 : list1;
        return newhead->next;
    }
};