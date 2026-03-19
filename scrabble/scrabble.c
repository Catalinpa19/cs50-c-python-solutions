#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

string score(string player1,string player2);

int main(void)
{
   string player1=get_string("Word1: ");
   string player2=get_string("Word2: ");
   printf("%s\n", score(player1,player2));
}
string score(string player1,string player2)
{
    int v[30]={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
    int score1=0,score2=0;
    for (int i=0;i<strlen(player1);i++)
    {
        player1[i]=toupper(player1[i]);
        if(player1[i]>='A' && player1[i]<='Z')
        {
            score1+=v[player1[i]-'A'];
        }
    }
    for (int i=0;i<strlen(player2);i++)
    {
        player2[i]=toupper(player2[i]);
        if(player2[i]>='A' && player2[i]<='Z')
        {
            score2+=v[player2[i]-'A'];
        }
    }
    if(score1>score2){
        return "Player1 wins!";
    }
    else if(score2>score1)
    {
       return "Player2 wins!";
    }
    else
    {
        return "Tie!";
    }
}
