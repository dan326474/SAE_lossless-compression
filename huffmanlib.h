#ifndef HUFFMANLIB_H
#define HUFFMANLIB_H

#include <stddef.h>

typedef struct {
    char *key;
    size_t *val;        //like int; cannot be <0; best use for sizes/counts
} Entry;

typedef struct {
    Entry *alphabet;
    size_t size;
    size_t capacity;
} Dictionary;

Dictionary *create_dictionary();
void new_entry(Dictionary *dict, char c);
int increment(Dictionary *dict, char c);
int increase_dict(Dictionary *dict);
int zip(char *word, Dictionary *dictionary);

#endif