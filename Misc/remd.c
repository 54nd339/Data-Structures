<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* link;
}Node;

void display(Node *head){
    Node *temp = head;
    if(head == NULL){
        printf("Empty List\n");
        return;
    }
    printf("List : ");
    while(temp){
        printf("%d",temp->data);
        if(temp->link) printf(" -> ");
        temp = temp->link;
    }
    printf("\n");
}

Node *create(Node *head){
    Node *temp = head = NULL;
    printf("Input (-1 to exit) : ");
    while(1){
        int info; scanf("%d",&info);
        if(info == -1) break;
        Node *new=malloc(sizeof(Node));
        new->data = info; new->link = NULL;
        if(!head) {
            head = new; temp = new;
        }
        else{
            temp->link = new; temp = new;
        }
    }
    display(head); return head;
}

Node *delete(Node *head, int k){
    Node *temp = head, *prev;
    while(temp){
        int flag = 1;
        if(temp->data%k == 0){
            if(temp == head){
                flag = 0;
                head = head->link;
            }
            else (prev)->link = temp->link;
            printf("Element Deleted : %d\n",temp->data);
            free(temp);
        }
        else prev = temp;
        temp = (flag) ? (prev)->link : head;
    }
    display(head); return head; 
}

int main(){
    Node *head;
    head = create(head);
    printf("Enter Number : ");
    int n; scanf("%d",&n);
    head = delete(head, n);
    return 0;
=======
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
}*head;

void display(){
    struct node *temp=head;
    if(head==NULL){
        printf("Empty List\n");
        return;
    }
    printf("List : ");
    while(temp){
        printf("%d",temp->data);
        if(temp->link) printf(" -> ");
        temp=temp->link;
    }
    printf("\n");
}

void create(){
    struct node *temp=head=NULL; int info;
    printf("Input (-1 to exit) : ");
    while(1){
        scanf("%d",&info);
        if(info==-1) break;
        struct node *new=malloc(sizeof(struct node));
        new->data=info; new->link=NULL;
        if(!head) {
            head = new; temp = new;
        }
        else{
            temp->link = new; temp = new;
        }
    }
    display();
}

void delete(int k){
    struct node *temp=head, *prev;
    while(temp){
        int flag=1;
        if(temp->data%k==0){
            if(temp==head){
                flag=0;
                head=head->link;
            }
            else (prev)->link=temp->link;
            printf("Element Deleted : %d\n",temp->data);
            free(temp);
        }
        else prev=temp;
        temp=(flag)?(prev)->link:head;
    }
    display(); 
}

int main(){
    int n; 
    create();
    printf("Enter Number : ");
    scanf("%d",&n);
    delete(n);
    return 0;
>>>>>>> c14086eac1b9db45c2ade3ab55c20ad590ceb675
}