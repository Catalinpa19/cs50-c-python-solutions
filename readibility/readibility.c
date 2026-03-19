#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float letters(string text);
float sentences(string text);
float words(string text);


int main(void)
{
   string text=get_string("Get a text: ");
   float nrletters=letters(text),nrsentences=sentences(text),nrwords=words(text);
   float index= (0.0588 * ((nrletters*100)/nrwords))-(0.296*((nrsentences*100)/nrwords)) - 15.8;
   printf("Grade: ");
   index=round(index);
   if(index>=16)
   {
       printf("16+\n");
   }
   else if(index<1)
   {
       printf("less than 1\n");
   }
   else
   {
       printf("%f\n",index);
   }
   return 0;
}
float letters(string text){
    int nrletters=0;
    for (int i=0;i<strlen(text);i++){
        if(isalpha(text[i]))
        {
           nrletters++;
        }

    }
    return nrletters;
}
float sentences(string text){
    int nrsentences=0;
    for (int i=0;i<strlen(text);i++)
    {
        if(text[i]=='?' || text[i]=='!' || text[i]=='.'){
            nrsentences++;
        }
    }
    return nrsentences;
}
float words(string text)
{
    int nrwords=1;
    for(int i=0;i<strlen(text);i++){
        if(text[i]==' ' && isalpha(text[i+1])){
            nrwords++;
        }
    }
    return nrwords;
}
