/*
 * main.c
 *
 *  Created on: Sep 18, 2024
 *      Author: Ahmed Nageeb
 */

#include <avr/delay.h>
#include "STD_Types.h"
#include "HLCD_interface.h"
#define EVEN_NUMBER 0
#define OFFSET_VALUE 3
#define COUNTER_LIMIT 10
#define NAME_CHAR_POS (1, 2, 3, 4)
#define C_CPU 8000000Ul

void HLCD_VoidWriteAhmad(void);

int main(int argc, char **argv)
{
    MDIO_IntialPins();
    HLCD_VoidLcdIint();
    HLCD_VoidWriteAhmad();
    u8 Local_u8Counter = 0;
    while (1)
    {

        if (Local_u8Counter % 2 == EVEN_NUMBER)
        {
            HLCD_VoidSetCurser(HLCD_LINE_1, Local_u8Counter);
            HLCD_u8WriteStr("Ahmed");
            HLCD_VoidSetCurser(HLCD_LINE_2, Local_u8Counter);
            HLCD_VoidLcdWriteChar(3);
            HLCD_VoidLcdWriteChar(2);
            HLCD_VoidLcdWriteChar(1);
            HLCD_VoidLcdWriteChar(0);
            _delay_ms(500);
            HLCD_VoidLcdClear();
        }
        else
        {
            HLCD_VoidSetCurser(HLCD_LINE_2, Local_u8Counter);
            HLCD_u8WriteStr("Ahmed");
            HLCD_VoidSetCurser(HLCD_LINE_1, Local_u8Counter);
            HLCD_VoidLcdWriteChar(3);
            HLCD_VoidLcdWriteChar(2);
            HLCD_VoidLcdWriteChar(1);
            HLCD_VoidLcdWriteChar(0);
            _delay_ms(500);
            HLCD_VoidLcdClear();
        }
        Local_u8Counter += OFFSET_VALUE;
        if (Local_u8Counter >= COUNTER_LIMIT)
        {
            Local_u8Counter = 0;
        }
    }
}

void HLCD_VoidWriteAhmad(void)
{
    /* 1- Draw "أ" (Alef with Hamza) */
    HLCD_VoidLcdWriteCmd(0x40 + (8 * 0)); // Set CGRAM address for first character
    HLCD_VoidLcdWriteChar(0B01111);       // Row 1
    HLCD_VoidLcdWriteChar(0B01010);       // Row 2
    HLCD_VoidLcdWriteChar(0B11111);       // Row 3
    HLCD_VoidLcdWriteChar(0B00100);       // Row 4
    HLCD_VoidLcdWriteChar(0B00100);       // Row 5
    HLCD_VoidLcdWriteChar(0B00100);       // Row 6
    HLCD_VoidLcdWriteChar(0B00100);       // Row 7
    HLCD_VoidLcdWriteChar(0B00100);       // Row 8

    /* 2- Draw "ح" (Haa) */
    HLCD_VoidLcdWriteCmd(0x40 + (8 * 1)); // Set CGRAM address for second character
    HLCD_VoidLcdWriteChar(0x18);       // Row 1
    HLCD_VoidLcdWriteChar(0x0E);       // Row 2
    HLCD_VoidLcdWriteChar(0x07);       // Row 3
    HLCD_VoidLcdWriteChar(0x03);       // Row 4
    HLCD_VoidLcdWriteChar(0x1F);       // Row 5
    HLCD_VoidLcdWriteChar(0x1F);       // Row 6
    HLCD_VoidLcdWriteChar(0x00);       // Row 7
    HLCD_VoidLcdWriteChar(0x00);       // Row 8

    /* 3- Draw "م" (Meem) */
    HLCD_VoidLcdWriteCmd(0x40 + (8 * 2)); // Set CGRAM address for third character
    HLCD_VoidLcdWriteChar(0x00);       // Row 1
    HLCD_VoidLcdWriteChar(0x00);       // Row 2
    HLCD_VoidLcdWriteChar(0x00);       // Row 3
    HLCD_VoidLcdWriteChar(0x00);       // Row 4
    HLCD_VoidLcdWriteChar(0x1F);       // Row 5
    HLCD_VoidLcdWriteChar(0x1F);       // Row 6
    HLCD_VoidLcdWriteChar(0x0A);       // Row 7
    HLCD_VoidLcdWriteChar(0x0E);       // Row 8

    /* 4- Draw "د" (Dal) */
    HLCD_VoidLcdWriteCmd(0x40 + (8 * 3)); // Set CGRAM address for fourth character
    HLCD_VoidLcdWriteChar(0x00);       // Row 1
    HLCD_VoidLcdWriteChar(0x03);       // Row 2
    HLCD_VoidLcdWriteChar(0x03);       // Row 3
    HLCD_VoidLcdWriteChar(0x03);       // Row 4
    HLCD_VoidLcdWriteChar(0x1F);       // Row 5
    HLCD_VoidLcdWriteChar(0x1F);       // Row 6
    HLCD_VoidLcdWriteChar(0x00);       // Row 7
    HLCD_VoidLcdWriteChar(0x00);       // Row 8
}
