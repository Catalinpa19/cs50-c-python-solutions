// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 17576;

// Hash table
node *table[N]={NULL};

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    if(table[hash(word)]!=NULL){
       if(strcasecmp(table[hash(word)]->word,word)==0){
          return true;
       }
      else
      {
        node* temp=table[hash(word)]->next;
        while(temp!=NULL)
        {
            if(strcasecmp(temp->word,word)==0)
            {
                return true;
            }
            temp=temp->next;

        }
      }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int sum=1;
    for(int i=0;i<3;++i)
    {
        if(word[i]=='\0')
        {
            return sum;
        }
        sum*=(toupper(word[i]) - 'A')%26;
    }
    return sum;
}

// Loads dictionary into memory, returning true if successful, else false

bool load(const char *dictionary)
{
    FILE *f = fopen(dictionary, "r");
    if (f == NULL)
        return false;

    char word[LENGTH + 1];
    while (fscanf(f, "%45s", word) != EOF)
    {
        unsigned int h = hash(word);

        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(f);
            return false;
        }
        strcpy(new_node->word, word);
        new_node->next = table[h];
        table[h] = new_node;
    }

    fclose(f);
    return true;
}


// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int size=0;
        for(int i=0;i<N;++i)
        {
            node* temp=table[i];

            while(temp!=NULL)
            {
                size++;
                temp=temp->next;
            }
        }


    return size;

}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for(int i=0;i<N;++i)
    {
        while(table[i]!=NULL)
        {
             node* temp=table[i];
             table[i]=table[i]->next;
             free(temp);

        }

    }

    return true;
}
