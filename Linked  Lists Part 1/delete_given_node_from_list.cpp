#include<iostream>
using namespace std;

class node{
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
    node *new_node = new node(val);
    if(head==nullptr){
        head = new_node;
        return ;
    }
    node *temp = head;
    while(temp->nxt != nullptr){
        temp = temp->nxt;
    }
    temp->nxt = new_node;
}

void printList(node *head){
    while(head!=nullptr){
        cout<<head->data<<" -> ";
        head = head->nxt;
    }
    cout<<"NULL"<<endl;
}

void delete_given_node(node *head, node *node){
    if(head==nullptr){
        return ;
    }
    node->data = node->nxt->data;
    node->nxt = node->nxt->nxt;
}

int main(){
    node *head = nullptr;
    insertAtEnd(head, 1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    printList(head);
    
    node *temp = head->nxt->nxt;
    delete_given_node(head, temp);
    printList(head);

    return 0;
}
