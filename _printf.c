#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    char c;
    char *str;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            putchar(*format);
            printed_chars++;
        }
        else
        {
            format++;
            switch (*format)
            {
                case 'c':
                    c = va_arg(args, int);
                    putchar(c);
                    printed_chars++;
                    break;
                case 's':
                    str = va_arg(args, char *);
                    if (str == NULL)
                        str = "(null)";
                    while (*str)
                    {
                        putchar(*str);
                        printed_chars++;
                        str++;
                    }
                    break;
                case '%':
                    putchar('%');
                    printed_chars++;
                    break;
                default:
                    putchar('%');
                    printed_chars++;
                    putchar(*format);
                    printed_chars++;
            }
        }
        format++;
    }

    va_end(args);
    return printed_chars;
}

int main(void)
{
    int len;
    int len2;
    char *str = "Hello, printf!";

    len = _printf("Let's try to print a character: %c\n", 'A');
    len2 = printf("Let's try to print a character: %c\n", 'A');
    printf("Length 1: %d, Length 2: %d\n", len, len2);

    len = _printf("Let's try to print a string: %s\n", str);
    len2 = printf("Let's try to print a string: %s\n", str);
    printf("Length 1: %d, Length 2: %d\n", len, len2);

    len = _printf("Let's try to print a percentage sign: %%\n");
    len2 = printf("Let's try to print a percentage sign: %%\n");
    printf("Length 1: %d, Length 2: %d\n", len, len2);

    return (0);
}
