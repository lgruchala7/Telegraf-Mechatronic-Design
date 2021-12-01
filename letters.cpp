#include "letters.h"
#include "hFramework.h"

#define WRITELETTER(x) write#x()

// typedef struct {
//       Node_T node5;
// /*            \                                                            */
//               Node_T nodeH;                                                     
// /*            /         \                                                  */
//       Node_T node4;// \   
//                        Node_T nodeS;
// /*                     /       \                                           
// /*                    /         \                                          */
//               Node_T nodeV; //\
// /*            /                   \                                        */
//       Node_T node3;              //\                                          */         
//                                    Node_T nodeI;
// /*                                 /       \                                
// /*                                /         \                              */
//               Node_T nodeF;     //           \       
// /*                    \         /             \
// /*                     \       /               \                            */
//                        Node_T nodeU;          //\
// /*                     /                         \                          
// /*                    /                           \                         */ 
//               Node_T nodeEmpty1;                 //\                        
// /*                  /                               \
// /*                 /                                 \
// /*                /                                   \
// /*               /                                     \
// /*              /                                       \
// /*             /                                         \
// /*            /                                           \                 */
//       Node_T node2;                                      //\
// /*                                                          \               */
//                                                             Node_T nodeE;
// /*                                                          /
// /*                                                         /
// /*                                                        /
// /*                                                       /
// /*                                                      /
// /*                                                     /
// /*                                                    /
// /*                                                   /
// /*                                                  /                       */
//               Node_T nodeL;                       //
// /*                    \                           /
// /*                     \                         /                          */
//                        Node_T nodeR;            //
// /*                             \               /
// /*                              \             /
// /*                               \           /
// /*                                \         /
// /*                                 \       /                                */
//                                    Node_T nodeA;
// /*                                 /
// /*                                /                                         */
//               Node_T nodeP;  //
// /*                    \         /
// /*                     \       /                                            */
//                        Node_T nodeW;
// /*                     /
// /*                    /                                                     */
//               Node_T nodeJ;
// /*            /                                                             */
//       Node_T node1;
//                                                 Node_T nodeStart;
//       Node_T node6;
// /*            \                                                             */
//               Node_T nodeB;
// /*                    \        
// /*                     \                                                    */
//                        Node_T nodeD;
// /*                     /       \
// /*                    /         \                                           */
//               Node_T nodeX; //\
// /*                                \
// /*                                 \                                        */
//                                    Node_T nodeN;
// /*                                 /       \                                
// /*                                /         \                               */
//               Node_T nodeC;  //           \
// /*                    \         /             \ 
// /*                     \       /               \                            */
//                        Node_T nodeK;       //\
// /*                     /                         \
// /*                    /                           \                         */
//               Node_T nodeY;                   //\
// /*                                                  \
// /*                                                   \
// /*                                                    \
// /*                                                     \
// /*                                                      \
// /*                                                       \
// /*                                                        \
// /*                                                         \
// /*                                                          \               */
//                                                             Node_T nodeT;
// /*                                                          /
// /*                                                         /
// /*                                                        /
// /*                                                       /  
// /*                                                      /
// /*                                                     /
// /*                                                    /                     */
//       Node_T node7;                              //
// /*            \                                     /                       */
//               Node_T nodeZ;                   ///
// /*                    \                           /
// /*                     \                         /                          */
//                        Node_T nodeG;       ///
// /*                     /       \               /
// /*                    /         \             /                             */
//               Node_T nodeQ; //\           /
// /*                                \         /
// /*                                 \       /                                */
//                                    Node_T nodeM;                        
//       Node_T node8;               //                                        */
// /*                \               /                                         */                     
//           Node_T nodeEmpty2;    //
// /*                    \         /
// /*                     \       /                                            */
//                        Node_T nodeO;
// /*                     /                         
// /*                    /                                                     */
//          Node_T nodeEmpty3;                
// /*                  /                            
// /*                 /                                                        */
//       Node_T node9;                                 
// /*            \  /                               
// /*             \/                                
// /*             /                                 
// /*            /                                                             */
//       Node_T node0;
// } LetterTree_T;

