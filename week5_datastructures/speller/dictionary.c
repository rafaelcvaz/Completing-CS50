// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

int n_words; // Setting a global variable to count how many words are in the dictionary.

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table. I chose 45 because I'm creating a hash table organized by the lenght of the words. The maximum lenght is 45 considering the word pneumonoultramicroscopicsilicovolcanoconiosis.
const unsigned int N = 45;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash word to obtain a hash value
    int index = hash(word);

    // Access the linked list through the index provided by the hash function
    node *cursor = table[index]; // Set pointer to iterate over dictionary

    while (cursor != NULL)
    {
        // Tranverse linked list looking for the word
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next; 
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    return strlen(word) - 1;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *source = fopen(dictionary, "r");
    
    if (source == NULL)
    {
        return false;
    }

    char new_word[LENGTH + 1]; // Variable to store individual words as we go through the dictionary

    // Read strings from file one at a time until the file is over
    while (fscanf(source, "%s", new_word) != EOF)
    {

        // Create a new node for each string
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, new_word);
        n->next = NULL;
        n_words++;

        // Hash word to obtain a hash value
        int index = hash(new_word);

        // Insert node at hash table at the correct location 
        n->next = table[index]; // Points the new node's pointer to the first element of the linked list at the specific index
        table[index] = n; // Points the head pointer to the new node
    }

    fclose(source);   
    return true;  
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (n_words == 0)
    {
        return 0;
    }
    else
    {
        return n_words;        
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    int del_words = 0;
    //For all indexes of the hash table
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        node *tmp = cursor;

        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            del_words++;
            tmp = cursor;
        }
    }
    
    if (del_words == n_words)
    {
        return true;
    }
    else
    {
        return false;
    }
}
