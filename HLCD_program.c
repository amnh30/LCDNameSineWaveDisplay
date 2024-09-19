/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "avr/delay.h"
#define C_CPU 8000000Ul

/*MCAL Layer Include*/
#include "MDIO/MDIO_Interface.h"

/* HAL Layer Include*/
#include "HLCD_private.h"
#include "HLCD_config.h"
#include "HLCD_interface.h"


void HLCD_VoidLcdIint(void)
{
	/* Delay for 32 Ms*/
	_delay_ms(31);

	/* Send The INntialixation Command*/
	HLCD_VoidLcdWriteCmd(0x38);

	/*Delay for 1 Ms*/
	_delay_us(40);

	/* Display ON/OFF Control*/
	HLCD_VoidLcdWriteCmd(0x0f);

	/*Delay for 1 Ms*/
	_delay_us(40);

	/* Display Clear*/
	HLCD_VoidLcdWriteCmd(0x01);

	/*Delay for 1 Ms*/
	_delay_ms(2);

	/* Display Entery Mode Set*/
	HLCD_VoidLcdWriteCmd(0x06);
}

void HLCD_VoidLcdWriteCmd(u8 Copy_u8Cmd)
{

	/*	RS pin  = 0 ==> Select Command Register*/
	MDIO_u8SetPinValue(HLCD_RS_PORT, HLCD_RS_PIN, MDIO_LOW);

	/*	R/W pin  = 0 ==> Select Write Mode*/
	MDIO_u8SetPinValue(HLCD_RW_PORT, HLCD_RW_PIN, MDIO_LOW);

	/*	E pin  = 1 ==> Enable the command */
	MDIO_u8SetPinValue(HLCD_EN_PORT, HLCD_EN_PIN, MDIO_HIGH);

	/*	Write Command */
	MDIO_u8SetPortValue(HLCD_DATA_PORT, Copy_u8Cmd);

	/*	Wait for 230 ns */
	_delay_us(1);

	/*	E pin  = 0 ==> Disable the command*/
	MDIO_u8SetPinValue(HLCD_EN_PORT, HLCD_EN_PIN, MDIO_LOW);
}

