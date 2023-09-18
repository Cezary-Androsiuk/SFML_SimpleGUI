#ifndef COMMON_HPP
#define COMMON_HPP

#include <SFML/Graphics.hpp>

namespace sgui{
    namespace _dev{
        #define _BITSET1(var, bit) ((var) |= (bit))
        #define _BITSET0(var, bit) ((var) &= ~ (bit))
        #define _BITGET(var, bit) ((var) & (bit))
    } // namespace _dev
} // namespace sgui

#endif 