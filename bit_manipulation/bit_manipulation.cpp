/*
    g++ -o bit_manipulation bit_manipulation.cpp
    ./bit_manipulation
*/

/*
    https://www.youtube.com/watch?v=aMAM5vL7wTs
    https://cp-algorithms.com/algebra/bit-manipulation.html
    https://www.youtube.com/watch?v=Ew2QnDeTCCE
*/

#define ONE (uint64_t)0x1 /* BF: Bit field, pos: position of the bit. */
#define SET_BIT(BF, pos) BF |= (ONE << pos)
#define CLEAR_BIT(BF, pos) BF &= ~(ONE << pos)
#define TOGGLE_BIT(BF, pos) BF ^= (ONE << pos)
#include <iostream>

bool is_bit_set(uint64_t bit_field, int position) 
{
    return (bit_field >> position) & ONE;
}

bool is_power_of_two(uint64_t bit_field) {
    return bit_field && !(bit_field & (bit_field - 1));
}

int num_set_bits(uint64_t bit_field)
{
    int count = 0;
    while (bit_field)
    {
        bit_field = bit_field & (bit_field - 1);
        count++;
    }
    return count;
}

void print_bits(uint64_t bit_field)
{
    for(int position = 0; position < 64; position++)
    {
        if(is_bit_set(bit_field, position))
        {
            std::cout << "+";
        }
        else
        {
            std::cout << ".";
        }
    }
    std::cout << std::endl;
}

int main()
{
    
    uint64_t bits = 0;
    print_bits(bits);

    SET_BIT(bits, 0);
    SET_BIT(bits, 2);
    SET_BIT(bits, 7);
    SET_BIT(bits, 33);
    SET_BIT(bits, 45);
    print_bits(bits);

    CLEAR_BIT(bits, 0);
    print_bits(bits);

    TOGGLE_BIT(bits, 7);
    print_bits(bits);

    std::cout << bits << std::endl;

    bool val = is_power_of_two(bits);
    int set_bits_count = num_set_bits(bits);

    std::cout << val << " " << set_bits_count << std::endl;

    return 0;
}
