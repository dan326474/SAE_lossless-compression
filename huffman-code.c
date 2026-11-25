#include <stdio.h>
#include <stdlib.h>
#include <error.h>

#define INITIAL_DICT_CAPACITY 8     //arbitrary

typedef struct{
    char *key;
    size_t *val;        //like int; cannot be <0; best use for sizes/counts
}Entry;

typedef struct{
    Entry *alphabet;
    size_t size;
    size_t capacity;
}Dictionary;

Dictionary *create_dictionary();
void new_entry(Dictionary *dict, char c);
int increment(Dictionary *dict, char c);

int zip(char *word, Dictionary *dictionary);

void main(){

    return 0;
}

Dictionary *create_dictionary(){
    Dictionary *new_dictionary = malloc(sizeof(Dictionary));
    if (new_dictionary == NULL) return NULL;
    new_dictionary->alphabet = NULL;
    new_dictionary->size = 0;
    new_dictionary->capacity = 0;
    return new_dictionary;
}

int increment(Dictionary *dict, char c){    //if c present in dict
    for (int i = 0; i < dict->size; i++){
        if (dict->alphabet[i].key == c){
            dict->alphabet[i].val++;
            return 1;
        }
    }

    if (dict->size == dict->capacity){      //dict full
        size_t new_capacity;
        if (dict->capacity  == 0) new_capacity = INITIAL_DICT_CAPACITY;
        else new_capacity = dict->capacity * 2;     //doubles dict capacity if full AND not a fresh dict
        
        Entry *new_alphabet = realloc(dict->alphabet, new_capacity * sizeof(*dict->alphabet));      //allocs new_capacity to alphabet
        
        if (new_alphabet == NULL) return 0;     //realloc failed; no changes

        dict->alphabet = new_alphabet;
        dict->capacity = new_capacity;
    }

    
}

void new_entry(Dictionary *dict, char c){
    Entry new_chara;
    new_chara.key = c;
    new_chara.val = 0;
    
    //tbc
}

int zip(char *word, Dictionary *dictionary){
    
}