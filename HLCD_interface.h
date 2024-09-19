#ifndef HLCD_INTERFACE_H
#define HLCD_INTERFACE_H




/*Line One Selelcte*/
#define HLCD_LINE_1 1
#define HLCD_LINE_2 2

/*Buffer Size For Int Funtion*/
#define BUFFER_SIZE 12



/**
 * @brief Initializes the LCD display.
 */
void HLCD_VoidLcdIint(void);

/**
 * @brief Sends a command to the LCD.
 * @param Copy_u8Cmd The command to send.
 */
void HLCD_VoidLcdWriteCmd(u8 Copy_u8Cmd);

/**
 * @brief Writes a character to the LCD.
 * @param Copy_u8Char The character to display.
 */
void HLCD_VoidLcdWriteChar(u8 Copy_u8Char);

/**
 * @brief Clears the LCD display.
 */
void HLCD_VoidLcdClear(void);

/**
 * @brief Sets the cursor position on the LCD.
 * @param Copy_u8LineNb Line number (1 or 2).
 * @param Copy_u8CharNb Character position within the line.
 * @return Status of the operation.
 */
u8 HLCD_VoidSetCurser(u8 Copy_u8LineNb, u8 Copy_u8CharNb);

/**
 * @brief Writes a string to the LCD.
 * @param Copy_pcStr Pointer to the null-terminated string.
 * @return Status of the operation.
 */
u8 HLCD_u8WriteStr(const char *Copy_pcStr);
/**
 * @brief Writes an integer to the LCD.
 *
 * This function converts an integer to its ASCII representation and displays it on the LCD.
 *
 * @param Copy_u32Number The integer to be displayed.
 */
void HLCD_VoidLcdWriteInt(int Copy_u32Number);
/* Function to store special characters in CGRAM and display them at the current cursor position */
void HLCD_VoidCreateSpecialChar(u8 Copy_u8Pattern[], u8 Copy_u8CGRAMIndex);
/* Function to write a string of special characters to the LCD */
void HLCD_VoidWriteSpecialCharString(u8 Copy_u8CGRAMIndices[], u8 Copy_u8Length);


#endif
