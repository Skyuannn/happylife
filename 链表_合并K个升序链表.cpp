// 顺序合并法.时间复杂度为 O(k2n),空间复杂度为 O(1)
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *ans = nullptr;
        for (int i = 0; i < lists.size(); ++i) {
            ans = mergeTwo(ans, lists[i]);
        }
        return ans;
    }

    ListNode *mergeTwo(ListNode *u, ListNode *v) {
        ListNode *newhead = new ListNode(-1);
        ListNode *temp = newhead;
        if (u == nullptr || v == nullptr) 
            return temp->next = u? u : v;
        while (u != nullptr && v != nullptr) {
            if (u->val > v->val) {
                temp->next = v;
                temp = v;
                v = v->next;
            }
            else {
                temp->next = u;
                temp = u;
                u = u->next;
            }
        }
        temp->next = u? u : v;
        return newhead->next;
    }   
};