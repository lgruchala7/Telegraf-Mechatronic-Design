#include "hFramework.h"
#include <stddef.h>
#include <stdio.h>
#include "Lego_Touch.h"
// #include "letters.h"

// #define MAX_SIGNS 50
// #define MAX_LETTERS 10
// #define TIME_UNIT 100

// using namespace hSensors;

// typedef enum {
// 	DOT,
// 	DASH,
// 	SIGN_SPACE,
// 	LETTER_SPACE,
// 	WORD_SPACE,
// 	NEW_LINE,
// 	IDLE_STATE
// } sign_t;

// hLegoSensor_simple ls(hSens5);	//button
// Lego_Touch button(ls);

// hSemaphore readyToDecodeSema;	//semaphores
// hSemaphore readyToWriteSema;

// hMutex dotsAndDashesMutex;	//mutexes
// hMutex lettersMutex;

// hQueue<sign_t> dots_and_dashes(MAX_SIGNS);
// hQueue<char> letters(MAX_LETTERS);

// extern Node_T node5;
// extern Node_T nodeH;                                                     
// extern Node_T node4; 
// extern Node_T nodeS;
// extern Node_T nodeV; 
// extern Node_T node3;                                                          
// extern Node_T nodeI;
// extern Node_T nodeF;       
// extern Node_T nodeU;          
// extern Node_T nodeEmpty1;                              
// extern Node_T node2;                                     
// extern Node_T nodeE;
// extern Node_T nodeL;                      
// extern Node_T nodeR;            
// extern Node_T nodeA;
// extern Node_T nodeP; 
// extern Node_T nodeW;
// extern Node_T nodeJ;
// extern Node_T node1;
// extern Node_T nodeStart;
// extern Node_T node6;
// extern Node_T nodeB;
// extern Node_T nodeD;
// extern Node_T nodeX; 
// extern Node_T nodeN;
// extern Node_T nodeC;  
// extern Node_T nodeK;       
// extern Node_T nodeY;                   
// extern Node_T nodeT;
// extern Node_T node7;                             
// extern Node_T nodeZ;                   
// extern Node_T nodeG;       
// extern Node_T nodeQ;         
// extern Node_T nodeM;                        
// extern Node_T node8;              
// extern Node_T nodeEmpty2;    
// extern Node_T nodeO;
// extern Node_T nodeEmpty3;                
// extern Node_T node9;                                 
// extern Node_T node0;

// void buttonTask(void);
// void decodeTask(void);
// void writeTask(void);

// sign_t whichSpace(uint64_t);
// sign_t whichSign(uint64_t);

// hQueue<sign_t> signs(6);

// void hMain()
// {
// 	sys.taskCreate(&buttonTask);	//create tasks
// 	sys.taskCreate(&writeTask);
// 	sys.taskCreate(&decodeTask);

// 	readyToDecodeSema.take();	//start with semaphore counter equal to 0
// 	readyToWriteSema.take();

// 	for(;;)
// 	{
// 	}
// }


// void buttonTask(void)
// {
// 	sign_t sign;
// 	sign_t space;
// 	bool isButtonPressed, wasButtonPressed;
// 	uint64_t start_time_ms, stop_time_ms, space_time_ms;
// 	uint64_t pressing_time_ms;

// 	wasButtonPressed = false;
// 	pressing_time_ms = 0ull;
// 	stop_time_ms = 0ull;

// 	for (;;)
// 	{
// 		isButtonPressed = button.isPressed();

// 		if (isButtonPressed && !wasButtonPressed)	//button pressed
// 		{
// 			start_time_ms = sys.getRefTime();
// 			space_time_ms = start_time_ms - stop_time_ms;

// 			space = whichSpace(space_time_ms);	//determine space time

// 			dotsAndDashesMutex.take();
// 			dots_and_dashes.sendToBack(space);	//add new data to the queue
// 			dotsAndDashesMutex.give();

// 			if (space >= LETTER_SPACE)
// 			{
// 				readyToDecodeSema.give();	//signal decodeTask about new data
// 			}

// 			wasButtonPressed = true;
// 		}
// 		else if (!isButtonPressed && wasButtonPressed)	//button released
// 		{
// 			stop_time_ms = sys.getRefTime();
// 			pressing_time_ms = stop_time_ms - start_time_ms;	//calculate time of pressing

// 			wasButtonPressed = false;
// 		}
		
