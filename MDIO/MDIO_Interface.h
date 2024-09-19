#ifndef MIDO_INTERFACE_H
#define MIDO_INTERFACE_H

/*Define Port ID*/
#define MDIO_PORTA 0
#define MDIO_PORTB 1
#define MDIO_PORTC 2
#define MDIO_PORTD 3

/*Define Pin ID*/
#define MDIO_PIN_0 0
#define MDIO_PIN_1 1
#define MDIO_PIN_2 2
#define MDIO_PIN_3 3
#define MDIO_PIN_4 4
#define MDIO_PIN_5 5
#define MDIO_PIN_6 6
#define MDIO_PIN_7 7

/* Define Pin Directions */
#define MDIO_OUTPUT          0
#define MDIO_INPUT_FLOATING  1
#define MDIO_INPUT_PULLED_UP 2

/*Define HIGH LOW*/
#define MDIO_HIGH 1
#define MDIO_LOW  0


/* Functions Prototype */
void MDIO_IntialPins(void);

u8 MDIO_u8SetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinDirec);
u8 MDIO_u8SetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PortDirec);
u8 MDIO_u8SetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue);
u8 MDIO_u8SetPortValue(u8 Copy_u8PortId, u8 Copy_u8PortValue);
u8 MDIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 *Copy_pu8ReturnedPinValue);
u8 MDIO_u8GetPortValue(u8 Copy_u8PortId, u8 *Copy_pu8ReturnedPortValue);



#endif
