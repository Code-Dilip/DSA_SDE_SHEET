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

void insertCloneNodes_in_between(node *head){
    node *temp = head;
    while(temp!=nullptr){
        node *new_node = new node(temp->data);
        new_node->next = temp->next;
        temp->next = new_node;
        temp = (temp->next)->next;
    }
}

void connect_random_ptrs(node *head){
    node *temp = head;
    while(temp!=nullptr){
        node *cloned_node = temp->next;
        if(temp->rand != nullptr){
            cloned_node->rand = (temp->rand)->next;
        }
        else{
            cloned_node->rand = nullptr;
        }
        temp = (temp->next)->next;
    }
}

node *connect_next_ptrs(node *head){
    node *temp = head;
    node *dummy_node = new node(-1);
    node *res = dummy_node;
    
    while (temp!=nullptr)
    {
        res->next = temp->next;
        res = temp->next;
        temp->next = res->next;
        temp = temp->next;
    }
    
    return dummy_node->next;
}

node *cloneLinkedList(node *head){
    insertCloneNodes_in_between(head);
    connect_random_ptrs(head);
    node *cloned_list_head = connect_next_ptrs(head);
    return cloned_list_head;
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
    cout<<endl;

    node *cloned_head = cloneLinkedList(head);
    printList(cloned_head);

    print_next_random_node(cloned_head->rand);
    print_next_random_node((cloned_head->next)->rand);
    print_next_random_node(((cloned_head->next)->next)->rand);
    print_next_random_node((((cloned_head->next)->next)->next)->rand);
    print_next_random_node(((((cloned_head->next)->next)->next)->next)->rand);
    cout<<endl;
    

    //insert_clone_nodes_in_between(head);
    //printList(head);
    
    return 0;
}

