#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 数组双指针
class Solution{
public:
    bool isPalindrome(ListNode *head) {
        vector<int> nums;
        while (head != nullptr){
            nums.emplace_back(head->val);
            head = head->next;
        }

        for (int i = 0, j = (int)nums.size() - 1; i < j; ++i, --j){
            if (nums[i] != nums[j]){
                return false;
            }
        }
        return true;
    }
};

// 递归1 *
class Solution{
private:
    ListNode *frontPointer;
public:
    bool check(ListNode *currentNode){
        if (currentNode != nullptr) {
            if (!check(currentNode->next)) return false;
            if (currentNode->val == frontPointer->val) {
                frontPointer = frontPointer->next;
                return true;
            }
            return false;
        }
        return true;
    }
    
    bool isPalindrome(ListNode *head){
        frontPointer = head;
        return(check(head));

    }
};

// 递归2
class Solution {
    ListNode *frontPointer;

public:
    bool isPalindrome(ListNode* head) {
        frontPointer = head;
        return isReverse(head);
    }

    bool isReverse(ListNode *currentNode) {
        if (currentNode == nullptr) return true;
        if (!isReverse(currentNode->next)) return false;
        if (frontPointer->val != currentNode->val) {
            return false;
        }
        frontPointer = frontPointer->next;
        return true;
    }
};

// 递归3,lambda表达式
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *newhead = head;
        auto isReverse = [&](auto &&isReverse, ListNode *head) {
            if (head == nullptr) return true;
            if (!isReverse(isReverse, head->next)) return false;
            if (head->val == newhead->val) {
                newhead = newhead->next;
                return true;
            }
            return false;
        };
        return isReverse(isReverse, head);
    }
};

