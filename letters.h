#ifndef LETTERS_H
#define LETTERS_H

#include "hFramework.h"
#include "tasks.h"

typedef struct 
{
    char letter;
    void * nodeLeft;
    void * nodeRight;
} Node_T;

void initLetterNodes(void);

sign_t whichSpace(uint64_t space_time_ms);
sign_t whichSign(uint64_t pressing_time_ms);
char whichLetter(void);

void write(const char letter);

#endif