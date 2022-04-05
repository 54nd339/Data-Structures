<<<<<<< HEAD
#include <stdio.h>
void towerOfHanoi(int n, char from, char aux, char to){
    if (n > 0){
        towerOfHanoi(n-1, from, to, aux);
        printf("Move disk 1 from rod %c to rod %c\n", from, to);
        towerOfHanoi(n-1, aux, from, to);
    }
}
int main(){
    printf("Enter No. of disks : ");
    int n; scanf("%d", &n);
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
=======
#include <stdio.h>
  
void towerOfHanoi(int n, char from, char aux, char to){
    if (n > 0){
        towerOfHanoi(n-1, from, to, aux);
        printf("Move disk 1 from rod %c to rod %c\n", from, to);
        towerOfHanoi(n-1, aux, from, to);
    }
}
  
int main(){
    int n;
    printf("Enter No. of disks : ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
>>>>>>> c14086eac1b9db45c2ade3ab55c20ad590ceb675
}