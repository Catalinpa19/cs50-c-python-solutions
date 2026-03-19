#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int check(string text);
string substitution(string text,string cipher);
int main(int argc,string argv[])
{
    if(argc!=2 || strlen(argv[1])!=26 || !check(argv[1]))
    {
        printf("Error: wrong declaration of key\n");
        return 1;
    }
    string text=get_string("blanktext: ");
    printf("ciphertext: %s\n",substitution(text,argv[1]));

}
int check(string text)
{
    char alphU[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char alphL[]="abcdefghijklmnopqrstuvwxyz";
    for(int i=0;i<strlen(text);i++)
    {
        if(!isalpha(text[i]))
        {
           return 0;
        }
        else
        {
          for(int j=0;j<strlen(alphU);j++)
          {
              if(toupper(text[i])==alphU[j]){
                 alphU[j]='0';
              }
          }
        }
    }
    for(int i=0;i<strlen(alphU);i++)
    {
        if(alphU[i]!='0')
        {
            return 0;
        }
    }
    return 1;
}
string substitution(string text,string cipher)
{
    char alphU[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char alphL[]="abcdefghijklmnopqrstuvwxyz";


    for (int i=0;i<strlen(text);i++)
    {
       for (int j=0;j<strlen(alphU);j++)
       {
         if(text[i]==alphU[j] || text[i]==alphL[j])
         {
            text[i]=cipher[j];
            break;
         }
       }
    }
    return text;
}
