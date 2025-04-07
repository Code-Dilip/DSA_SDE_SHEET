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


node *find_intersection_point(node *head1, node *head2){
    if(head1==nullptr || head2==nullptr){
        return nullptr;
    }
    node *temp1 = head1, *temp2 = head2;
    while(temp1!=temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
        if(temp1==temp2) return temp1;
        if(temp1==nullptr) temp1 = head2;
        if(temp2==nullptr) temp2 = head1;
    }
    return temp1;
}

int main(){
    node *head1 = new node(1);
    node *head2 = new node(2);
    node *new_node = new node(2);
    node *temp1 = head1, *temp2 = head2;
    temp1->next = new_node;
    temp1 = temp1->next;

    new_node = new node(8);
    temp1->next = new_node;
    temp1 = temp1->next;

    new_node = new node(8);
    temp2->next = new_node;
    temp2 = temp2->next;

    new_node = new node(1);
    temp2->next = new_node;
    temp2 = temp2->next;

    new_node = new node(3);
    temp2->next = new_node;
    temp2 = temp2->next;

    temp2->next = temp1;
    
    new_node = new node(7);
    temp1->next = new_node;
    temp1 = temp1->next;

    new_node = new node(6);
    temp1->next = new_node;
    temp1 = temp1->next;

    printList(head1);
    printList(head2);

    node *inter_point = find_intersection_point(head1, head2);
    printList(inter_point);
    return 0;
}

