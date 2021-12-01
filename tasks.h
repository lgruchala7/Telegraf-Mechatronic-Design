#ifndef TASKS_H
#define TASKS_H

#define MAX_SIGNS 50
#define MAX_LETTERS 10
#define TIME_UNIT 100

void buttonTask(void);
void decodeTask(void);
void writeTask(void);

typedef enum {
	DOT,
	DASH,
	SIGN_SPACE,
	LETTER_SPACE,
	WORD_SPACE,
	NEW_LINE,
	IDLE_STATE
} sign_t;

#endif