#include<stdio.h>
#include<stdlib.h>
int n,i,pos;
int *create(int *ar,int x){
    printf("Enter elements : ");
    for(i=0; i<x; i++)
        scanf("%d",ar+i);
    return ar;
}
void print(int *ar){
    for(i=0; i<n; i++)
        printf("%d ",*(ar+i));
}
void swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
void insert(int *ar){
    n++; ar=realloc(ar,n*sizeof(int));
    int new;
    printf("Enter the index and element : ");
    scanf("%d",&pos);
    scanf("%d",&new);
    for(i=0; i<n; i++)
        if(i>=pos)
            swap(&new,ar+i);
    printf("After Insertion : ");
    print(ar);
}
void delete(int *ar){
    printf("Enter the index : ");
    scanf("%d",&pos);
    for(i=0; i<n-1; i++)
        if(i>=pos)
            swap(ar+i,ar+i+1);
    n--; ar=realloc(ar,n*sizeof(int));;
    printf("After Deletion : ");
    print(ar);
}
void search(int *ar){
    printf("Enter element to be searched : ");
    scanf("%d",&pos);
    for(i=0; i<n; i++)
        if(*(ar+i)==pos){
            printf("Found at index : %d",i);
            return;
        }
    printf("Element Not Found");
}
void update(int *ar){
    int new;
    printf("Enter the index and updated value : ");
    scanf("%d",&pos);
    scanf("%d",&new);
    *(ar+pos)=new;
    printf("Updated Array : ");
    print(ar);
}
void reverse(int *ar){
    for(int i=0;i<n/2;i++)
        swap(ar+i,ar+n-1-i);
    printf("Reverse Array : ");
    print(ar);
}
void sort(int *ar){
    for(i=0;i<n;i++){
        int flag=0;
        for(int j=0;j<n-i-1;j++){
            if(ar+j>ar+j+1){
                swap(ar+j, ar+j+1);
                flag=1;
            }
        }
        if(flag==0) break;
    }
    printf("Sorted Array : ");
    print(ar);
}
int merge(int *ar){
    int m, *arr1;
    printf("Enter no. of elements : ");
    scanf("%d",&m);
    arr1=malloc(m*sizeof(int));
    arr1=create(arr1,m);
    i=n; n+=m; 
    ar=realloc(ar,n*sizeof(int));
    for(int j=0;i<n;i++,j++)
        *(ar+i)=*(arr1+j);
    printf("Merged Array : ");
    print(ar);
}
int main(){
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    int ch, *arr=malloc(n*sizeof(int));
    arr=create(arr,n);
    print(arr);
    printf("\n1. Insert an element");
    printf("\n2. Delete an element");
    printf("\n3. Search an element");
    printf("\n4. Update an element");
    printf("\n5. Reverse the array");
    printf("\n6. Sort the array");
    printf("\n7. Merge the array");
    printf("\n0. Exit program");
    while(1){
        printf("\n\nEnter Choice : ");getchar();
        scanf("%d",&ch);
        if(ch==1) insert(arr);
        else if(ch==2) delete(arr);
        else if(ch==3) search(arr);
        else if(ch==4) update(arr);
        else if(ch==5) reverse(arr);
        else if(ch==6) sort(arr);
        else if(ch==7) merge(arr);
        else if(ch==0) break;
        else printf("Wrong Input\n");
    }
    return 0;
}