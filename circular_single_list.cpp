#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};
struct node *avail = NULL;
struct node *head = NULL;

void insertion_first(){
    avail = (struct node*)malloc(sizeof(struct node));
    struct node *NN = avail;
    int val;
    cout<<"Enter val : ";
    cin>>val;
    if(avail == NULL){
        cout<<"no space";
    }
    else if(head == NULL){
         NN->data = val;
        NN->next = NN;
        head = NN;
        cout<<"first node inserted"<<endl;
    }
    else{
        NN->data = val;
        NN->next = head;
        struct node* p1 = head;
        while(p1->next != head){
            p1 = p1->next;
        }
        p1->next = NN;
        head = NN;

        cout<<"Node inserted at first"<<endl;
    }
}

void insertion_last(){
    avail = (struct node*)malloc(sizeof(struct node));
    struct node *NN = avail;
    int val;
    cout<<"Enter val : ";
    cin>>val;
    if(avail == NULL){
        cout<<"No space to insert"<<endl;
    }
    else if(head == NULL){
        NN->data = val;
        NN->next = NN;
        head = NN;
        cout<<"first node inserted"<<endl;
    }
    else{
        NN->data = val;
        NN->next = head;
        struct node *temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = NN;
       
        cout<<"Node inserted"<<endl;
    }

}
void insertion_before_desire(){
    int key;
    cout<<"Enter your desired key : ";
    cin>>key;
    avail = (struct node*)malloc(sizeof(struct node));
    struct node *NN = avail;
    int val;
    cout<<"Enter val : ";
    cin>>val;
    if(avail == NULL){
        cout<<"No space to insert"<<endl;
    }
    else{
        if(head->data == key){
            NN->data = val;
            NN->next = head;
            head = NN;
        }
        else{
        struct node *p1 = head;
        struct node *p2 = head;
        while(p2->data != key){
            if(p2->next == head){
                cout<<"No key found "<<endl;
                p2 = NULL;
                break;
            }
            p1 = p2;
            p2 = p2->next;
        }
        if(p2 != NULL){
        NN->data = val;
        NN->next = p2;
        p1->next = NN;
        cout<<"node inserted successfull before "<<key<<endl;
        }
        }
    }
    

}
void insertion_after_desire(){
    int key;
    cout<<"Enter your desired key : ";
    cin>>key;
    avail = (struct node*)malloc(sizeof(struct node));
    struct node *NN = avail;
    int val;
    cout<<"Enter val : ";
    cin>>val;
    if(avail == NULL){
        cout<<"No space to insert"<<endl;
    }
    else{
        struct node *p1 = head;
        while(p1->data != key){
            if(p1->next == head){
                cout<<"no key found"<<endl;
                p1 = NULL;
                break;
            }
            p1 = p1->next;
        }
        if(p1 != NULL){
            if(p1->next == head){
                NN->data = val;
                NN->next = head;
                p1->next = NN;
            }
        NN->data = val;
        NN->next = p1->next;
        p1->next = NN;
        cout<<"node inserted successfull before "<<key<<endl;
        }
    }
}
void delete_first(){
    if(head == NULL){
        cout<<"underflow"<<endl;
    }
    else if(head->next == head){
        struct node *p = head;
        free(p);
        head = NULL;
    }
    
    else{
        struct node *p1 = head;
        struct node *start = head;
        
        while(start->next != head){
            start = start->next;
        }
        head = head->next;
        start->next = head;
        free(p1);
        cout<<"deleted first node"<<endl;
    }
}
void delete_last(){
    if(head == NULL){
        cout<<"underflow"<<endl;
    }
    else if(head->next == head){
        struct node *p = head;
        free(p);
        head = NULL;
    }
    
    else{
        struct node *p1 = head;
        struct node *p2 = head;
        while(p2->next!=head){
            p1 = p2;
            p2 = p2->next;
        }
        p1->next = head;
        free(p2);
        cout<<"deleted last node"<<endl;

    }
}
void delete_position(){
    if(head == NULL){
        cout<<"underflow"<<endl;
    }
    else{
        int key;
        cout<<"Enter desired position : ";
        cin>>key;
        if(head->data == key){
            struct node *p = head;
            head = head->next;
            free(p);
        }
        else{
        struct node *p1 = head;
        struct node *p2 = head;
        while(p2->data != key){
            if(p2->next == head){
                cout<<"No desire position found"<<endl;
                p2=NULL;
                break;
            }
            p1 = p2;
            p2 = p2->next;
        }
        if(p2 != NULL){
            if(p2->next == head){
                p1->next = head;
            }
            else{
                p1->next = p2->next;
            }
        }
        free(p2);
        
        }
    }
}
void delete_after_desire(){
    if(head == NULL){
        cout<<"underflow"<<endl;
    }
    else{
        int key;
        cout<<"Enter desired key : ";
        cin>>key;
        struct node *p1 = head;
        while(p1->data != key){
            if(p1->next == head){
                cout<<"No key found"<<endl;
                p1 = NULL;
                break;
            }
            p1 = p1->next;
        }
        if(p1 != NULL){
            if(p1->next == head){
                cout<<"No node to delete : "<<endl;
        }
            else{
                struct node* p2 = p1->next;
                p1->next = p2->next;
                free(p2);
            }
        }
    }
}
void display(){
    if(head == NULL){
        cout<<"Linked list in empty"<<endl;
    }
    else{
        struct node *start = head;
        while(true){
        cout<<start->data<<" ";
        if(start->next == head){
            break;
        }
        else{
            start = start->next;
        }
    }
    cout<<endl;
    }
 }
int main(){
    bool c= true;
    int ch;
    while(c){ 
    cout<<"1 for insertion at first position\n2 for insertion at last position\n3 for insertion before desired postion\n4 for insertion after desired position\n5 for deletion at desired position\n6 for delete first node\n7 for delete last node\n8 for deletion after desired position\n9 for display\n10 for exit"<<endl;
    cout<<"Enter your choice : ";
    cin>>ch;
    switch(ch){
        case 1:{insertion_first(); break;}
        case 2:{insertion_last(); break;}
        case 3:{insertion_before_desire(); break;}
        case 4:{insertion_after_desire(); break;}
        case 5:{delete_position(); break;}
        case 6:{delete_first();break;}
        case 7:{delete_last();break;}
        case 8:{delete_after_desire(); break;}
        case 9:{display(); break;}
        case 10:{c=false;break;}
        default:{cout<<"Wrong choice entered : "<<endl;break;}
    }
    }
    
    return 0;
}