Node_T nodeStart = {.letter = NULL, .nodeLeft = (Node_T *)&nodeE, .nodeRight = (Node_T *)&nodeT};
Node_T nodeE = {.letter = 'E', .nodeLeft = (Node_T *)&nodeI, .nodeRight = (Node_T *)&nodeA};
Node_T nodeI = {.letter = 'I', .nodeLeft = (Node_T *)&nodeS, .nodeRight = (Node_T *)&nodeU};
Node_T nodeS = {.letter = 'S', .nodeLeft = (Node_T *)&nodeH, .nodeRight = (Node_T *)&nodeV};
Node_T nodeU = {.letter = 'U', .nodeLeft = (Node_T *)&nodeF, .nodeRight = (Node_T *)&nodeEmpty1};
Node_T nodeH = {.letter = 'H', .nodeLeft = (Node_T *)&node5, .nodeRight = (Node_T *)&node4};
Node_T nodeV = {.letter = 'V', .nodeLeft = NULL, .nodeRight = (Node_T *)&node3};
Node_T nodeF = {.letter = 'F', .nodeLeft = NULL, .nodeRight = NULL};
Node_T nodeEmpty1 = {.letter = NULL, .nodeLeft = NULL, .nodeRight = (Node_T *)&node2};
Node_T node5 = {.letter = '5', .nodeLeft = NULL, .nodeRight = NULL};
Node_T node4 = {.letter = '4', .nodeLeft = NULL, .nodeRight = NULL};
Node_T node3 = {.letter = '3', .nodeLeft = NULL, .nodeRight = NULL};
Node_T node2 = {.letter = '2', .nodeLeft = NULL, .nodeRight = NULL};
Node_T nodeA = {.letter = 'A', .nodeLeft = (Node_T *)&nodeR, .nodeRight = (Node_T *)&nodeW};
Node_T nodeR = {.letter = 'R', .nodeLeft = (Node_T *)&nodeL, .nodeRight = NULL};
Node_T nodeW = {.letter = 'W', .nodeLeft = (Node_T *)&nodeP, .nodeRight = (Node_T *)&nodeJ};
Node_T nodeL = {.letter = 'L', .nodeLeft = NULL, .nodeRight = NULL};
Node_T nodeP = {.letter = 'P', .nodeLeft = NULL, .nodeRight = NULL};
Node_T nodeJ = {.letter = 'J', .nodeLeft = NULL, .nodeRight = (Node_T *)&node1};
Node_T node1 = {.letter = '1', .nodeLeft = NULL, .nodeRight = NULL};
Node_T nodeT = {.letter = 'T', .nodeLeft = (Node_T *)&nodeN, .nodeRight = (Node_T *)&nodeM};
Node_T nodeN = {.letter = 'N', .nodeLeft = (Node_T *)&nodeD, .nodeRight = (Node_T *)&nodeK};
Node_T nodeM = {.letter = 'M', .nodeLeft = (Node_T *)&nodeG, .nodeRight = (Node_T *)&nodeO};
Node_T nodeD = {.letter = 'D', .nodeLeft = (Node_T *)&nodeB, .nodeRight = (Node_T *)&nodeX};
Node_T nodeK = {.letter = 'K', .nodeLeft = (Node_T *)&nodeC, .nodeRight = (Node_T *)&nodeY};
Node_T nodeG = {.letter = 'G', .nodeLeft = (Node_T *)&nodeZ, .nodeRight = (Node_T *)&nodeQ};
Node_T nodeO = {.letter = 'O', .nodeLeft = (Node_T *)&nodeEmpty2, .nodeRight = (Node_T *)&nodeEmpty3};
Node_T nodeB = {.letter = 'B', .nodeLeft = (Node_T *)&node6, .nodeRight = NULL};
Node_T nodeX = {.letter = 'X', .nodeLeft = NULL, .nodeRight = NULL};
Node_T nodeC = {.letter = 'C', .nodeLeft = NULL, .nodeRight = NULL};
Node_T nodeY = {.letter = 'Y', .nodeLeft = NULL, .nodeRight = NULL};
Node_T nodeZ = {.letter = 'Z', .nodeLeft = (Node_T *)&node7, .nodeRight = NULL};
Node_T nodeQ = {.letter = 'Q', .nodeLeft = NULL, .nodeRight = NULL};
Node_T nodeEmpty2 = {.letter = NULL, .nodeLeft = (Node_T *)&node8, .nodeRight = NULL};
Node_T nodeEmpty3 = {.letter = NULL, .nodeLeft = (Node_T *)&node9, .nodeRight = (Node_T *)&node0};
Node_T node6 = {.letter = '6', .nodeLeft = NULL, .nodeRight = NULL};
Node_T node7 = {.letter = '7', .nodeLeft = NULL, .nodeRight = NULL};
Node_T node8 = {.letter = '8', .nodeLeft = NULL, .nodeRight = NULL};
Node_T node9 = {.letter = '9', .nodeLeft = NULL, .nodeRight = NULL};
Node_T node0 = {.letter = '0', .nodeLeft = NULL, .nodeRight = NULL};


