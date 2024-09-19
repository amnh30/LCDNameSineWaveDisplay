#ifndef MIDO_PRIVATE_H
#define MIDO_PRIVATE_H

/*Define PORTA Registers*/
#define PRIVATE_PORTA_REG  *((volatile u8 *)0x3B)
#define PRIVATE_DDRA_REG   *((volatile u8 *)0x3A)
#define PRIVATE_PINA_REG   *((volatile const u8 *)0x39)

/*Define PORTB Registers*/
#define PRIVATE_PORTB_REG  *((volatile u8 *)0x38)
#define PRIVATE_DDRB_REG   *((volatile u8 *)0x37)
#define PRIVATE_PINB_REG   *((volatile const u8 *)0x36)

/*Define PORTC Registers*/
#define PRIVATE_PORTC_REG  *((volatile u8 *)0x35)
#define PRIVATE_DDRC_REG   *((volatile u8 *)0x34)
#define PRIVATE_PINC_REG   *((volatile const u8 *)0x33)

/*Define PORTD Registers*/
#define PRIVATE_PORTD_REG  *((volatile u8 *)0x32)
#define PRIVATE_DDRD_REG   *((volatile u8 *)0x31)
#define PRIVATE_PIND_REG   *((volatile const u8 *)0x30)

/*Concatenation Funtion*/
#define PRIVATE_CONC(b7,b6,b5,b4,b3,b2,b1,b0)        PRIVATE_CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)
#define PRIVATE_CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)	 (0b##b7##b6##b5##b4##b3##b2##b1##b0)

/*PRivate Drection For Pin*/
#define PRVATE_INPUT             0
#define PRVATE_OUTPUT            1
/*PRivate Value For Pin*/
#define PRIVATE_HIGH             1
#define PRIVATE_LOW              0
#define PRIVATE_INPUT_FLOATING   0
#define PRIVATE_INPUT_PULLED_UP  1
/*Define All Port Direction*/
#define PRIVATE_ALL_PORT_OUTPUT          0xFF
#define PRIVATE_ALL_PORT_INPUT_FLOATING  0x00
#define PRIVATE_ALL_PORT_INPUT_PULLED_UP 0x00
/*Define All PORT HIGH LOW*/
#define PRIVATE_ALL_PORT_HIGH            0xFF
#define PRIVATE_ALL_PORT_LOW             0X00


#endif
