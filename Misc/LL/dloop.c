//detect loop
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
}*head, *tail;

void create(){
    int in=4;
    while(1){
        if(in==-1) break;
        struct node *new=malloc(sizeof(struct node));
        new->data=in;new->link=NULL;
        if(head==NULL){
            head=new; tail=new;
        }
        else{
            tail->link=new; 
            tail=new;
        } in--;
    }
}
void display(){
    struct node *temp=head;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->link;
    }
}
void check(){
    struct node *slow, *fast;
    slow=head;fast=head;
    int flag=1;
    while(fast->link && fast->link->link){
        slow=slow->link;
        fast=fast->link->link;
        if(slow==fast){
            flag=0; break;
        }
    }
    if(flag) display();
    else printf("\nLoop Detected\n");
}
int main(){
    create();
    check();
    tail->link=head->link;
    check();
    return 0;
}