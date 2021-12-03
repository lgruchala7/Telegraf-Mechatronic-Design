#define DEBUG_MODE

// #define TEST
#ifndef TEST


#include "hFramework.h"
#include <stdio.h>
#include "Lego_Touch.h"
#include "letters.h"
#include "tasks.h"

#define MAX_SIGNS 50
#define MAX_LETTERS 10
#define TIME_UNIT 100

using namespace hSensors;

hLegoSensor_simple ls(hSens5);	//button
Lego_Touch button(ls);

hSemaphore readyToDecodeSema;	//semaphores
hSemaphore readyToWriteSema;

hMutex dotsAndDashesMutex;	//mutexes
hMutex lettersMutex;
hMutex signsMutex;

hQueue<sign_t> dots_and_dashes(MAX_SIGNS);
hQueue<char> letters(MAX_LETTERS);

hQueue<sign_t> signs(7);

void buttonTask(void)
{
	sign_t sign;
	sign_t space;
	bool isButtonPressed, wasButtonPressed;
	uint64_t start_time_ms, stop_time_ms, space_time_ms;
	uint64_t pressing_time_ms;

	wasButtonPressed = false;
	pressing_time_ms = 0ull;
	stop_time_ms = 0ull;

	for (;;)
	{
		isButtonPressed = button.isPressed();

		if (isButtonPressed && !wasButtonPressed)	//button pressed (rising edge)
		{
			start_time_ms = sys.getRefTime();
			space_time_ms = start_time_ms - stop_time_ms;

			space = whichSpace(space_time_ms);	//determine space time

			if (space >= LETTER_SPACE)
			{
				dotsAndDashesMutex.take();
				dots_and_dashes.sendToBack(space);	//add new data to the queue
				dotsAndDashesMutex.give();

			#ifdef DEBUG_MODE
			printf("Space: %d\n\r", (int)space);
			#endif

			readyToDecodeSema.give();	//signal decodeTask about new letter available
			}

			wasButtonPressed = true;
			#ifdef DEBUG_MODE
			// printf("Button pressed\n\r");
			#endif
		}
		else if (!isButtonPressed && wasButtonPressed)	//button not pressed (falling edge)
		{
			stop_time_ms = sys.getRefTime();
			pressing_time_ms = stop_time_ms - start_time_ms;	//calculate pressing time

			wasButtonPressed = false;
			#ifdef DEBUG_MODE
			// printf("Button released\n\r");
			#endif
		}

		if (pressing_time_ms != 0)	//decide what to do depending on the time of pressing
		{
			sign = whichSign(pressing_time_ms);	//determine input sign (dot/dash)

			dotsAndDashesMutex.take();
			dots_and_dashes.sendToBack(sign);	//add new data to the queue
			dotsAndDashesMutex.give();

			#ifdef DEBUG_MODE
			printf("Pressing time: %d ms\n\r", (int)pressing_time_ms);
			printf("Sign: %d\n\r", (int)sign);
			#endif
			// readyToDecodeSema.give();	//signal decodeTask about new data
			pressing_time_ms = 0ull;
		}
		
		sys.delay(20);	//debouncing
	}
	
}


void decodeTask(void)
{
	sign_t sign;
	char letter;

	#ifdef DEBUG_MODE
	printf("Decoding 1\n");
	#endif
for(;;)
{
	// readyToDecodeSema.take();
	if (dots_and_dashes.getElementCnt() != 0u)
{	do 
	{
		dotsAndDashesMutex.take();
		dots_and_dashes.receive(sign);
		dotsAndDashesMutex.give();

		lettersMutex.take();
		signs.sendToBack(sign);
		lettersMutex.give();
		#ifdef DEBUG_MODE
		printf("Decoding 2\n");
		#endif
	} while (sign < LETTER_SPACE && (signs.getElementCnt() < 7));	//read until at least end of letter reached 
																	//or too many signs sent without break
	letter = whichLetter();

	#ifdef DEBUG_MODE
	printf("Letter: %c\n\n\r", letter);
	#endif

	if (letter != (char)NULL)
	{
		lettersMutex.take();
		letters.sendToBack(letter);
		lettersMutex.give();
	}

	signs.flush();
}
}
}


void writeTask(void)
{
	char letter;
	bool new_data;
	uint8_t letters_in_a_row = 0u;

	for (;;)
	{
		dotsAndDashesMutex.take();
		new_data = letters.receive(letter);	// read decoded letters from the queue
		dotsAndDashesMutex.give();

		if (new_data)		//start writing if new letters available
		{
			write(letter);
			if (letters_in_a_row == 5u)
			{
				write('\n');
				letters_in_a_row = 0u;
			}
			++letters_in_a_row;
		}
	}
}

#endif