sign_t whichSpace(uint64_t space_time_ms)
{
	sign_t space;

	if (space_time_ms <= (uint64_t)(2 * TIME_UNIT))
	{
		space = SIGN_SPACE;
	}
	else if (space_time_ms > (uint64_t)(2 * TIME_UNIT) && space_time_ms <= (uint64_t)(5 * TIME_UNIT))
	{
		space = LETTER_SPACE;
	}
	else if (space_time_ms > (uint64_t)(5 * TIME_UNIT))
	{
		space = WORD_SPACE;
	}
	return space;
}


sign_t whichSign(uint64_t pressing_time_ms)
{
	sign_t sign;

	if (pressing_time_ms <= (uint64_t)TIME_UNIT)
	{
		sign = DOT;
	}
	else if ( (pressing_time_ms > (uint64_t)TIME_UNIT) && (pressing_time_ms <= (uint64_t)(5 * TIME_UNIT)) ) //(3 * TIME_UNIT)) - too short
	{
		sign = DASH;
	}
	else if ( (pressing_time_ms > (uint64_t)(5 * TIME_UNIT)) && (pressing_time_ms <= (uint64_t)(10 * TIME_UNIT)) )	// (5 * TIME_UNIT)
	{
		sign = WORD_SPACE;
	}
		else if ( (pressing_time_ms > (uint64_t)(10 * TIME_UNIT)) && (pressing_time_ms <= (uint64_t)(15 * TIME_UNIT)) )	// (5 * TIME_UNIT)
	{
		sign = NEW_LINE;
	}

	return sign;
}


char whichLetter(hQueue<sign_t> signs)
{
	uint32_t num_of_elements;
	sign_t sign;
	char letter;

	Node_T * node_ptr;

	node_ptr = &nodeStart;
	num_of_elements = signs.getElementCnt();

	for (uint32_t i = 0; i < num_of_elements; i++)
	{
		signs.receive(sign);

		switch (sign)
		{	
			case DOT:
				node_ptr = (Node_T *)node_ptr->nodeLeft;
				break;
			case DASH:
				node_ptr = (Node_T *)node_ptr->nodeRight;
				break;
			case WORD_SPACE:
				letter = ' ';
				break;		
			case NEW_LINE:
				letter = '\n';
				break;
			case SIGN_SPACE:
			case LETTER_SPACE:
			default:
				/* do nothing */
				break;
		}

		if (node_ptr == nullptr)
			return NULL;
	}

	letter = node_ptr->letter;
	return letter;
}


void write(const char letter)
{
    // WRITELETTER(letter);
}


void writeA(void)
{
    hMot1.rotRel(100, 100, false, 0);
}

void writeB(void)
{

}