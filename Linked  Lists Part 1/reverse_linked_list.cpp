#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int val){
        data = val;
        next = nullptr;
    }
};

void insertAtHead(node *&head, int val){
    node *new_node = new node(val);
    if(head == nullptr){
        head = new_node;
        return ;
    }
    new_node->next = head;
    head = new_node;
    return ;
}

void insertAtEnd(node *head, int val){
    node *new_node = new node(val);
    if(head == nullptr){
        head = new_node;
        return ;
    }
    node *temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next =  new_node;
    return;
}

void printList(node *head){
    node *temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void reverseList(node *&head){
    if(head == nullptr){
        return ;
    }
    node *prev = nullptr, *curr = head, *next;
    while(curr!=nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main(){
    node *head = nullptr;
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    printList(head);
    
    insertAtEnd(head,6);
    insertAtEnd(head,7);
    insertAtEnd(head,8);
    insertAtEnd(head,9);
    insertAtEnd(head,10);
    printList(head);

    reverseList(head);
    printList(head);

    return 0;
}