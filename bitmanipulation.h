Set Bit: Write a macro to set a specific bit at a given position in a register. position ranges from 0 to 32
#define SETBIT(reg,pos) (reg |= (1U << (pos)))

Clear Bit: Write a macro to clear a specific bit at a given position in a register.
#define CLEARBIT(reg,pos) (reg &= ~(1U << (pos))

Toggle Bit: Write a macro to toggle or flip a specific bit at a given position in a register.
#define TOGGLEBIT(reg,pos) (reg ^= (1U << (pos))

Read Bit: Write a macro to read the value (0 or 1) of a specific bit at a given position in a register.
#define READPOS(reg,pos) (((reg) >> (pos)) & 1U)

Write Bit: Write a macro to modify a specific bit at a given position in a register to a targeted value (0 or 1).
#define WRITE_BIT(reg, pos, val) ((CLEARBIT((reg, pos))) | ((val) << (pos)))
  
// 6. Get Mask
// Question: Write a macro to create a bitmask of a specific length starting at a given bit position.
#define GET_MASK(pos, len) (((1U << (len)) - 1U) << (pos))

// 7. Clear Field
// Question: Write a macro to clear a contiguous field of bits of a specified length starting at a given position in a register.
#define CLEAR_FIELD(reg, pos, len) \
    ((reg) &= ~(((1U << (len)) - 1U) << (pos)))

// 8. Write Field
// Question: Write a macro to write a multi-bit value into a specific bitfield of a given length and position in a register.
#define WRITE_FIELD(reg, pos, len, val) \
    ((reg) = ((reg) & ~(((1U << (len)) - 1U) << (pos))) | \
             (((val) & ((1U << (len)) - 1U)) << (pos)))

// 9. Check Power of Two
// Question: Write a macro to check whether a given integer is a power of two.
#define IS_POWER_OF_TWO(x) ((x) != 0 && (((x) & ((x) - 1)) == 0))

// 10. Align Up
// Question: Write a macro to round/align an address or value UP to the nearest power-of-two boundary.
#define ALIGN_UP(x, align) (((x) + ((align) - 1)) & ~((align) - 1))

// 11. Align Down
// Question: Write a macro to round/align an address or value DOWN to the nearest power-of-two boundary.
#define ALIGN_DOWN(x, align) ((x) & ~((align) - 1))

// 12. Clear Lowest Set Bit
// Question: Write a macro to clear the least significant set bit (lowest '1' bit) in an integer.
#define CLEAR_LOWEST_SET_BIT(x) ((x) & ((x) - 1))

// 13. Isolate Lowest Set Bit
// Question: Write a macro to isolate and extract only the least significant set bit in an integer, clearing all other bits.
#define ISOLATE_LOWEST_SET_BIT(x) ((x) & (-(x)))

// 14. Swap In-Place
// Question: Write a macro to swap two integer variables in-place without using a temporary variable.
#define SWAP(a, b) do { (a) ^= (b); (b) ^= (a); (a) ^= (b); } while(0)

// 15. Swap 16-Bit Endianness
// Question: Write a macro to swap the byte order (Endianness) of a 16-bit integer.
#define SWAP_16(x) \
    ((uint16_t)((((uint16_t)(x) & 0x00FFU) << 8) | \
                (((uint16_t)(x) & 0xFF00U) >> 8)))

// 16. Swap 32-Bit Endianness
// Question: Write a macro to swap the byte order (Endianness) of a 32-bit integer.
#define SWAP_32(x) \
    ((uint32_t)((((uint32_t)(x) & 0x000000FFU) << 24) | \
                (((uint32_t)(x) & 0x0000FF00U) << 8)  | \
                (((uint32_t)(x) & 0x00FF0000U) >> 8)  | \
                (((uint32_t)(x) & 0xFF000000U) >> 24)))
