#include "hFramework.h"
#include <stddef.h>
#include <stdio.h>
#include "Lego_Touch.h"
#include "tasks.h"

#define DEBUG_MODE

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


extern hSemaphore readyToDecodeSema;	//semaphores
extern hSemaphore readyToWriteSema;

void hMain()
{
	sys.taskCreate(&buttonTask);	//create tasks
	sys.taskCreate(&writeTask);
	sys.taskCreate(&decodeTask);

	readyToDecodeSema.take();	//start with semaphore counter equal to 0
	readyToWriteSema.take();

	for(;;)
	{
	}
}



// sign_t whichSpace(uint64_t space_time_ms)
// {
// 	sign_t space;

// 	if (space_time_ms <= (uint64_t)(2 * TIME_UNIT))
// 	{
// 		space = SIGN_SPACE;
// 	}
// 	else if (space_time_ms > (uint64_t)(2 * TIME_UNIT) && space_time_ms <= (uint64_t)(5 * TIME_UNIT))
// 	{
// 		space = LETTER_SPACE;
// 	}
// 	else if (space_time_ms > (uint64_t)(5 * TIME_UNIT))
// 	{
// 		space = WORD_SPACE;
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
// 	else if ( (pressing_time_ms > (uint64_t)(5 * TIME_UNIT)) && (pressing_time_ms <= (uint64_t)(10 * TIME_UNIT)) )	// (5 * TIME_UNIT)
// 	{
// 		sign = WORD_SPACE;
// 	}
// 		else if ( (pressing_time_ms > (uint64_t)(10 * TIME_UNIT)) && (pressing_time_ms <= (uint64_t)(15 * TIME_UNIT)) )	// (5 * TIME_UNIT)
// 	{
// 		sign = NEW_LINE;
// 	}

// 	return sign;
// }

// char whichLetter(hQueue<sign_t> signs)
// {
// 	uint32_t num_of_elements;
// 	sign_t sign;
// 	char letter;

// 	Node_T * node_ptr;

// 	node_ptr = &nodeStart;
// 	num_of_elements = signs.getElementCnt();

// 	for (uint32_t i = 0; i < num_of_elements; i++)
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
// 			case WORD_SPACE:
// 				letter = ' ';
// 				break;		
// 			case NEW_LINE:
// 				letter = '\n';
// 				break;
// 			case SIGN_SPACE:
// 			case LETTER_SPACE:
// 			default:
// 				/* do nothing */
// 				break;
// 		}

// 		if (*node_ptr == NULL)
// 			return NULL
// 	}

// 	letter = node_ptr->letter;
// 	return letter;
// }

// void writeA(void)
// {
//     hMot1.rotRel(100, 100, false, 0);
// }

// void hMain()
// {
// 	// while (true) {
// 		sys.delay_ms(1000);

// 		hMot2.rotRel(100,100, true, 0);

// 		// sys.delay_ms(1000);
// 		while (true){};

// 		// hMot1.rotRel(-100,100, true, 0);
// 	// }
// }