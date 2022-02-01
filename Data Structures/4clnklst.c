#include <stdio.h>  
#include <stdlib.h>    
struct node{  
    int data;  
    struct node *link;  
}*head=NULL, *tail;
int count=0;
struct node *newNode(int info){
    struct node *new=malloc(sizeof(struct node));
    new->data=info; new->link=NULL;
    count++; return new;
}
int indch(int pos){
    if(pos<0 || pos>count){
        printf("Index out of bound\n");
        return 1;
    }
    return 0;
}
int isNull(){
    if(head) return 0;
    printf("Empty list\n");
    return 1;
}

void display(){
    if(isNull()) return;
    struct node *temp=head;
    printf("List : ");
    do{
        printf("%d ",temp->data);
        temp=temp->link;
    }while(temp!=head);
    printf("\n");
}
void create(){
    int info;
    printf("Input (-1 to exit) : ");
    while(1){
        scanf("%d",&info);
        if(info==-1) break;
        struct node *new=newNode(info);
        if(head==NULL) head=new;
        else tail->link=new;
        tail=new; tail->link=head;
    }
    display();
}

void insert(int info, int ind){
    if(indch(ind)) return;
    struct node *new=newNode(info);
    if(head==NULL) head=new;
    else if(ind==0) {
        new->link=head; 
        head=new;
    }
    else if(ind==count-1){
        tail->link=new;
        tail=new;
    }
    else {
        struct node *temp=head, *prev;
        for(int i=1;i<=ind;i++) {
            prev=temp;
            temp=temp->link;
        }
        prev->link=new;
        new->link=temp;
    }
    tail->link=head;
    display();
}
void delete(int ind){
    if(isNull()) return;
    if(indch(ind+1)) return;
    struct node *temp=head, *prev;
    if(head==tail) head=NULL;
    else if(ind==0)
        head=temp->link;
    else{
        for(int i=1;i<=ind;i++) {
            prev=temp;
            temp=temp->link;
        }
        if(temp->link==NULL) tail=prev;
        else prev->link=temp->link;
    } tail->link=head;
    printf("Element Deleted : %d\n",temp->data);
    free(temp); count--; display(); 
}

int search(int info){
    if(isNull(head)) return -1;
    struct node *temp=head; int i=0;
    do{
        if(temp->data==info) return i;
        temp=temp->link; i++;
    }while(temp!=head);
    return -1;
}
void update(int info, int ind){
    if(isNull()) return;
    if(indch(ind+1)) return;
    struct node *temp=head;
    for(int i=0;i<ind;i++)
        temp=temp->link;
    temp->data=info;
    display();
}
void sort(){
    if(isNull()) return;
    struct node *index,*temp=head; int tmp;
    do{
        index=temp->link;  
        while(index!=head) {
            if(temp->data > index->data) {  
                tmp=temp->data;  
                temp->data=index->data;  
                index->data=tmp;  
            }  
            index=index->link;
        }
        temp=temp->link;  
    }while(temp->link!=head);   
    display();
}

void reverse(){
    if(isNull()) return;
    struct node *curr,**ref=&head;
    struct node *next, *prev=NULL; curr=*ref; 
    do{
        next=curr->link;
        curr->link=prev;
        prev=curr; curr=next;
    }while(curr!=*ref);
    (*ref)->link=prev;
    *ref=prev; display();
}
void rotate(int k){
    struct node *temp=head;
    for(int i=1;i<k;i++)
        temp=temp->link;
    tail=temp; head=temp->link;
    display();
}
void remDup(){
    struct node *t1=head;
    while (t1->link!=head){
        struct node *t2=t1;
        while(t2->link!=head){
            if (t1->data==t2->link->data) {
                struct node *dup = t2->link;
                t2->link = dup->link;
                free(dup);
            }
            else t2 = t2->link;
        }
        t1 = t1->link;
    }
    tail->link=head;
    display();
}

int main(){
    int ch, info, pos;
    printf("\n1. Create a list");
    printf("\n2. Insert an element");
    printf("\n3. Delete an element");
    printf("\n4. Search an element");
    printf("\n5. Update an element");
    printf("\n6. Sort the list");
    printf("\n7. Reverse the list");
    printf("\n8. Rotate the list");
    printf("\n9. Remove duplicates");
    printf("\n10. Delete a key");
    printf("\n0. Exit program\n");

    while(1){
        printf("\nEnter Choice : ");
        scanf("%d",&ch);
        if(ch==1) create();
        else if(ch==2) {
            printf("Enter data & index : ");
            scanf("%d%d",&info,&pos);
            insert(info, pos);
        }
        else if(ch==3) {
            printf("Enter index : ");
            scanf("%d",&pos);
            delete(pos);
        }
        else if(ch==4) {
            printf("Enter element : ");
            scanf("%d",&info);
            pos=search(info);
            if(pos!=-1)
                printf("Found at index :%d\n",pos);
            else
                printf("Element not found\n");
        }
        else if(ch==5) {
            printf("Enter data & index : ");
            scanf("%d%d",&info,&pos);
            update(info, pos);
        }
        else if(ch==6) sort(&head);
        else if(ch==7) reverse(&head);
        else if(ch==8) {
            printf("Enter the shift : ");
            scanf("%d",&info); info%=count;
            rotate(info);
        }
        else if(ch==9) remDup(&head);
        else if(ch==10) {
            printf("Enter key : ");
            scanf("%d",&info);
            int ind=search(info);
            if(ind==-1) printf("Element not found\n");
            else delete(ind);
        }
        else if(ch==0) break;
        else printf("Wrong Input\n");
    }
    return 0;
}