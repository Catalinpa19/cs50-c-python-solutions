#include <stdio.h>
#include <cs50.h>
int main(void){
    int n;
    do{
        n=get_int("Height: ");

    }while (n<=0);
    int copn=1,copn1=n-1;
    for (int i=1;i<=n;i++){
        for(int j=1;j<=copn1;j++){
            printf(" ");
        }
        for(int k=1;k<=copn;k++){
            printf("#");
        }
        printf(" ");
        printf(" ");
        for(int k=1;k<=copn;k++){
            printf("#");
        }
        copn++;
        copn1--;
        printf("\n");
    }
}
