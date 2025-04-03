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

node *merge_2_linked_lists(node *head1, node *head2){
    node *res = nullptr;
    while(head1!=nullptr && head2!=nullptr){
        if(head1->data <= head2->data){
            insertAtEnd(res,head1->data);
            head1 = head1->nxt;
        }
        else if(head2->data <= head1->data){
            insertAtEnd(res,head2->data);
            head2 = head2->nxt;
        }
    }

    while(head1!=nullptr){
        insertAtEnd(res,head1->data);
        head1 = head1->nxt;
    }
    while(head2!=nullptr){
        insertAtEnd(res,head2->data);
        head2 = head2->nxt;
    }
    return res;
}

int main(){
    node *head1 = nullptr;
    insertAtEnd(head1,1);
    insertAtEnd(head1,3);
    insertAtEnd(head1,6);
    
    node *head2 = nullptr;
    insertAtEnd(head2,1);
    insertAtEnd(head2,2);
    insertAtEnd(head2,4);
    insertAtEnd(head2,4);
    insertAtEnd(head2,5);
    insertAtEnd(head2,7);

    node *res = merge_2_linked_lists(head1, head2);
    printList(res);

    return 0;
}