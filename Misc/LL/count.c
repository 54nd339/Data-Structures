//count no. of occurence of elemnts
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
}*head,*temp;
int count=0;

void display(){
    if(head==NULL)
        printf("Empty node\n");
    else{
        temp=head;
        while(temp){
            printf("%d ",temp->data);
            temp=temp->link;
        }
    }
}

void create(){
    struct node *new; int in;
    printf("Input(-1 to exit) : ");
    while(1){
        scanf("%d",&in);
        if(in==-1) break;
        new=malloc(sizeof(struct node));
        new->data=in; new->link=NULL;
        if(head==NULL){
            head=new; temp=new;
        }
        else{
            temp->link=new; temp=new;
        }
        count++;
    }
    printf("List : ");
    display();
}

void sort(){
    struct node *cur; int tmp;
    for(temp=head;temp;temp=temp->link)
		for(cur=temp->link;cur;cur=cur->link)
			if(temp->data > cur->data) {
				tmp=temp->data;
				temp->data=cur->data;
				cur->data=tmp;
			}
}

void counte(){
    sort();
    temp=head;
    while(temp){
        int c=0;
        while(temp->link && temp->data==temp->link->data){
            c++; temp=temp->link;
        }
        printf("\nNo of. %d in list is %d",temp->data,c+1);
        temp=temp->link;
    }
}

int main(){
    create();
    (head==NULL)?printf("Empty node\n"):counte();
    return 0;
}