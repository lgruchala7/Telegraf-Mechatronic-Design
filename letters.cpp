// #define TEST

#ifndef TEST

#include "letters.h"
#include "hFramework.h"

extern hQueue<sign_t> signs;

Node_T nodeStart;    Node_T nodeE;        Node_T nodeI;
Node_T nodeS;        Node_T nodeU;        Node_T nodeH;
Node_T nodeF;        //Node_T nodeEmpty1;
// Node_T node5;        Node_T node4;        Node_T node3;
/* Node_T node2; */  Node_T nodeA;        Node_T nodeR;
Node_T nodeW;        Node_T nodeL;        Node_T nodeP;
Node_T nodeJ;       /* Node_T node1;*/        Node_T nodeT;
Node_T nodeN;        Node_T nodeM;        Node_T nodeD;
Node_T nodeK;        Node_T nodeG;        Node_T nodeO;
Node_T nodeB;        Node_T nodeX;        Node_T nodeC;
Node_T nodeY;        Node_T nodeZ;        Node_T nodeV;
// Node_T nodeEmpty2;   Node_T nodeEmpty3;   Node_T node6;
// Node_T node7;        Node_T node8;        Node_T node9;
// Node_T node0;  

void initLetterNodes(void)
{
  nodeStart = 	{.letter = (char)NULL, 	    .nodeLeft = (Node_T *)&nodeE, 		  .nodeRight = (Node_T *)&nodeT};
  nodeE = 		  {.letter = 'E', 	          .nodeLeft = (Node_T *)&nodeI, 		  .nodeRight = (Node_T *)&nodeA};
  nodeI = 		  {.letter = 'I', 	          .nodeLeft = (Node_T *)&nodeS, 		  .nodeRight = (Node_T *)&nodeU};
  nodeS = 		  {.letter = 'S', 	          .nodeLeft = (Node_T *)&nodeH, 		  .nodeRight = (Node_T *)&nodeV};
  nodeU = 		  {.letter = 'U', 	          .nodeLeft = (Node_T *)&nodeF, 		  .nodeRight = (Node_T *)NULL};
  nodeH = 		  {.letter = 'H', 	          .nodeLeft = (Node_T *)NULL, 		  .nodeRight = (Node_T *)NULL};
  nodeV = 		  {.letter = 'V', 	          .nodeLeft = NULL, 					        .nodeRight = (Node_T *)NULL};
  nodeF = 		  {.letter = 'F', 	          .nodeLeft = NULL, 					        .nodeRight = NULL};
//   nodeEmpty1 =  {.letter = (char)NULL, 	    .nodeLeft = NULL, 					        .nodeRight = (Node_T *)NULL};
//   node5 = 		  {.letter = '5', 	          .nodeLeft = NULL, 					        .nodeRight = NULL};
//   node4 = 		  {.letter = '4', 	          .nodeLeft = NULL, 					        .nodeRight = NULL};
//   node3 = 		  {.letter = '3', 	          .nodeLeft = NULL, 					        .nodeRight = NULL};
//   node2 = 		  {.letter = '2', 	          .nodeLeft = NULL, 					        .nodeRight = NULL};
  nodeA = 		  {.letter = 'A', 	          .nodeLeft = (Node_T *)&nodeR, 		  .nodeRight = (Node_T *)&nodeW};
  nodeR = 	  	{.letter = 'R', 	          .nodeLeft = (Node_T *)&nodeL, 		  .nodeRight = NULL};
  nodeW = 	  	{.letter = 'W', 	          .nodeLeft = (Node_T *)&nodeP, 		  .nodeRight = (Node_T *)&nodeJ};
  nodeL = 	  	{.letter = 'L', 	          .nodeLeft = NULL, 					        .nodeRight = NULL};
  nodeP = 	  	{.letter = 'P', 	          .nodeLeft = NULL, 					        .nodeRight = NULL};
  nodeJ = 		  {.letter = 'J', 	          .nodeLeft = NULL, 					        .nodeRight = (Node_T *)NULL};
//   node1 = 	  	{.letter = '1', 	          .nodeLeft = NULL, 					        .nodeRight = NULL};
  nodeT = 	  	{.letter = 'T',		          .nodeLeft = (Node_T *)&nodeN, 		  .nodeRight = (Node_T *)&nodeM};
  nodeN = 	  	{.letter = 'N', 	          .nodeLeft = (Node_T *)&nodeD, 		  .nodeRight = (Node_T *)&nodeK};
  nodeM = 	  	{.letter = 'M', 	          .nodeLeft = (Node_T *)&nodeG, 		  .nodeRight = (Node_T *)&nodeO};
  nodeD = 	  	{.letter = 'D', 	          .nodeLeft = (Node_T *)&nodeB, 		  .nodeRight = (Node_T *)&nodeX};
  nodeK = 	  	{.letter = 'K', 	          .nodeLeft = (Node_T *)&nodeC, 		  .nodeRight = (Node_T *)&nodeY};
  nodeG = 		  {.letter = 'G', 	          .nodeLeft = (Node_T *)&nodeZ, 		  .nodeRight = (Node_T *)NULL};
  nodeO = 		  {.letter = 'O', 	          .nodeLeft = (Node_T *)NULL,  .nodeRight = (Node_T *)NULL};
  nodeB = 		  {.letter = 'B', 	          .nodeLeft = (Node_T *)NULL, 		  .nodeRight = NULL};
  nodeX = 		  {.letter = 'X', 	          .nodeLeft = NULL, 					        .nodeRight = NULL};
  nodeC = 		  {.letter = 'C', 	          .nodeLeft = NULL, 					        .nodeRight = NULL};
  nodeY = 		  {.letter = 'Y', 	          .nodeLeft = NULL, 					        .nodeRight = NULL};
  nodeZ = 		  {.letter = 'Z', 	          .nodeLeft = (Node_T *)NULL, 		  .nodeRight = NULL};
//   nodeQ = 	  	{.letter = 'Q', 	          .nodeLeft = NULL, 					        .nodeRight = NULL};
//   nodeEmpty2 =  {.letter = (char)NULL, 	    .nodeLeft = (Node_T *)&node8, 		  .nodeRight = NULL};
//   nodeEmpty3 =  {.letter = (char)NULL, 	    .nodeLeft = (Node_T *)&node9, 		  .nodeRight = (Node_T *)&node0};
//   node6 = 	  	{.letter = '6', 	          .nodeLeft = NULL, 				      	  .nodeRight = NULL};
//   node7 = 	  	{.letter = '7', 	          .nodeLeft = NULL, 				      	  .nodeRight = NULL};
//   node8 = 	  	{.letter = '8', 	          .nodeLeft = NULL, 				      	  .nodeRight = NULL};
//   node9 = 	  	{.letter = '9', 	          .nodeLeft = NULL, 				      	  .nodeRight = NULL};
//   node0 = 	  	{.letter = '0', 	          .nodeLeft = NULL, 				      	  .nodeRight = NULL};
}

