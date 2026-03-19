#include <cs50.h>
#include <stdio.h>
int coin (int n);
int main(void)
{
    int n;
    do
    {
        n=get_int("Number of coins: ");

    }while (n<=0);
    printf("%i\n", coin(n) );

}
int coin (int n)
{
    int contor=0;
    while (n)
    {
        if (n>=25)
        {
            n-=25;
            contor++;
        }
        else if (n>=10)
        {
            n-=10;
            contor++;
        }
        else if (n>=5)
        {
            n-=5;
            contor++;
        }
        else{
            n-=1;
            contor++;
        }
    }
    return contor;
}
