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

bool detect_cycle(node *head){
    node *fast = head, *slow = head;
    do{
        fast = (fast->next)->next;
        slow = slow->next;
        if(fast==slow){
            return true;
        }
    }
    while(fast!=nullptr && fast->next!=nullptr);
    return false;
}


int main(){
    node *head1 = new node(1);
    node *temp1 = head1, *temp2;

    node *new_node = new node(2);
    temp1->next = new_node;
    temp1 = temp1->next;

    new_node = new node(3);
    temp1->next = new_node;
    temp1 = temp1->next;
    temp2 = temp1;

    new_node = new node(4);
    temp1->next = new_node;
    temp1 = temp1->next;

    new_node = new node(5);
    temp1->next = new_node;
    temp1 = temp1->next;

    new_node = new node(6);
    temp1->next = new_node;
    temp1 = temp1->next;

    new_node = new node(7);
    temp1->next = new_node;
    temp1 = temp1->next;

    new_node = new node(8);
    temp1->next = new_node;
    temp1 = temp1->next;

    new_node = new node(9);
    temp1->next = new_node;
    temp1 = temp1->next;

    //temp1->next = temp2;

    //printList(head1);

    cout<<detect_cycle(head1)<<endl;

    return 0;
}

