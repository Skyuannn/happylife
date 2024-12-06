#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

struct Node *Insert(struct Node *head, int data){
    Node *temp1 = new Node();
    int n = 1;
    temp1->data = data;
    temp1->next = NULL;
    if (n == 1){
        temp1->next = head;
        head = temp1;
        return head;
    }

    Node *temp2 = head;
    for (int i = 0; i < n - 2; i++){
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
    return head;
}

void Delete(int n){
    struct Node *temp1 = head;
    if (n == 1){
        head = temp1->next;
        delete temp1;
        return;
    }
    
    for (int i = 0; i < n - 2; ++i){
        temp1 = temp1->next;

    }
    struct Node *temp2 = temp1->next;

    temp1->next = temp2->next;
    delete temp2;
}

// 反转链表迭代方式
// struct Node *Reverse(struct Node *head){
//     struct Node *pre, *current, *next;
//     pre = NULL;
//     current = head;
//     while(current != NULL){
//         next = current->next;
//         current->next = pre;
//         pre = current;
//         current = next;
//     }
//     head = pre;
//     return pre;
// }

// 反转链表递归方式
struct Node *Reverse(struct Node *p){
    if (p->next == NULL){
        head = p;
        return head;
    }
    Reverse(p->next);
    struct Node *q = p->next;
    q->next = p;
    p->next = NULL;
    return head;
}

//迭代方式
void Print(struct Node *head){
    struct Node *temp = head;
    while(temp != NULL){
        cout << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

// 递归方法
// void Print(struct Node *head){
//     if (head == NULL)
//         return;
//     cout << head->data;
//     Print(head->next);
// }

// 反转列表递归方法
// void ReversePrint(struct Node *head){
//     if (head == NULL)
//         return;
//     ReversePrint(head->next);
//     cout << head->data;
// }

// int main(){
//     struct Node *head = NULL;
//     head = Insert(head,2);
//     head = Insert(head,4);
//     head = Insert(head,6);
//     head = Insert(head,8);
//     Print(head);
//     // int n, x;
//     // cout << "Eenter a position\n";
//     // cin >> x;
//     // Delete(x);
//     head = Reverse(head);
//     Print(head);
// }

int main(){
    struct Node *p = NULL;
    head = Insert(head,2);
    head = Insert(head,4);
    head = Insert(head,6);
    head = Insert(head,8);
    Print(head);
    // int n, x;
    // cout << "Eenter a position\n";
    // cin >> x;
    // Delete(x);
    head = Reverse(head);
    Print(head);
}