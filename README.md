*This project has been created as part of the 42 curriculum by yhayyani.*

# ft_printf

## Description

`ft_printf` is a recode of the C standard `printf()` function. The goal is to learn how **variadic functions** work in C (`stdarg.h`) and to build a small, well-structured and extensible library: `libftprintf.a`.

Prototype:

```c
int ft_printf(const char *format, ...);
```

It returns the number of characters printed, or `-1` on error (for example when `format` is `NULL` or when `write` fails).

### Supported conversions

| Specifier | Output |
|-----------|--------|
| `%c` | a single character |
| `%s` | a string (`(null)` if the pointer is `NULL`) |
| `%p` | a `void *` pointer in hexadecimal (`0x...`, or `(nil)` for `NULL`) |
| `%d` / `%i` | a signed decimal integer |
| `%u` | an unsigned decimal integer |
| `%x` | an unsigned integer in lowercase hexadecimal |
| `%X` | an unsigned integer in uppercase hexadecimal |
| `%%` | a percent sign |

The original `printf` buffer management is intentionally **not** reimplemented: every character is sent with `write`.

### Project structure

| File | Role |
|------|------|
| `ft_printf.h` | prototypes and includes |
| `ft_printf.c` | `ft_printf` and the main loop over the format string |
| `ft_printf_format.c` | `pf_convert`: dispatches a specifier to its handler |
| `ft_printf_utils.c` | `pf_putchar`, `pf_putstr` |
| `ft_printf_decimal.c` | `pf_putnbr` (`%d %i`), `pf_putunsigned` (`%u`) |
| `ft_printf_hex.c` | `pf_puthex` (`%x %X`), `pf_putpointer` (`%p`) |

## Instructions

### Compilation

```sh
make        # builds libftprintf.a at the root of the repository
make clean  # removes object files
make fclean # removes object files and libftprintf.a
make re     # fclean + all
```

The project is compiled with `cc -Wall -Wextra -Werror`, and the library is created with `ar rcs`. The Makefile does not relink when nothing changed.

### Usage

```c
#include "ft_printf.h"

int main(void)
{
    int n = 42;

    ft_printf("Hello %s, n = %d, hex = %x, ptr = %p, 100%%\n", "world", n, 255, &n);
    return (0);
}
```

Compile your file with the library:

```sh
cc main.c libftprintf.a
```

### Testing

The output and the return value can be compared with the real `printf`, for example by running both in a child process and diffing what each one writes. Build the tests with `-fsanitize=address,undefined` and run them under `valgrind` to check for crashes and leaks.

## Algorithm and data structures

**Algorithm.** `ft_printf` initializes a `va_list` with `va_start`, then walks the format string one character at a time (`pf_process`):

- a normal character is written directly with `pf_putchar`;
- on `%`, the next character is read and passed to `pf_convert`, which picks the right handler and fetches the matching argument with `va_arg`;
- every handler returns the number of characters it wrote, and the main loop adds them up into the final return value;
- if any `write` fails (returns something other than 1), `-1` is propagated all the way up and printing stops.

`va_end` is always called before returning.

**Number printing.** `pf_putnbr`, `pf_putunsigned` and `pf_puthex` are **recursive**: they print `n / base` first, then the last digit `n % base`. This outputs digits in the correct order without needing a buffer or any dynamic allocation, which also means there is nothing to free and no possible leak.

- `%d` / `%i` take an `int` but `pf_putnbr` works on a `long`, so negating `INT_MIN` does not overflow.
- `%x` / `%X` use the same function with an `upper` flag choosing between `a-f` and `A-F`.
- `%p` prints `0x` followed by the address as an `unsigned long`; a `NULL` pointer prints `(nil)`, like glibc.

**Data structure.** No custom structure is needed: the only state is the `va_list` (passed by pointer so the handlers consume arguments from the same list) and an integer counter. A single dispatch function (`pf_convert`) keeps the code extensible: supporting a new conversion means adding one handler and one line in that function.

## Resources

- `man 3 printf`, `man 3 stdarg`, `man 2 write`
- [GNU C Library manual: Variadic Functions](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)
- [cppreference: `printf`](https://en.cppreference.com/w/c/io/fprintf) and [`va_arg`](https://en.cppreference.com/w/c/variadic/va_arg)

### Use of AI

AI was used only as a support tool, not to write the project's code: it was used to build a test program that compares `ft_printf` against the real `printf` (output and return value, with AddressSanitizer and valgrind), to review the Makefile and Norm compliance, and to draft this README. The implementation itself and its explanation are the author's own work.