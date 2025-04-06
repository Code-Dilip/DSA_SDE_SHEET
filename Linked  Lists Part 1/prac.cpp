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
    if(head == nullptr){
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

void reverseList(node *&head){
    node *prev = nullptr, *curr = head, *next;
    while(curr!=nullptr){
        next = curr->nxt;
        curr->nxt = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

node *merge_2_sorted_lists(node *head1, node *head2){
    if(head1==nullptr){
        return head2;
    }
    if(head2==nullptr){
        return head1;
    }
    node *dummy = new node(-1);
    node *temp = dummy;
    while(head1!=nullptr && head2!=nullptr){
        if(head1->data <= head2->data){
            temp->nxt = head1;
            temp = head1;
            head1 = head1->nxt;
        }
        else if(head2->data <= head1->data){
            temp->nxt = head2;
            temp = head2;
            head2 = head2->nxt;
        }
    }
    if(head1==nullptr){
        temp->nxt = head2;
    }
    else{
        temp->nxt = head1;
    }
    return dummy->nxt;
}

int main(){
    node *head1 = nullptr, *head2 = nullptr;
    insertAtEnd(head1, 1);
    insertAtEnd(head1, 2);
    insertAtEnd(head1, 5);
    insertAtEnd(head1, 9);

    insertAtEnd(head2, 2);
    insertAtEnd(head2, 4);
    insertAtEnd(head2, 6);
    insertAtEnd(head2, 10);

    printList(head1);
    printList(head2);
    
    node *res = merge_2_sorted_lists(head1, head2);
    printList(res);

    return 0;
}