// #define TEST

#ifdef TEST

#include "hFramework.h"
#include <stddef.h>
#include <stdio.h>
#include <Lego_Touch.h>

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

	while (true)
	{
		isButtonPressed = button.isPressed();
	// 	ishbtn1Pressed = hBtn1.isPressed();
	// 	ishbtn2Pressed = hBtn2.isPressed();

	// 	if (isButtonPressed && !wasButtonPressed)
	// 	{
	// 		hMot2.rotRel(87, 500);
	// 		hMot1.rotRel(100, 600);
	// 	}
	// 	else if (!isButtonPressed && wasButtonPressed)
	// 	{
	// 		hMot2.rotRel(-87, 500);
	// 		hMot1.rotRel(-100, 600);
	// 	}


	// 	if (ishbtn1Pressed && !washbtn1Pressed)
	// 	{
	// 		// hMot2.rotRel(80);
	// 		hMot4.setPower(300);
	// 	}
	// 	else if (!ishbtn1Pressed && washbtn1Pressed)
	// 	{
	// 		// hMot2.rotRel(-80);
	// 		hMot4.setPower(0);
	// 	}

	// 	if (ishbtn2Pressed && !washbtn2Pressed)
	// 	{
	// 		hMot3.rotRel(100, 300);
	// 	}
	// 	else if (!ishbtn2Pressed && washbtn2Pressed)
	// 	{
	// 		hMot3.rotRel(-100, 300);
	// 	}

	// 	wasButtonPressed = isButtonPressed;
	// 	washbtn1Pressed = ishbtn1Pressed;
	// 	washbtn2Pressed = ishbtn2Pressed;

	// 	sys.delay(20);
	
	
	//hMot1, hMot2 - ruch po Y
	//hMot3 - ruch po X
	//hMot4 - podnoszenie

		if (isButtonPressed && !wasButtonPressed)
		{
			hMot3.rotRel(100, 300, false, 700);		

			printf("step 1\n");
			sys.delay(300);

			hMot2.rotAbs(80, 1000, false, 700);
			hMot1.rotAbs(80, 1000, false, 700);

			printf("step 2\n");
			sys.delay(300);

			hMot3.rotRel(-100, 300, false, 700);

			printf("step 3\n");
			sys.delay(300);

			hMot2.rotAbs(120, 1000, false, 700);
			hMot1.rotAbs(120, 1000, false, 700);

			printf("step 4\n");
			sys.delay(300);

			hMot3.rotRel(100, 300, false, 700);

			printf("step 5\n");
			sys.delay(300);

			hMot4.setPower(300);
			sys.delay(300);

			hMot2.rotAbs(0, 1000, false, 700);
			hMot1.rotAbs(0, 1000, false, 700);

			sys.delay(300);

			hMot4.setPower(0);
			
			sys.delay(300);
			
			hMot3.rotRel(-100, 300, false, 700);
		}

		wasButtonPressed = isButtonPressed;
	}
}
#endif

#ifndef TEST
#include "hFramework.h"
#include <stdio.h>
#include "Lego_Touch.h"
#include "tasks.h"
#include "letters.h"

extern hSemaphore readyToDecodeSema;	//semaphores
extern hSemaphore readyToWriteSema;


void hMain()
{
	sys.setLogDev(&Serial);

	initLetterNodes();
	readyToDecodeSema.give();	//start with semaphore counter equal to 1
	readyToWriteSema.give();

	sys.taskCreate(&buttonTask);	//create tasks
	// sys.taskCreate(&writeTask);
	sys.taskCreate(&decodeTask);
	for(;;)
	{
		sys.delay(UINT32_MAX);
	}
}

#endif