sign_t whichSpace(uint64_t space_time_ms)
{
	sign_t space;

	if (space_time_ms <= (uint64_t)(10 * TIME_UNIT))
	{
		space = SIGN_SPACE;
	}
	else if (space_time_ms > (uint64_t)(10 * TIME_UNIT))
	{
		space = LETTER_SPACE;
	}
	return space;
}


sign_t whichSign(uint64_t pressing_time_ms)
{
	sign_t sign;

	if (pressing_time_ms <= (uint64_t)3*TIME_UNIT)
	{
		sign = DOT;
	}
	else if ( (pressing_time_ms > (uint64_t)3*TIME_UNIT) && (pressing_time_ms <= (uint64_t)(20 * TIME_UNIT)) ) 
	{
		sign = DASH;
	}
	else if ( (pressing_time_ms > (uint64_t)(20 * TIME_UNIT)) && (pressing_time_ms <= (uint64_t)(40 * TIME_UNIT)) )	
	{
		sign = WORD_SPACE;
	}
	else if (pressing_time_ms > (uint64_t)(40 * TIME_UNIT))	
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
				return letter;
				break;		
			case NEW_LINE:
				letter = '\n';
				return letter;
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
	printf("Letter to write: %c\n", letter);
	switch (letter)
	{
		case 'A':
			writeA();
			break;
		case 'B':
			writeB();
			break;
		case 'C':
			writeC();
			break;
		case 'D':
			writeD();
			break;
		case 'E':
			writeE();
			break;
		case 'F':
			writeF();
			break;
		case 'G':
			writeG();
			break;
		case 'H':
			writeH();
			break;
		case 'I':
			writeI();
			break;			
		case 'J':
			writeJ();
			break;
		case 'K':
			writeK();
			break;
		case 'L':
			writeL();
			break;
		case 'M':
			writeM();
			break;	
		case 'N':
			writeN();
			break;
		case 'O':
			writeO();
			break;
		case 'P':
			writeP();
			break;
		case 'R':
			writeR();
			break;	
		case 'S':
			writeS();
			break;
		case 'T':
			writeT();
			break;
		case 'U':
			writeU();
			break;
		case 'V':
			writeV();
			break;
		case 'W':
			writeW();
			break;	
		case 'X':
			writeX();
			break;
		case 'Y':
			writeY();
			break;
		case 'Z':
			writeZ();
			break;
		case '\n':
			lineFeed();
			break;	
		case ' ':
			writeBigSpace();
			break;						
		default:
			break;
	}
}

	//hMot1, hMot2 - ruch po Y
	//hMot3 - ruch po X
	//hMot4 - podnoszenie

