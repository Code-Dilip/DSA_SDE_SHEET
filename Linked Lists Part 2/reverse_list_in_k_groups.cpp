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
}

node *get_kth_node(node *head, int k){
    k--;
    while(head!=nullptr && k>0){
        head = head->next;
        k--;
    }
    return head;
}


void reverse_list_in_k_groups(node *&head, int k){
    node *temp = head, *prevLast = nullptr;
    while(temp!=nullptr){
        node *kth_node = get_kth_node(temp, k);
        if(kth_node==nullptr){
            if(prevLast) prevLast->next = temp;
            break;
        }
        node *next_node = kth_node->next;
        kth_node->next = nullptr;

        reverseList(temp);
        if(temp==head){
            head = kth_node;
        }
        else{
            prevLast->next = kth_node;
        }
        prevLast = temp;
        temp = next_node;
    }
}

int main(){

    node *head = nullptr;
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    printList(head);

    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    insertAtEnd(head,6);
    printList(head);

    //reverseList(head);
    reverse_list_in_k_groups(head, 3);
    printList(head);
    return 0;
}