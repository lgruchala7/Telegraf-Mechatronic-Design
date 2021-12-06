// #define TEST

#ifdef TEST

#include "hFramework.h"
#include <stddef.h>
#include <stdio.h>
#include <Lego_Touch.h>
#include "letters.h"

#define LONG_V_DASH 360 // V stands for vertical and H for horizntal
#define V_DASH 180
#define LONG_H_DASH 500
#define H_DASH 250
#define POWER 300
#define MOVE_UP -1
#define MOVE_RIGHT -1
#define UP_POWER 300
#define DELAY 300
#define TAKE_UP -100
#define TAKE_DOWN 100

using namespace hSensors;

hLegoSensor_simple ls(hSens5);
Lego_Touch button(ls);

bool isButtonPressed = false;
bool wasButtonPressed = false;
bool ishbtn1Pressed = false;
bool washbtn1Pressed = false;
bool ishbtn2Pressed = false;
bool washbtn2Pressed = false;

void hMain()
{
	hMot1.setEncoderPolarity(Polarity::Reversed);
	hMot2.setEncoderPolarity(Polarity::Reversed);
	hMot3.setEncoderPolarity(Polarity::Reversed);
	hMot4.setEncoderPolarity(Polarity::Reversed);	

	sys.setLogDev(&Serial);

	// hMot4.rotRel(TAKE_UP, UP_POWER, false, 0);

	while (true)
	{
		isButtonPressed = button.isPressed();
		ishbtn1Pressed = hBtn1.isPressed();
		ishbtn2Pressed = hBtn2.isPressed();

		if (isButtonPressed && !wasButtonPressed)
		{
			writeY();
			writeSpace();
		}
		else if (!isButtonPressed && wasButtonPressed)
		{
			// hMot1.rotRel(MOVE_UP * V_DASH, POWER, false, 0);
		}


		if (ishbtn1Pressed && !washbtn1Pressed)
		{
			writeX();
			writeSpace();
		}
		else if (!ishbtn1Pressed && washbtn1Pressed)
		{
			// hMot3.rotRel(MOVE_RIGHT * H_DASH , POWER, false, 0);
		}

		if (ishbtn2Pressed && !washbtn2Pressed)
		{
			lineFeed();
			// writeSpace();
		}
		else if (!ishbtn2Pressed && washbtn2Pressed)
		{
		}

		wasButtonPressed = isButtonPressed;
		washbtn1Pressed = ishbtn1Pressed;
		washbtn2Pressed = ishbtn2Pressed;

		sys.delay(20);
	
	
	//hMot1, hMot2 - ruch po Y
	//hMot3 - ruch po X
	//hMot4 - podnoszenie

		// if (isButtonPressed && !wasButtonPressed)
		// {
		// 	hMot3.rotRel(100, 300, false, 700);		

		// 	printf("step 1\n");
		// 	sys.delay(300);

		// 	hMot2.rotAbs(80, 1000, false, 700);
		// 	hMot1.rotAbs(80, 1000, false, 700);

		// 	printf("step 2\n");
		// 	sys.delay(300);

		// 	hMot3.rotRel(-100, 300, false, 700);

		// 	printf("step 3\n");
		// 	sys.delay(300);

		// 	hMot2.rotAbs(120, 1000, false, 700);
		// 	hMot1.rotAbs(120, 1000, false, 700);

		// 	printf("step 4\n");
		// 	sys.delay(300);

		// 	hMot3.rotRel(100, 300, false, 700);

		// 	printf("step 5\n");
		// 	sys.delay(300);

		// 	hMot4.setPower(300);
		// 	sys.delay(300);

		// 	hMot2.rotAbs(0, 1000, false, 700);
		// 	hMot1.rotAbs(0, 1000, false, 700);

		// 	sys.delay(300);

		// 	hMot4.setPower(0);
			
		// 	sys.delay(300);
			
		// 	hMot3.rotRel(-100, 300, false, 700);
		// }

		// wasButtonPressed = isButtonPressed;
	}
}
#endif

#ifndef TEST
#include "hFramework.h"
#include <stdio.h>
#include "Lego_Touch.h"
#include "tasks.h"
#include "letters.h"

#define UP_POWER 300
#define TAKE_UP -100

extern hSemaphore readyToDecodeSema;	//semaphores
extern hSemaphore readyToWriteSema;


void hMain()
{
	sys.setLogDev(&Serial);
 
	hMot1.setEncoderPolarity(Polarity::Reversed);
	hMot3.setEncoderPolarity(Polarity::Reversed);
	hMot4.setEncoderPolarity(Polarity::Reversed);

	// hMot4.rotRel(TAKE_UP, UP_POWER, false, 0);

	initLetterNodes();
	readyToDecodeSema.take(0);		//start with semaphore counter equal to 0
	readyToWriteSema.take(0);

	sys.taskCreate(&buttonTask);	//create tasks
	sys.taskCreate(&decodeTask);
	sys.taskCreate(&writeTask);
	for(;;)
	{
		sys.delay(UINT32_MAX);
	}
}

#endif