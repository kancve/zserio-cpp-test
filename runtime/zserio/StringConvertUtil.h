#ifndef ZSERIO_STRING_CONVERT_UTIL_H_INC
#define ZSERIO_STRING_CONVERT_UTIL_H_INC

#include "zserio/String.h"
#include "zserio/RebindAlloc.h"
#include <sstream>
#include <limits>

namespace zserio
{

namespace detail
{

/**
 * Converts integer value to string into the given buffer.
 *
 * The string is filled from backwards starting at the 24th byte.
 *
 * \return Beginning of the resulting string which is null-terminated.
 */
template <typename T,
        typename std::enable_if<std::is_unsigned<T>::value && !std::is_same<T, bool>::value, int>::type = 0>
const char* convertIntToString(char buffer[24], T value, bool isNegative)
{
    static const char DIGITS[] = "0001020304050607080910111213141516171819"
                                 "2021222324252627282930313233343536373839"
                                 "4041424344454647484950515253545556575859"
                                 "6061626364656667686970717273747576777879"
                                 "8081828384858687888990919293949596979899";

    static const size_t BUFFER_SIZE = 24;
    char* bufferEnd = buffer + BUFFER_SIZE;

    *--bufferEnd = 0; // always terminate with '\0'

    while (value >= 100)
    {
        const unsigned int index = static_cast<unsigned int>((value % 100) * 2);
        value /= 100;
        *--bufferEnd = DIGITS[index + 1];
        *--bufferEnd = DIGITS[index];
    }

    if (value < 10)
    {
        *--bufferEnd = static_cast<char>('0' + value);
    }
    else
    {
        const unsigned int index = static_cast<unsigned int>(value * 2);
        *--bufferEnd = DIGITS[index + 1];
        *--bufferEnd = DIGITS[index];
    }

    if (isNegative)
        *--bufferEnd = '-';

    return bufferEnd;
}

} // namespace detail

/**
 * Converts unsigned integral value to string and writes the result to the given buffer.
 * Note that the buffer is filled from behind.
 *
 * \param buffer Buffer to fill with the string representation of the given value.
 * \param value  Value to convert.
 *
 * \return Pointer to the beginning of the resulting string.
 */
template <typename T,
        typename std::enable_if<std::is_unsigned<T>::value, int>::type = 0>
const char* convertIntToString(char buffer[24], T value)
{
    return detail::convertIntToString(buffer, value, false);
}

/**
 * Converts signed integral value to string and writes the result to the given buffer.
 * Note that the buffer is filled from behind.
 *
 * \param buffer Buffer to fill with the string representation of the given value.
 * \param value  Value to convert.
 *
 * \return Pointer to the beginning of the resulting string.
 */
template <typename T, typename std::enable_if<std::is_signed<T>::value, int>::type = 0>
const char* convertIntToString(char buffer[24], T value)
{
    using unsigned_type = typename std::make_unsigned<T>::type;
    unsigned_type absValue = static_cast<unsigned_type>(value);
    const bool isNegative = value < 0;
    if (isNegative)
        absValue = 0 - absValue;

    return detail::convertIntToString(buffer, absValue, isNegative);
}

/**
 * Converts float to string and writes the result to the given buffer.
 * Note that only five three digits after point are used. that the buffer is filled from behind.
 *
 * \param buffer Buffer to fill with the string representation of the given value.
 * \param value  Value to convert.
 *
 * \return Pointer to the beginning of the resulting string.
 */
inline const char* convertFloatToString(char buffer[48], float value)
{
    if (value >= static_cast<float>(std::numeric_limits<int64_t>::max()))
        return "+Inf";
    if (value <= static_cast<float>(std::numeric_limits<int64_t>::min()))
        return "-Inf";

    const int64_t integerPart = static_cast<int64_t>(value);
    const int64_t floatingPart = static_cast<int64_t>(
            (value - static_cast<float>(integerPart)) * 1E3f); // 3 digits
    const int64_t floatingPartAbs = (floatingPart < 0) ? 0 - floatingPart : floatingPart;
    char* floatingPartString = const_cast<char*>(convertIntToString(buffer + 24, floatingPartAbs));
    const char* integerPartString = convertIntToString(floatingPartString - 24, integerPart);
    *(floatingPartString - 1) = '.'; // replace terminated zero in the first substring (integerPartString)

    return integerPartString;
}

/**
 * Converts bool value to boolalpha C-string ("true" or "false").
 *
 * \param value Value to convert.
 *
 * \return C-string representation of the given bool value.
 */
inline const char* convertBoolToString(bool value)
{
    return value ? "true" : "false";
}

/**
 * Converts an integral value to string using the given allocator. Defined for convenience.
 *
 * \param value     Value to convert.
 * \param allocator Allocator to use for the string allocation.
 *
 * \return String representation of the given integral value.
 */
template <typename ALLOC, typename T>
string<ALLOC> toString(T value, const ALLOC& allocator = ALLOC())
{
    char buffer[24];
    return string<ALLOC>(convertIntToString(buffer, value), allocator);
}

/**
 * Converts a boolean value to string using the given allocator. Defined for convenience.
 *
 * Note that in contrast to std::to_string, this behaves as STL streams with boolalpha flag and produces
 * "true" and "false" strings.
 *
 * \param value Value to convert.
 * \param allocator Allocator to use for the string allocation.
 */
template <typename ALLOC>
string<ALLOC> toString(bool value, const ALLOC& allocator = ALLOC())
{
    return string<ALLOC>(convertBoolToString(value), allocator);
}

/**
 * Converts an integral (or a boolean) value to string. Convenience wrapper to call without allocator.
 *
 * \param value Value to convert.
 *
 * \return String representation of the given value.
 */
template <typename T>
string<std::allocator<char>> toString(T value)
{
    return toString<std::allocator<char>>(value);
}

} // namespace zserio

#endif // ifndef ZSERIO_STRING_CONVERT_UTIL_H_INC
