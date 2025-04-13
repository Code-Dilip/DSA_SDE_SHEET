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
  node *slow = head, *fast = head;
  while(fast->next!=nullptr && fast->next->next!=nullptr){
    fast = fast->next->next;
    slow = slow->next;
  }
  node *newHead = slow->next;
  reverseList(newHead);
  node *first_ptr = head, *second_ptr = newHead;
  while(second_ptr!=nullptr){
    if(first_ptr->data != second_ptr->data){
        reverseList(newHead);
        return 0;
    }
    first_ptr = first_ptr->next;
    second_ptr = second_ptr->next;
  }
  reverseList(newHead);
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
    insertAtEnd(head, 1);
    insertAtEnd(head, 0);
    printList(head);
    
    cout<<check_palindrome_or_not(head)<<endl;
    printList(head);
    return 0;
}