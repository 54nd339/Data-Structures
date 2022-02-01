#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *prev, *next;
}*head,*tail;
int count=0;
struct node *newNode(int info){
    struct node *new=malloc(sizeof(struct node));
    new->data=info; count++;
    new->prev= new->next = NULL;
    return new;
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
    printf("List (from start) : ");
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
    
    temp=tail;
    if(isNull()) return;
    printf("List (from end) : ");
    do{
        printf("%d ",temp->data);
        temp=temp->prev;
    }while(temp!=tail);
    printf("\n");
}
void create(){
    head=tail=NULL; int info;
    printf("Input (-1 to exit) : ");
    while(1){
        scanf("%d",&info);
        if(info==-1) break;
        struct node *new=newNode(info);
        if(head==NULL) head=new;
        else{
            tail->next=new;
            new->prev=tail;
        } tail=new;
        tail->next=head;
        head->prev=tail;
    }
    display();
}

void insert(int info, int ind){
    if(indch(ind)) return;
    struct node *new=newNode(info);
    if(head==NULL) head=new;
    else if(ind==0) {
        new->next=head; 
        head->prev=new;
        head=new;
    }
    else if(ind==count-1){
        tail->next=new;
        new->prev=tail;
        tail=new;
    }
    else {
        struct node *temp=head;
        for(int i=1;i<=ind;i++)
            temp=temp->next;
        temp->prev->next=new;
        new->prev=temp->prev;
        temp->prev=new;
        new->next=temp;
    }
    tail->next=head;
    head->prev=tail;
    display();
}
void delete(int ind){
    if(isNull()) return;
    if(indch(ind+1)) return;
    struct node *temp=head;
    if(head==tail) head=NULL;
    else if(ind==0)
        head=temp->next;
    else if(ind==count-1){
        temp=tail;
        tail=temp->prev;
    }
    else {
        for(int i=1;i<=ind;i++) 
            temp=temp->next;
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }
    tail->next=head; head->prev=tail;
    printf("Element Deleted : %d\n",temp->data);
    free(temp); count--; display(*head); 
}

int search(int info){
    if(isNull(head)) return -1;
    struct node *temp=head; int i=0;
    do{
        if(temp->data==info) return i;
        temp=temp->next; i++;
    }while(temp!=head);
    return -1;
}
void update(int info, int ind){
    if(isNull()) return;
    if(indch(ind+1)) return;
    struct node *temp=head;
    for(int i=0;i<ind;i++)
        temp=temp->next;
    temp->data=info;
    display();
}
void sort(){
    if(isNull()) return;
    struct node *index,*temp=head; int tmp;
    do{
        index=temp->next;  
        while(index!=head) {
            if(temp->data > index->data) {  
                tmp=temp->data;  
                temp->data=index->data;  
                index->data=tmp;  
            }  
            index=index->next;
        }
        temp=temp->next;  
    }while(temp->next!=head);   
    display();
}

void reverse(){
    if(isNull()) return;
    int n=count,i,tmp;
    struct node *tmph=head, *tmpt=tail;
    for(i=0;i<n/2;i++){
        tmp=tmph->data;
        tmph->data=tmpt->data;
        tmpt->data=tmp;
        tmph=tmph->next;
        tmpt=tmpt->prev;
    }
    display();
}
void rotate(int k){
    struct node *temp=head;
    for(int i=1;i<k;i++)
        temp=temp->next;
    tail=temp; head=temp->next;
    display();
}
void remDup(){
    struct node *t1=head;
    while (t1->next!=head){
        struct node *t2=t1;
        while(t2->next!=head){
            if (t1->data==t2->next->data) {
                struct node *dup = t2->next;
                t2->next = dup->next;
                dup->next->prev = t2;
                free(dup);
            }
            else t2 = t2->next;
        }
        t1 = t1->next;
    }
    tail->next=head;
    head->prev=tail;
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
        else if(ch==6) sort();
        else if(ch==7) reverse();
        else if(ch==8) {
            printf("Enter the shift : ");
            scanf("%d",&info); info%=count;
            rotate(info);
        }
        else if(ch==9) remDup();
        else if(ch==10) {
            printf("Enter key : ");
            scanf("%d",&info);
            delete(search(info));
        }
        else if(ch==0) break;
        else printf("Wrong Input\n");
    }
    return 0;
}