// 		if (pressing_time_ms != 0)	//decide what to do depending on the time of pressing
// 		{
// 			sign = whichSign(pressing_time_ms);	//determine typed sign

// 			dotsAndDashesMutex.take();
// 			dots_and_dashes.sendToBack(sign);	//add new data to the queue
// 			dotsAndDashesMutex.give();

// 			// readyToDecodeSema.give();	//signal decodeTask about new data
// 			pressing_time_ms = 0ull;
// 		}

// 		sys.delay_ms(20);	//debouncing
// 	}
	
// }


// void decodeTask(void)
// {
// 	sign_t sign;
// 	// hQueue<sign_t> signs(6);
// 	char letter;

// 	readyToDecodeSema.take();
// 	do {
// 		dots_and_dashes.receive(sign);
// 		signs.sendToBack(sign);
// 	} while (sign <= LETTER_SPACE && (signs.getElementCnt() != 6));	//read until at least end of letter reached 
// 																	//or too many signs sent without break
// 	letter = whichLetter();
// 	lettersMutex.take();
// 	letters.sendToBack(letter);
// 	lettersMutex.give();

// 	signs.flush();
// }


// void writeTask(void)
// {
// 	char letter;
// 	bool new_data;
// 	// readyToWriteSema.take();
// 	while (true)
// 	{
// 		dotsAndDashesMutex.take();
// 		new_data = letters.receive(letter);
// 		dotsAndDashesMutex.give();

// 		if (new_data)
// 		{
// 			write(letter);
// 		}
// 	}
// }


// sign_t whichSpace(uint64_t space_time_ms)
// {
// 	sign_t space;

// 	if (space_time_ms <= (2 * TIME_UNIT))
// 	{
// 		space = SIGN_SPACE;
// 	}
// 	else if (space_time_ms > (2 * TIME_UNIT) && space_time_ms <= (5 * TIME_UNIT))
// 	{
// 		space = LETTER_SPACE;
// 	}
// 	else if (space_time_ms > (5 * TIME_UNIT) && space_time_ms <= (10 * TIME_UNIT))
// 	{
// 		space = WORD_SPACE;
// 	}
// 	else	// > 10*TIME_UNIT
// 	{
// 		space = IDLE_STATE;
// 	}

// 	return space;
// }

// sign_t whichSign(uint64_t pressing_time_ms)
// {
// 	sign_t sign;

// 	if (pressing_time_ms <= (uint64_t)TIME_UNIT)
// 	{
// 		sign = DOT;
// 	}
// 	else if ( (pressing_time_ms > (uint64_t)TIME_UNIT) && (pressing_time_ms <= (uint64_t)(5 * TIME_UNIT)) ) //(3 * TIME_UNIT)) - too short
// 	{
// 		sign = DASH;
// 	}
// 	else	// >(5 * TIME_UNIT)
// 	{
// 		sign = NEW_LINE;
// 	}

// 	return sign;
// }

// char whichLetter()
// {
// 	uint32_t num_of_elements;
// 	sign_t sign;
// 	char letter;

// 	Node_T * node_ptr;

// 	node_ptr = &nodeStart;
// 	num_of_elements = signs.getElementCnt();

// 	for (int i = 0; i < num_of_elements; i++)
// 	{
// 		signs.receive(sign);

// 		switch (sign)
// 		{	
// 			case DOT:
// 				node_ptr = node_ptr->nodeLeft;
// 				break;
// 			case DASH:
// 				node_ptr = node_ptr->nodeRight;
// 				break;
// 			case SIGN_SPACE:
// 				/* do nothing */
// 				break;
// 			case LETTER_SPACE:
// 				/* do nothing */
// 				break;
// 			case WORD_SPACE:
// 				/* do nothing */
// 				break;		
// 			case NEW_LINE:
// 				letter = '\n';
// 				break;
// 			case IDLE_STATE:
// 				/* do nothing */
// 				break;
// 		}
// 	}

// 	if (letter != '\n')
// 		letter = node_ptr->letter;

// 	return letter;
// }

void writeA(void)
{
    hMot1.rotRel(100, 100, false, 0);
}

void hMain()
{
	// while (true) {
		sys.delay_ms(1000);

		hMot2.rotRel(100,100, true, 0);

		// sys.delay_ms(1000);
		while (true){};

		// hMot1.rotRel(-100,100, true, 0);
	// }
}