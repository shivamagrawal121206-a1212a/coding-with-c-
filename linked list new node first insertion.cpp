#include<iostream>
#include<cstdlib>
using namespace std;
struct node {
    int data;
    struct node *next;
};
struct node *start=NULL, *ptr;
int val;
void display() {
    ptr=start;
    while(ptr!=NULL) {
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<"NULL";
}
void createnode() {
    cout<<"Input the value to be inserted: ";
    cin>>val;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    if(start==NULL) {
        start=newnode;
    } else {
        ptr=start;
        while(ptr->next!=NULL) {
            ptr=ptr->next;
        }
        ptr->next=newnode;
    }
}
void createnodebag() {
    cout<<"Input the value to be inserted: ";
    cin>>val;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=start;
    start=newnode;
}
int main() {
    int n;
    cout<<"Number of nodes: ";
    cin>>n;
    for(int i=0; i<n; i++) {
        createnode();
    }
    cout<<"Existing Linked List: ";
    display();
    cout<<"\nInput the value to be inserted at the first: ";
    createnodebag();
    cout<<"\nLinked List after insertion at first: ";
    display();
    cout<<"\nFreeing memory...";
    ptr=start;
    while(ptr!=NULL) {
        struct node *nextnode=ptr->next;
        free(ptr);
        ptr=nextnode;
    }
    start=NULL;
    return 0;
}
