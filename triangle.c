#include <stdio.h>
#include <cs50.h>

int triangle(int a,int b ,int c);

int main(void)
{
    int a=get_int("Nr: "),b=get_int("Nr2: "),c=get_int("Nr3: ");
    if(triangle(a,b,c))
    {
        printf("It's a triangle\n");
    }
    else
    {
        printf("It's not a triangle\n");
    }
}
int triangle(int a,int b,int c)
{
    if((a<=0 || b<=0 || c<=0) || (a+b<c || a+c<b || c+b<a))
    {
      return 0;
    }
    else
    {
        return 1;
    }
}
