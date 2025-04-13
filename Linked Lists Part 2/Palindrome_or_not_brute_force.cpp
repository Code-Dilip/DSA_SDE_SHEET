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
    if(head==nullptr){
        head = new_node;
        return ;
    }
    new_node->next = head;
    head = new_node;
}

void insertAtEnd(node *&head, int val){
    node *new_node = new node(val);
    if(head==nullptr){
        head = new_node;
        return;
    }
    node *temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = new_node;
}

void printList(node *head){
    while(head != nullptr){
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

void reverseList(node *&head){
    node *prev = nullptr, *curr = head, *next;
    while(curr!=nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

bool check_palindrome_or_not(node *head){
    node *temp = head;
    reverseList(temp);
    while(temp!=nullptr && head!=nullptr){
        if(temp->data!=head->data){
            return 0;
        }
        temp = temp->next;
        head = head->next;
    }
    return 1;
}


int main(){

    node *head = nullptr;
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    printList(head);

    insertAtEnd(head, 3);
    insertAtEnd(head, 2);
    insertAtEnd(head,1);
    printList(head);
    
    cout<<check_palindrome_or_not(head)<<endl;
    return 0;
}