void writeA(void)
{	
	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);
	
    hMot1.rotRel(MOVE_UP * LONG_V_DASH, POWER, true, TIMEOUT);
	
	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);
	
	hMot1.rotRel(MOVE_DOWN * LONG_V_DASH, POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_UP * V_DASH, POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_LEFT * H_DASH, POWER, true, TIMEOUT);
	
	
	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);
	
	
    hMot1.rotRel(MOVE_DOWN * V_DASH, POWER, true, TIMEOUT);
	
	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);
	
}

void writeB(void)
{	
	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);
	
	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);
	
	hMot1.rotRel(MOVE_UP * V_DASH, POWER, true, TIMEOUT);
	
	hMot3.rotRel(MOVE_LEFT * H_DASH, POWER, true, TIMEOUT);
	
	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);
	
	hMot1.rotRel(MOVE_UP * V_DASH, POWER, true, TIMEOUT);
	
	hMot3.rotRel(MOVE_LEFT * H_DASH, POWER, true, TIMEOUT);
	
	hMot1.rotRel(MOVE_DOWN * LONG_V_DASH, POWER, true, TIMEOUT);
	

	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);
	
	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);
	
}

void writeC(void)
{	
	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);
	
	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);
	
	hMot3.rotRel(MOVE_LEFT * H_DASH, POWER, true, TIMEOUT);
	
	hMot1.rotRel(MOVE_UP * LONG_V_DASH, POWER, true, TIMEOUT);
	
	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);
	

	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_DOWN * LONG_V_DASH, POWER, true, TIMEOUT);
	
}

void writeD(void)
{
	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);
	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);
	
	hMot1.rotRel(MOVE_UP * LONG_V_DASH, POWER, true, TIMEOUT);
	
	hMot3.rotRel(MOVE_LEFT * H_DASH, POWER, true, TIMEOUT);
	
	hMot1.rotRel(MOVE_DOWN * LONG_V_DASH, POWER, true, TIMEOUT);
	

	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);
	
}

void writeE(void)
{
	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);
	

	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);
	
	
	hMot3.rotRel(MOVE_LEFT * H_DASH, POWER, true, TIMEOUT);
	
	
	hMot1.rotRel(MOVE_UP * V_DASH, POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_LEFT * H_DASH, POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_UP * V_DASH, POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);
	

	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_DOWN * LONG_V_DASH, POWER, true, TIMEOUT);
	
}

void writeF(void)
{
	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_UP * V_DASH, POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_LEFT * H_DASH, POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_UP * V_DASH, POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);
	

	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_DOWN * LONG_V_DASH, POWER, true, TIMEOUT);
	
}

void writeG(void)
{
	hMot3.rotRel(MOVE_RIGHT * H_DASH/2, POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_UP * V_DASH, POWER, true, TIMEOUT);
	

	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_RIGHT * H_DASH/2, POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_DOWN * V_DASH, POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_LEFT * H_DASH, POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_UP * LONG_V_DASH, POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);
	

	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_DOWN * LONG_V_DASH, POWER, true, TIMEOUT);
	
}

void writeH(void)
{
	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_UP * LONG_V_DASH, POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_DOWN * V_DASH, POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_UP * V_DASH, POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_DOWN * LONG_V_DASH, POWER, true, TIMEOUT);
	

	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);
	

}

