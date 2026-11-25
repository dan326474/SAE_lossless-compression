#include <stdlib.h>
#include "huffmanlib.h"

#define INITIAL_DICT_CAPACITY 8     //arbitrary

Dictionary *create_dictionary(){
    Dictionary *new_dictionary = malloc(sizeof(Dictionary));
    if (new_dictionary == NULL) return NULL;
    new_dictionary->alphabet = NULL;
    new_dictionary->size = 0;
    new_dictionary->capacity = 0;
    return new_dictionary;
}

void new_entry(Dictionary *dict, char c){
    if (dict->size == dict->capacity) increase_dict(dict);
    if (increase_dict == 1) abort();

    Entry new_char;
    new_char.key = c;
    new_char.val = 1;

    dict->size++;
    dict->alphabet[dict->size] = new_char;
}

int increase_dict(Dictionary *dict){      //if dict full
    size_t new_capacity;
    if (dict->capacity  == 0) new_capacity = INITIAL_DICT_CAPACITY;
    else new_capacity = dict->capacity * 2;     //doubles dict capacity if full AND not a fresh dict
       
    Entry *new_alphabet = realloc(dict->alphabet, new_capacity * sizeof(*dict->alphabet));      //allocs new_capacity to alphabet
       
    if (new_alphabet == NULL) return 1;     //realloc failed; no changes

    dict->alphabet = new_alphabet;
    dict->capacity = new_capacity;

    return 0;
}

int increment(Dictionary *dict, char c){    //if c present in dict
    for (int i = 0; i < dict->size; i++){
        if (dict->alphabet[i].key == c){
            dict->alphabet[i].val++;
            return 1;
        }
    } 
    return 0;   
}

int zip(char *word, Dictionary *dictionary){
    
}