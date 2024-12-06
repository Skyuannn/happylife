#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

Node *head;

Node *GetNewNode(int x){
    Node *newNode = new Node();
    newNode->data = x;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void InsertAtHead(int x){
    Node *temp = GetNewNode(x);
    if (head == nullptr){
        head = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
    
}

void Print(){
    Node *temp = head;
    while (temp != nullptr){
        cout << temp->data;
        temp = temp ->next;
    }
    cout << endl;
}

void ReversePrint(){
    Node *temp = head;
    if (temp == nullptr){
        return;
    }
    
    while (temp->next != nullptr){
        temp = temp->next;
    }

    while (temp != nullptr){
        cout << temp->data;
        temp = temp->prev;
    }
    cout << endl;
}

int main(){
    head = nullptr;
    InsertAtHead(2); Print(); ReversePrint();
    InsertAtHead(4); Print(); ReversePrint();
    InsertAtHead(6); Print(); ReversePrint();
}