void writeI(void){
	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);


	hMot1.rotRel(MOVE_UP * LONG_V_DASH, POWER, true, TIMEOUT);
	

	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);


	hMot1.rotRel(MOVE_DOWN * LONG_V_DASH, POWER, true, TIMEOUT);
	
}

void writeJ(void)
{
	hMot1.rotRel(MOVE_UP * V_DASH/2, POWER, true, TIMEOUT);


	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);


	hMot1.rotRel(MOVE_DOWN * V_DASH/2, POWER, true, TIMEOUT);


	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_UP * LONG_V_DASH, POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_LEFT * H_DASH, POWER, true, TIMEOUT);
	

	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_DOWN * LONG_V_DASH, POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);
	
}

void writeK(void)
{
	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);

	hMot1.rotRel(MOVE_UP * LONG_V_DASH, POWER, true, TIMEOUT);

	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);

	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);

	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);

	hMot3.rotRel(MOVE_LEFT * H_DASH, POWER + 100);
	hMot1.rotRel(MOVE_DOWN * V_DASH, POWER, true, TIMEOUT);

	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER + 100);
	hMot1.rotRel(MOVE_DOWN * V_DASH, POWER, true, TIMEOUT);

	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);
}

void writeL(void){
	hMot1.rotRel(MOVE_UP * LONG_V_DASH, POWER, true, TIMEOUT);
	

	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_DOWN * LONG_V_DASH, POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);
	

	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);
	

}

void writeM(void){
	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_UP * LONG_V_DASH, POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_RIGHT * H_DASH/2, POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_DOWN * LONG_V_DASH, POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_UP * LONG_V_DASH, POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_RIGHT * H_DASH/2, POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_DOWN * LONG_V_DASH, POWER, true, TIMEOUT);
	

	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);
	
}

void writeN(void)
{
	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);

	hMot1.rotRel(MOVE_UP * LONG_V_DASH, POWER, true, TIMEOUT);

	hMot3.rotRel(MOVE_RIGHT * H_DASH, (POWER + 100)/2);
	hMot1.rotRel(MOVE_DOWN * LONG_V_DASH, POWER, true, TIMEOUT);

	hMot1.rotRel(MOVE_UP * LONG_V_DASH, POWER, true, TIMEOUT);

	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);

	hMot1.rotRel(MOVE_DOWN * LONG_V_DASH, POWER, true, TIMEOUT);
}

void writeO(void){
	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_UP * LONG_V_DASH, POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_LEFT * H_DASH, POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_DOWN * LONG_V_DASH, POWER, true, TIMEOUT);
	

	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);
	

}

void writeP(void){
	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);
	
	
	hMot1.rotRel(MOVE_UP * LONG_V_DASH, POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_DOWN * V_DASH, POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_LEFT * H_DASH, POWER, true, TIMEOUT);
	

	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);


	hMot1.rotRel(MOVE_DOWN * V_DASH, POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);
	
}

void writeR(void)
{
	printf("Writing R\n");
	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);

	hMot1.rotRel(MOVE_UP * LONG_V_DASH, POWER, true, TIMEOUT);

	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);

	hMot1.rotRel(MOVE_DOWN * V_DASH, POWER, true, TIMEOUT);

	hMot3.rotRel(MOVE_LEFT * H_DASH, POWER, true, TIMEOUT);

	hMot3.rotRel(MOVE_RIGHT * H_DASH - 15, POWER + 150);
	hMot1.rotRel(MOVE_DOWN * V_DASH, POWER, true, TIMEOUT);

	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);
}

void writeS(void)
{
	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);	

	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);

	hMot1.rotRel(MOVE_UP * V_DASH, POWER, true, TIMEOUT);

	hMot3.rotRel(MOVE_LEFT * H_DASH, POWER, true, TIMEOUT);

	hMot1.rotRel(MOVE_UP * V_DASH, POWER, true, TIMEOUT);

	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);

	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);

	hMot1.rotRel(MOVE_DOWN * LONG_V_DASH, POWER, true, TIMEOUT);
}

void writeT(void){
	hMot1.rotRel(MOVE_UP * LONG_V_DASH, POWER, true, TIMEOUT);
	

	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_RIGHT * LONG_H_DASH, POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_LEFT * H_DASH, POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_DOWN * LONG_V_DASH, POWER, true, TIMEOUT);
	

	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);

	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);
	
}

