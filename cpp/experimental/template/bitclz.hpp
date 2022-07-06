#ifndef BITCLZ_HPP
#define BITCLZ_HPP
#include <cstdlib>
#include <type_traits>

typename std::enable_if<std::is_same<size_t, unsigned long>::value, size_t>::type
bitclz(size_t const i);
#endif // #ifndef BITCLZ_HPP
