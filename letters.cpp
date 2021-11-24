#include "letters.h"
#include "hFramework.h"


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

Node_T nodeStart = {.letter = ' ', .nodeLeft = &nodeE, .nodeRight = &nodeT};
Node_T nodeE = {.letter = 'E', .nodeLeft = &nodeI, .nodeRight = &nodeA};
Node_T nodeI = {.letter = 'I', .nodeLeft = &nodeS, .nodeRight = &nodeU};
Node_T nodeS = {.letter = 'S', .nodeLeft = &nodeH, .nodeRight = &nodeV};
Node_T nodeU = {.letter = 'U', .nodeLeft = &nodeF, .nodeRight = &nodeEmpty1};
Node_T nodeH = {.letter = 'H', .nodeLeft = &node5, .nodeRight = &node4};
Node_T nodeV = {.letter = 'V', .nodeLeft = NULL, .nodeRight = &node3};
Node_T nodeF = {.letter = 'F', .nodeLeft = NULL, .nodeRight = NULL};
Node_T nodeEmpty1 = {.letter = ' ', .nodeLeft = NULL, .nodeRight = &node2};
Node_T node5 = {.letter = '5', .nodeLeft = NULL, .nodeRight = NULL};
Node_T node4 = {.letter = '4', .nodeLeft = NULL, .nodeRight = NULL};
Node_T node3 = {.letter = '3', .nodeLeft = NULL, .nodeRight = NULL};
Node_T node2 = {.letter = '2', .nodeLeft = NULL, .nodeRight = NULL};
Node_T nodeA = {.letter = 'A', .nodeLeft = &nodeR, .nodeRight = &nodeW};
Node_T nodeR = {.letter = 'R', .nodeLeft = &nodeL, .nodeRight = NULL};
Node_T nodeW = {.letter = 'W', .nodeLeft = &nodeP, .nodeRight = &nodeJ};
Node_T nodeL = {.letter = 'L', .nodeLeft = NULL, .nodeRight = NULL};
Node_T nodeP = {.letter = 'P', .nodeLeft = NULL, .nodeRight = NULL};
Node_T nodeJ = {.letter = 'J', .nodeLeft = NULL, .nodeRight = &node1};
Node_T node1 = {.letter = '1', .nodeLeft = NULL, .nodeRight = NULL};
Node_T nodeT = {.letter = 'T', .nodeLeft = &nodeN, .nodeRight = &nodeM};
Node_T nodeN = {.letter = 'N', .nodeLeft = &nodeD, .nodeRight = &nodeK};
Node_T nodeM = {.letter = 'M', .nodeLeft = &nodeG, .nodeRight = &nodeO};
Node_T nodeD = {.letter = 'D', .nodeLeft = &nodeB, .nodeRight = &nodeX};
Node_T nodeK = {.letter = 'K', .nodeLeft = &nodeC, .nodeRight = &nodeY};
Node_T nodeG = {.letter = 'G', .nodeLeft = &nodeZ, .nodeRight = &nodeQ};
Node_T nodeO = {.letter = 'O', .nodeLeft = &nodeEmpty2, .nodeRight = &nodeEmpty3};
Node_T nodeB = {.letter = 'B', .nodeLeft = &node6, .nodeRight = NULL};
Node_T nodeX = {.letter = 'X', .nodeLeft = NULL, .nodeRight = NULL};
Node_T nodeC = {.letter = 'C', .nodeLeft = NULL, .nodeRight = NULL};
Node_T nodeY = {.letter = 'Y', .nodeLeft = NULL, .nodeRight = NULL};
Node_T nodeZ = {.letter = 'Z', .nodeLeft = &node7, .nodeRight = NULL};
Node_T nodeQ = {.letter = 'Q', .nodeLeft = NULL, .nodeRight = NULL};
Node_T nodeEmpty2 = {.letter = ' ', .nodeLeft = &node8, .nodeRight = NULL};
Node_T nodeEmpty3 = {.letter = ' ', .nodeLeft = &node9, .nodeRight = &node0};
Node_T node6 = {.letter = '6', .nodeLeft = NULL, .nodeRight = NULL};
Node_T node7 = {.letter = '7', .nodeLeft = NULL, .nodeRight = NULL};
Node_T node8 = {.letter = '8', .nodeLeft = NULL, .nodeRight = NULL};
Node_T node9 = {.letter = '9', .nodeLeft = NULL, .nodeRight = NULL};
Node_T node0 = {.letter = '0', .nodeLeft = NULL, .nodeRight = NULL};

void write(const char letter)
{
    switch (letter)
    {
    case 'a':
        
        break;
    
    default:
        break;
    }
}


void writeA(void)
{
    hMot1.rotRel(100, 100, false, 0);
}

void writeB(void)
{

}