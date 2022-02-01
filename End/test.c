#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node {
	int key;
	struct node* link;
};
void display(struct node *list){
    struct node *temp = list;
    while(temp){
        printf("%d ", temp->key);
        temp = temp->link;
    }
    printf("\n");
}

int isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) 
        if (n % i == 0) return 0;
    if (n <= 1) return 0;
    return 1;
}
struct node *split(struct node *list) {
    struct node *temp = list;
    struct node *prime = NULL, *comp = NULL;
    while(temp){
        struct node *new = malloc(sizeof(struct node));
        new->key = temp->key; new->link = NULL;
        if(isPrime(temp->key)) {
            if(prime == NULL) prime = new;
            else{
                struct node *temp_prime = prime;
                while(temp_prime->link) temp_prime = temp_prime->link;
                temp_prime->link = new;
            }
        }
        else {
            if(comp == NULL) comp = new;
            else{
                struct node *temp_comp = comp;
                while(temp_comp->link) temp_comp = temp_comp->link;
                temp_comp->link = new;
            }
        }
        temp = temp->link;
    }
    temp = comp;
    while(temp->link) temp = temp->link;
    temp->link = prime;
    return comp;
}

int main(){
    struct node *list = NULL; int info;
    printf("Enter nodes (-1 to exit) : ");
    do {
        scanf("%d", &info);
        if(info!=-1){
            struct node *new = malloc(sizeof(struct node));
            new->key = info; new->link = NULL;
            struct node *temp = list;
            if(temp == NULL) list = new;
            else{
                while(temp->link) temp = temp->link;
                temp->link = new;
            }
        }
    } while(info!=-1);
    display(list);
    struct node *out = split(list);
    display(out);
    return 0;
}