void HLCD_VoidLcdWriteChar(u8 Copy_u8Char)
{

	/*	RS pin  = 0 ==> Select Command Register*/
	MDIO_u8SetPinValue(HLCD_RS_PORT, HLCD_RS_PIN, MDIO_HIGH);

	/*	R/W pin  = 0 ==> Select Write Mode*/
	MDIO_u8SetPinValue(HLCD_RW_PORT, HLCD_RW_PIN, MDIO_LOW);

	/*	E pin  = 1 ==> Enable the command */
	MDIO_u8SetPinValue(HLCD_EN_PORT, HLCD_EN_PIN, MDIO_HIGH);

	/*	Write Command */
	MDIO_u8SetPortValue(HLCD_DATA_PORT, Copy_u8Char);

	/*	Wait for 230 ns */
	_delay_us(1);

	/*	E pin  = 0 ==> Disable the command*/
	MDIO_u8SetPinValue(HLCD_EN_PORT, HLCD_EN_PIN, MDIO_LOW);
}
u8 HLCD_VoidSetCurser(u8 Copy_u8LineNb, u8 Copy_u8CharNb)
{
	u8 Local_u8ErrorState = STD_TYPE_OK;

	switch (Copy_u8LineNb)
	{
	case HLCD_LINE_1:
		HLCD_VoidLcdWriteCmd(0x80 + Copy_u8CharNb);
		break;
	case HLCD_LINE_2:
		HLCD_VoidLcdWriteCmd(0xc0 + Copy_u8CharNb);
		break;
	default:
		Local_u8ErrorState = STD_TYPE_NOK;
		break;
	}

	return Local_u8ErrorState;
}
u8 HLCD_u8WriteStr(const char *Copy_pcStr)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;

    if (Copy_pcStr == STD_TYPE_POINTER_NULL)
    {
        return STD_TYPE_NOK; // Error if null pointer is passed
    }

    // Starting position
    u8 Line = HLCD_LINE_1;
    u8 CharPos = 0;

    // Write characters until the end of the string
    while (*Copy_pcStr)
    {
        // If we reach the end of the first line, switch to the second line
        if (CharPos >= 16 && Line == HLCD_LINE_1)
        {
            Line = HLCD_LINE_2;
            CharPos = 0;
            HLCD_VoidSetCurser(Line, CharPos); // Move cursor to start of the second line
        }

        // If we reach the end of the second line, wrap around to the start of the first line
        if (CharPos >= 16 && Line == HLCD_LINE_2)
        {
            Line = HLCD_LINE_1;
            CharPos = 0;
            HLCD_VoidSetCurser(Line, CharPos); // Move cursor to start of the first line
        }

        // Write the current character to the LCD
        HLCD_VoidLcdWriteChar(*Copy_pcStr++);

        // Increment character position
        CharPos++;
    }

    return Local_u8ErrorState;
}
void HLCD_VoidLcdClear(void)
{
    // Send the clear display command (0x01) to the LCD
    HLCD_VoidLcdWriteCmd(0x01);

    // Delay to allow the LCD to process the command and clear the screen
    _delay_ms(2); // 2 ms is typically enough for clearing the screen
}
void HLCD_VoidLcdWriteInt(int Copy_u32Number)
{
    char buffer[BUFFER_SIZE]; // Buffer to hold the converted string
    char temp[BUFFER_SIZE]; // Temporary buffer for reverse string
    int isNegative = 0; // Flag to check if number is negative
    int i = 0, j;

    // Check if the number is negative
    if (Copy_u32Number < 0)
    {
        isNegative = 1;
        Copy_u32Number = -Copy_u32Number; // Make number positive
    }

    // Convert integer to string
    do
    {
        buffer[i++] = (Copy_u32Number % 10) + '0'; // Get last digit
        Copy_u32Number /= 10; // Remove last digit
    } while (Copy_u32Number > 0);

    // Add negative sign if needed
    if (isNegative)
    {
        buffer[i++] = '-';
    }

    // Reverse the string
    buffer[i] = '\0'; // Null-terminate the string
    for (j = 0; j < i; j++)
    {
        temp[j] = buffer[i - j - 1];
    }
    temp[i] = '\0'; // Null-terminate the reversed string

    // Write the string to the LCD
    HLCD_u8WriteStr(temp);
}

/* Draw Special Chars */
/* 1- Sned Command to set CGRAM Address */
/* Draw 1 Special Char into First Char in CGRAM*/

/* Function to store special characters in CGRAM and display them at the current cursor position */
void HLCD_VoidCreateSpecialChar(u8 Copy_u8Pattern[], u8 Copy_u8CGRAMIndex)
{
    /* 1. Set CGRAM address command (0x40 + (index * 8)) */
    HLCD_VoidLcdWriteCmd(0x40 + (Copy_u8CGRAMIndex * 8));

    /* 2. Write the 8-byte pattern to CGRAM */
    for (u8 i = 0; i < 8; i++)
    {
        HLCD_VoidLcdWriteChar(Copy_u8Pattern[i]);
    }

    /* 3. Return to DDRAM (write mode) and display the special character */
    HLCD_VoidLcdWriteChar(Copy_u8CGRAMIndex);
}
/* Function to write a string of special characters to the LCD */
void HLCD_VoidWriteSpecialCharString(u8 Copy_u8CGRAMIndices[], u8 Copy_u8Length)
{
    /* Loop through the array of CGRAM indices */
    for (u8 i = 0; i < Copy_u8Length; i++)
    {
        /* Write each special character from CGRAM to the current cursor position */
        HLCD_VoidLcdWriteChar(Copy_u8CGRAMIndices[i]);
    }
}


