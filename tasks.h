#ifndef TASKS_H
#define TASKS_H

void buttonTask(void);
void decodeTask(void);
void writeTask(void);

#define MAX_SIGNS 50
#define MAX_LETTERS 20
#define TIME_UNIT 100


typedef enum {
	DOT,
	DASH,
	SIGN_SPACE,
	LETTER_SPACE,
	WORD_SPACE,
	NEW_LINE,
} sign_t;

#endif