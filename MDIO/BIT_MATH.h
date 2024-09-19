// Macro to set a specific bit
#define SET_BIT(REG, BIT)    ((REG) |= (1 << (BIT)))

// Macro to clear a specific bit
#define CLEAR_BIT(REG, BIT)  ((REG) &= ~(1 << (BIT)))

// Macro to toggle a specific bit
#define TOGGLE_BIT(REG, BIT) ((REG) ^= (1 << (BIT)))

// Macro to check if a specific bit is set (returns 1 if the bit is set, 0 if not)
#define IS_BIT_SET(REG, BIT) (((REG) >> (BIT)) & 1)

// Macro to check if a specific bit is cleared (returns 1 if the bit is cleared, 0 if not)
#define IS_BIT_CLEAR(REG, BIT) (!(((REG) >> (BIT)) & 1))
// Macro to get The Bit From regiser 
#define GET_BIT(REG, BIT) (((REG) >> (BIT)) & 0x01)
