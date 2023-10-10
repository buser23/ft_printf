# ft_printf

This project is part of the curriculum at 42. It is an implementation of the `printf` function in C programming language called `ft_printf`. The function allows formatting and printing of various types of data.

## Basic Conversions

The basic conversions supported by `ft_printf` are:

- `%c`: Character
- `%s`: String
- `%p`: Pointer
- `%d` and `%i`: Signed decimal integer
- `%u`: Unsigned decimal integer
- `%x` and `%X`: Unsigned hexadecimal integer
- `%%`: Percent sign

## Additional Flags

`ft_printf` supports additional flags that can be used for more precise formatting:

- `+`: Adds a plus sign (`+`) before positive numbers.
- ` ` (space): Inserts a space before positive numbers.
- `#`: Adds the "alternative form" for hexadecimal (`0x` or `0X`) conversions.
- `-`: Left-aligns the converted value within the field width.
- `0`: Pads the field width with leading zeros.
- `.` (dot): Specifies the precision of the conversion.