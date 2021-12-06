#ifndef LETTERS_H
#define LETTERS_H

#include "hFramework.h"
#include "tasks.h"

#define LONG_V_DASH 360 // V stands for vertical and H for horizntal
#define V_DASH 180
#define LONG_H_DASH 500
#define H_DASH 250
#define POWER 300
#define MOVE_DOWN 1
#define MOVE_UP -1
#define MOVE_LEFT 1
#define MOVE_RIGHT -1
#define UP_POWER 300
#define TIMEOUT 1000
#define TAKE_UP -100
#define TAKE_DOWN 100

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

void writeSpace(void);
void writeBigSpace(void);
void lineFeed(void);

void writeA(void);
void writeB(void);
void writeC(void);
void writeD(void);
void writeE(void);
void writeF(void);
void writeG(void);
void writeH(void);
void writeI(void);
void writeJ(void);
void writeK(void);
void writeL(void);
void writeM(void);
void writeN(void);
void writeO(void);
void writeP(void);
void writeR(void);
void writeS(void);
void writeT(void);
void writeU(void);
void writeV(void);
void writeW(void);
void writeX(void);
void writeY(void);
void writeZ(void);

#endif