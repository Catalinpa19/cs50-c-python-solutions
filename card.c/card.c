#include <stdio.h>
#include <cs50.h>
bool card(long long n);
int main(void){
    long long n;
    do{
        n=get_long("Card number: ");
    }while (n<=0);
    if (card(n))
    {
       while (n>99)
       {
         n/=10;
       }
       if ((n==51) || (n==52) || (n==53) || (n==54) || (n==55)){
                printf("MASTERCARD\n");
       }
       else if ((n==34) || (n==37)){
                printf("AMEX\n");
       }else{
                printf("VISA\n");

       }
    }
    else
    {
           printf("INVALID\n");
    }

}
bool card(long long n)
{
    if(n<=999999999999){
        return false;
    }
    int poz=0,sum1=0,sum2=0;
    while (n!=0)
    {
       if (poz%2==0)
       {
           sum1+=n%10;
       }
       else
       {
           sum2+=(((n%10)*2)%10+((n%10)*2)/10);
       }
       n/=10;
       poz++;
    }
    if ((sum1+sum2)%10==0) {
        return true;
    }
    else{
        return false;
    }

}

