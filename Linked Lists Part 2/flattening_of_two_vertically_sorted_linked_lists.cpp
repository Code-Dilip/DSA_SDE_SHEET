#include<iostream>
using namespace std;

class node{
    public: 
    int data ;
    node *next ;
    node *child;

    node(int val){
        data = val;
        next = nullptr;
        child = nullptr;
    }
};

void printAllChild(node *temp){
    while(temp!=nullptr){
        cout<<temp->data<<" -> ";
        temp = temp->child;
    }
    cout<<" | ";
}

void printList(node *head){
    while(head!=nullptr){
        printAllChild(head);
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

node *merge2lists(node *l1, node *l2){
    node *dummy = new node(-1);
    node *res = dummy;
    while (l1!=nullptr && l2!=nullptr)
    {
        if(l1->data <= l2->data){
            res->child = l1;
            res = l1;
            l1 = l1->child;
        }
        else{
            res->child = l2;
            res = l2;
            l2 = l2->child;
        }
        res->next = nullptr;
    }
    if(l1 != nullptr){
        res->child = l1;
    }
    else{
        res->child = l2;
    }
    return dummy->child;
}

int main(){

    node *head1 = new node(4);
    node *head2 = new node(5);

    head1->next = head2;
    head1->child = new node(9);
    
    head2->child = new node(6);
    head2->child->child = new node(8);

    printList(head1);

    node *merged_list = merge2lists(head1, head2);

    printList(merged_list);
    
    return 0;
}