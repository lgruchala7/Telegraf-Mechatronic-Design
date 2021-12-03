// #define TEST

#ifndef TEST

#include "letters.h"
#include "hFramework.h"

#define WRITELETTER(x) write#x()

extern hQueue<sign_t> signs;

// Node_T nodeStart = {NULL, NULL, NULL};    Node_T nodeE = {NULL, NULL, NULL};        Node_T nodeI = {NULL, NULL, NULL};
// Node_T nodeS = {NULL, NULL, NULL};        Node_T nodeU = {NULL, NULL, NULL};        Node_T nodeH = {NULL, NULL, NULL};
// Node_T nodeV = {NULL, NULL, NULL};        Node_T nodeF = {NULL, NULL, NULL};        Node_T nodeEmpty1 = {NULL, NULL, NULL};
// Node_T node5 = {NULL, NULL, NULL};        Node_T node4 = {NULL, NULL, NULL};        Node_T node3 = {NULL, NULL, NULL};
// Node_T node2 = {NULL, NULL, NULL};        Node_T nodeA = {NULL, NULL, NULL};        Node_T nodeR = {NULL, NULL, NULL};
// Node_T nodeW = {NULL, NULL, NULL};        Node_T nodeL = {NULL, NULL, NULL};        Node_T nodeP = {NULL, NULL, NULL};
// Node_T nodeJ = {NULL, NULL, NULL};        Node_T node1 = {NULL, NULL, NULL};        Node_T nodeT = {NULL, NULL, NULL};
// Node_T nodeN = {NULL, NULL, NULL};        Node_T nodeM = {NULL, NULL, NULL};        Node_T nodeD = {NULL, NULL, NULL};
// Node_T nodeK = {NULL, NULL, NULL};        Node_T nodeG = {NULL, NULL, NULL};        Node_T nodeO = {NULL, NULL, NULL};
// Node_T nodeB = {NULL, NULL, NULL};        Node_T nodeX = {NULL, NULL, NULL};        Node_T nodeC = {NULL, NULL, NULL};
// Node_T nodeY = {NULL, NULL, NULL};        Node_T nodeZ = {NULL, NULL, NULL};        Node_T nodeQ = {NULL, NULL, NULL};
// Node_T nodeEmpty2 = {NULL, NULL, NULL};   Node_T nodeEmpty3 = {NULL, NULL, NULL};   Node_T node6 = {NULL, NULL, NULL};
// Node_T node7 = {NULL, NULL, NULL};        Node_T node8 = {NULL, NULL, NULL};        Node_T node9 = {NULL, NULL, NULL};
// Node_T node0 = {NULL, NULL, NULL};  

Node_T nodeStart;    Node_T nodeE;        Node_T nodeI;
Node_T nodeS;        Node_T nodeU;        Node_T nodeH;
Node_T nodeV;        Node_T nodeF;        Node_T nodeEmpty1;
Node_T node5;        Node_T node4;        Node_T node3;
Node_T node2;        Node_T nodeA;        Node_T nodeR;
Node_T nodeW;        Node_T nodeL;        Node_T nodeP;
Node_T nodeJ;        Node_T node1;        Node_T nodeT;
Node_T nodeN;        Node_T nodeM;        Node_T nodeD;
Node_T nodeK;        Node_T nodeG;        Node_T nodeO;
Node_T nodeB;        Node_T nodeX;        Node_T nodeC;
Node_T nodeY;        Node_T nodeZ;        Node_T nodeQ;
Node_T nodeEmpty2;   Node_T nodeEmpty3;   Node_T node6;
Node_T node7;        Node_T node8;        Node_T node9;
Node_T node0;  

