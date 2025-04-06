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

void remove_node_at_end_by_n_pos(node *&head, int n){
    if(n==0){
        return ;
    }
    node *temp = head;
    int N = 0;
    while(temp!=nullptr){
        N ++;
        temp = temp->nxt;
    }
    node *del_node;
    int pos = N - n;
    if(pos==0){
        del_node = head;
        head = head->nxt;
        delete del_node;
        return ;
    }
    pos --;
    temp = head;
    while(pos>=0){
        temp = temp->nxt;
        pos --;
    }
    del_node = temp->nxt;
    temp->nxt = del_node->nxt;
    delete del_node;
}

int main(){
    
    node *head = nullptr;
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    insertAtEnd(head,6);
    printList(head);

    remove_node_at_end_by_n_pos(head,0);
    printList(head);
    
    return 0;
}