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

void remove_node_at_end_by_nth_pos(node *&head, int n){
   if(n==0){
    return ;
   }
   node *dummy = new node(-1);
   dummy->nxt = head;
   node *slow = dummy, *fast = dummy;

   for(int i=1;i<=n;i++){
    fast = fast->nxt;
   }

   while(fast!=nullptr){
    fast = fast->nxt;
    slow = slow->nxt;
   }
   node *del_node = slow->nxt;
   slow->nxt = del_node->nxt;
   delete del_node;
   head = dummy->nxt;
}

int main(){
    
    node *head = nullptr;
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    insertAtEnd(head,6);
    printList(head);

    remove_node_at_end_by_nth_pos(head,6);
    printList(head);
    
    return 0;
}