void initLetterNodes(void)
{
  nodeStart = 	{.letter = (char)NULL, 	    .nodeLeft = (Node_T *)&nodeE, 		  .nodeRight = (Node_T *)&nodeT};
  nodeE = 		  {.letter = 'E', 	          .nodeLeft = (Node_T *)&nodeI, 		  .nodeRight = (Node_T *)&nodeA};
  nodeI = 		  {.letter = 'I', 	          .nodeLeft = (Node_T *)&nodeS, 		  .nodeRight = (Node_T *)&nodeU};
  nodeS = 		  {.letter = 'S', 	          .nodeLeft = (Node_T *)&nodeH, 		  .nodeRight = (Node_T *)&nodeV};
  nodeU = 		  {.letter = 'U', 	          .nodeLeft = (Node_T *)&nodeF, 		  .nodeRight = (Node_T *)&nodeEmpty1};
  nodeH = 		  {.letter = 'H', 	          .nodeLeft = (Node_T *)&node5, 		  .nodeRight = (Node_T *)&node4};
  nodeV = 		  {.letter = 'V', 	          .nodeLeft = NULL, 					        .nodeRight = (Node_T *)&node3};
  nodeF = 		  {.letter = 'F', 	          .nodeLeft = NULL, 					        .nodeRight = NULL};
  nodeEmpty1 =  {.letter = (char)NULL, 	    .nodeLeft = NULL, 					        .nodeRight = (Node_T *)&node2};
  node5 = 		  {.letter = '5', 	          .nodeLeft = NULL, 					        .nodeRight = NULL};
  node4 = 		  {.letter = '4', 	          .nodeLeft = NULL, 					        .nodeRight = NULL};
  node3 = 		  {.letter = '3', 	          .nodeLeft = NULL, 					        .nodeRight = NULL};
  node2 = 		  {.letter = '2', 	          .nodeLeft = NULL, 					        .nodeRight = NULL};
  nodeA = 		  {.letter = 'A', 	          .nodeLeft = (Node_T *)&nodeR, 		  .nodeRight = (Node_T *)&nodeW};
  nodeR = 	  	{.letter = 'R', 	          .nodeLeft = (Node_T *)&nodeL, 		  .nodeRight = NULL};
  nodeW = 	  	{.letter = 'W', 	          .nodeLeft = (Node_T *)&nodeP, 		  .nodeRight = (Node_T *)&nodeJ};
  nodeL = 	  	{.letter = 'L', 	          .nodeLeft = NULL, 					        .nodeRight = NULL};
  nodeP = 	  	{.letter = 'P', 	          .nodeLeft = NULL, 					        .nodeRight = NULL};
  nodeJ = 		  {.letter = 'J', 	          .nodeLeft = NULL, 					        .nodeRight = (Node_T *)&node1};
  node1 = 	  	{.letter = '1', 	          .nodeLeft = NULL, 					        .nodeRight = NULL};
  nodeT = 	  	{.letter = 'T',		          .nodeLeft = (Node_T *)&nodeN, 		  .nodeRight = (Node_T *)&nodeM};
  nodeN = 	  	{.letter = 'N', 	          .nodeLeft = (Node_T *)&nodeD, 		  .nodeRight = (Node_T *)&nodeK};
  nodeM = 	  	{.letter = 'M', 	          .nodeLeft = (Node_T *)&nodeG, 		  .nodeRight = (Node_T *)&nodeO};
  nodeD = 	  	{.letter = 'D', 	          .nodeLeft = (Node_T *)&nodeB, 		  .nodeRight = (Node_T *)&nodeX};
  nodeK = 	  	{.letter = 'K', 	          .nodeLeft = (Node_T *)&nodeC, 		  .nodeRight = (Node_T *)&nodeY};
  nodeG = 		  {.letter = 'G', 	          .nodeLeft = (Node_T *)&nodeZ, 		  .nodeRight = (Node_T *)&nodeQ};
  nodeO = 		  {.letter = 'O', 	          .nodeLeft = (Node_T *)&nodeEmpty2,  .nodeRight = (Node_T *)&nodeEmpty3};
  nodeB = 		  {.letter = 'B', 	          .nodeLeft = (Node_T *)&node6, 		  .nodeRight = NULL};
  nodeX = 		  {.letter = 'X', 	          .nodeLeft = NULL, 					        .nodeRight = NULL};
  nodeC = 		  {.letter = 'C', 	          .nodeLeft = NULL, 					        .nodeRight = NULL};
  nodeY = 		  {.letter = 'Y', 	          .nodeLeft = NULL, 					        .nodeRight = NULL};
  nodeZ = 		  {.letter = 'Z', 	          .nodeLeft = (Node_T *)&node7, 		  .nodeRight = NULL};
  nodeQ = 	  	{.letter = 'Q', 	          .nodeLeft = NULL, 					        .nodeRight = NULL};
  nodeEmpty2 =  {.letter = (char)NULL, 	    .nodeLeft = (Node_T *)&node8, 		  .nodeRight = NULL};
  nodeEmpty3 =  {.letter = (char)NULL, 	    .nodeLeft = (Node_T *)&node9, 		  .nodeRight = (Node_T *)&node0};
  node6 = 	  	{.letter = '6', 	          .nodeLeft = NULL, 				      	  .nodeRight = NULL};
  node7 = 	  	{.letter = '7', 	          .nodeLeft = NULL, 				      	  .nodeRight = NULL};
  node8 = 	  	{.letter = '8', 	          .nodeLeft = NULL, 				      	  .nodeRight = NULL};
  node9 = 	  	{.letter = '9', 	          .nodeLeft = NULL, 				      	  .nodeRight = NULL};
  node0 = 	  	{.letter = '0', 	          .nodeLeft = NULL, 				      	  .nodeRight = NULL};
}

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


