#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node *child;
    node (int val){
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
    cout<<"NULL"<<" | ";
}

void printList(node *head){
    while(head != nullptr){
        printAllChild(head);
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

node *convert_to_list(vector <int> arr){
    int n = arr.size();
    if(n==0){
        return nullptr;
    }
    node *newHead = new node(arr[0]);
    node *temp =  newHead;
    for(int i=1;i<n;i++){
        node *new_node = new node(arr[i]);
        temp->child = new_node;
        temp = temp->child;
    }
    return newHead;
}

node *flatten_linked_list(node *head){

    vector <int> arr;
    while(head!=nullptr){
        node *temp = head;
        while(temp!=nullptr){
            arr.push_back(temp->data);
            temp = temp->child;
        }
        head = head->next;
    }

    sort(arr.begin(), arr.end());
    node *newHead = convert_to_list(arr);

    return newHead;
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

    node *new_Head = flatten_linked_list(head);

    printList(new_Head);

    return 0;
}
