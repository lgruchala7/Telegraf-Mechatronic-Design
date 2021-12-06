#define DEBUG_MODE

// #define TEST
#ifndef TEST


#include "hFramework.h"
#include <stdio.h>
#include "Lego_Touch.h"
#include "letters.h"
#include "tasks.h"

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
	bool ishButton1Pressed, ishButton2Pressed, washButton1Pressed, washButton2Pressed;
	uint64_t start_time_ms, stop_time_ms, space_time_ms;
	uint64_t pressing_time_ms;

	wasButtonPressed = false;
	washButton1Pressed = false;
	washButton2Pressed = false;
	pressing_time_ms = 0ull;
	stop_time_ms = 0ull;

	for (;;)
	{
		isButtonPressed = button.isPressed();
		ishButton1Pressed = hBtn1.isPressed();
		ishButton2Pressed = hBtn2.isPressed();

		if (isButtonPressed && !wasButtonPressed)	//button pressed (rising edge)
		{
			start_time_ms = sys.getRefTime();
			space_time_ms = start_time_ms - stop_time_ms;

			space = whichSpace(space_time_ms);	//determine space time

			#ifdef DEBUG_MODE
			// printf("\n\nSpace: %d\n\r", (int)space);
			// printf("Stop time: %d ms\n\r", (int)stop_time_ms);
			// printf("dots_and_dashes count: %d\n\r", (int)dots_and_dashes.getElementCnt());
			#endif

			if (space >= LETTER_SPACE && (stop_time_ms != 0u))
			{
				dotsAndDashesMutex.take(0);
				dots_and_dashes.sendToBack(space);	//add new data to the queue
				dotsAndDashesMutex.give();

				#ifdef DEBUG_MODE
				if (sign == LETTER_SPACE)
					printf("letter space\n\r");
				else if (sign == WORD_SPACE)
					printf("word space\n\r");
				#endif

				readyToDecodeSema.give();	//signal decodeTask about new letter available

				printf("BUTTON_TASK: ");
			}

			wasButtonPressed = true;
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

		// if (ishButton1Pressed && !washButton1Pressed)
		// {
		// 	dotsAndDashesMutex.take(0);
		// 	dots_and_dashes.sendToBack(WORD_SPACE);	//add new data to the queue
		// 	dotsAndDashesMutex.give();

		// 	washButton1Pressed = ishButton1Pressed;
		// }
		// else if (ishButton2Pressed && !washButton2Pressed)
		// {
		// 	dotsAndDashesMutex.take(0);
		// 	dots_and_dashes.sendToBack(NEW_LINE);	//add new data to the queue
		// 	dotsAndDashesMutex.give();

		// 	washButton2Pressed = ishButton2Pressed;
		// }

		if (pressing_time_ms != 0)	//decide what to do depending on the time of pressing
		{
			sign = whichSign(pressing_time_ms);	//determine input sign (dot/dash)

			dotsAndDashesMutex.take(0);
			dots_and_dashes.sendToBack(sign);	//add new data to the queue
			dotsAndDashesMutex.give();

			#ifdef DEBUG_MODE
			// printf("Pressing time: %d ms\n\r", (int)pressing_time_ms);
			printf("BUTTON_TASK: ");
			if (sign == DOT)
				printf(". ");
			else if (sign == DASH)
				printf("- ");
			else if (sign == WORD_SPACE)
				printf("word space ");
			else if (sign == NEW_LINE)
				printf("\\n");

				printf("\npressing time = %d\n", (int)pressing_time_ms);
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
		if (readyToDecodeSema.take(0))
		{
			#ifdef DEBUG_MODE
			printf("\nDECODE_TASK: ");
			#endif
			
			do {	
				do {
				dotsAndDashesMutex.take(0);
				dots_and_dashes.receive(sign);
				// dotsAndDashesMutex.give();

				#ifdef DEBUG_MODE
				if (sign == DOT)
					printf(". ");
				else if (sign == DASH)
					printf("- ");
				else if (sign == LETTER_SPACE)
					printf("letter space ");
				#endif

				lettersMutex.take(0);
				signs.sendToBack(sign);
				lettersMutex.give();
				} while (sign < LETTER_SPACE && (signs.getElementCnt() < 7));	//read until at least end of letter reached 
																				//or too many signs sent without break
				letter = whichLetter();

				#ifdef DEBUG_MODE
				printf("\nLetter: %c\n\n\r", letter);
				#endif

				if (letter != (char)0)
				{
					lettersMutex.take(0);
					letters.sendToBack(letter);
					lettersMutex.give();
					#ifdef DEBUG_MODE
					printf("Sending letter to write\n");
					#endif
					readyToWriteSema.give();
				}

				#ifdef DEBUG_MODE
				else
					printf("\nERROR\n\n\r");
				#endif

				signs.flush();
			} while((int)dots_and_dashes.getElementCnt() > 0);

			dotsAndDashesMutex.give();
		}
	}
}


void writeTask(void)
{
	char letter;
	int letters_in_a_row = 0;

	for (;;)
	{
		if (readyToWriteSema.take(0))
		{
			lettersMutex.take(0);
			letters.receive(letter);	// read decoded letters from the queue
			lettersMutex.give();

			write(letter);
			++letters_in_a_row;
			
			if (letter == ' ')
			{
				/* do nothing */
			}
			else if (letter == '\n')
			{
				letters_in_a_row = 0u;
			}
			else if (letters_in_a_row == 5)
			{
				write('\n');
				letters_in_a_row = 0u;
			}
			else
			{
				writeSpace();
			}
		}
	}
}

#endif