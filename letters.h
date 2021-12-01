#ifndef LETTERS_H
#define LETTERS_H

#include "hFramework.h"
#include "tasks.h"

struct Node_T 
{char letter;
 void * nodeLeft;
 void * nodeRight;
};

sign_t whichSpace(uint64_t space_time_ms);
sign_t whichSign(uint64_t pressing_time_ms);
char whichLetter(hQueue<sign_t> signs);

void write(const char letter);

#endif