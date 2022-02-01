#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
    int expo;
    float coeff;
    struct node *link;
}*t1,*t2,*temp,*new;

void new_node(struct node **ptr,int expo, float coeff){
    if(coeff==0) return;
    new=malloc(sizeof(struct node));
    new->expo=expo; new->coeff=coeff;
    new->link=NULL;
    if(*ptr==NULL){
        *ptr=new;temp=new;
    }else{
        temp->link=new; temp=new;
    }
}
void display(struct node *ptr){
    if(ptr==NULL){
        printf("Empty Polynomial\n");return;
    }
    temp=ptr;
    while(temp){
        float coeff=(temp==ptr)?temp->coeff:fabs(temp->coeff);
        if(temp->expo==0)
            printf("%.2f",coeff);
        else if(temp->expo==1){
            printf((coeff==1)?"x":"%.2fx",coeff);
        }
        else{
            if(coeff==1) printf("x^%d",temp->expo);
            else printf("%.2fx^%d",coeff,temp->expo);
        }
        if(temp=temp->link)
            printf((temp->coeff>=0)?" + ":" - ");
    }
    printf("\n");
}
void sort(struct node **ptr){
    if(ptr==NULL) return;
    struct node *cur; float tc; int tp;
    for(temp=*ptr;temp;temp=temp->link)
		for(cur=temp->link;cur;cur=cur->link)
			if(temp->expo < cur->expo) {
				tc=temp->coeff;
                tp=temp->expo;
                temp->coeff=cur->coeff;
                temp->expo=cur->expo;
                cur->coeff=tc;
                cur->expo=tp;
			}
}
void create(struct node **ptr){
    int expo; float in; temp=*ptr=NULL;
    printf("Input (expo as -1 to exit) : \n");
    while(1){
        //printf("Enter expo : ");
        scanf("%d",&expo);
        if(expo==-1) break;
        //printf("Enter Coeff. : ");
        scanf("%f",&in);
        new_node(ptr,expo,in);
    }
    sort(ptr);
    display(*ptr);
}

struct node *add(struct node *ptr1,struct node *ptr2,int t){
    struct node *sum=malloc(sizeof(struct node));
    t1=ptr1; t2=ptr2; temp=sum=NULL;
    while(t1!=NULL&&t2!=NULL){
        if(t1->expo==t2->expo){
            new_node(&sum,t1->expo,t1->coeff+t*t2->coeff);
            t1=t1->link;
            t2=t2->link;
        }
        else if(t1->expo>t2->expo){
            new_node(&sum,t1->expo,t1->coeff);
            t1=t1->link;
        }
        else{
            new_node(&sum,t2->expo,t*t2->coeff);
            t2=t2->link;
        }
    }
    while(t1!=NULL){
        new_node(&sum,t1->expo,t1->coeff);
        t1=t1->link;
    }
    while(t2!=NULL){
       new_node(&sum,t2->expo,t*t2->coeff);
       t2=t2->link;
    }
    return sum;
}

void remdup(struct node **ptr){
    t1 = *ptr;
    while (t1 && t1->link){
        t2 = t1;
        while (t2->link){
            if (t1->expo==t2->link->expo) {
                t1->coeff = t1->coeff + t2->link->coeff;
                struct node *dup = t2->link;
                t2->link = t2->link->link;
                free(dup);
            }
            else t2 = t2->link;
        }
        t1 = t1->link;
    }
}
struct node *mul(struct node *ptr1,struct node *ptr2){
    struct node *prod=malloc(sizeof(struct node));
    t1=ptr1; temp=prod=NULL;
    while(t1!=NULL){
        t2=ptr2;
        while(t2!=NULL){
            new_node(&prod,t1->expo+t2->expo,(t1->coeff)*(t2->coeff));
            t2=t2->link;
        }
        t1=t1->link;
    }
    remdup(&prod);
    return prod;
}

void divide(struct node *ptr1,struct node *ptr2){
    struct node *quo, *quot, *rem;
    quo=quot=rem=NULL; 
    while(ptr1!=NULL){
        new_node(&rem,ptr1->expo,ptr1->coeff);
        ptr1=ptr1->link;
    }
    while(rem && (rem->expo>=ptr2->expo)){
        int diff=rem->expo-ptr2->expo;
        float mulc=rem->coeff / ptr2->coeff;
        
        struct node *newq=malloc(sizeof(struct node));
        newq->expo=diff; newq->coeff=mulc; newq->link=NULL;
        if(quo==NULL){
            quo=newq; quot=newq;
        }else{
            quot->link=newq; quot=newq;
        }
        
        rem=add(rem,mul(quot,ptr2),-1);
    }
    printf("\nQuotient : ");
    display(quo);
    printf("Remainder : ");
    display(rem);
}

int main(){
    struct node *poly1, *poly2;
    struct node *sum, *sub, *prod; 
    printf("\nPolynomial 1 :\n");
    create(&poly1);
    printf("\nPolynomial 2 :\n");
    create(&poly2);
    
    sum=add(poly1, poly2,1);
    printf("\nSum : ");
    display(sum);

    sub=add(poly1, poly2,-1);
    printf("\nDiff : ");
    display(sub);

    prod=mul(poly1, poly2);
    printf("\nProduct : ");
    display(prod);

    divide(poly1,poly2);
    return 0;
}