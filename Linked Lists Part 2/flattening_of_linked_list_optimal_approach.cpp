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
    cout<<"NULL | ";
}

void printList(node *head){
    while(head!=nullptr){
        printAllChild(head);
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

node *merge2lists(node *l1, node *l2){
   node *dummy_node = new node(-1);
   node *res = dummy_node;
   while(l1!=nullptr && l2!=nullptr){
    if(l1->data<=l2->data){
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
   if(l1!=nullptr){
    res->child = l1;
   }
   else{
    res->child = l2;
   }
   return dummy_node->child;
}

node *flatten_linked_list(node *head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    node *merged_list = flatten_linked_list(head->next);
    return merge2lists(head, merged_list);
}

int main(){

    node *head = new node(3);
    node *temp = head;

    temp->next = new node(2);
    temp = temp->next;
    temp->child = new node(10);

    temp->next = new node(1);
    temp = temp->next;
    temp->child = new node(7);
    temp->child->child = new node(11);
    temp->child->child->child = new node(12);

    temp->next = new node(4);
    temp = temp->next;
    temp->child = new node(9);

    temp->next = new node(5);
    temp = temp->next;
    temp->child = new node(6);
    temp->child->child = new node(8);
    
    printList(head);
    
    node *flattened_list = flatten_linked_list(head);
    printList(flattened_list);
    printList(head);

    return 0;
}