void writeU(void){

	hMot1.rotRel(MOVE_UP * LONG_V_DASH, POWER, true, TIMEOUT);
	

	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_DOWN * LONG_V_DASH, POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_UP * LONG_V_DASH, POWER, true, TIMEOUT);
	

	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_DOWN * LONG_V_DASH, POWER, true, TIMEOUT);
	
}

void writeW(void){

	hMot1.rotRel(MOVE_UP * LONG_V_DASH, POWER, true, TIMEOUT);
	

	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_DOWN * LONG_V_DASH, POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_RIGHT * H_DASH/2, POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_UP * V_DASH, POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_DOWN * V_DASH, POWER, true, TIMEOUT);
	

	hMot3.rotRel(MOVE_RIGHT * H_DASH/2, POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_UP * LONG_V_DASH, POWER, true, TIMEOUT);
	

	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);
	

	hMot1.rotRel(MOVE_DOWN * LONG_V_DASH, POWER, true, TIMEOUT);
	
}

void writeV(void)
{
	hMot1.rotRel(MOVE_UP * LONG_V_DASH, POWER, true, TIMEOUT);

	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);

	hMot3.rotRel(MOVE_RIGHT * H_DASH, (POWER + 100)/2);
	hMot1.rotRel(MOVE_DOWN * LONG_V_DASH, POWER, true, TIMEOUT);

	hMot3.rotRel(MOVE_RIGHT * H_DASH, (POWER + 100)/2);
	hMot1.rotRel(MOVE_UP * LONG_V_DASH, POWER, true, TIMEOUT);

	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);

	hMot1.rotRel(MOVE_DOWN * LONG_V_DASH, POWER, true, TIMEOUT);
}

void writeX(void)
{
	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);

	hMot3.rotRel(MOVE_RIGHT * H_DASH, (POWER + 100)/2);
	hMot1.rotRel(MOVE_UP * LONG_V_DASH, POWER, true, TIMEOUT);

	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);

	hMot3.rotRel(MOVE_LEFT * H_DASH, POWER, true, TIMEOUT);

	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);

	hMot3.rotRel(MOVE_RIGHT * H_DASH,(POWER + 100)/2);
	hMot1.rotRel(MOVE_DOWN * LONG_V_DASH, POWER, true, TIMEOUT);

	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);
}

void writeY(void)
{
	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);

	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);

	hMot1.rotRel(MOVE_UP * V_DASH, POWER, true, TIMEOUT);

	hMot3.rotRel(MOVE_LEFT * H_DASH, POWER + 150);
	hMot1.rotRel(MOVE_UP * V_DASH, POWER, true, TIMEOUT);

	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);
	
	hMot3.rotRel(MOVE_RIGHT * LONG_H_DASH, POWER, true, TIMEOUT);

	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);

	hMot3.rotRel(MOVE_LEFT * H_DASH, POWER + 100);
	hMot1.rotRel(MOVE_DOWN * V_DASH, POWER, true, TIMEOUT);

	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);

	hMot1.rotRel(MOVE_DOWN * V_DASH, POWER, true, TIMEOUT);

	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);
}

void writeZ(void)
{
	hMot1.rotRel(MOVE_UP * LONG_V_DASH, POWER, true, TIMEOUT);

	hMot4.rotRel(TAKE_DOWN, UP_POWER, true, TIMEOUT);

	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);

	hMot3.rotRel(MOVE_LEFT * H_DASH, (POWER + 100)/2);
	hMot1.rotRel(MOVE_DOWN * LONG_V_DASH, POWER, true, TIMEOUT);

	hMot3.rotRel(MOVE_RIGHT * H_DASH, POWER, true, TIMEOUT);

	hMot4.rotRel(TAKE_UP, UP_POWER, true, TIMEOUT);
}

void writeSpace(void)
{
	hMot3.rotRel(MOVE_RIGHT * H_DASH/2, POWER, true, TIMEOUT);
}

void writeBigSpace(void)
{
	hMot3.rotRel(MOVE_RIGHT * LONG_H_DASH, POWER, true, TIMEOUT);
}

void lineFeed(void)
{
	hMot3.rotAbs(0, POWER, true, 10 * TIMEOUT);

	hMot1.rotRel(MOVE_DOWN * V_DASH/2, POWER, true, TIMEOUT);


	hMot1.rotRel(MOVE_DOWN * LONG_V_DASH, POWER, true, TIMEOUT);
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