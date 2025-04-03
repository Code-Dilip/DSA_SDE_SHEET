#include<iostream>
using namespace std;

class node {
    public: 
    int data;
    node *nxt;
    node(int val){
        data = val;
        nxt = nullptr;
    }
};

void insertAtHead(node *&head, int val){
    node *new_node = new node(val);
    if(head==nullptr){
        head = new_node;
        return ;
    }
    new_node->nxt = head;
    head = new_node;
}

void insertAtEnd(node *&head, int val){
    node *new_Node = new node(val);
    if(head == nullptr){
        head = new_Node;
        return ;
    }
    node *temp = head;
    while(temp->nxt != nullptr){
        temp = temp->nxt;
    }
    temp->nxt = new_Node;
}

void printList(node *head){
    node *temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" -> ";
        temp = temp->nxt;
    }
    cout<<" NULL"<<endl;
}

void reverseList(node *&head){
    node *prev = nullptr, *curr = head, *next;
    while(curr!=nullptr){
        next = curr->nxt;
        curr->nxt = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

node *find_mid(node *head){
    node *fast = head;
    node *slow = head;

    while(fast!=nullptr && fast->nxt!=nullptr){
        slow = slow->nxt;
        fast = (fast->nxt)->nxt;
    }
    slow->nxt = nullptr;
    return slow;
}

int main(){
    node *head = nullptr;
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    printList(head);

    insertAtEnd(head,4);
    insertAtEnd(head,5);
    insertAtEnd(head,6);
    printList(head);

    reverseList(head);
    printList(head);

    node *mid = find_mid(head);
    printList(mid);

    return 0;
}