char whichLetter(void)
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
			return 0;
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

#endif

/*    Node_T node5;
//             \                                                            
//               Node_T nodeH;                                                     
//             /         \                                                  
//       Node_T node4;    \   
//                        Node_T nodeS;
//                      /       \                                           
//                     /         \                                          
//               Node_T nodeV;    \
//             /                   \                                        
//       Node_T node3;              \                                                   
//                                    Node_T nodeI;
//                                  /       \                                
//                                 /         \                              
//               Node_T nodeF;    /           \       
//                     \         /             \
//                      \       /               \                            
//                        Node_T nodeU;          \
//                      /                         \                          
//                     /                           \                          
//               Node_T nodeEmpty1;                 \                        
//                   /                               \
//                  /                                 \
//                 /                                   \
//                /                                     \
//               /                                       \
//              /                                         \
//             /                                           \                 
//       Node_T node2;                                      \
//                                                           \               
//                                                             Node_T nodeE;
//                                                           /
//                                                          /
//                                                         /
//                                                        /
//                                                       /
//                                                      /
//                                                     /
//                                                    /
//                                                   /                       
//               Node_T nodeL;                      /
//                     \                           /
//                      \                         /                          
//                        Node_T nodeR;          /
//                              \               /
//                               \             /
//                                \           /
//                                 \         /
//                                  \       /                                
//                                    Node_T nodeA;
//                                  /
//                                 /                                         
//               Node_T nodeP;    /
//                     \         /
//                      \       /                                            
//                        Node_T nodeW;
//                      /
//                     /                                                     
//               Node_T nodeJ;
//             /                                                             
//       Node_T node1;
//                                                 Node_T nodeStart;
//       Node_T node6;
//             \                                                             
//               Node_T nodeB;
//                     \        
//                      \                                                    
//                        Node_T nodeD;
//                      /       \
//                     /         \                                           
//               Node_T nodeX;    \
//                                 \
//                                  \                                        
//                                    Node_T nodeN;
//                                  /       \                                
//                                 /         \                               
//               Node_T nodeC;    /           \
//                     \         /             \ 
//                      \       /               \                            
//                        Node_T nodeK;          \
//                      /                         \
//                     /                           \                         
//               Node_T nodeY;                      \
//                                                   \
//                                                    \
//                                                     \
//                                                      \
//                                                       \
//                                                        \
//                                                         \
//                                                          \
//                                                           \               
//                                                             Node_T nodeT;
//                                                           /
//                                                          /
//                                                         /
//                                                        /  
//                                                       /
//                                                      /
//                                                     /                     
//       Node_T node7;                                /
//             \                                     /                       
//               Node_T nodeZ;                      /
//                     \                           /
//                      \                         /                          
//                        Node_T nodeG;          /
//                      /       \               /
//                     /         \             /                             
//               Node_T nodeQ;    \           /
//                                 \         /
//                                  \       /                                
//                                    Node_T nodeM;                        
//       Node_T node8;              /                                        
//                  \              /                                                              
//           Node_T nodeEmpty2;   /
//                     \         /
//                      \       /                                            
//                        Node_T nodeO;
//                      /                         
//                     /                                                     
//          Node_T nodeEmpty3;                
//                   /                            
//                  /                                                        
//       Node_T node9;                                 
//             \  /                               
//              \/                                
//              /                                 
//             /                                                             
//       Node_T node0;
// */