// include the needed headers and library
#include <Wire.h>
#include <hd44780.h>						// main hd44780 header
#include <hd44780ioClass/hd44780_I2Cexp.h>	// i2c expander i/o class header

hd44780_I2Cexp lcd; // declare lcd object: auto locate & config exapander chip

// LCD geometry
const int LCD_COLS = 16;
const int LCD_ROWS = 2;


// ===VARIABLE DECLARATION
const int BAUDRATE = 9600; // Baudrate for serial
#define buttonUp 7
#define buttonDown 5
#define buttonLeft 6
#define buttonRight 4
#define buttonSelect 3
#define buttonBack 8


int buttonStateUp = HIGH;			// Button 0 = Pressed 1 = Not Pressed
int lastButtonStateUp = HIGH;		// Last reading
int buttonStateDown = HIGH;			// Button 0 = Pressed 1 = Not Pressed
int lastButtonStateDown = HIGH; 	// Last reading
int buttonStateLeft = HIGH;			// Button 0 = Pressed 1 = Not Pressed
int lastButtonStateLeft = HIGH; 	// Last reading
int buttonStateRight = HIGH;		// Button 0 = Pressed 1 = Not Pressed
int lastButtonStateRight = HIGH;	// Last reading
int buttonStateSelect = HIGH;		// Button 0 = Pressed 1 = Not Pressed
int lastButtonStateSelect = HIGH;	// Last reading
int buttonStateBack = HIGH;			// Button 0 = Pressed 1 = Not Pressed
int lastButtonStateBack = HIGH;		// Last reading

int buttonArray[6] = {buttonStateUp, buttonStateDown, buttonStateLeft, buttonStateRight, buttonStateSelect, buttonStateBack};
int count = 0; 				// To use with FOR

unsigned long lastDebounceTime = 0;		// The last time the output pin was toggled
unsigned long debounceDelay = 50; 		// The debounce time , how long a button need to be pressed

int menuSelect = 0;
int lastMenuSelect = 0;

// ===SETUP START===

void setup()
{

	// ===BUTTON INIT===
	pinMode(buttonUp, INPUT);
	pinMode(buttonDown, INPUT);
	pinMode(buttonLeft, INPUT);
	pinMode(buttonRight, INPUT);
	pinMode(buttonSelect, INPUT);
	pinMode(buttonBack, INPUT);


Serial.begin(BAUDRATE);




}
// ===SETUP END===




// ===LOOP START===
void loop()
{

//	int reading = digitalRead(buttonUp);

	// TODO: here the routine to chek button
	// if (reading != last)


	// Routine to state all button
	buttonStateUp = digitalRead(buttonUp);
	buttonStateDown = digitalRead(buttonDown);
	buttonStateLeft = digitalRead(buttonLeft);
	buttonStateRight = digitalRead(buttonRight);
	buttonStateSelect = digitalRead(buttonSelect);
	buttonStateBack = digitalRead(buttonBack);


/*
	for (int i = 0; i <= 5; i++)
	{
		int buttonArray[] = {buttonStateUp, buttonStateDown, buttonStateLeft, buttonStateRight, buttonStateSelect, buttonStateBack};
		if (buttonArray[i] == LOW) {
			Serial.println("something happened");

		} else
			{
			Serial.println("Nothing");
			}
	}


*/

	//int buttonArray[] = {buttonStateUp, buttonStateDown, buttonStateLeft, buttonStateRight, buttonStateSelect, buttonStateBack}

	for (int i = 0; i < 6; ++i)
	{
		if (buttonArray[i] == LOW) {
			Serial.println("something happened");
		}
		else {
			Serial.println("Nothing000");
		}
	}


	if (menuSelect == 1)
	{

	}

	menuSelect = 0;			// Seti here wich menu is displaky on lcd

	Serial.println("Still Nothing");
}
// ===LOOP END===


