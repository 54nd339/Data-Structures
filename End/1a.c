#include <stdio.h>
#include <stdlib.h>
struct node {
	int key;
	struct node* link;
}*head = NULL, *tail;

void enQueue(int k){
    struct node* temp = malloc(sizeof(struct node));
    temp->key = k; temp->link = NULL;
    if (head == NULL) head = temp;
	else tail->link = temp;
	tail = temp; tail->link = head;
}
void deQueue(){
    if(head == NULL) {
	    printf("Empty Queue\n");
	    return;
	}
	int val = head->key;
	struct node *temp = head;
	if(head->link == tail->link){
	    free(temp);
	    head = tail = NULL;
	}
    else {
        head = head->link;
        tail->link = head;
        free(temp);
    }
    printf("%d Dequeued\n",val);
}
void display(){
    if(head == NULL) {
	    printf("Empty Queue");
	    return;
	}
    struct node* temp = head;
    do{
        printf("%d ",temp->key);
        temp = temp->link;
    }while(temp!=head);
    printf("\n");
}

int main(){
	int ch,in;
    printf("1. Enqueue\n2. Dequeue\n3. Display\n0. Exit\n");
    while(1){
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        if(ch==1){
            printf("Enter the value : ");
            scanf("%d",&in);
            enQueue(in);
        }
        else if(ch==2) {
            deQueue();
        }
        else if(ch==3) display();
        else if(ch==0) break;
        else printf("Please Enter valid choice\n");
    }
    return 0;
}