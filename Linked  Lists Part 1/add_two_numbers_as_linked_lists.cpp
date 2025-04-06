#include<iostream>
using namespace std;

class node{
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

node *add_two_numbers(node *num1, node *num2){
    node *res = nullptr;
    int carry = 0;

    while(num1!=nullptr || num2!=nullptr || carry==1){
        int sum = 0;
        if(num1!=nullptr){
            sum += num1->data;
            num1 = num1->nxt;
        }
        if(num2!=nullptr){
            sum += num2->data;
            num2 = num2->nxt;
        }
        sum += carry;
        insertAtEnd(res, sum%10);
        carry = sum/10;
    }
    return res;
}

int main(){
    node *num1 = nullptr, *num2 = nullptr;
    insertAtEnd(num1 ,2);
    insertAtEnd(num1, 4);
    insertAtEnd(num1, 3);
    printList(num1);

    insertAtEnd(num2, 5);
    insertAtEnd(num2, 6);
    insertAtEnd(num2, 7);
    insertAtEnd(num2, 9);
    printList(num2);

    node *res = add_two_numbers(num1, num2);
    printList(res);
    return 0;
}