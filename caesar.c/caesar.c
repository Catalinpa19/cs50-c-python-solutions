#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
string converter(string text,int k);


 int main(int argc,string argv[])
 {
    if(argc!=2)
    {
        printf("Error: too many commands\n");
        return 1;
    }
    for(int i=0;i<strlen(argv[1]);i++){
        if(!isdigit(argv[1][i]))
        {
           printf("Usage: ./caesar key\n");
           return 1;
        }
    }
    if(atoi(argv[1])<0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int k=atoi(argv[1]);
    string text=get_string("plaintext: ");
    printf("ciphertext: %s\n",converter(text,k));
    return 0;

 }
string converter(string text,int k)
{
   string alphU="ABCDEFGHIJKLMNOPQRSTUVWXYZ",alphL="abcdefghijklmnopqrstuvwxyz";
   for (int i=0;i<strlen(text);i++)
   {

      if(isalpha(text[i]))
      {
         for(int j=0;j<strlen(alphU);j++)
         {
            if(text[i]==alphU[j] || text[i]==alphL[j])
            {
                if(islower(text[i]))
                {
                    text[i]=alphL[(j+k)%26];
                }
                else
                {
                    text[i]=alphU[(j+k)%26];

                }
                break;
            }
         }
      }
   }
   return text;
}
