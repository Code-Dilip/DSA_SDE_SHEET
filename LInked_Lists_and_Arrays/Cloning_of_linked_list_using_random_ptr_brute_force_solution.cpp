#include<iostream>
#include<map>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node *rand;
    node(int val){
        data = val;
        next = nullptr;
        rand = nullptr;
    }
};

void printList(node *head){
    while(head!=nullptr){
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

void print_next_random_node(node *node){
    if(node==nullptr){
        cout<<"NULL -> ";
        return ;
    }
    cout<<node->data<<" -> ";
}

node *cloneLinkedList(node *head){
    node *temp = head;
    map <node *, node *> mp_ptr;
    
    while(temp!=nullptr){
        node *new_node = new node(temp->data);
        mp_ptr[temp] = new_node;
        temp = temp->next;
    }

    temp = head;
    while(temp!=nullptr){
        node *clone_node = mp_ptr[temp];
        clone_node->next = mp_ptr[temp->next];
        clone_node->rand = mp_ptr[temp->rand];
        temp = temp->next;
    }

    return mp_ptr[head];
}

int main(){

    node *head = new node(7);
    node *first_node = head;
    node *second_node = new node(13);
    node *third_node = new node(11);
    node *fourth_node = new node(10);
    node *fifth_node = new node(1);

    first_node->next = second_node;
    first_node->rand = fifth_node->next;

    second_node->next = third_node;
    second_node->rand = first_node;

    third_node->next = fourth_node;
    third_node->rand = fifth_node;

    fourth_node->next = fifth_node;
    fourth_node->rand = third_node;

    fifth_node->next = nullptr;
    fifth_node->rand = first_node;

    printList(head);

    print_next_random_node(first_node->rand);
    print_next_random_node(second_node->rand);
    print_next_random_node(third_node->rand);
    print_next_random_node(fourth_node->rand);
    print_next_random_node(fifth_node->rand);
    cout<<endl;

    node *cloned_head = cloneLinkedList(head);
    printList(cloned_head);
    cout<<endl;

    print_next_random_node(cloned_head->rand);
    print_next_random_node((cloned_head->next)->rand);
    print_next_random_node(((cloned_head->next)->next)->rand);
    print_next_random_node((((cloned_head->next)->next)->next)->rand);
    print_next_random_node(((((cloned_head->next)->next)->next)->next)->rand);
    cout<<endl;
    
    return 0;
}

