#include <stdio.h>
#include <cs50.h>

int main(void){

   int v[]={1,3,4,6,5,7};
   for(int i=0;i<5;i++)
   {
      for(int j=i+1;j<6;j++)
      {
         if(v[i]>v[j])
         {
            int swap;
            swap=v[i];
            v[i]=v[j];
            v[j]=swap;
         }
      }
   }
   for(int i=0;i<6;i++)
   {
      printf("%d ",v[i]);
   }
}

