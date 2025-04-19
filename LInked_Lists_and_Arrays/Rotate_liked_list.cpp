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

node *get_Kth_node(node *head, int k){
    int cnt = 1;
    while(cnt!=k && head!=nullptr){
        head = head->next;
        cnt ++;
    }
    return head;
}

void rotateList(node *&head, int k){
    if(head==nullptr || k==0){
        return ;
    }
    int len = 1;
    node *tail = head;
    while(tail->next!=nullptr){
        len ++;
        tail = tail->next;
    }

    if(k%len==0){
        return ;
    }
    k = k%len;
    node *newLastNode = get_Kth_node(head, len-k);

    tail->next = head;
    head = newLastNode->next;
    newLastNode->next = nullptr;
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

    rotateList(head, 6);
    printList(head);

    rotateList(head, 7);
    printList(head);
    return 0;
}