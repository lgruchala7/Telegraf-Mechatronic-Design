#ifndef LETTERS_H
#define LETTERS_H

void write(const char);

#define LEFTSIDE_START  {true, true, true, true, true, true, true,\\
                        true, true, true, true, true, true, true,\\
                        true, true, true, false, false, false, false,\\
                        false, false, false, false, false, false, false,\\
                        false, false, false, false, false, false}

#define RIGHTSIDE_START  {false, false, false, false, false, false, false,\\
                        false, false, false, false, false, false, false,\\
                        false, false, false, true, true, true, true,\\
                        true, true, true, true, true, true, true,\\
                        true, true, true, true, true, true}

#define LEFTSIDE_E      {true, true, true, true, true, true, true,\\
                        true, true, true, false, false, false, false,\\
                        false, false, false, false, false, false, false,\\
                        false, false, false, false, false, false, false,\\
                        false, false, false, false, false, false}

#define RIGHTSIDE_E     {false, false, false, false, false, false, false,\\
                        false, false, false, true, true, true, true,\\
                        true, true, true, false, false, false, false,\\
                        false, false, false, false, false, false, false,\\
                        false, false, false, false, false, false}

#define LEFTSIDE_I      {true, true, true, true, true, true, true,\\
                        true, true, true, false, false, false, false,\\
                        false, false, false, false, false, false, false,\\
                        false, false, false, false, false, false, false,\\
                        false, false, false, false, false, false}

#define LEFTSIDE_I      {true, true, true, true, true, true, true,\\
                        true, true, true, false, false, false, false,\\
                        false, false, false, false, false, false, false,\\
                        false, false, false, false, false, false, false,\\
                        false, false, false, false, false, false}                        

struct Node_T {
      char letter;
      // bool isActive;
      Node_T * nodeLeft;
      Node_T * nodeRight;
};

// struct LetterTree_T {
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
//       Node_T node3;           //\                                          */         
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
// };


void writeA(void);

void writeB(void);

#endif