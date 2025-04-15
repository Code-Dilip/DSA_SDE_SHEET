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
}

void insertAtEnd(node *&head, int val){
    node *new_node = new node(val);
    if(head == nullptr){
        head = new_node;
        return ;
    }
    node *temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = new_node;
}

void printList(node *head){
    while(head!=nullptr){
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

void rotateList(node *&head, int k){
    int n = 0;
    node *temp = head;
    while(temp!=nullptr){
        n ++;
        temp = temp->next;
    }
    
    temp = head;
    if(k%n==0){
        return ;
    }
    k = k%n;
    while(k>=0 && temp!=nullptr){
        k --;
        temp = temp->next;
    }

    node *tail = temp;
    while(tail->next!=nullptr){
        tail = tail->next;
    }
    tail->next = head;
    
    head = temp->next;
    temp->next = nullptr;
}

int main(){

    node *head = nullptr;
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head,1);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);

    printList(head);
    rotateList(head, 3);
    printList(head);
    return 0;
}